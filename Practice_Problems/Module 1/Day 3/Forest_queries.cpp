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





// CSES Problem Set
//                 Forest Queries
        
// Task
// Statistics

    
    




// Time limit: 1.00 s
// Memory limit: 512 MB

// You are given an n \times n grid representing the map of a forest. Each square is either empty or contains a tree. The upper-left square has coordinates (1,1), and the lower-right square has coordinates (n,n).
// Your task is to process q queries of the form: how many trees are inside a given rectangle in the forest?
// Input
// The first input line has two integers n and q: the size of the forest and the number of queries.
// Then, there are n lines describing the forest. Each line has n characters: . is an empty square and * is a tree.
// Finally, there are q lines describing the queries. Each line has four integers y_1, x_1, y_2, x_2 corresponding to the corners of a rectangle.
// Output
// Print the number of trees inside each rectangle.
// Constraints

// 1 \le n \le 1000
// 1 \le q \le 2 \cdot 10^5
// 1 \le y_1 \le y_2 \le n
// 1 \le x_1 \le x_2 \le n

// Example
// Input:
// 4 3
// .*..
// *.**
// **..
// ****
// 2 2 3 4
// 3 1 3 1
// 1 1 2 2

// Output:
// 3
// 1
// 2

















void solve() {
    int n , q ;
    cin>> n >> q ;

    vector<vector<int>> forest(n, vector<int>(n));
    for(int i = 0 ; i < n ; i++){
        string inp ;
        cin>> inp ;
        for(int j = 0 ; j < n ; j++){
            if(inp[j] == '*'){
                forest[i][j] = 1 ;
            } else {
                forest[i][j] = 0 ;
            }
        }
    }

    vector<vector<int>> pre(n, vector<int>(n));
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            pre[i][j] = forest[i][j];
            if(j > 0){
                pre[i][j] += pre[i][j - 1];
            }

            if(i > 0){
                pre[i][j] += pre[i - 1][j];
            }

            if(i > 0 && j > 0){
                pre[i][j] -= pre[i - 1][j - 1];
            }
            // pre[i][j] = pre[i][j - 1] + pre[i - 1][j] - pre[i - 1][j - 1] + forest[i][j];
        }
    }



    while(q--){
        int x1, y1 , x2, y2 ;
        cin>> y1 >> x1 >> y2 >> x2 ;

        y1-- ;
        x1-- ;
        y2-- ;
        x2-- ;

        int ans = pre[y2][x2];

        if(y1 > 0){
            ans -= pre[y1 - 1][x2];
        }

        if(x1 > 0){
            ans -= pre[y2][x1 - 1];
        }

        if(y1 > 0 && x1 > 0){
            ans += pre[y1 - 1][x1 - 1];
        }

        // int ans = pre[x2][y2]- pre[x1][y1 - 1] - pre[x1 - 1][y2] + pre[x1 - 1][y1 - 1]  ;

        cout<< ans <<endl ;


    }





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


