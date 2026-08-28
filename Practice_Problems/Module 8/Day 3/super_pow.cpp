// // https://leetcode.com/problems/super-pow/description/

// class Solution {
//     long long expo(long long ai, long long bi){
//         long long res = 1 ;
//         ai %= 1337 ;
//         while(bi > 0){
//             if(bi & 1){
//                 res = (res * ai) % 1337 ; 
//             }

//             ai = (ai * ai) % 1337 ;
//             bi >>= 1 ;
//         }

//         return res ;

//     }
// public:
//     int superPow(int a, vector<int>& b) {
//         int n = b.size() ;

//         long long res = 1 ;

//         for(long long i = 0 ; i < n ; i++){
//             long long part1 = expo(res, 10);
//             long long part2 = expo(a, b[i]);

//             res = (part1 * part2) % 1337 ;
//         }

//         return res ;


//     }
// };