class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s2.size()<s1.size()) return false;
        int low = 0;
        vector<int>count1(26,0), count2(26,0);

        for(char ch:s1){
            count1[ch-'a']++;
        } 
        for(int high=0;high<s1.size();high++){
            count2[s2[high]-'a']++;
        }

        for(int high=s1.size();high<s2.size();high++){
            if(count1 == count2) return true;
            count2[s2[high]-'a']++;

            if(high-low+1>s1.size()){
                count2[s2[low]-'a']--;
                low++;
            }

        }
        return count1 == count2;
      
    }
};
