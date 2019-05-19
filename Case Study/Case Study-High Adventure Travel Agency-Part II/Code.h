#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

//global constant
const int BASE_DEVIL = 350, BASE_SCUBA = 1000, BASE_SKY = 400, BASE_BARRON = 700;
const int INSTRUCTION_CLIMBING = 100, INSTRUCTION_SCUBA = 100;
const int LODGING_WILD = 65, LODGING_INN = 120;
const int EQUIPMENT_RENTAL = 40;
const int DAY_DEVIL = 3, DAY_BARRON = 8, DAY_SKY = 4;
const double DISCOUNT_RATE_BASE = 0.1, DISCOUNT_NUM = 5;

//structured data
struct Package_1 //devil package, contains all the variable needed
{
	int num; //number of people in this package
	int num_instruction; //number of ppl who need instruction
	int num_equipment; //number of ppl who need equipment
	double charge_base; //the amount of base charges, which is: num * BASE_DEVIL
	double discount; //the amount of discount, if number of ppl is >= DISCOUNT_NUM, discount is equal to DISCOUNT_RATE_BASE * charge_base
	double charge_instruction; //charge of the instruction, which is num_instruction * INSTRUCTION_CLIMBING
	double charge_equipment; //charge of the equipment, which is num_equipment * EQUIPMENT_RENTAL * DAY_DEVIL
	double charge_total; //the total charge, which is charge(base+instruction+equipment-discount)
	double deposit; //the required deposit, which is half of the total charge
};

struct Package_2 //Scuba package, contains all the variable needed
{
	int num; //number of ppl
	int num_instruction; //number of ppl who need instruction
	double charge_base; //the amount of base charges, which is: num * BASE_SCUBA;
	double discount; //the amount of discount, if number of ppl is >= DISCOUNT_NUM, discount is equal to DISCOUNT_RATE_BASE * charge_base
	double charge_instruction; //charge of the instruction, which is num_instruction * INSTRUCTION_SCUBA
	double charge_total; //the total charge, which is charge(base+instruction-discount)
	double deposit; //the required deposit, which is half of the total charge
};

struct Package_3 //Sky dive package
{
	int num; //number of ppl
	int num_wild; //number of ppl who needs lodging at wilderness
	int num_inn; //number of ppl who needs lodging at luxury inn
	double charge_base; //the amount of base charges, which is: num * BASE_SKY;
	double discount; //the amount of discount, if number of ppl is >= DISCOUNT_NUM, discount is equal to DISCOUNT_RATE_BASE * charge_base
	double charge_wild; //the amount of wild inn charges, which is num_wild * LODGING_WILD
	double charge_inn; //the amount of luxury inn charges, which is num_inn * LODGING_INN
	double charge_total; //the total charge, which is charge(base+wild+inn-discount)
	double deposit; //the required deposit, which is half of the total charge
};

struct Package_4 //Barron package
{
	int num; //number of ppl
	int num_equipment; //number of ppl who need equipment
	double charge_base; //the amount of base charges, which is: num * BASE_BARRON;
	double discount; //the amount of discount, if number of ppl is >= DISCOUNT_NUM, discount is equal to DISCOUNT_RATE_BASE * charge_base
	double charge_equipment; //charge of the equipment, which is num_equipment * EQUIPMENT_RENTAL * DAY_BARRON
	double charge_total; //the total charge, which is charge(base+equipment-discount)
	double deposit; //the required deposit, which is half of the total charge	
};

struct Sales //sales result analysis data type
{
	double total; //hold the total sale
	double total_devil; //hold the total sale for devil package
	double total_scuba;
	double total_sky;
	double total_barron;
	double total_discount; //hold the total discount give away
	int devil_num; //hold the number of purchase
	int scuba_num;
	int sky_num;
	int barron_num;
};

//because each record of sale will record the data on a single pacakge, the above structures can be combined into a union
union Package
{
	Package_1 devil;
	Package_2 scuba;
	Package_3 sky;
	Package_4 barron;
};

//combine the union defined above with a number to form a new structured data type. 
//This data type has a number to show which package is stored in the union
struct Purchase
{
	int pack_num;
	Package pack;
};

//functional prototype
void show_menu(char &selection);
void devil_buy(std::vector<Purchase> &purchase_log);
void devil_print(const Purchase &purch);
void scuba_buy(std::vector<Purchase> &purchase_log);
void scuba_print(const Purchase &purch);
void sky_buy(std::vector<Purchase> &purchase_log);
void sky_print(const Purchase &purch);
void barron_buy(std::vector<Purchase> &purchase_log);
void barron_print(const Purchase &purch);
void result_analysis(std::vector<Purchase> &purchase_log); //the vector should be passed as constant reference, but I do not know how to do that

