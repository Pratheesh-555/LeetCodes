class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int res = nums[0];
        vector<int> temp;
        for(int i = 1; i < nums.size(); i++){
            temp.push_back(nums[i]);
        }
        sort(temp.begin(), temp.end());
        res += temp[0]+temp[1];
        return res;
    }
};