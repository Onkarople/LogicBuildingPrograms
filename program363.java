import java.util.*;

//create table student(RID int,Name varchar(30),Salaray int);
//Database table/schema
class Student {
    public int RID;
    public String Name;
    public int Salary;

    private static int Generator;

    static {
        Generator = 0;
    }

    public Student(String str, int value) {
        this.RID = ++Generator;
        this.Name = str;
        this.Salary = value;

    }

    public void DisplayData() {
        System.out.println(this.RID + " " + this.Name + " " + this.Salary + " ");

    }

}

class DBMS {
    public LinkedList<Student> lobj;

    public DBMS() {
        lobj = new LinkedList<>();
    }

    public void StartDBMS() {
        System.out.println("Marvellous Customized DBMS Started Succesfully...");

    }
}

public class program363 {
    public static void main(String arg[]) {
        Scanner sobj = new Scanner(System.in);

        DBMS dobj = new DBMS();
        dobj.StartDBMS();

    }

}
