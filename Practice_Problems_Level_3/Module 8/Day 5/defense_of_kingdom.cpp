#include <bits/stdc++.h>
using namespace std;


void solve() {
    int w, h, n ;
    cin>> w >> h >> n ;

    vector<int> x(n);
    vector<int> y(n);

    for(int i = 0 ; i < n ; i++){
        cin>> x[i] >> y[i] ;
    }

    if(n == 0){
        cout<< w * h <<endl ;
        return ;
    }

    sort(x.begin(), x.end());
    sort(y.begin(), y.end());

    int max_w = x[0] - 1 ;
    int max_h = y[0] - 1 ;

    for(int i = 1 ; i < n ; i++){
        max_w = max(max_w, x[i] - x[i - 1] -  1) ;
        max_h = max(max_h, y[i] - y[i - 1] -  1) ;
    }

    max_w = max(max_w , w - x[n - 1]);
    max_h = max(max_h , h - y[n - 1]);

    int ans = max_w * max_h ;

    cout<< ans <<endl ;


}






int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
}


