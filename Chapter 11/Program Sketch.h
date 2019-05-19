/* Chapter 11 */

/*********************/
/***Program Example***/
/*********************/

11-1. Practice using structure members
{

#include <iostream>
#include <vector>

struct Area
{
	double length;
	double width;
	const double PI = 3.1415926;
	double radius;
	double area;
};

int main()
{
	//std::vector<Area> area;
	Area area[2];
	Area circle, rectangle;
	circle.radius = 1;
	rectangle.length = 2;
	rectangle.width = 3;
	circle.area = circle.PI*circle.radius*circle.radius;
	rectangle.area = rectangle.length*rectangle.width;
	
	//area.push_back(circle);
	//area.push_back(rectangle);
	area[0].radius = 1;
	area[0].area = area[0].PI*area[0].radius*area[0].radius;

	
	std::cout << "Area of a circle: " << area[0].area << "\n";
	//std::cout << "Area of a rectangle: " << area[1].area << "\n";

	return 0;
}

}

11-2. Pass a member of a structure variable to function
{

#include <iostream>
#include <cmath>
#include <vector>

struct Circle
{
	double radius;
	double diameter;
	double area;
};

void get_info(int num, std::vector<Circle> &circles);

int main()
{
	std::vector<Circle> circles;
	
	//ask for number of circles
	std::cout << "How many circles you want to input: ";
	int num;
	std::cin >> num;
	
	//call function to get the radius for each circle, also calculate the diameter and area
	get_info(num, circles);
	
	//display area
	for (int i=0; i<circles.size(); i++)
		std::cout << "Area of circle " << i+1 << " is: " << circles[i].area << "\n";
	
	return 0;
	
}

//get_info function
void get_info(int num, std::vector<Circle> &circles)
{
	//define constant PI
	const double PI = 3.1415926;
	
	for (int i=0; i<num; i++)
	{
		std::cout << "What is the radius for circle " << i+1 << ": ";
		Circle transfer;
		std::cin >> transfer.radius;
		circles.push_back(transfer);
	}
	
	//calculate diameter and area
	for (int i=0; i<num; i++)
	{
		circles[i].diameter = circles[i].radius*2;
		circles[i].area = PI*pow(circles[i].radius, 2);
	}
	
}




}

11-3. Partially initialized structure variable
{

#include <vector>
#include <string>
#include <iostream>

struct Employee
{
	std::string name;
	int emp_id;
	double pay_rate;
	double hours;
	double gross_pay;
};

void get_info(int num, std::vector<Employee> &employee_info);

int main()
{
	//create a vector container to hold employee info for different employees
	std::vector<Employee> employee_info(2);
	
	//how many employee's info will be inputted
	int num = 2;
	
	//call a get_info function to input all the informations
	get_info(num, employee_info);
	
	//print out name and gross pay
	std::cout << "Payment info:\n";
	for (int i=0; i<employee_info.size(); i++)
	{
		std::cout << "Name: " << employee_info[i].name << "  Gross pay: $" << employee_info[i].gross_pay << "\n";		
	}
	std::cout << std::endl;
	
	return 0;
}

//get_info function, it will also calculate the gross income for the employee
void get_info(int num, std::vector<Employee> &employee_info)
{
	//partially initialize the two employee
	employee_info[0] = {"Yu Miao", 12345, 12.5};
	employee_info[1] = {"Yingying", 54321, 15.5};
	
	//input the details
	for (int i=0; i<num; i++)
	{
		//ask for hours
		std::cout << "What is the hours for " << employee_info[i].name << ": ";
		std::cin >> employee_info[i].hours;
		//calculate gross pay
		employee_info[i].gross_pay = employee_info[i].pay_rate*employee_info[i].hours;	
	}
}


}

Checkpoint 11-3
{

#include <iostream>
#include <string>

using namespace std;

struct movie
{
	string name;
	string director;
	string producer;
	string year;
};

int main()
{
	movie favorite_movie;
	cout << "Enter the following data about your\n";
	cout << "favorite movie.\n";
	cout << "name: ";
	getline(cin, favorite_movie.name);

	cout << "Director: ";
	getline(cin, favorite_movie.director);

	cout << "Producer: ";
	getline(cin, favorite_movie.producer);

	cout << "Year of release: ";
	getline(cin, favorite_movie.year);

	cout << "Here is data on your favorite movie:\n";
	cout << "Name: " << favorite_movie.name << "\n";
	cout << "Director: " << favorite_movie.director << "\n";
	cout << "Producer: " << favorite_movie.producer << "\n";
	cout << "Year: " << favorite_movie.year << "\n";

	return 0;
}

}

11-4. Use array of structures (already did in 11-3)

11-5. Use nested structures
{

#include <iostream>
#include <string>

//structure

struct Personal_info
{
	std::string name;
	int age;
	std::string gender;
	std::string education;
};

struct Pay_info
{
	double pay_rate;
	double hour;
	double gross_pay;
};

struct Employee
{
	Personal_info employee_detail;
	Pay_info employee_pay;
};


int main()
{
	//define the structure variable manager
	Employee manager;

	//ask for personal info
	std::cout << "What is the name of the empolyee: ";
	getline(std::cin, manager.employee_detail.name);
	std::cout << "What is the age of the employee: ";
	std::cin >> manager.employee_detail.age;
	std::cout << "What is the gender of the employee: ";
	std::cin.ignore();
	getline(std::cin, manager.employee_detail.gender);
	std::cout << "What is the education degree of the employee: ";
	getline(std::cin, manager.employee_detail.education);

	//ask for pay info and calculate gross pay
	std::cout << "What is the pay rate for the employee: ";
	std::cin >> manager.employee_pay.pay_rate;
	std::cout << "How many hours of work: ";
	std::cin >> manager.employee_pay.hour;
	manager.employee_pay.gross_pay = manager.employee_pay.pay_rate * manager.employee_pay.hour;

	//display info
	std::cout << "Here is what you inputted:\n\n";
	std::cout << "Name: " << manager.employee_detail.name << "\n";
	std::cout << "Age: " << manager.employee_detail.age << "\n";
	std::cout << "Gender: " << manager.employee_detail.gender << "\n";
	std::cout << "Education: " << manager.employee_detail.education << "\n";
	std::cout << "Pay rate: " << manager.employee_pay.pay_rate << "\n";
	std::cout << "Hour: " << manager.employee_pay.hour << "\n";
	std::cout << "Gross pay " << manager.employee_pay.gross_pay << "\n";

	return 0;
}

}

