// 抽牌获胜概率
// 1-10的牌等概率随机抽一张，下一次抽还是1-10
// 当累加和<17，你会一直抽牌
// 当累加和>=17且<21，获胜
// 当累加和>21，失败
class DrowCardsWin {
public:
    double probability() {
        return process(0);
    }
    double process(int cur) {
        if (cur >= 17 && cur < 21) {
            return 1.0;
        }
        if (cur >= 21) {
            return 0.0;
        }
        double ans = 0.0;
        for (int i = 1; i <= 10; i++) {
            ans += 0.1 * process(cur + i);
        }
        return ans;
    }

    // 扩展版
    // 1-N的牌等概率随机抽一张，下一次抽还是1-N
    // 当累加和<a，你会一直抽牌
    // 当累加和>=a且<b，获胜
    // 当累加和>b，失败
    double p2(int N, int a, int b) {
        if (N < 1 || a >= b || a < 0 || b < 0) {
            return 0.0;
        }
        if (b - a >= N) {
            return 1.0;
        }
        return f2(N, a, b, 0);
    }
    double f2(int N, int a, int b, int cur) {
        if (cur >= a && cur < b) {
            return 1.0;
        }
        if (cur >= b) {
            return 0.0;
        }
        double ans = 0.0;
        for (int i = 1; i <= N; i++) {
            ans += f2(N, a, b, cur + i);
        }
        return ans / N;
    }
};
