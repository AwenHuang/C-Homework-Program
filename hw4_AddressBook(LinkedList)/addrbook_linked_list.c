#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 1000

void addnode_beg(char *n1,char *n2);
void addnode_end(char *n1,char *n2);
int delnode(char *del_name,int option);

typedef struct TNode
{
		struct TNode *next;
		char name[MAX];
		char phone[MAX];
}Node;

Node *head = NULL; //set head as NULL which means list is empty

int main(int argc,char *argv[])
{
		int comd;
		int n=0;
		char buf[MAX];
		char *store[MAX];
		char *ptr;
		FILE *fp; //define a file pointer
		

		fp = fopen(argv[1],"r"); //open file argv[1],and read-only mode("r")

		while(1)
		{
				
				printf("--------------------\n1)list\n2)find\n3)insert\n4)delete\n5)exit\nPlease enter command:");
				scanf("%d",&comd);
				
				while(fgets(buf,MAX,fp) != NULL)
				{
						ptr=strtok(buf,"\t\n:");
						while(ptr != NULL)
						{
								store[n]=(char *)malloc(100);
								strcpy(store[n],ptr);
								n++;
								ptr=strtok(NULL,"\t\n:");
						}
						
					
						addnode_end(store[1],store[3]);
						n=0;
				}
				
				Node *list=head;//讓list_node指向第一個資料
				
				if(comd == 1)
				{
						if(list == NULL) // list is empty
						{
								printf("empty\n");
						}
						else
						{
								printf("\nName\tPhone\n--------------------\n");
								while(list != NULL) // let list_node travel the list to the end
								{
										printf("%s\t%s\n",list->name,list->phone);
						        		list=list->next;
						
								}
						}
				}
				else if(comd == 2)
				{
						char search[20];
						int comd_2;
						fpurge(stdin);//clear standard input
						printf("Please input the search name:");
						fgets(search,20,stdin);

						search[strlen(search)-1]='\0';

						printf("\nName\tPhone\n--------------------\n");
					
					
						while(list != NULL)
						{
								if(strcmp(list->name,search)==0)
								{
										printf("%s\t%s\n",list->name,list->phone);
										printf("--------------------\n\n1)delete it\n2)back to main menu\nPlease enter command:");
										scanf("%d",&comd_2);
										if(comd_2==1)
										{
												delnode(list->name,2);
												break;
										}
										else if(comd_2==2)
												break;
										else
										{
												printf("\ncommand is wrong!\nPlease check and enter again!\n");
												printf("\nName\tPhone\n--------------------\n");
												continue;
										}
										//list=list->next;
										
								}
								else
								{
										list=list->next;
								}

						}
						
						if(list == NULL)
								printf("Not found\n");
						
				}
				
				else if(comd == 3)//insert a data at front of the list
				{
						int comd_3,comd_already;
				
						char input_name[20];
						char input_phone[20];
					
						while(1)
						{
								fpurge(stdin);

								printf("input name:");
								fgets(input_name,20,stdin);
								input_name[strlen(input_name)-1]='\0';
								
								if(strlen(input_name)==0 || input_name[0]==' ')
								{
										printf("\nCan not input a empty name!\nPlease input again!\n\n");
										continue;
								}
								printf("input phone:");
								fgets(input_phone,20,stdin);

								//input_name[strlen(input_name)-1]='\0';
								input_phone[strlen(input_phone)-1]='\0';
								
								while(list != NULL)
								{
										if(strcmp(list->name,input_name)==0)
										{
												printf("\nThis name is already in the list!\n");
												printf("--------------------\n1)back to main menu\n2)override\nPlease enter command:");
												scanf("%d",&comd_already);
												if(comd_already == 1)
														break;
												else if(comd_already == 2)
												{
														strcpy(list->phone,input_phone);
														break;
												
												}
												else
												{
														printf("\ncommand is wrong!\nPlease check and enter again!\n");
														continue;
												}
										}
										list=list->next;
								}
						
								if(list == NULL)//掃完資料確定沒有一樣的名字,新增資料
										addnode_beg(input_name,input_phone);
								
								
					

								fpurge(stdin);
								printf("--------------------\n1)back to main menu\n2)insert next data\nPlease enter command:");
								scanf("%d",&comd_3);
								
								if(comd_3 == 1)
										break;
								else if(comd_3 == 2)
										continue;
								else
								{
										printf("\ncommand is wrong!\nBack to main menu!\n\n");
										break;
								}
								
										
						}
				
				}
				else if(comd == 4)
				{
						int comd_4;
						char del_name[20];
						while(1)
						{
								fpurge(stdin);

								printf("Please input the name will be deleted:");
								fgets(del_name,20,stdin);

								del_name[strlen(del_name)-1]='\0';

								if(delnode(del_name,4)==0)//want to delet the next data
										continue;
								else // don't want to delet back to main menu
										break;
						}
								
				}
				else if(comd == 5)
						break;
				else
				{
						printf("\ncommand is wrong!\nPlease check and enter again!\n");
						continue;
				}
		}
	return 0;	
}

