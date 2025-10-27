/*  Q1. Write a java program that will create the reference of the thread and display the details of the reference thread. (It should display class,
        name of thread, priority, group name).
*/

class Main {
    public static void main(String[] args) {
        Thread thread = Thread.currentThread();
        System.out.println("Class: " + thread.getClass());
        System.out.println("Name: " + thread.getName());
        System.out.println("Priority: " + thread.getPriority());
        System.out.println("Group name: " + thread.getThreadGroup().getName());
    }
}
