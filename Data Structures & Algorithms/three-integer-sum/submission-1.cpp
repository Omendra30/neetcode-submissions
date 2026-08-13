class Solution {
public:
vector<vector<int>> result;

    void twoSum(vector<int> &nums, int tar, int i, int j){

     while(i<j){
           if(nums[i]+nums[j]>tar) j--;
        else if(nums[i]+nums[j]<tar) i++;
        else{
            while(i<j && nums[i]==nums[i+1]) i++;
            while(j>0 && nums[j]==nums[j-1]) j--;

            result.push_back({-tar,nums[i],nums[j]});
            i++;
            j--;
        }
      }
    }

    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        if(n<3) return {};

        sort(nums.begin(),nums.end());
        result.clear();

        for(int i=0;i<n-2;i++){
            if(i>0 && nums[i]==nums[i-1]) continue;

            int n1 = nums[i];
            int tar = -n1;

            twoSum(nums,tar,i+1,n-1);
        }
      return result; 
    }
};
