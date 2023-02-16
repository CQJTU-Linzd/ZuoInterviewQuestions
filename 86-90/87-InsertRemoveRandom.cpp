// 87 O(1)时间插入、删除、获取随机元素
class InsertRemoveRandom {
    unordered_map<int, int>keyIndexMap;
    unordered_map<int, int>indexKeyMap;
    int size;
public:
    InsertRemoveRandom() {
        this->size = 0;
    }

    void insert(int val) {
        if (!keyIndexMap.count(val)) {
            keyIndexMap[val] = size;
            indexKeyMap[size] = val;
            size++;
        }
    }
    
    void remove(int val) {
        if (keyIndexMap.count(val)) {
            int replaceNum = indexKeyMap[size - 1];
            int targetIndex = keyIndexMap[val];
            indexKeyMap[targetIndex] = replaceNum;
            keyIndexMap[replaceNum] = targetIndex;
            keyIndexMap.erase(val);
            indexKeyMap.erase(size - 1);
            size--;
        }
    }

    int random() {
        srand(time(0));
        int index = rand() % size;
        return indexKeyMap[index];
    }
};
