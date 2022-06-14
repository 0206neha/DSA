#include<bits/stdc++.h>
using namespace std;

const char matrix[5][5]={{'M','O','N','A','R'},
                        {'C','H','Y','B','D'},
                        {'E','F','G','I','K'},
                        {'L','P','Q','S','T'},
                        {'U','V','W','X','Z'}};
int position(int r,int c,char str)
{
   cout<<'b';
    int i;
  
        if(str=='M' ||str =='m')
        {
            r=0;
            c=0;
        }
        else if(str=='O' ||str=='o')
        {
            r=0;
            c=1;
        }
         else if(str=='N' ||str=='n')
        {
            r=0;
            c=2;
        }
         else if(str=='A' ||str=='a')
        {
            r=0;
            c=3;
        }
         else if(str=='R' ||str=='r')
        {
            r=0;
            c=4;
        }
         else if(str=='C' ||str=='c')
        {
            r=1;
            c=0;
        }
         else if(str=='H' ||str=='h')
        {
            r=1;
            c=1;
        }
         else if(str=='Y' ||str=='y')
        {
            r=1;
            c=2;
        }
         else if(str =='B' ||str=='b')
        {
            r=1;
            c=3;
        }
         else if(str=='D' ||str=='d')
        {
            r=1;
            c=4;
        }
         else if(str=='E' ||str=='e')
        {
            r=2;
            c=0;
        }
         else if(str=='F' ||str=='f')
        {
            r=2;
            c=1;
        }
         else if(str=='G' ||str=='g')
        {
            r=2;
            c=2;
        }
         else if(str=='I' ||str=='i'||str=='J'||str=='j')
        {
            r=2;
            c=3;
        }
         else if(str=='K' ||str=='k')
        {
            r=2;
            c=4;
        }
         else if(str=='L' ||str=='l')
        {
            r=3;
            c=0;
        }
         else if(str=='P' ||str=='p')
        {
            r=3;
            c=1;
        }
         else if(str=='Q' ||str=='q')
        {
            r=3;
            c=2;
        }
         else if(str=='S' ||str=='s')
        {
            r=3;
            c=3;
        }
         else if(str=='T' ||str=='t')
        {
            r=3;
            c=4;
        }
         else if(str=='U' ||str=='u')
        {
            r=4;
            c=0;
        }
         else if(str=='V' ||str=='v')
        {
            r=4;
            c=1;
        }
         else if(str=='W' ||str=='w')
        {
            r=4;
            c=2;
        }
         else if(str=='X' ||str=='x')
        {
            r=4;
            c=3;
        }
         else if(str=='Z' ||str=='z')
        {
            r=4;
            c=4;
        }

         //int temp=(r,c);
         return 0;
    
}
void encrypt( string st,int n)
{
   cout<<'a';
    string temp[n];
    int i=0;
    int r1,r2,c1,c2;
    while(i<n)
    {
        cout<<'c';
    position(r1,c1,st[i]);
    i++;
    position(r2,c2,st[i]);
    }
  // same row

    if(r1==r2)
    {
        temp->push_back(matrix[r1] [(c1+1)%5]);
        temp->push_back(matrix [r2] [(c2+1)%5]);
    }
// same column
    else if(c1==c2)
    {
        temp->push_back(matrix [(r1+1)%5] [c1]);
        temp->push_back(matrix [(r2+1)%5] [c2]);
    }
// differnt row different column 
    else
    {
       temp->push_back(matrix[r1][c2]);
       temp->push_back(matrix[r2][c1]);
    }
for(i=0;i<n;i++)
{
    cout<<temp[i];
}

}
int main()
{
    string str;
    int n;
    cout<<"Enter the size of text "<<endl;
    cin>>n;
    cout<<"Enter plain string:"<<endl;
    cin>>str;
    encrypt(str,n);
    return 0;
}