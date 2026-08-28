#include <bits/stdc++.h>
using namespace std ;

typedef long long ll ;

void solve(){
    ll n ;
    cin>> n ;

    
    vector<ll> a(n);
    
    for(auto &it : a) cin >> it ;

    ll res = (a[0] * a[1])/ __gcd(a[0],a[1]) ;

    for(ll i = 2 ; i < n ; i++){
        res = (res * a[i])/ __gcd(res, a[i]);
    }

    cout<< res <<endl ;
}


int main(){
    int t = 1;
    while(t--){
        solve();
    }
}  