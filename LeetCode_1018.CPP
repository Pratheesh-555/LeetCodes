class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        long long num = 0;
        int n = nums.size();
        vector<bool> res;
        for(int n : nums){
            num = (num*2 + n)%5;
            res.push_back(num%5==0);
        }

        return res;
    }
};