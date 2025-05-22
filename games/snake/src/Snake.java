import java.awt.*;
import java.awt.event.*;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Random;
import javax.imageio.ImageIO;
import javax.swing.*;

public class Snake extends JPanel implements ActionListener {
    private static final int BODY_SIZE = 25;
    private final int boardWidth, boardHeight, cols, rows;

    private class Body {
        int x, y;
        Body(int x, int y) { this.x = x; this.y = y; }
    }

    private Body snakeHead;
    private ArrayList<Body> snakeBody = new ArrayList<>();
    private Body food;
    private Random random = new Random();
    private Image appleImage;
    private Image grassImage;
    private Timer timer;
    private int velX = 0, velY = 0;
    private boolean gameOver = false;

    public Snake(int width, int height) {
        this.boardWidth = width;
        this.boardHeight = height;
        this.cols = boardWidth / BODY_SIZE;
        this.rows = boardHeight / BODY_SIZE;

        setPreferredSize(new Dimension(boardWidth, boardHeight));
        setBackground(Color.BLACK);
        setFocusable(true);
        loadImages();
        initGame();
        addKeyListener(new KeyAdapter() {
            @Override
            public void keyPressed(KeyEvent e) {
                if (gameOver) {
                    if (e.getKeyCode() == KeyEvent.VK_SPACE) {
                        initGame();
                    }
                    return;
                }
                switch (e.getKeyCode()) {
                    case KeyEvent.VK_W:
                    case KeyEvent.VK_UP:
                        if (velY != 1) { velX = 0; velY = -1; }
                        break;
                    case KeyEvent.VK_S:
                    case KeyEvent.VK_DOWN:
                        if (velY != -1) { velX = 0; velY = 1; }
                        break;
                    case KeyEvent.VK_A:
                    case KeyEvent.VK_LEFT:
                        if (velX != 1) { velX = -1; velY = 0; }
                        break;
                    case KeyEvent.VK_D:
                    case KeyEvent.VK_RIGHT:
                        if (velX != -1) { velX = 1; velY = 0; }
                        break;
                }
            }
        });
        timer = new Timer(100, this);
        timer.start();
    }

    private void loadImages() {
        try {
            appleImage = ImageIO.read(getClass().getResource("/apple.png"))
                             .getScaledInstance(BODY_SIZE, BODY_SIZE, Image.SCALE_SMOOTH);
            grassImage = ImageIO.read(getClass().getResource("/grass.png"))
                             .getScaledInstance(boardWidth, boardHeight, Image.SCALE_SMOOTH);
        } catch (IOException | IllegalArgumentException e) {
            appleImage = null;
            grassImage = null;
            System.err.println("Error loading images: " + e.getMessage());
        }
    }

    private void initGame() {
        snakeHead = new Body(cols / 2, rows / 2);
        snakeBody.clear();
        placeFood();
        gameOver = false;
        velX = 0;
        velY = 0;
        if (timer != null && !timer.isRunning()) {
            timer.start();
        }
    }

    private void placeFood() {
        int fx, fy;
        boolean validPosition;
        do {
            fx = random.nextInt(cols);
            fy = random.nextInt(rows);
            final int finalFx = fx;
            final int finalFy = fy;
            validPosition = !(snakeHead.x == finalFx && snakeHead.y == finalFy) &&
                          !snakeBody.stream().anyMatch(b -> b.x == finalFx && b.y == finalFy);
        } while (!validPosition);
        food = new Body(fx, fy);
    }

    private boolean collision(Body a, Body b) {
        return a.x == b.x && a.y == b.y;
    }

    private void move() {
        if (collision(snakeHead, food)) {
            snakeBody.add(new Body(food.x, food.y));
            placeFood();
        }
        for (int i = snakeBody.size() - 1; i >= 0; i--) {
            Body part = snakeBody.get(i);
            if (i == 0) {
                part.x = snakeHead.x;
                part.y = snakeHead.y;
            } else {
                Body prev = snakeBody.get(i - 1);
                part.x = prev.x;
                part.y = prev.y;
            }
        }
        snakeHead.x += velX;
        snakeHead.y += velY;
        if (snakeHead.x < 0 || snakeHead.x >= cols ||
            snakeHead.y < 0 || snakeHead.y >= rows) {
            gameOver = true;
        }
        for (Body part : snakeBody) {
            if (collision(snakeHead, part)) {
                gameOver = true;
                break;
            }
        }
        if (gameOver) timer.stop();
    }