11-6. Pass the structure variable to function (by value or by reference, already finished this in 11-3)

11-7. Demonstrates function that returns structure variable
{

#include <iostream>
#include <string>

struct Product
{
	std::string description;
	int part_num;
	double cost;
};

Product get_info();

int main()
{
	Product parts[100];
	parts[0] = { "blessing", 13305, 2015.45 };
	std::cout << parts[0].description << "\n";
	
	parts[1] = get_info();
	parts[2] = get_info();
	std::cout << parts[2].description << "\n";
	return 0;
}

//function that returns structure variable
Product get_info()
{
	//define a variable to hold the data
	Product p;
	std::cout << "Please input the product description: ";
	getline(std::cin, p.description);
	std::cout << "Please input the product number: ";
	std::cin >> p.part_num;
	std::cout << "Please input the cost: ";
	std::cin >> p.cost;
	std::cin.ignore();

	//after inputting, return the variable
	return p;
}

}

11-8. Demonstrate a pointer to a structure can be used as a function parameter
{

#include <iostream>
#include <cmath>

struct Rectangle
{
	double length;
	double width;
	double area;
	double diagonol;
};

void get_data(Rectangle *r);
void calc_data(Rectangle *r);
void display(const Rectangle *r);

int main()
{
	//create a Rectangle variable and a pointer to the variable
	Rectangle rec1;
	Rectangle *ptr = &rec1;

	//call get_data function to input the length and width
	get_data(ptr);

	//call calc_data function to calculate the area and diagonol
	calc_data(ptr);

	//call a function to display info, pointer to constant
	display(ptr);

	return 0;
}

void get_data(Rectangle *r)
{
	std::cout << "Please input the length of the rectangle: ";
	std::cin >> r->length;
	std::cout << "Please input the width of the rectangle: ";
	std::cin >> r->width;
}


void calc_data(Rectangle *r)
{
	r->area = r->length * r->width;
	r->diagonol = pow((pow(r->length, 2) + pow(r->width, 2)), 0.5);
}

void display(const Rectangle *r)
{
	std::cout << "The area is: " << r->area << "\n";
	std::cout << "The diagonol is: " << r->diagonol << "\n";
}




}

11-9. Demonstrate the use of union data type
{

#include <iostream>
#include <string>
#include <cctype>


union Pay_source
{
	int hours;
	double sales;
};

struct Employee_info
{
	std::string name;
	char pay_type;
	Pay_source pay_s;
	double salary;
};

void get_info(Employee_info *ptr);
void calc_salary(Employee_info *ptr);

int main()
{
	//call function to get info for employee info
	Employee_info employee1;
	get_info(&employee1);

	//call calc_salary function to calculate salary based on the pay_type
	calc_salary(&employee1);

	//print out the salary
	std::cout << "\nThe total salary for " << employee1.name << " is: " << employee1.salary << "\n";

	return 0;
}

void get_info(Employee_info *ptr)
{
	std::cout << "Please input the name of the employee: ";
	getline(std::cin, ptr->name);
	std::cout << "Please input the pay type of the employee. C for commision, H for hour: ";
	std::cin >> ptr->pay_type;
}

void calc_salary(Employee_info *ptr)
{
	if (tolower(ptr->pay_type) == 'c')
	{
		//pay by commision, input the sales of the employee
		std::cout << "Please input the sales of the employee: ";
		std::cin >> ptr->pay_s.sales;
		//store the total salary
		ptr->salary = ptr->pay_s.sales * 0.1;
	}

	else if (tolower(ptr->pay_type) == 'h')
	{
		//pay by hour, input the hourly pay rate
		std::cout << "Please input the working hour of the employee: ";
		std::cin >> ptr->pay_s.hours;
		//store the total salary
		ptr->salary = ptr->pay_s.hours * 20;
	}
}



}

11-10. Demonstrate the use of anonymous union data type

11-11. Demonstrate the use of enumerated data type
{

#include <iostream>

//create an enumerator data type, a list of named integer constant
enum Day { MONDAY, TUESDAY, WEDNESDAY, THURSDAY, FRIDAY };

int main()
{
	const int NUM_DAYS = 5;
	double sales[NUM_DAYS];

	//get sales info
	for (int i = MONDAY; i <= FRIDAY; i++)
	{
		std::cout << "What is the sales amount for day " << i+1 << ": ";
		std::cin >> sales[i];
	}

	//calculate the total
	double total = 0;
	for (int i = MONDAY; i <= FRIDAY; i++)
		total += sales[i];

	//display the total
	std::cout << "The total sale is: " << total << "\n";

	return 0;
}

}

