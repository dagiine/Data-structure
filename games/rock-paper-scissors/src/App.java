import java.awt.*;
import java.io.File;
import java.util.Random;
import javax.sound.sampled.AudioInputStream;
import javax.sound.sampled.AudioSystem;
import javax.sound.sampled.Clip;
import javax.swing.*;

public class App {
    JFrame frame;
    JPanel mainPanel, playerPanel, computerPanel, vsPanel, choicePanel;
    JLabel resultLabel, computerImageLabel, playerImageLabel;
    String[] choices = {"Rock.png", "Paper.png", "Scissors.png"};

    public App() {
        frame = new JFrame("Rock, Paper, Scissors!");
        frame.setSize(900, 500);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setLocationRelativeTo(null);

        mainPanel = new JPanel() {
            @Override
            protected void paintComponent(Graphics g) {
                super.paintComponent(g);
                Image bg = new ImageIcon("Background.jpg").getImage();
                g.drawImage(bg, 0, 0, getWidth(), getHeight(), this);
            }
        };
        mainPanel.setLayout(new BorderLayout());

        JLabel titleLabel = new JLabel("Rock, Paper, Scissors!", SwingConstants.CENTER);
        titleLabel.setFont(new Font("Arial Black", Font.BOLD, 30));
        titleLabel.setForeground(Color.WHITE);
        mainPanel.add(titleLabel, BorderLayout.NORTH);

        vsPanel = new JPanel(new GridLayout(1, 3));
        vsPanel.setOpaque(false);

        playerPanel = new JPanel(new BorderLayout());
        playerPanel.setOpaque(false);
        JLabel playerLabel = new JLabel("PLAYER", SwingConstants.CENTER);
        playerLabel.setFont(new Font("Arial Black", Font.BOLD, 18));
        playerLabel.setForeground(Color.WHITE);
        playerImageLabel = new JLabel("", SwingConstants.CENTER);
        playerPanel.add(playerLabel, BorderLayout.NORTH);
        playerPanel.add(playerImageLabel, BorderLayout.CENTER);

        JLabel vsLabel = new JLabel("VS", SwingConstants.CENTER);
        vsLabel.setFont(new Font("Impact", Font.BOLD, 40));
        vsLabel.setForeground(Color.WHITE);

        computerPanel = new JPanel(new BorderLayout());
        computerPanel.setOpaque(false);
        JLabel computerLabel = new JLabel("COMPUTER", SwingConstants.CENTER);
        computerLabel.setFont(new Font("Arial Black", Font.BOLD, 18));
        computerLabel.setForeground(Color.WHITE);
        computerImageLabel = new JLabel("", SwingConstants.CENTER);
        computerPanel.add(computerLabel, BorderLayout.NORTH);
        computerPanel.add(computerImageLabel, BorderLayout.CENTER);

        vsPanel.add(playerPanel);
        vsPanel.add(vsLabel);
        vsPanel.add(computerPanel);
        mainPanel.add(vsPanel, BorderLayout.CENTER);

        resultLabel = new JLabel("Play", SwingConstants.CENTER);
        resultLabel.setFont(new Font("Arial", Font.BOLD, 24));
        resultLabel.setForeground(Color.YELLOW);
        resultLabel.setOpaque(false);

        choicePanel = new JPanel(new FlowLayout());
        choicePanel.setOpaque(false);
        for (int i = 0; i < choices.length; i++) {
            int index = i;
            JButton button = new JButton(scaleImage(choices[i], 70));
            button.setPreferredSize(new Dimension(90, 90));
            button.setContentAreaFilled(false);
            button.setBorderPainted(false);
            button.addActionListener(e -> playRound(index));
            choicePanel.add(button);
        }

        JPanel centerPanel = new JPanel();
        centerPanel.setLayout(new BorderLayout());
        centerPanel.setOpaque(false);
        centerPanel.add(resultLabel, BorderLayout.NORTH);
        centerPanel.add(vsPanel, BorderLayout.CENTER);

        mainPanel.add(centerPanel, BorderLayout.CENTER);
        mainPanel.add(choicePanel, BorderLayout.SOUTH);

        frame.setContentPane(mainPanel);
        frame.setVisible(true);
    }

    public void playRound(int playerChoice) {
        Random rand = new Random();
        int computerChoice = rand.nextInt(3);

        playerImageLabel.setIcon(scaleImage(choices[playerChoice], 100));
        computerImageLabel.setIcon(scaleImage(choices[computerChoice], 100));

        String result;
        Color resultColor;
        String soundFile;

        if (playerChoice == computerChoice) {
            result = "It's a Tie!";
            resultColor = Color.ORANGE;
            soundFile = "tie.wav";
        } else if ((playerChoice == 0 && computerChoice == 2) ||
                   (playerChoice == 1 && computerChoice == 0) ||
                   (playerChoice == 2 && computerChoice == 1)) {
            result = "You Win!";
            resultColor = Color.GREEN;
            soundFile = "win.wav";
        } else {
            result = "Computer Wins!";
            resultColor = Color.RED;
            soundFile = "lose.wav";
        }

        resultLabel.setText(result);
        resultLabel.setForeground(resultColor);

        playSound(soundFile);
    }

    private void playSound(String filename) {
        try {
            File file = new File(filename);
            if (!file.exists()) return;
            AudioInputStream audioStream = AudioSystem.getAudioInputStream(file);
            Clip clip = AudioSystem.getClip();
            clip.open(audioStream);
            clip.start();
        } catch (Exception e) {
            System.err.println("Sound error: " + e.getMessage());
        }
    }

    private ImageIcon scaleImage(String path, int size) {
        ImageIcon icon = new ImageIcon(path);
        Image img = icon.getImage().getScaledInstance(size, size, Image.SCALE_SMOOTH);
        return new ImageIcon(img);
    }

    public static void main(String[] args) {
        SwingUtilities.invokeLater(App::new);
    }
}