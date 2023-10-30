import javax.swing.*;
// import java.awt.event.*;

public class MainWindow extends JFrame {
    JButton button1;
    JButton button2;
    JButton button3;
    JTextArea textArea;

    public static void main(String[] args) {
        System.out.println("Hello World!");
        new MainWindow();
    }

    public MainWindow(){
        
        button1 = new JButton("Button 1");
        button2 = new JButton("Button 2");
        button3 = new JButton("Button 3");
        // textArea = new JTextArea(10, 20);
        this.add(button1);
        this.add(button2);
        this.add(button3);
        // this.add(textArea);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setTitle("Main Window");
        pack();
        setVisible(true);
    }
}