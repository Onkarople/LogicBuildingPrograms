import java.lang.*;
import java.util.*;

class program350 {
    public static void main(String arg[]) {
        Scanner sobj = new Scanner(System.in);

        System.out.println("Enter the number");
        int iNo = sobj.nextInt();

        int iMask = 0x00000001;
        int result = 0;

        for (int i = 1; i <= 32; i++) {
            result = iNo & iMask;
            if (result == iMask) {
                System.out.println(i);
            }
            iMask = iMask << 1;
        }

    }
}