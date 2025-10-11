class Solution {
public:
    long long check(vector<int> &piles, long long n){
        long long sum = 0;
        for(int i = 0; i < piles.size(); i++){
            sum+=ceil((double)piles[i]/(double)n);
        }
        return sum;

    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = *max_element(piles.begin(), piles.end());
        int ans = INT_MAX;
        while(low <= high){
            int mid = (low+high)/2;
            long long a = check(piles,mid);
            
            if( a<= h){
                high = mid -1;
                ans = mid;
            }           
            else{
                low = mid+1;
            }
        }
        return ans;
    }
};