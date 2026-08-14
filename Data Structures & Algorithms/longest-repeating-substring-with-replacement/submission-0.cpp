class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int low = 0, ans = 0, maxCount = 0;
        vector<int>count(26,0);

        for(int high=0;high<n;high++){
           count[s[high]-'A']++;
           maxCount = max(maxCount, count[s[high]-'A']);

           while((high-low+1)-maxCount > k){
            count[s[low]-'A']--;
            low++;
           }

           ans = max(ans, high-low+1);
        }
        return ans;
    }
};
