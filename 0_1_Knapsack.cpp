// Problem Name - knapsack 0 - 1 
// Tags - Dynamic Programming

// You are packing for a vacation on the sea side and you are going to carry only one bag with capacity S (1 <= S <= 1000). You also have N (1<= N <= 1000) items that you might want to take with you to the sea side. Unfortunately you can not fit all of them in the knapsack so you will have to choose. For each item you are given its size and its value. You want to maximize the total value of all the items you are going to bring. What is this maximum total value?

// Input Format
// On the first line you are given N and S.
// Second line contains N space separated integer where ith integer denotes the size of ith item. Third line contains N space seperated integers where ith integer denotes the value of ith item.

// Constraints
// 1 <= S,N <= 1000

// Output Format
// Output a single integer showing the maximum value that can be obtained by optimally choosing the items.

// Sample Input
// 5 4
// 1 2 3 2 2 
// 8 4 0 5 3
// Sample Output
// 13
// Explanation
// Total capacity = 4.
// Pick size 1 with value 8 and size 2 with value 5.



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
		profit_included = value[i] + knapsack(s-weight[i], i+1, weight, value, n);
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