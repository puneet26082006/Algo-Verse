// We want to calculate a to the power b with modulo mod 

#include <iostream> 
using namespace std ;

typedef long long ll ;

int expo(ll a, ll b, ll mod){
    ll res = 1 ;
    a %= mod ;

    while(b > 0){
        if(b & 1){
            res *= a ;
            res %= mod ;
        }

        a = (a * a) % mod;
        b >>= 1 ;
    }

    return res ;
}

int main(){
    ll a, b ;
    cin>> a >> b ;

    ll mod = 1e6 ;

    cout<< expo(a, b, mod);
}