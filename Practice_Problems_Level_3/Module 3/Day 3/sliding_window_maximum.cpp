// class Solution {
// public:
//     vector<int> maxSlidingWindow(vector<int>& nums, int k) {
//         int n = nums.size() ;
//         multiset<int> st ;
//         vector<int > ans ;
//         for(int i = 0 ; i < k ; i++){
//             st.insert(nums[i]);
//         }

//         ans.push_back(*st.rbegin());

//         for(int i = k ; i < n ; i++){
//             st.insert(nums[i]);
//             st.erase(st.find(nums[i - k]));

//             ans.push_back(*st.rbegin());
//         }

//         return ans ;
//     }
// };