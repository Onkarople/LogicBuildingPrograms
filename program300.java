import java.lang.*;
import java.util.*;

import java.io.*;

class program300 {
    public static void main(String arg[]) {
        try {
            Scanner sobj = new Scanner(System.in);

            System.out.println("Enter packed file name");
            String packFileName = sobj.nextLine();

            File fobj = new File(packFileName);

            FileInputStream fiobj = new FileInputStream(fobj);

            byte Headerarray[] = new byte[100];

            fiobj.read(Headerarray, 0, 100);

            String HeaderString = new String(Headerarray);
            System.out.println(HeaderString);

            String tokens[] = HeaderString.split(" ");
            System.out.println("File Name:" + tokens[0]);
            System.out.println("File Size:" + tokens[1]);

            File fobjnew = new File(tokens[0]);
            boolean bobj = fobjnew.createNewFile();

        } catch (Exception obj) {
            System.out.println(obj);
        }
    }
}