class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        // int count = 0;
        // int n = nums.size();
        // for(int i = 0; i < n; i++){
        //     for(int j = i+1; j < n; j++){
        //         for(int k = j+1; k < n; k++){
        //             if((nums[i] < nums[j]+nums[k]) && (nums[j] < nums[i]+ nums[k]) && (nums[k] < nums[i] + nums[j])){
        //                 count++;
        //             }
        //         }
        //     }
        // }
        // return count;

        int count=0;
        sort(nums.begin(), nums.end());
        int n= nums.size();

        // for(int i=0;i<n-2;i++){

        //     int left = i+1;
        //     int right = n-1;

        //     while(left < right){
        //         int sum = nums[i]+nums[left];

        //         if(sum>= nums[right]){
        //             count+= (right-left);
        //             right--;
        //         }
        //         left++;
        //     }
        // }
        // return count;

        for(int i=n-1;i>=2;i--){
            int left = 0;
            int right = i-1;
            while(left < right){
                if(nums[left]+nums[right] > nums[i]){
                    count += (right - left);
                    right--;
                }
                else{
                    left++;
                }
            }
        }
        return count;
    }
};