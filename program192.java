
//import java.lang.*;
import java.util.Scanner;

class Bitwise {

    public void DisplayBinary(int iNo) {
        int iDigit = 0;
        while (iNo != 0) {
            iDigit = iNo % 2;
            System.out.print(iDigit);
            iNo = iNo / 2;
        }
        System.out.println();
    }

}

class program192 {
    public static void main(String[] args) {
        Scanner sobj = new Scanner(System.in);
        System.out.println("Enter Number");
        int Value = sobj.nextInt();

        Bitwise bobj = new Bitwise();
        bobj.DisplayBinary(Value);

    }
}
