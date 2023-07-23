package infrastructure.util;

import infrastructure.pojo.ListNode;
import infrastructure.pojo.TreeNode;

import java.lang.reflect.Array;
import java.util.Arrays;

/**
 * 万能输出
 */
public class Printer {
    public static void print() {
        print("Hello world!");
    }

    public static <T> void print(T x) {
        if (x.getClass().isArray()) {
            Object[] array = object2Array(x);
            System.out.println(Arrays.deepToString(array));
        } else {
            System.out.println(x);
        }
    }

    public static void print(TreeNode root) {
        BTreePrinter.print(root);
    }

    public static void print(ListNode head) {
        if (head == null) {
            return;
        }
        while (head != null) {
            System.out.print(head.val + "->");
            head = head.next;
        }
        System.out.print("NULL");
    }

    private static Object[] object2Array(Object x){
        if (x.getClass().isArray()) {
            int length = Array.getLength(x);
            Object[] array = new Object[length];
            for (int i = 0; i < length; i++) {
                array[i] = Array.get(x, i);
                if (array[i].getClass().isArray()){
                    array[i] = object2Array(array[i]);
                }
            }
            return array;
        }
        return new Object[0];
    }
}
