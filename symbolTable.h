#ifndef TABLESYMBOLE_H
#define TABLESYMBOLE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/* Structures */
/*************************************************************************************/

/* Enumération des catégories de symboles */
typedef enum
{
    VARIABLE,   
    CONSTANTE,  
    FUNCTION     
} CategorieSymbole;

/* Structure représentant un paramètre de fonction */
typedef struct Parametre
{
    char *nom;                     
    char *type;                     
    struct Parametre *suivant;      // Pointeur vers le prochain paramètre
} Parametre;

/* Structure représentant les informations spécifiques aux fonctions */
typedef struct InfoFonction
{
    int nbParametres;               
    Parametre *parametres;          // Liste chaînée des paramètres
} InfoFonction;

/* Structure représentant un symbole dans la table */
typedef struct Symbole
{
    CategorieSymbole categorie;     
    char *nom;                      
    char *type;                     
    char *valeur;               
    int nnumLigne;                
    int adresseMem;    
    struct Symbole *suivant;        
    struct Symbole *precedent;        

    // Informations spécifiques aux fonctions
    InfoFonction *infoFonction;     
} Symbole;

/* Structure représentant la table des symboles */
typedef struct TableSymbole
{
    Symbole *debut;                 
    Symbole *fin;                   
    size_t taille;                 
} TableSymbole;

// Entete des fonctions
/*************************************************************************************/
Symbole *creerSymbole(CategorieSymbole categorie, char *nom, char *type, char *valeurInit, int numLigne, int adresseMem);
TableSymbole *creerTableSymbole();
void insererSymbole(TableSymbole *table, Symbole *symbole);
void afficherTableSymbole(TableSymbole *table);
bool rechercherSymbole(TableSymbole *table, const char *nom, Symbole **symboleTrouve);
void supprimerSymbole(TableSymbole *table, const char *nom);
void ajouterParametre(InfoFonction *info, const char *nom, const char *type);
void afficherInfoFonction(Symbole *symbole);

#endif