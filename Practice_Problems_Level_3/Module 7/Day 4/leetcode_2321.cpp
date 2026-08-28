// class Solution {
// public:
//     int maximumsSplicedArray(vector<int>& nums1, vector<int>& nums2) {
//         int n = nums1.size();

//         int sum1 = accumulate(nums1.begin(), nums1.end(), 0);
//         int sum2 = accumulate(nums2.begin(), nums2.end(), 0);

//         int ans1 = 0;
//         int max_ans1 = 0;
//         for (int i = 0; i < n; i++) {

//             ans1 += nums2[i] - nums1[i];
//             if (ans1 < 0) {
//                 ans1 = 0;
//             }

//             max_ans1 = max(ans1, max_ans1);
//         }

//         int ans2 = 0;
//         int max_ans2 = 0;
//         for (int i = 0; i < n; i++) {

//             ans2 += nums1[i] - nums2[i];
//             if (ans2 < 0) {
//                 ans2 = 0;
//             }
//             max_ans2 = max(ans2, max_ans2);
//         }

//         int ans = max(sum1 + max_ans1, sum2 + max_ans2);

//         return ans;
//     }
// };