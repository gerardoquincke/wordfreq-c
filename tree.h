struct treenode {
    char *word;
    int count;
    struct treenode *left, *right;
};


extern struct treenode * treenode_new(char *word);
extern struct treenode * tree_add(struct treenode *node, char *word);
extern void tree_print(struct treenode *node);
