class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int res = 0;
        sort(capacity.begin(), capacity.end());
        reverse(capacity.begin(), capacity.end());

        int sum = accumulate(apple.begin(), apple.end(), 0);
        int i = 0;
        while(sum > 0){
            sum -= capacity[i++];
            res++;   
        }
        return res;
    }
};