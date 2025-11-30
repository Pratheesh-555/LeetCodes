class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        long long total = accumulate(nums.begin(), nums.end(), 0LL);
        int rem = total % p;
        if (rem == 0) return 0;

        unordered_map<int, int> mp; // prefix_mod -> index
        mp[0] = -1; // base case

        long long prefix = 0;
        int res = nums.size();
        for (int i = 0; i < nums.size(); i++) {
            prefix = (prefix + nums[i]) % p;
            int target = (prefix - rem + p) % p;
            if (mp.count(target)) {
                res = min(res, i - mp[target]);
            }
            mp[prefix] = i;
        }
        return res == nums.size() ? -1 : res;

        // int left = 0;
        // int right = 0;

        // int n = nums.size();
        // long long total = accumulate(nums.begin(), nums.end(), 0);
        // if(total%p == 0) return 0;
        // long long sum = 0, res = INT_MAX;
        // while(right < n){
        //     sum += 1LL*nums[right];
            
        //     while(left < right && (total-sum)%p!=0){
        //         sum -= 1LL*nums[left];
        //         left++;
        //     }
        //     if((total-sum)%p == 0){
        //         res = min(1LL * (right-left+1),1LL* res);
        //     }
        //     right++;
        // }
        // return res == INT_MAX ? -1 : res;
    }
};