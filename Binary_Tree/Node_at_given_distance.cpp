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
 vector<int>ans;
     
     Node* search(Node *root,int target)
     {
         if(root==NULL)
         
         return NULL;
         
         if(root->data==target)
         return root;
         
         Node *ls=search(root->left,target);
         if(ls!=NULL)
         return ls;
         Node *rs=search(root->right,target);
         return rs;
     }
     
     void subtree(Node *root,int d,int k)
     {
         if(root==NULL)
         return;
         if(k==d)
        {
           ans.push_back(root->data);
           return;
        }
        
        subtree(root->left,d+1,k);
        subtree(root->right,d+1,k);
     }
     
     int fromAnscestor(Node *root,Node *target,int k)
     {
         if(root==NULL)return -1;
         if(root==target)return 1;
         
         int leftd=fromAnscestor(root->left,target,k); //if target is present in left of root
            if(leftd!=-1)        //if target is present in left subtree
           {
             if(k-leftd==0)     //ie k=ld
             ans.push_back(root->data);
             else
             
             subtree(root->right,0,k-leftd-1);//target node is in left n we need  to find nodesin right
             return leftd+1;                  //k-left distance -1 as ld is target node nd leftd-1 is root right
                                              //i.e in right part we need to serach nodes at dist=(k-(ld+1)
             
            }
         
         int rightd=fromAnscestor(root->right,target,k);
         if(rightd!=-1)
           {
             if(k-rightd==0)
             ans.push_back(root->data);
             else
             subtree(root->left,0,k-rightd-1);
             return rightd+1;
            }
            return -1;
     }


    vector <int> KDistanceNodes(Node* root, int target , int k)
    {
        // return the sorted vector of all nodes at k dist
        ans.clear();
        Node*targetn=search(root,target);
        if(targetn==NULL)
        return ans;
        subtree(targetn,0,k);
        fromAnscestor(root,targetn,k);
        sort(ans.begin(),ans.end());
        return ans;
    }

int main()
{   
    
    struct Node *root,*target;
    //level 0
    root = new Node(1);
    //level 1
    root->left = new Node(2);
    root->right = new Node(3);
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
   
  
  vector<int>ans;
  ans= KDistanceNodes(root,2,1);

  cout<<"Nodes are"<<endl;
  for(auto e:ans)
  {
      cout<<e<<" ";
  }
  
    
    return 0;
}