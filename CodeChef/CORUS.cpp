#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int main() {
	// your code goes here
	int t,n,q;
	string str="";
	cin>>t;
	while(t--){
	    unordered_map<char,int> map,temp;
	    vector<long> arr;
	    cin>>n;
	    cin>>q;
	    cin>>str;
	    int a=0;
	    for(int i =0; i < q;i++){
	        cin>>a;
	        arr.push_back(a);
	    }
	    for(int i =0; i <str.size();i++){
	       if(map.count(str[i])==1)
	            ++map[str[i]];
	       else
	            map.insert({str[i],1});
	    }
	    long pend;
	   for(int i = 0;i<q;i++){
	       pend= 0;
	        temp = map;
	        for (auto itr = temp.begin(); itr != temp.end(); ++itr) { 
                itr->second = itr->second-arr[i];
                if(itr->second>0){
                    pend+=itr->second;
                }
                
            } 
            cout <<pend<<"\n";
            
	   }
	   
	}
	return 0;
}
