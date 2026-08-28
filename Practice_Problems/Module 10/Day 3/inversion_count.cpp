// https://www.spoj.com/problems/INVCNT/


#include <bits/stdc++.h>
using namespace std ;

#define ll long long 

ll temp[1000000];

ll merge(vector<ll>& a, ll si, ll ei){
    ll mid = si + (ei - si)/ 2 ;

    ll i = si ;
    ll j = mid + 1 ;
    ll k = 0 ;
    ll ans = 0 ;

    while(i <= mid && j <= ei){
        if(a[i] > a[j]){
            ans += mid - i + 1 ;
            temp[k] = a[j];
            j++ ;
            k++ ;
        } else {
            temp[k] = a[i];
            i++ ;
            k++ ;
        }
    }

    while(i <= mid){
        temp[k] = a[i];
        i++ ;
        k++ ;
    }

    while(j <= ei){
        temp[k] = a[j];
        j++ ;
        k++ ;
    }

    ll t = si ;
    for(ll idx = 0 ; idx <= (ei - si) ; idx++){
        a[t] = temp[idx];
        t++ ;
    }

    return ans ;
}

ll mergesort(vector<ll>& a, ll si, ll ei){
    if(si >= ei){
        return 0 ;
    }

    ll mid = si + (ei - si)/2 ;

    ll ans = mergesort(a, si, mid);
    ans += mergesort(a, mid + 1, ei);
    ans += merge(a, si, ei);

    return ans ;
}

void solve(){
    ll n ;
    cin>> n ;

    vector<ll> a(n);
    for(auto &it : a) cin>> it ;
    

    ll ans = mergesort(a, 0, n - 1);

    cout<< ans <<endl ;

    
}



int main(){
    int t ;
    cin>> t ;

    while(t--){
        solve() ;
    }
}