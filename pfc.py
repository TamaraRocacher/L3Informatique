#!/usr/bin/env python3
# coding: utf-8

import sys
import os
import random
print("\n\t\t\tBienvenue dans le jeu Pierre Feuille Ciseaux\n")
cont =1
while(cont):
    print ("Choisissez... pierre , feuille ou ciseaux\n")
    pierre = "pierre"
    feuille ="feuille"
    ciseaux = "ciseaux"
    human = input()
    if human == pierre:
        human = pierre
        print("Vous avez choisi " + pierre + ".\n")
    elif human == feuille:
        human = feuille
        print("Vous avez choisi " + feuille + ".\n")
    elif human == ciseaux:
        human = ciseaux
        print("Vous avez choisi " + ciseaux + ".\n")
    else:
        print("Votre choix est incorrecte\n")
        
    computer_choice=random.randint(1,3)
    if computer_choice == 1:
        computer_choice = "pierre"
    elif computer_choice == 2:
        computer_choice = "feuille"
    elif computer_choice == 3:
        computer_choice="ciseaux"

    if computer_choice == "pierre" and human == "pierre":
        print("\t\t\tEgalité!\n")
    elif computer_choice == "pierre" and human == "ciseaux":
        print("\t\t\tVous avez perdu!\n")
    elif computer_choice == "pierre" and human == "feuille":
        print("\t\t\tVous avez gagné!\n")
    elif computer_choice == "feuille" and human == "ciseaux":
        print("\t\t\tVous avez gagné!\n")
    elif computer_choice == "feuille" and human == "pierre":
        print("\t\t\tVous avez perdu!\n")
    elif computer_choice == "feuille" and human == "feuille":
        print("\t\t\tEgalité!\n")
    elif computer_choice == "ciseaux" and human == "ciseaux":
        print("\t\t\tEgalité!\n")
    elif computer_choice == "ciseaux" and human == "pierre":
        print("\t\t\tVous avez gagné!\n")
    elif computer_choice == "ciseaux" and human == "feuille":
        print("\t\t\tVous avez perdu!\n")

    print("L'ordinateur a choisi " + computer_choice + ".\nVoulez vous faire uneouvelle manche(oui/non)\n")
    non = "non"
    oui = "oui" 
    quitter = input()
    if quitter==non:
        cont=0
    elif quitter==oui:
        cont = 1
    
