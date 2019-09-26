/* randomwalk.cpp - random walk simulation */
#include "knightwalk.h"
void Chessboard::Mark(const Offsets) {

}
int main(void) {
	Chessboard board(8, 8);
	struct Offsets startPosition;
	KnightWalk(board, startPosition);
	NthMove(board, startPosition);
}
void KnightWalk(Chessboard board, const struct Offsets position) {
	//start from position
	directions nextMove;;
	struct Offsets nextPosition;
	nextPosition = position;
	board.Mark(position);
	while (!board.CheckComplete()) {
		nextMove = (directions)(8.0 * rand());
		struct Offsets newPosition;
		newPosition.a = nextPosition.a + Move[nextMove].a;
		newPosition.b = nextPosition.b + Move[nextMove].b;
		if (!board.CheckBoundary(newPosition)) continue;
		else
			board.Mark(newPosition);
		nextPosition = newPosition;
	}
	cout << board;
}
void NthMove(Chessboard board, const struct Offsets position) {
	//start from position
	int nthTry = 0;
	directions nextMove;;
	struct Offsets nextPosition;
	nextPosition = position;
	board.MarkNth(position, nthTry);
	while (!board.CheckComplete()) {
		//nextMove = (directions)(8.0 * rand());
		nthTry++;
		//stack을 이용하여 pop
		for (directions d = NE; d <= NW; d++)
		{
			struct Offsets newPosition;
			newPosition.a = nextPosition.a + Move[nextMove].a;
			newPosition.b = nextPosition.b + Move[nextMove].b;
			if (!board.CheckBoundary(newPosition)) continue;
			else
				board.MarkNth(newPosition, nthTry);
			nextPosition = newPosition;
			//stack에 push 필요
		}

	}
	cout << board;
}