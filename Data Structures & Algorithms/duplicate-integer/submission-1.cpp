class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        int n = nums.size();
      unordered_map<int,int>freq;
      for(int i=0;i<n;i++){
        if(freq[nums[i]]>0) return true;
        else freq[nums[i]]++;
      }
      return false;
    }
};