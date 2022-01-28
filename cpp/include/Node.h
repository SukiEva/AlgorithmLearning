/*
 * @Author: SukiEva
 * @Date: 2022-01-28 14:10:27
 * @Description: https://github.com/SukiEva
 * わたし、気になります！
 */
#ifndef NODE_HEADER
#define NODE_HEADER

class Node {
   public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};

#endif