// https://codeforces.com/problemset/problem/251/A

#include <bits/stdc++.h>
using namespace std ;

#define ll long long 

void solve(){
    ll n, d;
    cin>> n >> d ;


    vector<ll> a(n);
    for(auto &it : a) cin>> it ;

    ll ans = 0 ;

    for(ll i = 2 ; i < n ; i++){
        ll idx = lower_bound(a.begin(), a.end(), a[i] - d) - a.begin() ;

        ll temp = i - idx ;

        if(temp >= 2){
            ans += temp * (temp - 1)/2 ;
        }
    }

    cout<< ans <<endl ;


}


int main(){
    int t = 1 ;
    // cin>> t ;
    
    while(t--){
        solve();
    }
}