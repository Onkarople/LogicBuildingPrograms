import java.lang.*;
import java.util.*;

class FactorialR {
    public int iNo;
    public int iFact;

    public FactorialR() {
        iNo = 0;
        iFact = 1;
    }

    public void Accept() {
        System.out.println("Enter Number");
        Scanner sobj = new Scanner(System.in);

        iNo = sobj.nextInt();
    }

    public int Fact() {
        if (iNo > 0) {
            iFact = iFact * iNo;
            iNo--;
            Fact();
        }
        return iFact;
    }
}

class Demo {
    public static void main(String args[]) {
        FactorialR obj = new FactorialR();
        int iret = 0;
        obj.Accept();
        iret = obj.Fact();
        System.out.println(iret);

    }
}
