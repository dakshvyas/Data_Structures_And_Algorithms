#include<iostream>
#include<map>
#include<unordered_map>
using namespace std;
int main(){
    //creation
    unordered_map<string,int>m;
    //insertion
    //1
    pair<string,int> p1 =make_pair("babbar",3);
   m.insert(p1);
    //2
    pair<string,int> p2("love",2);
    m.insert(p2);
    //3
    m["mera"]=1;
    m["mera"]=2;
    //Searching
   cout<<m["mera"]<<endl;
   cout<<m.at("babbar")<<endl;
   cout<<m["unknown"];
   cout<<m.at("unknown")<<endl;
cout<<m.size()<<endl;

unordered_map<string,int> ::iterator it=m.begin();

while(it!=m.end()){
    cout<<it->first<<" "<<it->second<<endl;
    it++;
}
    return 0;
}