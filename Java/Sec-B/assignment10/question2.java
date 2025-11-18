/*  Q2. Write a java awt program, which will create 3 text field and one button labelled as Subtract. The program will take the input from the two
        text filed and upon pressing the Subtract button it will display the result in the third text field.
*/

import java.awt.*;
import java.awt.event.*;

class MyFrame extends Frame {
    private TextField textField1, textField2, resultField;
    private Button subtractButton;

    public MyFrame() {
        setTitle("Question-2");
        setSize(300, 250);
        addWindowListener(new WindowAdapter() {
            public void windowClosing(WindowEvent event) {
                System.exit(0);
            }
        });
        setLayout(null);

        textField1 = new TextField();
        textField2 = new TextField();
        resultField = new TextField();
        resultField.setEditable(false);
        subtractButton = new Button("Subtract");

        textField1.setBounds(50, 70, 130, 30);
        textField2.setBounds(50, 120, 130, 30);
        resultField.setBounds(50, 170, 130, 30);
        subtractButton.setBounds(50, 220, 130, 30);

        add(textField1);
        add(textField2);
        add(resultField);
        add(subtractButton);

        subtractButton.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent event) {
                try {
                    int num1 = Integer.parseInt(textField1.getText());
                    int num2 = Integer.parseInt(textField2.getText());
                    int result = num1 - num2;
                    resultField.setText(Integer.toString(result));
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
