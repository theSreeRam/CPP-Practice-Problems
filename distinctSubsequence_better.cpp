#include<bits/stdc++.h>
using namespace std;
#define MAX_CHAR 256
#define MOD 1000000007
long long int countSubsequence(string str){
	vector<long long int> last(MAX_CHAR, -1);
 
    // Length of input string
    long long int n = str.length();
 
    // dp[i] is going to store count of distinct
    // subsequences of length i.
    long long int dp[n + 1];
 
    // Empty substring has only one subsequence
    dp[0] = 1;
 
    // Traverse through all lengths from 1 to n.
    for (long long int i = 1; i <= n; i++) {
        // Number of subsequences with substring
        // str[0..i-1]
        dp[i] = (2 * dp[i - 1])%MOD;
 
        // If current character has appeared
        // before, then remove all subsequences
        // ending with previous occurrence.
        if (last[str[i - 1]] != -1)
            dp[i] = dp[i] - dp[last[str[i - 1]]];
 
        // Mark occurrence of current character
        last[str[i - 1]] = (i - 1);
    }
 
    return dp[n];

}

int main(){
	
	long long int t;
	cin>>t;
	while(t--){
		string s;
		cin>>s;
		cout<<countSubsequence(s)%1000000007<<endl;
	}	
return 0;
}
