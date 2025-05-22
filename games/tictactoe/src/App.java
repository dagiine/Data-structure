import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class App extends JFrame implements ActionListener {
    static final char HUMAN = 'O';
    static final char COMPUTER = 'X';
    static final char EMPTY = '_';

    char[][] board = new char[3][3];
    JButton[][] buttons = new JButton[3][3];

    public App() {
        setTitle("Tic-Tac-Toe");
        setSize(400, 400);
        setLayout(new GridLayout(3, 3));
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                board[i][j] = EMPTY;
                buttons[i][j] = new JButton("");
                buttons[i][j].setFont(new Font("Arial", Font.BOLD, 60));
                buttons[i][j].addActionListener(this);
                add(buttons[i][j]);
            }
        }

        setVisible(true);
    }

    public void actionPerformed(ActionEvent e) {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (e.getSource() == buttons[i][j] && board[i][j] == EMPTY) {
                    board[i][j] = HUMAN;
                    buttons[i][j].setText("" + HUMAN);
                    buttons[i][j].setEnabled(false);

                    if (evaluate() == -10) {
                        showResult("Та яллаа!");
                        return;
                    }

                    if (!isMovesLeft()) {
                        showResult("Тэнцлээ!");
                        return;
                    }

                    int[] move = findBestMove();
                    board[move[0]][move[1]] = COMPUTER;
                    buttons[move[0]][move[1]].setText("" + COMPUTER);
                    buttons[move[0]][move[1]].setEnabled(false);

                    if (evaluate() == 10) {
                        showResult("Компьютер яллаа!");
                        return;
                    }

                    if (!isMovesLeft()) {
                        showResult("Тэнцлээ!");
                        return;
                    }
                }
            }
        }
    }

    void showResult(String message) {
        JOptionPane.showMessageDialog(this, message);
        System.exit(0);
    }

    int evaluate() {
        for (int i = 0; i < 3; i++) {
            if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
                if (board[i][0] == COMPUTER) return 10;
                if (board[i][0] == HUMAN) return -10;
            }
        }

        for (int j = 0; j < 3; j++) {
            if (board[0][j] == board[1][j] && board[1][j] == board[2][j]) {
                if (board[0][j] == COMPUTER) return 10;
                if (board[0][j] == HUMAN) return -10;
            }
        }

        if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
            if (board[0][0] == COMPUTER) return 10;
            if (board[0][0] == HUMAN) return -10;
        }

        if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
            if (board[0][2] == COMPUTER) return 10;
            if (board[0][2] == HUMAN) return -10;
        }

        return 0;
    }

    boolean isMovesLeft() {
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                if (board[i][j] == EMPTY)
                    return true;
        return false;
    }

    int minimax(int depth, boolean isComputer) {
        int score = evaluate();

        if (score == 10 || score == -10) return score;
        if (!isMovesLeft()) return 0;

        if (isComputer) {
            int best = -1000;
            for (int i = 0; i < 3; i++)
                for (int j = 0; j < 3; j++)
                    if (board[i][j] == EMPTY) {
                        board[i][j] = COMPUTER;
                        best = Math.max(best, minimax(depth + 1, false));
                        board[i][j] = EMPTY;
                    }
            return best;
        } else {
            int best = 1000;
            for (int i = 0; i < 3; i++)
                for (int j = 0; j < 3; j++)
                    if (board[i][j] == EMPTY) {
                        board[i][j] = HUMAN;
                        best = Math.min(best, minimax(depth + 1, true));
                        board[i][j] = EMPTY;
                    }
            return best;
        }
    }

    int[] findBestMove() {
        int bestVal = -1000;
        int[] bestMove = { -1, -1 };

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[i][j] == EMPTY) {
                    board[i][j] = COMPUTER;
                    int moveVal = minimax(0, false);
                    board[i][j] = EMPTY;

                    if (moveVal > bestVal) {
                        bestVal = moveVal;
                        bestMove[0] = i;
                        bestMove[1] = j;
                    }
                }
            }
        }

        return bestMove;
    }

    public static void main(String[] args) {
        new App();
    }
}