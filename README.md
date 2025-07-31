# get_next_line

Ce projet est un exercice classique de l'école 42 qui consiste à implémenter une fonction `get_next_line` capable de lire une ligne depuis un descripteur de fichier à chaque appel, de manière efficace et sans fuite de mémoire.

## Objectif

L'objectif est de fournir une fonction qui retourne la ligne suivante lue depuis un fichier (ou l'entrée standard), à chaque appel, jusqu'à la fin du fichier. La fonction doit gérer un buffer interne et être capable de fonctionner même si la ligne dépasse la taille du buffer.

## Fichiers principaux

- `get_next_line.c` : Contient l'implémentation principale de la fonction `get_next_line`.
- `get_next_line.h` : Header associé.
- `get_next_line_utils.c` : Fonctions utilitaires (gestion de chaînes, etc).
- Les versions bonus sont dans les fichiers `*_bonus.c` et `*_bonus.h`.

## Utilisation

### Compilation

Pour compiler le projet, utilisez `gcc` (ou tout autre compilateur C) en incluant les fichiers nécessaires. Par exemple :

```sh
gcc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c -o gnl
```

Vous pouvez ajuster la valeur de `BUFFER_SIZE` selon vos besoins.

### Exemple d'utilisation

Voici un exemple de programme pour lire un fichier ligne par ligne :

```c
#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"

int main(void) {
    int fd = open("mon_fichier.txt", O_RDONLY);
    char *line;
    while ((line = get_next_line(fd)) != NULL) {
        printf("%s", line);
        free(line);
    }
    close(fd);
    return 0;
}
```

### Arguments attendus

- `fd` : le descripteur de fichier à lire (obtenu via `open`).
- `BUFFER_SIZE` : à définir à la compilation (taille du buffer de lecture).

### Exécution

Après compilation, lancez l'exécutable en ligne de commande. Par exemple :

```sh
./gnl
```

## Remarques

- Le projet respecte les normes de l'école 42 (pas de fonction interdite, gestion stricte de la mémoire).
- Les versions bonus permettent la gestion de plusieurs descripteurs de fichiers simultanément.
