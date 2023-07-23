package solutions.java;

public class Sqrtx {
    public int mySqrt(int x) {
        if (x == 0) {
            return 0;
        }
        int l = 1, r = x;
        while (l < r) {
            int m = l + ((r - l) >> 1);
            if (m < x / m) {
                l = m + 1;
            } else if (m > x / m) {
                r = m;
            } else {
                return m;
            }
        }
        while (l > x / l) {
            l--;
        }
        return l;
    }
}