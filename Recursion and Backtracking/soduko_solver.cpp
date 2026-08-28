// // https://leetcode.com/problems/sudoku-solver/description/


// class Solution {
// public:

//     bool check(vector<vector<char>>& board, int row, int col, char ch){
//         for(int i = 0 ; i < 9 ; i++){
//             if(board[i][col] == ch) return false ;
//         }

//         for(int i = 0 ; i < 9 ; i++){
//             if(board[row][i] == ch) return false ;
//         }

//         int r = row - (row % 3);
//         int c = col - (col % 3);

//         for(int i = r ; i < r + 3 ; i++){
//             for(int j = c ; j < c + 3 ; j++){
//                 if(board[i][j] == ch){
//                     return false ;
//                 }
//             }
//         } 

//         return true ;
//     }
    
//     bool helper(vector<vector<char>>& board, int row, int col){
//         if(row == 9){
//             return true ;
//         }

//         if(col == 9){
//             return helper(board, row + 1, 0);
//         }

//         if(board[row][col] != '.'){
//             return helper(board, row, col + 1);
//         }

//         for(char ch = '1' ; ch <= '9' ; ch++){
//             if(check(board, row, col, ch) == false){
//                 continue ;
//             }

//             board[row][col] = ch ;

//             bool ans = helper(board, row, col + 1);

//             if(ans == true){
//                 return true ;
//             }
//         }

//         board[row][col] = '.';
//         return false ;
//     }

//     void solveSudoku(vector<vector<char>>& board) {
//         bool ans = helper(board, 0, 0);
//     }
// };