11-12. Demonstrate the use of enumerated data type (use enum variable as the counter variable)
{


#include <iostream>

//create an enumerator data type, a list of named integer constant
enum Day { MONDAY, TUESDAY, WEDNESDAY, THURSDAY, FRIDAY };

int main()
{
	const int NUM_DAYS = 5;
	double sales[NUM_DAYS];

	//get sales info
	for (Day i = MONDAY; i <= FRIDAY; i = static_cast<Day>(i + 1))
	{
		std::cout << "What is the sales amount for day " << i + 1 << ": ";
		std::cin >> sales[i];
	}

	//calculate the total
	double total = 0;
	for (Day i = MONDAY; i <= FRIDAY; i = static_cast<Day>(i + 1))
		total += sales[i];

	//display the total
	std::cout << "The total sale is: " << total << "\n";

	return 0;
}


}

11-13. Demonstrate output different contents based on different value of enumerated variable
{


#include <iostream>

//create an enumerator data type, a list of named integer constant
enum Day { MONDAY, TUESDAY, WEDNESDAY, THURSDAY, FRIDAY };

int main()
{
	const int NUM_DAYS = 5;
	double sales[NUM_DAYS];

	//get sales info
	for (Day i = MONDAY; i <= FRIDAY; i = static_cast<Day>(i+1))
	{
		std::cout << "What is the sales amount for ";
		switch (i)
		{
		case MONDAY: std::cout << "Monday:\n"; break;
		case TUESDAY: std::cout << "Tuesday:\n"; break;
		case WEDNESDAY: std::cout << "Wednesday:\n"; break;
		case THURSDAY: std::cout << "Thursday:\n"; break;
		case FRIDAY: std::cout << "Friday:\n"; break;
		}
		std::cin >> sales[i];
	}

	//calculate the total
	double total = 0;
	for (int i = MONDAY; i <= FRIDAY; i++)
		total += sales[i];

	//display the total
	std::cout << "The total sale is: " << total << "\n";

	return 0;
}


}

11-14. Specifying integer values for enumerators
{

#include <iostream>

enum Temperature { FREEZE = 0, COLD = 10, COOL = 20, PLEASANT = 25, WARM = 30, HOT = 35, SCORCHING = 45, BOIL = 100 };

int main()
{
	std::cout << "Please input the temperature: ";
	int temperature;
	std::cin >> temperature;
	
	if (temperature <= FREEZE)
		std::cout << "It's freezing!\n";
	else if (temperature >= BOIL)
		std::cout << "It's boiling!\n";
	else
		std::cout << "It's not freezing or boiling.\n";
	
	return 0;
}

}

Case Study: High Adventure Travel Agency Part II-1
{

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

//because each record will record the data on a single pacakge, the above structures can be combined into a union
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

 

}


/****************************/
/***Programming Challenges***/
/****************************/
1~6: lost because windows 10 auto update

