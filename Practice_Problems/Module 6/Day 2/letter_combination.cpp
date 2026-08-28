// https://leetcode.com/problems/letter-combinations-of-a-phone-number/


// class Solution {
// public:
//     vector<string> ans ;
//     vector<string> numberPad{"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

//     void helper(string& digits, int idx, string curr){
//         if(idx == digits.size()){
//             ans.push_back(curr);
//             return ;
//         }

//         for(auto &letter : numberPad[digits[idx] - '0']){
//             helper(digits, idx + 1, curr + letter);
//         }
//     }

//     vector<string> letterCombinations(string digits) {
//         helper(digits, 0, "");

//         return ans ;
//     }
// };