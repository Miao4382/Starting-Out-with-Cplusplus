//18. Tic-Tac-Toe Game
#include<iostream>


//function prototype
void board_printing(char board[3][3]);
int check_result(char board[3][3]); //return type: 1: P1 win, 2: P2 win, 3: tie, 4: continue game
void p1_play(char board[3][3]);
void p2_play(char board[3][3]);
int welcome();

int main()
{
	char board[3][3] = { {'*','*','*'},{'*','*','*'},{'*','*','*'} };
	int result = 4;
	
	//show a welcome interface
	welcome();
	std::cout << "\n";
	board_printing(board);

	//as long as result = 4, game continues
	while (result == 4)
	{

		//Player 1 turn
		std::cout << "\nPlayer 1 turn, please input your move: ";
		p1_play(board);
		board_printing(board);
		result=check_result(board);
		switch (result)
		{
		case 1: std::cout << "Player 1 won!\n"; break;
		case 3: std::cout << "This game is a tie.\n"; break;
		}
		if (result == 1 || result == 3) //if result is 1 or 3, no need to proceed
			break;

		//Player 2 turn
		std::cout << "\nPlayer 2 turn, please input your move: ";
		p2_play(board);
		board_printing(board);
		result = check_result(board);
		switch (result)
		{
		case 2: std::cout << "Player 2 won!\n"; break;
		case 3: std::cout << "This game is a tie.\n"; break;
		}
		if (result == 2 || result == 3) //if result is 2 or 3, no need to proceed
			break;

	}
	return 0;
}

//welcome interface, can teach user how to play
int welcome()
{
	char board[3][3] = { { 'X','O','X' },{ 'O','X','O' },{ 'X','O','X' } };
	char board2[3][3] = { { '*','*','*' },{ '*','*','*' },{ '*','*','*' } };
	board_printing(board);

	std::cout << "========\n\n";
	std::cout << "Welcome to Tic Tac Toe Game!\n"
		<< "Press 1 for help\n"
		<< "Press 2 to start\n";

	char choice;
	std::cin >> choice;
	while (choice != '1'&&choice != '2')
	{
		std::cout << "Please press 1 or 2: ";
		std::cin >> choice;
	}

	while (choice == '1')
	{
		std::cout << "Tic-tac-toe is a paper-and-pencil game for two players. You represent X or O.\n"
			<< "For this game, the board will be like this:\n\n";
		board_printing(board2);
		std::cout << "\nEvery '*' represent an empty location you can draw. you input a double-digit\n"
			<< "integer to draw your symbol. for example, if you input 23, you are going to\n"
			<< "draw at row 2, column 3.\n\n"
			<< "Symbol for player 1 is 'X', symbol for player 2 is 'O'. If there are three same\n"
			<< "symbols appear on the board, the player wins. A tie occurs when all of the \n"
			<< "board locations are full, but there is no winner. Press 2 to start!\n";
		std::cin >> choice;
		while (choice != '1'&&choice != '2')
		{
			std::cout << "Please press 1 or 2: ";
			std::cin >> choice;
		}
		if (choice == '2')
			return 0;
	}
}

//board printing function
void board_printing(char board[3][3])
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
			std::cout << board[i][j] << "  ";
		std::cout << "\n";
	}
}

//check result function
int check_result(char board[3][3])
{

	//win or loss check
	//row iteration
	for (int row_counter = 0; row_counter < 3; row_counter++)
	{
		if ((board[row_counter][0] == board[row_counter][1]) && (board[row_counter][1] == board[row_counter][2]))
		{
			if (board[row_counter][0] == 'X')
				return 1;
			else if (board[row_counter][0] == 'O')
				return 2;
			else
				continue; //this is the situation where they both equal to '*'
		}
	}
	//column iteration
	for (int column_counter = 0; column_counter < 3; column_counter++)
	{
		if ((board[0][column_counter] == board[1][column_counter]) && (board[1][column_counter] == board[2][column_counter]))
		{
			if (board[0][column_counter] == 'X')
				return 1;
			else if (board[0][column_counter] == 'O')
				return 2;
			else
				continue;
		}
	}
	//diagonal check
	if ((board[0][0] == board[1][1]) && (board[1][1] == board[2][2]))
	{
		if (board[0][0] == 'X')
			return 1;
		else if (board[0][0] == 'O')
			return 2;
		else;
	}
	if ((board[0][2] == board[1][1]) && (board[1][1] == board[2][0]))
	{
		if (board[0][2] == 'X')
			return 1;
		else if(board[0][2] == 'O')
			return 2;
		else;
	}

	//tie check: if no win or loss, and there is no free space, then the game is tie
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
			if (board[i][j] == '*') //if free space is found during the iteration, game continues
				return 4;
	}

	return 3; //if no space is found, and no win or loss, return 3: the game is tie
}

//player 1 move function
void p1_play(char board[3][3])
{
	int move, row, column;
	std::cin >> move;
	while (move != 11 && move != 12 && move != 13 && move != 21 && move != 22 && move != 23 && move != 31 && move != 32 && move != 33)
	{
		std::cout << "Invalid move! Please input proper move:	";
		std::cin >> move;
	}
	row = move / 10-1;
	column = move % 10-1;
	while (board[row][column] != '*')
	{
		std::cout << "That location is already occupied! Please pick another location: ";
		std::cin >> move;
		while (move != 11 && move != 12 && move != 13 && move != 21 && move != 22 && move != 23 && move != 31 && move != 32 && move != 33)
		{
			std::cout << "Invalid move! Please input proper move:	";
			std::cin >> move;
		}
		row = move / 10-1;
		column = move % 10-1;
	}
	board[row][column] = 'X';
}

//player 2 move function
void p2_play(char board[3][3])
{
	int move, row, column;
	std::cin >> move;
	while (move != 11 && move != 12 && move != 13 && move != 21 && move != 22 && move != 23 && move != 31 && move != 32 && move != 33)
	{
		std::cout << "Invalid move! Please input proper move:	";
		std::cin >> move;
	}
	row = move / 10-1;
	column = move % 10-1;
	while (board[row][column] != '*')
	{
		std::cout << "That location is already occupied! Please pick another location: ";
		std::cin >> move;
		while (move != 11 && move != 12 && move != 13 && move != 21 && move != 22 && move != 23 && move != 31 && move != 32 && move != 33)
		{
			std::cout << "Invalid move! Please input proper move:	";
			std::cin >> move;
		}
		row = move / 10-1;
		column = move % 10-1;
	}
	board[row][column] = 'O';
}