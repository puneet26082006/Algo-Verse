// class Solution {
//     bool helper(int mid, int m , int k, vector<int> day){
//         int bouquet = 0 ;
//         int curr = 0 ;

//         for(int i = 0 ; i < day.size() ; i++){
//             if(day[i] <= mid){
//                 curr++ ;
//                 if(curr == k){
//                     bouquet++ ;
//                     curr = 0 ;
//                 }
//             } else {
//                 curr = 0 ;
//             }
//         }

//         return (bouquet >= m) ; 


//     }
// public:
//     int minDays(vector<int>& bloomDay, int m, int k) {
//         int n = bloomDay.size() ;
//         int si =  *min_element(bloomDay.begin(), bloomDay.end());
//         int ei =  *max_element(bloomDay.begin(), bloomDay.end());
//         int ans = -1 ;

//         while(si <= ei){
//             int mid = si + (ei - si)/2 ;
//             if(helper(mid, m, k, bloomDay)){
//                 ans = mid ;
//                 ei = mid - 1 ;
//             } else {
//                 si = mid + 1 ;
//             }
//         }

//         return ans ;
//     }
// };