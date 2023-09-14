import java.lang.*;
import java.util.*;

class program345 {
    public static void main(String arg[]) {
        Scanner sobj = new Scanner(System.in);

        System.out.println("Enter Number");

        char Arr[] = (Integer.toString(sobj.nextInt())).toCharArray();

        for (int i = Arr.length - 1; i >= 0; i--) {
            for (int j = 0; j <= i; j++) {
                System.out.print(Arr[j] + " ");
            }
            System.out.println();
        }
    }
}