/*  Q1. Write a java program to creates three push buttons showing three different colors as their label. When a button is clicked, that particular
        color is set as background color in the frame.
*/

import java.awt.*;
import java.awt.event.*;

class Main {
    public static void main(String[] args) {
        Frame frame = new Frame("Question-1");
        Button button1 = new Button("Red");
        Button button2 = new Button("Green");
        Button button3 = new Button("Blue");

        button1.setBounds(50, 70, 80, 40);
        button2.setBounds(150, 70, 80, 40);
        button3.setBounds(260, 70, 80, 40);

        button1.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent event) {
                frame.setBackground(Color.RED);
            }
        });
        button2.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent event) {
                frame.setBackground(Color.GREEN);
            }
        });
        button3.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent event) {
                frame.setBackground(Color.BLUE);
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

        frame.setBackground(Color.LIGHT_GRAY);
        frame.setSize(400, 300);
        frame.setLayout(null);
        frame.setVisible(true);
    }
}
