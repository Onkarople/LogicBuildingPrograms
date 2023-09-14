
//template 
import java.lang.*;
import java.util.*;

class Number {
    private int iNo;

    public void Accept() {
        Scanner sobj = new Scanner(System.in);
        System.out.println("Enter Number:");
        this.iNo = sobj.nextInt();
    }

    public void Display() {
        System.out.println("Value is" + this.iNo);
    }

}

public class program146 {
    public static void main(String arg[]) {
        Number nobj = new Number();

        nobj.Accept();
        nobj.Display();

    }
}
