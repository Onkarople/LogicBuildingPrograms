import java.lang.*;
import java.nio.charset.StandardCharsets;
import java.util.*;
import java.io.*;

public class program289 {
    public static void main(String arg[]) {
        try {
            Scanner sobj = new Scanner(System.in);
            System.out.println("Please enter File name");

            String Filename = sobj.nextLine();

            File fobj = new File(Filename);
            if (fobj.exists()) {
                FileInputStream fiobj = new FileInputStream(fobj);
                byte buffer[] = new byte[100];
                int ret = 0;
                while ((ret = fiobj.read(buffer)) != -1) {
                    String string = new String(buffer, StandardCharsets.UTF_8);
                    System.out.println(string);
                }

            } else {
                System.out.println("there is no such file");
            }

        } catch (IOException obj) {
            System.out.println(obj);
        }

    }

}
