#include <bits/stdc++.h>
using namespace std ;

#define ll long long 

// Given an integer n, return the square root of n rounded down to an integer 
// Input : n = 14 
// Output : 3 
// n -> 1e18 

// bool helper(ll target , ll mid){
//     return (mid * mid <= target);
// }

void solve(){
    ll n ;
    cin>> n ;

    ll si = 0 ;
    ll ei = 1e9 ;

    ll ans = -1 ;

    // lambda function 

    auto helper = [&](ll mid) -> bool {
        return (mid * mid <= n);
    };

    // TTTTFFFF
    while(si <= ei){
        ll mid = si + (ei - si)/2 ;
        if(helper(mid)){
            ans = mid ;
            si = mid + 1 ;
        } else {
            ei = mid - 1 ;
        }
    }

    // FFFFFFFTTTTTTT
    // while(si<=ei){
    //     ll mid = si + (ei-si)/2;
    //     if(helper(mid,n)){
    //         ans=mid;
    //         ei=mid-1;
    //     }
    //     else{
    //         si=mid+1;
    //     }
    // }

    cout<< ans <<endl ;
}


int main(){
    int t = 1 ;

    while(t--){
        solve() ;
    }
}