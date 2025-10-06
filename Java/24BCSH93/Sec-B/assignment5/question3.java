/*	Q3. Write a program to create a class named Shape. It should contain two methods, draw() and erase() that prints “Drawing Shape” and “Erasing
        Shape” respectively. For this class, create three sub classes, Circle, Triangle and Square and each class should override the parent class
        functions- draw() and erase(). The draw() method should print “Drawing Circle”, “Drawing Triangle” and “Drawing Square” respectively. The
        erase() method should print “Erasing Circle”, “Erasing Triangle” and “Erasing Square” respectively. Create objects of Circle, Triangle and
        Square, assign each to Shape variable(reference) and call draw() and erase() method using each object.
*/

class Shape {
    public void draw() {
        System.out.println("Drawing Shape");
    }

    public void erase() {
        System.out.println("Erasing Shape");
    }
}

class Circle extends Shape {
    public void draw() {
        System.out.println("Drawing Circle");
    }

    public void erase() {
        System.out.println("Erasing Circle");
    }
}

class Triangle extends Shape {
    public void draw() {
        System.out.println("Drawing Triangle");
    }

    public void erase() {
        System.out.println("Erasing Triangle");
    }
}

class Square extends Shape {
    public void draw() {
        System.out.println("Drawing Square");
    }

    public void erase() {
        System.out.println("Erasing Square");
    }
}

class Main {
    public static void main(String[] args) {
        Shape shape = new Shape();
        shape.draw();
        shape.erase();
        System.out.println();

        shape = new Circle();
        shape.draw();
        shape.erase();
        System.out.println();

        shape = new Triangle();
        shape.draw();
        shape.erase();
        System.out.println();

        shape = new Square();
        shape.draw();
        shape.erase();
    }
}
