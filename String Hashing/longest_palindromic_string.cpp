#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;

ll expo(ll a, ll b, ll mod) {ll res = 1; while (b > 0) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b = b >> 1;} return res;}
ll mminvprime(ll a, ll b) {return expo(a, b - 2, b);}

// FAST ARITHMETIC EDITS: Replaced slow multi-modulo functions
inline ll mod_sub(ll a, ll b, ll m) { ll res = a - b; return res < 0 ? res + m : res; }
inline ll mod_mul(ll a, ll b, ll m) { return (a * b) % m; }

#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

ll const m1 = 1000000009 ;
ll const m2 = 1000000007 ;

ll const max_len = 1000006 ;

const ll base = 31 ;

ll p1[max_len];
ll p2[max_len];


ll inv1[max_len];
ll inv2[max_len];

vector<ll> h1 , h2 ;
vector<ll> rev_h1 , rev_h2 ;

void precompute() {
    p1[0] = 1 , p2[0] = 1 ;
    inv1[0] = 1 , inv2[0] = 1 ;

    ll inv_base1 = expo(base, m1 - 2, m1);
    ll inv_base2 = expo(base, m2 - 2, m2);

    for(ll i = 1 ; i < max_len ; i++){
        p1[i] = (p1[i - 1] * base) % m1 ;
        p2[i] = (p2[i - 1] * base) % m2 ;

        inv1[i] = (inv1[i - 1] * inv_base1) % m1 ;
        inv2[i] = (inv2[i - 1] * inv_base2) % m2 ;
    }
}

void build(string & s){
    ll n = s.size() ;

    h1.assign(n, 0);
    h2.assign(n, 0);
    rev_h1.assign(n, 0);
    rev_h2.assign(n, 0);

    for(int i = 0 ; i < n ; i++){
        ll val = s[i] - 'a' + 1 ;
        ll rev_val = s[n - i - 1] - 'a' + 1 ;

        h1[i] = (val * p1[i]) % m1 ;
        h2[i] = (val * p2[i]) % m2 ;

        rev_h1[i] = (rev_val * p1[i]) % m1 ; 
        rev_h2[i] = (rev_val * p2[i]) % m2 ; 

    }

    for(int i = 1 ; i < n ; i++){
        h1[i] = (h1[i] + h1[i - 1]) % m1 ;
        h2[i] = (h2[i] + h2[i - 1]) % m2 ;

        rev_h1[i] = (rev_h1[i] + rev_h1[i - 1]) % m1 ;
        rev_h2[i] = (rev_h2[i] + rev_h2[i - 1]) % m2 ;
    }
}

pair<ll, ll> get_hash(ll l, ll r, const vector<ll>& h1, const vector<ll>& h2){
    ll val1 = h1[r];
    ll val2 = h2[r];

    if(l > 0){
        val1 = mod_sub(val1, h1[l - 1], m1);
        val2 = mod_sub(val2, h2[l - 1], m2);
    }

    val1 = mod_mul(val1, inv1[l], m1) % m1 ;
    val2 = mod_mul(val2, inv2[l], m2) % m2 ;

    return {val1, val2} ;
}

pair<ll, ll> get_rev_h(ll l, ll r, ll n){
    return get_hash(n - r - 1, n - l - 1, rev_h1, rev_h2);
}


ll helper(ll k, string & s , ll n){
    
    for(ll i = 0 ; i <= n - k ; i++){
        if(get_hash(i, i + k - 1, h1, h2) == get_rev_h(i, i + k - 1, n)){
            return i ;
        }
    }

    return -1 ;
}

void solve() {
    string s ;
    cin>> s ;
    ll n = s.size() ;

    build(s);

    ll si = 0 ;
    ll ei = (n - 1)/ 2 ;

    ll ans1 = 0 ;
    ll best_idx = 0 ;

    while(si <= ei){
        ll mid = (si + ei)/ 2 ;
        ll len = 2 * mid + 1 ;
        ll idx = helper(len, s, n);
        if(idx != -1){
            if(len > ans1){
                ans1 = len ;
                best_idx = idx ;
            }
            si = mid + 1 ;
        } else {
            ei = mid - 1 ; 
        }
    }

    si = 1 ;
    ei = n / 2 ;

    while(si <= ei){
        ll mid = (si + ei)/ 2 ;
        ll len = 2 * mid ;

        ll idx = helper(len, s, n);
        if(idx != -1){
            if(len > ans1){
                ans1 = len ;
                best_idx = idx ;
            }
            si = mid + 1 ;
        } else {
            ei = mid - 1 ; 
        }
    }

    
    cout<< s.substr(best_idx, ans1) <<endl ;



}






int main() {
#ifndef ONLINE_JUDGE
    freopen("Error.txt", "w", stderr);
#endif
    fastio();

    precompute() ;

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
}