7, 8. Customer Account+
{

#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <cstring>

struct Account
{
	int account_number;
	std::string name;
	std::string address;
	std::string city_zip;
	std::string phone;
	double balance;
};

void show_menu(char &choice, int num);
void add_account(std::vector<Account> &data_base);
void modify_account(std::vector<Account> &data_base);
void display_account(std::vector<Account> &data_base);
void display(const Account &acc);
void search_account(std::vector<Account> &data_base);

int main()
{
	std::vector<Account> data_base;
	char choice;
	do
	{
		//show the menu and ask the user to make a choice
		show_menu(choice, data_base.size());

		switch (choice)
		{
		case '1': add_account(data_base); break;
		case '2': modify_account(data_base); break;
		case '3': display_account(data_base); break;
		case '4': search_account(data_base); break;
		case '5': break;
		}

	} while (choice != '5');

	std::cout << "You quitted.\n";

	return 0;
}

//show the menu and record choice
void show_menu(char &choice, int num)
{
	std::cout << "customer accounts manage system\n" << "--------------------------------------\n";
	std::cout << "Number of accounts in database: " << num << "\n";
	std::cout << "Please select one term below:\n\n";
	std::cout << "1. Add a customer account\n"
		<< "2. Modify a customer's account\n"
		<< "3. Display a customer's account\n"
		<< "4. Search for customer's account\n"
		<< "5. Exit\n";

	std::cin >> choice;
	while (choice != '1' && choice != '2' && choice != '3' && choice != '4' && choice != '5')
	{
		std::cout << "Please re-input 1~5: ";
		std::cin >> choice;
	}
	std::cin.ignore(); //to skip the '\n'

}

//account adding function, add an account to the data_base
void add_account(std::vector<Account> &data_base)
{
	static int counter = 270301100;
	Account acc; //create a subject to work with
	acc.account_number = counter++; //allocate account number, then update the counter
	std::cout << "Please input the name of the customer: ";
	getline(std::cin, acc.name);
	std::cout << "Please input the address of the customer: ";
	getline(std::cin, acc.address);
	std::cout << "Please input the city, state and zip code: ";
	getline(std::cin, acc.city_zip);
	std::cout << "Please input the phone number: ";
	getline(std::cin, acc.phone);
	std::cout << "Please input the balance of the account: ";
	std::cin >> acc.balance;
	std::cin.ignore(); //skip the '\n';

					   //add this account into the data base vector
	data_base.push_back(acc);

	std::cout << "\n\n";
}

//account modification function, ask the user to input account number and choose which term he wants to modify
void modify_account(std::vector<Account> &data_base)
{
	//ask user to input the account number to modify
	int num, found = 0;
	char selection;
	int middle; //to hold the matched position
	do
	{
		std::cout << "Please input the account number you want to modify: ";
		std::cin >> num;
		//perform a binary search
		int first = 0, last = data_base.size() - 1;

		do
		{
			middle = (first + last) / 2;
			if (data_base[middle].account_number == num)
			{
				found = 1;
				break;
			}
			else if (data_base[middle].account_number > num)
				last = middle - 1;
			else
				first = middle + 1;
		} while (first <= last);

		if (!found)
		{
			std::cout << "The account number is not found, would you want to input again? (Y/N) ";
			std::cin >> selection;
			while (toupper(selection) != 'N' && toupper(selection) != 'Y')
			{
				std::cout << "Please input Y or N: ";
				std::cin >> selection;
			}
			std::cin.ignore(); //skip the '\n'
		}
	} while (found == 0 && toupper(selection) == 'Y');

	if (!found)
		return; //found == 0, no match found

				//if function goes here, middle holds the position where the user wants to modify
	do
	{
		//display modification choice
		std::cout << "\nPlease select one term to modify: ";
		std::cout << "\n1) Name\n2) Address\n3) City, State and Zip code\n4) Phone number\n";
		std::cin >> selection;
		while (selection != '1' && selection != '2' && selection != '3' && selection != '4')
		{
			std::cout << "Invalid input, please input 1, 2, 3 or 4: ";
			std::cin >> selection;
		}
		std::cin.ignore(); //skip the '\n'

		switch (selection)
		{
		case '1':
			std::cout << "\nPlease input a new name: ";
			getline(std::cin, data_base[middle].name);
			break;
		case '2':
			std::cout << "\nPlease input a new address: ";
			getline(std::cin, data_base[middle].address);
			break;
		case '3':
			std::cout << "\nPlease input city, state and zip code: ";
			getline(std::cin, data_base[middle].city_zip);
			break;
		case '4':
			std::cout << "\nPlease input new phone number: ";
			getline(std::cin, data_base[middle].phone);
			break;
		}

		//ask user if he wants to continue
		std::cout << "Do you want to modify another term? (Y/N) ";
		std::cin >> selection;
		while (toupper(selection) != 'N' && toupper(selection) != 'Y')
		{
			std::cout << "Please input Y or N: ";
			std::cin >> selection;
		}
		std::cin.ignore();

	} while (toupper(selection) == 'Y');




}

//display account info
void display_account(std::vector<Account> &data_base)
{
	//ask user to input the account number to modify
	int num, found = 0;
	char selection;
	int middle; //to hold the matched position
	do
	{
		std::cout << "Please input the account number you want to check: ";
		std::cin >> num;
		//perform a binary search
		int first = 0, last = data_base.size() - 1;

		do
		{
			middle = (first + last) / 2;
			if (data_base[middle].account_number == num)
			{
				found = 1;
				break;
			}
			else if (data_base[middle].account_number > num)
				last = middle - 1;
			else
				first = middle + 1;
		} while (first <= last);

		if (!found)
		{
			std::cout << "The account number is not found, would you want to input again? (Y/N) ";
			std::cin >> selection;
			while (toupper(selection) != 'N' && toupper(selection) != 'Y')
			{
				std::cout << "Please input Y or N: ";
				std::cin >> selection;
			}
			std::cin.ignore(); //skip the '\n'
		}
	} while (found == 0 && toupper(selection) == 'Y');

	if (!found)
		return; //found == 0, no match found

				//if function goes here, middle holds the position where the user wants to display
	std::cout << "\nAccount Number: " << data_base[middle].account_number
		<< "\nAccount Holder: " << data_base[middle].name
		<< "\nAddress: " << data_base[middle].address
		<< "\nCity, State and Zip: " << data_base[middle].city_zip
		<< "\nPhone number: " << data_base[middle].phone
		<< "\nAccount balance: $" << data_base[middle].balance
		<< "\n\n";

}

//display account info-2, display the account info, no account number is required
void display(const Account &acc)
{
	std::cout << "\nAccount Number: " << acc.account_number
		<< "\nAccount Holder: " << acc.name
		<< "\nAddress: " << acc.address
		<< "\nCity, State and Zip: " << acc.city_zip
		<< "\nPhone number: " << acc.phone
		<< "\nAccount balance: $" << acc.balance
		<< "\n\n";
}

//search account function
void search_account(std::vector<Account> &data_base)
{
	//ask what type of data the user wants to search
	char choice;
	std::cout << "Please choose one term to search:"
		<< "\n1) Account number"
		<< "\n2) Account name"
		<< "\n3) Address"
		<< "\n4) City, state and zip code"
		<< "\n5) Phone"
		<< "\n6) Balance (will return account with balance equal or higher than keyword) ";
		std::cin >> choice;
	while (choice != '1' && choice != '2' && choice != '3' && choice != '4' && choice != '5' && choice != '6')
	{
		std::cout << "Invalid input, please input 1 ~ 6: ";
		std::cin >> choice;
	}
	std::cin.ignore(); //skip the '\n'

					   //ask user to input a key word to search
	std::string keyword;
	std::cout << "\nPlease input a keyword to search: ";
	getline(std::cin, keyword);

	//create a vector container to contain account that meet the search criteria
	std::vector<Account> match;
	std::string search; //hold the content in account info transferred into string

						//search the whole data base to find out records that match, based on the type of searching
	switch (choice)
	{
	case '1':
		for (int i = 0; i<data_base.size(); i++)
		{
			search = std::to_string(data_base[i].account_number);
			if (search.find(keyword) != -1)
				match.push_back(data_base[i]);
		}
		break;

	case '2':
		for (int i = 0; i<data_base.size(); i++)
		{
			search = data_base[i].name;
			if (search.find(keyword) != -1)
				match.push_back(data_base[i]);
		}
		break;

	case '3':
		for (int i = 0; i<data_base.size(); i++)
		{
			search = data_base[i].address;
			if (search.find(keyword) != -1)
				match.push_back(data_base[i]);
		}
		break;

	case '4':
		for (int i = 0; i<data_base.size(); i++)
		{
			search = data_base[i].city_zip;
			if (search.find(keyword) != -1)
				match.push_back(data_base[i]);
		}
		break;

	case '5':
		for (int i = 0; i<data_base.size(); i++)
		{
			search = data_base[i].phone;
			if (search.find(keyword) != -1)
				match.push_back(data_base[i]);
		}
		break;

	case '6':
		for (int i = 0; i<data_base.size(); i++)
		{
			//transfer keyword to a double number
			double balance;
			balance = atof(keyword.c_str());
			if (data_base[i].balance >= balance)
				match.push_back(data_base[i]);
		}
		break;
	}

	//print out account that match
	std::cout << "Search result:\n";
	if (match.size() != 0)
	{
		for (int i = 0; i<match.size(); i++)
		{
			std::cout << "Match " << i + 1 << ":\n";
			display(match[i]);
			std::cout << "\n";
		}

	}
	else
		std::cout << "No match!\n";

	std::cout << "Press enter to continue...";
	std::cin.get();

}


}

