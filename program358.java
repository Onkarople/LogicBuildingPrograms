import java.lang.*;
import java.util.*;

class program358 {
    public static void main(String arg[]) {
        Scanner sobj = new Scanner(System.in);

        System.out.println("Enter string");
        String str = sobj.nextLine();

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
        Set<Character> setobj = hobj.keySet();
        int iMax = 0;
        char c = '\0';

        for (char value : setobj) {

            if (hobj.get(value) > iMax) {
                iMax = hobj.get(value);
                c = value;
            }
        }
        System.out.println(c + " occurs maimum times: " + iMax);
    }
}