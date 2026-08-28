// https://leetcode.com/problems/combination-sum-ii/


// class Solution {
// public:
//     vector<vector<int>> ans ;
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
//         helper(candidates, target, curr, n, idx + 1, sum + candidates[idx]);
//         curr.pop_back();

//         while(idx + 1 < n && candidates[idx] == candidates[idx + 1]){
//             idx++ ;
//         }

//         helper(candidates, target, curr, n, idx + 1, sum);
//     }

//     vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
//         int n = candidates.size();

//         ans.clear();
//         curr.clear();

//         sort(candidates.begin(), candidates.end());

//         helper(candidates, target, curr, n, 0, 0);

//         return ans;
//     }
    
// };