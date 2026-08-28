#include <iostream>
#include <vector>
using namespace std ;

const int N = 1e7 ;
int spf[N];

void solve(){
    int n ;
    cin>> n ;

    vector<int> prime ;

    while(n > 1){
        prime.push_back(spf[n]);
        n /= spf[n];
    }

    for(auto &it : prime) cout<< it <<" ";
    cout<<endl ;
}

int main(){

    for(int i = 0 ; i < N ; i++){
        spf[i] = i ;
    }

    for(int i = 2 ; i * i <= N ; i++){
        if(spf[i] == i){
            for(int j = i * i ; j <= N ; j += i){
                if(spf[j] == j){
                    spf[j] = i ;
                }
            }
        }
    }

    int t = 1 ;

    while(t--){
        solve();

    }
    
}