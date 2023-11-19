import javax.swing.*;
import java.awt.event.*;

/**
 * The ActionAddText1 class represents an action that adds "Hello!" text to the TextAreaPanel.
 * It extends AbstractAction and is associated with a button or menu item.
 */
public class ActionAddText1 extends AbstractAction {
    private final TextAreaPanel textAreaPanel;

    /**
     * Constructs a new ActionAddText1 object.
     *
     * @param textAreaPanel The TextAreaPanel to which text will be added.
     */
    public ActionAddText1(TextAreaPanel textAreaPanel) {
        this.textAreaPanel = textAreaPanel;
    }

    /**
     * Performs the action by adding "Hello!" text to the TextAreaPanel.
     *
     * @param e The ActionEvent that triggered the action.
     */
    @Override
    public void actionPerformed(ActionEvent e) {
        textAreaPanel.addTextPlay();
    }
}
