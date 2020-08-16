/*There is a river of N unit and there are K stones across the river, each stone will be in one of 
the N units.Starting from 0th location your first jump will always be 1 unit (consider previous jump as L units),
 now your next subsequent jump can be either L + 1 or L – 1.Note few of the stoes can be missing.
You have to output the sum of square of Jump which you’ll take from each stone.*/

// @zandacross-v2
// Dynamic Programming
// Incomplete Solution: Just checks if frog can reach the other end. Not path

#include<bits/stdc++.h>
#define ll long long int
using namespace std;

int main(){
    int n;
    cin >>n;
    vector<ll> stones(n,0);
    for(int i=0;i<n;i++){
        cin >> stones[i];
    }
    int i,j,s;
    if(stones[1]!=1 || n<2){
        cout << 0 << endl;
        return 0;
    }
    if(n==2){
        cout << 1 << endl;
        return 0;
    }
    vector<vector<bool>> dp(n,vector<bool>(n,0));
    dp[1][0]=1;
    for(i=2;i<n;i++){
        for(j=1;j<i;j++){
            s=stones[i]-stones[j]-1;
            if(s<n){
                if(s+1<n && dp[j][s+1])
                    dp[i][s]=1;
                if(dp[j][s])
                    dp[i][s]=1;
                if(s-1>=0 && dp[j][s-1])
                    dp[i][s]=1;
                if(i==n-1 && dp[i][s]){
                    cout << 1 << endl;
                    break;
                }
            }
        }
    }
    return 0;
}
