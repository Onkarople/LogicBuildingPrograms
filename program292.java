import java.lang.*;
import java.util.*;
import java.io.*;

class program292 {
    public static void main(String arg[]) {
        try {
            Scanner sobj = new Scanner(System.in);
            System.out.println("Eneter directory name");
            String foldarName = sobj.nextLine();

            File dobj = new File(foldarName);
            File allfiles[] = dobj.listFiles();
            for (int i = 0; i < allfiles.length; i++) {
                System.out.println(allfiles[i].getName());
            }
        } catch (Exception obj) {
            System.out.println(obj);
        }
    }
}