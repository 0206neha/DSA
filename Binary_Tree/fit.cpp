//Name-Neha Sanjay Patil,Roll n0-20,Batch-1
//Experiment-10
//Title-First Fit Algorithm

#include <iostream>

using namespace std;

int main()
{ 
    cout<<"\n\n Memory Management algorithm:First Fit";
   int bno, pno,bsize[5], psize[5] ,flag[5], alloc[5], i, j;
   //Read input :no of blocks & no of processes
   
   cout<<"\n\t Enter number of blocks:";
   cin>>bno;   //5
   cout<<"\n\t Enter number of processes:";
   cin>>pno;    //4
   
   //Read input:Block size:5,process size:3

   cout<<"Enter block size";
    for(i=0;i<bno;i++)
    cin>>bsize[i];
    
    cout<<"Enter process size";
    for(i=0;i<pno;i++)
    cin>>psize[i];
    
    //set default flag=0,alloc=-1
    for(i=0;i<5;i++)
    {
        flag[i]=0;
        alloc[i]=-1;
    }
    
    //use first fit algorithm
    for(i = 0; i < pno; i++)         
    {
		for(j = 0; j < bno; j++)
		{
			if(flag[j] == 0 && bsize[j] >= psize[i])
			{
				alloc[j] = i;
				flag[j] = 1;
				break;
			}
		}
    }
   
   cout<<"\nBlock no.\tsize\t\tprocess no.\t\tsize";
   for(i=0;i<bno;i++)
   {
       cout<<"\n"<<i+1<<"\t\t"<<bsize[i]<<"\t\t";
       if(flag[i]==1)
         cout<<alloc[i]<<"\t\t\t"<<psize[alloc[i]];
        else
         cout<<"Not Allocated";
   }
   

    return 0;
}
