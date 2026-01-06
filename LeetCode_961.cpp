class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        int n = nums.size()/2;

        unordered_map<int, int> mp;

        for(int i : nums){
            mp[i]++;
            if(mp[i] == n) return i;
        }
        return 0;
    }
};