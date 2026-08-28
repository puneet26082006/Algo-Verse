#include <iostream>
using namespace std ;

typedef long long ll ;


ll expo(ll a, ll b, ll mod){
    if(b == 0){
        return 1 ;
    }


    ll temp = expo(a, b/2, mod);
    temp %= mod ;

    temp = (temp * temp) % mod ;

    if(b & 1){
        temp = (temp * a) % mod ;
    }

    return temp ;
}

int main(){
    ll a, b ;
    cin>> a >> b ;
    ll mod = 1e7 ;

    
    cout<< expo(a, b, mod) <<endl ;
}