// https://leetcode.com/problems/subsets-ii/


// class Solution {
// public:
//     set<vector<int>>st ;
//     void solve(vector<int>& nums, int idx, vector<int>&temp){
//         if(idx >= nums.size()){
//             st.insert(temp);
//             return ;
//         }

//         temp.push_back(nums[idx]);
//         solve(nums, idx + 1, temp);
//         temp.pop_back();

//         solve(nums, idx + 1, temp);

//     }
//     vector<vector<int>> subsetsWithDup(vector<int>& nums) {
//         st.clear();
//         sort(nums.begin(), nums.end());
//         vector<int > temp ;
//         solve(nums, 0, temp);

//         vector<vector<int>>results ;
//         for(auto &it : st) results.push_back(it);

//         return results ;
//     }
// };