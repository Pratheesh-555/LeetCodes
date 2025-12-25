class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        sort(happiness.rbegin(), happiness.rend());
        int res = 0;
        
        for(int i =0; i < k; i++){
            int val = happiness[i]-i;
            if(val > 0){
                res+=val;
            }
        }
        return res;
    }
};