import java.lang.*;
import java.util.*;

class program349 {
    public static void main(String arg[]) {
        Scanner sobj = new Scanner(System.in);

        System.out.println("Enter the number");
        int iNo = sobj.nextInt();

        System.out.println("Enter starting point");
        int iStart = sobj.nextInt();

        System.out.println("Enter ending point");
        int iEnd = sobj.nextInt();

        if ((iStart < 1 && iStart > 32) || (iEnd < 1 && iEnd > 32)) {
            System.out.println("incorrect points");
            return;

        }

        long iMask1 = 0xffffffff;
        long imask2 = 0xffffffff;

        iMask1 = iMask1 << (iStart - 1);
        imask2 = imask2 >> (32 - iEnd);

        long iMask3 = iMask1 & imask2;
        long result = 0;

        result = iNo & iMask3;

        if (result == iNo) {
            System.out.println("bits are on in that range");
        } else {
            System.out.println("bits are off");
        }
    }
}