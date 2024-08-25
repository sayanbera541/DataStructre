#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void insert_atBegining();
void insert_at_anyPosition();
void insert_atEnd();
void delete_atBegining();
void delete_atEnd();
void delete_at_anyPosition();
void display_node();
void count_node();
void linear_search(item);
	
struct node 
{
    int data;
    struct node *next;
};

struct node *start;

int main()
{
	int choice;
	bool flag = true;
	while(flag)
	{
		printf("Press 0 to insert at begining \n");
		printf("Press 1 to insert at end \n");
		printf("Press 2 to insert at any position \n");
		printf("Press 3 to delete at begining \n");
		printf("Press 4 to delete at end \n");
		printf("Press 5 to delete at any position \n");
		printf("Press 6 to display the list \n");
		printf("Press 7 to count the node in the list \n");
		printf("Press ")
		printf("Press any other key to exit \n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 0 : insert_atBegining();
			         break;
			case 1 : insert_atEnd();
			         break;
			case 2 : insert_at_anyPosition();
					 break;
			case 3 : delete_atBegining();
			         break;
			case 4 : delete_atEnd();
			         break;
			case 5 : delete_at_anyPosition();
					 break;       
			case 6 : display_node();
			         break;
			case 7 : count_node();
					 break;
		    default : flag = false;
		              exit(0);
		}
	}
	return 0;
}

void insert_atBegining()
{
	struct node *ptr = (struct node *)malloc(sizeof(struct node));
	if(ptr == NULL)
	{
		printf("\n Overflow");
	}
	else
	{
		int item;
		printf("Enter the number you want to insert into the node : \n");
		scanf("%d",&item);
		ptr->data = item;
		ptr->next = start;
		start = ptr; 
		printf("\nNew node inserted \n");
	}
	
}

void insert_atEnd()
{
	struct node *ptr = (struct node *)malloc(sizeof(struct node));
	if(ptr == NULL)
	{
		printf("\n Overflow");
	}
	else
	{
		int item;
		struct node *currentNode;
		printf("Enter the number you want to insert into the node : \n");
		scanf("%d",&item);
		ptr->data = item;
		ptr->next = NULL;
		if(start == NULL)
		{
			start = ptr;
		}
		else
		{	
			currentNode = start;
			while(currentNode -> next != NULL)
			{
				currentNode = currentNode -> next;
			}
			  	currentNode -> next = ptr;
		}
		printf("\nNew node inserted \n");
	}
	
}

void insert_at_anyPosition()
{
	struct node *curr_node;
	struct node *prev_node;
	curr_node = start;
	int i,loc;
	printf("Enter the position you want to insert  the node : \n");
	scanf("%d",&loc);
	if(start == NULL)
	{
		printf("There is no element at position %d \n",loc);
		return;
	}
	for(i=1;i<loc;i++)
	{
		if(curr_node == NULL)
		{
			printf("There is no element at position %d \n",loc);
			return;
		}
		else
		{
			prev_node = curr_node;
			curr_node = curr_node -> next;
		}
	}
	struct node *ptr = (struct node *)malloc(sizeof(struct node));
	if(ptr == NULL)
	{
		printf("OVERFLOW \n");
		return;	 
	}
	else
	{
		int item;
		printf("Enter the number you want to insert into the node : \n");
		scanf("%d",&item);
		ptr->data = item;
		ptr->next = curr_node;
		prev_node -> next = ptr; 
		printf("\nNew node inserted at position %d\n",loc);
	}		
}

void delete_atBegining()  
{  
    struct node *ptr;  
    if(start == NULL)  
    {  
        printf("\nList is empty \n");  
    }  
    else   
    {  
        ptr = start;  
        start = ptr->next;  
        free(ptr);  
        printf("\nNode deleted from the begining ...\n");  
    }  
}

void delete_atEnd()  
{  
    struct node *ptr;
	struct node *prev;
	ptr = start;  
	if(start==NULL)
	{
		printf("List is empty \n");
		return;
	}
    while ( ptr != NULL)
	{
		prev = ptr;
		ptr = ptr -> next;
		if(ptr -> next == NULL)
		{
			prev -> next = NULL;
			break;
		}
    }
	printf("\nNode deleted from the end of list ...\n");       
}

void delete_at_anyPosition()
{
	struct node *prev;
	struct node *current_node;
	current_node = start;
	if(current_node == NULL)
	{
		printf("\nList is empty \n");
		exit;
	}
	else
	{
		int loc;
		int i = 1;
		printf("Enter the position you want to delete the node : \n");
		scanf("%d",&loc);
		while(i<loc)  
		{
			prev = current_node;
			current_node = current_node -> next;
			i++;	
		}
		prev -> next = current_node -> next ;
		free(current_node);
		printf("\nNode deleted from %d position that you enter  ...\n",loc);  
	}	
}

void display_node()
{
	if(start == NULL)  
    {  
        printf("\nList is empty");  
    }  
    else   
    { 
		struct node *ptr = start;
	    while (ptr != NULL) 
		{
	        printf("%d \t ", ptr->data);
	        ptr = ptr->next;
	    }    
    }
    printf("\n");
}

void count_node()
{
	struct node *ptr;
	ptr = start;
	int i=0;
	if(ptr == NULL)
	{
		printf("There is %d node in the list \n",i);
	}
	else
	{
		while(ptr != NULL)
		{
			ptr = ptr -> next;
			i++;
		}
		printf("There is %d node in the list \n",i);
	}
}
