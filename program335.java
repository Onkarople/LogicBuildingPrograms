import MarvellousMatrix.Matrix;
import java.lang.*;
import java.util.*;

class Matrixx extends Matrix {

    public Matrixx(int a, int b) {
        super(a, b);
    }

    public void SwapRow() {
        int iTemp = 0;

        for (int i = 0; i < iRow - 1; i += 2) {
            for (int j = 0; j < iCol; j++) {
                iTemp = Arr[i][j];
                Arr[i][j] = Arr[i + 1][j];
                Arr[i + 1][j] = iTemp;
            }
        }

    }
}

class program335 {
    public static void main(String arg[]) {
        Scanner sobj = new Scanner(System.in);

        System.out.println("Enter number of rows");
        int iRow = sobj.nextInt();

        System.out.println("Eneter number of coloumns");
        int iCol = sobj.nextInt();

        Matrixx mobj = new Matrixx(iRow, iCol);

        mobj.Accept();
        mobj.Dispaly();

        mobj.SwapRow();
        System.out.println("Data after swaping is :");
        mobj.Dispaly();

    }
}