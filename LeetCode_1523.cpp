class Solution {
public:
    int countOdds(int low, int high) {
        int res = 0;
        res = high-low;
        res = res/2;
        if(low%2!=0 || high%2!= 0){
            res += 1;
        }
        return res;
    }
};