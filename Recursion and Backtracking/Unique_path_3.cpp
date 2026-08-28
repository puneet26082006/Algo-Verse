// // https://leetcode.com/problems/unique-paths-iii/


// class Solution {
//     int dx[4] = {0, 0, -1, 1};
//     int dy[4] = {-1, 1, 0, 0};
//     int helper(int r, int c, vector<vector<int>>& grid, int cnt){
//         int n = grid.size();
//         int m = grid[0].size();

//         if(r < 0 || r >= n || c < 0 || c >= m || grid[r][c] == -1){
//             return 0 ;
//         }

//         if(grid[r][c] == 2){
//             if(cnt == -1){
//                 return 1 ;
//             } else {
//                 return 0 ;
//             }
//         }


//         int temp = grid[r][c];
//         grid[r][c] = -1 ;

//         int ans = 0 ;

//         for(int i = 0 ; i < 4 ; i++){
//             int nr = r + dx[i];
//             int nc = c + dy[i];

//             ans += helper(nr, nc, grid, cnt - 1);
//         }

//         grid[r][c] = temp ;

//         return ans ;

//     }
// public:
//     int uniquePathsIII(vector<vector<int>>& grid) {
//         int n = grid.size();
//         int m = grid[0].size();

//         int r, c ;
//         int cnt = 0 ;

//         for(int i = 0 ; i < n ; i++){
//             for(int j = 0 ; j < m ; j++){
//                 if(grid[i][j] == 1){
//                     r = i ;
//                     c = j ;
//                 } else if(grid[i][j] == 0){
//                     cnt++ ;
//                 }
//             }
//         }

//         int ans = helper(r, c, grid, cnt);

//         return ans ;
//     }
// };