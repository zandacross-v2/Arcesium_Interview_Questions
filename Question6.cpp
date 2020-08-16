/*A boat when has full fuel tank can cover d stops. There are n stops 
and it’s given in an array that which of the stops have fuel station. 
Boat can be stopped at such stops to refill the tank. You have to minimize 
the number of stops to start from 1st station and reach the nth station.*/

// @zandacross-v2
// Implementation


#include<bits/stdc++.h>
#define ll long long int
using namespace std;

int main(){
    ll n,d;
    cin >> n >> d;
    vector<ll> v(n,0);
    for(int i=0;i<n;i++){
        cin >> v[i];
    }
    ll i=0,index,count=0;
    while(i<n){
        for(int j=i;j<i+d;j++){
            if(j==n-1){
                index = n;
                break;
            }
            if(v[j]==1){
                index = j;
            }
        }
        i = index;
        count++;
    }
    cout << --count << endl;
}
