import java.lang.*;
import java.util.*;
import java.io.*;

public class program287 {
    public static void main(String arg[]) {
        try {
            Scanner sobj = new Scanner(System.in);
            System.out.println("Please enter File name");

            String Filename = sobj.nextLine();

            File fobj = new File(Filename);
            if (fobj.exists()) {
                long size = fobj.length();
                System.out.println("file size is: " + size);

            } else {
                System.out.println("there is no such file");
            }

        } catch (Exception obj) {
            System.out.println(obj);
        }

    }

}
