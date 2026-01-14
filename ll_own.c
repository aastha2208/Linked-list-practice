#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *create()
{
    struct node *head=NULL,*temp=NULL,*newNode=NULL;
    char ch;
    int value;
    while(1)
    {
    printf("Do you want to enter a new node?(Y/y/N/n)");
    scanf(" %c",&ch);
    if(ch=='n' || ch=='N')
    break;
    else if(ch!='y' && ch!='Y')
    {
        printf("Please enter Y/N/y/n only!:\n");
        while(getchar() != '\n'); //Clears input buffer!
        continue;
    }

    newNode=(struct node *)malloc(sizeof(struct node ));
    if(newNode==NULL)
    {
        printf("Memory allocation failed\n");
        break;
    }
    printf("Enter data to be inserted:");
    int status=scanf("%d",&value);
    if(status!=1)
    {
        printf("Invalid value entered!");
        free(newNode);
        while(getchar()!='\n');
        continue;

    }
    newNode->data=value;
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
    }
    return head;
}
void display(struct node *head)
{
    if(head==NULL)
    {
        printf("List is empty");
        return;
    }
    printf("\nLinked list:");
    struct node *temp=head;
    while(temp!=NULL)
    {
        printf("%d->",temp->data);
        temp=temp->next;
    }
    printf("NULL");

}
void freeList(struct node *head)
{
    struct node *temp;
    while(head!=NULL)
    {
        temp=head;
        head=head->next;
        free(temp);
    }
    printf("\nMemory successfully cleared!");
}
int main()
{
    struct node *myList=create();
    display(myList);
    freeList(myList);
    myList = NULL;//To prevent dangling pointers!
    return 0;
}