    @Override
    protected void paintComponent(Graphics g) {
        super.paintComponent(g);
        draw((Graphics2D) g);
    }

    private void draw(Graphics2D g2) {
        if (grassImage != null) {
            g2.drawImage(grassImage, 0, 0, this);
        } else {
            g2.setColor(Color.BLACK);
            g2.fillRect(0, 0, boardWidth, boardHeight);
        }

        if (appleImage != null) {
            g2.drawImage(appleImage, food.x * BODY_SIZE, food.y * BODY_SIZE, this);
        } else {
            g2.setColor(Color.RED);
            g2.fillOval(food.x * BODY_SIZE, food.y * BODY_SIZE, BODY_SIZE, BODY_SIZE);
        }

        g2.setColor(new Color(0, 100, 0));
        g2.fill3DRect(snakeHead.x * BODY_SIZE, snakeHead.y * BODY_SIZE, BODY_SIZE, BODY_SIZE, true);

        for (Body b : snakeBody) {
            g2.setColor(new Color(0, 128, 0));
            g2.fill3DRect(b.x * BODY_SIZE, b.y * BODY_SIZE, BODY_SIZE, BODY_SIZE, true);
        }

        g2.setFont(new Font("Arial", Font.BOLD, 18));
        g2.setColor(Color.WHITE);
        g2.drawString("Score: " + snakeBody.size(), 10, 20);

        if (gameOver) {
            g2.setColor(new Color(0, 0, 0, 180));
            g2.fillRect(0, 0, boardWidth, boardHeight);

            String gameOverText = "GAME OVER";
            String scoreText = "Score: " + snakeBody.size();
            String restartText = "Press SPACE to restart";

            Font bigFont = new Font("Impact", Font.BOLD, 72);
            Font mediumFont = new Font("Arial", Font.BOLD, 36);
            Font smallFont = new Font("Arial", Font.PLAIN, 24);

            FontMetrics bigFm = g2.getFontMetrics(bigFont);
            FontMetrics mediumFm = g2.getFontMetrics(mediumFont);
            FontMetrics smallFm = g2.getFontMetrics(smallFont);

            int totalHeight = bigFm.getHeight() + mediumFm.getHeight() + smallFm.getHeight() + 40;
            int startY = (boardHeight - totalHeight) / 2 + bigFm.getAscent();

            g2.setFont(bigFont);
            g2.setColor(new Color(200, 0, 0));
            g2.drawString(gameOverText, (boardWidth - bigFm.stringWidth(gameOverText)) / 2 + 3, startY + 3);
            g2.setColor(new Color(255, 50, 50));
            g2.drawString(gameOverText, (boardWidth - bigFm.stringWidth(gameOverText)) / 2, startY);

            g2.setFont(mediumFont);
            g2.setColor(Color.WHITE);
            g2.drawString(scoreText, (boardWidth - mediumFm.stringWidth(scoreText)) / 2, startY + bigFm.getHeight() + 20);

            if ((System.currentTimeMillis() / 500) % 2 == 0) {
                g2.setFont(smallFont);
                g2.setColor(new Color(255, 255, 255));
                g2.drawString(restartText, (boardWidth - smallFm.stringWidth(restartText)) / 2,
                        startY + bigFm.getHeight() + mediumFm.getHeight() + 40);
            }
        }
    }

    @Override
    public void actionPerformed(ActionEvent e) {
        if (!gameOver) {
            move();
        }
        repaint();
    }

    public static void main(String[] args) {
        SwingUtilities.invokeLater(() -> {
            JFrame frame = new JFrame("Snake Game");
            Snake gamePanel = new Snake(600, 600);
            frame.add(gamePanel);
            frame.pack();
            frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
            frame.setResizable(false);
            frame.setLocationRelativeTo(null);
            frame.setVisible(true);
            gamePanel.requestFocusInWindow();
        });
    }
}