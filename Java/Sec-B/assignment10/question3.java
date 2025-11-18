/*  Q3. Write a java awt program, which will create 3 text field and two buttons labelled as Add and Subtract. The program will take the input from
        the two text filed and upon pressing the Add or Subtract button it will display the result in the third text field.
*/

import java.awt.*;
import java.awt.event.*;

class MyFrame extends Frame {
    private TextField textField1, textField2, resultField;
    private Button addButton, subtractButton;

    public MyFrame() {
        setTitle("Question-3");
        setSize(300, 250);
        this.addWindowListener(new WindowAdapter() {
            public void windowClosing(WindowEvent event) {
                System.exit(0);
            }
        });
        setLayout(null);

        textField1 = new TextField();
        textField2 = new TextField();
        resultField = new TextField();
        resultField.setEditable(false);
        addButton = new Button("+");
        subtractButton = new Button("-");

        textField1.setBounds(70, 70, 130, 30);
        textField2.setBounds(70, 120, 130, 30);
        resultField.setBounds(70, 170, 130, 30);
        addButton.setBounds(50, 220, 80, 40);
        subtractButton.setBounds(150, 220, 80, 40);

        add(textField1);
        add(textField2);
        add(resultField);
        add(addButton);
        add(subtractButton);

        addButton.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent event) {
                try {
                    int num1 = Integer.parseInt(textField1.getText());
                    int num2 = Integer.parseInt(textField2.getText());
                    resultField.setText(Integer.toString(num1 + num2));
                } catch (NumberFormatException e) {
                    resultField.setText("Invalid Input");
                }
            }
        });
        subtractButton.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent event) {
                try {
                    int num1 = Integer.parseInt(textField1.getText());
                    int num2 = Integer.parseInt(textField2.getText());
                    resultField.setText(Integer.toString(num1 - num2));
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
