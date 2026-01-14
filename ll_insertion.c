#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};
struct node *getNewNode()
{
    struct node *newNode=(struct node *)malloc(sizeof(struct node));
    if(newNode==NULL)
    {
        printf("Memory allocation failed!");
        return NULL;
    }
    int val;
    printf("Enter data:");
    int status=scanf("%d",&val);
    if(status!=1)
    {
        printf("Invalid input!Skipping....\n");
        while(getchar()!='\n');
        free(newNode);
        return NULL;
    }
    newNode->data=val;
    newNode->next=NULL;
    return newNode;
}

struct node *create()
{
    struct node *head=NULL,*temp=NULL;
    char ch;
    while(1)
    {
    printf("Do you want to enter a new node?(Y/y/N/n)");
    scanf(" %c",&ch);
    if(ch=='n' || ch=='N') break;
    else if(ch!='y' && ch!='Y')
    {
        printf("Please enter Y/N/y/n only!:\n");
        while(getchar() != '\n'); 
        continue;
    }
    struct node *newNode=getNewNode();
    if(newNode==NULL) continue;
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

struct node *insert_at_end(struct node *head)
{
    struct node *newNode=getNewNode();
    if(newNode==NULL) return head;
    if(head==NULL) return newNode;
    struct node *temp=head;
    while(temp->next!=NULL)
    temp=temp->next;
    temp->next=newNode;
    return head;
}

struct node *insert_at_beg(struct node *head)
{
    struct node *newNode=getNewNode();
    if(newNode==NULL) return head;
    newNode->next=head;
    return newNode;
}

struct node *insert_at_sp(struct node *head)
{
    int n;
    printf("Enter index to insert at:");
    scanf("%d",&n);

    if (n==0) return insert_at_beg(head);

    struct node *temp=head;
    for(int i=0;i<n-1 && temp!=NULL;i++)
    temp=temp->next;
    if(temp==NULL)
    printf("Error:Index out of bounds!\n");
    else
    {
        struct node *newNode=getNewNode();
        if(newNode!=NULL)
        {
            newNode->next=temp->next;
            temp->next=newNode;
        }
    }
    return head;
}

struct node *display(struct node *head)
{
    if(head==NULL)
    {
        printf("List is empty");
        return NULL;
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
    int choice;
    while(1)
    {
        printf("\n1.End       2.Beginning     3.Specific position     4.Display       5.Exit\n");
        if(scanf("%d",&choice)!=1)break;
        if(choice==5) break;

        switch(choice)
        {
            case 1:myList=insert_at_end(myList);break;
            case 2:myList=insert_at_beg(myList);break;
            case 3:myList=insert_at_sp(myList);break;
            case 4:myList=display(myList);break;
            default:printf("Invalid choice!\n");
        }
    }
    freeList(myList);
    return 0;
}
