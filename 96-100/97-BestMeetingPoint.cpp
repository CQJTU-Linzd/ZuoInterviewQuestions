// 97 最佳聚会地点
class BestMeetingPoint {
public:
    int minTotalDistance(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<int>rowOnes(n); // 每一行上有几个1
        vector<int>colOnes(m); // 每一列上有几个1
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    rowOnes[i]++;
                    colOnes[j]++;
                }
            }
        }
        int total = 0;
        int i = 0;
        int j = n - 1;
        int iRest = 0;
        int jRest = 0;
        while (i < j) {
            if (iRest + rowOnes[i] <= jRest + rowOnes[j]) {
                iRest += rowOnes[i++];
                total += iRest;
            } else {
                jRest += rowOnes[j--];
                total += jRest;
            }
        }
        i = 0;
        j = m - 1;
        iRest = 0;
        jRest = 0;
        while (i < j) {
            if (colOnes[i] + iRest <= colOnes[j] + jRest) {
                iRest += rowOnes[i++];
                total += iRest;
            } else {
                jRest += colOnes[j--];
                total += jRest;
            }
        }
        return total;
    }
};
