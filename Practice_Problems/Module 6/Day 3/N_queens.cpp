// https://leetcode.com/problems/n-queens/description/


// class Solution {
// public:
//     bool check(int row, int col, vector<string>& curr, int n){
//         for(int i = row ; i >= 0 ; i--){
//             if(curr[i][col] == 'Q'){
//                 return false ;
//             }
//         }

//         for(int i = row, j = col ; i >= 0 && j >= 0 ; i--, j--){
//             if(curr[i][j] == 'Q'){
//                 return false ;
//             }
//         }

//         for(int i = row, j = col ; i >= 0 && j < n ; i--, j++){
//             if(curr[i][j] == 'Q'){
//                 return false ;
//             }
//         }

        
//         return true ;
//     }

//     void helper(vector<vector<string>>& ans, vector<string>& curr, int n, int row){
//         if(row == n){
//             ans.push_back(curr);
//             return ;
//         }

//         for(int i = 0 ; i < n ; i++){
//             if(check(row, i, curr, n) == false) continue ;
//             curr[row][i] = 'Q';
//             helper(ans, curr, n, row + 1);
//             curr[row][i] = '.';
//         }
//     }
//     vector<vector<string>> solveNQueens(int n) {
//         vector<vector<string>> ans ;
//         string temp(n,'.');
//         vector<string> curr(n,temp);

//         helper(ans, curr, n, 0);

//         return ans ;
//     }
// };