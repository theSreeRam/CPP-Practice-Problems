#include<bits/stdc++.h>
using namespace std;

int **dp = new int*[1001];

bool targetSum(int arr[], int n, int i, int sum){
	if(i == n) {
		return false;
	}
	if(sum==0){
		return true;
	}
	if(sum<0){
		return false;
	}
	if(dp[i][sum] != -1){
		return dp[i][sum];
	}
	//Include the current
	bool res_inc = targetSum(arr, n, i+1, sum - arr[i]);
	bool res_exc = targetSum(arr, n, i+1, sum);
	return dp[i][sum] = (res_inc or res_exc);
}

int main(){

	int n, sum;
	cin>>n>>sum;
	int arr[n];
	for (int i = 0; i < n; ++i)
	{
		cin>>arr[i];
	}
	for(int i=0; i<1001; i++){
		dp[i] = new int[1001];
		for(int j=0; j<1001; j++){
			dp[i][j] = -1;
		}
	}

	if(targetSum(arr, n, 0,  sum)){
		cout<<"Yes"<<endl;
	} else {
		cout<<"No"<<endl;
	}
	
return 0;
}