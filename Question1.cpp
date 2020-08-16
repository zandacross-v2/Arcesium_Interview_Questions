/*Given a starting string and an ending string and an array of words, 
you have to return minimum number of operations required to convert 
start string to end string such that you can change only one character 
of the string in one operation and all the intermediate strings formed 
should be present in the array. If no way is possible return -1.*/

// @zandacross-v2
// BFS Traversal


#include<bits/stdc++.h>
#define ll long long int
#define ff first
#define ss second
using namespace std;

int main(){
    string s,e;
    cin >> s >> e;
    ll a= s.length(),b = e.length();
    ll n;
    cin >> n;
    unordered_map<string,ll> mp;
    vector<string> v(n,"");
    for(int i=0;i<n;i++){
        cin >> v[i];
        mp[v[i]]++;
    }
    if(a!=b){
        cout << "-1" << endl;
        return 0;
    }
    vector<ll> mark(n,0);
    ll count=0;
    queue<pair<string,ll>> q;
    q.push({s,0});
    while(!q.empty()){
        string k = q.front().ff;
        ll d = q.front().ss;q.pop();
        if(k==e){
            cout << d + 1 << endl;
            return 0;
        }
        for(int i=0;i<n;i++){
            count=0;
            for(int j=0;j<a;j++){
                if(k[j]!=v[i][j]){
                    count++;
                }
            }
            if(mark[i]==0 and count==1){
                q.push({v[i],d + 1});
                mark[i]=1;
            }
        }
    }
    cout << "-1" << endl;
    return 0;
}
