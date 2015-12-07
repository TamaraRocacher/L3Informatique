/*
 * =====================================================================================
 *
 *       Filename:  tpsup.c
 *
 *    Description:  Main file
 *
 *        Version:  1.0
 *        Created:  18/10/2015 10:31:36
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Guillerme Duvillié (mfreeze), gduvillie@openmailbox.org
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <errno.h>

#include "debug.h"
#include "binary.h"

#define BUF_SIZE 1024

const char *choices[] = { 
    "1. Test de parité", 
    "2. Test de puissance",
    "3. Représentation Mémoire",
    "4. Conversion Binaire",
    "0. Quit",
    NULL
};

/* A String represents an integer if and only if each character belong to [0-9] */
    int
isintegervalue (const char *s) 
{
    if (!s || *s == '\0')
        return 0;
    if (*s == '-' || *s == '+')
        s++;
    while (*s)
        if (*s < '0' || *s++ > '9')
            return 0;
    return 1;
}

/* A String represents an integer if and only if each character belong to [0-9.] */
    int
isdoublevalue (const char *s) 
{
    int dot = 0;
    if (!s || *s == '\0')
        return 0;
    if (*s == '-' || *s == '+')
        s++;
    while (*s) 
    {
        if ((*s != '.') && (*s < '0' || *s > '9'))
            return 0;
        if (*s++ == '.') 
            if (dot++)
                return 0;
    }
    return 1;
}



/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  getmenuinput
 *  Description:  Print menu and get the value entered by user
 * =====================================================================================
 */
    int
getmenuinput() 
{
    char buf[BUF_SIZE] = {0};
    switch(1) {
        do {
            default:
                printf("\nNot a number : '%s'\n", buf);
            case 1:
                printf ("\n***** MENU *****\n\n");
                const char **s = choices;
                while (*s)
                    printf("\t%s\n", *s++);

                /* User entry */
                printf("\nVeuillez entrer un choix : ");
                fgets(buf, BUF_SIZE, stdin);
                DEB_PRINT("Entrée utilisateur avant formattage : '%s'\n", buf);
                /* Remove the \r at the end of the string */
                buf[strlen(buf) - 1] = '\0';
                DEB_PRINT("Entrée utilisateur après formattage : '%s'\n", buf); 
        } while (!isintegervalue(buf));
    }
    return atoi(buf); 
}

    int
main (int argc, char **argv) 
{
    int loop = 1;
    char buf[BUF_SIZE];
    char *bin;
    while (loop) {
        int i = getmenuinput();
        printf("%d\n", i);
        switch(i) {
            case 1:
                switch(0) {
                    do {
                        default:
                            printf("L'entrée n'est pas un entier.\n");
                        case 0:
                            printf("Entrez un entier : ");
                            fgets(buf, BUF_SIZE, stdin);
                            DEB_PRINT("Entrée utilisateur avant formattage : '%s'\n", buf);
                            /* Remove the \r at the end of the string */
                            buf[strlen(buf) - 1] = '\0';
                            DEB_PRINT("Entrée utilisateur après formattage : '%s'\n", buf); 
                    } while (!isintegervalue(buf));
                }
                printf("%s est un entier pair ? %s\n", buf, iseven(atoi(buf)) ? "Oui" : "Non");
                break;
            case 2:
                switch(0) {
                    do {
                        default:
                            printf("L'entrée n'est pas un entier.\n");
                        case 0:
                            printf("Entrez un entier : ");
                            fgets(buf, BUF_SIZE, stdin);
                            DEB_PRINT("Entrée utilisateur avant formattage : '%s'\n", buf);
                            /* Remove the \r at the end of the string */
                            buf[strlen(buf) - 1] = '\0';
                            DEB_PRINT("Entrée utilisateur après formattage : '%s'\n", buf); 
                    } while (!isintegervalue(buf));
                }
                printf("%s est une puissance de 2 ? %s\n", buf, ispower2(atoi(buf)) ? "Oui" : "Non");
                break;
            case 3:
                printf("Entrez une donnée : ");
                fgets(buf, BUF_SIZE, stdin);
                DEB_PRINT("Entrée utilisateur avant formattage : '%s'\n", buf);
                /* Remove the \r at the end of the string */
                buf[strlen(buf) - 1] = '\0';
                DEB_PRINT("Entrée utilisateur après formattage : '%s'\n", buf); 
                if (isintegervalue(buf))
                {
                    DEB_PRINT("'%s' est considéré comme un entier.\n", buf);
                    int integer = atoi(buf);
                    bin = memoryrepresentation((void *) &integer, sizeof(int));
                    printf("Représentation mémoire de %d : %s\n", integer, bin);
                }
                else if (isdoublevalue(buf))
                {
                    DEB_PRINT("'%s' est considéré comme un double.\n", buf);
                    double dbl = atof(buf);
                    bin = memoryrepresentation((void *) &dbl, sizeof(double));
                    printf("Représentation mémoire de %lf : %s\n", dbl, bin);
                }
                else
                {
                    DEB_PRINT("'%s' est considéré comme une chaîne de caractères.\n", buf);
                    bin = memoryrepresentation((void *) buf, strlen(buf));
                    printf("Représentation mémoire de '%s' : %s\n", buf, bin);
                }
                free(bin);
                break;
            case 4:
                switch (1)
                {
                    int cont = 1;
                    do 
                    {
                        case 0:
                            printf("'%s' n'est ni un entier ni un caractère.\n", buf);
                            break;
                        default:
                            printf("Entrez un entier ou un charactère : ");
                            fgets(buf, BUF_SIZE, stdin);
                            DEB_PRINT("Entrée utilisateur avant formattage : '%s'\n", buf);
                            /* Remove the \r at the end of the string */
                            buf[strlen(buf) - 1] = '\0';
                            DEB_PRINT("Entrée utilisateur après formattage : '%s'\n", buf); 
                            if (isintegervalue(buf))
                            {
                                DEB_PRINT("'%s' est considéré comme un entier.\n", buf);
                                int integer = atoi(buf);
                                bin = binaryconversion1((void *) &integer, sizeof(int));
                                printf("Représentation binaire de %d : %s\n", integer, bin);
                                free(bin);
                                cont = 0;
                            }
                            else if (strlen(buf) == 1) {
                                DEB_PRINT("'%s' est considéré comme un caractère.\n", buf);
                                char c = buf[0];
                                bin = binaryconversion1((void *) &c, sizeof(char));
                                printf("Représentation binaire de %c : %s\n", c, bin);
                                free(bin);
                                cont = 0;
                            }
                    } while (cont);
                }
                break;
            case 0:
                loop = 0;
                break;
            default:
                printf("Le choix n'existe pas.\n");
                break;
        }
    }
    return EXIT_SUCCESS;
}