void addnode_end(char *n1,char *n2)//addnode after the list
{
		Node *temp1,*temp2;
		
		temp1=(Node *)malloc(sizeof(Node));//放資料的

		strcpy(temp1->name,n1);
		strcpy(temp1->phone,n2);

		temp2=head;//copying the head location into another node

		if(head == NULL)//list is empty
		{
				head=temp1;//create the first node in the list
				head->next=NULL;
		}
		else //list is not empty
		{
				//let temp2 travel the list to the end
				while(temp2->next != NULL) 
						temp2=temp2->next;

				temp2->next=temp1; //add data to the end of list
				temp1->next=NULL;
		}
}
void addnode_beg(char *n1,char *n2)//addnode in front of the list
{
		Node *temp;

		temp=(Node *)malloc(sizeof(Node));
		
		strcpy(temp->name,n1);
		strcpy(temp->phone,n2);
		
		if(head == NULL)//list is empty
		{
				head=temp; //create the first node in the list
				head->next=NULL;
		}
		else //list is not empty
		{
				temp->next=head;//let list's head be temp's next
				head=temp; // list's head be temp's head
		}								
		//printf("%s\t%s\n",temp->name,temp->phone);
}

int delnode(char *del_name,int option)
{
		char choose[10];
		int comd_4;
		Node *prev_ptr,*cur_ptr;

		cur_ptr=head;
	
		while(cur_ptr != NULL)//let cur_ptr travel the list 
		{
				if(strcmp(cur_ptr->name,del_name) != 0)//還沒找到要刪除的資料
				{
						prev_ptr = cur_ptr;
						cur_ptr = cur_ptr->next;
				}
				else if(strcmp(cur_ptr->name,del_name) == 0)//找到要刪除的資料
				{
						printf("\nName\tPhone\n--------------------\n");
						printf("%s\t%s\n",cur_ptr->name,cur_ptr->phone);
						printf("\ndelete it?(yes/no):");
						scanf("%s",choose);

						if(strcmp(choose,"yes") == 0)
						{	
								if(cur_ptr == head)//如果要刪除的資料是第一筆資料(開頭)
								{
										head = cur_ptr->next;
										free(cur_ptr);
								}
								else //如果要刪除的資料不是第一筆
								{
										prev_ptr->next = cur_ptr->next;
										free(cur_ptr);
								}
								
								if(option == 4)//是在command(4)下的delet,刪完資料會繼續詢問
								{
										printf("\n1)back to main menu\n2)delete next data\nPlease enter command:");
										scanf("%d",&comd_4);
										
										if(comd_4 == 1)
												return 1;
										else if(comd_4 == 2)
												return 0;
										else
										{
												printf("\ncommand is wrong!\nPlease check and enter again!\n");
												continue;
										}
								}
								else if(option == 2)//是在command(2)下的delet,刪完資料就會回到主畫面
										return 1;

						}
						else if(strcmp(choose,"no") == 0)
								return 1;
						else
						{
								printf("\nError!you only can enter 'yes' or 'no'!\nPlease check and enter again!\n");
								continue;
						}
				}
		}
		//cur_ptr跑完list沒發現要刪除的資料的存在
		printf("\nNot found '%s' in the list\n",del_name);
		return 1;
}
				