9. 10 Speakers' bureau and the search function: these two problems are almost identical with 7,8

11. Monthly budget
{

#include <iostream>

struct Budget
{
	double housing;
	double utility;
	double household;
	double transport;
	double food;
	double medical;
	double insurance;
	double entertain;
	double clothing;
	double misc;
};

void get_budget(Budget &budget);
void analyze_budget(const Budget &budget);

int main()
{
	//define a budget container, and call get_budget function to store
	Budget budget;
	get_budget(budget);

	//pass the budget to another function to compare and display the amount difference
	analyze_budget(budget);

	return 0;
}

void get_budget(Budget &budget)
{
	std::cout << "What is the housing expense this month: ";
	std::cin >> budget.housing;
	std::cout << "What is the utility expense this month: ";
	std::cin >> budget.utility;
	std::cout << "What is the household expense this month: ";
	std::cin >> budget.household;
	std::cout << "What is the transport expense this month: ";
	std::cin >> budget.transport;
	std::cout << "What is the food expense this month: ";
	std::cin >> budget.food;
	std::cout << "What is the medical expense this month: ";
	std::cin >> budget.medical;
	std::cout << "What is the insurance expense this month: ";
	std::cin >> budget.insurance;
	std::cout << "What is the entertainment expense this month: ";
	std::cin >> budget.entertain;
	std::cout << "What is the clothing expense this month: ";
	std::cin >> budget.clothing;
	std::cout << "What is the miscellaneous expense this month: ";
	std::cin >> budget.misc;
}

void analyze_budget(const Budget &budget)
{
	if (budget.housing >= 500)
		std::cout << "Amount over housing: " << budget.housing - 500;
	else
		std::cout << "Amount under housing: " << 500 - budget.housing;

	if (budget.utility >= 150)
		std::cout << "\nAmount over utility: " << budget.utility - 150;
	else
		std::cout << "\nAmount under utility: " << 150 - budget.utility;

	if (budget.household >= 65)
		std::cout << "\nAmount over household: " << budget.household - 65;
	else
		std::cout << "\nAmount under household: " << 65 - budget.household;

	if (budget.transport >= 50)
		std::cout << "\nAmount over transport: " << budget.transport - 50;
	else
		std::cout << "\nAmount under transport: " << 50 - budget.transport;

	if (budget.food >= 250)
		std::cout << "\nAmount over food: " << budget.food - 250;
	else
		std::cout << "\nAmount under food: " << 250 - budget.food;

	if (budget.medical >= 30)
		std::cout << "\nAmount over medical: " << budget.medical - 30;
	else
		std::cout << "\nAmount under medical: " << 30 - budget.medical;

	if (budget.insurance >= 100)
		std::cout << "\nAmount over insurance: " << budget.insurance - 100;
	else
		std::cout << "\nAmount under insurance: " << 100 - budget.insurance;

	if (budget.entertain >= 150)
		std::cout << "\nAmount over entertain: " << budget.entertain - 150;
	else
		std::cout << "\nAmount under entertain: " << 150 - budget.entertain;

	if (budget.clothing >= 75)
		std::cout << "\nAmount over clothing: " << budget.clothing - 75;
	else
		std::cout << "\nAmount under clothing: " << 75 - budget.clothing;

	if (budget.misc >= 50)
		std::cout << "\nAmount over misc: " << budget.misc - 50;
	else
		std::cout << "\nAmount under misc: " << 50 - budget.misc;

	std::cout << "\n";

}


}

