class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<bool> column(matrix[0].size(), false);
        vector<bool> row(matrix.size(), false);
        
        for(int i = 0; i < matrix.size(); i ++){
            for(int j = 0; j < matrix[0].size(); j++) {
                if(matrix[i][j] == 0) {
                    row[i] = true;
                    column[j] = true;
                }
            }
        }

        for(int i = 0; i < matrix.size(); i ++){
            for(int j = 0; j < matrix[0].size(); j++) {
                if(row[i] || column[j]) {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};
