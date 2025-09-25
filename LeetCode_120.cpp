// class Solution {
// public:
//     int minimumTotal(vector<vector<int>>& triangle) {
//         int res = triangle[0][0];

//         vector<vector<int>> dp(n,vector<int>(n,0));

//         for(int i = 1; i < triangle.size(); i++){
//             if(triangle[i][idx] > triangle[i][idx+1]){
                
//                 res += triangle[i][idx+1];
//                 idx++;
//             }
//             else{
//                 res += triangle[i][idx];
//             }

//         }
//         return res;
//     }
// };


class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        //vector<vector<int>> dp(n, vector<int>(n,0));
        
        // for(int i = 0; i < triangle[n-1].size(); i++){
        //     dp[n-1][i] = triangle[n-1][i];
        // }

        for(int i = n-2; i >= 0; i--){
            for(int j = 0; j < triangle[i].size(); j++){
                triangle[i][j] =  triangle[i][j] + min(triangle[i+1][j], triangle[i+1][j+1]);
            }
        }
        return triangle[0][0];
    }
};