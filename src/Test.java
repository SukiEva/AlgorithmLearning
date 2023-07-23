import static infrastructure.util.Printer.print;

import infrastructure.util.Inputer;
import solutions.java.SquaresOfASortedArray;

import java.io.FileInputStream;
import java.io.FileNotFoundException;

public class Test {
    static {
        try {
            System.setIn(new FileInputStream("./input.txt"));
        } catch (FileNotFoundException e) {
            print("input.txt not found");
        }
    }

    public static void main(String[] args) {
        var nums = Inputer.nextArray();
        var solution = new SquaresOfASortedArray();
        print(solution.sortedSquares(nums));
    }
}
