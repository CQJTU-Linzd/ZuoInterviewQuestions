// 71 有效数独
class ValidSudoku {
    bool validSudoku(vector<vector<char>>& board) {
        bool row[9][10]; // row[i][j]: 第i行，j这个数字时候出现过
        bool col[9][10]; // col[i][j]: 第i列，j这个数字时候出现过
        bool bucket[9][10]; // bucket[i][j]: 第i号桶，j这个数字时候出现过
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                // [i][j]每一个格子
                int bid = 3 * (i / 3) + (j / 3); // 获取桶的编号
                if (board[i][j] != '.') {
                    int num = board[i][j] - '0';
                    if (row[i][num] || col[j][num] || bucket[bid][num]) {
                        return false;
                    }
                    row[i][num] = true;
                    col[j][num] = true;
                    bucket[bid][num] = true;
                }
            }
        }
        return true;
    }
};
