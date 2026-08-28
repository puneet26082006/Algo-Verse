#include <bits/stdc++.h>
using namespace std ;

void solve(){
    int n ;
    cin>> n ;

    vector<int> a(n);
    for(auto &it : a) cin>> it ;

    int res = 0 ;

    for(int i = 0 ; i < n ; i++){
        res = __gcd(res, a[i]);
    }

    cout<< res <<endl ;


}

int main(){
    int t = 1 ;
    while(t--){
        solve() ;
    }
}