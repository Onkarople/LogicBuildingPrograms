import java.util.*;

class Student {
    public String Name;
    public int Rid;
    public int Age;

    public Student(String name, int no1, int no2) {
        Name = name;
        Rid = no1;
        Age = no2;

    }

}

class program361 {
    public static void main(String arg[]) {

        Scanner sobj = new Scanner(System.in);

        List<Student> lobj = new LinkedList<>();

        while (true) {
            System.out.println("Enter the query");
            String query = sobj.nextLine();

            String Arr[] = query.split(" ");

            for (int i = 0; i < Arr.length; i++) {
                if (Arr[i].equalsIgnoreCase("Select")) {

                    for (Student s : lobj) {
                        System.out.println("Name: " + s.Name + " " + " Age:" + s.Age + " " + "Rid: " + s.Rid);
                    }

                } else if (Arr[i].equalsIgnoreCase("insert")) {
                    System.out.println("Enter name");
                    String name = sobj.nextLine();

                    System.out.println("Enter RID");
                    int no1 = sobj.nextInt();

                    System.out.println("Enter age");
                    int no2 = sobj.nextInt();

                    Student obj1 = new Student(name, no1, no2);
                    lobj.add(obj1);
                } else if (Arr[i].equalsIgnoreCase("remove")) {
                    System.out.println("Enter RID of student to remove");
                    int iremove = sobj.nextInt();

                    lobj.remove(iremove);
                    System.out.println("REmoved succesfully");
                }

                else if (Arr[i].equalsIgnoreCase("Exit")) {
                    return;
                }

                else {
                    System.out.println("Invalid query");
                    return;
                }
            }

        }

    }
}