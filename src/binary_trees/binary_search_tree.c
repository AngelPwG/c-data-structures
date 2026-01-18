#include<stdio.h>
#include<malloc.h>

struct Tree{
	int valor;
	struct Tree *left;
	struct Tree *right;
};

void insert (struct Tree **root, int n);
void free_tree (struct Tree **root);
void show (struct Tree *root, int n);
struct Tree *search (struct Tree *root, int n);
void inorder (struct Tree *root);
void preorder (struct Tree *root);
void postorder (struct Tree *root);

int main(){
	int op, num;
	struct Tree *root = NULL;
	do{
		printf("1. Insert\n");
		printf("2. Search\n");
		printf("3. Show\n");
		printf("4. Inorder\n");
		printf("5. Postorder\n");
		printf("6. Preorder\n");
		printf("7. Exit\n");
		printf("Choose an option: ");
		scanf("%i",&op);
		switch(op){
			case 1:
				printf("Enter value: ");
				scanf("%i", &num);
				insert(&root, num);
				break;
			case 2:
				printf("Enter value to search: ");
				scanf("%i", &num);
				if(search(root, num) == NULL)
					printf("Not Found\n");
				else
					printf("Found\n");
				getchar();
				break;
			case 3:
				printf("Tree Structure\n");
				show(root, 0);
				getchar();
				break;
			case 4:
				printf("Inorder");
				inorder(root);
				printf("\n");
				getchar();
				break;
			case 5:
				printf("Postorder");
				postorder(root);
				printf("\n");
				getchar();
				break;
			case 6:
				printf("Preorder");
				preorder(root);
				printf("\n");
				getchar();
				break;
			default:
				printf("Choose a valid option \n");
				break;
			}
	}while(op!=7);
	free_tree(&root);
	return 0;
}

void insert (struct Tree **root, int n){
	if(*root == NULL){
		*root = (struct Tree *) malloc(sizeof(struct Tree));
		(*root)->valor = n;
		(*root)->left = NULL;
		(*root)->right = NULL;
	}
	else if((*root)->valor > n)
		insert(&((*root)->left), n);
	else if((*root)->valor < n)
		insert(&((*root)->right), n);
	else{
		printf("Duplicated number");
		getchar();
	}
}

void show(struct Tree *root, int n){
	int i;
	if (root == NULL)
		return;
	show(root->right, n + 1);
	for(i = 0; i < n; ++i)
		printf("   ");
	printf("%d\n", root->valor);
	show(root->left, n + 1);
}

struct Tree *search(struct Tree *root, int n){
	if(root == NULL)
		return NULL;
	else if(n == root->valor)
		return root;
	else if(n > root->valor)
		return search(root->right, n);
	else
		return search(root->left, n);
}

void inorder (struct Tree *root){
	if (root == NULL)
        return;
    inorder(root->left);
    
    printf("%d, ", root->valor);
    
    inorder(root->right);
}

void preorder (struct Tree *root){
	if (root == NULL)
        return;
    printf("%d, ", root->valor);
    
    preorder(root->left);
    
    preorder(root->right);
}

void postorder (struct Tree *root){
	if (root == NULL)
        return;
    postorder(root->left);
    
    postorder(root->right);
    
    printf("%d, ", root->valor);
}

void liberar (struct Tree **root){
	if (*root == NULL) 
		return;
    free_tree(&((*root)->left));
    free_tree(&((*root)->right));
    free(*root);
    *root = NULL;
}
