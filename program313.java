import java.lang.*;
import java.util.*;
import java.io.*;

class program313 {
    public static void main(String arg[]) {
        Scanner sobj = new Scanner(System.in);

        System.out.println("Enter the string");
        String str = sobj.nextLine();

        str = str.toLowerCase();

        char arr[] = str.toCharArray();

        int Freaquency[] = new int[26];
        int i = 0;

        for (i = 0; i < arr.length; i++) {
            Freaquency[arr[i] - 'a']++;
        }

        for (i = 0; i < Freaquency.length; i++) {
            System.out.println(Freaquency[i]);
        }

    }
}