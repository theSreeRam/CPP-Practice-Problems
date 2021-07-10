// Problem Name - K-Ordered LCS
// Tags - Dynamic Programming
// Any programmer worth his salt would be familiar with the famous Longest Common Subsequence problem. Mancunian was asked to solve the same by an incompetent programmer. As expected, he solved it in a flash. To complicate matters, a twist was introduced in the problem.

// In addition to the two sequences, an additional parameter k was introduced. A k-ordered LCS is defined to be the LCS of two sequences if you are allowed to change atmost k elements in the first sequence to any value you wish to. Can you help Mancunian solve this version of the classical problem?

// Input Format
// The first line contains three integers N, M and k, denoting the lengths of the first and second sequences and the value of the provided parameter respectively. The second line contains N integers denoting the elements of the first sequence. The third line contains M integers denoting the elements of the second sequence.

// Constraints
// 1 <= N, M <= 2000
// 1 <= k <= 5
// 1 <= element in any sequence <= 109

// Output Format
// Print the answer in a new line.

// Sample Input
// 5 5 1
// 1 2 3 4 5
// 5 3 1 4 2
// Sample Output
// 3


#include<bits/stdc++.h>
using namespace std;

int dp[2004][2005];

int lcs(int arr1[], int arr2[], int i, int j, int n, int m){
	if(i==n or j==m){
		return 0;
	}
	if(dp[i][j] != -1){
		return dp[i][j];
	}
	if(arr1[i] == arr2[j]){
		return dp[i][j] = 1 + lcs(arr1, arr2, i+1, j+1, n, m);
	}
	int op1 = lcs(arr1, arr2, i+1, j, n , m);
	int op2 = lcs(arr1, arr2, i, j+1, n , m);
	return dp[i][j] = max(op1, op2);

}

int main(){

	memset(dp, -1, sizeof(dp));

	int n, m, k;
	cin>>n>>m>>k;
	int arr1[n], arr2[m];
	for(int i=0; i<n; i++){
		cin>>arr1[i];
	}
	for(int i=0; i<m; i++){
		cin>>arr2[i];
	}

	int res = lcs(arr1, arr2, 0, 0, n, m);
	res = res + k;
	res = min(res, m);
	res = min(res, n);
	cout<<res<<endl;
	
return 0;
}