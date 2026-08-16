class Solution {
public:
    bool check(vector<int>& s_arr,vector<int>& t_arr){
        for(int i=0;i<256;i++){
            if(s_arr[i]<t_arr[i]) return false;
        }
        return true;
    }

    string minWindow(string s, string t) {
        if(s.size()<t.size()) return "";
        vector<int>s_arr(256,0);
        vector<int>t_arr(256,0);
        int low = 0, start = 0, ans = INT_MAX;

        for(int i=0;i<t.size();i++){
            t_arr[t[i]]++;
        }

        for(int high=0;high<s.length();high++){
            s_arr[s[high]]++;
            while(check(s_arr,t_arr)){
                int len = high-low+1;
                if(ans>len){
                    ans = len;
                    start = low;
                }
                s_arr[s[low]]--;
                low++;
            }
        }
        return ans == INT_MAX ? "":s.substr(start,ans); 

    }
};
