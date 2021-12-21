/*
 * @Author: SukiEva
 * @Date: 2021-12-21 14:27:23
 * @Description: https://github.com/SukiEva
 * わたし、気になります！
 */
#include <bits/stdc++.h>

#include "include/ListNode.h"
#include "include/TreeNode.h"

using namespace std;

class Solution {
   public:
    TreeNode* traversal(vector<int>& inorder, vector<int>& postorder,
                        int inorderBegin, int inorderEnd, int postorderBegin,
                        int postorderEnd) {
        if (postorderBegin >= postorderEnd) return nullptr;
        TreeNode* root = new TreeNode(postorder[postorderEnd - 1]);
        if (postorderEnd - postorderBegin == 1) return root;  // 叶子
        int rootIndex;
        for (int i = inorderBegin; i < inorderEnd; i++) {
            if (inorder[i] == postorder[postorderEnd - 1]) {
                rootIndex = i;
                break;
            }
        }
        root->left = traversal(inorder, postorder, inorderBegin, rootIndex,
                               postorderBegin,
                               rootIndex + postorderBegin - inorderBegin);
        root->right = traversal(inorder, postorder, rootIndex + 1, inorderEnd,
                                rootIndex + postorderBegin - inorderBegin,
                                postorderEnd - 1);
        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if (postorder.empty() || inorder.empty()) return nullptr;
        return traversal(inorder, postorder, 0, inorder.size(), 0,
                         postorder.size());
    }
};