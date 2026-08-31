class Solution {
public:

    int helper(vector<int>& arr, int num, int h){
        int count = 0;
        for(int i=0;i<arr.size();i++){
            // count += (arr[i] + num - 1) / num; // ceil division
            if(arr[i]%num == 0){
                count = count+ arr[i]/num;
            }
            else{
                count = count+arr[i]/num + 1;
            }
        }
        return count;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        
        int maxEl = *max_element(piles.begin(),piles.end());
        int low = 1, high = maxEl;
        int res = maxEl;

        while(low<=high){
            int mid = low+(high-low)/2;
            int count = helper(piles,mid,h);
            if(count <= h){
                res = mid;
                high = mid-1;
            }
            else if(count>h){
                low = mid+1;
            }
        }

        return res;
    }
};
