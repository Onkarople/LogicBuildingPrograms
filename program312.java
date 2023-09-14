import java.lang.*;
import java.util.*;
import java.io.*;

class program311 {
    public static void main(String arg[]) {
        Scanner sobj = new Scanner(System.in);

        System.out.println("Enter the string");
        String str = sobj.nextLine();

        System.out.println("Enter the string");
        String str2 = sobj.nextLine();

        char arr[] = str.toCharArray();
        char arr1[] = str2.toCharArray();

        int Freaquency[] = new int[26];
        int Freaquency1[] = new int[26];

        int i = 0;
        int j = 0;

        for (i = 0, j = 0; i < arr.length; i++, j++) {
            Freaquency[arr[i] - 'a']++;
            Freaquency1[arr1[j] - 'a']++;
        }

        for (i = 0; i < Freaquency.length; i++) {
            if (Freaquency[i] == Freaquency1[i]) {
                continue;
            }

        }

    }
}