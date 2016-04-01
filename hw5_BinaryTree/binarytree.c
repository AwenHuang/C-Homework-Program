#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 1000

typedef struct Treearray
{
		int count;
		char data[20];
}array;

array tree_array[MAX];

typedef struct BinaryTree
{
		int count;
		char data[20];
		struct BinaryTree *left;
		struct BinaryTree *right;
}tree;

tree *root = NULL;

int N=0;

tree* insert(tree *ptr,char *term);
tree* insert_i(tree *ptr,char *term);
void run(tree *ptr);
int comp(const void *a,const void *b);


int main(int argc,char *argv[])
{
		int k,j;
		int i=0,n=0;
		char input[20];
		FILE *fp; //define a file pointer

		if(argc == 2)
		{
				if(strcmp(argv[1],"-i")!=0 || strcmp(argv[1],"-n")!=0)
						k=1;
				else
						return 0;
		}
		else if(argc == 3)
		{
				if(strcmp(argv[1],"-i") == 0)
				{
						k=2;
 		        		i=1;
 		        }
 		        else if(strcmp(argv[1],"-n") == 0)
 		        {
 		        		k=2;
 		        		n=1;
 		        }
 		        else
 		        		return 0;
 		}
 		else if(argc == 4)
 		{
 		        if(strcmp(argv[1],"-i")==0 || strcmp(argv[2],"-n")==0)
 		        {
 		        		k=3;
 		        		i=1;
 		        		n=1;
 		        }
 		        else if(strcmp(argv[1],"-n")==0 || strcmp(argv[2],"-i")==0)
 		        {
 		        		k=3;
 		        		i=1;
 		                n=1;
 		        }
 		        else
 		        		return 0;
		}
		else
				return 0;

		fp = fopen(argv[k],"r");

		while(fgets(input,20,fp) != NULL)
		{
				int j;
				input[strlen(input)-1]='\0';
				if(i==0)
						root = insert(root,input);
				else if(i==1)
						root = insert_i(root,input);
		}
		
		run(root);
		
		if(n == 0)
		{
				for(j=0;j<N;j++)
						printf("%s %d\n",tree_array[j].data,tree_array[j].count);
		}
		else if(n == 1)
		{
				qsort(tree_array,N,sizeof(tree_array[0]),comp);
				for(j=0;j<N;j++)
						printf("%s %d\n",tree_array[j].data,tree_array[j].count);
		}

				
		return 0;
}

int comp(const void *a,const void *b)
{
		return ((*(array *)b).count - (*(array *)a).count);
}

tree* insert_i(tree *ptr,char *term)
{
		int i;
		for(i=0;i<strlen(term);i++)
				term[i]=tolower(term[i]);
		
		if(ptr == NULL)
		{
				ptr=(tree *)malloc(sizeof(tree));
				strcpy(ptr->data,term);
				ptr->count=1;

				ptr->left = NULL;
				ptr->right = NULL;
		}
		else
		{				
						if(strcmp(term,ptr->data)<0)
								ptr->left = insert(ptr->left,term);
						else if(strcmp(term,ptr->data)>0)
								ptr->right = insert(ptr->right,term);
						else
								ptr->count++;
		}
				return ptr;
}
tree* insert(tree *ptr,char *term)
{
		
		if(ptr == NULL)
		{
				ptr=(tree *)malloc(sizeof(tree));
				strcpy(ptr->data,term);
				ptr->count=1;

				ptr->left = NULL;
				ptr->right = NULL;
		}
		else
		{				
						if(strcmp(term,ptr->data)<0)
								ptr->left = insert(ptr->left,term);
						else if(strcmp(term,ptr->data)>0)
								ptr->right = insert(ptr->right,term);
						else
								ptr->count++;
		}
				return ptr;
}

void run(tree *ptr)
{
		if(ptr != NULL)
		{
				run(ptr->left);
				//printf("%s\t%d\n",ptr->data,ptr->count);
				
				strcpy(tree_array[N].data,ptr->data);
				tree_array[N].count = ptr->count;
				N++;
				
				run(ptr->right);

		}
}







		

		
		
	

		
		

