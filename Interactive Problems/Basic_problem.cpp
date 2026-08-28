// https://codeforces.com/gym/101021/problem/1

#include <bits/stdc++.h>
using namespace std ;


string ask(int x){
    cout<< x <<endl ;
    string c ;
    cin>> c ;
    return c ;
}


int main(){
    int l = 1 , r = 1e6 ;
    int ans = -1 ;

    while(l <= r){
        int mid = (l + r)/2 ;
        string result = ask(mid);

        if(result == ">="){
            ans = mid ;
            l = mid + 1 ;
        } else {
            r = mid - 1 ;
        }
    }

    cout<< "!" <<" "<< ans <<endl ;
}