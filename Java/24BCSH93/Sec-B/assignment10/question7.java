/*  Q7. Create three color buttons (with caption “Red”, “Blue” and “Green”) and a text label. Initially the text should be displayed in black color.
        When the user clicks on a particular color button the text should be changed to that particular color as shown in the figure.
*/

import java.awt.*;
import java.awt.event.*;

class Main {
    public static void main(String[] args) {
        Frame frame = new Frame("Question-7");
        Label label = new Label("Welcome");
        label.setAlignment(Label.CENTER);
        label.setFont(new Font("Roboto Condensed Light", Font.BOLD, 20));

        Button button1 = new Button("Red");
        Button button2 = new Button("Green");
        Button button3 = new Button("Blue");

        button1.setBounds(50, 70, 80, 40);
        button2.setBounds(150, 70, 80, 40);
        button3.setBounds(260, 70, 80, 40);
        label.setBounds(140, 100, 100, 80);

        button1.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent event) {
                label.setForeground(Color.RED);
            }
        });
        button2.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent event) {
                label.setForeground(Color.GREEN);
            }
        });
        button3.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent event) {
                label.setForeground(Color.BLUE);
            }
        });
        frame.addWindowListener(new WindowAdapter() {
            public void windowClosing(WindowEvent event) {
                System.exit(0);
            }
        });

        frame.add(button1);
        frame.add(button2);
        frame.add(button3);
        frame.add(label);
        frame.setSize(400, 300);
        frame.setLayout(null);
        frame.setVisible(true);
    }
}