12. Course grade
{

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

struct Student_data
{
	std::string name; //name of the student
	std::string idnum; //student id number
	double *test; //a pointer to an double array which stores the test scores
	double average; //hold the average score of the student
	char grade; //hold the course grade	
};

void get_data(Student_data *student, int num_student, int num_test);
char decide_grade(double score);
void score_analysis(Student_data *student, int num_student, int num_test);
void print(Student_data *student, int num_student);

int main()
{
	//ask how many students and how many tests
	int num_student, num_test;
	std::cout << "How many students: ";
	std::cin >> num_student;
	while (num_student <= 0)
	{
		std::cout << "Please input student number that is greater than zero: ";
		std::cin >> num_student;
	}

	std::cout << "How many tests: ";
	std::cin >> num_test;
	while (num_test <= 0)
	{
		std::cout << "Please input test number that is greater than zero: ";
		std::cin >> num_test;
	}
	std::cin.ignore(); //skip the '\n'

					   //dynamically allocate an array of Student_data, using the number of student just inputted
	Student_data *student = new Student_data[num_student];

	//dynamically allocate array space for test array in each student[] structure
	for (int i = 0; i<num_student; i++)
		student[i].test = new double[num_test];

	//call get_data function to fill up each slot
	get_data(student, num_student, num_test);

	//call score_analysis function to finish analyzing
	score_analysis(student, num_student, num_test);

	//call printing function to print the report to a file
	print(student, num_student);

	return 0;
}

void get_data(Student_data *student, int num_student, int num_test)
{
	for (int i = 0; i<num_student; i++)
	{
		std::cout << "Please input name for student " << i + 1 << ": ";
		getline(std::cin, student[i].name);

		std::cout << "Please input student number for student " << student[i].name << ": ";
		getline(std::cin, student[i].idnum);

		for (int j = 0; j<num_test; j++)
		{
			std::cout << "Please input score for test " << j + 1 << " of " << student[i].name << ": ";
			std::cin >> student[i].test[j];
			while (student[i].test[j] < 0 || student[i].test[j] > 100)
			{
				std::cout << "The test score should be in the range of 0~100, please re-input: ";
				std::cin >> student[i].test[j];
			}
		}

		std::cin.ignore(); //to skip the '\n'
	}
}

//grade determination function, accepts average score, returns the grade
char decide_grade(double score)
{
	if (score >= 91)
		return 'A';
	else if (score >= 81)
		return 'B';
	else if (score >= 71)
		return 'C';
	else if (score >= 61)
		return 'D';
	else
		return 'F';
}

//score analysis function, to find out the average score and record grade
void score_analysis(Student_data *student, int num_student, int num_test)
{
	//calculate average score, and then record grade
	for (int i = 0; i<num_student; i++)
	{
		double total = 0; //initialize running total
		for (int j = 0; j<num_test; j++)
		{
			total += student[i].test[j];
		}
		student[i].average = total / num_test;
		student[i].grade = decide_grade(student[i].average);
	}
}

//printing function
void print(Student_data *student, int num_student)
{
	std::ofstream cout;
	cout.open("D:\\student score report.txt");

	//print the table head
	cout << "Course Grade Report\n"
		<< "----------------------\n\n\n"
		<< "Student Name           Student ID           Average Test Score           Course Grade\n"
		<< "------------------------------------------------------------------------------------------\n";

	//print the table
	cout << std::setprecision(2) << std::fixed << std::left;
	for (int i = 0; i<num_student; i++)
	{
		cout << std::setw(28) << student[i].name << std::setw(24) << student[i].idnum << std::setw(27) << student[i].average << student[i].grade << "\n";
	}

	//print the table end
	cout << "------------------------------------------------------------------------------------------\n";

	//notify user of completion
	std::cout << "Report generated.\n";
}





}

