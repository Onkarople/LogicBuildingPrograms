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
            System.out.println(Arr[i]);
        }
    }

    public void BubbleSort() {
        int i = 0;
        int j = 0;
        int temp = 0;

        for (i = 0; i < Arr.length; i++) {
            for (j = 0; j < Arr.length - i - 1; j++) {
                if (Arr[j] > Arr[j + 1]) {
                    temp = Arr[j];
                    Arr[j] = Arr[j + 1];
                    Arr[j + 1] = temp;
                }

            }
        }
    }

}

class program379 {

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