int main()
{
	std::vector<Purchase> purchase_log; //to store all the purchase information
	char selection; //to hold the choice user made

	do
	{
		show_menu(selection); //show menu and make a choice

		switch (selection)
		{
		case '1': devil_buy(purchase_log); break;
		case '2': scuba_buy(purchase_log); break;
		case '3': sky_buy(purchase_log); break;
		case '4': barron_buy(purchase_log); break;
		case '5': break;
		}

		if (selection != '5')
		{
			std::cout << "Purchase complete, press enter to continue.";
			std::cin.get();
		}

	} while (selection != '5');

	std::cout << "You quitted. The program is creating analysis report...\n";

	//call result analysis function to analysis the whole result, then write the result to a new report
	result_analysis(purchase_log);

	std::cout << "The report has been created.\n\n";

	return 0;

}

void show_menu(char &selection)
{
	std::cout << "Welcome to the package selecting program.\n";
	std::cout << "\nPlease select one term above (1~5):\n";
	std::cout << "1) Devil's Courthouse Adventure Weekend\n";
	std::cout << "2) Scuba Bahama\n";
	std::cout << "3) Sky Dive Colorado\n";
	std::cout << "4) Barron Cliff Spelunk\n";
	std::cout << "5) Exit\n";
	std::cin >> selection;
	while (selection != '1' && selection != '2' && selection != '3' && selection != '4' && selection != '5')
	{
		std::cout << "Invalid input! Please input 1-5: ";
		std::cin >> selection;
	}
}

//devil buy function
void devil_buy(std::vector<Purchase> &purchase_log)
{
	Purchase purch; //create a container to process data, at the end of the function, the content in this container will be stored in purchase_log
	purch.pack_num = 1; //to record the ID of this purch data type: what it belongs to

						//ask for number of ppl
	std::cout << "How many people in the party: ";
	std::cin >> purch.pack.devil.num;
	while (purch.pack.devil.num <= 0)
	{
		std::cout << "Invalid input, please input again: ";
		std::cin >> purch.pack.devil.num;
	}

	//calculate the base charge and discount
	purch.pack.devil.charge_base = purch.pack.devil.num * BASE_DEVIL;
	if (purch.pack.devil.num >= DISCOUNT_NUM)
		purch.pack.devil.discount = DISCOUNT_RATE_BASE * purch.pack.devil.charge_base;
	else
		purch.pack.devil.discount = 0;

	//ask for number of ppl who needs instruction
	std::cout << "How many people need instruction? ";
	std::cin >> purch.pack.devil.num_instruction;
	while (purch.pack.devil.num_instruction<0 || purch.pack.devil.num_instruction>purch.pack.devil.num)
	{
		std::cout << "Invalid input. Please input a number between 0 and " << purch.pack.devil.num << std::endl;
		std::cin >> purch.pack.devil.num_instruction;
	}
	purch.pack.devil.charge_instruction = purch.pack.devil.num_instruction*INSTRUCTION_CLIMBING;

	//ask for number of ppl who needs equipment
	std::cout << "How many people need equipments? ";
	std::cin >> purch.pack.devil.num_equipment;
	while (purch.pack.devil.num_equipment<0 || purch.pack.devil.num_equipment>purch.pack.devil.num)
	{
		std::cout << "Invalid input. Please input a number between 0 and " << purch.pack.devil.num << std::endl;
		std::cin >> purch.pack.devil.num_equipment;
	}
	purch.pack.devil.charge_equipment = purch.pack.devil.num_equipment*EQUIPMENT_RENTAL*DAY_DEVIL;

	//after the final input, skip the '\n'
	std::cin.ignore();

	//calculate total charge and required deposit
	purch.pack.devil.charge_total = purch.pack.devil.charge_base + purch.pack.devil.charge_equipment + purch.pack.devil.charge_instruction - purch.pack.devil.discount;
	purch.pack.devil.deposit = purch.pack.devil.charge_total / 2;

	//call another function to generate the report and notify user
	devil_print(purch);

	//add this purchased pacakge to the purchase_log data base
	purchase_log.push_back(purch);
}

