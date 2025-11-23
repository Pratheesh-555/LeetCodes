// class Solution {
// public:
//     int msum(int idx, vector<int> &nums){
       
//         if(idx == 0){
//             return nums[idx];
//         }
//         if(idx < 0 ) return 0;

//         int pick =nums[idx] +  msum(idx-1,nums);
//         int notpick = 0+ msum(idx-1, nums);
//         int sum = max(sum , (pick+notpick) % 3 == 0 ? pick+notpick : 0);
//         return sum%3 == 0 ? sum : 0;
//     }
//     int maxSumDivThree(vector<int>& nums) {
//         int n = nums.size();
//         return msum(0, nums);
//     }
// };

class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        vector<int> dp(3, 0);  

        for(int num : nums){
            vector<int> cur(dp); 
            for(int r = 0; r < 3; r++){
                int newSum = dp[r] + num;
                cur[newSum % 3] = max(cur[newSum % 3], newSum);
            }
            dp = cur; 
        }
        return dp[0]; 
    }
};
