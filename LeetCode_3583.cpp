// class Solution {
// public:
//     int specialTriplets(vector<int>& nums) {
//         int n = nums.size();
//         int res = 0;
//         // int i = 0;

//         // while(i < n - 2){
//         //     int left = i+1;
//         //     int right = n-1;
//         //     while(left <= right){
//         //         if(nums[i] == nums[left]*2 && nums[i] == nums[right]*2){
//         //             res++;
//         //         }
//         //         left++;
//         //     }
//         //     while(left <= right){
//         //         if(nums[i] == nums[left]*2 && nums[i] == nums[right]*2){
//         //             res++;
//         //         }
//         //         right--;
//         //     }
//         // }
//         // unordered_map<int, int> mp;
//         // for(int i = 0; i < n; i++){
//         //     mp[nums[i]*2] = i;
//         // }
//         // unordered_map<int, int> freq;
//         // for(int num: nums){
//         //     freq[num]++;
//         // }
        
//         // for(int i = n-1; i > 0; i--){
//         //     if(nums[i] == nums[i-1]) continue;
//         //     if(freq[nums[i]] > 1){
//         //         if(mp.count(nums[i]*2) != 0 && i < mp[nums[i]]){
//         //             res++;
//         //         }
//         //     }
//         // }
         
//         // return res;
//     }
// };
class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        const int MOD = 1e9 + 7;
        int n = nums.size();
        long long res = 0;

        unordered_map<int, long long> suffix, prefix;

        // Step 1: build suffix frequency
        for(int num : nums) suffix[num]++;

        // Step 2: iterate through j
        for(int j = 0; j < n; j++) {
            suffix[nums[j]]--; // remove current element from suffix

            long long left = prefix[nums[j] * 2];   // count of i < j
            long long right = suffix[nums[j] * 2];  // count of k > j

            res = (res + left * right) % MOD;

            prefix[nums[j]]++; // add current element to prefix
        }

        return (int)res;
    }
};