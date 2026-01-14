#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void display(struct node *head)
{
    if(head==NULL)
    {
        printf("List is empty\n");
        return;
    }
    printf("Linked list:\n");
    struct node *temp=head;
    while(temp!=NULL)
    {
        printf("%d->",temp->data);
        temp=temp->next;
    }
    printf("NULL");
}
struct node *create()
{
    struct node *head=NULL,*temp=NULL,*newNode=NULL;
    char ch;
    int value;
    while(1)
    {
    printf("Do you want to enter a new node?(Y/y/N/n):");
    scanf(" %c",&ch);
    if(ch=='n' || ch=='N')
    break;
    else if(ch!='y' && ch!='Y')
    {
        printf("Please enter Y/N/y/n only!\n");
        while(getchar() != '\n'); //Clears input buffer!
        continue;
    }

    newNode=(struct node *)malloc(sizeof(struct node ));
    if(newNode==NULL)
    {
        printf("Memory allocation failed\n");
        break;
    }
    printf("Enter data to be inserted:\n");
    int status=scanf("%d",&value);
    if(status!=1)
    {
        printf("Invalid value entered!\n");
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
struct node *delete_from_beg(struct node *head)
{
    if(head==NULL)
    {
        printf("List is empty,nothing to delete!\n");
        return NULL;
    }
    struct node *temp=head;
    head=head->next;
    printf("Deleted %d\n",temp->data);
    free(temp);
    return head;
}
struct node *delete_from_end(struct node *head)
{
    if(head==NULL)
    {
        printf("List is empty,nothing to delete\n");
        return NULL;
    }
    if(head->next==NULL)
    {
        printf("Deleted %d\n",head->data);
        free(head);
        return NULL;
    }
    struct node *temp=head;
    while(temp->next->next!=NULL)
    temp=temp->next;
    struct node *d=temp->next;
    printf("Deleted %d",d->data);
    temp->next=NULL;
    free(d);
    return head;

}
struct node *delete_from_sp(struct node *head)
{
    if(head==NULL)
    {
        printf("List is empty,nothing to delete\n");
        return NULL;
    }
    int n;
    printf("Enter index to delete from:\n");
    scanf("%d",&n);

    if(n==0) return delete_from_beg(head);

    struct node *temp=head;
    for(int i=0;i<n-1 && temp->next!=NULL;i++)
    temp=temp->next;

    if(temp->next==NULL)
    printf("Error:Index out of bounds!\n");
    else
    {
        struct node *d=temp->next;
        printf("Deleted %d",d->data);
        temp->next=d->next;
        free(d);
    }
    return head;
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
    int choice;
    while(1)
    {
        printf("\n1.End       2.Beginning     3.Specific position       4.Display       5.Exit\n");
        if(scanf("%d",&choice)!=1)break;
        if(choice==5) break;

        switch(choice)
        {
            case 1:myList=delete_from_end(myList);break;
            case 2:myList=delete_from_beg(myList);break;
            case 3:myList=delete_from_sp(myList);break;
            case 4:display(myList);break;
            default:printf("Invalid choice!\n");
        }
    }
    freeList(myList);
    return 0;
}