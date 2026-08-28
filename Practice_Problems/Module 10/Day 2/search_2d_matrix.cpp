// // https://leetcode.com/problems/search-a-2d-matrix/description/


// const int num = 1e4 ;
// class Solution {
// public:
//     bool searchMatrix(vector<vector<int>>& matrix, int target) {
//         if (matrix.empty() || matrix[0].empty()) return false;
//         int n = matrix.size() ;
//         int m = matrix[0].size() ;

//         int si = 0 ;
//         int ei = (n * m) - 1 ; 

//         while(si <= ei){
//             int mid = si + (ei - si)/2 ;

//             int row = mid / m ;
//             int col = mid % m ;
//             if(matrix[row][col] == target){
//                 return true ;
//             } else if(matrix[row][col] < target){
//                 si = mid + 1 ;
//             } else {
//                 ei = mid - 1 ;
//             }
//         }

//         return false ;
//     }
// };