13. Drink machine simulator
{

#include <iostream>
#include <string>
#include <iomanip>

struct Drink_info
{
	std::string name;
	double cost;
	int num;
};

void show_menu(char &choice, Drink_info *inventory);

int main()
{
	//create an array of Drink_info, initialize it
	Drink_info inventory[5] = { { "Cola", 0.75, 3 },{ "Root Beer", 0.75, 20 },{ "Lemon-Lime", 0.75, 20 },{ "Grape Soda", 0.8, 20 }, { "Cream Soda", 0.8, 20 } };

	char choice; //to hold user's choice
	double earn = 0; //running total for the amount of money this machine earns
	double purchase; //hold the amount of money user inputted

	do
	{
		//show menu and ask the user for choice
		show_menu(choice, inventory);

		//sell the drink
		int insufficient = 0;
		std::cout << std::setprecision(2) << std::fixed;
		switch (choice)
		{
			//sell Cola
		case '1':
			//check stock
			if (inventory[0].num == 0)
			{
				std::cout << "Sorry, Cola is sold out, please pick another drink.\n";
				break;
			}

			//ask to insert money
			std::cout << "Please insert money (only accepts amount under $1.00): ";
			std::cin >> purchase;
			while (purchase > 1 || purchase < inventory[0].cost || purchase <= 0)
			{
				if (purchase > 1 || purchase <= 0)
					std::cout << "Only accepts positive amount under $1.00, please re-insert: ";
				else
				{
					std::cout << "Your money is not enough to make this purchase.\n";
					insufficient = 1;
					break;
				}

				std::cin >> purchase;
			}

			if (insufficient)
				break; //insufficient fund, return to the menu
			//sell drink and show change
			earn += inventory[0].cost; //keep running total
			inventory[static_cast<int>(choice) - 49].num--; //update stock amount
			std::cout << "Here is your drink. Your change is: $" << purchase - inventory[0].cost << ".\n"; //show change
			std::cin.ignore(); //ignore the '\n'
			std::cout << "Press enter to continue...";
			std::cin.get();
			break;

			//sell Root beer
		case '2':
			//check stock
			if (inventory[1].num == 0)
			{
				std::cout << "Sorry, Root beer is sold out, please pick another drink.\n";
				break;
			}

			//ask to insert money
			std::cout << "Please insert money (only accepts amount under $1.00): ";
			std::cin >> purchase;
			while (purchase > 1 || purchase < inventory[1].cost || purchase <= 0)
			{
				if (purchase > 1 || purchase <= 0)
					std::cout << "Only accepts positive amount under $1.00, please re-insert: ";
				else
				{
					std::cout << "Your money is not enough to make this purchase.\n";
					insufficient = 1;
					break;
				}

				std::cin >> purchase;
			}

			if (insufficient)
				break;
			//sell drink and show change
			earn += inventory[1].cost;
			inventory[static_cast<int>(choice) - 49].num--; //update stock amount
			std::cout << "Here is your drink. Your change is: $" << purchase - inventory[1].cost << ".\n";
			std::cin.ignore(); //ignore the '\n'
			std::cout << "Press enter to continue...";
			std::cin.get();
			break;

			//Sell lemon-lime
		case '3':
			//check stock
			if (inventory[2].num == 0)
			{
				std::cout << "Sorry, Lemon-Lime is sold out, please pick another drink.\n";
				break;
			}

			//ask to insert money
			std::cout << "Please insert money (only accepts amount under $1.00): ";
			std::cin >> purchase;
			while (purchase > 1 || purchase < inventory[2].cost || purchase <= 0)
			{
				if (purchase > 1 || purchase <= 0)
					std::cout << "Only accepts positive amount under $1.00, please re-insert: ";
				else
				{
					std::cout << "Your money is not enough to make this purchase.\n";
					insufficient = 1;
					break;
				}

				std::cin >> purchase;
			}

			if (insufficient)
				break;
			//sell drink and show change
			inventory[static_cast<int>(choice) - 49].num--; //update stock amount
			earn += inventory[2].cost;
			std::cout << "Here is your drink. Your change is: $" << purchase - inventory[2].cost << ".\n";
			std::cin.ignore(); //ignore the '\n'
			std::cout << "Press enter to continue...";
			std::cin.get();
			break;

			//sell grape soda
		case '4':
			//check stock
			if (inventory[3].num == 0)
			{
				std::cout << "Sorry, grape soda is sold out, please pick another drink.\n";
				break;
			}

			//ask to insert money
			std::cout << "Please insert money (only accepts amount under $1.00): ";
			std::cin >> purchase;
			while (purchase > 1 || purchase < inventory[3].cost || purchase <= 0)
			{
				if (purchase > 1 || purchase <= 0)
					std::cout << "Only accepts positive amount under $1.00, please re-insert: ";
				else
				{
					std::cout << "Your money is not enough to make this purchase.\n";
					insufficient = 1;
					break;
				}

				std::cin >> purchase;
			}

			if (insufficient)
				break;
			//sell drink and show change
			earn += inventory[3].cost;
			inventory[static_cast<int>(choice) - 49].num--; //update stock amount
			std::cout << "Here is your drink. Your change is: $" << purchase - inventory[3].cost << ".\n";
			std::cin.ignore(); //ignore the '\n'
			std::cout << "Press enter to continue...";
			std::cin.get();
			break;

			//sell cream soda
		case '5':
			//check stock
			if (inventory[4].num == 0)
			{
				std::cout << "Sorry, Cream soda is sold out, please pick another drink.\n";
				break;
			}

			//ask to insert money
			std::cout << "Please insert money (only accepts amount under $1.00): ";
			std::cin >> purchase;
			while (purchase > 1 || purchase < inventory[4].cost || purchase <= 0)
			{
				if (purchase > 1 || purchase <= 0)
					std::cout << "Only accepts positive amount under $1.00, please re-insert: ";
				else
				{
					std::cout << "Your money is not enough to make this purchase.\n";
					insufficient = 1;
					break;
				}

				std::cin >> purchase;
			}

			if (insufficient)
				break;
			//sell drink and show change
			earn += inventory[4].cost;
			inventory[static_cast<int>(choice) - 49].num--; //update stock amount
			std::cout << "Here is your drink. Your change is: $" << purchase - inventory[4].cost << ".\n";
			std::cin.ignore(); //ignore the '\n'
			std::cout << "Press enter to continue...";
			std::cin.get();
			break;

		}

	} while (choice != '6');

	//after exiting the program, display the total amount of earning by this run
	std::cout << "You quitted. The total earning of this run is: $";
	std::cout << earn << "\n";

	return 0;

}

void show_menu(char &choice, Drink_info *inventory)
{
	//print out the table of current drinks available
	std::cout << "Soft drink vendor machine\n";
	std::cout << std::setprecision(2) << std::fixed;

	for (int i = 0; i<5; i++)
	{
		std::cout << i + 1 << ". " << inventory[i].name << "\n";
		std::cout << "\tCost: $" << inventory[i].cost << "\n";
		std::cout << "\tStock: " << inventory[i].num << "\n";
	}

	std::cout << "6. Quit\n";
	std::cout << "Select one term (1~6): ";
	std::cin >> choice;
	while (choice != '1' && choice != '2' && choice != '3' && choice != '4' && choice != '5' && choice != '6')
	{
		std::cout << "Please input 1~6: ";
		std::cin >> choice;
	}
	std::cin.ignore(); //to ignore the '\n'
}

}

