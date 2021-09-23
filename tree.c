#include "tree.h"
#include "wrappers.h"
#include <string.h>

/* struct defined in tree.h
struct treenode {           // simple binary tree node
    char *word;             // node key = word
    int count;              // number of ocurrences of the word
    struct treenode *left, *right; // left and right subtree pointers
};
*/


struct treenode *
treenode_new(char *word)
{
    // creates a new treenode with the word argument and count=1, returns pointer to new treenode
    struct treenode *node;

    node = malloc_or_exit(sizeof(struct treenode));
    node->word = malloc_or_exit(strlen(word) + 1);
    strcpy(node->word, word);
    node->count = 1;
    node->left = node->right = NULL;
    return node;
}

struct treenode *
tree_add(struct treenode *node, char *word)
{
    // recursively looks up word in the node, if found, increments count, if not, inserts new node
    int cmp;

    if (node == NULL) {                                 // inserts new node
        node = treenode_new(word);
    } else if ( (cmp=strcmp(word, node->word)) == 0) {  // found: increments count
        node->count++;
    } else if (cmp < 0) {                               // recursively looksup/inserts word in the left tree
        node->left = tree_add(node->left, word);
    } else {                                            // recursively looksup/inserts word in the right tree
        node->right = tree_add(node->right, word);
    }
    return node;
}

void
tree_print(struct treenode *node)
{
    // recursively prints tree words and count, in order

    if (node != NULL) {
        tree_print(node->left);                         // first print left subtree
        printf("%6d %s\n", node->count, node->word);    // then print node contents
        tree_print(node->right);                        // finally print right subtree
    }
}

