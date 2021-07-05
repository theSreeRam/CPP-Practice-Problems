#include<bits/stdc++.h>
using namespace std;

void permutations(string s, int i, string curr){
	if(i==s.length()-1){
		cout<<s<<endl;
		return;
	}

	//otherwise we swap with the remaining and backtrack
	for(int j=i ; j<s.length(); j++){
		swap(s[i], s[j]);
		permutations(s, i+1, curr);
		swap(s[i], s[j]);
	}
}

int main(){

	string s;
	cin>>s;
	permutations(s, 0, "");
	
return 0;
}