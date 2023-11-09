import javax.swing.*;

/**
 * The TextAreaPanel class represents a scrollable text area within the application.
 * It extends JScrollPane and contains a JTextArea for displaying and editing text.
 */
public class TextAreaPanel extends JScrollPane {
    private final JTextArea textArea;

    /**
     * Constructs a new TextAreaPanel object.
     */
    public TextAreaPanel() {
        super();
        textArea = new JTextArea();
        this.setViewportView(textArea);
    }

    /**
     * Appends "Hello!" to the text area.
     */
    public void addText1() {
        textArea.append("Hello!\n");
    }

    /**
     * Appends "Bonjour!" to the text area.
     */
    public void addText2() {
        textArea.append("Bonjour!\n");
    }
}
