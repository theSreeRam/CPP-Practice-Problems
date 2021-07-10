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

		minJumps(arr, n, i);

	}
	
return 0;
}
