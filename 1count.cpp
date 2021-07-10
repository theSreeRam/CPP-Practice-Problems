#include<bits/stdc++.h>
using namespace std;



int main(){

	int n, k;
	cin>>n>>k;
	int arr[n];

	for(int i=0; i<n; i++){
		cin>>arr[i];
	}

	int left = 0, right = 0, countZero = 0;
	int res = 0, window = 0, window_start = 0;
	while(right<n){
		if(arr[right]==0){
			countZero++;
		}
		while(countZero>k){
			if(arr[left]==0){
				countZero--;
			}
			left++;
		}
		window = (right-left+1);
		if(window>res){
			res = window;
			window_start = left;
		}
		right++;

	}
	cout<<res<<endl;
	for(int i=window_start ; i<(window_start + res); i++){
		arr[i] = 1;
	}
	for(int i=0; i<n; i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
return 0;
}