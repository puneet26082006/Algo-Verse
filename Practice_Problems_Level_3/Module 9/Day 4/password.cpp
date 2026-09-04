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


const ll m1 = 1000000009 ;
const ll m2 = 1000000007 ;

const ll max_len = 1000006 ;
const ll base = 131 ;

ll p1[max_len];
ll p2[max_len];

ll inv1[max_len];
ll inv2[max_len];

vector<ll> h1 , h2 ;

void precompute() {
    p1[0] = 1 ; p2[0] = 1 ;
    inv1[0] = 1 ; inv2[0] = 1 ;

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

pair<ll, ll> get_hash(ll l, ll r){
    ll val1 = h1[r];
    ll val2 = h2[r] ;

    if(l > 0){
        val1 = mod_sub(val1, h1[l - 1], m1);
        val2 = mod_sub(val2, h2[l - 1], m2);
    }

    val1 = mod_mul(val1, inv1[l], m1);
    val2 = mod_mul(val2, inv2[l], m2);

    return {val1, val2};
}


bool helper(ll k , string & s , ll n){
    pair<ll, ll> hash = get_hash(0, k - 1);

    for(ll i = 1 ; i <= n - k - 1 ; i++){
        if(get_hash(i , i + k - 1) == hash){
            return true ;
        }
    }

    return false ;

}



void solve() {
    string s ;
    cin>> s ;

    build(s);

    ll n = s.size() ;

    vector<ll> idx ;
    for(ll i = 0 ; i < n ; i++){
        if(get_hash(0, i - 1) == get_hash(n - i, n - 1)){
            idx.pb(i);
        }
    }

    if(idx.empty()){
        cout<< "Just a legend" <<endl ;
        return ;
    }

    ll si = 0 ;
    ll ei = idx.size() - 1 ;

    ll best_idx = -1 ;

    while(si <= ei){
        ll mid = (si + ei) /2 ;

        if(helper(idx[mid], s , n)){
            best_idx = idx[mid];
            si = mid + 1 ;
        } else {
            ei = mid - 1 ;
        }
    }

    if(best_idx == -1){
        cout<< "Just a legend" <<endl ;
        return ;

    } 

    cout<< s.substr(0, best_idx) <<endl ;

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