//devil_print function
void devil_print(const Purchase &purch)
{
	static int counter = 0; //to keep track of how many devil reports are printed. Static variable exists for the life time of the program
	counter++; //each time the devil_print is called, counter is increased by 1
	std::string counter_str = std::to_string(counter); //used to create a string version of counter, used for creating file path
	std::string path = "D:\\Devil's Courthouse Adventure Weekend_report_";
	path.append(counter_str); //to append the index of the report
	path.append(".txt"); //remember the file type

						 //create a file streamer: write
	std::ofstream cout;
	cout.open(path);

	//begin printing file
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
	cout << std::left << std::setw(37) << "Number in Party" << std::setw(2) << " " << std::right << std::setw(9) << purch.pack.devil.num << std::endl;
	cout << std::left << std::setw(37) << "Base Charges" << std::setw(2) << "$" << std::right << std::setw(9) << purch.pack.devil.charge_base << std::endl;
	cout << std::left << std::setw(37) << "Instruction Cost" << std::setw(2) << "$" << std::right << std::setw(9) << purch.pack.devil.charge_instruction << std::endl;
	cout << std::left << std::setw(37) << "Equipment Rental" << std::setw(2) << "$" << std::right << std::setw(9) << purch.pack.devil.charge_equipment << std::endl;
	cout << std::left << std::setw(37) << "Discount" << std::setw(2) << "$" << std::right << std::setw(9) << purch.pack.devil.discount << std::endl;
	cout << std::left << std::setw(37) << "Total Charges" << std::setw(2) << "$" << std::right << std::setw(9) << purch.pack.devil.charge_total << std::endl;
	cout << std::left << std::setw(37) << "Required Deposit" << std::setw(2) << "$" << std::right << std::setw(9) << purch.pack.devil.deposit << std::endl;
	cout << "-------------------------------------------------------\n";

	//disconnect the file
	cout.close();

	//notify user
	std::cout << "The purchase report has been created, index: " << counter << "\n";
}

//scuba buy function
void scuba_buy(std::vector<Purchase> &purchase_log)
{
	Purchase purch; //create a container to process data, at the end of the function, the content in this container will be stored in purchase_log
	purch.pack_num = 2; //to record the ID of this purch data type: what it belongs to

						//ask for number of ppl
	std::cout << "How many people in the party: ";
	std::cin >> purch.pack.scuba.num;
	while (purch.pack.devil.num <= 0)
	{
		std::cout << "Invalid input, please input again: ";
		std::cin >> purch.pack.devil.num;
	}

	//calculate the base charge and discount
	purch.pack.scuba.charge_base = purch.pack.scuba.num * BASE_SCUBA;
	if (purch.pack.scuba.num >= DISCOUNT_NUM)
		purch.pack.scuba.discount = DISCOUNT_RATE_BASE * purch.pack.scuba.charge_base;
	else
		purch.pack.scuba.discount = 0;

	//ask for number of ppl who needs instruction
	std::cout << "How many people need instruction? ";
	std::cin >> purch.pack.scuba.num_instruction;
	while (purch.pack.scuba.num_instruction<0 || purch.pack.scuba.num_instruction > purch.pack.scuba.num)
	{
		std::cout << "Invalid input. Please input a number between 0 and " << purch.pack.scuba.num << std::endl;
		std::cin >> purch.pack.scuba.num_instruction;
	}
	purch.pack.scuba.charge_instruction = purch.pack.scuba.num_instruction*INSTRUCTION_SCUBA;

	//after the final input, skip the '\n'
	std::cin.ignore();

	//calculate total charge and required deposit
	purch.pack.scuba.charge_total = purch.pack.scuba.charge_base + purch.pack.scuba.charge_instruction - purch.pack.scuba.discount;
	purch.pack.scuba.deposit = purch.pack.scuba.charge_total / 2;

	//call scuba_print function to print a report and notify user of completion
	scuba_print(purch);

	//add this purchased pacakge to the purchase_log data base
	purchase_log.push_back(purch);

}

