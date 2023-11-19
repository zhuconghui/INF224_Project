import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

/**
 * @class ButtonPanel
 * @brief This class creates and manages a set of buttons for interaction with MainPanel.
 *
 * ButtonPanel is an extension of JPanel that contains a series of buttons for performing
 * various actions such as play, search, send requests, and exit the application.
 * This panel relies on an instance of MainPanel to interact with other parts of the application.
 */
public class ButtonPanel extends JPanel implements ActionListener {
    private JButton buttonPlay;
    private JButton buttonSearchObj;
    private JButton buttonSearchGrp;
    private JButton buttonSend;
    private JButton buttonExit;

    private final MainPanel mainPanel;

    /**
     * Constructor initializes the ButtonPanel, setting up its layout and functionalities.
     * 
     * @param mainPanel A reference to MainPanel, used to interact with it when button events are triggered.
     */
    public ButtonPanel(MainPanel mainPanel) {

        this.mainPanel = mainPanel;

        setLayout(new GridLayout(1, 5));

        buttonSearchObj = new JButton("searchObj");
        this.add(buttonSearchObj);
        buttonSearchObj.addActionListener(this);

        buttonSearchGrp = new JButton("searchGrp");
        this.add(buttonSearchGrp);
        buttonSearchGrp.addActionListener(this);

        buttonPlay = new JButton("play");
        this.add(buttonPlay);
        buttonPlay.addActionListener(this);

        buttonSend = new JButton("send");
        this.add(buttonSend);
        buttonSend.addActionListener(this);

        buttonExit = new JButton("Exit");
        this.add(buttonExit);
        buttonExit.addActionListener(this);
    }

    /**
     * Handles action events triggered by the buttons in this panel.
     * 
     * Depending on which button is pressed, different actions are performed.
     * These actions include setting text in the request field of the main panel,
     * sending a request to the main frame, and exiting the application.
     *
     * @param e The ActionEvent triggered by button interactions.
     */
    @Override
    public void actionPerformed(ActionEvent e) {
        if (e.getSource() == buttonPlay) {
            mainPanel.getRequestField().setText("play ");
        } else if (e.getSource() == buttonSearchObj) {
            mainPanel.getRequestField().setText("searchObj ");
        } else if (e.getSource() == buttonSearchGrp) {
            mainPanel.getRequestField().setText("searchGrp ");
        } else if (e.getSource() == buttonSend) {
            String request = mainPanel.getRequestField().getText();
            mainPanel.getMainFrame().setRequest(request);
            mainPanel.getMainFrame().setSendClicked(1);
            mainPanel.getRequestField().setText("");
        } else if (e.getSource() == buttonExit) {
            System.exit(0);
        }
    }
}
