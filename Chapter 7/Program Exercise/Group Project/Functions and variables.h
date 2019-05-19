0. Header files need to be included
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <iomanip>

1. Functions

1-0. int main()
	
	/* This function will control other functions to achieve the goal*/
	
	Steps:
	//variable definition
	char seat[N_row][N_seat]; //This is a 2D array used to store and update the seat information
	std::vector<double> price; //A double vector used to store prices
	char choice; //to hold choice user made at the menu
	double total=0; //to hold running total of ticket sales
	
	> load the price info into price vector, using load_price function.
	> initialize the seat info, using initialize_seat function.
	
	do
	{
		> display menu and accept input, call show_menu function.
		> use a swtich statement to perform different tasks switch(choice)
			case 1: buy ticket. call ticket_buying function; break;
			case 2: show seat diagram, call print_seat function; break;
			case 3: display temporary total sale data, call sale_report(seat, total); break;
			case 5: display help information (show all the txt info); break;
	} while (choice!='4');
	
	//if come this far, choice == 4, then print the report and exit
	sale_report_print(char const seat[][N_seat], double total);
	
	end here, return 0;


1-1. void load_price(std::vector<double> &price)
{
	//the vector should be passed by reference	
	/* This function will load price information from a txt file. */
	
	steps:
	double transfer; //used to transfer price info from txt file to vector (use push_back)
	int counter = 0; //counter used to count the total data number in file (to check)
	std::string path; //used to store the address of file
	std::ifstream cin(); //used to read the file
	
	> ask the user to input a file path to load the file
	> read the file and then determine if the file has 15 lines
		no: notice the user the file is incorrect, let the user input another path
			use a while loop to achieve this
		yes: close the file and reopen the file /*to re-initiate the reader*/
	> read the file again, to the transfer variable, save data to price vector
}

	
1-2. void initialize_seat(char seat[N_row][N_seat])
{
	/* This function will initialize the seat matrix to a status that all seats are 
	empty */
	
	steps:
	> use a nested for loop to assign '#' to all slots in seat[N_row][N_seat]
}
	

1-3. int show_menu(char &choice)
{
	/* This function will first print out menue and then ask the user to input their
	choices. Parameter is passed by reference. If user selected [4] quit, the function
	should double check. 
	After each operation, the program should call show_menu function to begin next 
	operation */
	
	steps:
	char double_check;
	
	do
	{
		> print the menu to console, ask the user to input a choice
		> input choice
		> check if choice is valid
			valid: choice can only be 1, 2, 3, 4 or 5
			in-valid: any other input, use a while loop to accept valid choice
		> check if choice is 4
			yes: print message (this will ....) and ask the user again (Y/N).
				Y: return to main() (return 0;)
				N: continue; continue the loop, to show the menu again and select again
			No: this means choice is 1, 2, 3 or 5. Under this condition, you can directly
				return to main(). (return 0;)
	} while (double_check='N');
}

	
	
1-4. void ticket_buying(char seat[][N_seat], std::vector<double> price, double &total)
{
	/* This program will ask for ticket buying info. The user can input one or multiple 
	tickets, they have to input -1 at end of their selection. The data structure for the
	ticket is: a b, where a is an integer from 1 to 15, which shows the row number; b is
	an integer from 1 to 30, which shows the seat number. For example, if a user input: 
	1 12 2 25 3 22 -1, it means he chooses three locations, row 1 seat 12, row 2 seat 25,
	row 3 seat 22. cin feature and keyboard buffer will be used to store these data properly.
	
	All data will first be save to a vector named raw_ticket. The first checking is: check 
	if the amount of data in the raw_ticket is even number. If not, the user must input 
	a -1 after he or she entered a row number (without inputting a seat number). If this is 
	the case, use pop_back member function to delete the last element (the extra row number).
	
	Then, the function begin transfer the data inside the raw_ticket into the ticket. 
	During this process, it has to screen the raw ticket data, just to make sure there 
	is no other errors. If there is any errors, the function will ask user to change. 
	If they choose not to change, the data will not be transferred to the final container
	(skipped). In this way, all data transferred to final container should be legal data, 
	which can be used to calculate total and modify seat[][].
	
	Errors need to be checked:
	1) the row number and seat number should be within the range. 0 < row number < N_row
		0 < seat number < N_seat
	2) the position selected should not be occupied
	
	*/
	
	std::vector<int> raw_ticket; //to hold the first input ticket of a user. 
	std::vector<int> ticket; //to hold the corrected ticket of a user (no errors)
	double sale=0; //hold the sub total for one customer
	char seat_buy[N_row][N_seat]; //this 2D array is used for showing specifically position bought in this purchase
	
	//copy seat info to seat_buy
	> copy seat to seat)buying
	
	//input raw_ticket data and check
	> input raw_ticket data into raw_ticket (using push_back function)
	> check the size of raw_ticket:
		even number: continue to next step.
		odd number: delete the last component (using .pop_back() member function), then 
					proceed.
	> begin transfer data from raw_ticket to ticket
		for (int i=0;i<raw_ticket.size();i+=2) //step size is 2, so everytime it begins at row
		{
			//check if row number and seat number is within right range
			while(raw_ticket[i]<1||raw_ticket[i]>15||raw_ticket[i+1]<1||raw_ticket[i+1]>30||seat[raw_ticket[i]-1][raw_ticket[i+1]-1]=='*') //raw_ticket[i] is natural row number, - 1 is the array index for corresponding row
			{
				if(seat[raw_ticket[i]-1][raw_ticket[i+1]-1]=='*')
					std::cout<<"Ticket " << i+1 << " has selected positions that are already occupied, would you want to select another position? (Y/N) ";
				else
					std::cout<<"Ticket " <<i+1 << " has selected illegal position, would you want to select another position? (Y/N) ";
				char choice;
				std::cin>>choice;
				> input check
				> decide
					Y: proceed to input another row and seat number;
					N: break; //if breaks here, there is no chance to revise the selection
				> input another row and seat number;
				> back to the head of while loop and check again
			}
			
			//transfer will be proceeded only if the selection is valid
			if(!(raw_ticket[i]<1||raw_ticket[i]>15||raw_ticket[i+1]<0||raw_ticket[i+1]>30||seat[raw_ticket[i]-1][raw_ticket[i+1]-1]=='*'))
			{
				ticket.push_back(raw_ticket[i]);
				ticket.push_back(raw_ticket[i+1]);
			}
				
		}
		
		//after the above loop, all data in the ticket is legal, proceed to calculating price and update seat 2D array
		for(int i=0;i<ticket.size();i+=2)
		{
			sale += price[ticket[i]-1]; //ticket[i] is the natural row number (begin at 1), -1 is to transfer to vector index
			seat[ticket[i]-1][ticket[i+1]-1]='*'; //update seat array
		}
		
		total += sale; //update sub total sale to total sale
		
		//show ticket info and sale for this purchase on console
		std::cout<<"Ticket information:\n";
		for(int i=0;i<ticket.size();i+=2)
			std::cout<<"row " <<ticket[i] << ", seat " <<ticket[i+1] <<std::cout;
		std::cout<<"Total will be: $" << sale <<". \n";
		
		//show specifically the ticket bought in this purchase (symbol is O)
		for(int i=0;i<ticket.size();i+=2)
		{			
			seat_buy[raw_ticket[i]-1][raw_ticket[i+1]-1]='O'; //update seat array
		}
		
		> print the seat diagram using print_seat function
		> after printing the seat diagram, notice the operator to press enter to continue
		> press enter to continue //this will back to the menu after quitting the function 
	

}


