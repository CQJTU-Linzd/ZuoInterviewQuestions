// 任务完成所需时间
class TimeOfTask {
public:
    vector<int> times(vector<int>& time, vector<vector<int>>& m) {
        int n = time.size();
        vector<vector<int>>nexts(n);
        vector<int>in(n);
        for (vector<int> it : m) {
            int from = it[1];
            int to = it[0];
            nexts[from].push_back(to);
            in[to]++;
        }
        queue<int>zeroInQue;
        for (int curin : in) {
            if (curin == 0) {
                zeroInQue.push(curin);
            }
        }
        vector<int>ans(n);
        while (!zeroInQue.empty()) {
            int cur = zeroInQue.front();
            zeroInQue.pop();
            ans[cur] += time[cur];
            for (int next : nexts[cur]) {
                ans[next] = max(ans[next], ans[cur]);
                if (--in[next] == 0) {
                    zeroInQue.push(next);
                }
            }
        }
        return ans;
    }
};
