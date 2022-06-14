#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next, *arb;

    Node(int val)
    {
        data = val;
        next = NULL;
        arb = NULL;
    }
};

Node *Clone_using_map(Node *head)
{
    unordered_map<Node *, Node *> um;
    Node *temp = head;
    while (temp != NULL)
    {

        um[temp] = new Node(temp->data); // same as a[0]=23
        temp = temp->next;
    }
    temp = head;
    while (temp)
    {

        um[temp]->next = um[temp->next]; //clone->next=original->next
        um[temp]->arb = um[temp->arb];
        temp = temp->next;
    }

    return um[head];
}
Node *Clone_using_map1(Node *head)
{
    unordered_map<Node *, Node *> um;
    Node *curr = head;

    while (curr != NULL)
    {
        Node *clone = new Node(curr->data);
        um[curr] = clone;
        curr = curr->next;
    }
    curr = head;
    while (curr)
    {
        um[curr]->next = um[curr->next];
        um[curr]->arb = um[curr->arb];
        curr = curr->next;
    }

    return um[head];
}

void append(Node *head)
{
    Node *temp = head, *nxt;

    while (temp != NULL)
    {
        Node *clone = new Node(temp->data);
        clone->next = temp->next;
        temp->next = clone;
        temp = clone->next;
    }
    
}

void set_random(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        if (temp->arb)
        {
            temp->next->arb=temp->arb->next;
        }
        temp=temp->next->next;

    }
}
Node *list1(Node *head)
{
    Node *temp=head;
    Node *s=new Node (-1);
    Node *t=s;
    while(temp!=NULL)
    {   

        t->next=temp->next;
        temp->next=t->next;
        temp=temp->next;
        t=t->next;
    }

    return s->next;
}

Node *Cloning(Node *head)
{
    append(head);
    set_random(head);
    Node *head1=list1(head);
    return head1;
}