class Solution {
public:
    int totalMoney(int n) {
        int mon = 0;
        int total = 0;
        int prev = 0;
        for(int i = 0; i < n; i++){
            if(i%7 == 0){
                mon = mon + 1;
                total += mon;
                prev = mon;
            }
            else{
                prev += 1;
                total += prev;
            }
        }
        return total;
    }
};