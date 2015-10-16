#include <stdio.h>
#include <stdlib.h>



struct bin_tree {
	int data;
	struct bin_tree * right, * left;
};
typedef struct bin_tree node;

void insert(node ** tree, int val)
{
    node *temp = NULL;
    if(!(*tree))
    {
        temp = (node *)malloc(sizeof(node));
        temp->left = temp->right = NULL;
        temp->data = val;
        *tree = temp;
        return;
    }

    if(val < (*tree)->data)
    {
        insert(&(*tree)->left, val);
    }
    else if(val > (*tree)->data)
    {
        insert(&(*tree)->right, val);
    }

}

void print_preorder(node *tree)
{
    if (tree)
    {
        printf("%d\n",tree->data);
        print_preorder(tree->left);
        print_preorder(tree->right);
    }

}

void print_inorder(node *tree)
{
    if (tree)
    {
        print_inorder(tree->left);
        printf("%d\n",tree->data);
        print_inorder(tree->right);
    }
}

void print_postorder(node *tree)
{
    if (tree)
    {
        print_postorder(tree->left);
        print_postorder(tree->right);
        printf("%d\n",tree->data);
    }
}

void deltree(node *tree)
{
    if (tree)
    {
        deltree(tree->left);
        deltree(tree->right);
        free(tree);
    }
}

node* search(node ** tree, int val)
{
    if(!(*tree))
    {
        return NULL;
    }

    if(val < (*tree)->data)
    {
        search(&((*tree)->left), val);
    }
    else if(val > (*tree)->data)
    {
        search(&((*tree)->right), val);
    }
    else if(val == (*tree)->data)
    {
        return *tree;
    }
}



int main() {


	// Problem 1 
	
	int a[]= {12,23,34,45,56,67,78,89,90};
	int *p;
	p=a;
	printf("%p\n", p);

	printf ("int a[]= {12,23,34,45,56,67,78,89,90};\n\n\n\n");
	
	printf("1. *p+2             %d \t\t\t\t Dereferencing the first index in p, which is the same as a, and adds 2: 12+2=14  \n", *p+2);
	printf("2. *(p+2)           %d \t\t\t\t Dereferencing the third element in the array\n", *(p+2));
	printf("3. &p+1             %p \t\t The adress of p+1?\n", &p+1);
	printf("4. &a[4]-3          %p \t\t Prints the adress of a memory location 8 bytes from the first index of a \n", &a[4]-3);
	printf("5. a+3              %p \t\t Prints the memory location if the 4th element in the array\n", a+3);
	printf("6. &a[7]-p          %ld \t\t\t\t Prints the difference of the memory adresses of the 8th and first element in a\n", &a[7]- p );
	printf("7. p+(*p-10)        %p \t\t\t Adds 12-10=2 to the memory location of a\n", p + (*p-10));
	printf("8. *(p+*(p+8)-a[7]) %d \t\t\t\t Evaluates the exp inside the paratesis as *(p+1) = 23\n", *(p+*(p+8)-a[7]));
	


	// Problem 2
	
	node *root;
	node *tmp;

	root = NULL;
	insert(&root, 10);
	insert(&root, 5 );
	insert(&root, 8 );
	insert(&root, 19);
	insert(&root, 50);
	insert(&root, 14);
	insert(&root, 12);
	insert(&root, 10);
 	
	printf("\n\npre\n\n");
	print_preorder(root);
	printf("\n\n inorder\n\n");
	print_inorder(root);
	printf("\n\n post\n\n");
	print_postorder(root);

	deltree(root);
	
return 0;
}
