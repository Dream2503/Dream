/*  Q5. Write a java awt program, which will create 2 text field and one button labelled as Reverse. The user will enter a number in the 1st text
        field and upon pressing the button it will display the reverse of the number in the 2nd text field.
*/

import java.awt.*;
import java.awt.event.*;

class MyFrame extends Frame {
    private TextField textField1, resultField;
    private Button reverseButton;

    public MyFrame() {
        setTitle("Question-5");
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
        reverseButton = new Button("Reverse");

        textField1.setBounds(50, 70, 130, 30);
        resultField.setBounds(50, 120, 130, 30);
        reverseButton.setBounds(50, 170, 130, 30);

        add(textField1);
        add(resultField);
        add(reverseButton);

        reverseButton.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent event) {
                try {
                    int n = Integer.parseInt(textField1.getText());
                    int reverse = 0;

                    while (n != 0) {
                        reverse = reverse * 10 + n % 10;
                        n /= 10;
                    }
                    resultField.setText(Integer.toString(reverse));
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
