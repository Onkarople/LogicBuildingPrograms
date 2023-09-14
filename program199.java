import java.lang.*;
import java.util.*;
//0000 0100 0000 0000 0000 0000 0000 0000 
//0     4   0    0    0   0    0   0

class Bitwise {
    public int OnBit(int iNo) {

        int iMask = 0X04000000;
        int iResult = 0;

        iResult = iNo | iMask;

        return iResult;

    }

}

class program199 {
    public static void main(String[] args) {
        Scanner sobj = new Scanner(System.in);

        System.out.println("Enter Number");
        int Value = sobj.nextInt();

        Bitwise bobj = new Bitwise();
        int bRet = bobj.OnBit(Value);
        System.out.println("Number is " + bRet);

    }
}
