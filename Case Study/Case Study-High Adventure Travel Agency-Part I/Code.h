//case study: High Adventure Travel Agency-Part I
Devil's Courthouse Adventure Weekend
Base Charge: 				$350 per person
Climbing Instruction: 		$100 per person
Equipment Rental: 			$40/day per person

Scuba Bahama
Base Charge: 				$1000 per person
Scuba Instruction: 		$100 per person

Sky Dive Colorado
Base Charge:				$400 per person
Lodging at Wilderness Lodge: $65/day per person
Lodging at Luxury Inn: 	$120/day per person

Barron Cliff Spelunk
Base Charge: 				$700 per person
Equipment Rental: 			$40/day per person

A 10 percent discount on the base charges of any package is given for a party
of five or more.

named constant: all the charges
variable: num_person //number of person

structure of the program: using four function to calculate the charge;

First, show the menu (done by a show_menu function)

Then record the choice (done by show menu function, add a input validity check)




const int BASE_DEVIL = 350, BASE_SCUBA = 1000, BASE_SKY = 400, BASE_BARRON = 700;
const int INSTRUCTION_CLIMBING = 100, INSTRUCTION_SCUBA = 100;
const int LODGING_WILD = 65, LODGING_INN = 120;
const int EQUIPMENT_RENTAL = 40;
const double DISCOUNT_RATE_BASE = 0.1, DISCOUNT_NUM = 5;


Source Code:

//case study: High Adventure Travel Agency-Part I
#include <iostream>
#include <fstream>
#include <iomanip>

//define constants
const int BASE_DEVIL = 350, BASE_SCUBA = 1000, BASE_SKY = 400, BASE_BARRON = 700;
const int INSTRUCTION_CLIMBING = 100, INSTRUCTION_SCUBA = 100;
const int LODGING_WILD = 65, LODGING_INN = 120;
const int EQUIPMENT_RENTAL = 40;
const int DAY_DEVIL = 3, DAY_BARRON = 8;
const double DISCOUNT_RATE_BASE = 0.1, DISCOUNT_NUM = 5;

//function prototype
void show_menu(int &);
void devil_analyze(int);
void scuba_analyze(int);
void sky_analyze(int);
void barron_analyze(int);

//main function
int main()
{
	int choice; //hold the choice
	int num; //hold the number of people

	//show the menu and get choice input
	show_menu(choice);

	//1~4 has been choosen, input number of people
	if (choice != 5)
	{
		std::cout << "How many people in the party? ";
		std::cin >> num;
		while (num <= 0)
		{
			std::cout << "Invalid input! Number of people should be greater than 0\n";
			std::cin >> num;
		}
	}
	else
		std::cout << "You quited.\n";

	//use four function to calculate charge for the four different plan
	switch (choice)
	{
	case 1:
		devil_analyze(num); break;
	case 2:
		scuba_analyze(num); break;
	case 3:
		sky_analyze(num); break;
	case 4:
		barron_analyze(num); break;
	case 5:
		break;
	}
	if (choice != 5)
		std::cout << "The report has been generaeted, please check.\n";

	return 0;
}

//show menu function
void show_menu(int &selection)
{
	std::cout << "Welcome to the package selecting program.\n";
	std::cout << "\nPlease select one term above (1~5):\n";
	std::cout << "1) Devil's Courthouse Adventure Weekend\n";
	std::cout << "2) Scuba Bahama\n";
	std::cout << "3) Sky Dive Colorado\n";
	std::cout << "4) Barron Cliff Spelunk\n";
	std::cout << "5) Exit\n";
	std::cin >> selection;
	while (selection != 1 && selection != 2 && selection != 3 && selection != 4 && selection != 5)
	{
		std::cout << "Invalid input! Please input 1-5: ";
		std::cin >> selection;
	}
}

