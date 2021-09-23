#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "wrappers.h"
#include "tree.h"

#define MAXWORD     64                              // longest word

int
main(int argc, char *argv[])
{
    FILE *fp;
    char word[MAXWORD];
    struct treenode *root = NULL;                   // binary tree root
    extern int fgetword(FILE *fp, char *word, int lim);
    extern void convert2alpha(char *word);

    if (argc == 1) {                                // no arguments, reads from stdin
        fp = stdin;
    } else {                                        // uses first argument only
        fp = fopen_or_exit(argv[1], "r");
    }

    while (fgetword(fp, word, MAXWORD) != '\0') {
        convert2alpha(word);
        if (*word != '\0') {
            root = tree_add(root, word);
        }
    }

    if (root != NULL) {
        tree_print(root);
    }

    exit(EXIT_SUCCESS);
}
