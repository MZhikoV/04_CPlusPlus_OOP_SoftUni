#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

class Board {
    
    private:
        char board[10][10];

    public: 

        Board(istream & istr);

        void print(ostream & ostr) {
            for(size_t x=0; x<10; x++) {
                for(size_t col = 0; col<10; col++)
                    ostr << board[x][col];
                ostr << endl;
            }
        }

        void set(size_t row, size_t col, char m);
        char get(size_t row, size_t col) { return board[row][col]; }
};

Board::Board(istream & istr) {

	for(size_t x=0; x<10; x++) {
		string buff;
		getline(istr, buff);
		for(size_t col = 0; col<10; col++)
			board[x][col] = buff[col];
	}
}

void Board::set(size_t row, size_t col, char m) {
	if (row<10 && col<10)
		if (board[row][col] != '#' && board[row][col] != '!')
			board[row][col] = m;
}

class Rust {

    const char new_rust = '?';
    const char old_rust = '!';

    private:
        Board board;

    public:
        Rust(istream & istr) 
            : board(istr) 
        {
        }

        void processBoard()
        {
            for(size_t row=0; row<10; row++)
                for(size_t col = 0; col<10; col++)
                    if (board.get(row, col) == old_rust) {
                        // mark the new rust
                        board.set(row-1, col, new_rust);
                        board.set(row+1, col, new_rust);
                        board.set(row  , col-1, new_rust);
                        board.set(row  , col+1, new_rust);
                    }

            for(size_t row=0; row<10; row++)
                for(size_t col = 0; col<10; col++)
                    if (board.get(row, col) == new_rust)
                        board.set(row, col, old_rust);
        }

        void printBoard(ostream & ostr) { board.print(ostr); }
};

int main() {

    Rust r(cin);

	size_t ticks;
	cin >> ticks;

	for(size_t tick = 0; tick < ticks; tick++)
		r.processBoard();

	r.printBoard(cout);
    
    system("pause");
    return 0;
}
