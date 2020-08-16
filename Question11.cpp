/*Given a string str, the task is to find the minimum number of 
characters to be inserted to convert it to palindrome.*/

// @zandacross-v2
// Dynamic Programming


#include<bits/stdc++.h>
#define ll long long int
using namespace std;

int main(){
    string s;
    cin >> s;
    int n = s.length();
    vector< vector<ll> > dp(n,vector<ll>(n,0));
    for(int i=1;i<n;i++){
        for(int j=i,l=0;j<n;j++,l++){
            if(s[j]==s[l]){
                dp[l][j] = dp[l+1][j-1];
            }
            else{
                dp[l][j] = min(dp[l+1][j],dp[l][j-1]) + 1;
            }
        }
    }
    cout << dp[0][n-1] << endl;
}
