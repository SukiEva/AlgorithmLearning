// https://leetcode-cn.com/problems/remove-linked-list-elements/submissions/
#include "ListNode.h"
using namespace std;

class Solution {
   public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* h = new ListNode();
        h->next = head;
        ListNode* p = h;
        while (p->next!=NULL) {
            if (p->next->val == val) {
                ListNode* tmp = p->next;
                p->next = p->next->next;
                delete tmp;
            }
            else p = p->next;
        }
        head = h->next;
        delete h;
        return head;
    }
};

ListNode* InitData() {
    vector<int> a = {1, 2, 6, 3, 4, 5, 6};
    int len = a.size();
    ListNode* L = new ListNode(a[0]);
    ListNode *s, *r = L;
    for (int i = 1; i < len; i++) {
        s = new ListNode(a[i]);
        r->next = s;
        r = s;
    }
    return L;
}

void output(ListNode* L){
    ListNode* p = L;
    while (p != NULL) {
        cout << p->val << " ";
        p = p->next;
    }
}

int main() {
    ListNode* data = InitData();
    Solution solution = Solution();
    ListNode* ans = solution.removeElements(data,6);
    output(ans);
    return 0;
}
