// https://codeforces.com/problemset/problem/1238/A

#include <iostream>
using namespace std ;
 
void solve(){
    long long x, y ;
    cin>> x >> y ;
    
    if((x - y) == 1){
        cout<< "NO" <<endl ;
    } else {
        cout<< "YES" <<endl ;
    }
}
 
int main(){
    int t ;
    cin>> t ;
    
    while(t--){
        solve();
    }
}