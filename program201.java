//32 31 30 29 28 27 26 25 24 23 22 21 20 19 18 17 16 15 14 13 12 11 10 9 8 7 6 5 4 3 2 1 
//0   0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0 0 0 0 0 0 0 0 0 0 

//import java.lang.*;
import java.util.*;
//0000 0000 0000 0000 0000 0000 0000 0000 
//0     0     0    0    0   0    0    0

class Bitwise {
    public int OnBit(int iNo) {

        int iMask = 0X00000048;
        int iResult = 0;

        iResult = iNo ^ iMask;

        return iResult;

    }

}

class program201 {
    public static void main(String[] args) {
        Scanner sobj = new Scanner(System.in);

        System.out.println("Enter Number");
        int Value = sobj.nextInt();

        Bitwise bobj = new Bitwise();
        int bRet = bobj.OnBit(Value);
        System.out.println("Number is " + bRet);

    }
}
