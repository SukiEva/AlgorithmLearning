/*
 * @Author: SukiEva
 * @Date: 2022-01-16 14:39:33
 * @Description: https://github.com/SukiEva
 * わたし、気になります！
 */
#include <bits/stdc++.h>

#include "include/ListNode.h"
#include "include/TreeNode.h"

using namespace std;

class Solution {
   public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return build(preorder, inorder, 0, preorder.size() - 1, 0,
                     inorder.size() - 1);
    }

    TreeNode* build(vector<int>& preorder, vector<int>& inorder, int pb, int pe,
                    int ib, int ie) {
        if (pb > pe) return nullptr;
        TreeNode* root = new TreeNode(preorder[pb]);
        int rootIndex = ib;
        while (inorder[rootIndex] != root->val) rootIndex++;
        root->left = build(preorder, inorder, pb + 1, pb + rootIndex - ib, ib,
                           rootIndex - 1);
        root->right = build(preorder, inorder, pb + rootIndex - ib + 1, pe,
                            rootIndex + 1, ie);
        return root;
    }
};