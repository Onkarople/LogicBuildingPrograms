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

    public int BiDirectionalSearch(int iNo) {
        int iStart = 0;
        int iEnd = Arr.length - 1;
        int ipos = -1;

        while (iStart <= iEnd) {
            if (Arr[iStart] == iNo) {
                ipos = iStart;
                break;
            }
            if (Arr[iEnd] == iNo) {
                ipos = iEnd;
                break;
            }
            iStart++;
            iEnd--;
        }

        return ipos;

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

    public int BinarySearch(int iNo) {
        int iStart = 0;
        int iEnd = Arr.length - 1;
        int iMiddle = 0;

        while (iStart < iEnd) {
            iMiddle = (iStart + (iEnd - iStart) / 2);

            if (Arr[iMiddle] == iNo) {
                break;
            }
            if (iNo > Arr[iMiddle]) {
                iStart = iMiddle + 1;
            }
            if (iNo < Arr[iMiddle]) {
                iEnd = iMiddle - 1;
            }
        }

        if (Arr[iMiddle] == iNo) {
            return iMiddle;
        } else {
            return -1;
        }

    }

}

class program377 {

    public static void main(String arg[]) {
        Scanner ssobj = new Scanner(System.in);
        System.out.println("Enter the size of array");

        int size = ssobj.nextInt();

        Searching obj = new Searching(size);
        obj.Accept();
        obj.Display();

        System.out.println("Enter element that search");
        int No = ssobj.nextInt();

        int iRet = obj.BiDirectionalSearch(No);

        if (iRet == -1) {
            System.out.println("There no such element");
        } else {
            System.out.println("Element is there at Index: " + iRet);
        }

    }

}
