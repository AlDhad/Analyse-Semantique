#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "symbolTable.h"
#include <stdbool.h>
#include <ctype.h>

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
Symbole *creerSymbole(CategorieSymbole categorie, char *nom, char *type, char *valeur, int numLigne, int taille)

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
    symbole->taille = taille;

    if (categorie == FUNCTION)
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
bool rechercherParametre(Symbole *fonction, const char *nomParam, Parametre **parametreTrouve) {
    if (fonction == NULL || fonction->categorie != FUNCTION || fonction->infoFonction == NULL) {
        *parametreTrouve = NULL;
        return false;
    }

    Parametre *current = fonction->infoFonction->parametres;
    while (current != NULL) {
        if (strcmp(current->nom, nomParam) == 0) {
            *parametreTrouve = current;
            return true;
        }
        current = current->suivant;
    }

    *parametreTrouve = NULL;
    return false;
}
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
    printf("---------------------------------------------------------------------------------------------------------------------------\n");
    printf("| %-20s | %-10s | %-10s | %-15s | %-15s | %-30s |\n", "Nom", "Type", "Catégorie", "Adresse mémoire", "Valeur Init", "Infos Fonction");
    printf("---------------------------------------------------------------------------------------------------------------------------\n");
    while (current != NULL) {
        char infosFonction[256] = "";
        if (current->categorie == FUNCTION) {
            snprintf(infosFonction, sizeof(infosFonction), "Nb Params: %d", current->infoFonction->nbParametres);
            Parametre *param = current->infoFonction->parametres;
            while (param != NULL) {
                char paramInfo[64];
                snprintf(paramInfo, sizeof(paramInfo), ", %s: %s", param->nom, param->type);
                strncat(infosFonction, paramInfo, sizeof(infosFonction) - strlen(infosFonction) - 1);
                param = param->suivant;
            }
        }
        printf("| %-20s | %-10s | %-10s | %-15d | %-15s | %-30s |\n", current->nom, current->type, categorieToString(current->categorie), current->taille, current->valeur, infosFonction);
        current = current->suivant;
    }
    printf("---------------------------------------------------------------------------------------------------------------------------\n");
}

