class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        // Sort intervals by start
        sort(intervals.begin(), intervals.end());
        
        // Sort queries but keep original indices
        vector<pair<int,int>> q;
        for(int i=0;i<queries.size();i++) q.push_back({queries[i], i});
        sort(q.begin(), q.end());
        
        vector<int> ans(queries.size(), -1);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
        
        int i = 0;
        for(auto [query, idx] : q) {
            // Add intervals that start <= query
            while(i < intervals.size() && intervals[i][0] <= query) {
                int l = intervals[i][0], r = intervals[i][1];
                pq.push({r - l + 1, r}); // store length and right end
                i++;
            }
            
            // Remove intervals that end < query
            while(!pq.empty() && pq.top().second < query) {
                pq.pop();
            }
            
            // Answer is smallest interval covering query
            if(!pq.empty()) ans[idx] = pq.top().first;
        }
        
        return ans;
    }
};
