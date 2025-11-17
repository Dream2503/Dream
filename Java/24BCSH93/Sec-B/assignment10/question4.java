/*  Q4. Write a java awt program, which will create 2 text field and one button labelled as Factorial. The user will enter a number in the 1st text
        field and upon pressing the button it will display the Factorial of the number in the 2nd text field.
*/

import java.awt.*;
import java.awt.event.*;

class MyFrame extends Frame {
    private TextField textField1, resultField;
    private Button factorialButton;

    public MyFrame() {
        setTitle("Question-4");
        setSize(300, 250);
        this.addWindowListener(new WindowAdapter() {
            public void windowClosing(WindowEvent event) {
                System.exit(0);
            }
        });
        setLayout(null);

        textField1 = new TextField();
        resultField = new TextField();
        resultField.setEditable(false);
        factorialButton = new Button("Factorial");

        textField1.setBounds(50, 70, 130, 30);
        resultField.setBounds(50, 120, 130, 30);
        factorialButton.setBounds(50, 170, 130, 30);

        add(textField1);
        add(resultField);
        add(factorialButton);

        factorialButton.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent event) {
                try {
                    int n = Integer.parseInt(textField1.getText());
                    int fact = 1;

                    for (int i = 2; i <= n; i++) {
                        fact *= i;
                    }
                    resultField.setText(Integer.toString(fact));
                } catch (NumberFormatException e) {
                    resultField.setText("Invalid Input");
                }
            }
        });
    }
}

class Main {
    public static void main(String[] args) {
        MyFrame frame = new MyFrame();
        frame.setVisible(true);
    }
}
