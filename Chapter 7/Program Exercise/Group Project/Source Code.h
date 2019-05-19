//Group Project: Theater Tickets Sales System
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <iomanip>

//global constant
const int N_row = 15, N_seat = 30;

//function prototype
void load_price(std::vector<double> &price);
void initialize_seat(char seat[N_row][N_seat]);
int show_menu(char &choice);
void ticket_buying(char seat[][N_seat], std::vector<double> price, double &total);
void print_seat(char const seat[][N_seat], std::vector<double> price);
void sale_report(char const seat[][N_seat], double total);
void help();
void sale_report_print(char const seat[][N_seat], double total, std::vector<double> price);


int main()
{
	//variable definition
	char seat[N_row][N_seat]; //This is a 2D array used to store and update the seat information
	std::vector<double> price; //A double vector used to store prices
	char choice; //to hold choice user made at the menu
	double total = 0; //to hold running total of ticket sales

	//show weicome screen
	std::cout << "Welcome to the Theater Sales System\n\n";

	//load price info by calling load_price function
	load_price(price);

	//initialize seat info by calling initialize seat function. This is to put '-' to all position
	initialize_seat(seat);

	//show menu and begin working, repeat the menu until an exit option has been choosen
	do
	{
		//display menu, input choice. choice from previous loops will be overwritten here
		show_menu(choice);

		//use a switch statement to do different things according to choice
		switch (choice)
		{
		case '1': ticket_buying(seat, price, total); break; //option 1 is buy ticket
		case '2': print_seat(seat, price); break;
		case '3': sale_report(seat, total); break;
		case '5': help(); break;
		}

	} while (choice != '4');

	//if come this far, choice == 4 (already double checked), time to write the final report to txt file and exit
	sale_report_print(seat, total, price);

	return 0;

}

//load_price function, to load price information into price vector
void load_price(std::vector<double> &price)
{
	//variable definition
	double transfer; //used to transfer price info from txt file to vector (use push_back)
	int counter = 0; //counter used to count the total data number in file (to check)
	std::string path; //used to store the address of file
	std::ifstream cin; //used to read the file

	//ask user to input a data file path
	std::cout << "Please input the path of the data file containing price information:";
	getline(std::cin, path);

	//read the file and then determine if the file has 15 lines
	cin.open(path);
	while (cin >> transfer)
		counter++;
	while (counter != 15)
	{
		std::cout << "File loading failed. Please check the path and try again, input another file path: ";
		//std::cin.ignore();
		getline(std::cin, path);
		cin.close();
		cin.open(path);
		counter = 0;
		while (cin >> transfer)
			counter++;
	}

	//close the file and open again, start to load data
	cin.close();
	cin.open(path);
	while (cin >> transfer)
		price.push_back(transfer); //price vector will be loaded with information from price data file after this loop

	//show complete
	std::cout << "\n\nLoading successful.\n\n";
}

//function: to put '-' to all slots
void initialize_seat(char seat[N_row][N_seat])
{
	for (int i = 0; i < N_row; i++)
	{
		for (int j = 0; j < N_seat; j++)
			seat[i][j] = '-';
	}
}

//To show menu and pick up a choice
int show_menu(char &choice)
{
	char double_check; //double check variable. If user inputed quit option, try to double check before sending this back to main function

	//print the menu to console, then ask the user to make a choice
	do
	{
		std::cout << "Please select options below:\n"
			<< "[1] Buy Ticket\n"
			<< "[2] Show Seating Diagram (with prices for each row)\n"
			<< "[3] View Total Ticket Sales\n"
			<< "[4] Print Report and Exit\n"
			<< "[5] Help\n\n";
		std::cin >> choice;
		//input check
		while (choice != '1'&&choice != '2'&&choice != '3'&&choice != '4'&&choice != '5')
		{
			std::cout << "Invalid input! You should input 1, 2, 3, 4 or 5: ";
			std::cin >> choice;
		}

		//check if choice == '4', if so, double check (if user changed his mind, print the menu again and select again, if not return to main function
		if (choice == '4') //if choice == '4'
		{
			std::cout << "This will print a final report and exit the program, are you sure you want to do that? (Y/N) ";
			std::cin >> double_check;
			while (double_check != 'Y'&&double_check != 'N'&&double_check != 'y'&&double_check != 'n')
			{
				std::cout << "Please input Y or N: ";
				std::cin >> double_check;
			}
			if (double_check == 'y' || double_check == 'Y')
				return 0;
			else
				continue;
		}
		else
			return 0; //under this circumstance, just return to main directly, because the program won't exit
	} while (double_check == 'N'||double_check=='n');

}

