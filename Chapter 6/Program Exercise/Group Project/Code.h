#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

//global variable
int num_days_total;
int hour_depart, min_depart, hour_arrive, min_arrive;

//global constant
const double CAR_EXPENSE = 0.27,
PARKING_MAX = 6,
TAXI_MAX = 10,
HOTEL_EXPENSE = 90,
BREAKFAST_EXPENSE = 9,
LUNCH_EXPENSE = 12,
DINNER_EXPENSE = 16;

//function prototype
void create_report();
void transportation_expense(double &transportation_allowed, double &transportation_saved, double &transportation_total);
double conference_expense();
void hotel_expense(double &hotel_total, double &hotel_saved, double &hotel_allowed);
void food_expense(double &food_total, double &food_allowed, double &food_saved);


int main()
{
	//create a file stream object
	std::ofstream cout;

	//ask for how many days of travel, departure time and arrival time
	std::cout << "How many days of travel: ";
	std::cin >> num_days_total;
	std::cout << "What is the departure time, input format is: hh:mm, 24 hours.\n";
	std::cin >> hour_depart;
	std::cin.ignore();
	std::cin >> min_depart;
	std::cout << "What is the arrival time,  input format is: hh:mm, 24 hours.\n";
	std::cin >> hour_arrive;
	std::cin.ignore();
	std::cin >> min_arrive;

	//write the head of the report and overview
	cout.open("D:\\overview.txt");
	cout << std::setw(57) << "Travel Expenses Report\n"
		<< "-------------------------------------------------------------------------------------------\n\n\n"
		<< "**Overview**\n"
		<< "-------------------------------------------------------------------------------------------\n"
		<< "This section displays the total travel days, departure and arrival time.\n\n"
		<< "Overview:\n"
		<< std::left << std::setw(25) << "Total Travel Days" << std::right << std::setw(5) << num_days_total << std::endl
		<< std::left << std::setw(25) << "Departure Time" << std::right << hour_depart << ":" << min_depart << std::endl
		<< std::left << std::setw(25) << "Back Time" << std::right << hour_arrive << ":" << min_arrive << std::endl
		<< "-------------------------------------------------------------------------------------------\n\n\n";
	cout.close();

	//transportation expense
	std::cout << "\n\nSection 1: transportation expense analysis\n\n";
	double transportation_allowed, transportation_saved, transportation_total;
	transportation_expense(transportation_allowed, transportation_saved, transportation_total);

	//conference and seminar registration expense
	std::cout << "\n\nSection 2: conference expense analysis\n\n";
	double registration_fee;
	registration_fee = conference_expense();

	//hotel expense
	std::cout << "\n\nSection 3: hotel expense analysis\n\n";
	double hotel_total=0, hotel_saved=0, hotel_allowed;
	hotel_expense(hotel_total, hotel_saved, hotel_allowed);

	//food expense
	std::cout << "\n\nSection 4: food expense analysis\n\n";
	double food_total = 0, food_allowed=0, food_saved = 0;
	food_expense(food_total, food_allowed, food_saved);

	//calculate total expense, allowable expense and saved amount, create a summary report
	double total_expense, total_allow, total_saved;
	total_expense = transportation_total + registration_fee + hotel_total + food_total;
	total_allow = transportation_allowed + hotel_allowed + food_allowed+registration_fee;
	total_saved = transportation_saved + hotel_saved + food_saved;
	
	cout.open("D:\\summary.txt");
	cout << "**Summary**\n"
		<< "-------------------------------------------------------------------------------------------\n";
	cout << std::left << std::setw(37) << "Total expense" << "$" << std::right << std::setw(15) << total_expense << "\n\n";
	cout << std::left << std::setw(37) << "Total allowed expense" << "$" << std::right << std::setw(15) << total_allow << "\n\n";
	if(total_saved>=0)
		cout << std::left << std::setw(37) << "Total saved expense" << "$" << std::right << std::setw(15) << total_saved << "\n\n";
	else
		cout << std::left << std::setw(37) << "Expense needs reimbursing" << "$" << std::right << std::setw(15) << -total_saved << "\n\n";
	cout << "-------------------------------------------------------------------------------------------\n";
	cout.close();

	//call create report function to generate a complete report
	create_report();

	return 0;
}

