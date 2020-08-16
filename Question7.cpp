/*You have been given a m*n chess board and there were black pawns on the board(represented by 1).
You have to put your white pawn on all possible position’s where it can be and the calculate how
 many kills are possible from each location and sum it up.You can only move straight (x+1, y) 
 and for a kill diagonal move (x+1, y+1) & (x+1, y-1)*/

// @zandacross-v2
// Dynamic Programming


#include<bits/stdc++.h>
#define ll long long int
#define ff first
#define ss second
using namespace std;

int main(){
    ll n,m;
    cin >> n >> m;
    vector< vector<ll> > a(n,vector<ll>(m,0)),dp(n,vector<ll>(m,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> a[i][j];
        }
    }
    for(int j=0;j<m;j++){
        dp[n-1][j]=0;
    }
    for(int i=n-2;i>=0;i--){
        for(int j=0;j<m;j++){
            if(j-1>=0 and a[i+1][j-1]==1){
                dp[i][j] = max(dp[i][j],dp[i+1][j-1] + 1);
            }
            if(a[i+1][j]==0){
                dp[i][j] = max(dp[i][j],dp[i+1][j]);
            }
            if(j+1<m and a[i+1][j+1]==1){
                dp[i][j] = max(dp[i][j],dp[i+1][j+1] + 1);
            }
        }
    }
    ll sum=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(a[i][j]==0){
                sum += dp[i][j];
            }
        }
    }
    cout << sum << endl;
    return 0;
}