//ticket buying function
void ticket_buying(char seat[][N_seat], std::vector<double> price, double &total)
{
	//variable definition
	std::vector<int> raw_ticket; //to hold the first input ticket of a user. 
	std::vector<int> ticket; //to hold the corrected ticket of a user (no errors)
	double sale = 0; //hold the sub total for one customer, running total
	char seat_buy[N_row][N_seat]; //this 2D array is used for showing specifically position bought in this purchase
	int transfer; //to transfer ticket data from std::cin to vector

	//copy seat info to seat_buy
	for (int i = 0; i < N_row; i++)
	{
		for (int j = 0; j < N_seat; j++)
		{
			seat_buy[i][j] = seat[i][j];
		}
	}

	//input raw ticket data and check
		//input
	std::cout << "Please input the position you want to buy ticket. For example, 12 15 means row 12, seat 15. Add a -1 at the end of your purchase to finish inputting.\n";
	std::cin >> transfer;
	while (transfer == -1)
	{
		std::cout << "The first number is -1, please reinput:\n";
		std::cin >> transfer;
	}
		//use a for loop to read all data from keyboard buffer to transfer and then to raw_ticket vector
	for (int i = 0; i < N_row*N_seat+1; i++) //maximum number should be N_row*N_seat, +1 is for end sign (-1)
	{
		raw_ticket.push_back(transfer);
		std::cin >> transfer;
		if (transfer == -1)
			break;
	}

		//check the size of raw ticket data, it its odd, delete the last element (extra row number)
	if (raw_ticket.size() % 2 != 0)
		raw_ticket.pop_back();
		
		//go over the raw ticket data, then find out any repitition input. In this process the whole raw_ticket will be copied
		//to the end of this vector, and the final transfer will begin from behind
	int position = raw_ticket.size(); //record the final position of raw_ticket, the transfer from raw_ticket starts from position
	int position_dynamic = raw_ticket.size(); //explain below
	/* Two position indicator is used. static position and dynamic position. When copying data from the raw_ticket to 
	the copy section, you should use static position, because whether or not the repitition exists, the reading continue
	to a higher index number. it will read next two element in the raw_ticket. However, data saved in the copy region doesn't 
	contain repeated data, so you have to use a dynamic position to control the reading position (this reading position is used
	to compare the value between raw_ticket input section and copy section. If you deleted two repeat infor, you have subtract 2
	from the dynamic position, so (i+position_dynamic) and (i_position_dynamic+1) is always the last element in copy section*/
	for (int i = 0; i < position; i += 2)
	{
		//first, to copy the first two element to the last of raw_ticket
		raw_ticket.push_back(raw_ticket[i]);
		raw_ticket.push_back(raw_ticket[i + 1]);
		//go over the rest of raw_ticket (before the copied section), if there is one identical section, delete data copied
		//in copy section. This is a reverse deletion, in this way the repitition will be deleted first
		for (int j = i+2; j < position-1; j+=2)
		{
			//bool flag = true;
			if (raw_ticket[j] == raw_ticket[i + position_dynamic] && raw_ticket[j + 1] == raw_ticket[i + position_dynamic + 1])
			{
				raw_ticket.pop_back();
				raw_ticket.pop_back(); //delete the inputted data, because a repition is found
				position_dynamic -= 2;
				//flag = false;
				break; //After deleting the inputted two elements, you have to break, since if there is more than one repitition, you'll delete backward and ruin your raw inputted data
			}
			
		}
	}

	//At this point, the copy region of raw_ticket should be free of repitition data
	//begin transferring data in raw_ticket to ticket, check the content at every transfer, if data is good, transfer to ticket vector
	//transfer begins at the copy region
	for (int i = position; i < raw_ticket.size(); i += 2) //so every i is the row number index
	{
		//check if 1) row number and seat number is within right range; 2) whether the seat is occupied
		while (raw_ticket[i] < 1 || raw_ticket[i]>15 || raw_ticket[i + 1] < 1 || raw_ticket[i + 1]>30 || seat[raw_ticket[i] - 1][raw_ticket[i + 1] - 1] == 'O')
		{
			if (seat[raw_ticket[i] - 1][raw_ticket[i + 1] - 1] == 'O') //situation when the seat is occupied
				std::cout << "Ticket " << (i-position)/2 + 1 << " has selected positions that are already occupied, would you want to select another position? (Y/N) ";
			else
				std::cout << "Ticket " << (i-position)/2 + 1 << " has selected illegal position, would you want to select another position? (Y/N) ";			
			char choice; //to hold choice made when encountering bad data (failed data check)
			std::cin >> choice;
			while (choice != 'y'&&choice != 'n'&&choice != 'Y'&&choice != 'N')
			{
				std::cout << "Please input Y or N: ";
				std::cin >> choice;
			}
			if (choice == 'Y' || choice == 'y')
			{
				std::cout << "Please input the modified row and seat number, separate by a space: ";
				std::cin >> transfer;
				raw_ticket[i] = transfer;
				std::cin >> transfer;
				raw_ticket[i + 1] = transfer;
			}
			else
				break;
		}

		//if the data is good, transfer to ticket, if its bad, that means the user doesn't want to modify it, just skip
		if (!(raw_ticket[i] < 1 || raw_ticket[i]>15 || raw_ticket[i + 1] < 1 || raw_ticket[i + 1]>30 || seat[raw_ticket[i] - 1][raw_ticket[i + 1] - 1] == 'O'))
		{
			ticket.push_back(raw_ticket[i]);
			ticket.push_back(raw_ticket[i + 1]);
		}


	}

	//at this point, ticket should contain all good data, proceed to calculate price and update seat
	for (int i = 0; i < ticket.size(); i += 2)
	{
		sale += price[ticket[i] - 1]; //ticket[i] is the natural row number (begin at 1), -1 is to transfer to vector index
		seat[ticket[i] - 1][ticket[i + 1] - 1] = 'O'; //update seat
	}
	total += sale; //update total sale

	//show ticket info and seat diagram for this purchase
	std::cout << "Purchase complete! Details are follows:\n";
	for (int i = 0; i < ticket.size(); i += 2)
	{
		std::cout << "Row " << ticket[i] << ", seat " << ticket[i + 1] << std::endl;
	}
	std::cout << "Total: $" << sale << std::endl;
		//show the location of ticket bought in this purchase specifically
	for (int i = 0; i < ticket.size(); i+=2)
		seat_buy[ticket[i] - 1][ticket[i + 1] - 1] = 'X';
	print_seat(seat_buy,price);

	//displaying complete, press enter to continue
	std::cout << "Press Enter to Continue\n";
	std::cin.ignore();
	std::cin.get();

}

