import java.lang.*;
import java.util.*;

class program346 {
    public static void main(String arg[]) {
        Scanner sobj = new Scanner(System.in);

        System.out.println("Enter Number");
        int no = sobj.nextInt();

        int iDigit = 0;
        int iSum = 0;

        while (true) // while(no>10)
        {

            while (no != 0) {

                iDigit = no % 10;
                iSum = iSum + iDigit;
                no = no / 10;

            }
            no = iSum;
            iSum = 0;
            if (no < 10) {
                break;
            }

        }

        System.out.println(no);

    }
}