import java.lang.*;
import java.util.*;
import java.io.*;

class program317 {
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

        int Freaquency1[] = new int[26];
        int Freaquency2[] = new int[26];

        if (str1.length() != str2.length()) {
            System.out.println("String are not anagram as length are not equal");
            return;
        }

        int i = 0;

        for (i = 0; i < arr.length; i++) {
            Freaquency1[arr[i] - 'a']++;
        }

        for (i = 0; i < brr.length; i++) {
            Freaquency2[brr[i] - 'a']++;
        }

        for (i = 0; i < Freaquency1.length; i++) {
            if (Freaquency1[i] != Freaquency2[i]) {

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