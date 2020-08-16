/*You are given a string S composed of only lowercase letters and an array of points 
corresponding to each letter. You have to find maximum score you can get for a substring 
which starts and ends with same letter. Constraints : 1 <= |S| <= 10^5  -10 <= points <= 10*/

// @zandacross-v2
// Map and Implementation


#include<bits/stdc++.h>
#define ll long long int
using namespace std;

int main(){
    ll n;
    cin >> n;
    string s;
    cin >> s;
    vector<ll> v(n,0),sum(n,0);
    for(int i=0;i<n;i++){
        cin >> v[i];
    }
    unordered_map< ll,vector<ll> >mp;
    sum[0] = v[0];
    for(int i=1;i<n;i++){
        mp[s[i]].push_back(i);
        sum[i] = sum[i-1] + v[i];
    }
    ll mx = INT_MIN;
    for(auto x:mp){
        for(int i=0;i<x.second.size() - 1;i++){
            mx = max(mx,sum[x.second[i+1]] - sum[x.second[i]] + v[x.second[i]]);
        }
    }
    cout << mx << endl;
}
