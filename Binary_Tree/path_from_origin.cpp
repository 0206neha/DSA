#include<iostream>
using namespace std;


int ways(int x, int y)
    {
      
      if(x<0 || y<0)
      return 0;
      if(x==0 && y==0)
      return 1;
      
      int l=ways(x-1,y);
      int r=ways(x,y-1);
      return l+r;
    }

    int main()
    {
         int n,m;
        cout<<"enter values for n an m \n";
        cin>>n>>m;
        cout<<ways(n,m);

    }