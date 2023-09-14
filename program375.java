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

class Searching extends Array {

    public Searching(int iSize) {
        super(iSize);
    }

    public int LinearSearch(int iNo) {

        int iindex = 0;
        int i = 0;
        for (i = 0; i < Arr.length; i++) {
            if (iNo == Arr[i]) {
                iindex = i;
                break;
            }
        }

        if (i == Arr.length) {
            return -1;
        } else {
            return iindex;
        }

    }

}

class program375 {

    public static void main(String arg[]) {
        Scanner ssobj = new Scanner(System.in);
        System.out.println("Enter the size of array");

        int size = ssobj.nextInt();

        Searching obj = new Searching(size);
        obj.Accept();
        obj.Display();

        System.out.println("Enter element that search");
        int No = ssobj.nextInt();

        int iRet = obj.LinearSearch(No);

        if (iRet == -1) {
            System.out.println("There no such element");
        } else {
            System.out.println("Element is there at Index: " + iRet);
        }

    }
}
