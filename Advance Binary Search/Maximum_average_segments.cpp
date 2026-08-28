// https://codeforces.com/edu/course/2/lesson/6/4/practice/contest/285069/problem/A

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



lld maximum_sum(vector<lld>& a, int d){

    vector<lld> prefix(a.size());
    prefix[0] = a[0];
    for(lld i = 1 ; i < a.size() ; i++){
        prefix[i] = prefix[i - 1] + a[i];
    }

    lld minsofar = 0 ;
    lld ans = -1e18 ;

    for(lld i = d - 1 ; i < a.size() ; i++){
        lld bestarray = prefix[i] - minsofar ;
        minsofar = min(minsofar, prefix[i - d + 1]);
        ans = max(ans, bestarray);
    }

    return ans ;
}

bool helper(lld mid, vector<lld>& a , int d ){
    vector<lld> transformed(a.size());

    for(lld i = 0 ; i < a.size() ; i++){
        transformed[i] = a[i] - mid ;
    }

    return maximum_sum(transformed, d) >= 0;
}


pair<int, int> anysubarray(lld x, vector<lld>& a, int d, int n){

    vector<lld> prefix(n);
    prefix[0] = a[0];
    for(lld i = 1 ; i < n ; i++){
        prefix[i] = prefix[i - 1] + a[i];
    }

    lld minsofar = 0 ;
    lld ans = -1e18 ;
    int best_last_idx = -1 ;

    for(int i = d - 1 ; i < a.size() ; i++){
        lld bestarray = prefix[i] - minsofar ;
        ans = max(ans, bestarray) ;
        if(ans >= 0){
            return {best_last_idx + 2, i + 1};
        }

        if(minsofar > prefix[i - d + 1]){
            minsofar = prefix[i - d + 1];
            best_last_idx = i - d + 1 ;

        }
    }

    return {-10 , 10}; // this will never happen 

    
}

pair<int, int> bestsubarray(lld mid, vector<lld>& a , int d, int n ){
    vector<lld> transformed(a.size());

    for(int i = 0 ; i < a.size() ; i++){
        transformed[i] = a[i] - mid ;
    }

    return anysubarray(mid, transformed, d, n);
}


void solve() {
    lld n, d ;
    cin>> n >> d ;

    vector<lld> a(n);
    for(auto &it : a) cin>> it ;

    lld si = 0 ;
    lld ei = 100 ;

    int iterations = 100 ;

    for(int i = 0 ; i < iterations ; i++){
        lld mid = (si + ei)/2 ;

        if(helper(mid, a, d)){
            si = mid ;
        } else {
            ei = mid ;
        }
    }

    cout<< setprecision(10)<<fixed ;

    pair<int, int> ans = bestsubarray(si, a, d, n);

    cout<< ans.ff <<" "<<ans.ss <<endl ;

    // cout<< si <<endl ;
    





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


