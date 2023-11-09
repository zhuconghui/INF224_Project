import javax.swing.*;
import java.awt.event.*;

/**
 * The ActionAddText2 class represents an action that adds "Bonjour!" text to the TextAreaPanel.
 * It extends AbstractAction and is associated with a button or menu item.
 */
public class ActionAddText2 extends AbstractAction {
    private final TextAreaPanel textAreaPanel;

    /**
     * Constructs a new ActionAddText2 object.
     *
     * @param textAreaPanel The TextAreaPanel to which text will be added.
     */
    public ActionAddText2(TextAreaPanel textAreaPanel) {
        this.textAreaPanel = textAreaPanel;
    }

    /**
     * Performs the action by adding "Bonjour!" text to the TextAreaPanel.
     *
     * @param e The ActionEvent that triggered the action.
     */
    @Override
    public void actionPerformed(ActionEvent e) {
        textAreaPanel.addText2();
    }
}
