/*You are given N distinct coins. In one move you pick a random coin of value X 
and then you remove all the coins with value X-1 and X+1 along with the coin X. 
The game gets finished when no coins are left to pick. Find the maximum number 
of moves in which you can finish the game. Constraints : 1 <= N <= 10^5*/

// @zandacross-v2
// Priority_queue and Implemenetation


#include<bits/stdc++.h>
#define ll long long int
using namespace std;

int main(){
    ll n;
    cin >> n;
    vector<ll> v(n,0);
    unordered_map<ll,ll> mp;
    for(int i=0;i<n;i++){
        cin >> v[i];
        mp[v[i]]++;
    }
    priority_queue<pair<int,int>> q;
    for(auto x:mp){
        q.push({x.second,x.first});
    }
    ll count=0;
    while(!q.empty()){
        ll k = q.top().first;
        ll l = q.top().second;
        q.pop();
        if(mp.find(l)==mp.end()){
            continue;
        }
        if(mp.find(l+1)!=mp.end()){
            mp.erase(l+1);
        }
        if(mp.find(l-1)!=mp.end()){
            mp.erase(l-1);
        }
        count +=k;
    }
    cout << count << endl;
}
