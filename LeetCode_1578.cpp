class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int res = 0;
        int n = colors.size();
        int sum = neededTime[0];
        int maxEl = sum;
        for(int i = 1; i < n; i++){
            if(colors[i]== colors[i-1]){
                maxEl = max(maxEl, neededTime[i]);
               sum += neededTime[i];
               if(i == n-1){
                res += (sum-maxEl);
                sum = neededTime[i];
                maxEl = sum;
               }
            }
            else{
                res += (sum-maxEl);
                sum = neededTime[i];
                maxEl = sum;
            }
        }
        return res;
    }
};