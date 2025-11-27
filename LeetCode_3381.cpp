class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        // int cur = nums[0];
        // int sum = nums[0];
        // int n = nums.size();
        // int x = 0, y = 0;
        // int res = INT_MIN;
        // for(int i = 1; i < n; i++){
           
        //     if((cur+nums[i]) > nums[i]){
        //         cur = cur + nums[i];
        //         y = i;
        //     }
        //     else{
        //         cur = nums[i];
        //         x = i;
        //         y = i;  
        //     }
           
        //     if((y-x+1) % k == 0){
        //         sum = max(cur, sum);
        //     }
        // }
        // if((y-x+1) % k == 0){
        //         sum = max(cur, sum);
        //     }
        // return sum;
        int n = nums.size();
        vector<long long> prefix(n+1, 0);

        for (int i = 0; i < n; i++) {
            prefix[i+1] = prefix[i] + nums[i];
        }

        // Store minimum prefix sum for each modulo class
        vector<long long> minPrefix(k, LLONG_MAX);
        long long res = LLONG_MIN;

        for (int i = 0; i <= n; i++) {
            int mod = i % k;
            if (minPrefix[mod] != LLONG_MAX) {
                res = max(res, prefix[i] - minPrefix[mod]);
            }
            minPrefix[mod] = min(minPrefix[mod], prefix[i]);
        }


        // int n = nums.size();
        // vector<long long> prefix(n+1, 0);

        // // Build prefix sum
        // for (int i = 0; i < n; i++) {
        //     prefix[i+1] = prefix[i] + nums[i];
        // }

        // long long res = LLONG_MIN;

        // // Check all subarrays
        // for (int i = 0; i < n; i++) {
        //     for (int j = i+k; j <= n; j += k) { // ensure length divisible by k
        //         long long sum = prefix[j] - prefix[i];
        //         res = max(res, sum);
        //     }
        // }

        // return res;

    // }
};