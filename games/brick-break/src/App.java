import java.awt.*;
import java.awt.event.*;
import java.util.Random;
import javax.swing.*;

public class App extends JPanel implements KeyListener, ActionListener {
    private final int ROWS = 5, COLS = 10;
    private final int BLOCK_WIDTH = 60, BLOCK_HEIGHT = 20;
    private final Color[] rowColors = {Color.RED, Color.BLUE, Color.YELLOW, Color.GREEN, Color.CYAN};
    private final boolean[][] blocks = new boolean[ROWS][COLS];
    private final boolean[][] isSpecial = new boolean[ROWS][COLS];
    private int paddleX = 250, paddleWidth = 100;
    private int ballX = 290, ballY = 350, ballDX = 2, ballDY = -2;
    private int lives = 3, score = 0;
    private Timer timer;

    public App() {
        setFocusable(true);
        addKeyListener(this);
        initBlocks();
        timer = new Timer(10, this);
        timer.start();
    }

    private void initBlocks() {
        Random rand = new Random();
        int specialBlocks = 0;

        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                blocks[i][j] = true;

                if (specialBlocks < 2 && rand.nextDouble() < 0.05) {
                    isSpecial[i][j] = true;
                    specialBlocks++;
                } else {
                    isSpecial[i][j] = false;
                }
            }
        }
    }

    @Override
    public void paintComponent(Graphics g) {
        super.paintComponent(g);
        setBackground(new Color(20, 18, 27));

        for (int i = 0; i < lives; i++) {
            g.setColor(Color.WHITE);
            g.fillOval(20 + i * 25, 10, 15, 15);
        }

        g.setColor(Color.WHITE);
        g.setFont(new Font("Arial", Font.BOLD, 20));
        g.drawString(String.format("%05d", score), getWidth() / 2 - 30, 25);

        for (int i = 0; i < ROWS; i++) {
            g.setColor(rowColors[i % rowColors.length]);
            for (int j = 0; j < COLS; j++) {
                if (blocks[i][j]) {
                    int x = j * BLOCK_WIDTH + 30;
                    int y = i * BLOCK_HEIGHT + 50;

                    if (isSpecial[i][j]) {
                        g.setColor(Color.white);
                        g.fillRoundRect(x, y, BLOCK_WIDTH - 5, BLOCK_HEIGHT - 5, 10, 10);
                    } else {
                        g.setColor(rowColors[i]);
                        g.fillRoundRect(x, y, BLOCK_WIDTH - 5, BLOCK_HEIGHT - 5, 8, 8);
                    }
                }
            }
        }

        g.setColor(Color.WHITE);
        g.fillRoundRect(paddleX, 400, paddleWidth, 10, 10, 10);

        g.fillOval(ballX, ballY, 20, 20);
    }

    @Override
    public void actionPerformed(ActionEvent e) {
        ballX += ballDX;
        ballY += ballDY;

        if (ballX <= 0 || ballX >= getWidth() - 20) ballDX *= -1;
        if (ballY <= 0) ballDY *= -1;

        if (ballY >= 400 && ballX + 20 >= paddleX && ballX <= paddleX + paddleWidth) {
            ballDY *= -1;
        }

        outer:
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                int blockX = j * BLOCK_WIDTH + 30;
                int blockY = i * BLOCK_HEIGHT + 50;
                Rectangle blockRect = new Rectangle(blockX, blockY, BLOCK_WIDTH - 5, BLOCK_HEIGHT - 5);
                Rectangle ballRect = new Rectangle(ballX, ballY, 20, 20);

                if (blocks[i][j] && ballRect.intersects(blockRect)) {
                    blocks[i][j] = false;
                    score += 100;

                    if (isSpecial[i][j] && lives < 3) {
                        lives++;
                    }

                    ballDY *= -1;
                    break outer;
                }
            }
        }

        if (ballY > getHeight()) {
            lives--;
            if (lives == 0) {
                timer.stop();
                JOptionPane.showMessageDialog(this, "You Lose!", "Game Over", JOptionPane.INFORMATION_MESSAGE);
                System.exit(0);
            }
            ballX = 290;
            ballY = 350;
            ballDX = 2;
            ballDY = -2;
        }

        if (isAllBlocksCleared()) {
            timer.stop();
            JOptionPane.showMessageDialog(this, "You Win!", "Victory", JOptionPane.INFORMATION_MESSAGE);
            System.exit(0);
        }

        repaint();
    }

    private boolean isAllBlocksCleared() {
        for (int i = 0; i < ROWS; i++)
            for (int j = 0; j < COLS; j++)
                if (blocks[i][j]) return false;
        return true;
    }

    @Override
    public void keyPressed(KeyEvent e) {
        if (e.getKeyCode() == KeyEvent.VK_LEFT && paddleX > 0) {
            paddleX -= 20;
        }
        if (e.getKeyCode() == KeyEvent.VK_RIGHT && paddleX < getWidth() - paddleWidth) {
            paddleX += 20;
        }
    }

    @Override
    public void keyReleased(KeyEvent e) {}

    @Override
    public void keyTyped(KeyEvent e) {}

    public static void main(String[] args) {
        JFrame frame = new JFrame("Block Breaker Game");
        App game = new App();
        frame.setSize(670, 500);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.add(game);
        frame.setLocationRelativeTo(null);
        frame.setVisible(true);
    }
}