class Solution {
public:
    int maxArea(vector<int>& height) {
        int water = 0;
        int n = height.size();
        int left = 0, right = n-1;
        while(left < right){
            if(height[left] >= height[right]){
                water = max(water, height[right]*(right-left));
                right--;
            }
            else{
                water = max(water, height[left]*(right-left));
                left++;
            }

        }
        return water;
  }
};