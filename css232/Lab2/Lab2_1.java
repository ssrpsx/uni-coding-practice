
import java.util.Scanner;


public class Lab2_1 {

    static class Student {
        String name;
        int age;

        public Student(String name, int age) {
            this.name = name;
            this.age = age;
        }

        public Student() {
            this.name = "null";
            this.age = 0;
        }
    }

    public static void main(String[] args) {
        try(Scanner sc = new  Scanner(System.in))
        {
            System.out.print("Enter your Name: ");
            String name = sc.next();
            System.out.print("Enter your age: ");
            int age = sc.nextInt();
            sc.close();

            Student st = new Student(name, age);
            System.out.println("Student: " + st.name + ", Age: " + st.age);
        }
    }
}
