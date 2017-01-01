/*
 * =====================================================================================
 *
 *       Filename:  anagram.c
 *
 *    Description:  Body file for anagram
 *
 *        Version:  1.0
 *        Created:  09/11/2015 22:26:27
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Guillerme Duvillié (mfreeze), gduvillie@openmailbox.org
 *   Organization:  
 *
 * =====================================================================================
 */

#include "anagram.h"


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  initialise_anagramme
 *  Description:  Génére une nouvelle manche d'anagramme en utilisant le fichier dict
 *                  - anagram_t *a : un pointeur sur la structure amenée à contenir les 
 *                      informations d'une nouvelle manche
 *                  - char *dict   : le fichier contenant le dictionnaire d'anagrammes
 *       Return:  Retourne le nombre de réponses possibles en cas de succès, retourne -1
 *                sinon.
 * =====================================================================================
 */
int initialise_anagramme (anagram_t * a, dict_t *dico) 
{
    char *parser;
    printf("chemin: %s\n",dico->chemin);
    FILE *fichier_dict = fopen(dico->chemin, "r");
    if (!fichier_dict) 
    {
        perror("Erreur à l'ouverture du fichier dictionnaire.\n");
        return -1;
    }

    // On tire la ligne à considérer au hasard
    int ligne = rand() % dico->nombre_lignes;

    // On parse le fichier jusqu'à la ligne qui nous intéresse
    while (ligne --)
        fgets(a->liste, MAX_LEN, fichier_dict);

    // Lit la ligne courante
    if (!fgets(a->liste, MAX_LEN, fichier_dict))
    {
        perror("Erreur lors de la lecture de la ligne\n");
        //Fermeture du fichier
        fclose(fichier_dict);
        return -1;
    }

    // Fermeture du fichier car à partir de maintenant, il n'est plus utilisé
    fclose(fichier_dict);

    // Compte le nombre de mot et leur taille
    parser = a->liste;

    a->longueur_mot = strcspn(a->liste, " \n\0"); 
    a->nombre_mot = 0; 


    while (*parser) 
    {
        parser += a->longueur_mot + 1;
        a->nombre_mot ++;
    }

    // Suppression du caractère de fin ('\n')
    parser = strrchr(a->liste, '\n');
    if (parser)
        *parser = '\0';

    // TODO Sélectionner le mot au hasard
    a->deb_mot_courant = a->liste + (rand() % a->nombre_mot)*(a->longueur_mot + 1);

    // Copie le mot dans le buffer
    strncpy(a->mot_courant, a->deb_mot_courant, a->longueur_mot);

    // Positionne le caractère de fin de chaîne
    a->mot_courant[a->longueur_mot] = '\0';
    

    return a->nombre_mot - 1;
}


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  est_une_solution
 *  Description:  Teste si une chaîne de caractère est une solution à la manche en cours
 *                  - const anagram_t *a : pointeur sur la manche en cour
 *                  - const char *chaine : chaîne de caractère à tester
 *       Return:  1 si la réponse est valide, zéro sinon
 * =====================================================================================
 */
int est_une_solution     (const anagram_t *a, const char *chaine) 
{
    // Dans un premier temps on teste la taille
    if (strlen(chaine) != a->longueur_mot)
        return 0;
    // La chaîne ne peut pas contenir d'espace
    // pour éviter tout problème avec la recherche de sous chaîne, on retourne 0 si la chaîne
    // fournie en contient au moins 1.
    if (strchr(chaine, ' '))
        return 0;

    char *souschaine = strstr(a->liste, chaine);
    if (souschaine && souschaine != a->deb_mot_courant)
        return 1;

    return 0;
}



/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  initialise_dico
 *  Description:  Initialise une structure dictionnaire
 *                  - dict_t *dico       :  la structure à initialiser
 *                  - const char *chemin :  le chemin du fichier dictionnaire
 *       Return:   Le nombre de lignes du fichier en cas de succès, -1 sinon.
 * =====================================================================================
 */
int initialise_dico(dict_t *dico, const char *chemin)
{
    char buffer[MAX_LEN];

    strncpy(dico->chemin, chemin, MAX_LEN);
    dico->nombre_lignes = 0;

    FILE *fichier_dict = fopen(dico->chemin, "r");
    if (!fichier_dict) 
    {
        perror("Erreur à l'ouverture du fichier dictionnaire.");
        return -1;
    }

    while (fgets(buffer, MAX_LEN, fichier_dict))
        dico->nombre_lignes++;

    fclose(fichier_dict);

    /*-----------------------------------------------------------------------------
     *  Initialisation du random
     *-----------------------------------------------------------------------------*/
    srand(time(NULL));


    return dico->nombre_lignes;
}
