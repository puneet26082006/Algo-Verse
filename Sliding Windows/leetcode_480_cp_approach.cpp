// #include <vector>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>

// using namespace std;
// using namespace __gnu_pbds;

// #define ordered_set tree<pair<long long, long long>, null_type, less<pair<long long, long long>>, rb_tree_tag, tree_order_statistics_node_update>
// #define ll long long
// class Solution {
// public:
//     vector<double> medianSlidingWindow(vector<int>& nums, int k) {
//         ll n = nums.size();

//         ordered_set < pair<ll, ll> st;

//         vector<double> ans;
//         ll size = k / 2;

//         for (ll i = 0; i < k; i++) {
//             st.insert({nums[i], i});
//         }

//         if (k % 2 == 1) {
//             auto it = st.find_by_order(size);
//             ans.push_back((double)it->first);
//         } else {
//             auto it1 = st.find_by_order(size);
//             auto it2 = st.find_by_order(size - 1);
//             ans.push_back(((double)it1->first + (double)it2->first) / 2.0);
//         }

//         for (ll i = k; i < n; i++) {
//             st.insert({nums[i], i});
//             st.erase({nums[i - k], i - k});

//             if (k % 2 == 1) {
//                 auto it = st.find_by_order(size);
//                 ans.push_back((double)it->first);
//             } else {
//                 auto it1 = st.find_by_order(size);
//                 auto it2 = st.find_by_order(size - 1);
//                 ans.push_back(((double)it1->first + (double)it2->first) / 2.0);
//             }
//         }

//         return ans;
//     }
// };