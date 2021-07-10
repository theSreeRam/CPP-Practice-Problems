// Bytelandian Gold Coins Problem – Dynamic Programming Solutions
// Problem Description
// Each Bytelandian gold coin has an integer number written on it. A coin n can be exchanged in a bank into three coins: n/2, n/3 and n/4. But these numbers are all rounded down (the banks have to make a profit).

// You can also sell Bytelandian coins for American dollars. The exchange rate is 1:1. But you can not buy Bytelandian coins.

// You have one gold coin of value n, 0 <= n <= 1000000000. What is the maximum amount of American dollars you can get for it?

// Problem Solution
// This is a Dynamic programming problem. We can observe that for amount upto 8, we can’t get more money by dividing (into n/2, n/3 and n/4). We will create an array to memoize the values. For any value, min. amount we can get out of it=n. We will compare this value with the value we get after dividing n and select the bigger value.

// Expected Input and Output
// Case-1:

 
// Amount of Bytelandian coin=8
// Maximum amount of american dollars which can be made out of it=8
// Case-2:

 
// Amount of Bytelandian coin=25
// Maximum amount of american dollars which can be made out of it=27
// Case-3:

 
// Amount of Bytelandian coin=520
// Maximum amount of american dollars which can be made out of it=576

#include<bits/stdc++.h>
using namespace std;

long long *dp = new long long [100000000];

long long coins(long long n){
	if(n==0 or n==1){
		return dp[n] = n;
	}
	
	if(n < 1000000){

		if(dp[n] != 0){
			return dp[n];
		} 
		long long op1 = coins(n/2);
		long long op2 = coins(n/3);
		long long op3 = coins(n/4);
		// cout<<"for n : "<<n<<" op1: "<<op1<<" op2: "<<op2<<" op3:"<<op3<<endl;
		return dp[n] = max(n, op1+op2+op3);
	} 

	long long x = coins(n/2) + coins(n/3) + coins(n/4);
	return  max(n, x);

}

int main(){

	long long n;
	cin>>n;

	dp[1] = 1;

	cout<<coins(n)<<endl;

	
return 0;
}
