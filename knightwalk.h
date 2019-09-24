#pragma once
/* knightwalk.h - knightm Walk에 필요한 header file */
#pragma once
#include <iostream>
using namespace std;
struct Offsets {
	int a, b;
};
enum directions { NE, EN, ES, SE, SW, WS, WN, NW };
Offsets Move[8] = { {1,-2},{2,-1},{2,1},{1,2},{-1,2},{-2,1},{-2,-1},{-1,-2} };
//[g,h] <= [i,j], g = i + move[NE].a; h = j + move[NE].b;
class Chessboard {
public:
	Chessboard(int row=8, int col=8);//체스판 배열을 생성자로 호출
	void initialize();//체스판 배열의 각 cell = 0으로 초기화
	Offsets Walk(Offsets now);//난수를 불러 now 다음 위치를 결정
	int CheckComplete();//모든 cell이 nonzero면 종료
	int CheckBoundary(Offsets nextPosition);
	void Mark(const Offsets chess);
	void CountMove(int row, int col);//[row,col]에 대하여 1번 이동, 2번 이동 등
	friend ostream& operator << (ostream& stream, Chessboard& s);
private:
	int rows, cols;
	int* Term;//the add 2.6ress of a[i][j] = 0 + i * cols + j => Fig2.6
};