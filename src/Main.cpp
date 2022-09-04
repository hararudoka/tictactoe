#include <iostream>

// here we calling for "library" named std. it contains useful stuff
using namespace std;

class game
{
    // public means that these functions and fields (but here are no fields) can be called from outside the class
    public:
    // initializer of the class
    game()
    {
        // create empty board. we can not assign it with {...} value because it is not a initialization
        // i was shocked when i found out that it is not possible... so i created this ugly loop
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                board[i][j] = ' ';
            }
        }
    }

    // run game
    void run() {
        while (true) {
            print();
            checkWin();
            if (nowX) {
                cout << "X turn" << endl;
                input();
                if (place(x, y, 'X')) {
                    nowX = false;
                } else {
                    nowX = true;
                }
               
            } else {
                cout << "O turn" << endl;
                input();
                if (place(x, y, 'O')) {
                    nowX = true;
                } else {
                    nowX = false;
                }
            }
        }
    }

    // like public but visa verse
    private:
    // place X or O on the board
    bool place(int x, int y, char c)
    {
        if (board[x][y] == ' ')
        {
            board[x][y] = c;
            return true;
        } else {
            return false;
        }
        return true;
    }

    // send string of board to cout
    void print()
    {
        clear();
        // print game's name
        cout << "Tic Tac Toe" << endl;
        cout << "  0 1 2" << endl;

        // fill string with board
        for (int i = 0; i < 3; i++)
        {
            cout << i << '|';
            for (int j = 0; j < 3; j++)
            {
                // we reverse i and j because we want to print board with x and y axis like in math
                cout << board[j][i];
                cout << '|';
            }
            cout << endl;
        }

        cout << endl;
    }

    // check board for winning lines
    void checkWin() {
        // check rows
        for (int i = 0; i < 3; i++)
        {
            if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ') {
                cout << "Player " << board[i][0] << " won!" << endl;
                exit(0);
            }
        }

        // check columns
        for (int i = 0; i < 3; i++)
        {
            if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ') {
                cout << "Player " << board[0][i] << " won!" << endl;
                exit(0);
            }
        }

        // check diagonals
        if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ') {
            cout << "Player " << board[0][0] << " won!" << endl;
            exit(0);
        }

        if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ') {
            cout << "Player " << board[0][2] << " won!" << endl;
            exit(0);
        }
    }

    // clear screen (and some more pretty stuff)
    void clear() {
        cout << "\x1b[48;5;0m\x1b[38;5;231m\033[H\033[2J\033[1;1H";
    }

    // just input x and y
    void input() {
        while (cout << "> " && !(cin >> x >> y))
        {
            // idk that it is, i just copied it from internet
            cin.clear(); // clear bad input flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // discard input
            cout << "invalid input; please re-enter.\n";
        }
    }

    // last input
    int x, y;

    // true if X's turn, false if O's turn
    bool nowX;

    // field of board
    char board[3][3];
};

// entry point of whole program
int main() {
    // init game class
    game g;
    // call run function
    g.run();
}
