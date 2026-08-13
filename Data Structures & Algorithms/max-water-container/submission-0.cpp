class Solution {
public:
    int maxArea(vector<int>& heights) {
      int n = heights.size();
      int left = 0, right = n-1;
      int maxWater = INT_MIN;

      while(left<right){
        int length = min(heights[left],heights[right]);
        int width = right-left;
        int currWater = length*width;
        maxWater = max(maxWater,currWater);
        if(heights[left]<heights[right]) left++;
        else right--; 
      }

      return maxWater;  
    }
};
