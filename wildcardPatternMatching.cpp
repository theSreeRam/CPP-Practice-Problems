#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> dp;

int finding(string s, string p, int n, int m){
	    if (n < 0 && m < 0)
        return 1;
   
    // return 0 if m is negative
    if (m < 0)
        return 0;
   
    // return n if n is negative
    if (n < 0)
    {
        // while m is positve
        while (m >= 0)
        {
            if (p[m] != '*')
                return 0;
            m--;
        }
        return 1;
    }
    
    // if dp state is not visited
    if (dp[n][m] == -1)
    {
        if (p[m] == '*')
        {
            return dp[n][m] = finding(s, p, n - 1, m)
                              || finding(s, p, n, m - 1);
        }
        else
        {
            if (p[m] != s[n] && p[m] != '?')
                return dp[n][m] = 0;
            else
                return dp[n][m]
                       = finding(s, p, n - 1, m - 1);
        }
    }
   
    // return dp[n][m] if dp state is previsited
    return dp[n][m];

}

int main(){

	string str, pattern;
	cin>>str>>pattern;
	dp.clear();
	dp.resize(str.size()+1, vector<int>(pattern.size()+1, -1));
	cout<<finding(str, pattern, str.size()-1, pattern.size()-1);
	
return 0;
}