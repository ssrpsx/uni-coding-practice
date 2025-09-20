class Student {
    String name;
    int age;

    public Student(String name, int age)
    {
        this.name = name;
        this.age = age;
    }

    public Student()
    {
        this.name = "Unknown";
        this.age = 0;
    }

    public void display()
    {
        System.out.println("Name: " + name + ", Age: " + age);
    }
}

public class Lab3_1 {

    public static void main(String[] args) {
        Student s1 = new Student("Alice", 20);
        Student s2 = new Student();

        s1.display();
        s2.display();
    }
}
