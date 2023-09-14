
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

        Scanner scanobj = new Scanner(System.in);
        String Query = "";

        while (true) {
            System.out.print("Marvellus DBMS console->");
            Query = scanobj.nextLine();

            String tokens[] = Query.split(" ");
            int QuerySize = tokens.length;

            if (QuerySize == 1) {
                if ("help".equals(tokens[0])) {
                    System.out.println("this application is used to demonstrates customized DBMS");
                    System.out.println("Exit:Terminate DBMS");
                    System.out.println("Display all data:Select * from student");
                    System.out.println("Insert data:Insert into  student name salaray");
                } else if ("Exit".equals(tokens[0])) {
                    System.out.println("Tahnk you");
                    break;
                }
            } else if (QuerySize == 2) {

            } else if (QuerySize == 4) {
                if ("select".equals(tokens[0])) {
                    if ("*".equals(tokens[1])) {
                        DisplayAll();
                    }
                }
            }

            else if (QuerySize == 5) {
                if ("Insert".equals(tokens[0])) {
                    InsertData(tokens[3], Integer.parseInt(tokens[4]));
                }
            }

        }

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

    public void AggregateMax() {
        int iMax = 0;
        Student temp = null;
        for (Student sref : lobj) {
            if (sref.Salary > iMax) {
                iMax = sref.Salary;
                temp = sref;
            }
        }
        System.out.println(" formation of student having maximum salaray:");
        temp.DisplayData();
    }

    public void AggregateMin() {
        int iMin = lobj.getFirst().Salary;
        Student temp = lobj.getFirst();
        for (Student sref : lobj) {
            if (sref.Salary < iMin) {
                iMin = sref.Salary;
                temp = sref;
            }
        }
        System.out.println("formation of student having minimum salaray:");
        temp.DisplayData();
    }

    public void AggregateSum() {
        long iSum = 0;

        for (Student sref : lobj) {
            iSum = iSum + sref.Salary;
        }

        System.out.println("Sumation of salaries  is:" + iSum);

    }

    public void AggregateAvg() {
        int iSum = 0;
        int iavg = 0;

        for (Student sref : lobj) {

            iSum = iSum + sref.Salary;
        }
        iavg = iSum / lobj.size();

        System.out.println("Avarage salary is :" + iavg);

    }

    public void AggregateCount() {
        System.out.println("Count is:" + lobj.size());
    }

}

public class program371 {
    public static void main(String arg[]) {
        Scanner sobj = new Scanner(System.in);

        DBMS dobj = new DBMS();
        dobj.StartDBMS();

        /*
         * dobj.InsertData("onkar", 2000);
         * dobj.InsertData("Shruti", 3000);
         * dobj.InsertData("sachin", 1000);
         * dobj.InsertData("suraj", 10000);
         * dobj.InsertData("mayur", 8000);
         * dobj.InsertData("ganesh", 9000);
         * 
         * dobj.DisplayAll();
         * 
         * // dobj.DisplaySpecific(2);
         * // dobj.DisplaySpecific("onkar");
         * 
         * // dobj.DeleteSpecific(2);
         * 
         * // dobj.DeleteSpecific("sachin");
         * dobj.AggregateMax();
         * dobj.AggregateMin();
         * dobj.AggregateSum();
         * dobj.AggregateAvg();
         * dobj.AggregateCount();
         */

    }

}
