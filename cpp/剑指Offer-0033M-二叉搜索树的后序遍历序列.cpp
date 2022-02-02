/*
 * @Author: SukiEva
 * @Date: 2022-02-02 21:10:43
 * @Description: https://github.com/SukiEva
 * わたし、気になります！
 */
#include <bits/stdc++.h>

#include "include/ListNode.h"
#include "include/TreeNode.h"

using namespace std;

class Solution {
   private:
    bool vertify(vector<int>& postorder, int begin, int end) {
        if (begin >= end) return true;
        int p = begin;
        while (postorder[p] < postorder[end]) p++;
        for (int i = p; i <= end; i++)
            if (postorder[i] < postorder[end]) return false;
        return vertify(postorder, begin, p - 1) &&
               vertify(postorder, p, end - 1);
    }

   public:
    bool verifyPostorder(vector<int>& postorder) {
        return vertify(postorder, 0, postorder.size() - 1);
    }
};

// 写繁了
class Solution2 {
   private:
    bool vertify(vector<int>& postorder, vector<int>& inorder, int pb, int pe,
                 int ib, int ie) {
        if (pb > pe) return true;
        int root = postorder[pe];
        int rootIndex = ib;
        for (int i = ib; i <= ie; i++) {
            if (inorder[i] == root) {
                rootIndex = i;
                break;
            }
        }
        for (int i = pe - (ie - rootIndex); i <= pe - 1; i++)
            if (postorder[i] < root) return false;
        for (int i = pb; i <= pe - (ie - rootIndex) - 1; i++)
            if (postorder[i] > root) return false;
        return vertify(postorder, inorder, pe - (ie - rootIndex), pe - 1,
                       rootIndex + 1, ie) &&
               vertify(postorder, inorder, pb, pe - (ie - rootIndex) - 1, ib,
                       rootIndex - 1);
    }

   public:
    bool verifyPostorder(vector<int>& postorder) {
        vector<int> inorder = postorder;
        sort(inorder.begin(), inorder.end());
        return vertify(postorder, inorder, 0, postorder.size() - 1, 0,
                       inorder.size() - 1);
    }
};