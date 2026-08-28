// https://codeforces.com/gym/101021/problem/1

#include <bits/stdc++.h>
using namespace std ;

int toGuess = 15 ;
bool testing = true ;

string interactor(int x){
    if(toGuess >= x) return ">=";
    return "<" ;
}

string ask(int x){
    cout<< x <<endl ;
    if(testing){
        cout<< interactor(x) << endl ;
        return interactor(x) ;
    }

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