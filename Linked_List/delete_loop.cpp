
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    Node *next;
    int data;
    Node(int v)
    {
        data = v;
        next = NULL;
    }
};
Node *check_loop(Node *head)
{
    Node *slow=head,*fast=head;
    while(fast!=NULL && fast->next!=NULL)
    {
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast)
        break;
    }

    if(fast==NULL || fast->next==NULL)  //if loop dosent exist
    {
        return NULL;
    }

    slow=head;

    while(slow!=fast)  //find start  of loop
    {
        slow=slow->next;
        fast=fast->next;

    }
    while(fast->next!=slow)
    {
        fast=fast->next;
    }
    fast->next=NULL;
    return head;
}

Node * insertAtTail(Node *head,int d)
{
    if(head==NULL)
    {
            return new Node(d);
    }
    
    Node *tail=head;

    while(tail->next!=NULL)
    {
        tail=tail->next;
    }

    tail->next=new Node(d);

    return head;
}




Node * create(vector<int>&arr)
{
    Node *head=NULL;

    for(int i=0;i<arr.size();i++)
    {
        head=insertAtTail(head,arr[i]);
    }

    return head;
}

void print(Node *head)
{
    Node *temp=head;

    while(temp!=NULL)
    {
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"NULL\n";
}

int main()
{
    vector<int>arr={1,2,3,4,5,6,7,8};
    
    Node *head=create(arr);
    Node *random=head;
    for(int i=0;i<3;i++)
    {
        random=random->next;
    }
    Node *tail=head;
    while(tail->next!=NULL)
    tail=tail->next;

    tail->next=random;
    //cout<<startPoint(head)->data;
    //cout<<((checkLoop(head)==1)?"true":"false");
    check_loop(head);
    print(head);
    
}


