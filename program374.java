import java.util.*;

class Array {
    public int Arr[];

    public Array(int iSize) {
        Arr = new int[iSize];
    }

    protected void finalize() {
        Arr = null;
        System.gc();
    }

    public void Accept() {

        Scanner sobj = new Scanner(System.in);
        System.out.println("Enter elements");
        for (int i = 0; i < Arr.length; i++) {
            Arr[i] = sobj.nextInt();
        }
    }

    public void Display() {
        System.out.println("Elements are");
        for (int i = 0; i < Arr.length; i++) {
            System.out.println(Arr[i]);

        }

    }
}

public class program374 {

    public static void main(String arg[]) {
        Array obj = new Array(5);
        obj.Accept();
        obj.Display();
    }

}
