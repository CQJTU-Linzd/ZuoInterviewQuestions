#pragma once
#include<iostream>
using namespace std;
#include<vector>
#include<map>
#include<set>
#include<stack>
#include<queue>
#include<string>
#include<algorithm>
#include<numeric>
#include<unordered_set>
#include<unordered_map>

class TreeNode {
public:
    int val;
    bool save;
    TreeNode* left;
    TreeNode* right;
    TreeNode() {}
    TreeNode(int val) {
        this->val = val;
        this->left = nullptr;
        this->right = nullptr;
    }
    TreeNode(int val, bool s) {
        this->val = val;
        this->save = s;
        this->left = nullptr;
        this->right = nullptr;
    }
};
