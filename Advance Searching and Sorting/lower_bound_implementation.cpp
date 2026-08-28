#include <bits/stdc++.h>
using namespace std ;

void solve() {
    int n ;
    cin>> n ;

    vector<int> a(n);
    for(auto &it : a) cin>> it ;

    int target ;
    cin>> target ;

    int si = 0 ;
    int ei = n ;

    int ans = -1 ;

    auto helper = [&](int mid) -> bool {
        return a[mid] >= target ;
    };

    // FFFFFFFTTTTTTTTT
    while(si <= ei){
        int mid = si + (ei - si)/ 2 ;

        if(helper(mid)){
            ans = mid ;
            ei = mid - 1 ;
        } else {
            si = mid + 1 ;
        }
    }

    cout<< ans <<endl ;

}


int main(){
    int t = 1 ;

    while(t--){
        solve() ;
    }
}