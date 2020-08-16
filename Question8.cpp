/*A and B play a game. They are given an array of positive numbers. Each player 
in his turn picks up 2 numbers from the array such that the difference of the 
numbers does not exist in the array. He then places the difference into the array
 too thus increase the array count by 1. Then the next player repeats the same process. 
 The game continues till there are no 2 numbers such that difference does not exist in 
 the array. The one who’s not able to choose numbers loses. If A starts the game and 
 the game proceeds optimally, find who’ll win the game*/

// @zandacross-v2
// Implementation


#include<bits/stdc++.h>
#define ll long long int
#define ff first
#define ss second
using namespace std;

int main(){
    ll n,g;
    cin >> n;
    vector<ll> v(n,0);
    for(int i=0;i<n;i++){
        cin >> v[i];
    }
    g = v[0];
    ll mx = v[0];
    for(int i=1;i<n;i++){
        g = __gcd(v[i],g);
        mx = max(v[i],mx);
    }
    ll moves = (mx/g) - n;
    if(moves%2==0){
        cout << "B" << endl;
    }
    else{
        cout << "A" << endl;
    }
    return 0;
}