//to copy all other file into one file and create a report
void create_report()
{
	//create a file stream object: read file
	std::ifstream cin;
	cin.open("D:\\overview.txt");

	//create a file stream object: write file
	std::ofstream cout;
	cout.open("D:\\Travel Expense Report.txt");

	//create a transfer variable
	std::string transfer;

	//copy the overview file
	std::cout << "Generating overview report...\n";
	while (getline(cin, transfer))
	{
		cout << transfer;
		cout << std::endl;
	}
	cout << std::endl;

	//close the file, then open transportation_report
	cin.close();
	cin.open("D:\\transport_report.txt");

	//copy the transport report
	std::cout << "Generating transportation report...\n";
	while (getline(cin, transfer))
	{
		cout << transfer;
		cout << std::endl;
	}
	cout << std::endl;

	//close the file, then open conference file
	cin.close();
	cin.open("D:\\conference_report.txt");

	//copy the conference report
	std::cout << "Generating conference report...\n";
	while (getline(cin, transfer))
	{
		cout << transfer;
		cout << std::endl;
	}
	cout << std::endl;

	//close the file, then open hotel report
	cin.close();
	cin.open("D:\\hotel_report.txt");

	//copy the hotel report
	std::cout << "Generating hotel report...\n";
	while (getline(cin, transfer))
	{
		cout << transfer;
		cout << std::endl;
	}
	cout << std::endl;

	//close the file, then open food report
	cin.close();
	cin.open("D:\\food_report.txt");

	//copy the food report
	std::cout << "Generating food report...\n";
	while (getline(cin, transfer))
	{
		cout << transfer;
		cout << std::endl;
	}
	cout << std::endl;

	//close the file, then open summary report
	cin.close();
	cin.open("D:\\summary.txt");

	//copy the summary report
	std::cout << "Generating summary report...\n";
	while (getline(cin, transfer))
	{
		cout << transfer;
		cout << std::endl;
	}
	cout << std::endl;

	//disconnect cout and report file
	cout.close();

	std::cout << "Report complete.\n";
}

