// Problem Name - Count Number of Binary Strings
// Tags - Dynamic Programming, DP, Recursion
// You are provided an integers N. You need to count all possible distinct binary strings of length N such that there are no consecutive 1’s.

// Input Format
// First line contains integer t which is number of test case. For each test case, it contains an integer n which is the the length of Binary String.

// Constraints
// 1<=t<=100 1<=n<=90

// Output Format
// Print the number of all possible binary strings.

// Sample Input
// 2
// 2
// 3
// Sample Output
// 3
// 5
// Explanation
// 1st test case : 00, 01, 10 2nd test case : 000, 001, 010, 100, 101



#include<bits/stdc++.h>
using namespace std;

long long dp[105];


int main(){
	dp[0] = 1;
	dp[1] = 2;
	dp[2] = 3;
	for(long long i=3; i<=105; i++){
		dp[i] = dp[i-1] + dp[i-2];
	}
	long long t;
	cin>>t;
	while(t--){
		long long n;
		cin>>n;
		cout<<dp[n]<<endl;
	}
	
return 0;
}

