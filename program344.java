import java.lang.*;
import java.util.*;

class program344 {
    public static void main(String arg[]) {
        Scanner sobj = new Scanner(System.in);

        System.out.println("Enter Number");

        char Arr[] = (Integer.toString(sobj.nextInt())).toCharArray();

        for (int i = 0; i < Arr.length; i++) {
            for (int j = 0; j < Arr.length; j++) {
                System.out.print(Arr[j] + " ");
            }
            System.out.println();
        }
    }
}