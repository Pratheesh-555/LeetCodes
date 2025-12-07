class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxprod = nums[0];
        int minprod = nums[0];
        int res = nums[0];
        for(int i = 1; i < nums.size(); i++){
            int cur = nums[i];
            if(cur < 0) swap(maxprod, minprod);

            maxprod = max(maxprod*cur, cur);
            minprod = min(minprod*cur, cur);
            res = max(maxprod, res);
        }
        return res;
    }
};