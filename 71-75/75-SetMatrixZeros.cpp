// 75 矩阵置零
class SetMatrixZeros {
public:
    void setZeros(vector<vector<int>>& matrix) {
        bool col0Zero = false; // 第0列要不要变零，单独记一下
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    if (j == 0) {
                        col0Zero = true;
                    } else {
                        matrix[0][j] = 0;
                    }
                }
            }
        }
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 1; j < matrix[0].size(); j++) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }
        if (col0Zero) {
            for (int i = 0; i < matrix.size(); i++) {
                matrix[i][0] = 0;
            }
        }
    }
};
