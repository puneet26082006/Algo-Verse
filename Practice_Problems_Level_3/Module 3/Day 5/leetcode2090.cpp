// #define pb push_back 
// class Solution {
// public:
//     vector<int> getAverages(vector<int>& a, int k) {
//         int n = a.size() ;
//         int max_k = 2 * k + 1 ;

//         vector<int> ans(n, -1) ;
//         if(max_k > n){
//             return ans ;
//         }

//         long long sum = 0 ;
//         for(int i = 0 ; i < max_k ; i++){
//             sum += a[i];
//         }


//         ans[k] = sum / max_k ;

//         for(int i = max_k ; i < n ; i++){
//             sum += a[i];
//             sum -= a[i - max_k];

//             ans[i - k] = sum / max_k ;
            
//         }

//         return ans ;
//     }
// };