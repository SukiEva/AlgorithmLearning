// https://leetcode-cn.com/problems/delete-node-in-a-bst/
#include "../TreeNode.h"
using namespace std;

class Solution {
   public:
    bool NodeDelete(TreeNode* T, TreeNode* par) {
        TreeNode* tmp;
        // - 1. T为叶子结点，直接删除（没有父结点，将T置为NULL
        if (T->left == nullptr && T->right == nullptr) {
            if (par == T) {
                delete T;
                return false;
            }
            if (par->left == T)
                par->left = nullptr;
            else
                par->right = nullptr;
            delete T;
        }
        // - 2. T左子树为空，用右子树替代当前结点
        else if (T->left == nullptr) {
            tmp = T->right;
            T->val = tmp->val;
            T->left = tmp->left;
            T->right = tmp->right;
            delete tmp;
        }
        // - 2. T右子树为空，用左子树替代当前结点
        else if (T->right == nullptr) {
            tmp = T->left;
            T->val = tmp->val;
            T->left = tmp->left;
            T->right = tmp->right;
            delete tmp;
        }
        // - 3. T左右子树均不为空，用右子树的最小结点替代
        else {
            tmp = T;
            TreeNode* minnode = T->right;
            while (minnode->left != nullptr) {
                tmp = minnode;  // 记录最小结点的父结点
                minnode = minnode->left;
            }
            T->val = minnode->val;

            // ! 下面画图可以更好理解
            if (tmp != T)  // while执行，说明T的右子树有左子树
                // 让最小结点的右子树（可能存在）跟在其父结点的左边
                tmp->left = minnode->right;
            else  // T的右子树没有左子树，此时tmp=T
                tmp->right = minnode->right;  // 右子树的右子树上移
            delete minnode;
        }
        return true;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        TreeNode *p = root, *par = root;
        while (p != nullptr && key != p->val) {
            par = p;
            if (key < p->val)
                p = p->left;
            else
                p = p->right;
        }
        bool tag = true;
        if (p != nullptr) tag = NodeDelete(p, par);
        if (!tag) return nullptr;
        return root;
    }
};