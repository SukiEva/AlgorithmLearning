package solutions.java;

public class ValidPerfectSquare {
    public boolean isPerfectSquare(int x) {
        if (x == 0) {
            return true;
        }
        int l = 1, r = x + 1;
        while (l < r) {
            int m = l + ((r - l) >> 1);
            if (m < x / m) {
                l = m + 1;
            } else if (m > x / m) {
                r = m;
            } else {
                return x % m == 0;
            }
        }
        return false;
    }
}
