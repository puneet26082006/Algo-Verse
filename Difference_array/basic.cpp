// Given an array with all 0s initially perform the following Q queries on it.
// In the ith query you will be given 3 integers: Li, Ri, Xi. You need to add Xi, to
// all the values in the array from index Li to Ri.
// After performing all the queries print the final state of the array.


#include <iostream>
#include <vector>
using namespace std ;

int main(){
    int n ;
    cin>> n ;

    vector<int> v(n,0);
    
    vector<int> diff(n + 1, 0);
    int q ;
    cin>> q ;
    
    while(q--){
        int l, r, x ;
        cin>>l >> r >> x ;  
        
        diff[l] += x ;
        diff[r + 1] -= x ;

    }

    for(int i = 1 ; i < n ; i++){
        diff[i] += diff[i - 1];
    }

    for(int i = 0 ; i < n ; i++){
        cout<<v[i] + diff[i] <<" " ;
    }
}