//transportation function
void transportation_expense(double &transportation_allowed, double &transportation_saved, double &transportation_total)
{
	//create a file stream object, set the format
	std::ofstream cout;
	cout.open("D:\\transport_report.txt");
	cout << std::setprecision(2) << std::fixed;

	//variable definition
	double round_trip_air_expense; //airline expense
	double car_rental = 0; //rental expense. User should decide using rental car or private car
	double miles_driven = 0; //if private car is used, ask for milage traveled and calculate cost
	double car_private = 0; //calculate the expense of private car
	double parking_days; //ask for how many days parking is used
	double parking_allowed; //parking_days*PARKING_MAX, holds the amount allowed maximum
	double parking_fee; //maximum $6 per day. use an iteration to calculate total (use parking_days). Store (6-parking_fee) into parking_fee_saved
	double parking_total = 0; //calculate the parking total, initiate with 0
	double parking_fee_saved = 0; //to record how much parking fee is saved by employee. If it is negative, the employee must reimburse it
	double taxi_days; //ask for howmany days taxi is used
	double taxi_allowed; //taxi_days*TAXI_MAX, holds the amount allowed maximum for taxi expense
	double taxi_fee; //maximum $10 per day. use an iteration to calculate total (use taxi_days). Store (10-taxi_fee) into taxi_fee_saved
	double taxi_total = 0; //calculate the taxi total
	double taxi_fee_saved = 0; //to record how much taxi fee is saved by employee. If it is negative, the employee must reimburse it

							   //initialize transportation_saved and transportation_total
	transportation_saved = 0;
	transportation_total = 0;
	transportation_allowed = 0;

	//ask for air line charge
	std::cout << "What is the round trip airline expense: ";
	std::cin >> round_trip_air_expense;
	transportation_total += round_trip_air_expense;

	//print out the head and air line expense
	cout << "**Transportation**\n";
	cout << "-------------------------------------------------------------------------------------------\n";
	cout << "This section displays the details of expenses related to transportation\n\n";
	cout << std::left << std::setw(37) << "Round-trip Air Expenses:" << "$" << std::right << std::setw(15) << round_trip_air_expense << "\n\n";

	//*****calculate car expense*****//
	//*******************************//

	char choice; //to store the choice made below
				 //car rental
	std::cout << "Is there any car rental expense: (Y/N)";
	std::cin >> choice;
	while (choice != 'y'&&choice != 'Y'&&choice != 'n'&&choice != 'N')
	{
		std::cout << "Invalid input, please input Y or N:\n";
		std::cout << choice;
	}
	switch (choice)
	{
	case 'Y':
	case 'y':
		std::cout << "How much is the car rental expense: ";
		std::cin >> car_rental;
		while (car_rental < 0)
		{
			std::cout << "Invalid input. Input a car rental expense greater than zero: ";
			std::cin >> car_rental;
		}
		break;
	case 'n':
	case 'N':
		break;
	}

	//add up total
	transportation_total += car_rental;
	//write down the car rental
	cout << std::left << std::setw(37) << "Car rental expense:" << "$" << std::right << std::setw(15) << car_rental << "\n\n";

	//private car expense
	std::cout << "Is private car used: (Y/N)\n";
	std::cin >> choice;

	while (choice != 'y'&&choice != 'Y'&&choice != 'n'&&choice != 'N')
	{
		std::cout << "Invalid input, please input Y or N:\n";
		std::cout << choice;
	}

	switch (choice)
	{
	case 'Y':
	case 'y':
		std::cout << "How many milage used: ";
		std::cin >> miles_driven;
		while (miles_driven < 0)
		{
			std::cout << "Invalid input, please input a value greater than zero: ";
			std::cin >> miles_driven;
		}
		car_private = miles_driven*CAR_EXPENSE;
		break;
	case 'n':
	case 'N':
		break;
	}

	//addup total
	transportation_total += car_private;
	//print out price
	cout << std::left << std::setw(37) << "Private car expense:" << "$" << std::right << std::setw(15) << car_private << "\n\n";

	//*****calculate parking expense*****//
	//***********************************//

	//ask for how many days parking is used
	std::cout << "How many days of parking service is used: ";
	std::cin >> parking_days;
	while (parking_days <= 0)
	{
		std::cout << "The parking days should be greater than zero, please re-input: ";
		std::cin >> parking_days;
	}
	//calculate allowed parking fee (TOTAL)
	parking_allowed = parking_days*PARKING_MAX;

	//use a loop to gather all parking fee
	for (int i = 1; i <= parking_days; i++)
	{
		std::cout << "What is the charge for parking on day " << i << ": ";
		std::cin >> parking_fee;
		while (parking_fee < 0)
		{
			std::cout << "Parking fee should be greater than zero, please input again: ";
			std::cin >> parking_fee;
		}
		parking_total += parking_fee;
		parking_fee_saved += 6 - parking_fee;
	}

	//print out total parking fee
	cout << std::left << std::setw(37) << "Total parking expense:" << "$" << std::right << std::setw(15) << parking_total << "\n\n";
	if (parking_fee_saved >= 0)
	{
		cout << std::left << std::setw(37) << "Parking fee paid by company:" << "$" << std::right << std::setw(15) << parking_total << "\n\n";
		cout << std::left << std::setw(37) << "Parking fee saved by employee:" << "$" << std::right << std::setw(15) << parking_fee_saved << "\n\n";
	}
	else
	{
		cout << std::left << std::setw(37) << "Parking fee paid by company:" << "$" << std::right << std::setw(15) << parking_total + parking_fee_saved << "\n\n";
		cout << std::left << std::setw(37) << "Parking fee paid by employee:" << "$" << std::right << std::setw(15) << -parking_fee_saved << "\n\n";
	}

	//addup total
	transportation_allowed += parking_allowed;
	transportation_total += parking_total;
	transportation_saved += parking_fee_saved;

	//*****calculate taxi expense*****//
	//********************************//

	//ask for how many days taxi is used
	std::cout << "How many days of taxi service is used: ";
	std::cin >> taxi_days;
	while (taxi_days < 0)
	{
		std::cout << "The parking days should not be negative, please re-input: ";
		std::cin >> parking_days;
	}

	if (taxi_days == 0)
		cout << std::left << std::setw(37) << "Total taxi expense:" << "$" << std::right << std::setw(15) << "0" << "\n\n";
	else
	{
		//calculate allowed taxi fee (TOTAL)
		taxi_allowed = taxi_days*TAXI_MAX;

		//use a loop to gather all taxi fee
		for (int i = 1; i <= taxi_days; i++)
		{
			std::cout << "What is the charge for taxi on day " << i << ": ";
			std::cin >> taxi_fee;
			while (taxi_fee < 0)
			{
				std::cout << "taxi fee should be greater than zero, please input again: ";
				std::cin >> taxi_fee;
			}
			taxi_total += taxi_fee;
			taxi_fee_saved += TAXI_MAX - taxi_fee;
		}

		//print out total parking fee
		cout << std::left << std::setw(37) << "Total taxi expense:" << "$" << std::right << std::setw(15) << taxi_total << "\n\n";
		if (taxi_fee_saved >= 0)
		{
			cout << std::left << std::setw(37) << "Taxi fee paid by company:" << "$" << std::right << std::setw(15) << taxi_total << "\n\n";
			cout << std::left << std::setw(37) << "taxi fee saved by employee:" << "$" << std::right << std::setw(15) << taxi_fee_saved << "\n\n";
		}
		else
		{
			cout << std::left << std::setw(37) << "Taxi fee paid by company:" << "$" << std::right << std::setw(15) << taxi_total + taxi_fee_saved << "\n\n";
			cout << std::left << std::setw(37) << "Taxi fee paid by employee:" << "$" << std::right << std::setw(15) << -taxi_fee_saved << "\n\n";
		}
	}

	//addup total
	transportation_allowed += taxi_allowed+ round_trip_air_expense+ car_rental+ car_private;
	transportation_total += taxi_total;
	transportation_saved += taxi_fee_saved;

	//print out total 
	cout << std::left << std::setw(37) << "Transportation total:" << "$" << std::right << std::setw(15) << transportation_total << "\n\n";
	cout << std::left << std::setw(37) << "Transportation allowed:" << "$" << std::right << std::setw(15) << transportation_allowed << "\n\n";
	if (transportation_saved >= 0)
	{
		cout << std::left << std::setw(37) << "Transportation saved:" << "$" << std::right << std::setw(15) << transportation_saved << "\n\n";
	}
	else
		cout << std::left << std::setw(37) << "Transportation reimburse fee:" << "$" << std::right << std::setw(15) << -transportation_saved << "\n\n";
	cout << "-------------------------------------------------------------------------------------------\n\n\n";

	//close file
	cout.close();

	//user notification
	std::cout << "Section 1 is complete. Press enter to begin section 2: conference expense analysis.\n";
	std::cin.ignore();
	std::cin.get();
}

