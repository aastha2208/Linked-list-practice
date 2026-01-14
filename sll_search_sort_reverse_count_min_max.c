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

struct node *reverse(struct node *head)
{
    if(head==NULL) return NULL;
    struct node *prev=NULL,*temp=head,*next=NULL;
    while(temp!=NULL)
    {
        next=temp->next;
        temp->next=prev;
        prev=temp;
        temp=next;
    }
    head=prev;
    return head;
}

void *min_max_count(struct node *head)
{
    if(head==NULL)
    {
        printf("List is empty\n");
        return;
    }
    int c=0,min=head->data,max=head->data;
    struct node *temp=head;
    while(temp!=NULL)
    {
        c++;
        if(temp->data<min) min=temp->data;
        if(temp->data>max) max=temp->data;
        temp=temp->next;
    }
    printf("No. of nodes=%d\t\tMinimum element=%d\t\tMaximum element=%d",c,min,max);
}

void search(struct node *head,int key)
{
    if(head==NULL)
    {
        printf("List is empty!\n");
        return;
    }
    struct node *temp=head;
    int ind=0,found=0;
    while(temp!=NULL)
    {
        if(temp->data==key)
        {
            found=1;
            printf("%d found at position %d\n",key,(ind+1));
            return;
        }
        ind++;
        temp=temp->next;
    }
    if(found==0)
    printf("%d isn't present in the list!\n",key);
}

void sortList(struct node *head)
{
    if(head==NULL  || head->next==NULL) return ;//Already sorted!

    struct node *i,*j;
    int tempVal;
    for(i=head;i->next!=NULL;i=i->next)
    {
        for(j=i->next;j!=NULL;j=j->next)
        {
            if(i->data>j->data)
            {
                tempVal=i->data;
                i->data=j->data;
                j->data=tempVal;
            }
        }
    }
}

struct node *concat(struct node *head1,struct node *head2)
{
    if(head1==NULL) return head2;
    if(head2==NULL) return head1;
    if(head1==head2)
    {
        printf("Error:Cannot concatenate a list with itself!\n");
        return head1;
    }
    int cho;
    printf("1st+2nd (choose 1) or 2nd+1st(choose 2)?:\n");
    int status=scanf("%d",&cho);
    if((status!=1) || (cho!=1 && cho!=2))
    {
        printf("Invalid input..Keeping list1 as primary\n");
        while(getchar()!='\n');
        return head1;
    }
    if(cho==1)
    {
        printf("1st list + 2nd list:\n");
        struct node *temp=head1;
        while(temp->next!=NULL)
        temp=temp->next;
        temp->next=head2;
        return head1;
    }
    else
    {
        printf("2nd list + 1st list:\n");
        struct node *temp=head2;
        while(temp->next!=NULL)
        temp=temp->next;
        temp->next=head1;
        return head2;
    }
}

int main()
{
    struct node *myList=create();
    
    return 0;
}