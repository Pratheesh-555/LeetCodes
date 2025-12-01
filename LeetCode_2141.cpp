class Solution {
public:
    long long maxRunTime(int n, vector<int>& batteries) {
        long long low = 0;
        long long high = accumulate(batteries.begin(), batteries.end(), 0LL) / n;
        long long ans = 0;

        while (low <= high) {
            long long mid = (low + high) / 2;

            // Check feasibility
            long long total = 0;
            for (long long b : batteries) {
                total += min(b, mid);
            }

            if (total >= mid * n) {
                ans = mid;        // feasible
                low = mid + 1;    // try longer time
            } else {
                high = mid - 1;   // too long, reduce
            }
        }
        return ans;
    }
};