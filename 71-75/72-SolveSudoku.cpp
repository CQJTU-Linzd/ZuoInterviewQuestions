// 72 解数独
class SolveSudoku {
    bool row[9][10]; // row[i][j]: 第i行，j这个数字时候出现过
    bool col[9][10]; // col[i][j]: 第i列，j这个数字时候出现过
    bool bucket[9][10]; // bucket[i][j]: 第i号桶，j这个数字时候出现过
public:
    void solveSudoku(vector<vector<char>>& board) {
        initMap(board);
        process(board, 0, 0);
    }
    void initMap(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                int bid = 3 * (i / 3) + (j / 3);
                if (board[i][j] != '.') {
                    int num = board[i][j] - '0';
                    this->row[i][num] = true;
                    this->col[j][num] = true;
                    this->bucket[bid][num] = true;
                }
            }
        }
    }
    bool process(vector<vector<char>>& board, int i, int j) {
        if (i == 9) {
            return true;
        }
        int nexti = j == 8 ? i + 1 : i;
        int nextj = j == 8 ? 0 : j + 1;
        if (board[i][j] != '.') {
            return process(board, nexti, nextj);
        } else { // 当前位置需要填数字
            int bid = 3 * (i / 3) + (j / 3);
            for (int num = 1; num <= 9; num++) { // 1~9进行尝试
                if (!row[i][num] && !col[j][num] && !bucket[bid][num]) {
                    board[i][j] = (char)(num + '0');
                    row[i][num] = true;
                    col[j][num] = true;
                    bucket[bid][num] = true;
                    if (process(board, nexti, nextj)) {
                        return true;
                    }
                    board[i][j] = '.';
                    row[i][num] = false;
                    col[j][num] = false;
                    bucket[bid][num] = false;
                }
            }
            return false;
        }
    }
};
