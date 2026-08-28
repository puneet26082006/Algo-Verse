// https://codeforces.com/contest/1479/problem/A


#include <bits/stdc++.h>
using namespace std ;

int ask(int x){
    cout<< "?" <<" "<< x <<endl ; 
    int num ;
    cin>> num ;
    return num ;
}

int main(){
    int n ;
    cin>> n ;

    int si = 1 ;
    int ei = n ;
    int mid = 1 ;

    int ans = -1 ;

    while(si <= ei){
        mid = (si + ei)/2 ;

        int num = ask(mid);

        int num1 = 0 ;
        if(mid - 1 < 1){
            num1 = 1e9 ;
        } else {
            num1 = ask(mid - 1);

        }

        int num2 = 0 ;
        if(mid + 1> n){
            num2 = 1e9 ;
        } else {
            num2 = ask(mid + 1);
        }

        if(num < num1 && num < num2){
            ans = num ;
            break ;
        } else if(num > num2){
            si = mid + 1 ;
        } else {
            ei = mid - 1 ;
        }
    }

    cout<<"! " << mid <<endl ;
}