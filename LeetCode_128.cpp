class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0) return 0;

        unordered_set<int> uset;
        for(int n : nums){
            uset.insert(n);
        }
        int res = 1;

        for(auto &it : uset){
           
            if(uset.count(it-1) == 0){
                int target = it;
                int s = 1; 
                while(uset.count(target+1)!=0){
                    s++;
                    target++;
                }
                res = max(res,s);
            }
            
        }
        return res;
    }
};