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
    Node *head=NULL;
    for (int i = 0; i <a.size(); i++)
    {
        head=insert_at_tail(head,a[i]);
    }
    return head;
}

//1->2->3->4->5
Node *recursion(Node *head)
{
    if (head == NULL || head->next == NULL)
        return head;

    Node *temp = recursion(head->next);
    head->next->next = head;    //after recursion 1->4-5->3->2->1
                                //hence 1->2->next=1 and 1->next=NULL
    head->next = NULL;
    return temp;
}

Node *reverse(Node *head)
{
    if (head == NULL || head->next == NULL)
        return head;
    Node *prev=NULL,*nxt=NULL;

    while(head!=NULL)
    {
        nxt=head->next;
        head->next=prev;
        prev=head;
        head=nxt;
    }
    return prev;
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
  vector<int>a={1,2,3,4,5,6};
  Node *head=create(a);
  print(head);
  head=recursion(head);
 // head=reverse(head);
 print(head);

  return 0;
}