//  Q4. Define a package and create a sub package. Try to access it from outside of the package.

import mypkg.subpkg.SubTest;

class Main {
    public static void main(String[] args) {
        SubTest subTest = new SubTest();
        subTest.display();
    }
}
