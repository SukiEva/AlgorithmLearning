/*
 * @Author: SukiEva
 * @Date: 2022-03-21 12:54:03
 * @Description: https://github.com/SukiEva
 * わたし、気になります！
 */
#include <bits/stdc++.h>

#include "include/ListNode.h"
#include "include/TreeNode.h"

using namespace std;

class Leaderboard {
   private:
    unordered_map<int, int> player;
    multiset<int> board;

   public:
    Leaderboard() {}

    void addScore(int playerId, int score) {
        if (player.count(playerId)) {
            board.erase(board.find(player[playerId]));
            player[playerId] += score;
        } else
            player[playerId] = score;
        board.insert(player[playerId]);
    }

    int top(int K) {
        int ans = 0;
        int cnt = 0;
        for (auto it = board.rbegin(); cnt < K && it != board.rend();
             it++, cnt++)
            ans += *it;
        return ans;
    }

    void reset(int playerId) {
        if (player.count(playerId)) {
            board.erase(board.find(player[playerId]));
            player.erase(playerId);
        }
    }
};

/**
 * Your Leaderboard object will be instantiated and called as such:
 * Leaderboard* obj = new Leaderboard();
 * obj->addScore(playerId,score);
 * int param_2 = obj->top(K);
 * obj->reset(playerId);
 */