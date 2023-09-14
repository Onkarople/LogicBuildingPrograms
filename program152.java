import java.util.*;

class pattern {
    private int iRow, iCol;

    public pattern(int a, int b) {
        iRow = a;
        iCol = b;
    }

    public void Display() {
        int i = 0, j = 0;
        for (i = 1; i <= iRow; i++) {
            for (j = 1; j <= iCol; j++) {
                System.out.print(" * ");
            }
            System.out.println();
        }
    }
}

class program152 {
    public static void main(String arg[])

    {
        pattern obj = new pattern(4, 4);
        obj.Display();
    }
}