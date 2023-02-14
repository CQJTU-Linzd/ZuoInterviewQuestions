// 82 查寻明星
class FindTheCelebrity {
public:
    // knows(i,j)：i号人是否认识j号人
    // 系统提供的函数，不需要自己实现
    // 注意：如果i和j的值相等，返回false
    bool knows(int i, int j) {
        return true;
    }

    // 0~n-1号人
    // 明星：除了自己，所有人都认识他；但是，他不认识所有人
    int findCelebrity(int n) {
        // cand：可能成为明星的人
        int cand = 0;
        for (int i = 0; i < n; i++) {
            if (knows(cand, i)) {
                cand = i;
            }
        }
        // cand：唯一可能成为明星的人
        // 验证cand是不是明星
        // (1)cand是不是不认识所有人（cand右侧的人，他一定不认识）
        // 只需验证cand左侧的人
        for (int i = 0; i < cand; i++) {
            if (knows(cand, i)) {
                return -1;
            }
        }
        // (2)是不是所有人都认识cand
        for (int i = 0; i < n; i++) {
            if (!knows(i, cand)) {
                return -1;
            }
        }
        return cand;
    }
};
