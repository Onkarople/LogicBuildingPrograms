import java.lang.*;
import java.util.*;

import javax.swing.Icon;

class Arryx {
    private int Arr[];

    public Arryx(int iNo) {
        Arr = new int[iNo];
    }

    public void Accept() {
        int iCnt = 0;
        Scanner sobj = new Scanner(System.in);
        System.out.println("Enter values");
        for (iCnt = 0; iCnt < Arr.length; iCnt++) {
            Arr[iCnt] = sobj.nextInt();
        }

    }

    public void Display() {
        int iCnt = 0;
        System.out.println("values are");
        for (iCnt = 0; iCnt < Arr.length; iCnt++) {
            System.out.println(Arr[iCnt]);
        }
    }

    public int Summation() {
        int iCnt = 0;
        int iSum = 0;

        for (iCnt = 0; iCnt < Arr.length; iCnt++) {
            iSum = iSum + Arr[iCnt];

        }
        return iSum;
    }
}

public class program144 {
    public static void main(String arg[]) {
        int iRet = 0;
        System.out.println("Enter the how many elements you want");

        Scanner sobj = new Scanner(System.in);
        int iValue = sobj.nextInt();

        Arryx obj = new Arryx(iValue);

        obj.Accept();
        obj.Display();

        iRet = obj.Summation();
        System.out.println("sum is:" + iRet);

        obj = null;

    }

}
