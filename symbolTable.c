#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "symbolTable.h"
#include <stdbool.h>


// Création de la table des symboles

TableSymbole *creerTableSymbole()
{
    TableSymbole *table = (TableSymbole *)malloc(sizeof(TableSymbole));
    if (table == NULL)
    {
        fprintf(stderr, "Erreur: impossible d'allouer la mémoire pour la table des symboles\n");
        exit(1);
    }

    table->debut = NULL;
    table->fin = NULL;
    table->taille = 0;

    return table;
}

// Création d'un symbole
Symbole *creerSymbole(CategorieSymbole categorie, char *nom, char *type, char *valeur, int numLigne, int adresseMem)

{
    Symbole *symbole = (Symbole *)malloc(sizeof(Symbole));
    if (symbole == NULL)
    {
        fprintf(stderr, "Erreur: impossible d'allouer la mémoire pour le symbole\n");
        exit(1);
    }

    symbole->categorie = categorie;
    symbole->nom = strdup(nom);
    symbole->type = strdup(type);
    symbole->valeur = strdup(valeur);
    symbole->nnumLigne = numLigne;
    symbole->adresseMem = adresseMem;

    if (categorie == FONCTION)
    {
        symbole->infoFonction = (InfoFonction *)malloc(sizeof(InfoFonction));
        if (symbole->infoFonction == NULL)
        {
            fprintf(stderr, "Erreur: impossible d'allouer la mémoire pour les informations de la fonction\n");
            exit(1);
        }

        symbole->infoFonction->nbParametres = 0;
        symbole->infoFonction->parametres = NULL;
    }
    else // Pour le cas où le symbole est une variable ou une constante
    {
        symbole->infoFonction = NULL;
    }
    return symbole;
}
//fonction d'insertion d'un symbole dans la table des symboles
void insererSymbole(TableSymbole *table, Symbole *symbole) {
    if (table->debut == NULL) {
        // La table est vide, insérer au début
        table->debut = symbole;
        table->fin = symbole;
        symbole->precedent = NULL;
        symbole->suivant = NULL;
    } else {
        // La table n'est pas vide, insérer à la fin
        table->fin->suivant = symbole;
        symbole->precedent = table->fin;
        symbole->suivant = NULL;
        table->fin = symbole;
    }
    table->taille++;
}

//fonction d'affichage de la table des symboles
void afficherTableSymbole(TableSymbole *table) {
    Symbole *current = table->debut;
    printf("Table des symboles (taille: %zu):\n", table->taille);
    printf("---------------------------------------------------------------------------------------\n");
    printf("| %-20s | %-10s | %-10s | %-15s | %-15s |\n", "Nom", "Type", "Catégorie", "Adresse mémoire", "Valeur Init");
    printf("---------------------------------------------------------------------------------------\n");
    while (current != NULL) {
        printf("| %-20s | %-10s | %-10d | %-15d | %-15s |\n", current->nom, current->type, current->categorie, current->adresseMem, current->valeur);
        current = current->suivant;
    }
    printf("---------------------------------------------------------------------------------------\n");
}

//fonction de recherche d'un symbole
//utilisée surtout avant la création d'un symbole pour vérifier si un symbole avec le même nom existe déjà, pour éviter les doublons
bool rechercherSymbole(TableSymbole *table, const char *nom, Symbole **symboleTrouve) {
    Symbole *current = table->debut;
    while (current != NULL) {
        if (strcmp(current->nom, nom) == 0) {
            *symboleTrouve = current;
            return true;
        }
        current = current->suivant;
    }
    *symboleTrouve = NULL;
    return false;
}
//fonction de suppression d'un symbole
void supprimerSymbole(TableSymbole *table, const char *nom) {
    Symbole *symboleASupprimer;
    if (rechercherSymbole(table, nom, &symboleASupprimer)) {
        if (symboleASupprimer->precedent != NULL) {
            symboleASupprimer->precedent->suivant = symboleASupprimer->suivant;
        } else {
            table->debut = symboleASupprimer->suivant;
        }

        if (symboleASupprimer->suivant != NULL) {
            symboleASupprimer->suivant->precedent = symboleASupprimer->precedent;
        } else {
            table->fin = symboleASupprimer->precedent;
        }

        free(symboleASupprimer->nom);
        free(symboleASupprimer->type);
        free(symboleASupprimer->valeur);
        if (symboleASupprimer->infoFonction != NULL) {
            free(symboleASupprimer->infoFonction);
        }
        free(symboleASupprimer);

        table->taille--;
    } else {
        printf("Symbole non trouvé: %s\n", nom);
    }
}

//fonction pour ajouter un paramètre à une fonction
void ajouterParametre(InfoFonction *info, const char *nom, const char *type) {
    Parametre *param = (Parametre *)malloc(sizeof(Parametre));
    if (param == NULL) {
        fprintf(stderr, "Erreur: impossible d'allouer la mémoire pour le paramètre\n");
        exit(1);
    }
    param->nom = strdup(nom);
    param->type = strdup(type);
    param->suivant = NULL;

    if (info->parametres == NULL) {
        info->parametres = param;
    } else {
        Parametre *current = info->parametres;
        while (current->suivant != NULL) {
            current = current->suivant;
        }
        current->suivant = param;
    }
    info->nbParametres++;
}
//fonction pour afficher les informations d'une fonction
void afficherInfoFonction(Symbole *symbole) {
    InfoFonction *info = symbole->infoFonction;
    printf("Nom de la fonction: %s\n", symbole->nom);
    printf("Type de retour: %s\n", symbole->type);
    printf("Adresse mémoire: %d\n", symbole->adresseMem);
    printf("Nombre de paramètres: %d\n", info->nbParametres);
    printf("Liste des paramètres:\n");
    Parametre *current = info->parametres;
    while (current != NULL) {
        printf("Paramètre: %s, Type: %s\n", current->nom, current->type);
        current = current->suivant;
    }
}

int main() {
    Symbole *symbole = creerSymbole(FONCTION, "main", "void", "", 1, 0);
    Symbole *symbole2 = creerSymbole(VARIABLE, "x", "int", "8", 4, 0);
    
    TableSymbole *table = creerTableSymbole();
    if (table != NULL) {
        printf("Table des symboles créée\n");
    }
    insererSymbole(table, symbole);
    insererSymbole(table, symbole2);
    afficherTableSymbole(table);
    ajouterParametre(symbole->infoFonction, "a", "int");
    afficherTableSymbole(table);
    printf("affihcage des informations de la fonction\n");
    afficherInfoFonction(symbole);
    return 0;
}