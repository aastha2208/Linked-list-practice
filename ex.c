#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define l  50
struct node
{
    char data[l];
    struct node *next;
}*head=NULL,*temp=NULL,*newNode=NULL,*d,*prev=NULL;
char ch;

void delete_from_beg()
{
do
    {
    printf("Do you want to enter a new node?(Y/y/N/n)");
    scanf(" %c",&ch);

    if(ch=='n' || ch=='N')
    break;

    
        newNode=(struct node *)malloc(sizeof(struct node ));
        printf("Enter data to be inserted:");
        scanf("%s",&newNode->data);
        newNode->next=NULL;
        if(head==NULL)
        {
            head=newNode;
            temp=newNode;
        }
        else
        {
            temp->next=newNode;
            temp=newNode;//temp=temp->next;
        }
    
    }while(ch=='y' || ch=='Y');

    struct node *d=head;
    head=head->next;
    // printf("Deleted node is %s",d->data);
    d->next=NULL;
    free(d);//memory gets destroyed and the same memory can be used for storing another variable!!

}

void delete_item(char key[])
{
    while(temp != NULL)
    {
        if(strcmp(temp->data, key) == 0)
        {
            if(prev == NULL)          // deleting first node
                head = temp->next;
            else
                prev->next = temp->next;

            free(temp);
            return;
        }
        prev = temp;
        temp = temp->next;
    }
}


int main()
{
    delete_from_beg();
    delete_from_sp();
    return 0;
}