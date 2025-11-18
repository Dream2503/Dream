/*  Q2. We need to develop a model of students and teachers in an application. We can define a super class called Person to store common properties
        such as name and address. Define a sub-classes Student and Teacher for their specific properties. For Students, we need to maintain the
        courses taken and their respective grades; add a course with grade, print all courses taken and the average grade.

        Assume that.
        1.	A student can take maximum 6 courses for the entire program.
        2.	For teachers, we need to maintain the courses taught currently, and able to add or remove a course taught.
        3.	A teacher can teaches maximum 5 courses concurrently.

        Test the methods of both the derived classes by creating objects of the derived classes in the main method of another class.
*/

import java.util.Scanner;

class Person {
    protected String name, address;

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
        return name + "(" + address + ")";
    }
}

class Student extends Person {
    private int numCourses;
    private String[] courses;
    private int[] grades;

    public Student(String name, String address) {
        super(name, address);
        numCourses = 0;
        courses = new String[6];
        grades = new int[6];
    }

    public void addCourseGrade(String course, int grade) {
        if (numCourses == courses.length) {
            System.out.println("Maximum 6 course can be taken\n");
        }
        courses[numCourses] = course;
        grades[numCourses++] = grade;
    }

    public void printGrades() {
        if (numCourses == 0) {
            System.out.println("No courses have been added yet");
            return;
        }
        System.out.println("Courses taken and Grades scored for " + name + ":");

        for (int i = 0; i < numCourses; i++) {
            System.out.println("- " + courses[i] + ": " + grades[i]);
        }
    }

    public double getAverageGrade() {
        double sum = 0.0;

        for (int i = 0; i < numCourses; i++) {
            sum += grades[i];
        }
        return sum / (numCourses == 0 ? 1 : numCourses);
    }

    public String toString() {
        return "Student: " + super.toString();
    }
}

class Teacher extends Person {
    private int numCourses;
    private String[] courses;

    public Teacher(String name, String address) {
        super(name, address);
        numCourses = 0;
        courses = new String[5];
    }

    public boolean addCourse(String course) {
        if (numCourses == courses.length) {
            System.out.println("Maximum 5 course can be taken\n");
            return false;
        }
        for (int i = 0; i < numCourses; i++) {
            if (courses[i].equals(course)) {
                return false;
            }
        }
        courses[numCourses++] = course;
        return true;
    }

    public boolean removeCourse(String course) {
        if (numCourses == 0) {
            System.out.println("No course left to remove\n");
            return false;
        }
        for (int i = 0; i < numCourses; i++) {
            if (courses[i].equals(course)) {
                while (i < numCourses - 1) {
                    courses[i] = courses[i + 1];
                    i++;
                }
                numCourses--;
                return true;
            }
        }
        return false;
    }

    public void printCourses() {
        if (numCourses == 0) {
            System.out.println("No courses have been added yet");
            return;
        }
        System.out.println("Courses taught by " + name + ":");

        for (int i = 0; i < numCourses; i++) {
            System.out.println("- " + courses[i]);
        }
    }

    public String toString() {
        return "Teacher: " + super.toString();
    }
}

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter a Person Name: ");
        String personName = sc.next();
        System.out.print("Enter a Person Address: ");
        String personAddress = sc.next();

        Person person = new Person(personName, personAddress);
        System.out.println(person);

        System.out.print("Enter the new address of " + person + ": ");
        personAddress = sc.next();
        person.setAddress(personAddress);
        System.out.println(person);

        System.out.print("\nEnter Student Name: ");
        String studentName = sc.next();
        System.out.print("Enter Student Address: ");
        String studentAddress = sc.next();

        Student student = new Student(studentName, studentAddress);
        System.out.println(student);

        System.out.print("How many courses to add for " + student.getName() + " at " + student.getAddress() + ": ");
        int studentCourses = sc.nextInt();

        for (int i = 0; i < studentCourses; i++) {
            System.out.print("Enter course" + (i + 1) + " name: ");
            String course = sc.next();
            System.out.print("Enter grade for " + course + ": ");
            int grade = sc.nextInt();
            student.addCourseGrade(course, grade);
        }
        System.out.println();
        student.printGrades();
        System.out.println("Average grade: " + student.getAverageGrade());

        System.out.print("\nEnter Teacher Name: ");
        String teacherName = sc.next();
        System.out.print("Enter Teacher Address: ");
        String teacherAddress = sc.next();

        Teacher teacher = new Teacher(teacherName, teacherAddress);
        System.out.println(teacher);

        System.out.print("How many courses to add for " + teacher.getName() + " at " + teacher.getAddress() + ": ");
        int teacherCourses = sc.nextInt();

        for (int i = 0; i < teacherCourses; i++) {
            System.out.print("Enter course " + (i + 1) + " name: ");
            String course = sc.next();

            if (!teacher.addCourse(course)) {
                System.out.println("Could not add (duplicate or max limit).");
            }
        }
        System.out.println();
        teacher.printCourses();
    }
}