//devil_analyze function
void devil_analyze(int num_ppl)
{
	//create a file stream object
	std::ofstream cout;
	cout.open("D:\\High Adventure Travel Agency Package Report.txt");

	//write report head into the file, format output first
	cout << std::setprecision(2) << std::fixed;
	cout << std::setw(45) << "************************************\n"
		<< std::setw(44) << "** High Adventure Travel Agency **\n"
		<< std::setw(45) << "------------------------------------\n"
		<< std::setw(45) << "Devil's Courthouse Adventure Weekend\n"
		<< std::setw(46) << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n"
		<< "Package Description\n"
		<< "---------------------\n"
		<< "An action-packed three-day weekend spent camping,\n"
		<< "rock climbing, and rapelling at Devil's Courthouse,\n"
		<< "North Carolina. This getaway is for novices and \n"
		<< "experts alike. Optional climbing instruction is\n"
		<< "available to beginners at a low price. Camping\n"
		<< "equipment rental is also available.\n\n"
		<< "Package Details:\n"
		<< "-------------------------------------------------------\n";

	//calculate base charge, if num_ppl is no less than 5, calculate discount
	double charge_base, discount = 0;
	charge_base = num_ppl*BASE_DEVIL;
	if (num_ppl >= DISCOUNT_NUM)
		discount = charge_base*DISCOUNT_RATE_BASE;

	//ask for number of ppl who needs instruction
	int num_instruction;
	double charge_instruction;
	std::cout << "How many people need instruction? ";
	std::cin >> num_instruction;
	while (num_instruction<0 || num_instruction>num_ppl)
	{
		std::cout << "Invalid input. Please input a number between 0 and " << num_ppl << std::endl;
		std::cin >> num_instruction;
	}
	charge_instruction = num_instruction*INSTRUCTION_CLIMBING;

	//ask for number of ppl who needs equipment
	int num_equipment;
	double charge_equipment;
	std::cout << "How many people need equipments? ";
	std::cin >> num_equipment;
	while (num_equipment<0 || num_equipment>num_ppl)
	{
		std::cout << "Invalid input. Please input a number between 0 and " << num_ppl << std::endl;
		std::cin >> num_equipment;
	}
	charge_equipment = num_equipment*EQUIPMENT_RENTAL*DAY_DEVIL;

	//calculate total charge and required deposit
	double charge_total, deposit;
	charge_total = charge_base + charge_equipment + charge_instruction - discount;
	deposit = charge_total / 2;

	//print the report to the file
	cout << std::left << std::setw(37) << "Number in Party" << std::setw(2) << " " << std::right << std::setw(9) << num_ppl << std::endl;
	cout << std::left << std::setw(37) << "Base Charges" << std::setw(2) << "$" << std::right << std::setw(9) << charge_base << std::endl;
	cout << std::left << std::setw(37) << "Instruction Cost" << std::setw(2) << "$" << std::right << std::setw(9) << charge_instruction << std::endl;
	cout << std::left << std::setw(37) << "Equipment Rental" << std::setw(2) << "$" << std::right << std::setw(9) << charge_equipment << std::endl;
	cout << std::left << std::setw(37) << "Discount" << std::setw(2) << "$" << std::right << std::setw(9) << discount << std::endl;
	cout << std::left << std::setw(37) << "Total Charges" << std::setw(2) << "$" << std::right << std::setw(9) << charge_total << std::endl;
	cout << std::left << std::setw(37) << "Required Deposit" << std::setw(2) << "$" << std::right << std::setw(9) << deposit << std::endl;
	cout << "-------------------------------------------------------\n";

	//close file
	cout.close();

}

