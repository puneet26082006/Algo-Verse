// https://leetcode.com/problems/count-good-numbers/


// class Solution {
// long long expo(long long a, long long b, long long mod){
//     long long ans = 1 ;
//     a %= mod ;

//     while(b > 0){
//         if(b & 1){
//             ans = (ans * a) % mod ;
//         }

//         a = (a * a) % mod ;
//         b >>= 1 ;
//     }

//     return ans ;
// }
// public:
//     int countGoodNumbers(long long n) {
//         long long res = 1 ;
//         long long mod = 1e9 + 7 ;
//         if(n % 2 == 0){
//             long long part1 = expo(5, (n/2), mod);
//             long long part2 = expo(4, (n/2), mod);

//             res = (res * part1 * part2) % mod ;
//         } else {
//             long long part1 = expo(5, ((n/2) + 1), mod);
//             long long part2 = expo(4, (n/2), mod);

//             res = (res * part1 * part2) % mod ;
//         }

//         return res ;
//     }
// };