//conference fee
double conference_expense()
{
	//ask for conference fee and seminar fee
	double conference_fee, seminar_fee;
	std::cout << "What is the conference fee:	";
	std::cin >> conference_fee;
	while (conference_fee <= 0)
	{
		std::cout << "Invalid input, please input conference fee greater than zero: ";
		std::cin >> conference_fee;
	}

	std::cout << "What is the seminar fee:	";
	std::cin >> seminar_fee;
	while (seminar_fee <= 0)
	{
		std::cout << "Invalid input, please input conference fee greater than zero: ";
		std::cin >> seminar_fee;
	}

	//print into the report
	std::ofstream cout;
	cout.open("D:\\conference_report.txt");
	cout << std::setprecision(2) << std::fixed;
	cout << "**Conference**\n"
		<< "-------------------------------------------------------------------------------------------\n"
		<< "This section displays the details of expenses related to conference fee\n\n";
	cout << std::left << std::setw(37) << "Conference registration fee:" << "$" << std::right << std::setw(15) << conference_fee << "\n\n";
	cout << std::left << std::setw(37) << "Seminar registration fee:" << "$" << std::right << std::setw(15) << seminar_fee << "\n\n";
	cout << "-------------------------------------------------------------------------------------------\n\n\n";
	cout.close();


	//user notification
	std::cout << "Section 2 is complete. Press enter to begin section 3: hotel expense analysis.\n";
	std::cin.ignore();
	std::cin.get();

	//return total
	return conference_fee + seminar_fee;


}

