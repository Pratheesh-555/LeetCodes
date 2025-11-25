class Solution {
public:
    int smallestRepunitDivByK(int k) {
        long long num = 0;
        if(k%2 == 0 || k%5 == 0) return -1;
        for(int i = 1; i <= k; i++){
            num = (1LL*num*10 + 1)%k;
            if(num == 0) return i;
        }
        return -1;
    }
};