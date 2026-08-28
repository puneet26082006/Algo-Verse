#include <bits/stdc++.h>
using namespace std ;

void solve(){
    deque<int> dq ;

    dq.push_front(1);
    dq.push_back(2);
    dq.push_front(3);

    cout<< dq.front() <<endl ;
    dq.pop_back() ;
    cout<< dq.back() <<endl ;

    if(dq.empty()){
        cout<< "D-Queue is empty" <<endl ; 
    } else {
        cout << "D-Queue is not empty " <<endl ;
    }

}


int main(){
    int t = 1 ;

    while(t--){
        solve() ;
    }
}