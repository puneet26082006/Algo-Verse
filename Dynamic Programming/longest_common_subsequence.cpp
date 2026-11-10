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





void solve() {
    string a , b ;
    cin>> a >> b ;

    int n = a.size();
    int m = b.size();

    vector<vector<pair<int, int>>> dp(n + 1, vector<pair<int, int>>(m + 1)) ;
    
    // dp[i][j] = length of LCS in a[i, n - 1] and b[j, m - 1]
    dp[n][0] = {0, -1} ; // length LCS in a[n , n - 1] and b[0, m - 1] 
    dp[0][m] = {0, -1} ; // length LCS in a[0, n - 1] and b[m, m - 1] 

    for(int i = 0 ; i <= n ; i++){
        dp[i][m] = {0, -1} ;
    }

    for(int j = 0 ; j <= m ; j++){
        dp[n][j] = {0, -1} ;
    }
    // transition 
    
    // dp[i][j] = dp[i + 1][j] // skip the i-th in a  --> take a 
    // dp[i][j] = dp[i][j + 1] // skip the j-th in b  --> take b

    // dp[i][j] = max(take a, take b)

    // if(a[i] == b[i]) --> dp[i][j] = 1 + dp[i + 1][j + 1] 

    // (i + 1)(j) --> 0 --> down  
    // (i){j + 1} --> 1 --> right 
    // (i + 1)(j + 1) --> 2  --> diagonal  

    for(int i = n - 1 ; i >= 0 ; i--){
        for(int j = m - 1 ; j >= 0 ; j--){
            if(a[i] == b[j]){
                dp[i][j] = {1 + dp[i + 1][j + 1].first, 2} ;
                continue ;
            }

            dp[i][j].first = max(dp[i + 1][j].first, dp[i][j + 1].first) ;
            if(dp[i + 1][j].first > dp[i][j + 1].first){
                dp[i][j].second = 0 ;
            } else {
                dp[i][j].second = 1 ;
            }
        }
    }

    string ans = "" ;

    int i = 0 , j = 0 ;

    while(i < n && j < m){
        if(dp[i][j].second == 2){
            ans += a[i] ;
            i++ ;
            j++ ;
        } else if(dp[i][j].second == 1){
            j++ ;
        } else {
            i++ ;
        }
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


