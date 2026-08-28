#include <iostream>
#include <vector>
using namespace std ;

int main(){
    int n ;
    cin>> n ;

    vector<int> v(n);
    for(auto &it: v) cin>>it ;

    vector<int>pre(n);
    pre[0] = v[0];

    for(int i = 1 ; i < n ; i++){
        pre[i] = pre[i - 1] + v[i];
    }

    int q ;
    cin>> q ;
    while(q--){
        int l, r ;
        cin>> l >> r ;

        int sum = pre[r];
        if(l > 0){
            sum -= pre[l - 1];
        }

        cout<< sum << endl ;
    }

}
