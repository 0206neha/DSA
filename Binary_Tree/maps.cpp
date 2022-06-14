#include<bits/stdc++.h>
#include<map>
#include<iterator>
using namespace std;

int main()
{
  map<int,int>mp;

  mp.insert(pair<int,int>(2,30));
  mp.insert(pair<int,int>(3,40));
  mp.insert(pair<int,int>(4,50));
  mp.insert(pair<int,int>(5,60));
  mp.insert(pair<int,int>(2,70)); //keys always remain sorted
  mp.insert(pair<int,int>(9,80));
  mp.insert(pair<int,int>(90,3));
  mp.insert(pair<int,int>(11,100));
  
map<int,int> :: iterator itr;
mp.erase(5);
mp.erase(mp.begin(),mp.find(4));
cout<<"\n The map mp is:\n";
cout<<"\tKEY\t ELEMENT\n";

for(itr=mp.begin(); itr!=mp.end(); ++itr)
{
    cout<<'\t'<<itr->first<<'\t'<<itr->second<<'\n';
}
cout<<"size is  "<<mp.size();
mp.clear();
return 0;
}