#include<bits/stdc++.h>
using namespace std;
int dp[10000][10000];

int optimal(int arr[], int n, int i, int j){
	if(i>j){
		return 0;
	}
	if(j==i+1){
		return max(arr[i], arr[j]);
	}
	if(dp[i][j]!=-1){
		return dp[i][j];
	}

	return dp[i][j] = max(arr[i] + min(optimal(arr, n, i+2,j), optimal(arr, n, i+1, j-1)), arr[j] + min(optimal(arr, n, i,j-2), optimal(arr, n, i+1, j-1)));

}

int main(){

	int n;
	cin>>n;
	int arr[n];
	for (int i = 0; i < n; ++i)
	{
		cin>>arr[i];
	}
	memset(dp, -1, sizeof(dp));
	cout<<optimal(arr, n, 0, n-1)<<endl;
return 0;
}