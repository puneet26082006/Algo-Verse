// #define ll long long 
// class Solution {
// public:
//     vector<double> medianSlidingWindow(vector<int>& nums, int k) {
//         ll n = nums.size() ;

//         multiset<ll> left ;
//         multiset<ll> right ;

//         auto balance = [&]() {
//             if(left.size() > right.size() + 1){
//                 right.insert(*left.rbegin());
//                 left.erase(left.find(*left.rbegin()));
//             }

//             if(right.size() > left.size()){
//                 left.insert(*right.begin());
//                 right.erase(right.find(*right.begin()));
//             }
//         };


//         vector<double> answer ;

//         for(ll i = 0 ; i < n ; i++){
//             if(left.empty() || nums[i] <= *left.rbegin()){
//                 left.insert(nums[i]);
//             } else {
//                 right.insert(nums[i]);
//             }

//             balance() ;
//             if(i >= k){
//                 int out = nums[i - k];
//                 if(out <= *left.rbegin()){
//                     left.erase(left.find(out));
//                 } else {
//                     right.erase(right.find(out));
//                 }
//                 balance() ;

//             }
            
//             if(i >= k - 1){
//                 if(k % 2 == 1){
//                     answer.push_back((double)*left.rbegin());
//                 } else {
//                     answer.push_back(((double)*left.rbegin() + (double)*right.begin())/2.0);
//                 }
//             }
            
//         }

//         return answer ;

//     }
// };