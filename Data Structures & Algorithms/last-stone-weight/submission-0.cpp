class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;

        //priority_queue<int> pq(stones.begin(), stones.end());

        for(int i=0;i<stones.size();i++){
            pq.push(stones[i]);
        }

        while(pq.size()>1){

            int e1 = pq.top();
            pq.pop();
            int e2 = pq.top();
            pq.pop();

            int diff = abs(e1-e2);

            if(diff ==0) continue;
            else pq.push(diff);
        }

        return pq.empty() ? 0 : pq.top();
    }
};
