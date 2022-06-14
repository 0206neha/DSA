
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int value)
    {
        data = value;
        next = NULL;
    }
};

Node *insert_at_beg(Node *head, int d)
{
    Node *node = new Node(d);
    if (head == NULL)
    {
        head = node;
    }

    else
    {
        node->next = head;
        head = node;
    }
    return head;
}
Node *deletion(Node *head, int post)
{
    Node *p, *q;

    if (post == 0)
    {
        p = head;
        head = head->next;
        free(p);
    }
    else
    {
        p = head;
        q = NULL;
        for (int i = 0; i < post && p; i++)
        {
            q = p;
            p = p->next;
        }
        q->next = p->next;
        free(p);
    }

    // Node Deletion(Node head, int position) {
    // if (position == 0){ return head.next; }
    // head->next = Delete(head.next, position-1);
    // return head;
    //}
    return head;
}
Node *insert_at_tail(Node *head, int d)
{
    Node *node = new Node(d);
    if (head == NULL)
    {
        head = node;
    }
    Node *tail = head;
    while (tail->next != NULL)
    {
        tail = tail->next;
    }
    tail->next = node;
    return head;
}

void insert_at_pos_rec(Node *&head, int d, int pos)
{
          if (head == NULL)
          return;
          if(pos==0)
          {
             head= insert_at_beg(head,d);
             return;
          }
          if(pos==1)
          {
               Node *new1 = new Node(d);
               new1->next=head->next;
               head->next=new1;
               return;
          }
    
    // Node *t = head;
     insert_at_pos_rec(head->next, d, pos - 1);
   
}
// 1  2  3 4
Node *insert_at_pos(Node *head, int d, int pos)
{
    int counter = 0;
    Node *temp = head;
    while (temp != NULL)
    {
        temp = temp->next;
        counter++;
    }
    if (pos == 0)
    {
        head = insert_at_beg(head, d);
    }

    else if (pos > 0 && pos <= counter)
    {
        temp = head;
        for (int i = 0; i < pos; i++)
        {
            if (temp->next != NULL)
                temp = temp->next;
            else
                break;
        }
        Node *node = new Node(d);
        node->next = temp->next;
        temp->next = node;
    }

    else
    {
        cout << endl;
        cout << "Invalid position";
    }
    return head;
}

Node *create(vector<int> &arr)
{
    Node *head = NULL;
    for (int i = 0; i < arr.size(); i++)
    {
        head = insert_at_beg(head, arr[i]);
        //head=insert_at_tail(head,arr[i]);
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
    cout << "NULL";
}
int main()
{

    //create new node
    Node *head = new Node(1);

    //delete node
    //delete head;

    // vector<int>arr={9,3,4,6,1,2};
    //// Node *head=create(arr);

    print(head);

    head = insert_at_beg(head, 10);
    cout << endl;
    print(head);

    head = insert_at_tail(head, 5);
    cout << endl;
    print(head);

    head = insert_at_pos(head, 7, 7);
    cout << endl;
    print(head);

    insert_at_pos_rec(head, 20, 0);
    cout << endl;
    print(head);

    head = deletion(head, 1);
    cout << endl;
    print(head);

    return 0;
}