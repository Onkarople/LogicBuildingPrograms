import java.util.*;

//create table student(RID int,Name varchar(30),Salaray int);
//Database table/schema
class Student {
    public int RID;
    public String Name;
    public int Salary;

    public Student(int no, String str, int value) {
        this.RID = no;
        this.Name = str;
        this.Salary = value;

    }

}

public class program362 {
    public static void main(String arg[]) {
        Scanner sobj = new Scanner(System.in);

        Student obj = new Student(11, "onkar", 1000);

        System.out.println(obj.RID + " " + obj.Name + " " + obj.Salary + " ");
    }

}
