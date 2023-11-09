/**
 * The MainFrame class represents the main window of the application.
 * It extends the JFrame class to create a graphical user interface.
 */
import javax.swing.*;

public class MainFrame extends JFrame {
    private final MenuBar menuBar;
    private final MainPanel mainPanel;

    /**
     * Constructs a new MainFrame object.
     */
    public MainFrame(){
        super("Main Window");

        // Set the main panel as the content pane of the frame
        setContentPane(mainPanel = new MainPanel(this));

        // Set the menu bar
        setJMenuBar(menuBar = new MenuBar(mainPanel.getTextAreaPanel()));

        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        pack();
        setVisible(true);
        setSize(400, 300);
    }
}
