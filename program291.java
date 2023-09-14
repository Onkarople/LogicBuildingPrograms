import java.lang.*;
import java.util.*;
import java.io.*;

public class program291 {
    public static void main(String arg[]) {
        try {
            Scanner sobj = new Scanner(System.in);
            System.out.println("Please enter existing  File name");

            String Filename = sobj.nextLine();

            File fobj = new File(Filename);
            System.out.println("enter new file to cretae");
            String newfile = sobj.nextLine();

            File fobjn = new File(newfile);
            boolean bobj = fobjn.createNewFile();

            if (fobj.exists()) {
                FileInputStream fiobj = new FileInputStream(fobj);
                FileOutputStream foobj = new FileOutputStream(fobjn);
                byte buffer[] = new byte[100];
                int ret = 0;
                while ((ret = fiobj.read(buffer)) != -1) {
                    foobj.write(buffer, 0, ret);
                }

            } else {
                System.out.println("there is no such file");
            }

        } catch (IOException obj) {
            System.out.println(obj);
        }

    }

}