1-5. void print_seat(char const seat[][N_seat])
/* This function will print the seat diagram to the console */
{
	> use a nested for loop to print the figure that is passed to the function
	> no need to press to continue
}

1-6. void sale_report(char const seat[][N_seat], double total)
{
	/* This function will show following data:
		1) Sold and unsold position number in each row (from row 1 to 15)
		2) Total sold tickets number and total sales;
		3) The seating diagram of current status */
	
	//print table head
	std::cout<<"Row         Sold         Left\n"
	<<"--------------------------------\n";	
	
	//use a nested loop to check each row
	int total_ticket_sold=0;
	for(int i=0;i<N_row;i++)
	{
		int sold=0; //initialize a counter for sold position
		for(int j=0;j<N_seat;j++)
		{
			if(seat[i][j]=='*')
				sold++;
		}
		total_ticket_sold+=sold; //update total ticket sold
		std::cout <<std::setw(3) <<i+1 <<std::setw(13) <<sold <<std::setw(13) <<N_seat-sold <<std::endl;
	}
	
	//print table tail
	std::cout<<"--------------------------------\n";
	
	//print total tickets number and total sales figure
	std::cout<<"\nTotal Tickets Sold: " << total_ticket_sold<<std::endl
	<< "Total Sales: $" << total <<std::endl;
	
	//press enter to continue
	std::cout<< "Press Enter to Continue\n";
	std::cin.get();
	
}
	
1-7. void help()
{
	/* This function will display the help information, which will give introduction to different choices */
}

1-8. void sale_report_print(char const seat[][N_seat], double total)
{
	/* This function will print following data to a txt file
		1) Sold and unsold position number in each row (from row 1 to 15)
		2) Total sold tickets number and total sales;
		3) The seating diagram of current status */
	
	//create file write streamer
	std::ofstream cout;
	cout.open("D:\\Theater Sales Report.txt");
	
	//print table head
	cout<<"Theater Sales Report\n\n";
	cout<<"Row         Sold         Left\n"
	<<"--------------------------------\n";	
	
	//use a nested loop to check each row
	int total_ticket_sold=0;
	for(int i=0;i<N_row;i++)
	{
		int sold=0; //initialize a counter for sold position
		for(int j=0;j<N_seat;j++)
		{
			if(seat[i][j]=='*')
				sold++;
		}
		total_ticket_sold+=sold; //update total ticket sold
		cout <<std::setw(3) <<i+1 <<std::setw(13) <<sold <<std::setw(13) <<N_seat-sold <<std::endl;
	}
	
	//print table tail
	cout<<"--------------------------------\n";
	
	//print total tickets number and total sales figure
	cout<<"\nTotal Tickets Sold: " << total_ticket_sold<<std::endl
	<< "Total Sales: $" << total <<std::endl;
	
	//press enter to continue
	std::cout<< "Press Enter to Exit\n";
	std::cin.get();
	
} 

2. Global Constants
	const int N_row = 15, N_seat = 30;


