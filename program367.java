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

    // insert data
    public void InsertData(String str, int ivalue) {
        Student sobj = new Student(str, ivalue);
        lobj.add(sobj);
    }

    // display without condition
    public void DisplayAll() {
        for (Student sref : lobj) {
            sref.DisplayData();
        }
    }

    // display by rid
    public void DisplaySpecific(int rid) {
        for (Student sref : lobj) {
            if (sref.RID == rid) {
                sref.DisplayData();
                break;
            }
        }
    }

    // display by name
    public void DisplaySpecific(String name) {
        for (Student sref : lobj) {
            if (name.equals(sref.Name)) {
                sref.DisplayData();

            }
        }
    }

    // delete specific
    public void DeleteSpecific(int rid) {
        int index = 0;
        for (Student sref : lobj) {
            if (sref.RID == rid) {
                lobj.remove(index);
                break;

            }
            index++;
        }
    }

    // delete by name
    public void DeleteSpecific(String name) {
        int index = 0;
        for (Student sref : lobj) {
            if (name.equals(sref.Name)) {
                lobj.remove(index);
                break;
            }
            index++;
        }
    }
}

public class program367 {
    public static void main(String arg[]) {
        Scanner sobj = new Scanner(System.in);

        DBMS dobj = new DBMS();
        dobj.StartDBMS();

        dobj.InsertData("onkar", 1000);
        dobj.InsertData("Shruti", 2000);
        dobj.InsertData("sachin", 3000);

        dobj.DisplaySpecific(2);
        dobj.DisplaySpecific("onkar");

        dobj.DeleteSpecific(2);
        dobj.DisplayAll();

        dobj.DeleteSpecific("sachin");
        dobj.DisplayAll();

    }

}
