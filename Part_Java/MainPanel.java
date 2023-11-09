import java.awt.*;
import javax.swing.*;

/**
 * The MainPanel class represents the main panel within the application window.
 * It extends JPanel and contains a TextAreaPanel and a ButtonPanel.
 */
public class MainPanel extends JPanel{
    private final ButtonPanel buttonPanel;
    private final TextAreaPanel textAreaPanel;
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
        buttonPanel = new ButtonPanel(textAreaPanel);
        this.add(buttonPanel, BorderLayout.SOUTH);
    }

    /**
     * Gets the TextAreaPanel contained within this MainPanel.
     *
     * @return The TextAreaPanel instance.
     */
    public TextAreaPanel getTextAreaPanel() {
        return textAreaPanel;
    }
}