//scuba_analyze function
void scuba_analyze(int num_ppl)
{
	//create a file stream object
	std::ofstream cout;
	cout.open("D:\\High Adventure Travel Agency Package Report.txt");

	//write report head into the file, format output first
	cout << std::setprecision(2) << std::fixed;
	cout << std::setw(45) << "************************************\n"
		<< std::setw(44) << "** High Adventure Travel Agency **\n"
		<< std::setw(45) << "------------------------------------\n"
		<< std::setw(35) << "Scuba Dive Colorado\n"
		<< std::setw(46) << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n"
		<< "Package Description\n"
		<< "---------------------\n"
		<< "A week-long cruise to the Bahamas with three days of \n"
		<< "scuba diving. Those with prior experience may dive \n"
		<< "right in, while beginners should choose to take optional, \n"
		<< "but very affordable lessons.\n\n"
		<< "Package Details:\n"
		<< "-------------------------------------------------------\n";

	//calculate base charge, if num_ppl is no less than 5, calculate discount
	double charge_base, discount = 0;
	charge_base = num_ppl*BASE_SCUBA;
	if (num_ppl >= DISCOUNT_NUM)
		discount = charge_base*DISCOUNT_RATE_BASE;

	//ask for number of ppl who needs instruction
	int num_instruction;
	double charge_instruction;
	std::cout << "How many people need instruction? ";
	std::cin >> num_instruction;
	while (num_instruction<0 || num_instruction>num_ppl)
	{
		std::cout << "Invalid input. Please input a number between 0 and " << num_ppl << std::endl;
		std::cin >> num_instruction;
	}
	charge_instruction = num_instruction*INSTRUCTION_SCUBA;


	//calculate total charge and required deposit
	double charge_total, deposit;
	charge_total = charge_base + charge_instruction - discount;
	deposit = charge_total / 2;

	//print the report to the file
	cout << std::left << std::setw(37) << "Number in Party" << std::setw(2) << " " << std::right << std::setw(9) << num_ppl << std::endl;
	cout << std::left << std::setw(37) << "Base Charges" << std::setw(2) << "$" << std::right << std::setw(9) << charge_base << std::endl;
	cout << std::left << std::setw(37) << "Instruction Cost" << std::setw(2) << "$" << std::right << std::setw(9) << charge_instruction << std::endl;
	cout << std::left << std::setw(37) << "Discount" << std::setw(2) << "$" << std::right << std::setw(9) << discount << std::endl;
	cout << std::left << std::setw(37) << "Total Charges" << std::setw(2) << "$" << std::right << std::setw(9) << charge_total << std::endl;
	cout << std::left << std::setw(37) << "Required Deposit" << std::setw(2) << "$" << std::right << std::setw(9) << deposit << std::endl;
	cout << "-------------------------------------------------------\n";

	//close file
	cout.close();
}

//sky_analyze function
void sky_analyze(int num_ppl)
{
	//create a file stream object
	std::ofstream cout;
	cout.open("D:\\High Adventure Travel Agency Package Report.txt");

	//write report head into the file, format output first
	cout << std::setprecision(2) << std::fixed;
	cout << std::setw(45) << "************************************\n"
		<< std::setw(44) << "** High Adventure Travel Agency **\n"
		<< std::setw(45) << "------------------------------------\n"
		<< std::setw(34) << "Sky Dive Colorado\n"
		<< std::setw(46) << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n"
		<< "Package Description\n"
		<< "---------------------\n"
		<< "Four thrilling days with expert sky-diving instructors \n"
		<< "in Colorado Springs, Colorado. For lodging, you may  \n"
		<< "choose either the Wilderness Lodge or the Luxury Inn. \n"
		<< "(Instruction is included for all members of the party.)\n\n"
		<< "Package Details:\n"
		<< "-------------------------------------------------------\n";

	//calculate base charge, if num_ppl is no less than 5, calculate discount
	double charge_base, discount = 0;
	charge_base = num_ppl*BASE_SKY;
	if (num_ppl >= DISCOUNT_NUM)
		discount = charge_base*DISCOUNT_RATE_BASE;

	//ask for number of ppl who needs lodging at wilderness
	int num_wild;
	double charge_wild;
	std::cout << "How many people need a wilderness lodge? ";
	std::cin >> num_wild;
	while (num_wild<0 || num_wild>num_ppl)
	{
		std::cout << "Invalid input. Please input a number between 0 and " << num_ppl << std::endl;
		std::cin >> num_wild;
	}
	charge_wild = num_wild*LODGING_WILD;

	//ask for number of ppl who needs lodging at luxury inn
	int num_inn;
	double charge_inn;
	std::cout << "How many people need a luxury inn? ";
	std::cin >> num_inn;
	while (num_inn<0 || num_inn>num_ppl)
	{
		std::cout << "Invalid input. Please input a number between 0 and " << num_ppl << std::endl;
		std::cin >> num_inn;
	}
	charge_inn = num_inn*LODGING_INN;

	//calculate total charge and required deposit
	double charge_total, deposit;
	charge_total = charge_base + charge_wild+charge_inn - discount;
	deposit = charge_total / 2;

	//print the report to the file
	cout << std::left << std::setw(37) << "Number in Party" << std::setw(2) << " " << std::right << std::setw(9) << num_ppl << std::endl;
	cout << std::left << std::setw(37) << "Base Charges" << std::setw(2) << "$" << std::right << std::setw(9) << charge_base << std::endl;
	cout << std::left << std::setw(37) << "Lodging at Wilderness Lodge" << std::setw(2) << "$" << std::right << std::setw(9) << charge_wild << std::endl;
	cout << std::left << std::setw(37) << "Lodging at Luxury inn" << std::setw(2) << "$" << std::right << std::setw(9) << charge_inn << std::endl;
	cout << std::left << std::setw(37) << "Discount" << std::setw(2) << "$" << std::right << std::setw(9) << discount << std::endl;
	cout << std::left << std::setw(37) << "Total Charges" << std::setw(2) << "$" << std::right << std::setw(9) << charge_total << std::endl;
	cout << std::left << std::setw(37) << "Required Deposit" << std::setw(2) << "$" << std::right << std::setw(9) << deposit << std::endl;
	cout << "-------------------------------------------------------\n";

	//close file
	cout.close();
}

