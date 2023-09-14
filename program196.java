import java.lang.*;
import java.util.*;
//0000 0000 0000 0000 0010 0000 0000 0000 
//0     0    0    0    0     0    0   0

class Bitwise {
    public boolean CheckBit(int iNo) {

        int iResult = 0;
        int iMask = 0X00100000; // 1048576;

        iResult = iNo & iMask;

        if (iResult == 0) {
            return false;
        } else {
            return true;
        }

    }

}

class program196 {
    public static void main(String[] args) {
        Scanner sobj = new Scanner(System.in);

        System.out.println("Enter Number");
        int Value = sobj.nextInt();

        Bitwise bobj = new Bitwise();
        boolean bRet = bobj.CheckBit(Value);

        if (bRet == true) {
            System.out.println("Bit is on");
        } else {
            System.out.println("Bit is off");
        }
    }
}
