// class Solution {
// public:

//     long long maximumProfit(vector<int>& prices, int k) {
//         long long res = 0;
//         int n = prices.size();
//         vector<bool> vis(n,false);
//         int minP = INT_MAX;
//         int maxP = INT_MIN;
//         while(k>0){
//             for(int i = 0; i < n; i++){
//                 if(!vis[i]){
//                     // minP = min(minP, prices[i]);
//                 if(prices[i] < minP){
//                     vis[i] = true;
//                     minP = prices[i];
//                 }
//                 // maxP = max(maxP, prices[i]-minP);
//                 if(prices[i]-minP > maxP){
//                     vis[i] = true;
//                     maxP = prices[i] - minP;
//                 }
//                 }
//             }
//             k--;
//         }
//         return maxP;
//     }
// };

class Solution {
public:
    long long maximumProfit(vector<int>& prices, int k) {
        int n = prices.size();
        const long long NEG = -1e18;

        vector<long long> none(k+1, 0);
        vector<long long> longPos(k+1, NEG);
        vector<long long> shortPos(k+1, NEG);

        for (int price : prices) {
            for (int j = k; j >= 0; j--) {
                // open positions
                longPos[j] = max(longPos[j], none[j] - price);
                shortPos[j] = max(shortPos[j], none[j] + price);

                // close positions
                if (j > 0) {
                    none[j] = max({
                        none[j],
                        longPos[j-1] + price,
                        shortPos[j-1] - price
                    });
                }
            }
        }

        return *max_element(none.begin(), none.end());
    }
};
