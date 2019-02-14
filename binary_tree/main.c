#include "bintree.h"

int main(){
    tree t = create_tree();

    // add 20 nodes with random keys
    int i;
    int n_nodes = 20;
    int nodes_added[n_nodes];
    for (i=0; i<n_nodes; i++){
        int k = rand() % 100;
        nodes_added[i] = k;
        int val = k+1;
        t = insert_node(t, k, val);
    }

    walk_inorder(t);
    
    printf("Finding 5th added node, of key %d!\n",nodes_added[4]);
    node *fifth = find_node(t, nodes_added[4]);
    
    if ((fifth->left != NULL) && (fifth->right != NULL)){
        printf("The node has two children!\n");
    }
    printf("Node value: %d\n",fifth->value);
    t = delete_node(t, fifth);

    walk_inorder(t);

    free_tree(t);

    return 0;
}
