/*  Q8. Write a AWT program, which creates 2 text field with two labels and one button labelled as Count. The program will take the input from one
        text filed. When we click the button it will count the number of digits of the given number and display the result in the second field. Label
        one will be written as "Input number" and second label will show "Number of digits: ".
 */

import java.awt.*;
import java.awt.event.*;

class MyFrame extends Frame {
    private TextField textField1, resultField;
    private Button digitsButton;
    private Label label1, label2;

    public MyFrame() {
        setTitle("Question-8");
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
        digitsButton = new Button("Compute");
        label1 = new Label("Input number");
        label2 = new Label("Number of digits");

        label1.setBounds(50, 70, 130, 30);
        textField1.setBounds(150, 70, 130, 30);
        label2.setBounds(50, 120, 130, 30);
        resultField.setBounds(150, 120, 130, 30);
        digitsButton.setBounds(80, 170, 130, 30);

        add(textField1);
        add(resultField);
        add(digitsButton);
        add(label1);
        add(label2);

        digitsButton.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent event) {
                try {
                    int n = Integer.parseInt(textField1.getText());
                    int res = 0;

                    while (n != 0) {
                        res++;
                        n /= 10;
                    }
                    resultField.setText(Integer.toString(res));
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
        frame.setBackground(Color.LIGHT_GRAY);
        frame.setVisible(true);
    }
}
