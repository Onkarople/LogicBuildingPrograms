import java.lang.*;
import java.util.*;

class program360 {
    public static void main(String arg[]) {
        Scanner sobj = new Scanner(System.in);

        System.out.println("Enter string");
        String str = sobj.nextLine();

        System.out.println("Eneter word that replace");
        String rplace = sobj.nextLine();

        System.out.println("Enter  word ");
        String newword = sobj.nextLine();

        String arr[] = str.split(" ");

        String newstr = new String();

        for (int i = 0; i < arr.length; i++) {
            if (arr[i].equals(rplace)) {
                newstr = newstr + " " + newword;
            } else {
                newstr = newstr + " " + arr[i] + " ";
            }
        }

        System.out.println(newstr);

    }
}