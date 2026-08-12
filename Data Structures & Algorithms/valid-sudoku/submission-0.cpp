class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        
        vector<unordered_set<int>>rows(9);
        vector<unordered_set<int>>cols(9);
        vector<unordered_set<int>>boxes(9);
        
        for(int i=0; i<9;i++){
            for(int j=0;j<9;j++){

                char num = board[i][j];

                if(num == '.') continue;

                // rows
                if(rows[i].count(num)) return false;
                rows[i].insert(num);

                // cols
                if(cols[j].count(num)) return false;
                cols[j].insert(num);

                // boxes
                int idx = (i/3) * 3 + (j/3);
                if(boxes[idx].count(num)) return false;
                boxes[idx].insert(num);


            }
        }
        return true;
    }
};