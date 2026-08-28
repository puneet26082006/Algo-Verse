#include <bits/stdc++.h>
using namespace std ;

void solve(){
    stack<int> st ;
    st.push(1);
    st.push(2);
    st.push(3);

    st.pop() ;

    cout<< st.top() <<endl ;
    cout<< st.size() <<endl ;

    if(st.empty()){
        cout<< "Stack is empty" <<endl ;
    } else {
        cout<< "Stack is not empty " <<endl ;
    }
}


int main(){
    int t = 1 ;

    while(t--){
        solve() ;
    }
}