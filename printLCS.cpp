// Problem Name - Print LCS (Longest Common Subsequence)
// Tags - Dynamic Programming, Backtracking

// A subsequence is a sequence that can be derived from another sequence by deleting some elements without changing the order of the remaining elements. For example, the sequence {A,B,D} is a subsequence of {A,B,C,D,E,F}, obtained after removal of elements C, E and F.

// Given two strings A and B of size n and m respectively, you have to print the Longest Common Subsequence(LCS) of strings A and B, where LCS is the longest sequence present in both A and B.

// Note: It is gauranteed that there is only one unique longest common subsequence

// Input Format
// Two strings A and B.

// Constraints
// 1 <= n,m <= 10^3

// Output Format
// Output the LCS of A and B.

// Sample Input
	// abc
	// acd	
// Sample Output
	// ac



#include<bits/stdc++.h>
using namespace std;

int dp[1001][1001];

int lcs(string s1, string s2, int i, int j){
	if(i==s1.length() or j == s2.length()){
		return 0;
	}
	
	if(dp[i][j]!=-1){
		return dp[i][j];
	}

	if(s1[i]==s2[j]){
		return dp[i][j] = 1 + lcs(s1,s2,i+1, j+1);
	}

	int op1 = lcs(s1,s2,i+1,j);
	int op2 = lcs(s1,s2,i,j+1);
	return dp[i][j] = max(op1, op2);
}


int main(){
	
	memset(dp, -1, sizeof(dp));

	string s1, s2;
	cin>>s1>>s2;

	//First let's find the LCS, then we'll backtrack from the dp array
	int res = lcs(s1,s2,0,0);
	
	// for(int i=0; i<10; i++){
	// 	for(int j=0; j<10; j++){
	// 		cout<<dp[i][j]<<" ";
	// 	}
	// 	cout<<endl;
	// }

	int n1 = s1.length(), n2 = s2.length();
	int i=0, j=0;

	while(i<n1 and j<n2){
		if(dp[i][j] == dp[i+1][j]){
			i++;
		}
		else if(dp[i][j] == dp[i][j+1]){
			j++;
		} else {
			if(dp[i][j]!=0){
				cout<<s1[i];
			}
			i++;
			j++;
		}
	}

return 0;
}