//print seat and corresponding price to the screen
void print_seat(char const seat[][N_seat], std::vector<double> price)
{
	//printing the stage
	std::cout 
		<< "                                         *************************************\n"
		<< "                                         *                                   *\n"
		<< "                                         *               STAGE               *\n"
		<< "                                         *                                   *\n"
		<< "                                         *************************************\n\n";

	//print seats line
	std::cout << "Seats      01  02  03  04  05  06  07  08  09  10  11  12  13  14  15  16  17  18  19  20  21  22  23  24  25  26  27  28  29  30\n";

	//use loop to print out all row information
	for (int i = 0; i < N_row; i++)
	{
		std::cout << "Row ";
		std::cout.fill('0');
		std::cout << std::setw(2) << i + 1 << "   ";
		std::cout.fill(' ');
		for (int j = 0; j < N_seat; j++)
		{
			std::cout << std::setw(4) << seat[i][j];
		}
		std::cout << "   ($" << price[i] << ")\n";
	}
	std::cout << "\n";
}

//show a temporary report on screen
void sale_report(char const seat[][N_seat], double total)
{
	//print table head
	std::cout << "Row         Sold         Left\n"
		<< "--------------------------------\n";

	//use a nested loop to check each row
	int total_ticket_sold = 0;
	for (int i = 0; i<N_row; i++)
	{
		int sold = 0; //initialize a counter for sold position
		for (int j = 0; j<N_seat; j++)
		{
			if (seat[i][j] == 'O')
				sold++;
		}
		total_ticket_sold += sold; //update total ticket sold
		std::cout << std::setw(3) << i + 1 << std::setw(13) << sold << std::setw(13) << N_seat - sold << std::endl;
	}

	//print table tail
	std::cout << "--------------------------------\n";

	//print total tickets number and total sales figure
	std::cout << "\nTotal Tickets Sold: " << total_ticket_sold << std::endl
		<< "Total Sales: $" << total << std::endl;

	//press enter to continue
	std::cout << "Press Enter to Continue\n";
	std::cin.ignore();
	std::cin.get();

}

