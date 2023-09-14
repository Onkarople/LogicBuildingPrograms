import MarvellousMatrix.Matrix;
import java.lang.*;
import java.util.*;

class Matrixx extends Matrix {

    public Matrixx(int a, int b) {
        super(a, b);
    }

    public void SwapCol() {
        int iTemp = 0;

        for (int i = 0; i < iRow; i++) {
            for (int j = 0; j < iCol - 1; j += 2) {
                iTemp = Arr[i][j];
                Arr[i][j] = Arr[i][j + 1];
                Arr[i][j + 1] = iTemp;
            }
        }

    }
}

class program336 {
    public static void main(String arg[]) {
        Scanner sobj = new Scanner(System.in);

        System.out.println("Enter number of rows");
        int iRow = sobj.nextInt();

        System.out.println("Eneter number of coloumns");
        int iCol = sobj.nextInt();

        Matrixx mobj = new Matrixx(iRow, iCol);

        mobj.Accept();
        mobj.Dispaly();

        mobj.SwapCol();
        System.out.println("Data after swaping is :");
        mobj.Dispaly();

    }
}