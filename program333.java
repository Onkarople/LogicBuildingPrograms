import MarvellousMatrix.Matrix;
import java.lang.*;
import java.util.*;

class Matrixx extends Matrix {

    public Matrixx(int a, int b) {
        super(a, b);
    }

    public int Maximum() {

        int iMax = Arr[0][0];
        for (int i = 0; i < iRow; i++) {
            for (int j = 0; j < iCol; j++) {
                if (Arr[i][j] > iMax) {
                    iMax = Arr[i][j];
                }
            }
        }
        return iMax;
    }
}

class program333 {
    public static void main(String arg[]) {
        Scanner sobj = new Scanner(System.in);

        System.out.println("Enter number of rows");
        int iRow = sobj.nextInt();

        System.out.println("Eneter number of coloumns");
        int iCol = sobj.nextInt();

        Matrixx mobj = new Matrixx(iRow, iCol);

        mobj.Accept();
        mobj.Dispaly();

        int iret = 0;
        iret = mobj.Maximum();
        System.out.println("Maximum element is:" + iret);

    }
}