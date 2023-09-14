import java.lang.*;
import java.util.*;
//0000 0000 0000 0000 0010 0000 0000 0000 
//0     0    0    0    2    0    0   0

class Bitwise {
    public int OnBit(int iNo) {

        int iMask = 0X00000008;
        int iResult = 0;

        iResult = iNo | iMask;

        return iResult;

    }

}

class program198 {
    public static void main(String[] args) {
        Scanner sobj = new Scanner(System.in);

        System.out.println("Enter Number");
        int Value = sobj.nextInt();

        Bitwise bobj = new Bitwise();
        int bRet = bobj.OnBit(Value);
        System.out.println("Number is " + bRet);

    }
}
