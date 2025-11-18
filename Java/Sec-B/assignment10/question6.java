/*  Q6. Design an AWT GUI application (called AWT Counter). Each time the "Count" button is clicked, the counter value should increase by 1 and each
        time the Reset button is clicked the counter value should be reset to zero.
*/

import java.awt.*;
import java.awt.event.*;

class MyFrame extends Frame {
    private int count = 0;
    private TextField textField1;
    private Button countButton, resetButton;

    public MyFrame() {
        setTitle("Question-6");
        setSize(300, 250);
        this.addWindowListener(new WindowAdapter() {
            public void windowClosing(WindowEvent event) {
                System.exit(0);
            }
        });
        setLayout(null);

        textField1 = new TextField();
        textField1.setEditable(false);
        countButton = new Button("Count");
        resetButton = new Button("Reset");

        textField1.setBounds(50, 70, 130, 30);
        countButton.setBounds(200, 70, 80, 30);
        resetButton.setBounds(50, 120, 80, 30);

        add(textField1);
        add(countButton);
        add(resetButton);
        textField1.setText(Integer.toString(count));

        countButton.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent event) {
                try {
                    textField1.setText(Integer.toString(++count));
                } catch (NumberFormatException e) {
                    textField1.setText("Invalid Input");
                }
            }
        });
        resetButton.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent event) {
                try {
                    count = 0;
                    textField1.setText(Integer.toString(count));
                } catch (NumberFormatException e) {
                    textField1.setText("Invalid Input");
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
