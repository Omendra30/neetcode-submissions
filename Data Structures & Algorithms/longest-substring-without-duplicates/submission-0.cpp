class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int low = 0,ans = 0;
        unordered_map<char,int> mp;

        
        for(int high=0;high<n;high++){
            mp[s[high]]++;

            while(mp[s[high]]>1){
                mp[s[low]]--;
                low++;
            }
            ans = max(ans, high - low + 1);
        }
        return ans;
    }
};
