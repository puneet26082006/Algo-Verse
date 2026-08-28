#include <bits/stdc++.h>
// #include<ext/pb_ds/assoc_container.hpp>
// #include<ext/pb_ds/tree_policy.hpp>
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





// D - Snuke Prime  / 
// Time Limit: 2 sec / Memory Limit: 1024 MiB

// Score : 
// 400 points

// Problem Statement
// Snuke Inc. offers various kinds of services.
// A payment plan called Snuke Prime is available.
// In this plan, by paying 
// C yen (the currency of Japan) per day, you can use all services offered by the company without additional fees.
// You can start your subscription to this plan at the beginning of any day and cancel your subscription at the end of any day.

// Takahashi is going to use 
// N of the services offered by the company.
// He will use the 
// i-th of those services from the beginning of the 
// a 
// i
// ​
//  -th day until the end of the 
// b 
// i
// ​
//  -th day, where today is the first day.
// Without a subscription to Snuke Prime, he has to pay 
// c 
// i
// ​
//   yen per day to use the 
// i-th service.

// Find the minimum total amount of money Takahashi has to pay to use the services.

// Constraints
// 1≤N≤2×10 
// 5
 
// 1≤C≤10 
// 9
 
// 1≤a 
// i
// ​
//  ≤b 
// i
// ​
//  ≤10 
// 6
 
// 1≤c 
// i
// ​
//  ≤10 
// 9
 
// All values in input are integers.











//   for a[i] and b[i]  <= 1e6 using difference arrays .






void solve() {
    ll n , c ; 
    cin>> n >> c ;

    vector<ll > start(n), end(n), cost(n);
    for(ll i = 0 ; i < n ; i++){
        cin>> start[i] >> end[i] >> cost[i];
    }

    set<ll > st ;
    for(ll i = 0 ; i < n ; i++){
        st.insert(start[i]);
        st.insert(end[i] + 1);
    }

    ll idx = 0 ;
    map<ll, ll> mp ;
    for(auto it : st){
        mp[it] = idx ;
        idx++ ;
    }

    vector<ll > diff(idx + 1, 0);
    for(ll i = 0 ; i < n ; i++){
        diff[mp[start[i]]] += cost[i];
        diff[mp[end[i] + 1]] -= cost[i];
    }


    for(ll i = 1 ; i <= idx ; i++){
        diff[i] += diff[i - 1];
    }

    ll ans = 0 ;

    vector<int>a(st.begin(), st.end());

    for(ll i = 1 ; i < a.size() ; i++){
        ll span = a[i] - a[i - 1];
        ans += min(diff[i - 1], c) * span ;
    }

    cout<< ans <<endl ;


    

    

}



































int main() {
#ifndef ONLINE_JUDGE
    freopen("Error.txt", "w", stderr);
#endif
    fastio();

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
}