// Fonction pour convertir la catégorie en chaîne de caractères
const char* categorieToString(CategorieSymbole categorie) {
    switch (categorie) {
        case VARIABLE: return "VARIABLE";
        case CONSTANTE: return "CONSTANTE";
        case FUNCTION: return "FUNCTION";
        default: return "UNKNOWN";
    }
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

void ajouterParametre(Symbole *fonction, const char *nom, const char *type) {
    if (fonction == NULL) {
        fprintf(stderr, "Erreur: pointeur de fonction NULL\n");
        return;
    }

    if (fonction->categorie != FUNCTION) {
        fprintf(stderr, "Erreur: le symbole n'est pas une fonction\n");
        return;
    }

    if (fonction->infoFonction == NULL) {
        fprintf(stderr, "Erreur: infoFonction non initialisé\n");
        fonction->infoFonction = (InfoFonction *)malloc(sizeof(InfoFonction));
        if (fonction->infoFonction == NULL) {
            fprintf(stderr, "Erreur: impossible d'allouer la mémoire pour infoFonction\n");
            exit(1);
        }
        fonction->infoFonction->nbParametres = 0;
        fonction->infoFonction->parametres = NULL;
    }

    Parametre *param = (Parametre *)malloc(sizeof(Parametre));
    if (param == NULL) {
        fprintf(stderr, "Erreur: impossible d'allouer la mémoire pour le paramètre\n");
        exit(1);
    }
    param->nom = strdup(nom);
    param->type = strdup(type);
    param->suivant = NULL;

    if (fonction->infoFonction->parametres == NULL) {
        fonction->infoFonction->parametres = param;
    } else {
        Parametre *current = fonction->infoFonction->parametres;
        while (current->suivant != NULL) {
            current = current->suivant;
        }
        current->suivant = param;
    }
    fonction->infoFonction->nbParametres++;
}
//fonction pour afficher les informations d'une fonction
void afficherInfoFonction(Symbole *symbole) {
    InfoFonction *info = symbole->infoFonction;
    printf("Nom de la fonction: %s\n", symbole->nom);
    printf("Type de retour: %s\n", symbole->type);
    printf("Adresse mémoire: %d\n", symbole->taille);
    printf("Nombre de paramètres: %d\n", info->nbParametres);
    printf("Liste des paramètres:\n");
    Parametre *current = info->parametres;
    while (current != NULL) {
        printf("Paramètre: %s, Type: %s\n", current->nom, current->type);
        current = current->suivant;
    }
}

// int main() {
//     Symbole *symbole = creerSymbole(FUNCTION, "main", "void", "", 1, 0);
//     Symbole *symbole2 = creerSymbole(VARIABLE, "x", "int", "8", 4, 0);
    
//     TableSymbole *table = creerTableSymbole();
//     if (table != NULL) {
//         printf("Table des symboles créée\n");
//     }
//     insererSymbole(table, symbole);
//     insererSymbole(table, symbole2);
//     afficherTableSymbole(table);
//     ajouterParametre(symbole->infoFonction, "a", "int");
//     afficherTableSymbole(table);
//     printf("affihcage des informations de la fonction\n");
//     afficherInfoFonction(symbole);
//     return 0;
// }
int isIntOrfloat(int x){
    int result = 0 ; 
    if (x == 1 || x == 2){
        result = 1 ; 
    }
    return result ; 
}

int isInt(int x){
    int result = 0 ; 
    if (x == 1){
        result = 1 ; 
    }
    return result ; 
}


int isFlt(int x){
    int result = 0 ; 
    if (x == 2){
        result = 1 ; 
    }
    return result ; 
}
void SetTypeSymbol(Symbole* symbole, char* type) {
    if (symbole != NULL) {
        symbole->type = type;
    }
}

void SetNomSymbol(Symbole* symbole, char* nom) {
    if (symbole != NULL) {
        free(symbole->nom);
        symbole->nom = strdup(nom);
    }
}

void SetValueSymbol(Symbole* symbole, char* value) {
    if (symbole != NULL) {
        free(symbole->valeur);
        symbole->valeur = strdup(value);
    }
}
#define TYPE_ENTIER "ENTIER"
#define TYPE_FLOTTANT "FLOTTANT"
#define TYPE_CHAR "CHAR"
#define TYPE_STRING "STRING"
#define TYPE_BOOLEAN "BOOLEAN"

// Helper function to get type from string
static char getTypeChar(const char* type) {
    if (!type) return 0;
    if (strcmp(type, TYPE_ENTIER) == 0) return 'i';
    if (strcmp(type, TYPE_FLOTTANT) == 0) return 'f';
    if (strcmp(type, TYPE_CHAR) == 0) return 'c';
    if (strcmp(type, TYPE_STRING) == 0) return 's';
    if (strcmp(type, TYPE_BOOLEAN) == 0) return 'b';
    return 0;
}

void* convertirCSVEnTableau(char* csv, int* taille, const char* type) {
    if (!csv || !taille || !type) return NULL;
    
    *taille = 0;
    int maxElements = 1;
    for (char* p = csv; *p; p++) {
        if (*p == ',') maxElements++;
    }

    char typeChar = getTypeChar(type);
    if (!typeChar) return NULL;
    size_t elementSize;
    switch (typeChar) {
        case 'i': elementSize = sizeof(int); break;
        case 'f': elementSize = sizeof(float); break;
        case 'c': elementSize = sizeof(char); break;
        case 's': elementSize = sizeof(char*); break;
        case 'b': elementSize = sizeof(int); break;
        default: return NULL;
    }

    void* tableau = calloc(maxElements, elementSize);
    if (!tableau) return NULL;

    char* csvCopy = strdup(csv);
    if (!csvCopy) {
        free(tableau);
        return NULL;
    }

    char* context = NULL;
    char* token = strtok_r(csvCopy, ",", &context);
    int index = 0;

    while (token && index < maxElements) {
        while (isspace(*token)) token++;
        char* end = token + strlen(token) - 1;
        while (end > token && isspace(*end)) end--;
        *(end + 1) = '\0';
        switch (typeChar) {
            case 'i':
                ((int*)tableau)[index] = atoi(token);
                break;
            case 'f':
                ((float*)tableau)[index] = atof(token);
                break;
            case 'c':
                if (strcmp(token, "null") == 0) {
                    ((char*)tableau)[index] = '\0';
                } else {
                    ((char*)tableau)[index] = token[0];
                }
                break;
            case 's': {
                if (strcmp(token, "null") == 0) {
                    ((char**)tableau)[index] = NULL;
                } else {
                    // Handle escaped quotes
                    if (token[0] == '"') {
                        token++;
                        end = strrchr(token, '"');
                        if (end) *end = '\0';
                    }
                    size_t len = strlen(token);
                    char* str = malloc(len + 1);
                    if (!str) {
                        // Clean up on allocation failure
                        for (int i = 0; i < index; i++) {
                            free(((char**)tableau)[i]);
                        }
                        free(tableau);
                        free(csvCopy);
                        return NULL;
                    }
                    // Unescape quotes
                    char* dst = str;
                    for (char* src = token; *src; src++) {
                        if (*src == '\\' && *(src + 1) == '"') {
                            src++;
                        }
                        *dst++ = *src;
                    }
                    *dst = '\0';
                    printf("Valeur str: %s\n", str);  // Debug print
                    ((char**)tableau)[index] = str;
                }
                break;
            }
            case 'b':
                ((int*)tableau)[index] = (strcmp(token, "true") == 0) ? 1 : 0;
                break;
        }
        token = strtok_r(NULL, ",", &context);
        index++;
    }

    free(csvCopy);
    *taille = index;
    return tableau;
}

void initialiserTableau(Symbole *symbole, int taille) {
    char *resultat = malloc(taille * 16);
    if (!resultat) return;
    resultat[0] = '\0';

    char typeChar = getTypeChar(symbole->type);
    for (int i = 0; i < taille; i++) {
        if (typeChar == 'b') {
            strcat(resultat, "false"); // Initialisation par défaut pour boolean
        } else {
            strcat(resultat, "null");
        }
        if (i < taille - 1) strcat(resultat, ",");
    }

    symbole->valeur = resultat;
    symbole->taille = taille;
}

void modifierCase(Symbole *symbole, int index, void *nouvelleValeur) {
    if (index < 0 || index >= symbole->taille) {
        printf("Index invalide : %d\n", index);
        return;
    }
    char buffer[256];
    char typeChar = getTypeChar(symbole->type);
    switch (typeChar) {
        case 'i': // ENTIER
            snprintf(buffer, sizeof(buffer), "%d", *((int*)nouvelleValeur));
            break;
        case 'f': // FLOTTANT
            snprintf(buffer, sizeof(buffer), "%.2f", *((float*)nouvelleValeur));
            break;
        case 'c': // CHAR
            if (*((char*)nouvelleValeur) == '\0') {
                snprintf(buffer, sizeof(buffer), "null");
            } else {
                snprintf(buffer, sizeof(buffer), "%c", *((char*)nouvelleValeur));
            }
            break;
        case 's': // STRING
            if (*((char**)nouvelleValeur) == NULL) {
                snprintf(buffer, sizeof(buffer), "null");
            } else {
                snprintf(buffer, sizeof(buffer), "\"%s\"", (char*)nouvelleValeur);
            }
                printf("Nouvelle valeur: %s\n", (char*)nouvelleValeur);

            break;
        case 'b': // BOOLEAN
            snprintf(buffer, sizeof(buffer), "%s", *((int*)nouvelleValeur) ? "true" : "false");
            break;
        default:
            return;
    }

    char *csvCopy = strdup(symbole->valeur);
    char *token = strtok(csvCopy, ",");
    char nouvelleCSV[1024] = "";
    int position = 0;

    while (token != NULL) {
        if (position == index) {
            strcat(nouvelleCSV, buffer);
        } else {
            strcat(nouvelleCSV, token);
        }
        token = strtok(NULL, ",");
        if (token != NULL) strcat(nouvelleCSV, ",");
        position++;
    }

    free(csvCopy);
    free(symbole->valeur);
    symbole->valeur = strdup(nouvelleCSV);
}

void* lireCase(Symbole *symbole, int index) {
    if (index < 0 || index >= symbole->taille) {
        printf("Index invalide : %d\n", index);
        return NULL;
    }

    int taille;
    printf("Valeur CSV: %s\n", symbole->valeur);  // Debug print
    char *tableau = convertirCSVEnTableau(symbole->valeur, &taille, symbole->type);
    if (!tableau) {
        printf("Erreur lors de la conversion CSV en tableau\n");  // Debug print
        return NULL;
    }
        printf("Valeur table: %s\n", ((char**)tableau)[index]);  // Debug print

    void *resultat = NULL;
    char typeChar = getTypeChar(symbole->type);
    switch (typeChar) {
        case 'i': { // ENTIER
            int *val = malloc(sizeof(int));
            *val = ((int*)tableau)[index];
            resultat = val;
            break;
        }
        case 'f': { // FLOTTANT
            float *val = malloc(sizeof(float));
            *val = ((float*)tableau)[index];
            resultat = val;
            break;
        }
        case 'c': { // CHAR
            char *val = malloc(sizeof(char));
            *val = ((char*)tableau)[index];
            resultat = val;
            break;
        }
        case 's': { // STRING
            char *val = malloc(sizeof(char*));
            val = ((char**)tableau)[index] ? strdup(((char**)tableau)[index]) : NULL;
            resultat = val;
            break;
        }
        case 'b': { // BOOLEAN
            int *val = malloc(sizeof(int));
            *val = ((int*)tableau)[index];
            resultat = val;
            break;
        }
    }

    if (typeChar == 's') {
        for (int i = 0; i < taille; i++) {
            free(((char**)tableau)[i]);
        }
    }
    free(tableau);

    return resultat;
}