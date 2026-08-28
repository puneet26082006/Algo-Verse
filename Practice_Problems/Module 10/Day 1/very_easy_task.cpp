// https://codeforces.com/edu/course/2/lesson/6/2/practice/contest/283932/problem/C

#include <bits/stdc++.h>
using namespace std ;

void solve(){
    int n, x, y ;
    cin>> n >> x >> y ;

    if(n == 1){
        cout<< min(x, y) <<endl ;
        return ;
    }

    int first_copy = min(x, y);

    int si = 0 ;
    int ei = (n - 1) * min(x, y) ;  // worst case only one machine is used  

    int ans = -1 ;

    auto helper = [&](int mid) -> bool {
        return (mid/x + mid/y >= n - 1);
    };

    while(si <= ei){
        int mid = si + (ei - si)/2 ;

        if(helper(mid)){
            ans = mid ;
            ei = mid - 1 ;
        } else {
            si = mid + 1 ;
        }
    }

    cout<< ans + first_copy <<endl ;


}


int main(){
    int t = 1;
    // cin>> t ;

    while(t--){
        solve();
    }
}