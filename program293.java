import java.lang.*;
import java.util.*;
import java.io.*;

class program293 {
    public static void main(String arg[]) {
        try {
            Scanner sobj = new Scanner(System.in);
            System.out.println("Eneter directory name");
            String foldarName = sobj.nextLine();

            File dobj = new File(foldarName);
            File allfiles[] = dobj.listFiles();
            String name;
            for (int i = 0; i < allfiles.length; i++) {
                name = allfiles[i].getName();
                if (name.endsWith(".txt")) {
                    System.out.println(name);
                }

            }
        } catch (Exception obj) {
            System.out.println(obj);
        }
    }
}