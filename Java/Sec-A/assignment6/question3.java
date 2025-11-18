/*  Q3. Define a class Test inside a package (say pkg). Outside of the package, Inherit a class TestInherit from Test. Check the members which are
        accessible by TestInherit.
*/

import pkg.Test;

class TestInherit extends Test {
    public void accessMembers() {
        System.out.println("Accessing from TestInherit:");
//        System.out.println(defaultVar); // package-private
//        System.out.println(privateVar); // private
        System.out.println("proVar = " + protectedVar);
        System.out.println("pubVar = " + publicVar);
    }
}

class Main {
    public static void main(String[] args) {
        TestInherit testInherit = new TestInherit();
        testInherit.accessMembers();

        System.out.println("Accessing through object reference:");
        System.out.println("testInherit.publicVar = " + testInherit.publicVar);
//        System.out.println(testInherit.protectedVar); // protected
//        System.out.println(testInherit.defaultVar); // package-private
//        System.out.println(testInherit.privateVar); // private
    }
}