//scuba print function
void scuba_print(const Purchase &purch)
{
	static int counter = 0; //to keep track of how many reports are printed. Static variable exists for the life time of the program
	counter++; //each time this function is called, counter is increased by 1
	std::string counter_str = std::to_string(counter); //used to create a string version of counter, used for creating file path
	std::string path = "D:\\Scuba Bahama_report_";
	path.append(counter_str); //to append the index of the report
	path.append(".txt"); //remember the file type

						 //create a file streamer: write
	std::ofstream cout;
	cout.open(path);

	//start printing
	cout << std::setprecision(2) << std::fixed;
	cout << std::setw(45) << "************************************\n"
		<< std::setw(44) << "** High Adventure Travel Agency **\n"
		<< std::setw(45) << "------------------------------------\n"
		<< std::setw(35) << "***Scuba Bahama***\n"
		<< std::setw(46) << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n"
		<< "Package Description\n"
		<< "---------------------\n"
		<< "A week-long cruise to the Bahamas with three days of \n"
		<< "scuba diving. Those with prior experience may dive \n"
		<< "right in, while beginners should choose to take optional, \n"
		<< "but very affordable lessons.\n\n"
		<< "Package Details:\n"
		<< "-------------------------------------------------------\n";
	cout << std::left << std::setw(37) << "Number in Party" << std::setw(2) << " " << std::right << std::setw(9) << purch.pack.scuba.num << std::endl;
	cout << std::left << std::setw(37) << "Base Charges" << std::setw(2) << "$" << std::right << std::setw(9) << purch.pack.scuba.charge_base << std::endl;
	cout << std::left << std::setw(37) << "Instruction Cost" << std::setw(2) << "$" << std::right << std::setw(9) << purch.pack.scuba.charge_instruction << std::endl;
	cout << std::left << std::setw(37) << "Discount" << std::setw(2) << "$" << std::right << std::setw(9) << purch.pack.scuba.discount << std::endl;
	cout << std::left << std::setw(37) << "Total Charges" << std::setw(2) << "$" << std::right << std::setw(9) << purch.pack.scuba.charge_total << std::endl;
	cout << std::left << std::setw(37) << "Required Deposit" << std::setw(2) << "$" << std::right << std::setw(9) << purch.pack.scuba.deposit << std::endl;
	cout << "-------------------------------------------------------\n";

	//notify user of completion
	std::cout << "The purchase report has been created, index: " << counter << "\n";

	//disconnect the file
	cout.close();
}

//sky_buy function
void sky_buy(std::vector<Purchase> &purchase_log)
{
	Purchase purch; //create a container to process data, at the end of the function, the content in this container will be stored in purchase_log
	purch.pack_num = 3; //to record the ID of this purch data type: what it belongs to

						//ask for number of ppl
	std::cout << "How many people in the party: ";
	std::cin >> purch.pack.sky.num;
	while (purch.pack.sky.num <= 0)
	{
		std::cout << "Invalid input, please input again: ";
		std::cin >> purch.pack.sky.num;
	}

	//calculate the base charge and discount
	purch.pack.sky.charge_base = purch.pack.sky.num * BASE_SKY;
	if (purch.pack.sky.num >= DISCOUNT_NUM)
		purch.pack.sky.discount = DISCOUNT_RATE_BASE * purch.pack.sky.charge_base;
	else
		purch.pack.sky.discount = 0;

	//ask for number of ppl who wants wild inn
	std::cout << "How many people need a wilderness lodge: ";
	std::cin >> purch.pack.sky.num_wild;
	while (purch.pack.sky.num_wild<0 || purch.pack.sky.num_wild>purch.pack.sky.num)
	{
		std::cout << "Invalid input. Please input a number between 0 and " << purch.pack.sky.num << std::endl;
		std::cin >> purch.pack.sky.num_wild;
	}
	purch.pack.sky.charge_wild = purch.pack.sky.num_wild*LODGING_WILD*DAY_SKY;

	//ask for number of ppl who wants luxury inn
	std::cout << "How many people need a luxury inn: ";
	std::cin >> purch.pack.sky.num_inn;
	while (purch.pack.sky.num_inn<0 || purch.pack.sky.num_inn>purch.pack.sky.num)
	{
		std::cout << "Invalid input. Please input a number between 0 and " << purch.pack.sky.num << std::endl;
		std::cin >> purch.pack.sky.num_inn;
	}
	purch.pack.sky.charge_inn = purch.pack.sky.num_inn*LODGING_INN*DAY_SKY;

	//after the final input, skip the '\n'
	std::cin.ignore();

	//calculate the total amount and required deposit
	purch.pack.sky.charge_total = purch.pack.sky.charge_base + purch.pack.sky.charge_wild + purch.pack.sky.charge_inn - purch.pack.sky.discount;
	purch.pack.sky.deposit = purch.pack.sky.charge_total / 2;

	//call sky_print function to print the report and notify user of completion
	sky_print(purch);

	//add this purchased pacakge to the purchase_log data base
	purchase_log.push_back(purch);

}

