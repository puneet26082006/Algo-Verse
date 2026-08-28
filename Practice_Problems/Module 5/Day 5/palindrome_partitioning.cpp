// https://leetcode.com/problems/palindrome-partitioning/description/

// class Solution {
// public:
//     vector<string> palindrome ;
//     vector<vector<string>> ans ;

//     bool ispalindrome(string& s, int left, int right){
//         bool possible = true ;
//         for(int i = left ; i <= right ; i++){
//             if(s[i] != s[right - (i - left)]){
//                 possible = false ;
//                 break ;
//             }
//         }
//         return possible ;
//     }

//     void helper(string& s, int idx, vector<string>& palindrome){
//         if(idx == s.size()){
//             ans.push_back(palindrome);
//             return ;
//         }

//         string temp = "";
//         for(int i = idx ; i < s.size() ; i++){
//             temp += s[i];
//             if(ispalindrome(s, idx, i)){
//                 palindrome.push_back(temp);
//                 helper(s, i + 1, palindrome);
//                 palindrome.pop_back();
//             }
//         }
//     }
//     vector<vector<string>> partition(string s) {
//         helper(s, 0, palindrome);

//         return ans ;
//     }
// };