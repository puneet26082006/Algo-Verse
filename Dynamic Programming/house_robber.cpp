// const int N = 1e5 ;
// int dp[N] ;
// class Solution {
//     int f(int idx, vector<int>& a, int n){
//         if(idx == n - 1){
//             return max(0, a[n - 1]);
//         }

//         if(idx == n - 2){
//             return max({0, a[n - 2], a[n - 1]});
//         }

//         if(dp[idx] != -1){
//             return dp[idx] ;
//         }

//         dp[idx] = max(a[idx] + f(idx + 2, a, n), f(idx + 1, a, n));

//         return dp[idx] ;
//     }
// public:
//     int rob(vector<int>& nums) {
//         int n = nums.size() ;
//         for(int i = 0 ; i < N ; i++){
//             dp[i] = -1 ;
//         }
//         return f(0, nums, n);
//     }
// };