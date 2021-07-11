// Problem Name - Mixtures

// Harry Potter has n mixtures in front of him, arranged in a row. Each mixture has one of 100 different colors (colors have numbers from 0 to 99).

// He wants to mix all these mixtures together. At each step, he is going to take two mixtures that stand next to each other and mix them together, and put the resulting mixture in their place.

// When mixing two mixtures of colors a and b, the resulting mixture will have the color (a+b) mod 100.

// Also, there will be some smoke in the process. The amount of smoke generated when mixing two mixtures of colors a and b is a*b.

// Find out what is the minimum amount of smoke that Harry can get when mixing all the mixtures together.
// You can find the original problem here.

// Input Format
// The first line of each input file will contain n, the number of mixtures. The second line will contain n integers between 0 and 99 - the initial colors of the mixtures.

// Constraints
// 1 <= n <= 100

// Output Format
// Output the minimum amount of smoke.

// Sample Input
// 3
// 40 60 20
// Sample Output
// 2400
// Explanation
// There are two possibilities: first mix 40 and 60 (smoke: 2400), getting 0, then mix 0 and 20 (smoke: 0); total amount of smoke is 2400. first mix 60 and 20 (smoke: 1200), getting 80, then mix 40 and 80 (smoke: 3200); total amount of smoke is 4400. The first scenario is a much better way to proceed.



#include<bits/stdc++.h>
using namespace std;

long long dp[1000][1000];

long long csum(int arr[], int s, int e){
	long long sum = 0;
	for(int i=s; i<=e; i++){
		sum += arr[i];
		sum %= 100;
	}
	return sum;
}

long long mixtures(int arr[], int n, int i, int j){
	//There can be K partitions from 0 to k-1, and we then ultimately mix them

	//Base case
	// cout<<"n:"<<n<<" s:"<<s<<" e:"<<e<<endl;
	if(i>=j){
		return 0;
	}

	if(dp[i][j]!=-1){
		return dp[i][j];
	}

	//Now otherwise we find for the two halves
	dp[i][j] = INT_MAX;
	for(int k=i; k<=j; k++){
		dp[i][j] = min(dp[i][j] , mixtures(arr, n, i,k) + mixtures(arr, n, k+1, j) + csum(arr, i,k) * csum(arr, k+1, j));
	}
	return dp[i][j];
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
	cout<<mixtures(arr, n, 0, n-1)<<endl;
	
return 0;
}