class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int, int> mp;
        vector<int> res;
        int n = nums.size();
        n = floor(double(n)/ double(3));
        for(int num : nums){
            mp[num]++;
        }
        for(auto& it: mp){
            if(it.second > n){
                res.push_back(it.first);
            }
        }
        return res;
    }
};