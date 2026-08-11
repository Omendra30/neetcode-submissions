class Solution {
public:
    bool isAnagram(string s, string t) {
        int n = s.length();
        int m = t.length();
        if(n != m) return false;

        vector<int>freq(128,0);

        for(char ch:s){
            freq[ch]++;
        }

        for(char ch:t){
            if(freq[ch]==0) return false;
            freq[ch]--;
        }
        return true;
    }
};
