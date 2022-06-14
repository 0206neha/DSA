#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;

    Node(int d)
    {
        data = d;
        next = NULL;
    }
};

/*algos-
insert all nodes in map of h1 and increament count
now traverse h2 and if count==0 add those nodes in temp
*/

//1->5->8->2->9->3          6->2->1->3->4

Node *Unsorted_Union(Node *h1, Node *h2)
{
    if (h1 == NULL)
        return h2;
    if (h2 == NULL)
        return h1;

    Node *head = h1;
    unordered_map<int, int> um; //map value with count

    while (h1->next != NULL && um[h1->data] == 0) //to avoid duplicates um condn
    {

        um[h1->data]++;
        h1 = h1->next;
    }
    um[h1->data]++; //as last node will not be inserted

    Node *temp = h1; //store last node of h1 in temp

    while (h2 != NULL)
    {
        if (um[h2->data] == 0)
        {
            temp->next = h2;
            temp = temp->next;
        }

        h2 = h2->next;
    }
    temp->next = NULL;
    return head;
}
Node *Unsorted_Intersection(Node *h1, Node *h2)
{
    if (h1 == NULL)
        return h2;
    if (h2 == NULL)
        return h1;

    Node *head = h1;
    unordered_map<int, int> um; //map value with count

    while (h1!= NULL) //to avoid duplicates um condn
    {

        um[h1->data]++;
        h1 = h1->next;
    }
   
    Node *s=new Node(-1);
    Node *temp = s; //store last node of h1 in temp

    while (h2 != NULL)
    {
        if (um[h2->data] == 1)
        {
            temp->next = h2;
            temp = temp->next;
        }

        h2 = h2->next;
    }
    temp->next = NULL;
    return s->next;
}
// 2->4->7->6->10           2->4->7
Node *Union(Node *h1, Node *h2)
{
    if (h1 == NULL)
        return h2;
    if (h2 == NULL)
        return h1;

    Node *s = new Node(-1);
    Node *t = s;

    while (h1 != NULL && h2 != NULL)
    {
        if (h1->data == h2->data)
        {
            t->next = h1;
            t = t->next;
            h1 = h1->next;
            h2 = h2->next;
        }
       else if(h1->data<h2->data)
       {
           t->next=h1;
           t=t->next;
           h1=h1->next;

       }
       else
       {
           t->next=h2;
           t=t->next;
           h2=h2->next;
       }
    }

    if (h1 != NULL)
    {
        t->next = h1;
    }
    if (h2 != NULL)
    {
        t->next = h2;
    }
    t = t->next;
    return s->next;
}


Node *Intersect(Node *h1, Node *h2)
{
    if (h1 == NULL || h2 == NULL)
        return NULL;

    Node *s = new Node(-1);
    Node *t = s;

    while (h1 != NULL && h2 != NULL)
    {
        if (h1->data == h2->data)
        {
            t->next = h1;
            t = t->next;
            h1 = h1->next;
            h2 = h2->next;
        }

        else if (h1->data > h2->data)
        {
            h2 = h2->next;
        }
        else
        {
            h1 = h1->next;
        }
    }
    t->next = NULL;
    return s->next;
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

Node *create(vector<int> &arr)
{
    Node *head = NULL;
    for (int i = 0; i < arr.size(); i++)
    {
        head = insert_at_tail(head, arr[i]);
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
    vector<int> arr1 = {6, 2, 3, 4, 5};
    vector<int> arr2 = {3, 9, 6, 7, 8};

    Node *head1 = create(arr1);
    Node *head2 = create(arr2);

    print(head1);
    print(head2);
    Node *head;
    //head=Unsorted_Union(head1,head2);
    //print(head);
    head=Unsorted_Intersection(head1,head2);
   // head = Union(head1, head2);
    //print(head);
   //  head=Intersect(head1,head2);
    // head=sorted_Union(head1,head2);
    print(head);
    return 0;
}