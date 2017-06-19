#include <stdio.h>
#include <stdlib.h>
struct nd 
{
	int data;
	struct node *next;
};
typedef struct nd node;
void reverse(node** head_ref)
{
    node *prev = NULL;
    node *current = *head_ref;
    node *next;
    while (current != NULL)
    {
        next  = current->next;  
        current->next = prev;   
        prev = current;
        current = next;
    }
    *head_ref = prev;
}
int duplicate(node **head,int data)
{
	node *temp=*head;
	while(temp!=NULL)
	{
		if(temp->data == data)
			return 1;
		temp=temp->next;
	}
	return 0;
}
void delete(node **head)
{
	int data;
	printf("Enter data:");
	scanf("%d",&data);
	node *temp=*head,*prev=*head,*fre;
	if((*head)->data ==data)
	{
		fre=*head;
		*head=(*head)->next;
		free(fre);
		printf("%d Successfully Deleted!\n",data);
		return;
	}
	while(temp!=NULL)
	{
		if(temp->data==data)
		{
			prev->next=temp->next;
			temp->next=NULL;
			free(temp);
			printf("%d Successfully Deleted!\n",data);
			return;
		}
		prev=temp;
		temp=temp->next;
	}
	printf("NOT FOUND!\nTry Again...\n");
	return;
}
void insert(node **head)
{
	int data;
	printf("Enter data:");
	scanf("%d",&data);
	if(duplicate(head,data)==1)
	{
		printf("Already Inserted!\nTry Again...");
		return;
	}
	node *temp,*temp1,*prev;
	temp=(node *)malloc(sizeof(node));
	temp->next =NULL;
	temp->data = data;
	if(*head==NULL)
	{
		*head=temp;
	}
	else
	{
		temp1=*head;
		prev=*head;
		while(temp1!=NULL)
		{
			if(temp->data < (*head)->data)
			{
				temp->next=*head;
				*head=temp;
				break;
			}
			else if(temp1->next==NULL)
			{
				if(temp1->data > temp->data)
				{
					temp->next=prev->next;
					prev->next=temp;
				}
				else
				{
					temp1->next=temp;
				}
				break;
			}
			else
			{
				if(temp->data < temp1->data)
				{
					temp->next=prev->next;
					prev->next=temp;
					break;
				}
			}
			prev=temp1;
			temp1=temp1->next;
		}
	}
	printf("%d Successfully Inserted!\n", data);
}
void print_list(node **head)
{
	node *temp=*head;
	while(temp!=NULL)
	{
		printf("%d ",temp->data);
		temp=temp->next;
	}
}
int main(int argc, char const *argv[])
{
	int choice;
	node *hd=NULL,*temp;
	while(1)
	{
		printf("\n\t\t\t1.Insert\n\t\t\t2.Delete\n\t\t\t3.Show\n\t\t\t4.Reverse\n\t\t\t0.Exit\n\n");
		printf("Make your choice:");
		scanf("%d",&choice);
		switch(choice)
		{
			case 0:
					return 0;
			case 1:
					insert(&hd);
					break;
			case 2:
					delete(&hd);
					break;
			case 3:
					print_list(&hd);
					break;
			case 4:
					reverse(&hd);
					break;
			default:
					printf("INVALID ENTRY!!!\nTry Again...");
					break;
		}
	}
	temp=hd;
	printf("\n\n");
	while(temp!=NULL)
	{
		printf("%d ",temp->data );
		temp=temp->next;
	}
	return 0;
}