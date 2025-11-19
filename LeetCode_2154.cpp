class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        while(true){
            int found = 0;
            for(int n : nums){
                if(n == original){
                    original *= 2;
                    found = 1;
                }
            }
            if(!found) return original;
        }
    }
};