// Problem Name - Minimum Jumps Required

// You are provided an array of integers where each element represents the max number of steps you can take to move ahead. You need to check that how many minimum steps required to reach at the end of the array.

// Hint - If N==0 you can never move forward, your return INT_MAX (Infinity).

// Input Format
// First line contains integer t which is number of test case. For each test case, it contains an integers n which the size of array A[]. Next line contains n space separated integers.

// Constraints
// 1<=t<=50
// 1<=n<=1000
// 0<=A[i]<=100

// Output Format
// Print the minimum number of jumps.

// Sample Input
// 1
// 11
// 1 3 5 8 9 2 6 7 6 8 9
// Sample Output
// 3
// Explanation
// 1-> 3 (you can pick 5 or 8 or 9 , pick either 8 or 9) -> 8 -> 9



#include<bits/stdc++.h>
using namespace std;

//Let's first try to solve this question using recursion

int minJumps(int arr[], int n){

	int jumps[n] = {0};
	int i, j;
	//Already reached the last point
	if(n==0 or arr[0] ==0){
		return INT_MAX;
	}

	jumps[0] = 0; //Base Case

	for(i=1; i<n; i++){
		jumps[i] = INT_MAX;
		for(j = 0; j<i; j++){
			if( i<= j + arr[j] && jumps[j] != INT_MAX){
				jumps[i] = min(jumps[i], jumps[j] + 1);
				break;
			}
		}
	}
	return jumps[n-1];

}

int main(){

	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int arr[n];
		for(int i=0; i<n; i++){
			cin>>arr[i];
		}

		cout<<minJumps(arr, n)<<endl;

	}
	
return 0;
}
