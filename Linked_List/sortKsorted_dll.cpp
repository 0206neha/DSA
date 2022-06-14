#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;

    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

/*
//tc-> o(n + n +n)->O(3n)
//sc->O(n+n)->O(2n)
    3->2->1->4->5->6->7->NULL   k=3       3 2 1 6 5 4 7 
    
  3->2->1->6->5->4->7->NULL
*/

struct comp
{
    bool operator()(Node *a, Node *b)
    {
        return a->data > b->data;
    }
};

Node *sortKSorted(Node *head, int k)
{
    if (head == NULL || k == 0)
        return head;

    //priority_queue<Node *>pq;  this will give max heap
    priority_queue<Node *, vector<Node *>, comp> pq; //this will give min heap


}


Node *at_tail(Node *head, int d)
{
    if (head == NULL)
        return new Node(d);

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
        head = at_tail(head, arr[i]);
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
    head = sortKSorted(head, 3);
    print(head);
}