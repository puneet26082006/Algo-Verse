// // https://leetcode.com/problems/combination-sum/description/

// class Solution {
// public:
//     vector<vector<int>> ans;
//     vector<int> curr;

//     void helper(vector<int>& candidates, int target, vector<int>& curr, int n, int idx, int sum) {
//         if (sum == target) {
//             ans.push_back(curr);
//             return;
//         }

//         if ((sum > target || idx >= n)) {
//             return;
//         }

//         curr.push_back(candidates[idx]);
//         helper(candidates, target, curr, n, idx, sum + candidates[idx]);
//         curr.pop_back();
//         helper(candidates, target, curr, n, idx + 1, sum);
//     }

//     vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
//         int n = candidates.size();

//         helper(candidates, target, curr, n, 0, 0);


//         return ans;
//     }
// };