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

Node *remove_dups(Node *head)
{
    if (head == NULL || head->next == NULL)
        return head;

    Node *prev = head, *nxt = head->next;
    while (nxt != NULL)
    {
        if (prev->data != nxt->data)

        {
            prev->next = nxt;
            prev = prev->next;
        }
        nxt = nxt->next; //as in both if and else condn we have to move nxt
    }
    return head;
}

//1,2,3,3,4,5

Node *remove_sorted(Node *head)
{
    if (head == NULL || head->next == NULL)
        return head;

    Node *s = new Node(-1);
    Node *t = s;
    while(head->next!=NULL)
    {
        if(head->data!=head->next->data)
        {
            t->next=head;
            t=t->next;
        }
        head=head->next;
    }
    t->next=head;
    return s->next;
}
// 1,4,2,5,3,8,9
Node *dups_Unsorted(Node *head)
{
    if (head == NULL && head->next == NULL)
        return head;

    Node *s = new Node(-1);
    Node *t = s;

    unordered_map<int, int> un; //node->data,count

    while (head != NULL)
    {
        if (un[head->data] == 0)
        {
            t->next = head;
            t = t->next;
        }
        un[head->data]++;
        head = head->next;
    }
    t->next = NULL;
    return s->next;
}

int main()
{
    vector<int> a = {1, 2,2,3, 4, 5, 6, 6, 7};
    Node *head = create(a);
    print(head);
    // head = remove_dups(head);
    // print(head);

    // Node *h = dups_Unsorted(head);
    // print(h);

    Node *he=remove_sorted(head);
    print(he);

    return 0;
}