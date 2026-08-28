#include <bits/stdc++.h>
using namespace std ;

void solve(){
    priority_queue<int> pq ;   // max priority queue 

    pq.push(1);
    pq.push(2);
    pq.push(3);
    pq.push(9);
    pq.push(5);

    cout<< pq.top() <<endl ;
    pq.pop();
    cout<< pq.top()<<endl ;
    cout<< pq.size() <<endl ;

    if(pq.empty()){
        cout<< "Priority Queue is empty " <<endl ;
    } else {
        cout<< "Priority Queue is not empty"<<endl ;
    }
}

int main(){
    int t = 1;
    // cin>> t ;

    while(t--){
        solve() ;
    }
}