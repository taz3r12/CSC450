package Portfolio_Project_Part_2;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class concurrencyThread {
    
    // GUI components
    private JFrame frame;
    private JTextArea textArea;
    private JButton closeButton;

    public static void main(String[] args) {
        // Create instance of the UI class
        SwingUtilities.invokeLater(concurrencyThread::new);
    }

    public concurrencyThread() {
        // Create the GUI
        createUI();

        // Start counting threads
        startCountingThreads();
    }

    private void createUI() {
        frame = new JFrame("CSC450 Concurrency Concepts");
        frame.setSize(500, 800);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        // Text area to display output
        textArea = new JTextArea();
        textArea.setEditable(false);
        JScrollPane scrollPane = new JScrollPane(textArea);
        
        // Close button
        closeButton = new JButton("Close Program");
        closeButton.setEnabled(false); // Disable until counting finishes
        closeButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                // Close the application when the button is clicked
                System.exit(0);
            }
        });

        // Layout setup
        frame.setLayout(new BorderLayout());
        frame.add(scrollPane, BorderLayout.CENTER);
        frame.add(closeButton, BorderLayout.SOUTH);

        frame.setVisible(true);
    }

    private void startCountingThreads() {
        // Create and start thread for counting up
        Thread countUpThread = new Thread(new CountUpTask());
        countUpThread.start();

        // Wait for the count up thread to finish, then start count down thread
        new Thread(() -> {
            try {
                countUpThread.join(); // Wait for counting up to finish
                Thread countDownThread = new Thread(new CountDownTask());
                countDownThread.start();
                countDownThread.join(); // Wait for counting down to finish
                // Enable the close button when both threads are done
                SwingUtilities.invokeLater(() -> closeButton.setEnabled(true));
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }).start();
    }

    // Task for counting up
    class CountUpTask implements Runnable {
        @Override
        public void run() {
            for (int i = 1; i <= 20; i++) {
                final int count = i;
                SwingUtilities.invokeLater(() -> textArea.append("Counting Up: " + count + "\n"));
                try {
                    Thread.sleep(100); // Simulate work with sleep
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
            }
        }
    }

    // Task for counting down
    class CountDownTask implements Runnable {
        @Override
        public void run() {
            for (int i = 20; i >= 0; i--) {
                final int count = i;
                SwingUtilities.invokeLater(() -> textArea.append("Counting Down: " + count + "\n"));
                try {
                    Thread.sleep(100); // Simulate work with sleep
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
            }
        }
    }
}
