class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();

        if(m>n){
            return findMedianSortedArrays(nums2,nums1);
        }

        int low =  0, high = m-1;

        while(low<=high){
            int partitionX = low+(high-low)/2;
            int partitionY = (m+n+1)/2-partitionX;

            int left1 = (partitionX == 0) ? INT_MIN : nums1[partitionX-1];
            int right1 = (partitionX == m) ? INT_MAX : nums1[partitionX];

            int left2 = (partitionY == 0) ? INT_MIN : nums2[partitionY-1];
            int right2 = (partitionY == n) ? INT_MAX : nums2[partitionY];


            if(left1<= right2 && left2<=right1){
                if((m+n)%2==0){
                    return (double) (max(left1,left2)+min(right1,right2))/2;
                }
                else{
                    return (double) max(left1,left2);
                }
            }
            else if(left1>right2){
                high = partitionX-1;
            }
            else{
                low = partitionX+1;
            }
        }
    }
};
