class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<char> rows[9], cols[9], boxes[9];

        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                char nums = board[i][j];
                if(nums == '.') continue;
                int boxIndex = (i/3)* 3 + (j/3);

                if(rows[i].count(nums)) return false;
                if(cols[j].count(nums)) return false;
                if(boxes[boxIndex].count(nums)) return false;

                rows[i].insert(nums);
                cols[j].insert(nums);
                boxes[boxIndex].insert(nums);
            }
        }
        return true;
    }
};
