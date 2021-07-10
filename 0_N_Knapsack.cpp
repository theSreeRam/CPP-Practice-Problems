// Problem Name - knapsack 0 - N , 0-N Knapsack
// Tags - Dynamic Programming


// You've heard of 0-1 knapsack. Below is the problem statement for the same.

// Given weights and values of n items, put these items in a knapsack of capacity cap to get the maximum total value in the knapsack. In other words, given two integer arrays val[0..n-1] and wt[0..n-1] which represent values and weights associated with n items respectively. Also given an integer cap which represents knapsack capacity, find out the maximum value subset of val[] such that sum of the weights of this subset is smaller than or equal to cap. You cannot break an item, either pick the complete item, or don’t pick it (0-1 property).
// There is a little twist for 0-N knapsack. You can pick an element more than once. Now you have to find maximum value multi subset of val[] such that sum of the weights of this subset is smaller than or equal to cap.

// Note: Maximum value subset means the sunset with maximum sum of all the values in subset.

// Input Format
// The first line contains two integers, representing n(size of val[]) and cap respectively. The subsequent line contains n integers representing the wt[] array. The next line, again, contains n integers representing the val[] array.

// Constraints
// 1 <= n,cap <= 1000 1 <= wt[i] <= cap 1 <= val[i] <= 100000

// Output Format
// Print a single integer, the answer to the problem.

// Sample Input
// 5 11
// 3 2 4 5 1
// 4 3 5 6 1
// Sample Output
// 16
// Explanation
// We take second item 4 times and fifth item one time to make the total values 16.




#include<bits/stdc++.h>
using namespace std;

int dp[1002][1002];

int knapsack(int s, int i, int weight[], int value[], int n){
	if(i==n){
		return 0;
	}
	//We can include the current item and find remaining profit
	if(dp[s][i]!=-1){
		return dp[s][i];
	}
	int profit_included = 0, profit_excluded = 0;;

	if(weight[i] <= s){
		profit_included = value[i] + knapsack(s-weight[i], i, weight, value, n);
	}

	//Or we exclude the current item and find profit

	profit_excluded = knapsack(s, i+1, weight, value, n);

	return dp[s][i] = max(profit_excluded, profit_included);

}

int main(){

	memset(dp, -1, sizeof(dp));
	int n, s;	
	cin>>n>>s;
	int value[n] , weight[n];
	
	for(int i=0; i<n; i++){
		cin>>weight[i];
	}

	for(int i=0; i<n; i++){
		cin>>value[i];
	}
	
	int maxValue = knapsack(s, 0, weight, value, n);
	cout<<maxValue<<endl;
return 0;
}