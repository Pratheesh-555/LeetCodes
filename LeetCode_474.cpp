// class Solution {
// public:
//     vector<int> nums(string s){
//         int a = 0;
//         int b = 0;
//         for(char ch : s){
//             if(ch == '0') a++;
//             else b++;
//         }
//         return {a,b};
//     }

//     int findMaxForm(vector<string>& strs, int m, int n) {
//         int res = 0;
    
//         for(int i = 0;i < strs.size(); i++){
//              int z =0, o = 0,count = 0;
//             for(int j = i; j < strs.size(); j++){
//                 vector<int> t = nums(strs[j]);
//                 if(z > m || o > n || z+t[0] > m || o+t[1] > n) continue;
//                 z += t[0];
//                 o += t[1];
//                 count++;
//             }
//             res = max(count, res);
//         }
//         return res;
//     }
// };
class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        
        for (string& s : strs) {
            int zeros = 0, ones = 0;
            for (char c : s) {
                if (c == '0') zeros++;
                else ones++;
            }

            // Traverse backwards to avoid recomputation
            for (int i = m; i >= zeros; i--) {
                for (int j = n; j >= ones; j--) {
                    dp[i][j] = max(dp[i][j], 1 + dp[i - zeros][j - ones]);
                }
            }
        }
        return dp[m][n];
    }
};
