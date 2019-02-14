#include "bintree.h"

tree create_tree(){
    node *empty_root = NULL;
    return empty_root;
}

node *find_node(tree t, int key){
    node *current_node = t;
    while((current_node->key != key) && (current_node != NULL)){
        if (key >= current_node->key){
            current_node = current_node->right;
        }
        else{
            current_node = current_node->left;
        }
    }
    if (current_node == NULL){
        printf("Node not found! Returning NULL...\n");
    }
    return current_node;
}

tree insert_node(tree t, int key, int value){
    node *new_node = malloc(sizeof(node));
    new_node->key = key;
    new_node->value = value;
    new_node->left = NULL;
    new_node->right = NULL;

    // finding the parent node

    node *candidate_node = t; 
    node *candidate_parent = NULL;
    while(candidate_node != NULL){
        candidate_parent = candidate_node;
        if (key >= candidate_node->key){
            candidate_node = candidate_node->right;
        }
        else{
            candidate_node = candidate_node->left;
        }
    }

    new_node->parent = candidate_parent;
    if (candidate_parent == NULL){ // if the tree is empty
        return new_node;
    }
    else if (key >= candidate_parent->key){
        candidate_parent->right = new_node;
    }
    else{
        candidate_parent->left = new_node;
    }
    return t;
}

tree delete_node(tree t, node *n){
    if (n == NULL){
        printf("There is no way to delete an inexistent node...\n");
        return t;
    }

    node *parent = n->parent;
    int is_right = 0;
    if (n->key >= parent->key)  is_right = 1;

    if ((n->left == NULL) && (n->right == NULL)){
        if (parent != NULL){
            if (is_right){
                parent->right = NULL;
            }
            else{
                parent->left = NULL;
            }
        }
        free(n);
    }

    else if ((n->left == NULL) != (n->right == NULL)){
        node *only_child = n->left;
        if (only_child == NULL){
            only_child = n->right;
        }

        if (parent != NULL){
            if (is_right){
                parent->right = only_child;
            }
            else{
                parent->left = only_child;
            }
        }

        only_child->parent = parent;
        free(n);
    }

    else{
        node *successor = successor_node(n);
        int suc_key = successor->key;
        int suc_val = successor->value;

        delete_node(t,successor);

        n->key = suc_key;
        n->value = suc_val;
    }

    return t;
}

node *successor_node(node* n){
    node *next = n->right;
    while (next->left != NULL){
        next = next->left;
    }
    return next;
}

node *antecessor_node(node* n){
    node *next = n->left;
    while (next->right != NULL){
        next = next->right;
    }
    return next;
}

void walk_inorder(tree t){
    if (t == NULL) return;

    if (t->parent == NULL)  printf("Inorder walk:\n");

    walk_inorder(t->left);

    printf("\tKey: %d\n",t->key);

    walk_inorder(t->right);
}

void free_tree(tree t){
    if (t == NULL)  return;

    free_tree(t->left);
    free_tree(t->right);

    free(t);
}
