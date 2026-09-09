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


// Problem 1

// Given a list of N strings (a1, a2, .... aN) and Q queries. In each query you will
// be given a string X, you need to find whether there exist less than equal to 2
// strings in the database such that the concatenation of them results in X.

struct Node {
    vector<int> children ;
    int ending_here ;
    int ending_below ;

    Node(){
        children.resize(26, -1) ;
        ending_here = 0 ;
        ending_below = 0 ;

    }
};


struct Trie {
    vector<Node> tree ;
    int size = 0 ;

    Trie() {
        tree.push_back(Node());
        size++ ;
    }

    void add(string & word) {
        int curr = 0 ;
        for(auto &ch : word){
            int idx = ch - 'a' ;
            if(tree[curr].children[ch - 'a'] == -1){
                tree[curr].children[idx] = size ;
                tree.push_back(Node()) ;
            }

            curr = tree[curr].children[idx] ;
            tree[curr].ending_below++ ;
        }

        tree[curr].ending_here++ ;
    }

    bool search(string& word){
        int curr = 0 ;

        for(auto &ch : word){
            int idx = ch - 'a' ;
            if(tree[curr].children[idx] == -1){
                return false ;
            }
            curr = tree[curr].children[idx] ;
        }

        return tree[curr].ending_here > 0 ;

    }


};


void solve() {
    int n, q ;
    cin>> n >> q ;

    vector<string> words;
    vector<string> rev_words ;
    for(int i = 0 ; i < n ; i++){
        string s ;
        cin>> s ;

        words.pb(s) ;
        reverse(s.begin(), s.end());
        rev_words.pb(s);
    }

    Trie trie ;
    Trie rev_trie ;

    for(int i = 0 ; i < n ; i++){
        trie.add(words[i]) ;
        rev_trie.add(rev_words[i]);
    }

    while(q--){
        string x ;
        cin>> x ;

        int m = x.size() ;

        bool possible = false ;
        if(trie.search(x)){
            possible = true ;
        } else {
            vector<bool> pref(m, false);
            vector<bool> suff(m, false);
            
            int curr = 0 ;

            for(int i = 0 ; i < m ; i++){
                int idx = x[i] - 'a' ;
                if(trie.tree[curr].children[idx] == -1){
                    break ;
                }

                curr = trie.tree[curr].children[idx] ;
                if(trie.tree[curr].ending_here > 0){
                    pref[i] = true ;
                }
            }

            curr = 0 ; 
            reverse(x.begin(), x.end()) ;

            for(int i = 0 ; i < m ; i++){
                int idx = x[i] - 'a' ;
                
                if(rev_trie.tree[curr].children[idx] == -1){
                    break ;
                }

                curr = rev_trie.tree[curr].children[idx] ;
                if(rev_trie.tree[curr].ending_here > 0){
                    suff[m - i - 1] = true ;
                }
            }

            for(int i = 0 ; i < m - 1 ; i++){
                if(pref[i] && suff[i + 1]){
                    possible = true ;
                    break ;
                }
            }
        }

        if(possible) cout<< "YES" <<endl ;
        else cout<< "NO" <<endl ;
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


