class Solution {
public:
    int f(int idx,int sum, vector<int> &nums, int target,vector<vector<int>> &dp, int x){
       
        if(idx == nums.size()){
            if(target == sum) return 1;
            return 0;
        }
        if(dp[idx][sum+x] != -1) return dp[idx][sum+x];
        int plus = f(idx+1,sum+nums[idx],nums,target,dp,x);
        int minus = f(idx+1,sum-nums[idx],nums,target,dp,x);

        return dp[idx][sum+x] = plus+minus;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int s = accumulate(nums.begin(),nums.end(),0);
        int  x = s;
        vector<vector<int>> dp(nums.size(),vector<int>(2*s+1, -1));
        return f(0, 0, nums,target,dp,x);
    }
};