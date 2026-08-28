// https://leetcode.com/problems/merge-sorted-array/description/


// class Solution {
// public:
//     void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
//         int i = 0 ; 
//         int j = 0 ;

//         vector<int> merge ;

//         while(i < m && j < n){
//             if(nums1[i] > nums2[j]){
//                 merge.push_back(nums2[j]);
//                 j++ ;
//             } else {
//                 merge.push_back(nums1[i]);
//                 i++ ;
//             }
//         }

//         while(i < m){
//             merge.push_back(nums1[i]);
//             i++ ;
//         }

//         while(j < n){
//             merge.push_back(nums2[j]);
//             j++ ;
//         }

//         for(int i = 0 ; i < merge.size() ; i++){
//             nums1[i] = merge[i];
//         }


//     }
// };