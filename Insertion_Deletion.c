//
// Created by ashik on 9/17/2023.
//
#include<stdio.h>
#include<stdlib.h>
struct student
{
    int id;
    struct student *next;
};
typedef struct student s;
s *start;
void insert_first_position()
{
    s *firstNode;
    firstNode=(s*) malloc(sizeof (s));
    int a;
    printf("Enter data for insertion first position : ");
    scanf("%d",&a);
    firstNode->id=a;
    firstNode->next=start;
    start=firstNode;
}
void insert_last_position()
{
    s *lastNode;
    lastNode=(s *) malloc(sizeof (s));
    s *p;
    p=start;
    int a;
    printf("\nEnter data for last position insertion : ");
    scanf("%d",&a);
    while(p->next!=NULL)
    {
        p=p->next;
    }
    p->next=lastNode;
    lastNode->id=a;
    lastNode->next=NULL;
}
void insert_any_position()
{
    s *anyNode;
    anyNode=(s*)malloc(sizeof (s));
    s *p;
    p=start;
    int key;
    printf("\nEnter the value of searching key : ");
    scanf("%d",&key);
    while(p!=NULL)
    {
        if(p->id==key)
        {
            int a;
            printf("\nEnter data insert after %d : ",key);
            scanf("%d",&a);
            anyNode->id=a;
            anyNode->next=p->next;
            p->next=anyNode;
            return;
        }
        else
        {
            p=p->next;
        }
    }
}
void deletion_first_position()
{
    if(start==NULL)
    {
        printf("Underflow !!!\n");
        return;
    }
    start=start->next; //only we change the next part and now start node starts from start->next that means second node.
    printf("\nDeleting first Node.\n");
}
void deletion_last_position()
{
    s *p;
    p=start;
    while(p->next->next!=NULL)
    {
        p=p->next;
    }
    p->next=NULL;
    printf("Last node Deleted\n");
}
void deletion_any_node(int search_key)
{
    if(start==NULL)
    {
        printf("Could not deleted because linked list is already empty\n");
        return;
    }
    else
    {
        s *pointer=start;
        s*previous_pointer=NULL;
        while(pointer!=NULL)
        {
            if(pointer->id==search_key)
            {
                if(previous_pointer==NULL) //that's means first node
                {
                    start=pointer->next;
                }
                else
                {
                    previous_pointer->next=pointer->next;
                }
                printf("\n%d node is deleted\n",search_key);
                return;
            }
            previous_pointer=pointer;
            pointer=pointer->next;
        }

    }
}
void show()
{
    s *point;
    point=start;
    while(point!=NULL)
    {
        printf("%d ",point->id);
        point=point->next;
    }
}
int main()
{
    start=(s*)malloc(sizeof (s));
    start->id=78;
    start->next=NULL;
    insert_first_position();
    show();
    insert_last_position();
    show();
    insert_any_position();
    show();
    deletion_first_position();
    show();
    deletion_last_position();
    show();
    int n;
    printf("\nwhich value of node you want to delete : ");
    scanf("%d",&n);
    deletion_any_node(n);
    show();
}