//sky_print function
void sky_print(const Purchase &purch)
{
	static int counter = 0; //to keep track of how many reports are printed. Static variable exists for the life time of the program
	counter++; //each time this function is called, counter is increased by 1
	std::string counter_str = std::to_string(counter); //used to create a string version of counter, used for creating file path
	std::string path = "D:\\Sky Dive Colorado_report_";
	path.append(counter_str); //to append the index of the report
	path.append(".txt"); //remember the file type

						 //create a file streamer: write
	std::ofstream cout;
	cout.open(path);

	//start printing	
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
	cout << std::left << std::setw(37) << "Number in Party" << std::setw(2) << " " << std::right << std::setw(9) << purch.pack.sky.num << std::endl;
	cout << std::left << std::setw(37) << "Base Charges" << std::setw(2) << "$" << std::right << std::setw(9) << purch.pack.sky.charge_base << std::endl;
	cout << std::left << std::setw(37) << "Lodging at Wilderness Lodge" << std::setw(2) << "$" << std::right << std::setw(9) << purch.pack.sky.charge_wild << std::endl;
	cout << std::left << std::setw(37) << "Lodging at Luxury inn" << std::setw(2) << "$" << std::right << std::setw(9) << purch.pack.sky.charge_inn << std::endl;
	cout << std::left << std::setw(37) << "Discount" << std::setw(2) << "$" << std::right << std::setw(9) << purch.pack.sky.discount << std::endl;
	cout << std::left << std::setw(37) << "Total Charges" << std::setw(2) << "$" << std::right << std::setw(9) << purch.pack.sky.charge_total << std::endl;
	cout << std::left << std::setw(37) << "Required Deposit" << std::setw(2) << "$" << std::right << std::setw(9) << purch.pack.sky.deposit << std::endl;
	cout << "-------------------------------------------------------\n";

	//disconnect file
	cout.close();

	//notify user
	std::cout << "The purchase report has been created, index: " << counter << "\n";

}

//barron buy function
void barron_buy(std::vector<Purchase> &purchase_log)
{
	Purchase purch; //create a container to process data, at the end of the function, the content in this container will be stored in purchase_log
	purch.pack_num = 4; //to record the ID of this purch data type: what it belongs to

						//ask for number of ppl
	std::cout << "How many people in the party: ";
	std::cin >> purch.pack.barron.num;
	while (purch.pack.barron.num <= 0)
	{
		std::cout << "Invalid input, please input again: ";
		std::cin >> purch.pack.barron.num;
	}

	//calculate the base charge and discount
	purch.pack.barron.charge_base = purch.pack.barron.num * BASE_BARRON;
	if (purch.pack.barron.num >= DISCOUNT_NUM)
		purch.pack.barron.discount = DISCOUNT_RATE_BASE * purch.pack.barron.charge_base;
	else
		purch.pack.barron.discount = 0;

	//ask for number of ppl who needs equipment
	std::cout << "How many people need equipments? ";
	std::cin >> purch.pack.barron.num_equipment;
	while (purch.pack.barron.num_equipment<0 || purch.pack.barron.num_equipment>purch.pack.barron.num)
	{
		std::cout << "Invalid input. Please input a number between 0 and " << purch.pack.barron.num << std::endl;
		std::cin >> purch.pack.barron.num_equipment;
	}
	purch.pack.barron.charge_equipment = purch.pack.barron.num_equipment*EQUIPMENT_RENTAL*DAY_BARRON;

	//after the final input, skip the '\n'
	std::cin.ignore();

	//calculate total charge and required deposit
	purch.pack.barron.charge_total = purch.pack.barron.charge_base + purch.pack.barron.charge_equipment - purch.pack.barron.discount;
	purch.pack.barron.deposit = purch.pack.barron.charge_total / 2;

	//call barron_print function to print the report and notify user of the completion
	barron_print(purch);

	//add this purchased pacakge to the purchase_log data base
	purchase_log.push_back(purch);

}

