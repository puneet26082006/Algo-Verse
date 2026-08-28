// https://www.spoj.com/problems/HS08PAUL/

#include <bits/stdc++.h>
// #include<ext/pb_ds/assoc_container.hpp>
// #include<ext/pb_ds/tree_policy.hpp>
using namespace std;



const int N = 1e7 + 7 ;
int seive[N + 1];

int ans[N + 1];

void precompute() {
    for(int i = 0 ; i < N ; i++){
        seive[i] = 0 ;
    }

    seive[0] = seive[1] = 1 ;

    for(int i = 2 ; i * i <= N ; i++){
        if(seive[i] == 0){
            for(int j = i * i ; j < N ; j += i){
                seive[j] = 1 ;
            }
        }
    }

    for(int i = 0 ; i < N ; i++){
        ans[i] = 0 ;
    }

    for(int x = 1 ; x <= 3500 ; x++){
        for(int y = 1 ; y <= 60 ; y++){
            int res = (x * x) + (y * y * y * y) ;

            if(res <= N && !seive[res]){
                ans[res] = 1 ;
            }
        }
    }

    for(int i = 1 ; i < N ; i++){
        ans[i] += ans[i - 1] ;
    }




}

void solve(){
    int n ;
    cin>> n ;



    cout<< ans[n] <<endl ;
}






int main() {
#ifndef ONLINE_JUDGE
    freopen("Error.txt", "w", stderr);
#endif

    precompute();

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
}


