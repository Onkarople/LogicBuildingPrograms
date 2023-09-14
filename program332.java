import MarvellousMatrix.Matrix;
import java.lang.*;
import java.util.*;

class program332 {
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