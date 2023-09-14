import java.lang.*;
import java.util.*;
import java.io.*;

class program319 {
    public static void main(String arg[]) {
        Scanner sobj = new Scanner(System.in);

        System.out.println("Enter the first string");
        String str1 = sobj.nextLine();

        str1 = str1.toLowerCase();

        System.out.println("Enter the second  string");
        String str2 = sobj.nextLine();

        str2 = str2.toLowerCase();

        char arr[] = str1.toCharArray();
        char brr[] = str2.toCharArray();

        int Freaquency[] = new int[26];

        if (str1.length() != str2.length()) {
            System.out.println("String are not anagram as length are not equal");
            return;
        }

        int i = 0;

        for (i = 0; i < arr.length; i++) {
            Freaquency[arr[i] - 'a']++;
            Freaquency[brr[i] - 'a']--;
        }

        for (i = 0; i < Freaquency.length; i++) {
            if (Freaquency[i] != 0) {

                break;
            }

        }

        if (i == 26) {
            System.out.println("String are anagram");
        } else {
            System.out.println("String are not anagram");
        }

    }
}