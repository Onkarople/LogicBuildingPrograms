//32 31 30 29 28 27 26 25 24 23 22 21 20 19 18 17 16 15 14 13 12 11 10 9 8 7 6 5 4 3 2 1 
//0   0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0 0 0 0 0 0 0 0 0 0 

//import java.lang.*;
import java.util.*;
//0000 0000 0000 0000 0000 0000 0000 0000 
//0     0     0    0    0   0    0    0

class Bitwise {
    public int ToggleBit(int iNo, int iPos) {

        if (iPos <= 0 || iPos > 32) {
            System.out.println("inavalid position");
            return 0;
        }

        int iMask = 0X00000001;
        int iResult = 0;

        iMask = iMask << (iPos - 1);

        iResult = iNo ^ iMask;

        return iResult;

    }

}

class program203 {
    public static void main(String[] args) {
        Scanner sobj = new Scanner(System.in);

        System.out.println("Enter Number");
        int Value = sobj.nextInt();

        System.out.println("Enter Position");
        int iPos = sobj.nextInt();

        Bitwise bobj = new Bitwise();
        int iRet = bobj.ToggleBit(Value, iPos);
        System.out.println("updated Number is " + iRet);

    }
}
