// 84 生命游戏
class LifeGame {
    int n;
    int m;
public:
    // 0是死细胞，1是活细胞
    // 任意一个活，如果周围有2~3个活细胞，那么下一轮才会活，否则就会死
    // 任意一个死，如果周围正好有3个活细胞，那么下一轮就会活，否则还是死
    void lifeGame(vector<vector<int>>& board) {
        n = board.size();
        m = board[0].size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int neighbor = neighbors(board, i, j);
                if (neighbor == 3 || (board[i][j] == 1 && neighbor == 2)) {
                    board[i][j] |= 2; // 二进制里的第二位设置成1，表示这个位置下一轮为1
                }
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                board[i][j] >>= 1;
            }
        }
    }

    // 统计一个位置周围有几个1
    int neighbors(vector<vector<int>>& board, int i, int j) {
        int cnt = 0;
        cnt += in(i - 1, j) ? board[i - 1][j] : 0;
        cnt += in(i - 1, j - 1) ? board[i - 1][j - 1] : 0;
        cnt += in(i, j - 1) ? board[i][j - 1] : 0;
        cnt += in(i + 1, j - 1) ? board[i + 1][j - 1] : 0;
        cnt += in(i + 1, j) ? board[i + 1][j] : 0;
        cnt += in(i + 1, j + 1) ? board[i + 1][j + 1] : 0;
        cnt += in(i, j + 1) ? board[i][j + 1] : 0;
        cnt += in(i - 1, j + 1) ? board[i - 1][j + 1] : 0;
        return cnt;
    }
    bool in(int i, int j) {
        return i >= 0 && i < n&& j >= 0 && j < m;
    }
};
