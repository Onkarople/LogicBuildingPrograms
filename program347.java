import java.lang.*;
import java.util.*;

class program347 {
    public static void main(String arg[]) {
        Scanner sobj = new Scanner(System.in);

        System.out.println("Enter the number");
        int iNo = sobj.nextInt();

        int iMask = 0x0000000f;
        int result = 0;

        result = iNo & iMask;

        if (result == iMask) {
            System.out.println("First nibble is completely on");
        } else {
            System.out.println("First nibble is off");
        }
    }
}