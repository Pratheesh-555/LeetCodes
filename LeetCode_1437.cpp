class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int left = 0;
        int right = 0;
        int cnt = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == 1){
                left = i;
                right = i+1;
                break;
            }
        }
        while(right < nums.size()){
            if(nums[right] == 1){
                // while(nums[left] == 0){
                //     left++;
                // }
                if(right - left - 1 < k){
                    return false;
                }
                left = right;
            }
            right++;
        }
        return true;
    }
};