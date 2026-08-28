// // https://leetcode.com/problems/word-search/description/?envType=problem-list-v2&envId=backtracking



// class Solution {
//     int dx[4] = {0, 0, -1, 1};
//     int dy[4] = {1, -1, 0, 0};

//     bool helper(vector<vector<char>>& board,int n, int m, string word, int row, int col){
//         if(word.size() == 0){
//             return true ;
//         }

//         if(row < 0 || row >= n || col < 0 || col >= m || word[0] != board[row][col]){
//             return false ;
//         }

//         char s = board[row][col];
//         string new_word = word.substr(1);
//         board[row][col] = '*';

//         bool ans = false ;

//         for(int i = 0 ; i < 4 ; i++){
//             int new_row = row + dx[i];
//             int new_col = col + dy[i];

//             ans |= helper(board, n, m, new_word, new_row, new_col);
//         }

//         board[row][col] = s ;

//         return ans ;
//     }

// public:
//     bool exist(vector<vector<char>>& board, string word) {
//         int n = board.size();
//         int m = board[0].size();
    

//         for(int i = 0 ; i < n ; i++){
//             for(int j = 0 ; j < m ; j++){
//                 if(board[i][j] == word[0]){
//                     bool res = helper(board,n, m, word, i, j);
//                     if(res){
//                         return true ;
//                     }
//                 }
//             }
//         }

//         return false ;


//     }
// };