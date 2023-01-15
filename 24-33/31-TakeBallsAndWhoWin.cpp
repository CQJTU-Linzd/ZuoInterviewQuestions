// 拿球
class WinBalls {
public:
    // balls奇数 每人每轮拿1~3个
    // 甲先乙后
    string WhoWin(int balls) {
        return process(0, balls, 0, 0);
    }
    // turn 谁的回合 turn=0，甲的回合；turn=1，乙的回合
    // jia: 之前甲已经拿了几个球
    // yi: 之前乙已经拿了几个球
    string process(int turn, int rest, int jia, int yi) {
        if (rest == 0) {
            return jia % 2 == 0 ? "甲" : "乙";
        }
        if (turn == 0) {
            for (int pick = 1; pick <= min(3, rest); pick++) {
                string next = process(1, rest - pick, jia + pick, yi);
                if (next == "甲") {
                    return "甲";
                }
            }
            return "乙";
        } else {
            for (int pick = 1; pick <= min(3, rest); pick++) {
                string next = process(0, rest - pick, jia, yi + pick);
                if (next == "乙") {
                    return "乙";
                }
            }
            return "甲";
        }
    }
};
