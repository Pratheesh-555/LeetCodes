class Solution {
public:
//     int maxDistinctElements(vector<int>& nums, int k) {
//         unordered_map<int, int> freq;
//         for (int num : nums) freq[num]++;
//         sort(nums.begin(), nums.end());
//         unordered_set<int> used;
//         int distinct = 0;
//         for (int num : nums) {
//             bool placed = false;
//             for (int delta = -k; delta <= k; ++delta) {
//                 long long candidate = (long long)num + delta;
//                 if (!used.count(candidate)) {
//                     used.insert(candidate);
//                     placed = true;
//                     distinct++;
//                     break;
//                 }
//             }
//         }
//     return distinct;
        int maxDistinctElements(vector<int>& nums, int k) {
    sort(nums.begin(), nums.end());
    
    long long last = LLONG_MIN;
    int distinct = 0;

    for (int num : nums) {
        long long left = (long long)num - k;
        long long right = (long long)num + k;
        
        if (last < right) {
            long long newVal = max(left, last + 1);
            last = newVal;
            distinct++;
        }
    }
    return distinct;
}

  
};

