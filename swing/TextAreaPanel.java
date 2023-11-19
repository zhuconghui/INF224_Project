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
        textArea.setEditable(false);
    }

    /**
     * Appends "Hello!" to the text area.
     */
    public void addTextPlay() {
        textArea.append("Play ");
    }

    /**
     * Appends "Bonjour!" to the text area.
     */
    public void addTextSearchObj() {
        textArea.append("SearchObj ");
    }

    public void addTextSearchGrp() {
        textArea.append("SearchGrp ");
    }

    public void addText(String text) {
        textArea.append(text + "\n");
    }

    public String getText(){
        return textArea.getText();
    }
}
