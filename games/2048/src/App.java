import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import java.util.Random;

public class App extends JPanel implements KeyListener {
    private static final int SIZE = 4;
    private static final int TILE_SIZE = 70;
    private static final int GAP = 5;
    private static final int WINNING_TILE = 2048;
    private int[][] board = new int[SIZE][SIZE];
    private int score = 0;
    private boolean gameOver = false;
    private boolean gameWon = false;

    public App() {
        setFocusable(true);
        addKeyListener(this);
        setPreferredSize(new Dimension(SIZE * (TILE_SIZE + GAP) + GAP, SIZE * (TILE_SIZE + GAP) + GAP + 40));
        initializeBoard();
    }

    private void initializeBoard() {
        score = 0;
        gameOver = false;
        board = new int[SIZE][SIZE];
        generateNewTile();
        generateNewTile();
        repaint();
    }

    private void generateNewTile() {
        Random random = new Random();
        int value = random.nextInt(10) < 9 ? 2 : 4;

        while (true) {
            int row = random.nextInt(SIZE);
            int col = random.nextInt(SIZE);
            if (board[row][col] == 0) {
                board[row][col] = value;
                break;
            }
        }
    }

    @Override
    public void paintComponent(Graphics g) {
        super.paintComponent(g);
        g.setFont(new Font("SansSerif", Font.BOLD, 18));
        g.setColor(Color.DARK_GRAY);
        g.drawString("Score: " + score, 20, 25);

        for (int row = 0; row < SIZE; row++) {
            for (int col = 0; col < SIZE; col++) {
                int value = board[row][col];
                int x = col * (TILE_SIZE + GAP) + GAP;
                int y = row * (TILE_SIZE + GAP) + GAP + 30;
                drawTile(g, x, y, value);
            }
        }

        if (gameOver) {
            g.setColor(new Color(0, 0, 0, 170));
            g.fillRect(0, 0, getWidth(), getHeight());
            g.setColor(Color.WHITE);
            g.setFont(new Font("SansSerif", Font.BOLD, 28));
            g.drawString("Game Over!", 80, getHeight() / 2);
        }

        if (gameWon) {
            g.setColor(new Color(0, 180, 0, 170));
            g.fillRect(0, 0, getWidth(), getHeight());
            g.setColor(Color.WHITE);
            g.setFont(new Font("SansSerif", Font.BOLD, 28));
            g.drawString("You Win!", 110, getHeight() / 2);
        }
    }

    private void drawTile(Graphics g, int x, int y, int value) {
        g.setColor(getTileColor(value));
        g.fillRoundRect(x, y, TILE_SIZE, TILE_SIZE, 10, 10);
        g.setColor(Color.BLACK);
        g.setFont(new Font("SansSerif", Font.BOLD, 18));
        if (value != 0) {
            FontMetrics fm = g.getFontMetrics();
            int strWidth = fm.stringWidth(String.valueOf(value));
            int strHeight = fm.getAscent();
            g.drawString(String.valueOf(value), x + (TILE_SIZE - strWidth) / 2, y + (TILE_SIZE + strHeight) / 2 - 4);
        }
    }

    private Color getTileColor(int value) {
        return switch (value) {
            case 2 -> new Color(0xeee4da);
            case 4 -> new Color(0xede0c8);
            case 8 -> new Color(0xf2b179);
            case 16 -> new Color(0xf59563);
            case 32 -> new Color(0xf67c5f);
            case 64 -> new Color(0xf65e3b);
            case 128 -> new Color(0xedcf72);
            case 256 -> new Color(0xedcc61);
            case 512 -> new Color(0xedc850);
            case 1024 -> new Color(0xedc53f);
            case 2048 -> new Color(0xedc22e);
            default -> new Color(0xcdc1b4);
        };
    }

    private void moveLeft() {
        boolean moved = false;
        for (int row = 0; row < SIZE; row++) {
            int[] temp = new int[SIZE];
            int index = 0;
            boolean merged = false;
            for (int col = 0; col < SIZE; col++) {
                if (board[row][col] != 0) {
                    if (index > 0 && temp[index - 1] == board[row][col] && !merged) {
                        temp[index - 1] *= 2;
                        score += temp[index - 1];
                        merged = true;
                        moved = true;
                    } else {
                        temp[index++] = board[row][col];
                        merged = false;
                        if (col != index - 1) moved = true;
                    }
                }
            }
            board[row] = temp;
        }
        if (moved) {
            generateNewTile();
            checkGameOver();
        }
    }

    private void moveRight() {
        rotateBoard(180);
        moveLeft();
        rotateBoard(180);
    }

    private void moveUp() {
        rotateBoard(270);
        moveLeft();
        rotateBoard(90);
    }

    private void moveDown() {
        rotateBoard(90);
        moveLeft();
        rotateBoard(270);
    }

    private void rotateBoard(int angle) {
        int[][] newBoard = new int[SIZE][SIZE];
        for (int row = 0; row < SIZE; row++) {
            for (int col = 0; col < SIZE; col++) {
                switch (angle) {
                    case 90 -> newBoard[col][SIZE - 1 - row] = board[row][col];
                    case 180 -> newBoard[SIZE - 1 - row][SIZE - 1 - col] = board[row][col];
                    case 270 -> newBoard[SIZE - 1 - col][row] = board[row][col];
                }
            }
        }
        board = newBoard;
    }

    private void checkGameOver() {
    for (int[] row : board) {
        for (int tile : row) {
            if (tile == WINNING_TILE && !gameWon) {
                gameWon = true;
                repaint();
                return;
            }
            if (tile == 0) return;
        }
    }

    for (int row = 0; row < SIZE; row++) {
        for (int col = 0; col < SIZE; col++) {
            if (col < SIZE - 1 && board[row][col] == board[row][col + 1]) return;
            if (row < SIZE - 1 && board[row][col] == board[row + 1][col]) return;
        }
    }

    gameOver = true;
    }

    @Override
    public void keyPressed(KeyEvent e) {
        if (gameOver) return;
        switch (e.getKeyCode()) {
            case KeyEvent.VK_LEFT -> moveLeft();
            case KeyEvent.VK_RIGHT -> moveRight();
            case KeyEvent.VK_UP -> moveUp();
            case KeyEvent.VK_DOWN -> moveDown();
        }
        repaint();
    }

    @Override public void keyReleased(KeyEvent e) {}
    @Override public void keyTyped(KeyEvent e) {}

    public static void main(String[] args) {
        JFrame frame = new JFrame("2048");
        App game = new App();
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setResizable(false);
        frame.setContentPane(game);
        frame.pack();
        frame.setLocationRelativeTo(null);
        frame.setVisible(true);
    }
}