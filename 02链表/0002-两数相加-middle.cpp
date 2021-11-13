// https://leetcode-cn.com/problems/add-two-numbers/
#include "ListNode.h"
using namespace std;

class Solution {
   public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* ans = new ListNode;
        ListNode *p = ans, *nx;
        int cnt = 0, sum;
        while (l1 != nullptr || l2 != nullptr || cnt > 0) {
            sum = (l1 == nullptr ? 0 : l1->val) +
                  (l2 == nullptr ? 0 : l2->val) + cnt;
            nx = new ListNode(sum % 10);
            cnt = sum / 10;
            p->next = nx;
            p = nx;
            l1 = (l1 == nullptr) ? nullptr : l1->next;
            l2 = (l2 == nullptr) ? nullptr : l2->next;
        }
        p = ans->next;
        delete ans;
        return p;
    }
};