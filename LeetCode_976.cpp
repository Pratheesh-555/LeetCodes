class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int res = 0;
        for(int i = nums.size()-1; i >= 2; i--){
            int left = 0;
            int right = i-1;
            while(left < right){
                int per =  nums[left]+nums[right]+nums[i] ;
                if(nums[left] + nums[right] > nums[i]){
                    res = max(res,per);
                    // right--;
                }
                // else{
                //     left++;
                // }
                left++;
            }
        }
        return res;
    }
};