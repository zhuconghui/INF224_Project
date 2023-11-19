import javax.swing.*;

/**
 * @class MainFrame
 * @brief The main window frame of the application, managing the GUI components and client interactions.
 *
 * MainFrame extends JFrame and is the primary window for the application. It contains
 * the main panel, menu bar, and handles the client-server communication. It is responsible
 * for initializing the GUI components and managing the lifecycle of the application.
 */
public class MainFrame extends JFrame {
    private final MenuBar menuBar;
    private final MainPanel mainPanel;
    private Client client;
    private String request;
    private int sendClicked = 0;

    /**
     * Constructor for MainFrame which sets up the GUI components and client connection.
     * It initializes the main panel, menu bar, and sets up the frame properties.
     * Also, it establishes the client connection and manages the main application loop.
     */
    public MainFrame() {
        super("Main Window");

        // Set the main panel as the content pane of the frame
        setContentPane(mainPanel = new MainPanel(this));

        // Set the menu bar
        setJMenuBar(menuBar = new MenuBar(mainPanel.getTextAreaPanel()));

        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        pack();
        setVisible(true);
        setSize(800, 600);

        // Set the client
        String host = "localhost";
        int port = 3331;

        Client client = null;
    
        try {
            client = new Client(host, port);
        }
        catch (Exception e) {
            System.err.println("Client: Couldn't connect to "+host+":"+port);
            System.exit(1);
        }

        while (true) {
            mainPanel.getTextAreaPanel().addText("Please enter your command:");

            while(sendClicked == 0) {
                try {
                    Thread.sleep(100);
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
            };

            System.out.println("Request: " + request);
            String response = client.send(request);
            String respondeModified = response.replace("; ", "\n");
            mainPanel.getTextAreaPanel().addText(respondeModified);
            sendClicked = 0;
        }
    }

    /**
     * Returns the Client instance used for server communication.
     * 
     * @return The Client object used in this frame.
     */
    public Client getClient() {
        return client;
    }

    /**
     * Sets the request string to be sent to the server.
     * 
     * @param request The request string.
     */
    public void setRequest(String request) {
        this.request = request;
    }

    /**
     * Sets the state of the sendClicked flag.
     * 
     * @param sendClicked The state to set for sendClicked.
     */
    public void setSendClicked(int sendClicked) {
        this.sendClicked = sendClicked;
    }
}
