#include <bits/stdc++.h>
// #include<ext/pb_ds/assoc_container.hpp>
// #include<ext/pb_ds/tree_policy.hpp> -->
using namespace std;
// using namespace __gnu_pbds;
typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
ll expo(ll a, ll b, ll mod) {ll res = 1; while (b > 0) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b = b >> 1;} return res;}
ll mminvprime(ll a, ll b) {return expo(a, b - 2, b);}
ll mod_mul(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
ll mod_sub(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
ll mod_div(ll a, ll b, ll m) {a = a % m; b = b % m; return (mod_mul(a, mminvprime(b, m), m) + m) % m;}  //only for prime m
#define fr(i,n) for (ll i=0;i<n;i++)
#define pb push_back
#define sz(x) (int)x.size()
#define ff first
#define ss second
#define all(v) v.begin(), v.end()
// typedef tree<long long, null_type, less_equal<long long>, rb_tree_tag, tree_order_statistics_node_update> pbds; // find_by_order, order_of_key
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x)
#endif
void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(lld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}

/*
**************************************************************************************************
**************************************************************************************************


                    ***        **************
                    ***        **************
                    ***  ***   ***   ***
                    ***  ***   ***   ***
                    ***        ***
                    *************************
                    *************************
                               ***        ***
                         ***   ***   ***  ***
                         ***   ***   ***  ***
                    **************        ***
                    **************        ***

**************************************************************************************************
**************************************************************************************************
*/
template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(unordered_map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
#pragma GCC optimize("unroll-loops,O3,Ofast") //even 10^8+ also works with this
#pragma GCC target("avx2,avx,fma,bmi,bmi2,lzcnt,popcnt")

int knightx[8] = { -1, -2, -2, -1, 1, 2, 2, 1};
int knighty[8] = { -2, -1, 1, 2, 2, 1, -1, -2};


// Given a string S of length N (1 <= N <= 105

// ) and Q (1 <= Q <= 105

// ) queries
// where each query contains 2 integers L and R (1 <= L <= R <= N), find out
// for each query if the substring from L to R is a palindrome.

// Example:

// abccbd, q1

// = [3, 4] => Yes, q2 = [1, 5] => No, q3

// = [2, 4] => Yes

const ll max_len = 10'00'005 ;

const ll m1 = 1'00'00'00'009 ;
const ll m2 = 1'00'00'00'007 ;

ll p1[max_len];
ll p2[max_len];

ll inv1[max_len];
ll inv2[max_len];

const ll base = 31 ;

vector<ll> h1 , h2 , h1_rev, h2_rev ;

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

void build(string& s, vector<ll>& h1 , vector<ll>& h2){
    ll n = s.size() ;

    h1.assign(n, 0);
    h2.assign(n, 0);

    for(ll i = 0 ; i < n ; i++){
        ll val = s[i] - 'a' + 1 ;
        h1[i] = (val * p1[i]) % m1 ;
        h2[i] = (val * p2[i]) % m2 ;
    }

    for(ll i = 1 ; i < n ; i++){
        h1[i] = (h1[i] + h1[i - 1]) % m1 ;
        h2[i] = (h2[i] + h2[i - 1]) % m2 ;
    }

}


ll get_hash(ll l, ll r, const vector<ll>& h1, const vector<ll>& h2){
    ll val1 = h1[r];
    ll val2 = h2[r];

    if(l > 0){
        val1 = (val1 - h1[l - 1] + m1) % m1 ;
        val2 = (val2 - h2[l - 1] + m2) % m2 ;
    }

    val1 = mod_mul(val1, inv1[l], m1);
    val2 = mod_mul(val2, inv2[l], m2);

    return (val1 << 32) | val2 ;
}



void solve() {
    string s ;
    cin>> s ;

    ll q ;
    cin>> q ;

    int n = s.size() ;


    string rev_s = s ;
    reverse(rev_s.begin(), rev_s.end());

    build(s, h1, h2);
    build(rev_s, h1_rev, h2_rev);

    while(q--){
        ll l, r ;
        cin>> l >> r ;

        l-- ;
        r-- ;

        ll hash_s = get_hash(l, r, h1, h2);
        ll hash_rev_s = get_hash(n - r - 1, n - l - 1, h1_rev , h2_rev) ;

        if(hash_s == hash_rev_s){
            cout<< "Yes" <<endl ;
        } else {
            cout<< "No" <<endl ;
        }

    }



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