//hotel fee
void hotel_expense(double &hotel_total, double &hotel_saved, double &hotel_allowed)
{
	//initialize the variable
	double hotel_fee;
	hotel_allowed = (num_days_total-1)*HOTEL_EXPENSE;

	//create a file stream object and setup format
	std::ofstream cout;
	cout.open("D:\\hotel_report.txt");
	cout << std::setprecision(2) << std::fixed;

	//print the head of the report
	cout << "**Hotel Expense**\n"
		<< "-------------------------------------------------------------------------------------------\n"
		<< "This section displays the details of expenses related to hotel fee\n\n";

	//use an iteration to calculate total hotel expense
	for (int i = 1; i < num_days_total; i++)
	{
		std::cout << "What is the expense of hotel for day " << i << ": ";
		std::cin >> hotel_fee;
		while (hotel_fee <= 0)
		{
			std::cout << "Invalid input. Please input an expense greater than zero: ";
			std::cin >> hotel_fee;
		}
		hotel_total += hotel_fee;
		hotel_saved += 90 - hotel_fee;
	}

	//print out total hotel expense
	cout << std::left << std::setw(37) << "Total hotel expense:" << "$" << std::right << std::setw(15) << hotel_total << "\n\n";
	cout << std::left << std::setw(37) << "Hotel expense allowed:" << "$" << std::right << std::setw(15) << hotel_allowed << "\n\n";
	if (hotel_saved >= 0)
	{
		cout << std::left << std::setw(37) << "Hotel expense saved:" << "$" << std::right << std::setw(15) << hotel_saved << "\n\n";
	}
	else
		cout << std::left << std::setw(37) << "Hotel fee reimburse:" << "$" << std::right << std::setw(15) << -hotel_saved << "\n\n";
	cout << "-------------------------------------------------------------------------------------------\n\n";
	cout.close();

	//user notification
	std::cout << "Section 3 is complete. Press enter to begin section 4: food expense analysis.\n";
	std::cin.ignore();
	std::cin.get();
}

