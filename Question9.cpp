/*Given a string containing only lowercase alphabets, you have to convert it into a string 
such that it contains only vowels by doing minimum number of operations. In one operation, 
you could select a substring always starting from index 0, and move that substring forward 
or backward. Example of rolling forward or backward are given :
Rolling Forward
Input- axzf
Let index chosen be 0 to 3 and moving it forward
Output- byag
Rolling Backward
Input – axze
Let index chosen be 0 to 2 and moving it backwards
Output- zwyd*/

// @zandacross-v2
// Dynamic Programming


#include<bits/stdc++.h>
#define ll long long int
using namespace std;

int main(){
    string s;
    cin >> s;
    ll n = s.length();
    ll dp[n+1][5][2];
    unordered_map<ll,char> mp;
    mp[0] = 'a'; mp[1] = 'e';mp[2] = 'i';mp[3] = 'o';mp[4]='u';
    for(int i=0;i<5;i++){
        dp[n][i][1] =0;
        dp[n][i][0] =0;
    }
    for(int i=n-1;i>=0;i--){
        for(int j=0;j<5;j++){
            ll val = INT_MAX,fix = INT_MAX,swap = INT_MAX,test = INT_MAX;
            for(int k=0;k<5;k++){
                char pos = 'a' + (s[i] + dp[i+1][k][1] - 97)%26;
                char pos2 = 'a' + (s[i] - dp[i+1][k][0] - 97)%26;
                if(mp[j]>=pos){
                    val = min(val,mp[j] - pos + dp[i+1][k][1]);
                    swap = min(swap,26 - mp[j] + pos + dp[i+1][k][1]);
                }
                if(mp[j]>=pos2){
                    fix = min(fix,mp[j] - pos2 + dp[i+1][k][0]);
                    test = min(test,26 - mp[j] + pos2 + dp[i+1][k][0]);
                }
            }
            dp[i][j][1] = min(val,fix);
            dp[i][j][0] = min(swap,test);
        }
    }
    ll ans = INT_MAX;
    for(int i=0;i<5;i++){
        ans = min(ans,min(dp[0][i][1],dp[0][i][0]));
    }
    cout << ans << endl;
    return 0;
}
