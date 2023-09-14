import java.lang.*;
import java.util.*;
import java.io.*;

class program308 {
    public static void main(String arg[]) {
        Scanner sobj = new Scanner(System.in);

        System.out.println("Enter the string");
        String str = sobj.nextLine(); //

        String newstr = str.replaceAll("\\s+", " ");

        String newstr2 = newstr.trim();

        String arr[] = newstr2.split(" ");
        int iMax = 0;
        int ipos = 0;

        for (int i = 0; i < arr.length; i++) {

            if (arr[i].length() > iMax) {
                iMax = arr[i].length();
                ipos = i;

            }

        }
        System.out.println("Largest world is: " + arr[ipos]);

    }
}