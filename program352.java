import java.lang.*;
import java.util.*;

class program352 {
    public static void main(String arg[]) {
        Scanner sobj = new Scanner(System.in);

        System.out.println("Enter Firts number");
        int iNo1 = sobj.nextInt();

        System.out.println("Enter second number");
        int iNo2 = sobj.nextInt();

        int iNo = iNo1 & iNo2;

        int iMask = 0x00000001;
        int result = 0;
        int iCnt = 0;

        for (int i = 1; i <= 32; i++) {
            result = iNo & iMask;
            if (result == iMask) {
                iCnt++;
            }
            iMask = iMask << 1;
        }

        System.out.println("Number of ON bits are:" + iCnt);

    }
}