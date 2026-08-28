#include <bits/stdc++.h>
using namespace std ;

void solve(){
    int n ;
    cin>> n ;

    vector<int> a(n);
    for(auto &it : a) cin>> it ;

    int target ;
    cin>> target ;

    //lower bound -> returns the index where value greater then or equal to target 

    int lower_idx = lower_bound(a.begin(), a.end(), target) - a.begin();
    if(lower_idx == n){
        cout<< "Element does not exits in vector"<<endl ;
    } else {
        cout<< a[lower_idx] <<endl ;
    }

    // upper bound -> returns the indes where value greater then the target 

    int upper_idx = upper_bound(a.begin(), a.end(), target) - a.begin(); 

    if(upper_idx == n){
        cout<<"Element does not exist"<<endl ;
    } else {
        cout<< a[upper_idx] <<endl ;
    }




}


int main(){
    int t = 1 ;

    while(t--){
        solve() ;
    }
}