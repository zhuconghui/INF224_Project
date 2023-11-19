import java.awt.*;
import javax.swing.*;

/**
 * The MainPanel class represents the main panel within the application window.
 * It extends JPanel and contains a TextAreaPanel and a ButtonPanel.
 */
public class MainPanel extends JPanel {
    private final ButtonPanel buttonPanel;
    private final TextAreaPanel textAreaPanel;
    private final JTextField requestField;
    private final JTextArea infoArea;
    private final MainFrame mainFrame;

    /**
     * Constructs a new MainPanel object.
     *
     * @param mainFrame The parent MainFrame object that contains this panel.
     */
    public MainPanel(MainFrame mainFrame) {
        super();
        this.mainFrame = mainFrame;
        setLayout(new BorderLayout());

        // Create and add the TextAreaPanel to the center of the MainPanel
        textAreaPanel = new TextAreaPanel();
        this.add(textAreaPanel, BorderLayout.CENTER);

        // Create and add the ButtonPanel to the south of the MainPanel
        buttonPanel = new ButtonPanel(this);
        this.add(buttonPanel, BorderLayout.SOUTH);

        // Initialize and add the request field to the top of the MainPanel
        requestField = new JTextField();
        this.add(requestField, BorderLayout.NORTH);
        requestField.setPreferredSize(new Dimension(800, 20));

        // Initialize and add the information area to the right side of the MainPanel
        infoArea = new JTextArea();
        this.add(infoArea, BorderLayout.EAST);
        infoArea.setPreferredSize(new Dimension(360, 600));
        // Set the initial text for the information area
        infoArea.setText("Info: \n" + 
                        "How to use buttons: \n" +
                        "searchObj : add text \"searchObj\" to request field \n" +
                        "searchGrp : add text \"searchGrp\" to request field \n" +
                        "play : add text \"play\" to request field \n" +
                        "send : send request to server \n" +
                        "exit : exit program \n\n\n" +
                        "Multimedia in the library: \n" +
                        "C++_Logo\n" +
                        "test_video\n" +
                        "test_film\n\n\n" +
                        "Group Multimedia name: groupMultimedia\n" +
                        "For exmaple, to play test_video\n" +
                        "just enter \"play test_video\" in request field and click send button.\n\n\n" +   
                        "Please test the function searchObj and searchGrp first, \n" +
                        "then test the function play\n" +
                        "There is a bug but I don't know how to fix it.\n");
        infoArea.setEditable(false);
    }

    /**
     * Gets the TextAreaPanel contained within this MainPanel.
     *
     * @return The TextAreaPanel instance.
     */
    public TextAreaPanel getTextAreaPanel() {
        return textAreaPanel;
    }

    /**
     * Gets the request field JTextField contained within this MainPanel.
     * 
     * @return The JTextField instance for entering requests.
     */
    public JTextField getRequestField() {
        return requestField;
    }

    /**
     * Gets the MainFrame that contains this MainPanel.
     * 
     * @return The MainFrame instance associated with this panel.
     */
    public MainFrame getMainFrame() {
        return mainFrame;
    }
}
