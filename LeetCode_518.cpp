class Solution {
public:
    int f(int idx, int target, vector<int> &coins, vector<vector<int>> &dp){
        if(idx == 0){
            if(target%coins[0]==0) return 1;
            return 0;
        }
        if(target < 0 || idx < 0) return 0;
        if(dp[idx][target] != -1) return dp[idx][target];
        int take = f(idx,target-coins[idx],coins,dp);
        int nottake = f(idx-1,target,coins,dp);

        return dp[idx][target]=take+nottake;
    }
    int change(int amount, vector<int>& coins) {
        vector<vector<int>> dp(coins.size()+1,vector<int>(amount+1,-1));
        return f(coins.size()-1,amount,coins,dp);
    }
};