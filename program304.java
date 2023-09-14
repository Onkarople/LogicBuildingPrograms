import java.lang.*;
import java.util.*;
import java.io.*;

class program304 {
    public static void main(String arg[]) {
        Scanner sobj = new Scanner(System.in);

        System.out.println("Enter the string");
        String str = sobj.nextLine(); //

        char arr[] = str.toCharArray(); // property
        int iCnt = 0;

        for (int i = 0; i < arr.length; i++) {
            if (arr[i] >= 'a' && arr[i] <= 'z') {
                iCnt++;
            }
        }
        System.out.println("Number of small case letter are:" + iCnt);

    }
}