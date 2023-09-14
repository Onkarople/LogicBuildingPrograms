import java.lang.*;
import java.util.*;
import java.io.*;

class program322 {
    public static void main(String arg[]) {
        Scanner sobj = new Scanner(System.in);

        System.out.println("Enter the first string");
        String str1 = sobj.nextLine();

        System.out.println("Enter the second  string");
        String str2 = sobj.nextLine();

        char arr[] = (str1.toLowerCase()).toCharArray();
        char brr[] = (str2.toLowerCase()).toCharArray();

        Arrays.sort(arr);
        Arrays.sort(brr);

        if (Arrays.equals(arr, brr) == true) {
            System.out.println("Strings are anaggram");
        } else {
            System.out.println("Not anagram");
        }

    }
}