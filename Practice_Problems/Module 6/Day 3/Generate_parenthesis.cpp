// https://leetcode.com/problems/generate-parentheses/description/


// class Solution {
// public:
//     void helper(int n, vector<string>& ans, string curr, int numopen, int idx){

//         if(idx == n){
//             if(numopen == 0){
//                 ans.push_back(curr);
//             }
//             return ;
//         }

        
//         helper(n, ans, curr + '(', numopen + 1, idx + 1); 
//         if(numopen > 0){
//             helper(n, ans, curr + ')' , numopen - 1, idx + 1);
//         }
//     }

//     vector<string> generateParenthesis(int n) {
//         vector<string > ans ;
//         string curr ;

//         helper(2 * n, ans, curr, 0, 0);

//         return ans ;
//     }
// };