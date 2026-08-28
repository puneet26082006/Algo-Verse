// #define ll long long 
// class Solution {
// public:
//     int nthMagicalNumber(int n, int a, int b) {
//         ll mod = 1e9 + 7 ;
//         ll si = 1 ;
//         ll ei = 1e18;

//         ll ans = -1 ;

//         auto helper = [&](ll mid) -> bool {

//             ll cnt_a = mid /a ;
//             ll cnt_b = mid / b ;

//             ll lcm = (a * b)/ __gcd(a,b);
//             ll cnt_c = mid / lcm ;

//             ll cnt = cnt_a + cnt_b - cnt_c ;

//             if(cnt >= n){
//                 return true ;
//             }

//             return false ;
//         };


//         while(si <= ei){
//             ll mid = si + (ei - si)/2 ;
//             if(helper(mid)){
//                 ans = mid ;
//                 ei = mid - 1 ;
//             } else {
//                 si = mid + 1 ;
//             }
//         }

//         ans %= mod ;

//         return ans ;
//     }
// };