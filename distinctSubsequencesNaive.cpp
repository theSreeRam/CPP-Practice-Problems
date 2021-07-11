#include<bits/stdc++.h>
using namespace std;

unordered_set<string> dp;

void countSubsequence(string s, int i, string curr){
	if(i==s.length()){
		// cout<<"Curr : " <<curr<<endl;
		dp.insert(curr);
		return;
	}

	//Include the current item
	countSubsequence(s, i+1, curr + s[i]);
	//Exclude
	countSubsequence(s, i+1, curr);
}

int main(){
	
	int t;
	cin>>t;
	while(t--){
		string s;
		cin>>s;
		countSubsequence(s, 0, "");
		cout<<dp.size()<<endl;
		dp.clear();
	}	
return 0;
}
