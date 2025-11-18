//	Q4. Write a program to implement multiple inheritance using interface.

interface Interface1 {
    void method1();
}

interface Interface2 {
    void method2();
}

interface Interface3 {
    void method3();
}

class MultipleInheritance implements Interface1, Interface2, Interface3 {
    public void method1() {
        System.out.println("Method1 from Interface1");
    }

    public void method2() {
        System.out.println("Method2 from Interface2");
    }

    public void method3() {
        System.out.println("Method3 from Interface3");
    }
}

class Main {
    public static void main(String[] args) {
        MultipleInheritance multipleInheritance = new MultipleInheritance();
        multipleInheritance.method1();
        multipleInheritance.method2();
        multipleInheritance.method3();
    }
}
