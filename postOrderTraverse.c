#include <stdio.h>
#include <stdlib.h>
struct node* createNode (int data);
void postOrder (struct node *root);

struct node {
    int data;
    struct node *left;
    struct node *right;
};

int main ()
{
    int root;

    printf("What is the root?\n");
    scanf("%d", &root);

    struct node *p = createNode(root);
    //other
    struct node *p1 = createNode(4);
    struct node *p2 = createNode(9);
    struct node *p3 = createNode(0);
    struct node *p4 = createNode(2);
    struct node *p5 = createNode(11);
    struct node *p6 = createNode(6);
    struct node *p7 = createNode(20);

    //linking the node with left and right children
    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;
    p3->left = p5;
    p2->left = p6;
    p2->right = p7;

    /*the tree is :
               root
             /     \
            4       9
          / \      / \
         0   2   6   20
        /
      11                    */

    printf("Post order sequence is : Left -> Right -> Root\n");
    postOrder(p);
}

struct node* createNode (int data)
{
    struct node *NODE = (struct node*) malloc(sizeof(struct node));

    NODE->data = data;
    NODE->left = NULL;
    NODE->right = NULL;

    return NODE; //returning the created node
}

void postOrder (struct node *root)
{
    if (root != NULL){
        postOrder (root->left);
        postOrder (root->right);
        printf("%d ", root->data);
    }
}
