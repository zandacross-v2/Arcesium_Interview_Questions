/*Given a array of positive integers, you have to find the 
smallest positive integer that can not be formed from the 
sum of numbers from array.*/

// @zandacross-v2
// Implementation


#include<bits/stdc++.h>
#define ll long long int
using namespace std;

int main(){
    ll n;
    cin >> n;
    vector<ll> v(n,0);
    for(int i=0;i<n;i++){
        cin >> v[i];
    }
    sort(v.begin(),v.end());
    if(v[0]!=1){
        cout << 1 << endl;
        return 0;
    }
    ll count=0;
    for(int i=1;i<n;i++){
        if(v[i]-v[i-1]!=1){
            count = i;
            break;
        }
    }
    ll ans =0;
    if(count==0){
        ans = (n*(n+1))/2;
    }
    else{
        ans = (count*(count+1))/2;
    }
    cout << ans + 1 << endl;
    return 0;
}
