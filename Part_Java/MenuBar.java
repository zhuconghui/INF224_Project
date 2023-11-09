import javax.swing.*;

/**
 * The MenuBar class represents the application's menu bar and toolbar.
 * It extends JMenuBar and includes options for adding text to the TextAreaPanel.
 */
public class MenuBar extends JMenuBar {
    private final JMenu menuFile;
    private final JToolBar toolBar;
    private final TextAreaPanel textAreaPanel;

    /**
     * Constructs a new MenuBar object.
     *
     * @param textAreaPanel The TextAreaPanel associated with this menu bar.
     */
    public MenuBar(TextAreaPanel textAreaPanel){
        super();
        this.textAreaPanel = textAreaPanel;

        // Create a toolbar and create 2 buttons for adding Text
        toolBar = new JToolBar();

        JButton buttonAddText1 = new JButton(new ActionAddText1(textAreaPanel));
        buttonAddText1.setText("Add Text 1");
        toolBar.add(buttonAddText1);

        JButton buttonAddText2 = new JButton(new ActionAddText2(textAreaPanel));
        buttonAddText2.setText("Add Text 2");
        toolBar.add(buttonAddText2);

        // Create a "File" menu create 2 menu items for adding Text
        menuFile = new JMenu("File");

        JMenuItem menuItemAddText1 = new JMenuItem(new ActionAddText1(textAreaPanel));
        menuItemAddText1.setText("Add Text 1");
        menuFile.add(menuItemAddText1);

        JMenuItem menuItemAddText2 = new JMenuItem(new ActionAddText2(textAreaPanel));
        menuItemAddText2.setText("Add Text 2");
        menuFile.add(menuItemAddText2);

        // Add the "File" menu and the toolbar to the menu bar
        this.add(menuFile);
        this.add(toolBar);
    }
}
