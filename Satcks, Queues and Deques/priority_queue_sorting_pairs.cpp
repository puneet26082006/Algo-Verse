#include <bits/stdc++.h>
using namespace std ;

struct custom_compare {
    bool operator()(pair<int, int>& a, pair<int, int>& b){
        if(a.first == b.first){
            return (a.second < b.second);
        }

        return (a.first > b.first) ;
    }
};

void solve(){
    // priority_queue<int, vector<int>, greater<int>> pq ;    Min Priority Queue
    priority_queue<pair<int, int>, vector<pair<int, int>>, custom_compare> pq ;   
    
    pq.push({3,4});
    pq.push({3,3});
    pq.push({2,1});
    pq.push({6,3});

    cout<< pq.top().first <<" "<< pq.top().second <<endl ;
    pq.pop();
    cout<< pq.top().first <<" "<< pq.top().second <<endl ;

}

int main(){
    int t = 1 ;

    while(t--){
        solve() ;
    }
}