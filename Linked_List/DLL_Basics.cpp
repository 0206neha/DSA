
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *prev, *next;

    Node(int val)
    {
        data = val;
        prev = NULL;
        next = NULL;
    }
};

Node *insert_at_beg(Node *head, int d)
{
    Node *node = new Node(d);
    if (head == NULL)
        return node;
    else
    {
        node->next = head;
        head->prev = node;
    }

    return node;
}

Node *insert_at_tail(Node *tail, int d)
{
    Node *node = new Node(d);
    if (tail == NULL)
    {
        return node;
    }

    tail->next = node;
    node->prev = tail;
    node = tail;
    return tail;
}

Node *after_pos(Node *head, int pos, int d)
{
    if (pos == 0)
        return insert_at_beg(
            head, d);
    Node *node = new Node(d);
    if (pos == 1)
        head->next = node;
    node->prev = head;

    Node *temp = head;

    for (int i = 0; i < pos - 1; i++)
    {
        if (temp->next != NULL)
            temp = temp->next;
        else
            break;
    }
    if (temp->next == NULL)
        insert_at_tail(temp, d);
    node->next = temp->next;
    node->prev = temp;
    temp->next = node;
    node->next->prev = node;
    return head;
}
pair<Node*, Node*> create(vector<int>arr)
{
    Node *head = NULL, *tail = NULL;

    for (auto x : arr)
    {    
        
         head=insert_at_beg(head,x);
         if(tail==NULL)
         tail=head;

          //tail = insert_at_tail(tail, x);
       // if (head == NULL)
       //     head = tail;
            
    }
    return {head, tail};
}

void print(Node *head)
{
    Node *temp=head;

    
    while(temp!=NULL)
    {
        cout<<temp->data<<"<=>";
        temp=temp->next;
    }
    cout<<"NULL\n";
    
}
int main()
{
    vector<int>arr = {1, 2, 3, 4, 5, 6};
    auto p = create(arr);

    Node *head = p.first;
    Node *tail = p.second;

    print(head);
    //head=insertAtPos(head,3,4);
    //print(head);
    //print(tail);
    return 0;
}