/*	Q4. Define a class Time having data members hour, minute and second. The class should have a parameterized constructor to initialize its data
        members. It should also have methods display() to display the time in HH:MM:SS format and add() to add two time objects. Define a main class
        and access all the methods.
*/

import java.util.Scanner;

class Time {
    private int hour, minute, second;

    public Time(int hour, int minute, int second) {
        if (hour < 0 || minute < 0 || second < 0) {
            System.out.println("The time component cannot be negative");
            System.exit(0);
        }
        this.hour = hour;
        this.minute = minute;
        this.second = second;
        this.resolve();
    }

    public void display() {
        System.out.println(hour + ":" + minute + ":" + second);
    }

    public static Time add(Time time1, Time time2) {
        return new Time(time1.hour + time2.hour, time1.minute + time2.minute, time1.second + time2.second);
    }

    private void resolve() {
        minute += second / 60;
        second %= 60;
        hour += minute / 60;
        minute %= 60;
    }
}

class Main {
    public static void main(String[] args) {
        Time time1 = createTime("first");
        Time time2 = createTime("second");
        System.out.println("The two Time objects are: ");
        time1.display();
        time2.display();

        Time sum = Time.add(time1, time2);
        System.out.print("Sum of two time objects is: ");
        sum.display();
    }

    private static Time createTime(String name) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter hour, minute and second values for " + name + " time object: ");
        int hour = sc.nextInt();
        int minute = sc.nextInt();
        int second = sc.nextInt();
        return new Time(hour, minute, second);
    }
}
