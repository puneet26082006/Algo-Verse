// To find next smaller element towards left/ right 

#include <bits/stdc++.h>
using namespace std ;

void solve(){
    int n ;
    cin>> n ;

    vector<int>v(n);
    for(auto &it : v) cin>> it ;

    stack<int> st ;
    vector<int> ans(n);

    for(int i = 0 ; i < n ; i++){    // for nsr just change for(int i = n - 1 ; i >= 0 ; i--)
        while(!st.empty() && st.top() >= v[i]){  // next larger emement change st.top() <= v[i]  just 
            st.pop() ;
        }

        if(st.empty()){
            ans[i] = -1 ;
        } else {
            ans[i] = st.top() ;
        }

        st.push(v[i]);
    }

    for(auto &it : ans) cout<< it <<" ";
    cout<<endl ;

}

int main(){
    int t = 1 ;

    while(t--){
        solve() ;
    }
}