// https://leetcode.com/problems/subsets/description/

// class Solution {
// public:
//     vector<vector<int >> results ;
//     void helper(vector<int>nums, int n, int idx, vector<int>& subsets){
//         if(idx >= n){
//             results.push_back(subsets);
//             return ;
//         }

//         subsets.push_back(nums[idx]);
//         helper(nums, n, idx + 1, subsets);

//         subsets.pop_back();
//         helper(nums, n, idx + 1, subsets);
//     }

//     vector<vector<int>> subsets(vector<int>& nums) {
//         vector<int> subsets ;
//         int n = nums.size();
//         helper(nums, n, 0, subsets);

//         return results ;
//     }
// };