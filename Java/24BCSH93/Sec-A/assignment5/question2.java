/*  Q2. We need to develop a model of students and teachers in an application. We can define a super class called Person to store common properties
        such as name and address. Define a sub-classes Student and Teacher for their specific properties. For Students, we need to maintain the
        courses taken and their respective grades; add a course with grade, print all courses taken and the average grade.

        Assume that.
        1.	A student can take maximum 6 courses for the entire program.
        2.	For teachers, we need to maintain the courses taught currently, and able to add or remove a course taught.
        3.	A teacher can teaches maximum 5 courses concurrently.
*/

import java.util.Scanner;

class Person {
    protected String name, address;

    public Person() {
        this.name = "Unknown Student";
        this.address = "Unknown Address";
    }

    public Person(String name, String address) {
        this.name = name;
        this.address = address;
    }

    public String getName() {
        return name;
    }

    public String getAddress() {
        return address;
    }

    public void setAddress(String address) {
        this.address = address;
    }

    public String toString() {
        return "Name: " + name + "\nAddress: " + address;
    }
}

class Student extends Person {
    private int numCourses = 0;
    private String[] courses;
    private int[] grades;

    public Student(String name, String address, String[] courses, int[] grades) {
        super(name, address);

        if (courses.length != grades.length) {
            System.out.println("Courses and grades must match in length.");
            System.exit(0);
        }
        this.courses = courses;
        this.grades = grades;
    }

    public void printGrades() {
        System.out.println("Courses and Grades for " + name + ":");

        for (int i = 0; i < courses.length; i++) {
            System.out.println(courses[i] + ": " + grades[i]);
        }
    }

    public double getAverageGrade() {
        if (grades.length == 0) {
            return 0.0;
        }
        int sum = 0;

        for (int grade : grades) {
            sum += grade;
        }
        return (double) sum / grades.length;
    }
}

class Teacher extends Person {
    private String[] courses;

    public Teacher() {
        courses = null;
    }

    public Teacher(String name, String address, String[] courses) {
        super(name, address);
        this.courses = courses;
    }

    public void printCourses() {
        System.out.println("Courses taught by " + name + ":");

        for (String course : courses) {
            System.out.println("- " + course);
        }
    }
}

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter Student Name: ");
        String studentName = sc.next();
        System.out.print("Enter Student Address: ");
        String studentAddress = sc.next();
        System.out.print("Enter number of courses taken by student: ");
        int studentSize = sc.nextInt();
        String[] studentCourses = new String[studentSize];
        int[] studentGrades = new int[studentSize];

        for (int i = 0; i < studentSize; i++) {
            System.out.print("Enter course name: ");
            studentCourses[i] = sc.next();
            System.out.print("Enter grade for " + studentCourses[i] + ": ");
            studentGrades[i] = sc.nextInt();
        }
        Student student = new Student(studentName, studentAddress, studentCourses, studentGrades);
        System.out.print("\nEnter Teacher Name: ");
        String teacherName = sc.next();
        System.out.print("Enter Teacher Address: ");
        String teacherAddress = sc.next();
        System.out.print("Enter number of courses taught by teacher: ");
        int teacherSize = sc.nextInt();
        String[] teacherCourses = new String[teacherSize];

        for (int i = 0; i < teacherSize; i++) {
            System.out.print("Enter course name taught: ");
            teacherCourses[i] = sc.next();
        }
        Teacher teacher = new Teacher(teacherName, teacherAddress, teacherCourses);
        System.out.println("\n----- Student Details -----");
        student.toString();
        student.printGrades();
        System.out.println("Average Grade: " + student.getAverageGrade());
        System.out.println("\n----- Teacher Details -----");
        teacher.toString();
        teacher.printCourses();
    }
}
