import java.io.*;
import java.util.*;
import java.lang.*;

public class program328 {
    public static void main(String arg[]) {

        Scanner sobj = new Scanner(System.in);

        System.out.println("Enter number of rows");
        int irow = sobj.nextInt();

        System.out.println("Enter number of columns");
        int icol = sobj.nextInt();

        int Arr[][] = new int[irow][icol];

        System.out.println("ENter the elements");
        for (int i = 0; i < Arr.length; i++) {
            for (int j = 0; j < Arr[i].length; j++) {
                Arr[i][j] = sobj.nextInt();
            }
        }

        int iSum = 0;

        for (int i = 0; i < Arr.length; i++) {
            for (int j = 0; j < Arr[i].length; j++) {
                if (i == j) {
                    iSum = iSum + Arr[i][j];
                }

            }

        }

        System.out.println("Addition is:" + iSum);

    }
}
