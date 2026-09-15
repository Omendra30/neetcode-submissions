class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        
        priority_queue<pair<int, vector<int>>> max_heap;
        
        for(auto& point : points){

            int dst = point[0]*point[0] + point[1]*point[1];
            max_heap.push({dst,point});

            if(max_heap.size()>k){
                max_heap.pop();
            }

        }

        vector<vector<int>> res;
        while(!max_heap.empty()){
            res.push_back(max_heap.top().second);
            max_heap.pop();
        }
    return res;
    }
};
