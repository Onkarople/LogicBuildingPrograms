import java.lang.*;
import java.io.*;
import java.util.*;

class Matrix {
    public int iRow;
    public int iCol;
    public int Arr[][];

    public Matrix(int a, int b) {
        this.iRow = a;
        this.iCol = b;

        Arr = new int[iRow][iCol];

    }

    protected void finalize() {
        Arr = null;
        System.gc();
    }

    public void Accept() {
        Scanner sobj = new Scanner(System.in);
        System.out.println("Enter the elements");
        for (int i = 0; i < Arr.length; i++) {
            for (int j = 0; j < Arr[i].length; j++) {
                Arr[i][j] = sobj.nextInt();
            }
        }

    }

    public void Dispaly() {
        System.out.println("Elements are");
        for (int i = 0; i < Arr.length; i++) {
            for (int j = 0; j < Arr[i].length; j++) {
                System.out.print(Arr[i][j] + " ");
            }
            System.out.println();
        }

    }
}

class program331 {
    public static void main(String arg[]) {
        Scanner sobj = new Scanner(System.in);

        System.out.println("Enter number of rows");
        int iRow = sobj.nextInt();

        System.out.println("Eneter number of coloumns");
        int iCol = sobj.nextInt();

        Matrix obj = new Matrix(iRow, iCol);

        obj.Accept();
        obj.Dispaly();

    }
}