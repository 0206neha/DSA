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

Node *merge(Node *h1, Node *h2)
{
    if (h1 == NULL)
        return h2;
    if (h2 == NULL)
        return h1;

    

    Node *s=new Node(-1);
    Node *t=s;

    while (h1 != NULL && h2 != NULL)
    {
        if (h1->data < h2->data)
        {
            t->next=h1;
            h1=h1->next;
        }
        else
        {
            t->next=h2;
            h2=h2->next;
        }

        t=t->next;
    }
    t->next=NULL;

    if(h1!=NULL)
    {
        t->next=h1;
    }
    if(h2!=NULL)
    {
        t->next=h2;
    }

    return s->next;
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
    vector<int>arr1={1,4,7,9};
    vector<int>arr2={2,3,5,6,8,9,10};

    Node *head1=create(arr1);
    Node *head2=create(arr2);

    print(head1);
    print(head2);
    Node *head=merge(head1,head2);
    print(head);
    return 0;
}
