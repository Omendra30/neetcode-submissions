// T.C -> O(n+m)
// class Solution {
// public:
//     bool searchMatrix(vector<vector<int>>& matrix, int target) {
//         int row = matrix.size();
//         int col = matrix[0].size();
//         int r = row-1, c = 0;

//         while(r>=0 && c<col){
//             if(matrix[r][c] == target) return true;
//             else if(matrix[r][c] > target) r--;
//             else c++;
//         }

//     return false;
//     }
// };

// T.C -> O(lon(n*m))
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int low = 0, high = m*n - 1;

        while(low <= high) {
            int mid = low + (high - low)/2;
            int val = matrix[mid/n][mid%n]; // map 1D index to 2D

            if(val == target) return true;
            else if(val < target) low = mid + 1;
            else high = mid - 1;
        }
        return false;
    }
};

