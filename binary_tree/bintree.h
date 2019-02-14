#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int key;
    int value;
    struct node *parent;
    struct node *left;
    struct node *right;
} node;

typedef node *tree;

tree create_tree();

node *find_node(tree t, int key);

tree insert_node(tree t, int key, int value);

tree delete_node(tree t, node *n);

node *successor_node(node* n);

node *antecessor_node(node *n);

void walk_inorder(tree t);

//void walk_preorder(tree t);
//
//void walk_postorder(tree t);

void free_tree(tree t);
