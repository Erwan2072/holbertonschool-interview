# Projet : Insertion dans une Liste Chainee Triee

## Description
Ce projet consiste a implementer une fonction en C permettant d'inserer un nombre dans une liste chainee simple triee de maniere ascendante. L'objectif est de maintenir l'ordre croissant de la liste apres l'insertion.

## Fonctionnalites
- Creation d'une structure de liste chainee simple.
- Insertion d'un nouvel element tout en maintenant l'ordre de tri.
- Affichage de tous les elements de la liste.
- Libération de la memoire allouee dynamiquement pour eviter les fuites de memoire.

## Fichiers
- **lists.h** : Fichier d'en-tete contenant la definition de la structure de la liste chainee et les prototypes des fonctions.
- **linked_lists.c** : Contient les fonctions d'affichage, d'ajout de noeud a la fin de la liste et de liberation de la memoire.
- **0-insert_number.c** : Implementation de la fonction `insert_node` permettant d'inserer un nombre dans la liste triee.
- **0-main.c** : Fichier principal pour tester la fonctionnalite d'insertion et d'affichage de la liste.

## Prototype de la Fonction
```c
listint_t *insert_node(listint_t **head, int number);
```
- **head** : Pointeur vers le pointeur de tete de la liste.
- **number** : Nombre a inserer dans la liste.
- **Return** : L'adresse du nouveau noeud ou `NULL` en cas d'echec d'allocation de memoire.

## Compilation et Execution
### Compilation
```bash
gcc -Wall -Werror -Wextra -pedantic 0-main.c linked_lists.c 0-insert_number.c -o insert
```

### Execution
```bash
./insert
```

## Exemple de Sortie
```bash
0
1
2
3
4
98
402
1024
-----------------
0
1
2
3
4
27
98
402
1024
```

## Contraintes
- Le code doit suivre la norme de style Betty.
- Interdiction d'utiliser des variables globales.
- Pas plus de 5 fonctions par fichier.
- Tous les fichiers doivent se terminer par une nouvelle ligne.

## Outils Utilises
- **Editeurs autorises** : vi, vim, emacs.
- **Compilation** : gcc 4.8.4 avec les flags `-Wall -Werror -Wextra -pedantic`.
- **OS cible** : Ubuntu 14.04 LTS.

## Licence
Projet realise dans le cadre de l'ecole Holberton School. Ce projet est destine a l'apprentissage et a l'amelioration des competences en C.

