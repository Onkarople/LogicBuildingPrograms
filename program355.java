import java.lang.*;
import java.util.*;

class program355 {
    public static void main(String arg[]) {
        Scanner sobj = new Scanner(System.in);

        System.out.println("Enter string");
        String str = sobj.nextLine();
        str = str.replaceAll("\\s", "");

        char Arr[] = str.toCharArray();

        HashMap<Character, Integer> hobj = new HashMap<>();

        int Frequency = 0;

        for (char ch : Arr) // for(int i=;i<Arr.lemgth;i++)
        {
            if (hobj.containsKey(ch)) {
                Frequency = hobj.get(ch);

                hobj.put(ch, Frequency + 1);

            } else {
                hobj.put(ch, 1);
            }
        }
        System.out.println(hobj);

    }
}