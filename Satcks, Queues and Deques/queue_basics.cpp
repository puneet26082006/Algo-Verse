#include <bits/stdc++.h>
using namespace std ;

void solve(){
    queue<int> q ;

    q.push(1);
    q.push(2);
    q.push(3);

    cout<< q.front() <<endl ;
    q.pop() ;
    cout<< q.front() <<endl ;

    if(q.empty()){
        cout<< "Queue is empty" <<endl ; 
    } else {
        cout << "Queue is not empty " <<endl ;
    }

}


int main(){
    int t = 1 ;

    while(t--){
        solve() ;
    }
}