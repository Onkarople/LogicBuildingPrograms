import java.util.*;

interface MarvellousSort {
    public void Accept();

    public void Display();

    public void BubbleSort();
}

class Array implements MarvellousSort {
    public int Arr[];

    public Array(int iSize) {
        Arr = new int[iSize];
    }

    public void Accept() {
        Scanner sobj = new Scanner(System.in);
        System.out.println("Enter elements");
        for (int i = 0; i < Arr.length; i++) {
            Arr[i] = sobj.nextInt();
        }
    }

    public void Display() {
        System.out.println("Elments are");
        for (int i = 0; i < Arr.length; i++) {
            System.out.print(Arr[i] + " ");
        }
        System.out.println();
    }

    public void BubbleSort() {
        int i = 0;
        int j = 0;
        int temp = 0;
        boolean Swap = false;

        for (i = 0; i < Arr.length; i++) {
            Swap = false;
            for (j = 0; j < Arr.length - i - 1; j++) {
                if (Arr[j] > Arr[j + 1]) {
                    temp = Arr[j];
                    Arr[j] = Arr[j + 1];
                    Arr[j + 1] = temp;
                    Swap = true;
                }

            }
            System.out.println("pass:" + (i + 1));
            Display();
            if (Swap == false) {
                break;
            }
        }
    }

}

class program381 {

    public static void main(String arg[]) {
        Scanner ssobj = new Scanner(System.in);
        System.out.println("Enter the size of array");

        int size = ssobj.nextInt();

        Array aobj = new Array(size);
        aobj.Accept();
        aobj.Display();

        aobj.BubbleSort();

        System.out.println("Data after sorting");

        aobj.Display();

    }

}
