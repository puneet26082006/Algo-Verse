// https://leetcode.com/problems/restore-ip-addresses/description/





// class Solution {
// public:
//     vector<string> ans ;

//     bool isOkay(string s){
//         int num = stoi(s);

//         string s2 = to_string(num);

//         return ((s == s2) && (num <= 255));
//     }

//     void helper(string s, int sec , string curr, int idx){
//         if(sec == 4){
//             if(idx == s.size()){
//                 curr.pop_back();
//                 ans.push_back(curr);
//             }
//             return ;
//         }

        
//         for(int i = 1 ; i <= 3 ; i++){
//             if((idx + i <= s.size()) && isOkay(s.substr(idx,i))){
//                 helper(s, sec + 1, curr + s.substr(idx, i) + ".", idx + i);
//             }
//         }
        
//     }


//     vector<string> restoreIpAddresses(string s) {
//         int n = s.size();
//         ans.clear();

//         helper(s, 0,"",0);

//         return ans ;


//     }
// };