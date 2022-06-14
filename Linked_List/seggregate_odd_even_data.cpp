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

Node *seggregate(Node *head)
{
    if (head == NULL)
        return NULL;

    Node *curr = head;
    Node *even = new Node(-1);
    Node *e = even;

    Node *odd = new Node(-1);
    Node *o = odd;
    while (curr != NULL)
    {
        if (curr->data % 2 == 0)
        {
            e->next = curr;
            e = e->next;
        }
        else
        {
            o->next=curr;
            o=o->next;
        }
        curr=curr->next;
    }
    if(even->next==NULL){return odd->next;}
     else
    e->next=odd->next;
    o->next=NULL;
    return even->next;
}
Node *insert_at_tail(Node *head, int d)
{

    if (head == NULL)
    {
        return new Node(d);
    }

    Node *tail = head;
    while (tail->next != NULL)
    {
        tail = tail->next;
    }
    tail->next = new Node(d);
    return head;
}

Node *create(vector<int> &a)
{
    Node *head = NULL;
    for (int i = 0; i < a.size(); i++)
    {
        head = insert_at_tail(head, a[i]);
    }
    return head;
}

void print(Node *head)
{
    Node *temp = head;

    while (temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL\n";
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8};

    Node *head = create(arr);
    print(head);
    Node *h = seggregate(head);
    print(h);
}