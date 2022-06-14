#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};


//Ques 1-sym of leaf nodes

int sum=0;
int sum1(Node*root)
{

 
  if(root==NULL)return 0;
   if(root->left==NULL && root->right==NULL)
 {
   sum+=root->data;
 }
 
  sum1(root->left);
  sum1(root->right);

  return sum;
}


  

// Ques2 --zigzagtree
vector <int> zigzag(Node* root)
{
    queue<Node*>q;
    vector<int>v;
    stack<int>s;
    
    if(root==NULL)
    return v;  
    //return so return  type is vect int so return vec
    q.push(root);
    int level=0,n;
    
    while(!q.empty())
    {
        n=q.size();
        for(int i=1;i<=n;i++)
        {
            Node *temp=q.front();
            q.pop();
            if(level%2==1)
            {
                s.push(temp->data);
            }
            
            else
            v.push_back(temp->data);
            
            if(temp->left!=NULL)
            q.push(temp->left);
            if(temp->right!=NULL)
            q.push(temp->right);
        }
        level++;
        while(!s.empty())
        {
            
            v.push_back(s.top());
            s.pop();
        }
        
    }
    return v;
 }
        
// ques3--> verticaltree traversal
 vector<int>verticaltree(Node*root)
{ 
  vector<int>v;
  if(root==NULL)return v;
  map<int,vector<int>>mp;
  queue<pair<Node *,int>>q;
  pair<Node*,int>p;
  
  q.push({root,0});

   while(!q.empty())
  {
     int n=q.size();
     for(int i=1;i<=n;i++)
   {
     p=q.front();
     q.pop();
    
     Node*temp=p.first;
     int d=p.second;
   
     mp[d].push_back(temp->data);

     if(temp->left!=NULL)
     q.push({temp->left,d-1});
     if(temp->right!=NULL)
     q.push({temp->right,d+1});
    }
  }

   for(auto p:mp)
 {
    for(int x:p.second)
   { 
      v.push_back(x);
    }
 }
 return v;
} 



//Quesm4-flatten tree
void Flatten(Node*root)
{
  if(root==NULL ||( root->left==NULL &&root->right==NULL))
  return;

  if(root->left!=NULL)
 {
    Flatten(root->left);
    
    Node *temp=root->right;
    root->right=root->left;
    root->left=NULL;
   
    Node *rt=root->right;
    while(rt->right!=NULL)
   {
	  rt=rt->right;
   }
   
   rt->right=temp;
 }
   Flatten(root->right);
}
  
//Ques 5-leaf nodes to cdl and ddl

Node *tail=NULL,*head=NULL;
Node* leaves(Node*root)
{
  if(root==NULL)return NULL;
  if(root->left==NULL && root->right==NULL)
{
  if(head==NULL) 
 {
   head=root;
   tail=root;
 }
 else
 {
   tail->right=root;
   root->left=root;
   tail=root;
 }
 return NULL;
}
 root->left=leaves(root->left);
 root->right=leaves(root->right);
 return root;
}

Node* leavestodll(Node*root)
{ 
  head=NULL;
  tail=NULL;
  if(root==NULL)return NULL;
  if(root->left==NULL && root->right==NULL)
  {
    head=root;
    root=NULL;
  }
  else
  leaves(root);
  return head;
}
 


//Ques6-construct tree from in,pre ans in post
int search(int cn,int in[],int low,int high)
{
  for(int i=low;i<=high;i++)
  {
    if(in[i]==cn)
    return i;
  }

return -1;

}

int ind=0;
Node* inpre(int in[],int pre[],int low,int high)
{
  if(low>high)return NULL;
  
  int cn=pre[ind];
  ind++;
 
 Node *temp=new Node(cn);
 temp->left=NULL;
 temp->right=NULL;
 
 if(low==high)return temp;

 int pos=search(cn,in,low,high);

 temp->left=inpre(in,pre,low,pos-1);
 temp->right=inpre(in,pre,pos+1,high);

return temp;
}


//inoder postorder
int search2(int cn,int in[],int low,int high)
{
  for(int i=high;i>=low;i--)
  {
    if(in[i]==cn)
    return i;
  }
  return -1;
}

int indexing=8;
Node* inpost(int in[],int post[],int low,int high)
{
  if(low>high)return NULL;
  
  int cn=post[indexing];
  indexing--;
 
 Node *temp=new Node(cn);
 temp->left=NULL;
 temp->right=NULL;
 
 if(low==high)return temp;

 int pos=search2(cn,in,low,high);

 temp->right=inpre(in,post,pos+1,high);
 temp->left=inpre(in,post,low,pos-1);
 

return temp;
}
void preorder(Node *root)
{
    if(root==NULL)
        return;

    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);  
}
void postorder(Node *root)
{
    if(root==NULL)
        return;
    postorder(root->left);
    
    postorder(root->right);
    cout<<root->data<<" ";
}

void inOrder(Node *root)
{
    if(root==NULL)
        return;
    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);
}

void printList(Node *head){
    while(head!=NULL){
        cout<<head->data<<" ";
        head=head->right;
    }
}

int main()
{
    struct Node *root,*target;
    //level 0
    root = new Node(1);
    //level 1
    root->left = new Node(2);
    target=root->right = new Node(3);
    //level 2
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    //level 3
    root->right->right->left = new Node(8);
    root->right->left->left=new Node(9);

    /*
            1
           /\
          2  3
          /\  /\
        4  5 6   7
            /  /
           9   8 
    */
   vector<int>res;
    //if func returns vector then do -> res = function();
    Node * ans;
    
    //sum of leaf nodes
    //sum=0;
   // cout<<sum1(root);

    // zigzag traversal
    //res=zigzag(root);
     

   //vertical order
   //res=verticaltree(root);

   //flatten tree
   //Flatten(root);
   //inOrder(root);

   /*leaves to dll
   ans=leavestodll(root);
   cout<<"Remaining tree is:"<<endl;
   inOrder(root);
   cout<<endl;
   cout<<"DLL of leaves is:"<<endl;
   printList(head); */

  //construct tree from inoder and pre order
  /* int n=9;
   ind=0;
   int in[]={4,2,5,1,9,6,3,8,7};
   int pre[]={1,2,4,5,3,6,79,8};
  
   inpre(in,pre,0,n-1);
   postorder(root);
   cout<<endl;
   */


//inorder and postorder;
indexing=0;
int in[]={4,2,5,1,9,6,3,8,7};
int post[]={4,5,2,9,6,8,7,3,1};
 int n1=9; 
 inpost(in,post,0,n1-1);
 preorder(root);

   for(auto x : res){
        cout<<x<<" ";
    }
    
    return 0;
 
}