//barron_analyze function
void barron_analyze(int num_ppl)
{
	//create a file stream object
	std::ofstream cout;
	cout.open("D:\\High Adventure Travel Agency Package Report.txt");

	//write report head into the file, format output first
	cout << std::setprecision(2) << std::fixed;
	cout << std::setw(45) << "************************************\n"
		<< std::setw(44) << "** High Adventure Travel Agency **\n"
		<< std::setw(45) << "------------------------------------\n"
		<< std::setw(35) << "Barron Cliff Spelunk\n"
		<< std::setw(46) << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n"
		<< "Package Description\n"
		<< "---------------------\n"
		<< "Eight days spent hiking and exploring caves in the \n"
		<< "Barron Cliff Wilderness Area, Tennessee. Camping \n"
		<< "equipment rental is available.\n\n"
		<< "Package Details:\n"
		<< "-------------------------------------------------------\n";

	//calculate base charge, if num_ppl is no less than 5, calculate discount
	double charge_base, discount = 0;
	charge_base = num_ppl*BASE_BARRON;
	if (num_ppl >= DISCOUNT_NUM)
		discount = charge_base*DISCOUNT_RATE_BASE;

	//ask for number of ppl who needs equipment
	int num_equipment;
	double charge_equipment;
	std::cout << "How many people need equipments? ";
	std::cin >> num_equipment;
	while (num_equipment<0 || num_equipment>num_ppl)
	{
		std::cout << "Invalid input. Please input a number between 0 and " << num_ppl << std::endl;
		std::cin >> num_equipment;
	}
	charge_equipment = num_equipment*EQUIPMENT_RENTAL*DAY_BARRON;

	//calculate total charge and required deposit
	double charge_total, deposit;
	charge_total = charge_base + charge_equipment- discount;
	deposit = charge_total / 2;

	//print the report to the file
	cout << std::left << std::setw(37) << "Number in Party" << std::setw(2) << " " << std::right << std::setw(9) << num_ppl << std::endl;
	cout << std::left << std::setw(37) << "Base Charges" << std::setw(2) << "$" << std::right << std::setw(9) << charge_base << std::endl;
	cout << std::left << std::setw(37) << "Equipment Rental" << std::setw(2) << "$" << std::right << std::setw(9) << charge_equipment << std::endl;
	cout << std::left << std::setw(37) << "Discount" << std::setw(2) << "$" << std::right << std::setw(9) << discount << std::endl;
	cout << std::left << std::setw(37) << "Total Charges" << std::setw(2) << "$" << std::right << std::setw(9) << charge_total << std::endl;
	cout << std::left << std::setw(37) << "Required Deposit" << std::setw(2) << "$" << std::right << std::setw(9) << deposit << std::endl;
	cout << "-------------------------------------------------------\n";

	//close file
	cout.close();
}

