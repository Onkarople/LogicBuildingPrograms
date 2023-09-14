import java.lang.*;
import java.util.*;

import java.io.*;

class program296 {
    public static void main(String arg[]) {
        try {
            Scanner sobj = new Scanner(System.in);

            System.out.println("Eneter directory name");
            String foldarName = sobj.nextLine();

            File dobj = new File(foldarName);

            File allfiles[] = dobj.listFiles();

            File fobj = new File("Combine.txt");
            boolean bobj = fobj.createNewFile();

            FileOutputStream writerobj = new FileOutputStream(fobj);

            FileInputStream readerobj = null;
            int ret = 0;
            String name1;
            byte buffer[] = new byte[100];

            for (int i = 0; i < allfiles.length; i++) {

                name1 = allfiles[i].getName();

                if (name1.endsWith(".txt")) {

                    name1 = name1 + " " + (allfiles[i].length());

                    for (int j = name1.length(); j < 100; j++) {
                        name1 = name1 + " ";
                    }

                    byte namearray[] = name1.getBytes();
                    writerobj.write(namearray, 0, namearray.length);

                    readerobj = new FileInputStream(allfiles[i]);

                    while ((ret = readerobj.read(buffer)) != -1) {
                        writerobj.write(buffer, 0, ret);
                    }
                    readerobj.close();
                }

            }
        } catch (Exception obj) {
            System.out.println(obj);
        }
    }
}