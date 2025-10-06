/*	Q5. Create a class Point2D with the data member x and y coordinate. Use default and parameterised constructor to set the coordinate values and
		display() to show the coordinates. Create a subclass called Point3D which is derived from the superclass Point2D with data members z
		coordinate and has constructor to initialize the input and show() method to display the coordinates. Test the methods of both the classes by
		creating objects in the main method of driver class.
*/

import java.util.Scanner;

class Point2D {
	protected double x, y;
	
	public Point2D() {
		x = y = 0.0;
	}
	
	public Point2D(double x, double y) {
		this.x = x;
		this.y = y;
	}
	
	public void display() {
		System.out.println("(" + x + ", " + y + ")");
	}
}

class Point3D extends Point2D {
	private double z;
	
	public Point3D() {
		super();
		z = 0.0;
	}
	
	public Point3D(double x, double y, double z) {
		super(x, y);
		this.z = z;
	}
	
	public void show() {
		System.out.println("(" + x + ", " + y + ", " + z + ")");
	}
}

class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		System.out.print("Enter the 2D coordinates: ");
		double x = sc.nextDouble();
		double y = sc.nextDouble();
		Point2D point2D = new Point2D(x, y);
		point2D.display();
		
		System.out.print("\nEnter the 3D coordinates: ");
		x = sc.nextDouble();
		y = sc.nextDouble();
		double z = sc.nextDouble();
		Point3D point3D = new Point3D(x, y, z);
		point3D.show();
	}
}
