// https://leetcode-cn.com/problems/longest-common-prefix/
#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int nx[205];
    void getnx(string x) {
        int m = x.size();
        int j = nx[0] = -1;
        int i = 0;
        while (i < m) {
            while (j != -1 && x[i] != x[j]) j = nx[j];
            if (x[++i] == x[++j])
                nx[i] = nx[j];
            else
                nx[i] = j;
        }
    }

    int strStr(string haystack, string needle) {
        // getnx(needle);
        int n = haystack.size(), m = needle.size();
        int i = 0, j = 0;
        while (i < n && j < m) {
            while (j != -1 && haystack[i] != needle[j]) j = nx[j];
            i++, j++;
        }
        if (j == m)
            return i - j;
        else
            return -1;
    }

    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 1) return strs[0];
        string p = strs[0];
        getnx(p);
        int len = p.size();
        int si = strs.size();
        if (len == 0) return "";
        for (int l = len; l >= 1; l--) {
            string t = p.substr(0, l);
            cout<<t<<endl;
            int cnt = 0;
            for (string i : strs) {
                if (strStr(i, t) !=0)
                    break;
                else
                    cnt++;
            }
            if (cnt == si) return t;
        }
        return "";
    }
};