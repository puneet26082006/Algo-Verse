#include <bits/stdc++.h> 
using namespace std ;

int query(int l, int r){
    cout<< "? "<< l <<" "<< r <<endl ;
    int idx ;
    cin>> idx ;
    return idx ; 
}


int left(int l, int r, int s){
    int ans = -1 ;

    while(l <= r){
        int mid = (l + r)/2 ;
        if(query(mid, s) == s){
            ans = mid ;
            l = mid + 1 ;
        } else {
            r = mid - 1 ;
        }
    }

    return ans ;
}

int right(int l, int r, int s){
    int ans = -1 ;

    while(l <= r){
        int mid = (l + r)/2 ;
        if(query(s, mid) == s){
            ans = mid ;
            r = mid - 1 ;
        } else {
            l = mid + 1 ;
        }
    }

    return ans ;
}


int main(){
    int n ;
    cin>> n ;

    int idx_second = query(1, n);

    int idx_first = 0 ;
    if(idx_second > 1 && query(1, idx_second) == idx_second){
        idx_first = left(1, idx_second - 1, idx_second);
    } else {
        idx_first = right(idx_second + 1, n, idx_second);
    }

    cout<< "! " << idx_first <<endl ;
}