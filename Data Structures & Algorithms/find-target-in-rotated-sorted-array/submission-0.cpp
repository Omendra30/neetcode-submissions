class Solution {
private:
int helper(vector<int>& arr, int tar, int left, int rgt){
    if(left>rgt) return -1;

    int mid = left+(rgt-left)/2;

    if(arr[mid]==tar) return mid;

    if(arr[left]<=arr[mid]){
        if(arr[left]<=tar && tar<=arr[mid]){
            return helper(arr,tar,left,mid-1);
        }
        else{
             return helper(arr,tar,mid+1,rgt);
        }
    } 
    else{
        if(arr[mid]<=tar && tar<=arr[rgt]){
            return helper(arr,tar,mid+1,rgt);
        }
        else{
            return helper(arr,tar,left,mid-1);
        }
    }
}


public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
       return helper(nums,target,0,n-1);
    }
};
