// #define ll long long 
// ll expo(ll a, ll b , ll mod){
//     ll res = 1 ;

//     while(b > 0){
//         if(b & 1){
//             res = (res * a) % mod ;
//         }
//         a = (a * a) % mod ;
//         b >>= 1 ;
//     }

//     return res ;
// }

// const ll m1 = 1000000009 ;
// const ll m2 = 1000000007 ;

// const ll max_len = 1000005 ;
// const ll base = 131 ;

// ll p1[max_len];
// ll p2[max_len];

// ll inv1[max_len];
// ll inv2[max_len];

// vector<ll> h1 , h2 ;

// bool precomputed = false ;

// void precompute(){
//     if(precomputed) return ;

//     p1[0] = 1 ; p2[0] = 1 ;
//     inv1[0] = 1; inv2[0] = 1 ;

//     ll inv_base1 = expo(base, m1 - 2, m1);
//     ll inv_base2 = expo(base, m2 - 2, m2);

//     for(ll i = 1 ; i < max_len ; i++){
//         p1[i] = (p1[i - 1] * base) % m1 ;
//         p2[i] = (p2[i - 1] * base) % m2 ;

//         inv1[i] = (inv1[i - 1] * inv_base1) % m1 ;
//         inv2[i] = (inv2[i - 1] * inv_base2) % m2 ;
//     }

//     precomputed = true ;
// }

// void build(string & s){
//     ll n = s.size() ;
//     h1.assign(n, 0);
//     h2.assign(n, 0);

//     for(ll i = 0 ; i < n ; i++){
//         ll val = s[i] - 'a' + 1 ;
//         h1[i] = (val * p1[i]) % m1 ; 
//         h2[i] = (val * p2[i]) % m2 ; 
//     }

//     for(ll i = 1 ; i < n ; i++){
//         h1[i] = (h1[i] + h1[i - 1]) % m1 ;
//         h2[i] = (h2[i] + h2[i - 1]) % m2 ;
//     }
// }

// pair<ll, ll> get_hash(ll l, ll r){
//     ll val1 = h1[r] ;
//     ll val2 = h2[r] ;

//     if(l > 0){
//         val1 = ((val1 - h1[l - 1]) + m1) % m1 ;
//         val2 = ((val2 - h2[l - 1]) + m2) % m2 ;
//     }

//     val1 = (val1 * inv1[l]) % m1 ; 
//     val2 = (val2 * inv2[l]) % m2 ;

//     return {val1, val2} ; 
// }

// class Solution {
// public:
//     string longestPrefix(string s) {
//         precompute() ;
//         ll n = s.size() ;
//         build(s) ;
//         ll mx = 0 ;
//         for(ll i = 1 ; i < n ; i++){
//             if(get_hash(0, i - 1) == get_hash(n - i, n - 1)){
//                 mx = i ;
//             }
//         }

//         return s.substr(0, mx) ;
        
//     }
// };