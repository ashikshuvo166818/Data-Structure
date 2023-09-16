//
// Created by ashik on 9/16/2023.
//
#include<stdio.h>
#include<stdlib.h>
struct student{
    int id;
    struct student *next;
};
typedef struct student s;
s *start;
void insert_first_position()
{
    s *firstNode;
    firstNode=(s *)malloc(sizeof(s));
    int a;
    printf("\nEnter data for insert first position : ");
    scanf("%d",&a);
    firstNode->id=a;
    firstNode->next=start;  //it connect with start node that means next node is start
    start=firstNode;    // start is the first node and that line means linked list start from firstNode
}
void insert_last_position()
{
    s *lastNode;
    lastNode=(s*)malloc(sizeof(s));
    int b;
    printf("\nEnter data for insert last position : ");
    scanf("%d",&b);
    lastNode->id=b;
    lastNode->next=NULL;
    s *p; //for point
    p=start;
    while(p->next!=NULL)
    {
        p=p->next;
    }
    p->next=lastNode;
}
void insert_any_position()
{
    s *p=start; //p is a pointer and p is start from start node
    int key;
    printf("\nEnter searching value where you want to insert : ");
    scanf("%d",&key);
    while(p->next!=NULL)
    {
        if(p->id==key)
        {
            s *anyNode;
            anyNode=(s *) malloc(sizeof (s));
            int i;
            printf("Enter data for insertion after %d :",key);
            scanf("%d",&i);
            anyNode->id=i;
            anyNode->next=p->next;  //it connect new node with next node
            p->next=anyNode;        // it connect new node with previous node
            return;
        }
        else
        {
            p=p->next; //for go to next element
        }
    }
}
void show()
{
    s *point;
    point=start;
    while(point!=NULL) //until point is got NUll it will continue
    {
        printf("%d\t",point->id);
        point=point->next;  //it works similar i++ that means go to next Node
    }
}
int main()
{
    start = (s *)malloc(sizeof(s));
    start->id = 78;
    start->next = NULL; // Initialize the next pointer to NULL
    // in the first only start node is exist that's why start->next=NULL
    insert_first_position();
    show();
    insert_last_position();
    show();
    insert_any_position();
    show();
}
