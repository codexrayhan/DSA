#include<iostream>
using namespace std;

struct node
{
    int data;
    node* next;

    node(int value)
    {
        data=value;
        next=NULL;
    }
};

node* head= NULL;

void insertHead(int value)
{
    node *newItem =new node(value);
    newItem->next=head;
    head=newItem;


}

void printList()
{
    if(head==NULL)
    {
        cout<<"Linked List is Empty"<<endl;
        return;
    }

    node* current= head;

    while(current!=NULL)
    {
        cout<<current->data<<" ";
        current=current->next;
    }

    cout<<endl;
}


void insertLast(int value)
{
    node* newItem= new node(value);

    node* current = head;

    while(current->next!=NULL)
    {
        current=current->next;
    }

    current->next=newItem;
}

void insertMiddle(int target, int value)
{
    node* newItem= new node(value);

    node* current=head;

    while(current->data!= target)
    {
        current=current->next;
    }

    newItem->next= current->next;
    current->next=newItem;
}

void deleteHead()
{
    if(head==NULL)
    {
        cout<<"Linked List is empty"<<endl;
        return;
    }

    node* current=head;

    head=head->next;

    delete current;
}

void deletelast()
{
    if(head==NULL)
    {
        cout<<"Linked List is empty"<<endl;
        return;
    }

    node* current=head;
    node* prev=NULL;

    while(current->next!=NULL)
    {
        prev=current;
        current=current->next;
    }

    if(prev!=NULL)
    {
        prev->next=NULL;
    }
    else{
        head=NULL;
    }

    delete current;
}

 void deleteAny(int target)
 {
     if(head==NULL)
    {
        cout<<"Linked List is empty"<<endl;
        return;
    }

    node* current=head;
    node* prev=NULL;

    while(current->data!=target)
    {
        prev=current;
        current=current->next;
    }

    if(prev!=NULL)
    {
        prev->next=current->next;
    }
    else{
        head=NULL;
    }

    delete current;

 }

int main()
{
    insertHead(8);
    insertHead(9);
    insertHead(10);
    printList();

    insertLast(25);
    printList();

    insertMiddle(9,15);
    printList();

    deleteHead();
    printList();

    deletelast();
    printList();

    deleteAny(15);
    printList();


}
