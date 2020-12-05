/**
 * Unit Tests for TicTacToeBoard
**/

#include <gtest/gtest.h>
#include "TicTacToeBoard.h"
 
class TicTacToeBoardTest : public ::testing::Test
{
	protected:
		TicTacToeBoardTest(){} //constructor runs before each test
		virtual ~TicTacToeBoardTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor) 
};

/* EXAMPLE TEST FORMAT
TEST(TicTacToeBoardTest, unitTestName)
{
	ASSERT_TRUE(true);
}
*/

//Checks if out of bounds detection works
TEST(TicTacToeBoardTest, out_of_bounds){
	TicTacToeBoard obj;
	ASSERT_EQ(obj.placePiece(0,3), Invalid);
}

//Checks if a filled spot returns properly
TEST(TicTacToeBoardTest, filled_spot){
	TicTacToeBoard obj;
	obj.placePiece(0,0);
	ASSERT_EQ(obj.placePiece(0,0), X);
}

//Checks if board is filled
TEST(TicTacToeBoardTest, filled_board){
	TicTacToeBoard obj;
	obj.placePiece(0,0);	//x
	obj.placePiece(1,1);	//o
	obj.placePiece(2,2);	//x
	obj.placePiece(0,2);	//o
	obj.placePiece(2,0);	//x
	obj.placePiece(2,1);	//o
	obj.placePiece(0,1);	//x
	obj.placePiece(1,0);	//o
	obj.placePiece(1,2);	//x
	ASSERT_EQ(obj.getWinner(), Blank);
}

//Checks if getWinner works
TEST(TicTacToeBoardTest, X_wins){
	TicTacToeBoard obj;
	obj.placePiece(1,1);	//x
	obj.placePiece(0,1);	//o
	obj.placePiece(2,2);	//x
	obj.placePiece(0,0);	//o
	obj.placePiece(0,2);	//x
	obj.placePiece(1,2);	//o
	obj.placePiece(2,0);	//x
	ASSERT_EQ(obj.getWinner(), X);
}

//Checks left side win condition
TEST(TicTacToeBoardTest, Left_side_win){
	TicTacToeBoard obj;
	obj.placePiece(0,0);
	obj.placePiece(1,1);
	obj.placePiece(0,1);
	obj.placePiece(2,2);
	obj.placePiece(0,2);
	ASSERT_EQ(obj.getWinner(), X);
}

//Checks right side win condition
TEST(TicTacToeBoardTest, Right_side_win){
	TicTacToeBoard obj;
	obj.placePiece(0,0);
	obj.placePiece(2,2);
	obj.placePiece(1,1);
	obj.placePiece(2,1);
	obj.placePiece(1,2);
	obj.placePiece(2,0);
	ASSERT_EQ(obj.getWinner(), O);
}

//Checks right side win condition
TEST(TicTacToeBoardTest, Top_side_win){
	TicTacToeBoard obj;
	obj.placePiece(0,0);
	obj.placePiece(1,1);
	obj.placePiece(1,0);
	obj.placePiece(2,2);
	obj.placePiece(2,0);
	ASSERT_EQ(obj.getWinner(), X);
}

//Checks right side win condition
TEST(TicTacToeBoardTest, Bottom_side_win){
	TicTacToeBoard obj;
	obj.placePiece(0,0);
	obj.placePiece(2,2);
	obj.placePiece(1,1);
	obj.placePiece(2,1);
	obj.placePiece(1,2);
	obj.placePiece(0,2);
	ASSERT_EQ(obj.getWinner(), O);
}

//Checks if X starts
TEST(TicTacToeBoardTest, X_starts){
	TicTacToeBoard obj;
	ASSERT_EQ(obj.placePiece(0,0), X);
}

//Checks for blank spot
TEST(TicTacToeBoardTest, Blank_check){
	TicTacToeBoard obj;
	ASSERT_EQ(obj.getPiece(1,1), ' ');
}

//Force skip 'O' turn and check for X
TEST(TicTacToeBoardTest, turn_check){
	TicTacToeBoard obj;
	obj.placePiece(0,0);
	ASSERT_EQ(obj.toggleTurn(), X);	
}

TEST(TicTacToeBoardTest, Not_over){
	TicTacToeBoard obj;
	obj.placePiece(0,0);
	obj.placePiece(1,1);
	ASSERT_EQ(obj.getWinner(), Invalid);
}