class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool rows[9][9] = {},
        cols[9][9] = {},
        boxes[9][9] = {};

        for(int r = 0; r< board.size(); r++) {
            for(int c = 0; c < board[0].size(); c++){
                if (board[r][c] == '.') continue;

                int d = board[r][c] - '1';
                
                int b = (r / 3)*3 + (c/3);

                if(cols[c][d] || rows[r][d] || boxes[b][d]) return false;

                cols[c][d] = true;
                rows[r][d] = true;
                boxes[b][d] = true;

            }
        }
        return true;
    }
};
