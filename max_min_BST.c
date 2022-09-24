//Searching using sir's Algorithm
#include <stdio.h>
#include <stdlib.h>

struct node* createNode (int data);
struct node* search (struct node *root, int key);
struct node* max(struct node *x);
struct node* min(struct node *x);
void inOrder (struct node *root);

struct node {
    int data;
    struct node *left;
    struct node *right;
};

struct node *p;

int main ()
{
    printf("The root for this BST is : 5\n");

    p = createNode(5);
    //other
    struct node *p1 = createNode(3);
    struct node *p2 = createNode(7);
    struct node *p3 = createNode(2);
    struct node *p4 = createNode(4);
    struct node *p5 = createNode(1);
    struct node *p6 = createNode(6);
    struct node *p7 = createNode(10);

    //linking the node with left and right children
    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;
    p3->left = p5;
    p2->left = p6;
    p2->right = p7;

    /*the tree is :

               5
             /    \
            3      7
           / \    / \
          2   4  6   10
         /
        1                    */


    printf("In order sequence for the BST is : Left -> Root -> Right\n");
    inOrder(p); // BST will be sorted

    int key;

    printf("\nInput the element you want to search in the BST : ");
    scanf("%d", &key);

    struct node *x = search (p, key);

    if (x != NULL){
        printf("%d found in the BST.\n", (search (p, key))->data);
    }
    else{
        printf("NOT found!\n");
    }

    printf("The Minimum element in BST is : %d\n", min(p)->data);

    printf("The Maximum element in BST is : %d\n", max(p)->data);

}

struct node* createNode (int data)
{
    struct node *n = (struct node*) malloc(sizeof(struct node));

    n->data = data;
    n->left = NULL;
    n->right = NULL;

    return n;//returning the created node
}

void inOrder (struct node *root)
{
    if (root != NULL){
        inOrder (root->left);
        printf("%d ", root->data);
        inOrder (root->right);
    }
}

struct node* search (struct node *root, int key)
{
    if (root == NULL || key == root->data){
        return root;
    }

    else if (key < root->data){
        return search (root->left, key);
    }

    else {
        return search (root->right, key);
    }
}

struct node* max(struct node *x)
{
    while (x->right != NULL){
        x = x->right;
    }

    return x;
}

struct node* min(struct node *x)
{
    while (x->left != NULL){
        x = x->left;
    }

    return x;
}

