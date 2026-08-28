// https://leetcode.com/problems/different-ways-to-add-parentheses/description/




// class Solution {
// public:
//     vector<int> helper(int start, int end, string& expression){
//         int len = end - start + 1 ;
//         if(len <= 2){
//             return {stoi(expression.substr(start, len))};
//         }


//         vector<int> ans ;

//         for(int i = start ; i <= end ; i++){
//             if(expression[i] == '+' || expression[i] == '-' || expression[i] == '*'){
//                 vector<int> left = helper(start, i - 1, expression);
//                 vector<int> right = helper(i + 1, end, expression);

//                 for(auto &it : left){
//                     for(auto &jt : right){
//                         if(expression[i] == '+') ans.push_back(it + jt);
//                         if(expression[i] == '-') ans.push_back(it - jt);
//                         if(expression[i] == '*') ans.push_back(it * jt);
//                     }
//                 }


//             }
//         }

//         return ans ;
//     }

//     vector<int> diffWaysToCompute(string expression) {
//         int n = expression.size();

//         return helper(0, n - 1, expression);
//     }
// };