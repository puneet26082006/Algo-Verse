// https://atcoder.jp/contests/abc119/tasks/abc119_d

#include <bits/stdc++.h>
using namespace std ;

#define ll long long 
#define pb push_back
const ll INF = 1e18 ;

void solve() {
    ll A, B, Q ;
    cin>> A >> B >> Q ;

    vector<ll> shrines;

    shrines.pb(-INF);
    for(ll i = 0 ; i < A ; i++){
        ll val ;
        cin>> val ;
        shrines.pb(val);
    }
    shrines.pb(INF);

    vector<ll> temples ;
    temples.pb(-INF);
    for(ll i = 0 ; i < B ; i++){
        ll val ;
        cin>> val ;
        temples.pb(val);
    }
    temples.pb(INF);

    
    
    while(Q--){
        ll x ;
        cin>> x ;
        
        ll t_right_idx = lower_bound(temples.begin(), temples.end(), x) - temples.begin() ;
        ll s_right_idx = lower_bound(shrines.begin(), shrines.end(), x) - shrines.begin() ;
        
        ll t_left_idx = t_right_idx - 1 ;
        ll s_left_idx = s_right_idx - 1 ;
        
        ll t_val[] = {temples[t_right_idx], temples[t_left_idx]};
        ll s_val[] = {shrines[s_right_idx], shrines[s_left_idx]};
        
        
        ll ans = INF ;
        for(ll i = 0 ; i < 2 ; i++){
            for(ll j = 0 ; j < 2 ; j++){
                ll t = t_val[i];
                ll s = s_val[j];

                ll dist1 = abs(x - s) + abs(s - t);
                ll dist2 = abs(x - t) + abs(t - s);

                ans = min({ans, dist1, dist2});

            }
        }


        cout<< ans <<endl ;



        
        
    }


}


int main(){
    int t = 1 ;
    // cin>> t ;

    while(t--){
        solve();
    }
}