#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define HASHSIZE 1000
#define MAX 1000
typedef struct Nlist
{
		char *key;
		int count;
		struct Nlist *next;
}list;

typedef struct Tstore
{
		char *key;
		int count;
}store;

list *hashtab[MAX];
store sort[MAX];

unsigned int hash(char *s);
unsigned int hash_i(char *s);

list *lookup(char *s,int option);
int install(char *key,int option);

int key_comp(const void *a,const void *b);
int count_comp(const void *a,const void *b);

int main(int argc,char *argv[])
{
		int i;
		int comd_i=0,comd_n=0,N=0;
		char input[20];
		FILE *fp;
		fp = fopen(argv[argc-1],"r");
		if(argc == 1 || argc > 4)
		{
				printf("No file!\n");
				return 0;
		}
		else if(argc == 2)
		{
				if(strcmp(argv[1],"-n") == 0 || strcmp(argv[1],"-i") == 0)
				{
						printf("No file!\n");
						return 0;
				}
		}
		else if(argc == 3)
		{
				if(strcmp(argv[1],"-n") == 0)
						comd_n = 1;
				else if(strcmp(argv[1],"-i") == 0)
						comd_i = 1;
				else
				{
						printf("Wrong command!\n");
						return 0;
				}
		}
		else if(argc == 4)
		{
				if((strcmp(argv[1],"-n") == 0 && strcmp(argv[2],"-i") == 0)||(strcmp(argv[1],"-i") == 0 && strcmp(argv[2],"-n") == 0))
				{
						comd_n = 1;
						comd_i = 1;
				}
				else
				{
						printf("Wrong command!\n");
						return 0;
				}
		}
		
		while(fgets(input,20,fp) != NULL)
		{
				input[strlen(input)-1] = '\0';
				install(input,comd_i);
		}
		for(i=0; i<HASHSIZE; i++)
		{
				list *ptr = hashtab[i];
				while(ptr != NULL)
				{
						//strcpy(sort[N].key,ptr->key);
						sort[N].key = strdup(ptr->key);
						sort[N].count = ptr->count;
						N++;
						ptr = ptr->next;
				}
		}
		
		if(comd_n == 0)
		{
				qsort(sort,N,sizeof(store),key_comp);
				for(i=0;i<N;i++)
						printf("%s\t%d\n",sort[i].key,sort[i].count);
		}
		else if(comd_n == 1)
		{
				qsort(sort,N,sizeof(store),count_comp);
				for(i=0;i<N;i++)
						printf("%s\t%d\n",sort[i].key,sort[i].count);
		}
		return 0;
}

//form hash value
unsigned int hash(char *s)
{
		int len,i,hv=0;
		len = strlen(s);

		for (i = 0; i<len ; i++)
				hv = (hv << 5) + s[i];
		if(hv < 0)
				hv = hv * (-1);
		return hv % HASHSIZE;
}
unsigned int hash_i(char *s)
{
		int len,i,hv=0;
		len = strlen(s);
		for(i=0;i<len;i++)
		{
				int temp;
                if(s[i] >='A' && s[i] <='Z')
                		temp = s[i] + 32;
                else
                		temp = s[i];
                hv = (hv << 5) + temp;
		}
		if(hv < 0)
				hv = hv * (-1);
		return hv % HASHSIZE;
}

int type = 0;
// look for s in hashtab
list *lookup(char *s,int option)
{
		int hashvalue;
		list *ptr;
		if(option == 0)
				hashvalue = hash(s);
		else if(option == 1)
				hashvalue = hash_i(s);
	
		if(hashtab[hashvalue] == NULL)
				return NULL; //new hashvalue
		else 
		{
				ptr = hashtab[hashvalue];
				while(ptr != NULL)
				{
						if(option == 0)
						{
								if(strcmp(ptr->key,s) == 0)
								{
										return ptr; // same hashvalue and same word
								}
								else
										ptr = ptr->next;
								
						}
						else if(option == 1)
						{

								if(strcasecmp(ptr->key,s) == 0)
								{
										return ptr;
								}
								else
										ptr = ptr->next;
							
						}

				}
				if(ptr == NULL)
						type = 1;
				// same hashvalue but different word
		}
}

// put term in hashtab
int install(char *key,int option) 
{
		int hashvalue;
		if(option == 0)
				hashvalue = hash(key);
		else if(option == 1)
				hashvalue = hash_i(key);

		if (lookup(key,option) == NULL)
		{
				list *temp = (list *)malloc(sizeof(list));
				temp->key = strdup(key);
				//strcpy(temp->key,key);
				temp->count = 1;

				hashtab[hashvalue] = temp;
				temp->next = NULL;
		}
		else if (type == 1)
		{
				list *temp2 = (list *)malloc(sizeof(list));
				temp2->key = strdup(key);
				//strcpy(temp2->key,key);
				temp2->count = 1;

				temp2->next = hashtab[hashvalue];
				hashtab[hashvalue] = temp2;
		}
		else 
		{		
				list *temp = lookup(key,option);
				temp->count++;

		}
		type = 0;
}
int key_comp(const void *a,const void *b)
{
		return (strcmp((*(store*)a).key,(*(store*)b).key));
		//return (strcmp(((store *)a)->key,((store *)b)->key));
}
int count_comp(const void *a,const void *b)
{
		return ( (*(store *)b).count - (*(store *)a).count);
}


	



			