void barron_print(const Purchase &purch)
{
	static int counter = 0; //to keep track of how many reports are printed. Static variable exists for the life time of the program
	counter++; //each time this function is called, counter is increased by 1
	std::string counter_str = std::to_string(counter); //used to create a string version of counter, used for creating file path
	std::string path = "D:\\Barron Cliff Spelunk_report_";
	path.append(counter_str); //to append the index of the report
	path.append(".txt"); //remember the file type

						 //create a file streamer: write
	std::ofstream cout;
	cout.open(path);

	//start printing
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
	cout << std::left << std::setw(37) << "Number in Party" << std::setw(2) << " " << std::right << std::setw(9) << purch.pack.barron.num << std::endl;
	cout << std::left << std::setw(37) << "Base Charges" << std::setw(2) << "$" << std::right << std::setw(9) << purch.pack.barron.charge_base << std::endl;
	cout << std::left << std::setw(37) << "Equipment Rental" << std::setw(2) << "$" << std::right << std::setw(9) << purch.pack.barron.charge_equipment << std::endl;
	cout << std::left << std::setw(37) << "Discount" << std::setw(2) << "$" << std::right << std::setw(9) << purch.pack.barron.discount << std::endl;
	cout << std::left << std::setw(37) << "Total Charges" << std::setw(2) << "$" << std::right << std::setw(9) << purch.pack.barron.charge_total << std::endl;
	cout << std::left << std::setw(37) << "Required Deposit" << std::setw(2) << "$" << std::right << std::setw(9) << purch.pack.barron.deposit << std::endl;
	cout << "-------------------------------------------------------\n";

	//disconnect the file streamer
	cout.close();

	//notify the user
	std::cout << "The purchase report has been created, index: " << counter << "\n";
}

//result analysis function
void result_analysis(std::vector<Purchase> &purchase_log)
{
	//file streamer
	std::ofstream cout;
	cout.open("D:\\Travel Agency Report.txt");

	Sales sale;
	sale.total = 0;
	sale.total_barron = 0;
	sale.total_devil = 0;
	sale.total_discount = 0;
	sale.total_scuba = 0;
	sale.total_sky = 0;
	sale.devil_num = 0;
	sale.scuba_num = 0;
	sale.sky_num = 0;
	sale.barron_num = 0;

	//go over the record and calculate the following data
	for (int i = 0; i < purchase_log.size(); i++)
	{
		switch (purchase_log[i].pack_num)
		{
		case 1: 
			sale.total_devil += purchase_log[i].pack.devil.charge_total; 
			sale.devil_num++; 
			sale.total += purchase_log[i].pack.devil.charge_total; 
			sale.total_discount += purchase_log[i].pack.devil.discount;
			break;
		case 2: 
			sale.total_scuba += purchase_log[i].pack.scuba.charge_total; 
			sale.scuba_num++; 
			sale.total += purchase_log[i].pack.scuba.charge_total; 
			sale.total_discount += purchase_log[i].pack.scuba.discount;
			break;
		case 3: 
			sale.total_sky += purchase_log[i].pack.sky.charge_total; 
			sale.sky_num++; 
			sale.total += purchase_log[i].pack.sky.charge_total; 
			sale.total_discount += purchase_log[i].pack.sky.discount;
			break;
		case 4: 
			sale.total_barron += purchase_log[i].pack.barron.charge_total; 
			sale.barron_num++; 
			sale.total += purchase_log[i].pack.barron.charge_total; 
			sale.total_discount += purchase_log[i].pack.barron.discount; 
			break;
		}
	}

	//print out the report
	cout << std::setprecision(2) << std::fixed;
	int total = sale.devil_num + sale.scuba_num + sale.sky_num + sale.barron_num;
	double total_sale = sale.total_devil + sale.total_scuba + sale.total_sky + sale.total_barron;
	cout << "Total package sold: " << total << std::endl;
	cout << "Total sales: $" << total_sale << std::endl;
	cout << "Devil package sold: " << sale.devil_num << ", percentage: " << static_cast<double>(sale.devil_num) / total << ". Sales from these devil package: $" << sale.total_devil << ". Sales percentage: " << sale.total_devil / total_sale << "\n";
	cout << "Scuba package sold: " << sale.scuba_num << ", percentage: " << static_cast<double>(sale.scuba_num) / total << ". Sales from these scuba package: $" << sale.total_scuba << ". Sales percentage: " << sale.total_scuba / total_sale << "\n";
	cout << "Sky package sold: " << sale.sky_num << ", percentage: " << static_cast<double>(sale.sky_num) / total << ". Sales from these sky package: $" << sale.total_sky << ". Sales percentage: " << sale.total_sky / total_sale << "\n";
	cout << "Barron package sold: " << sale.barron_num << ", percentage: " << static_cast<double>(sale.barron_num) / total << ". Sales from these barron package: $" << sale.total_barron << ". Sales percentage: " << sale.total_barron / total_sale << "\n";
	cout << "Total discount: " << sale.total_discount << ".\n";
	std::cout << "\n";

	//close the cout streamer
	cout.close();

}

