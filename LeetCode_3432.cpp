class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(),0);
        int left = 0;
        int res = 0;

        for(int i = 0; i < nums.size()-1; i++){
            left += nums[i];
            int right = sum - left;
            if(((left-right)%2) == 0){
                res++;
            }
        }
        return res;
    }
};