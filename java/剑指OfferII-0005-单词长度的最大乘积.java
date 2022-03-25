/*
 * @Author: SukiEva
 * @Date: 2022-03-20 20:16:42
 * @Description: https://github.com/SukiEva
 * わたし、気になります！
 */
class Solution {
    public int maxProduct(String[] words) {
        int[] bit = new int[words.length];
        int ans = 0;
        for (int i = 0; i < words.length; i++) {
            for (int j = 0; j < words[i].length(); j++)
                bit[i] |= 1 << (words[i].charAt(j) - 'a');
            for (int j = 0; j < i; j++) {
                if ((bit[i] & bit[j]) == 0) {
                    ans = Math.max(ans, words[i].length() * words[j].length());
                }
            }
        }
        return ans;
    }
}