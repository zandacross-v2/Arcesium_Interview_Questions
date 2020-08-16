/*You have a key board with keys consisting of only alphabet from a-z and 
number of times you can use a key utmost is given in an array, if the value 
in array is zero means that particular key is already broken. Every key 
breaks after it is used for more than it’s threshold. Now given a string and 
a number K. Print the maximum length of prefix of string you can print
 with utmost k errors..*/

// @zandacross-v2
// Hashing and Implementation


#include<bits/stdc++.h>
#define ll long long int
#define ff first
#define ss second
using namespace std;

int main(){
    vector<ll> v(26,0);
    for(int i=0;i<26;i++){
        cin >> v[i];
    }
    string s;
    cin >> s;
    ll k,n,count=0,index=n-1;
    n = s.length();
    vector<ll> t(n,0);
    cin >> k;
    for(int i=0;i<n;i++){
        if(v[s[i]-'a']>0){
            v[s[i]-'a']--;
        }
        else{
            t[i]=1;
            count++;
        }
        if(count>k){
            index=i-1;
            break;
        }
    }
    ll sum=0;
    for(int i=0;i<26;i++){
        sum += v[i];
    }
    if(sum<k){
        for(int i=index;i>=0;i--){
            if(t[i]==1){
                k--;
            }
            else{
                sum ++;
            }
            if(sum>=k){
                index=i;
                break;
            }
        }
    }
    string ans="";
    for(int i=0;i<=index;i++){
        ans += s[i];
    }
    cout << ans << endl;
    return 0;
}