//food expense
void food_expense(double &food_total, double &food_allowed, double &food_saved)
{
	//variable definition
	double break_fee, lunch_fee, dinner_fee;

	//create a file stream object to write food report
	std::ofstream cout;
	cout.open("D:\\food_report.txt");
	cout << std::setprecision(2) << std::fixed;

	//write head of the report
	cout << "**Food Expense**\n"
		<< "-------------------------------------------------------------------------------------------\n"
		<< "This section displays the details of expenses related to food\n\n";

	//calculate food expense for the first day
	if (hour_depart <= 18)
	{
		if (hour_depart <= 12)
		{
			if (hour_depart <= 7)
			{
				//contain breakfast
				std::cout << "What is the expense of breakfast on day 1: ";
				std::cin >> break_fee;
				while (break_fee < 0)
				{
					std::cout << "Invalid input, please input a value greater than zero: ";
					std::cin >> break_fee;
				}
				food_total += break_fee;
				food_allowed += BREAKFAST_EXPENSE;
				food_saved += BREAKFAST_EXPENSE - break_fee;
			}
			// contain lunch
			std::cout << "What is the expense of lunch on day 1: ";
			std::cin >> lunch_fee;
			while (lunch_fee < 0)
			{
				std::cout << "Invalid input, please input a value greater than zero: ";
				std::cin >> lunch_fee;
			}
			food_total += lunch_fee;
			food_allowed += LUNCH_EXPENSE;
			food_saved += LUNCH_EXPENSE - lunch_fee;
		}
		
		//contain dinner
		std::cout << "What is the expense of dinner on day 1: ";
		std::cin >> dinner_fee;
		while (dinner_fee < 0)
		{
			std::cout << "Invalid input, please input a value greater than zero: ";
			std::cin >> dinner_fee;
		}
		food_total += dinner_fee;
		food_allowed += DINNER_EXPENSE;
		food_saved += DINNER_EXPENSE - dinner_fee;
	}

	//calculate food expense on 2 ~ (N-1) day, if number of days is greater than 2
	if (num_days_total > 2)
	{
		for (int i = 2; i < num_days_total; i++)
		{
			//breakfast fee
			std::cout << "What is the expense of breakfast on day " << i << ": ";
			std::cin >> break_fee;
			while (break_fee < 0)
			{
				std::cout << "Invalid input, please input a value greater than zero: ";
				std::cin >> break_fee;
			}
			food_total += break_fee;
			food_allowed += BREAKFAST_EXPENSE;
			food_saved += BREAKFAST_EXPENSE - break_fee;

			//lunch fee
			std::cout << "What is the expense of lunch on day " << i << ": ";
			std::cin >> lunch_fee;
			while (lunch_fee < 0)
			{
				std::cout << "Invalid input, please input a value greater than zero: ";
				std::cin >> lunch_fee;
			}
			food_total += lunch_fee;
			food_allowed += LUNCH_EXPENSE;
			food_saved += LUNCH_EXPENSE - lunch_fee;

			//dinner fee
			std::cout << "What is the expense of dinner on day " << i << ": ";
			std::cin >> dinner_fee;
			while (dinner_fee < 0)
			{
				std::cout << "Invalid input, please input a value greater than zero: ";
				std::cin >> dinner_fee;
			}
			food_total += dinner_fee;
			food_allowed += DINNER_EXPENSE;
			food_saved += DINNER_EXPENSE - dinner_fee;

		}
	}

	//calculate food expense for the last day
	if (hour_arrive > 8)
	{
		//contain breakfast
		std::cout << "What is the expense of breakfast on day " << num_days_total << ": ";
		std::cin >> break_fee;
		while (break_fee < 0)
		{
			std::cout << "Invalid input, please input a value greater than zero: ";
			std::cin >> break_fee;
		}
		food_total += break_fee;
		food_allowed += BREAKFAST_EXPENSE;
		food_saved += BREAKFAST_EXPENSE - break_fee;

		//contain lunch
		if (hour_arrive > 13)
		{
			std::cout << "What is the expense of lunch on day " << num_days_total << ": ";
			std::cin >> lunch_fee;
			while (lunch_fee < 0)
			{
				std::cout << "Invalid input, please input a value greater than zero: ";
				std::cin >> lunch_fee;
			}
			food_total += lunch_fee;
			food_allowed += LUNCH_EXPENSE;
			food_saved += LUNCH_EXPENSE - lunch_fee;

			//contain dinner
			if (hour_arrive > 19)
			{
				std::cout << "What is the expense of dinner on day " << num_days_total << ": ";
				std::cin >> dinner_fee;
				while (dinner_fee < 0)
				{
					std::cout << "Invalid input, please input a value greater than zero: ";
					std::cin >> dinner_fee;
				}
				food_total += dinner_fee;
				food_allowed += DINNER_EXPENSE;
				food_saved += DINNER_EXPENSE - dinner_fee;
			}

		}
	}

	//write the report
	cout << std::left << std::setw(37) << "Total food expense:" << "$" << std::right << std::setw(15) << food_total << "\n\n";
	cout << std::left << std::setw(37) << "Total food expense allowed:" << "$" << std::right << std::setw(15) << food_allowed << "\n\n";
	if (food_saved >= 0)
	{
		cout << std::left << std::setw(37) << "Total food expense saved:" << "$" << std::right << std::setw(15) << food_saved << "\n\n";
	}
	else
		cout << std::left << std::setw(37) << "Food expense reimburse:" << "$" << std::right << std::setw(15) << -food_saved << "\n\n";
	cout << "-------------------------------------------------------------------------------------------\n\n\n";
	cout.close();

	//user notification
	std::cout << "Section 4 is complete. Press enter to begin data analysis and generating a final report.\n";
	std::cin.ignore();
	std::cin.get();
}