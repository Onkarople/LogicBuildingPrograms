import java.lang.*;
import java.util.*;
import java.io.*;

class program303 {
    public static void main(String arg[]) {
        Scanner sobj = new Scanner(System.in);

        System.out.println("Enter the string");
        String str = sobj.nextLine(); //

        char arr[] = str.toCharArray(); // property

        for (int i = 0; i < arr.length; i++) {
            System.out.println(arr[i]);
        }

    }
}