//show the help information
void help()
{
	std::cout << "Choosing [1] to buy ticket. You will be prompted to input row and seat number. You can\n"
		<< "input as two integers. For example, if you want to select row 12, seat 23, just input\n"
		<< "12 23, separate by a space. You can buy multiple tickets by entering a series of row\n "
		<< "and seat numbers, add -1 at the end of your input to finish inputting.\n\n"
		<< "After selecting the row and seats, the price will be shown on screen.\n\n"
		<< "Choosing [2] to show the current seating diagram. The entire auditorium will be shown\n "
		<< "on screen. Symbol '-' represents seats that are not taken, 'O' represents seats that\n "
		<< "are already taken. Also, the price of each row will be displayed.\n\n"
		<< "Choosing [3] to view the total ticke sales information. This is a general report of\n "
		<< "ticket sale. It includes: 1), Total ticket sales; 2), Sold and unsold seats numbers in\n"
		<< "each row; 3) A seating diagram for current seats\n\n"
		<< "Choosing [4] when the sales is done. A summary report will be printed to a txt file.\n "
		<< "After that the program will quit.\n\n";

	std::cout << "Press Enter to Continue\n";
	std::cin.get();
}

void sale_report_print(char const seat[][N_seat], double total, std::vector<double> price)
{
	/* This function is almost identical with the sale_report function, except this function prints the report to
		a txt file.*/

	//create file write streamer
	std::ofstream cout;
	cout.open("D:\\Theater Sales Report.txt");

	//print table head
	cout << "Theater Sales Report\n\n";
	cout << "Row         Sold         Left\n"
		<< "--------------------------------\n";

	//use a nested loop to check each row
	int total_ticket_sold = 0;
	for (int i = 0; i<N_row; i++)
	{
		int sold = 0; //initialize a counter for sold position
		for (int j = 0; j<N_seat; j++)
		{
			if (seat[i][j] == 'O')
				sold++;
		}
		total_ticket_sold += sold; //update total ticket sold
		cout << std::setw(3) << i + 1 << std::setw(13) << sold << std::setw(13) << N_seat - sold << std::endl;
	}

	//print table tail
	cout << "--------------------------------\n";

	//print total tickets number and total sales figure
	cout << "\nTotal Tickets Sold: " << total_ticket_sold << std::endl
		<< "Total Sales: $" << total << std::endl;

	//print seat diagram
	//printing the stage
	cout
		<<"\n\nAuditorium Diagram\n\n"
		<< "                                         *************************************\n"
		<< "                                         *                                   *\n"
		<< "                                         *               STAGE               *\n"
		<< "                                         *                                   *\n"
		<< "                                         *************************************\n\n";

	//print seats line
	cout << "Seats      01  02  03  04  05  06  07  08  09  10  11  12  13  14  15  16  17  18  19  20  21  22  23  24  25  26  27  28  29  30\n";

	//use loop to print out all row information
	for (int i = 0; i < N_row; i++)
	{
		cout << "Row ";
		cout.fill('0');
		cout << std::setw(2) << i + 1 << "   ";
		cout.fill(' ');
		for (int j = 0; j < N_seat; j++)
		{
			cout << std::setw(4) << seat[i][j];
		}
		cout << "   ($" << price[i] << ")\n";
	}
	cout << "\n";

	//press enter to continue
	std::cout << "Press Enter to Exit\n";
	std::cin.ignore();
	std::cin.get();
}