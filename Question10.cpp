/*Each letter, a-z, is assigned values in the following way: a: 1, b: 2, …, z: 26. 
You are given string, S, consisting of lowercase English letters and an integer, K. 
Find the lexicographically minimal substring, whose sum is equal to K*/

// @zandacross-v2
// Implementation


#include<bits/stdc++.h>
#define ll long long int
using namespace std;

int main(){
    string s;
    ll k;
    cin >> s >> k;
    ll n = s.length();
    vector<ll> sum(n+1,0);
    vector<string> u;
    sum[0]=0;
    for(int i=1;i<=n;i++){
        sum[i] = sum[i-1] + (s[i-1]-96);
    }
    for(int i=0;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            if(sum[j] - sum[i]==k){
                u.push_back(s.substr(i,j-1));
            }
        }
    }
    if(u.size()==0){
        cout << -1 << endl;
        return 0;
    }
    sort(u.begin(),u.end());
    cout << u[0] << endl;
    return 0;
}
