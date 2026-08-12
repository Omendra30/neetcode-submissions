class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();

        unordered_map<int,int> mp;\

        // min-heap storing {frequency, element}
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

        for(int num:nums){
            mp[num]++;
        }

        for(auto &p:mp){
          pq.push({p.second, p.first});
          if(pq.size()>k){ // to store only k elements
            pq.pop();
          }
        }

        vector<int> result;
        while(!pq.empty()){
            result.push_back(pq.top().second);
            pq.pop();
        }

        return result;
    }
};
