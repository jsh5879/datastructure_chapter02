/* randomwalk.cpp - random walk simulation */
#include "randomwalk.h"
void Chessboard::Mark(const Offsets) {

}
int main(void) {
	Chessboard g(10, 10);
	struct Offsets startPosition;
	Walk(g, startPosition);
}
void Walk(Chessboard g, const struct Offsets position) {
	//start from position
	directions randomMove;;//random number
	struct Offsets nextPosition;
	nextPosition = position;
	g.Mark(position);
	while (!g.CheckComplete()) {
		randomMove = (directions)(8.0 * rand());
		struct Offsets newPosition;
		newPosition.a = nextPosition.a + Move[randomMove].a;
		newPosition.b = nextPosition.b + Move[randomMove].b;
		if (!g.CheckBoundary(newPosition)) continue;
		else
			g.Mark(newPosition);
		nextPosition = newPosition;
	}
	cout << g;
}