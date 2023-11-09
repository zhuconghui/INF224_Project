import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class ButtonPanel extends JPanel implements ActionListener{
    private JButton buttonAddText1;
    private JButton buttonAddText2;
    private JButton buttonExit;
    // private MainFrame mainFrame;
    private final TextAreaPanel textAreaPanel;

    public ButtonPanel(TextAreaPanel textAreaPanel) {

        this.textAreaPanel = textAreaPanel;

        setLayout(new GridLayout(1,3));

        buttonAddText1 = new JButton("Add Text 1");
        this.add(buttonAddText1);
        buttonAddText1.addActionListener(this);

        buttonAddText2 = new JButton("Add Text 2");
        this.add(buttonAddText2);
        buttonAddText2.addActionListener(this);

        buttonExit = new JButton("Exit");
        this.add(buttonExit);
        buttonExit.addActionListener(this);
    }

    @Override
    public void actionPerformed(ActionEvent e) {
        if (e.getSource() == buttonAddText1) {
            System.out.println("Button 1 pressed");
            textAreaPanel.addText1();
        } else if (e.getSource() == buttonAddText2) {
            System.out.println("Button 2 pressed");
            textAreaPanel.addText2();
        } else if (e.getSource() == buttonExit) {
            System.exit(0);
        }
    }

    // public void notifyForUpdate(ActionEvent e) {
    //     mainFrame.notifyForUpdate(e);
    // }
}
