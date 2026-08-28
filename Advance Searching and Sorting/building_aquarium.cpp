#include <bits/stdc++.h>
using namespace std ;

#define ll long long 

void solve(){
    ll n, x ;
    cin>> n >> x ;

    vector<int>a(n);
    for(auto &it : a) cin>> it ;

    
    auto helper = [&] (ll mid) -> bool {
        ll water_req = 0 ;
        for(ll i = 0 ; i < n ; i++){
            water_req += max(0LL, mid - a[i]);
        }
        
        return (water_req <= x); 
    };
    
    ll si = 1 ;
    ll ei = 1e10 ;
    ll ans = -1 ;

    while(si <= ei){
        ll mid = si + (ei - si) / 2 ;

        if(helper(mid)){
            ans = mid ;
            si = mid + 1 ;
        } else {
            ei = mid - 1 ;
        }
    }

    cout<< ans <<endl ;


}


int main(){
    int t ;
    cin>> t ;

    while(t--){
        solve();
    }
}