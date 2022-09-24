#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* left;
    struct node* right;
    struct node* parent;
};

struct node *root = NULL;


/*FUNCTION Prototypes*/

//Creating a function for new node
struct node* newnode(int key);
//Finding MAX value
struct node* Extract_max(struct node* x);
//Finding MIN value
struct node* Extract_min(struct node* x);
//Inserting element in BST
struct node* Insert(struct node *root, int key);
//inorder Traversal = Sorted data
void inorder(struct node* root);
//Search element
struct node* Tree_search(struct node *x, int k);
//finding Successor
struct node* Tree_successor(int val);
//delete
void Tree_delete(int key);


int main()
{
    freopen ("BST.txt", "r", stdin);

    int n;
    printf("How many elements do you want to insert in BST?\n");
    scanf("%d", &n);

    //Inserting elements to the BST
    int r;
    printf("Enter the root of the binary search tree : \n");
    scanf("%d", &r);

    root = Insert(root, r);

    printf("Enter the other elements of binary search tree :\n");
    for(int i=1; i<n; i++){
        int x;
        scanf("%d",&x);
        Insert(root,x);
    }

    //BST inorder traverse
    printf("\nPrinting in inorder format we have : \n");
    inorder(root);
    printf("\n");

    //min value
    struct node *max = Extract_max(root);
    printf("\nMaximum value is : %d\n", max->data);

    //max value
    struct node *min = Extract_min(root);
    printf("Minimum value is : %d\n", min->data);

    //search
    printf("\nEnter the element you want to search : \n");
    int a;
    scanf("%d", &a);

    struct node *search = Tree_search(root,a);

    if(search == NULL){
        printf("Element not found\n");
    }
    else {
        printf("%d Found in the BST\n",search->data);
    }

    //Successor
    printf("\nFor which element you want to find Successor?\n");
    scanf("%d", &a);

    struct node *success = Tree_successor(a);

    printf("Successor is %d for the element %d\n", success->data, a);

    //delete
    printf("\nEnter the element you want to delete : \n");
    scanf("%d", &a);

    Tree_delete(a);

    printf("After deletion :\n");

    inorder(root);
    printf("\n");

    getch();
    return 0;
}


/*Other FUNCTIONS*/

struct node* newnode(int key)
{
    struct node *temp = (struct node*)malloc(sizeof(struct node));

    temp->data = key;
    temp->left = temp->right = temp->parent = NULL;

    return temp;
}

//Finding MAX value
struct node* Extract_max(struct node* x)
{
    while(x->right != NULL){
        x = x->right;
    }

    return x;
}

//Finding MIN value
struct node* Extract_min(struct node* x)
{
    while(x->left != NULL){
        x = x->left;
    }

    return x;
}

//Inserting element in BST
struct node* Insert(struct node *root, int key)
{
    struct node *y = NULL;
    struct node *x = root;
    struct node *z = newnode(key);

    while(x != NULL){
        y = x;

        if(z->data < x->data){
            x = x->left;
        }
        else {
            x = x->right;
        }
    }

    z->parent = y;

    if(y == NULL){
        root = z;
    }
    else if(z->data < y->data){
        y->left = z;
    }
    else y->right = z;

    return root;
}

//inorder Traversal = Sorted data
void inorder(struct node* root)
{
    if (root != NULL) {

        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

//Search element
struct node* Tree_search(struct node *x, int k)
{
    if (x == NULL || k == x->data){
        return x;
    }
    if(k < x->data){
        return Tree_search(x->left, k);
    }
    else {
        return Tree_search(x->right, k);
    }
}

/*
ITERATIVE tree search

struct node* IterativeTreeSearch (struct node *x, int k)
{
    while (x != NULL && k != x->data){
        if (k < x->data) x = x->left;
        else x = x->right;
    }

    return x;
}
*/


//finding Successor
struct node* Tree_successor(int val)
{
    struct node* x = Tree_search(root, val);

    if (x->right != NULL){
        return Extract_min(x->right);
    }

    struct node *y = x->parent;

    while(y != NULL && x == y->right){
        x = y;
        y = y->parent;
    }

    return y;
}

void Tree_delete(int key)
{
    struct node *z = Tree_search(root, key);
    struct node *y;
    struct node *x;

    if (z->left == NULL || z->right == NULL){
        y = z;
    }
    else {
        y = Tree_successor(z->data);
    }

    if (y->left != NULL){
        x = y->left;
    }
    else x = y->right;

    if (x != NULL){
        x->parent = y->parent;
    }
    if (y->parent == NULL){
        root = x;
    }
    else if (y == y->parent->left){
        y->parent->left = x;
    }
    else y->parent->right = x;

    if (y != z){
        z->data = y->data;
    }

}

//RED Blood Tree
