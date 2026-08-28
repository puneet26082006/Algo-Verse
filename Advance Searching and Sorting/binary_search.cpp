#include <bits/stdc++.h>
using namespace std ;

void solve(){
    int n ;
    cin>> n ;

    vector<int> a(n);
    for(auto &it : a) cin>>it ;

    int target ;
    cin>> target ;

    int low = 0 ;
    int high = n - 1 ;

    while(low <= high){
        int mid = low + (high - low)/2 ;
        if(a[mid] == target){
            cout<< "YES" <<endl ;
            return ;
        } else if(a[mid] > target){
            high = mid - 1 ;
        } else {
            low = mid + 1 ;
        }
    }

    cout<<"NO"<<endl ;





}

int main(){
    int t = 1 ;

    while(t--){
        solve();
    }
}