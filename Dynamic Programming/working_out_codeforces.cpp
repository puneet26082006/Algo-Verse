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
    int n, m ;
    cin>> n >> m ;

    vector<vector<int>> a(n + 1, vector<int>(m + 1));
    for(int i = 1 ; i <= n ; i++){
        for(int j = 1 ; j <= m ; j++){
            cin>> a[i][j] ;
        }
    }


    vector<vector<int>> dp1(n + 2, vector<int>(m + 2));
    vector<vector<int>> dp2(n + 2, vector<int>(m + 2));
    vector<vector<int>> dp3(n + 2, vector<int>(m + 2));
    vector<vector<int>> dp4(n + 2, vector<int>(m + 2));

    
    for(int i = 1 ; i <= n  ; i++){  // top left -> dp1[i][j] -> max sum path from (0, 0) -> (i, j) 
        for(int j = 1 ; j <= m ; j++){
            dp1[i][j] = a[i][j] + max(dp1[i - 1][j], dp1[i][j - 1]);
        }
    }

    for(int i = 1 ; i <= n ; i++){ // top right -> dp2[i][j] -> max sum path from (0, m) -> (i, j)
        for(int j = m ; j >= 1 ; j--){
            dp2[i][j] = a[i][j] + max(dp2[i - 1][j], dp2[i][j + 1]);
        }
    }

    for(int i = n ; i >= 1 ; i--){ // bottom left -> dp3[i][j] -> max sum path from (n, 0) -> (i, j) 
        for(int j = 1 ; j <= m ; j++){
            dp3[i][j] = a[i][j] + max(dp3[i + 1][j], dp3[i][j - 1]) ;
        }
    }

    for(int i = n ; i >= 1 ; i--){ // bottom right -> dp4[i][j] -> max sum path from (n - 1, m - 1) -> (i, j)
        for(int j = m ; j >= 1 ; j--){
            dp4[i][j] = a[i][j] + max(dp4[i + 1][j], dp4[i][j + 1]) ;
        }
    }

    int ans = 0 ;

    for(int i = 2 ; i < n ; i++){
        for(int j = 2 ; j < m ; j++){
            int ans1 = dp1[i - 1][j] + dp4[i + 1][j] + dp3[i][j - 1] + dp2[i][j + 1] ;
            int ans2 = dp1[i][j - 1] + dp4[i][j + 1] + dp3[i + 1][j] + dp2[i - 1][j] ;

            ans = max(ans, max(ans1, ans2));
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