14. Inventory bins
{

#include <iostream>
#include <string>
#include <cctype>
#include <iomanip>

struct Bin_info
{
	std::string name; //hold the name of the part stored in bin
	int num; //hold the number of the part
};

//void add_part(Bin_info &bin, int num);
//void remove_part(Bin_info &bin, int num);
void show_menu(Bin_info *bin, int size, char &choice);
void process(Bin_info *bin, char choice);

int main()
{
	//create an array of ten bins, initialize them
	Bin_info bin[10] = { { "Valve", 10 },{ "Bearing", 5 },{ "Bushing", 15 },{ "Coupling", 21 },{ "Flange", 7 },{ "Gear", 5 },{ "Gear Housing", 5 },{ "Vacuum Gripper", 25 },{ "Cable", 18 },{ "Rod", 12 } };

	char choice; //to hold user's choice

	do
	{
		//show menu and ask for choice
		show_menu(bin, 10, choice);

		//if choice is not Q, user can chose add or remove parts from that bin, all these operations are finished in process function
		if (toupper(choice) != 'Q')
			process(bin, choice);

	} while (tolower(choice) != 'q');

	return 0;

}

//void add_part(Bin_info &bin, int num)
//{
//	bin.num += num;
//}
//
//void remove_part(Bin_info &bin, int num)
//{
//	bin.num -= num;
//}

//show menu function and ask for choice
void show_menu(Bin_info *bin, int size, char &choice)
{
	//print the table head
	std::cout << "\nInventory Management System\n"
		<< "----------------------------------------------------------------\n"
		<< "Bin #   Part Description          Number of Parts in the Bin\n"
		<< "----------------------------------------------------------------\n";

	//print the content
	std::cout << std::left;
	for (int i = 0; i<size; i++)
	{
		std::cout << "  " << std::setw(7) << static_cast<char>(i + 65) << std::setw(39) << bin[i].name << bin[i].num << "\n";
	}

	//print the table end
	std::cout << "----------------------------------------------------------------\n";

	//print out instruction
	std::cout << "\nPlease select one bin by inputting the bin #, or input Q to quit: ";
	std::cin >> choice;
	while ((toupper(choice) < 65 || toupper(choice) > 74) && toupper(choice) != 'Q')
	{
		std::cout << "Invalid input, please input again: ";
		std::cin >> choice;
	}
	std::cin.ignore(); //skip the '\n'
}

//process function
void process(Bin_info *bin, char choice)
{
	choice = toupper(choice);
	char selection; //to hold the user's choice: add or remove

					//ask user whether he wants to add or remove
	std::cout << "Please select your operation:\n"
		<< "1) Add item\n2) Remove item\n";
	std::cin >> selection;
	while (selection != '1' && selection != '2')
	{
		std::cout << "Invalid input, please input 1 or 2: ";
		std::cin >> selection;
	}

	//call different function based on the choice
	int num; //hold the number of item user wants to add or remove
	switch (selection)
	{
	case '1':
		std::cout << "Please input the number you want to add: ";
		std::cin >> num;
		while (num<0 || bin[static_cast<int>(choice - 65)].num + num > 30)
		{
			if (num < 0)
				std::cout << "Invalid input, please input positive value: ";
			else if (bin[static_cast<int>(choice - 65)].num + num > 30)
				std::cout << "Number of parts in this bin has exceeded 30, please input another number: ";
			std::cin >> num;
		}
		//after the above loop, num has the valid part number, add to the bin
		bin[static_cast<int>(choice - 65)].num += num;
		break;

	case '2':
		std::cout << "Please input the number you want to remove: ";
		std::cin >> num;
		while (num<0 || bin[static_cast<int>(choice - 65)].num - num < 0)
		{
			if (num < 0)
				std::cout << "Invalid input, please input positive value: ";
			else if (bin[static_cast<int>(choice - 65)].num - num < 0)
				std::cout << "Number of removal has exceeded the number of parts in the bin, please input another number: ";
			std::cin >> num;
		}
		//after the above loop, num has the valid part number, add to the bin
		bin[static_cast<int>(choice - 65)].num -= num;
		break;
	}
	
	
	//tell the user the process has been completed, and press enter to continue
	std::cout << "Process complete, press enter to continue...";
	std::cin.ignore(); //to remove '\n'
	std::cin.get();
}


}

15. Multipurpose Payroll
{

#include <iostream>

struct Hourly_paid
{
	int hour;
	double rate;
};

struct Salaried
{
	double salary;
	double bonus;
};

union Worker
{
	Hourly_paid hour_w;
	Salaried sal_w;
};

int main()
{
	char choice;
	Worker pay; //create a union type variable, which is either hourly paid or salaried worker
				//ask the user to select a type
	std::cout << "What is the work type: \n"
		<< "1) Hourly paid worker;\n2) Salaried worker\n";

	std::cin >> choice;
	while (choice != '1' && choice != '2')
	{
		std::cout << "Invalid input, please input 1 or 2: ";
		std::cin >> choice;
	}

	switch (choice)
	{
	case '1':
		std::cout << "How many hours you worked: ";
		std::cin >> pay.hour_w.hour;
		while (pay.hour_w.hour <= 0 || pay.hour_w.hour > 80)
		{
			std::cout << "Invalid input, please input again: ";
			std::cin >> pay.hour_w.hour;
		}
		std::cout << "What is your pay rate: ";
		std::cin >> pay.hour_w.rate;
		while (pay.hour_w.rate <= 0)
		{
			std::cout << "Invalid rate, please input rate that is greater than 0: ";
			std::cin >> pay.hour_w.hour;
		}
		std::cout << "Your salary is: $" << pay.hour_w.hour * pay.hour_w.rate << "\n";
		break;

	case '2':
		std::cout << "What is your basic salary: ";
		std::cin >> pay.sal_w.salary;
		while (pay.sal_w.salary <= 0)
		{
			std::cout << "Please input salary that is greater than zero: ";
			std::cin >> pay.sal_w.salary;
		}
		std::cout << "Please input your bonus: ";
		std::cin >> pay.sal_w.bonus;
		while (pay.sal_w.bonus <= 0)
		{
			std::cout << "Please input bonus greater than zero: ";
			std::cin >> pay.sal_w.bonus;
		}
		std::cout << "Your salary is: $" << pay.sal_w.salary + pay.sal_w.bonus << "\n";
		break;
	}

	return 0;
}

}



/**********************************************************/
/** Patience and diligence, like faith, remove mountains **/
/**********************************************************/



