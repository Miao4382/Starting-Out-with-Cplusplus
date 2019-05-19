/* Chapter 12 */

/*********************/
/***Program Example***/
/*********************/

1. Practice using fstream and std::ios::out access flag
{

#include <fstream>
#include <iostream>
#include <string>

int main()
{
	std::fstream file;
	file.open("D:\\example.txt", std::ios::out);
	file << "abcdef";

	return 0;
	
}

}

2. Practice using std::ios::app access flag
{

#include <iostream>
#include <fstream>

int main()
{
	//creating file streamer: fstream
	std::fstream file;
	
	//open a file, write two line data into it, and close the file
	file.open("D:\\12-2.txt", std::ios::out);
	file << "The first line\n";
	file << "The second line\n";
	file.close();
	
	//open the same file in append mode, add another two lines to the end of the file, then close
	file.open("D:\\12-2.txt", std::ios::app);
	file << "Added third line\n";
	file << "Added fourth line.\n";
	file.close();
	
	std::cout << "Process completed.\n";
	
	return 0;
}

}

3.4. Format of file stream object, already did this in previous practice
//file existence check function (by passing path of the file)
{

#include <iostream>
#include <fstream>
#include <string>

bool open_check(std::string path);

int main()
{
	std::fstream file;
	std::string path = "D:\\example.txt";
	bool result; //to store result

	//call the open_check function to see if the path is valid
	result = open_check(path);

	//print out result
	if (result)
		std::cout << "Open successful.\n";
	else
		std::cout << "Open unsuccessdul.\n";

	return 0;
}

//check file function
bool open_check(std::string path)
{
	std::fstream file;
	file.open(path, std::ios::in);

	if (file)
	{
		file.close();
		return true;
	}

	else
	{
		file.close();
		return false;
	}
}

}

5. Demonstrate how file stream objects may be passed as argument to functions
{

#include <iostream>
#include <fstream>
#include <string>

void num_writer(std::fstream &file);
void string_writer(std::fstream &file);

int main()
{
	//creating file streamer: fstream
	std::fstream file;
	file.open("D:\\12-5.txt", std::ios::out);
	
	//write number to first line
	num_writer(file);
	
	//write string to second line
	string_writer(file);
	
	//exit
	std::cout << "Process complete.\n";
	
	return 0;
}

void num_writer(std::fstream &file)
{
	int num;
	std::cout << "Please input a number: ";
	std::cin >> num;
	std::cin.ignore(); //to ignore the '\n'
	file << num << "\n";
}

void string_writer(std::fstream &file)
{
	std::string str;
	std::cout << "Please input a string: ";
	getline(std::cin, str);
	
	file << str << "\n";
}


}

6. Practice error state bits test member function to check the status of flags
{

#include <iostream>
#include <fstream>

void show_state(std::fstream &file);

int main()
{
	std::fstream file;
	std::cout << "After creating the fstream object:\n";
	show_state(file);
	//create the file
	file.open("D:\\12-6.txt", std::ios::out);
	std::cout << "\n\nAfter openning the file\n";
	show_state(file);
	//store integer value 10 in the file
	file << 10;
	std::cout << "\n\nAfter storing a integer value of 10 into the file:\n";
	show_state(file);
	//close the file
	file.close();
	std::cout << "\n\nAfter closing the file.\n";
	show_state(file);
	//reopen for input
	file.open("D:\\12-6.txt", std::ios::in);
	std::cout << "\n\nAfter reopen for input:\n";
	show_state(file);
	//read an item to a variable
	int num;
	file >> num;
	std::cout << "\n\nAfter first attempt of reading:\n";
	show_state(file);
	//read another item to a variable
	file >> num;
	std::cout << "\n\nAfter second attempt of reading:\n";
	show_state(file);
	//show the status after clreaing
	file.clear();
	std::cout << "\n\nAfter clearing bad bit flag:\n";
	show_state(file);
	//use this input stream object to output data into the file
	file << "123";
	std::cout << "\n\nAfter invalid operation:\n";
	show_state(file);

	file.close();
	return 0;

}

void show_state(std::fstream &file)
{
	
	//test eofbit
	if (file.eof())
		std::cout << "End of an input stream is encountered\n";
	else
		std::cout << "End of an input stream is not encountered\n";
	//test failbit
	if (file.fail())
		std::cout << "An attempted operation has failed\n";
	else
		std::cout << "No attempted operation has failed\n";
	//test badbit
	if (file.bad())
		std::cout << "An invalid operation has been attempted\n";
	else
		std::cout << "No invalid operation has been attempted\n";
	//test goodbit
	if (file.good())
		std::cout << "The stream is in good condition.\n";
	else
		std::cout << "The stream is not in good condition.\n";
	file.clear(); //clear any bad bits
}

}

7. 8. Getline function. Already did this in previous practice.

9. Getline function that specifies different delimiter
{

#include <iostream>
#include <string>
#include <fstream>

int main()
{
	std::fstream file("D:\\name2.txt", std::ios::in);
	std::string str; //to hold string read from the file
	if (!file.fail())
	{
		while (getline(file, str, '$'))
			std::cout << str << "\n";
	}
	else
		std::cout << "Error, cannot open file.\n";


	return 0;
}

}

10. use get() member function to replicate a file
{

#include <iostream>
#include <fstream>

int main()
{
	std::fstream file;
	file.open("D:\\Travel Expense Report.txt", std::ios::in);

	char ch; //create a character container to hold the data read from the file, one character at a time

			 //check the open status
	if (file)
	{
		//read the first character
		file.get(ch);

		//while the eofbit is not set, continue
		while (file)
		{
			//display the character
			std::cout << ch;
			//read the next character
			file.get(ch);
		}
	}
	else
		std::cout << "File open failed, please check the path.\n";

	return 0;

}

}

11. use put() member function to add a character to a file
{

#include <iostream>
#include <fstream>

int main()
{
	std::fstream file;
	file.open("D:\\nasme2.txt", std::ios::app);
	char ch = 'E';

	if (file) //even if no name2.txt, the program will create a new file. This method is only available for input file stream. if you want to test file existence, use an input file stream object
	{
		file.put(ch);
		std::cout << "Insert completed.\n";
	}
	else
		std::cout << "File open failed, please try again.\n";

	return 0;
}

}

12. practice writting a filter program
{

#include <iostream>
#include <cctype>
#include <fstream> 	

int main()
{
	std::fstream file;
	file.open("D:\\Travel Expense Report.txt", std::ios::in);
	std::fstream write;
	write.open("D:\\Travel Expense Report_space inserted and uppercased.txt", std::ios::out);
	
	char ch; //the transfer container
	while (file)
	{
		file.get(ch);
		ch = toupper(ch); //turn into upper case
		write.put(ch); //transfer to the file
		write.put(' '); //transfer to the file, the space
	}
	
	std::cout << "Transfer completed.\n";
	file.close();
	write.close();
	
	return 0;
}

}

13. practice write and read member function
{

#include <iostream>
#include <fstream>

int main()
{
	//create a file stream object
	std::fstream file;
	file.open("D:\\12-13.txt", std::ios::out | std::ios::binary); //open in binary mode

																  //create a character array
	char ch[] = { 'A', 'B', 'c', 'D', 'e', '\n', 'K' };
	//write into the file
	file.write(ch, sizeof(ch));
	//disconnect
	file.close();
	//open in read|binary mode
	file.open("D:\\12-13.txt", std::ios::in | std::ios::binary);
	//create another string to hold the data 
	char ch2[sizeof(ch) / sizeof(char)];
	//read the file, store the value in the char array
	file.read(ch2, sizeof(ch2));
	//print out the content of ch and ch2
	for (int i = 0; i<sizeof(ch) / sizeof(char); i++)
	{
		std::cout << ch[i] << "  " << ch2[i] << "\n";
	}
	return 0;

}

}

14. continue to practice write and read member function (write and read an array)
{

#include <iostream>
#include <fstream>

int main()
{
	//create a file stream object, open the file in write|binary mode
	std::fstream file;
	file.open("D:\\example.txt", std::ios::out | std::ios::binary);

	//create a double number and save to the file (in binary form)
	double num[5] = { 2.1, 3.4, 5.6, 1.2, 9.4 };
	file.write(reinterpret_cast<char *>(num), sizeof(num));

	//disconnect the file stream object
	file.close();

	//open the file in read|binary mode)
	file.open("D:\\example.txt", std::ios::in | std::ios::binary);

	//create a new variable, store the data read from the file
	double num2[5];	
	file.read(reinterpret_cast<char *>(num2), sizeof(num2));

	//print out the data stored in num2
	std::cout << "The number array is: ";
	for (int i = 0; i < 5; i++)
	{
		std::cout << num2[i] << " ";
	}
	std::cout << "\n";

	return 0;
}

}

15. Creating records with structures
{

#include <iostream>
#include <fstream>

struct Person_info
{
	char name[21];
	char gender;
};

int main()
{
	//create a file stream object
	std::fstream file;
	file.open("D:\\12-15.dat", std::ios::out | std::ios::binary);

	//input data
	char choice;
	do
	{
		Person_info person;
		std::cout << "What is the person's name: ";
		std::cin.getline(person.name, sizeof(person.name));
		std::cout << "What is the person's gender: (M/F)";
		std::cin >> person.gender;

		//store the data in file
		file.write(reinterpret_cast<char *>(&person), sizeof(person));

		//ask for repeat
		std::cout << "Do you want to save another record? (y/n): ";
		std::cin >> choice;
		std::cin.ignore(); //skip the '\n'
	} while (choice != 'n');

	std::cout << "Thank you, data has been recorded\n";

	file.close();

	return 0;
}

}

16. Read records created by structures
{

#include <iostream>
#include <fstream>
#include <string>

struct Person_info
{
	char name[21];
	char gender;
};

int main()
{
	//create a file stream object in read | binary mode
	std::fstream file;
	file.open("D:\\12-15.dat", std::ios::in | std::ios::binary);

	//create a string variable to hold path, verify file openning status
	std::string path;
	while (file.fail()) //this means the openning of file has failed
	{
		std::cout << "File open failed, please check your path and input again: ";
		getline(std::cin, path);
		file.clear(); //clear the failbit
		file.open(path, std::ios::in | std::ios::binary);
	}

	//create a structure variable 
	Person_info person;

	//read the content in file until the end of the document
	int counter = 1; //counter for the number of people
	while (!file.eof()) //while the end of the file has not been met, continue to read 
	{
		file.read(reinterpret_cast<char *>(&person), sizeof(person)); //read one record of person data type
																	  //print out the record
		std::cout << "Record " << counter++ << "\n\tName: " << person.name << "\n\tGender: " << person.gender << "\n\n";
	}

	file.close();

	return 0;
}

}

17. Practice using seekg
{

#include <iostream>
#include <fstream>

void show_state(std::fstream &file);

int main()
{
	//create a file stream object, open the file in read mode
	std::fstream file;
	file.open("D:\\letters.txt", std::ios::in);

	//ask user to input the reading position
	char choice;
	do
	{
		int position;
		char letter;
		std::cout << "Which character you want to read: ";
		std::cin >> position;

		//move the file stream object
		file.clear(); //clear bad status so the file stream object can work properly
		file.seekg(position - 1, std::ios::beg);
		//check file status
		show_state(file);

		//read the content
		file >> letter;
		//print the content
		std::cout << "Letter stored there is: " << letter << "\n";

		//ask for repeat
		std::cout << "Would you want to test another letter? y/n: ";
		std::cin >> choice;
	} while (choice != 'n');

	std::cout << "You quitted.\n";

	return 0;
}

void show_state(std::fstream &file)
{
	std::cout << "\n\nTest result:\n";
	//test eofbit
	if (file.eof())
		std::cout << "End of an input stream is encountered\n";
	else
		std::cout << "End of an input stream is not encountered\n";
	//test failbit
	if (file.fail())
		std::cout << "An attempted operation has failed\n";
	else
		std::cout << "No attempted operation has failed\n";
	//test badbit
	if (file.bad())
		std::cout << "An invalid operation has been attempted\n";
	else
		std::cout << "No invalid operation has been attempted\n";
	//test goodbit
	if (file.good())
		std::cout << "The stream is in good condition.\n";
	else
		std::cout << "The stream is not in good condition.\n";

}

}

18. seekg used to seek structured data
{

#include <iostream>
#include <fstream>

struct Person_info
{
	char name[21];
	char gender;
};

int main()
{
	//create a file stream object
	std::fstream file;
	file.open("D:\\12-15.dat", std::ios::in | std::ios::binary);
	
	//create a Person_info variable to hold the data read from the file
	Person_info person;
	
	//ask for user which record they want to see
	int position;
	std::cout << "Which record to view: ";
	std::cin >> position;
	
	//move the file read position to the destination
	file.seekg((position-1)*sizeof(person), std::ios::beg);
	
	//read to the variable
	file.clear();
	file.read(reinterpret_cast<char *>(&person), sizeof(person));
	
	//print out 
	std::cout << "\nName: " << person.name << "\n"
	<< "Gender: " << person.gender << "\n";
	
	return 0;
}


}

19. practice using tellg member function to find out the size of the file
{

#include <iostream>
#include <fstream>

int main()
{
	//create a file stream object, open a file in read 
	std::fstream file;
	file.open("D:\\Travel Expense Report_space inserted and uppercased.txt", std::ios::in);

	//move the read position to the end of the file
	file.seekg(0, std::ios::end);
	//use an integer to hold the size
	long long size;
	size = file.tellg();
	//report the size
	std::cout << "The file has a size of " << size << " bytes\n";

	return 0;
}

}


20. practice using binary mode to save structure variable to file 
{

#include <iostream>
#include <fstream>

const int NUM = 5;

//structure: inventory records
struct Item
{
	char description[100];
	int stock;
	double price;
};

//function prototype, for string copy function
void strcpy2(char *destination, const char *source);

int main()
{
	//define a file stream object, open a file in write|binary mode, binary mode is to write the structure variable into the file
	std::fstream file;
	file.open("D:\\12-20.dat", std::ios::out | std::ios::binary);

	//define an array of Item type (total number is five), and initialize it with blank data 
	Item inventory[NUM];
	for (int i = 0; i<NUM; i++)
	{
		strcpy2(inventory[i].description, "None"); //to store None in description of each struct variable 
		inventory[i].stock = 0; //stock number is zero
		inventory[i].price = 0.0; //price is zero 		
	}

	//now, store the array of inventory to file, (using binary mode)
	file.write(reinterpret_cast<char *>(inventory), sizeof(inventory));

	//close the file
	file.close();

	//show completion
	std::cout << "The process has been completed.\n";

	return 0;
}

//string copy function
void strcpy2(char *destination, const char *source)
{
	int i = 0;
	while (source[i] != '\0')
		destination[i] = source[i++];
	destination[i] = '\0';
}

}

21. Display contents of the file created in 20
{

#include <iostream>
#include <fstream>

//structure: inventory records
struct Item
{
	char description[100];
	int stock;
	double price;
};

//function prototype, display the content of Item variable 
void display(Item record);

int main()
{
	//create a file stream object and open the file in read|binary mode
	std::fstream file;
	file.open("D:\\12-20.dat", std::ios::in | std::ios::binary);
	
	//display each element
	Item record; //define a container to hold the Item variable
	while (!file.eof()) //while the file stream object has not met the end
	{
		file.read(reinterpret_cast<char *>(&record), sizeof(record)); //read data from the file to the transfer variable: record
		display(record); //display the record
	}
	
	//close the file stream object 
	file.close();
	
	return 0;
}

//display function, will display the content of the Item variable
void display(Item record)
{
	std::cout << "\n";
	std::cout << "Description: " << record.description << "\n";
	std::cout << "Stock: " << record.stock << "\n";
	std::cout << "Price: $" << record.price << "\n";
}

}

22. Practice openning a file with both input and output mode, allows the user to change the content of the specified record 
{

#include <iostream>
#include <fstream>

//structure: inventory records
struct Item
{
	char description[100];
	int stock;
	double price;
};

//function prototype, display the content of Item variable 
void display(Item record);

//to modify record
void modify_record(Item &record);

//str copy function
void strcpy2(char *destination, const char *source);

int main()
{
	//create a file stream object
	std::fstream file;


	//prepare for 
	char repeat; //hold user's choice: whether or not continue
	const int size = sizeof(Item); //store the size of one record in file 
	int choice;
	Item record; //hold the write or read transfer variable 
	Item record2;

	do
	{
		//open the file
		file.open("D:\\12-20.dat", std::ios::binary | std::ios::in | std::ios::out);
		//display the whole record
		for (int i = 0; i<5; i++)
		{
			std::cout << "\nNo. " << i + 1;
			file.read(reinterpret_cast<char *>(&record), size);
			display(record);
		}
		file.clear(); //clear the eof() flag

					  //ask the user which record to change
		std::cout << "Please input the record to change: ";
		std::cin >> choice;
		std::cin.ignore(); //skip the '/n'
		choice--; //transfer from 1~5 to 0~4

				  //read the corresponding record
				  //move the file stream object to the target position
		file.seekg(choice*size, std::ios::beg);
		//read the record
		file.read(reinterpret_cast<char *>(&record), size);

		//call a function to modify the record
		modify_record(record);

		//write the record back into the file
		//move the file stream object back to the target position
		file.seekp(-size, std::ios::cur);
		//file.seekp(choice*size, std::ios::beg);
		//write the record into file
		file.write(reinterpret_cast<char *>(&record), size);

		//ask the user if he wants to modify another record
		std::cout << "Do you want to modify another record: (y/n)";
		std::cin >> repeat;
		std::cin.ignore();

		//close the file
		file.close();

	} while (repeat != 'N' && repeat != 'n');

	//display the final record 
	std::cout << "\n\nFinal record:";
	//open the file
	file.open("D:\\12-20.dat", std::ios::in);
	//print
	for (int i = 0; i<5; i++)
	{
		std::cout << "\nNo. " << i + 1;
		file.read(reinterpret_cast<char *>(&record), size);
		display(record);
	}

	//disconnect the file stream object
	file.close();

	return 0;
}

//display function, will display the content of the Item variable
void display(Item record)
{
	std::cout << "\n";
	std::cout << "Description: " << record.description << "\n";
	std::cout << "Stock: " << record.stock << "\n";
	std::cout << "Price: $" << record.price << "\n";
}

//modify the record 
void modify_record(Item &record)
{
	char descript[100];
	std::cout << "Please input the description: ";
	std::cin.getline(descript, 100); //get description
	strcpy2(record.description, descript); //copy the description to record variable 

	std::cout << "Please input the stock number: ";
	std::cin >> record.stock;

	std::cout << "Please input the price: ";
	std::cin >> record.price;

	std::cin.ignore(); //skip the '\n'
	std::cout << "Modify complete.\n";
}

//string copy function
void strcpy2(char *destination, const char *source)
{
	int i = 0;
	while (source[i] != '\0')
		destination[i] = source[i++];
	destination[i] = '\0';
}



}

Case study: High Adventure Travel Agency
{

1) extra printing check
{

#include <iostream>
#include <fstream>

int main()
{
	std::fstream file("D:\\test.txt", std::ios::in | std::ios::binary);

	char transfer;
	int counter = 0;

	while (!file.eof())
	{
		file.read(&transfer, sizeof(transfer));
		counter++;
		if (!file.eof())
			std::cout << "Time of reading: " << counter << " Reading content: " << transfer << " File eof():  " << file.eof() << "\n";
		
	}

	return 0;
}

}

2) Code
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
const std::string PATH = "D:\\High Adventure Reservation File.dat"; //to hold the path of reservation file

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
void devil_buy();
void devil_print(const Purchase &purch);
void scuba_buy();
void scuba_print(const Purchase &purch);
void sky_buy();
void sky_print(const Purchase &purch);
void barron_buy();
void barron_print(const Purchase &purch);
void display_reservation();
void result_analysis(); //read data from the reservation file and do result analysis

int main()
{
	char selection; //to hold the choice user made

	do
	{
		show_menu(selection); //show menu and make a choice

		switch (selection)
		{
		case '1': devil_buy(); break;
		case '2': scuba_buy(); break;
		case '3': sky_buy(); break;
		case '4': barron_buy(); break;
		case '5': display_reservation(); break;
		case '6': break;
		}

		if (selection != '6')
		{
			std::cout << "Purchase complete, press enter to continue.";
			std::cin.get();
		}

	} while (selection != '6');

	std::cout << "You quitted. The program is creating analysis report...\n";

	//call result analysis function to analysis the whole result, then write the result to a new report
	result_analysis();

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
	std::cout << "5) Show Reservation file\n";
	std::cout << "6) Exit\n";
	std::cin >> selection;
	while (selection != '1' && selection != '2' && selection != '3' && selection != '4' && selection != '5' && selection != '6')
	{
		std::cout << "Invalid input! Please input 1-6: ";
		std::cin >> selection;
	}
}

//devil buy function
void devil_buy()
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

	//create a file stream pbject, open the file in app | binary mode, to save purch into the file (append to the end of the file), and then close the file
	std::fstream file;
	file.open(PATH, std::ios::app | std::ios::binary);
	file.write(reinterpret_cast<char *>(&purch), sizeof(purch));
	file.close();

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
void scuba_buy()
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

	//create a file stream pbject, open the file in app | binary mode, to save purch into the file (append to the end of the file), and then close the file
	std::fstream file;
	file.open(PATH, std::ios::app | std::ios::binary);
	file.write(reinterpret_cast<char *>(&purch), sizeof(purch));
	file.close();

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
void sky_buy()
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

	//create a file stream pbject, open the file in app | binary mode, to save purch into the file (append to the end of the file), and then close the file
	std::fstream file;
	file.open(PATH, std::ios::app | std::ios::binary);
	file.write(reinterpret_cast<char *>(&purch), sizeof(purch));
	file.close();

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
void barron_buy()
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

	//create a file stream pbject, open the file in app | binary mode, to save purch into the file (append to the end of the file), and then close the file
	std::fstream file;
	file.open(PATH, std::ios::app | std::ios::binary);
	file.write(reinterpret_cast<char *>(&purch), sizeof(purch));
	file.close();

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

//display reservation file content. The length of each record is the same (although the length of different packages are different, they are unioned together, and the saved data unit is an integer + the union data type. So each record has the same length)
void display_reservation()
{
	//define a file stream object
	std::fstream file;
	file.open(PATH, std::ios::in | std::ios::binary);

	//define a container to hold data read from the file, and a counter to hold the index
	Purchase record;
	int counter = 0;
	//read the first record
	file.read(reinterpret_cast<char *>(&record), sizeof(record));

	while (!file.eof()) //while the end of the file has not been reached
	{
		counter++;
		std::cout << "Reservation No. " << counter << ":\n";
		switch (record.pack_num)
		{
		case 1:
			std::cout << "Number of people: " << record.pack.devil.num << "\n";
			std::cout << "Basic charge: $" << record.pack.devil.charge_base << "\n";
			std::cout << "Discount: $" << record.pack.devil.discount << "\n";
			std::cout << "People needs equipment: " << record.pack.devil.num_equipment << "\n";
			std::cout << "People needs instruction: " << record.pack.devil.num_instruction << "\n";
			std::cout << "Total charge: $" << record.pack.devil.charge_total << "\n";
			std::cout << "Deposit: $" << record.pack.devil.deposit << "\n";
			break;
		case 2:
			std::cout << "Number of people: " << record.pack.scuba.num << "\n";
			std::cout << "Basic charge: $" << record.pack.scuba.charge_base << "\n";
			std::cout << "Discount: $" << record.pack.scuba.discount << "\n";
			std::cout << "People needs instruction: " << record.pack.scuba.num_instruction << "\n";
			std::cout << "Total charge: $" << record.pack.scuba.charge_total << "\n";
			std::cout << "Deposit: $" << record.pack.scuba.deposit << "\n";
			break;
		case 3:
			std::cout << "Number of people: " << record.pack.sky.num << "\n";
			std::cout << "Basic charge: $" << record.pack.sky.charge_base << "\n";
			std::cout << "Discount: $" << record.pack.sky.discount << "\n";
			std::cout << "Number of people needs wilderness lodge: " << record.pack.sky.num_wild << "\n";
			std::cout << "Number of people needs luxury inn: " << record.pack.sky.num_inn << "\n";
			std::cout << "Total charge: $" << record.pack.sky.charge_total << "\n";
			std::cout << "Deposit: $" << record.pack.sky.deposit << "\n";
			break;
		case 4:
			std::cout << "Number of people: " << record.pack.barron.num << "\n";
			std::cout << "Basic charge: $" << record.pack.barron.charge_base << "\n";
			std::cout << "Discount: $" << record.pack.barron.discount << "\n";
			std::cout << "People needs equipment: " << record.pack.barron.num_equipment << "\n";
			std::cout << "Total charge: $" << record.pack.barron.charge_total << "\n";
			std::cout << "Deposit: $" << record.pack.barron.deposit << "\n";
			break;
		}

		std::cout << "\n\n";

		//read the next record
		file.read(reinterpret_cast<char *>(&record), sizeof(record));
	}

	//close the file stream object
	file.close();

}

//result analysis function
void result_analysis()
{
	//read data from the file and analyze
	//define a file streamer, open the reservation file in read|binary mode
	std::fstream file;
	file.open(PATH, std::ios::in | std::ios::binary);

	//define a container to transfer record to the vector
	Purchase record;

	//define file streamer, to write report
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
	while (!file.eof())
	{
		//load the record to the file 
		file.read(reinterpret_cast<char *>(&record), sizeof(record));

		//update record
		if (!file.eof())
		{
			switch (record.pack_num)
			{
			case 1:
				sale.total_devil += record.pack.devil.charge_total;
				sale.devil_num++;
				sale.total += record.pack.devil.charge_total;
				sale.total_discount += record.pack.devil.discount;
				break;
			case 2:
				sale.total_scuba += record.pack.scuba.charge_total;
				sale.scuba_num++;
				sale.total += record.pack.scuba.charge_total;
				sale.total_discount += record.pack.scuba.discount;
				break;
			case 3:
				sale.total_sky += record.pack.sky.charge_total;
				sale.sky_num++;
				sale.total += record.pack.sky.charge_total;
				sale.total_discount += record.pack.sky.discount;
				break;
			case 4:
				sale.total_barron += record.pack.barron.charge_total;
				sale.barron_num++;
				sale.total += record.pack.barron.charge_total;
				sale.total_discount += record.pack.barron.discount;
				break;
			}
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

	//close the file stream object
	cout.close();
	file.close();

}


}

}



/****************************/
/***Programming Challenges***/
/****************************/

1. File head program
{

#include <string>
#include <fstream>
#include <iostream>

int main()
{
	std::string path;
	std::cout << "Please input the path of the file: ";
	getline(std::cin, path);
	
	//define a file streamer, and open the file 
	std::fstream file(path, std::ios::in);
	while (!file)
	{
		std::cout << "Unable to open the file, please input the path again: ";
		getline(std::cin, path);
		file.open(path, std::ios::in);
	}
	
	//define a counter and a container to hold content read from the file
	int counter = 0;
	std::string line;
	
	//read from the file and print, for the first 10 lines
	while (getline(file, line) && counter++ < 10)
	{
		std::cout << line << "\n";
	}
	
	//check if the end of the file has been reached
	if (file.eof())
		std::cout << "The entire file has been displayed.\n";
	else
		std::cout << "The header has been displayed.\n";
	
	//disconnect file
	file.close();
	
	return 0;
}

}

2. File display program
{

#include <string>
#include <fstream>
#include <iostream>

const int LINE_NUM = 5;

int main()
{
	std::string path;
	std::cout << "Please input the path of the file: ";
	getline(std::cin, path);
	
	//define a file streamer, and open the file 
	std::fstream file(path, std::ios::in);
	while (!file)
	{
		std::cout << "Unable to open the file, please input the path again: ";
		getline(std::cin, path);
		file.open(path, std::ios::in);
	}
	
	//define a counter and a container to hold content read from the file
	int counter = 1;
	std::string line;
	
	//load the first line
	getline(file, line);
	
	while (!file.eof()) //while the end has not been reached
	{
		std::cout << line << "\n";
		counter++;
		if (counter > LINE_NUM) //when counter reaches 5
		{
			std::cout << "Display paused, please press enter to continue...";
			std::cin.get();
			std::cout << "\n";
			counter = 1;
			getline(file, line);
			continue;
		}
		getline(file, line); //load the following line
	}
	
	std::cout << "The entire file has been displayed.\n";
	
	return 0;
}

}

3. Punch line 
{

#include <iostream>
#include <fstream>
#include <string>

void display_joke(std::fstream &file_joke);
void display_punchline(std::fstream &file_punchline);

int main()
{
	//create two file stream object
	std::fstream file_joke("D:\\joke.txt", std::ios::in);
	std::fstream file_punchline("D:\\punchline.txt", std::ios::in);
	
	//call display_joke to show joke
	display_joke(file_joke);
	
	//call display_punchline to show punchline
	display_punchline(file_punchline);
	
	//disconnect two file stream object 
	file_joke.close();
	file_punchline.close();
	
	return 0;
}

void display_joke(std::fstream &file_joke)
{
	std::string line;
	
	while (getline(file_joke, line))
		std::cout << line << "\n";
	
}

void display_punchline(std::fstream &file_punchline)
{
	//move to the end of the file (not the last element, because it might be '\n')
	file_punchline.seekg(-1, std::ios::end);
	
	//define a character to hold the current content in file. The search is backward, looking for '\n', which is a symbol of newline
	char ch;
	do
	{
		file_punchline.get(ch);
		if (ch == '\n')
			break;
		file_punchline.seekg(-2, std::ios::cur); //go backward two elements, because the reading will push the position forward for 1 unit
	} while (ch != '\n');
	
	//after the loop, now the position should be the first character of the last line 
	std::string line;
	getline(file_punchline, line);
	std::cout << line << "\n";
}


}

4. Tail program (The myth of backward)
{

1) about the '\n' and seekg, it seems when the file streamer reads \n, it actually moves two bytes, rather than one. Following code shows the process of reverse printing a file
{

#include <iostream>
#include <fstream>
#include <string>

int main()
{
	//define the file stream object
	std::fstream file;

	//define a path container and ask user to input path 
	std::string path;
	path = "D:\\P4_long.txt";

	//open the file 
	file.open(path, std::ios::in);
	if (!file)
	{
		std::cout << "File open failed. Please check the file and restart the program.\n";
		return 0;
	}

	char ch;
	file.seekg(-1, std::ios::end);
	file.get(ch);
	
	do
	{
		std::cout << ch;
		if (ch == '\n')
			file.seekg(-3, std::ios::cur);
		else
			file.seekg(-2, std::ios::cur);
		file.get(ch);
	} while (ch != 'Z');
	

	return 0;
}



}

2) Code
{

#include <iostream>
#include <fstream>
#include <string>

int main()
{
	//define the file stream object
	std::fstream file;

	//define a path container and ask user to input path 
	std::string path;
	path = "D:\\P4_short.txt";

	//open the file 
	file.open(path, std::ios::in);
	if (!file) //check whether the file has been opened
	{
		std::cout << "File open failed. Please check the file and restart the program.\n";
		return 0;
	}

	//move the file streamer to the end
	file.seekg(-1, std::ios::end); //the first character before EOF
	int counter = 0; //to hold the total number of '\n' encounterred while going backward
	char ch; //hold the character read from the file. To check whether the character is '\n'
	int loop_counter = 0;
	do
	{
		file.get(ch); //to get the character 
		if (ch == '\n')
		{
			counter++; //found one '\n', update the counter
			file.seekg(-3, std::ios::cur); //move the file streamer
		}
		else
			file.seekg(-2, std::ios::cur); //move the file streamer
		
	} while (counter < 5 && !file.fail()); //when the streamer reaches the first position in the file, stop 
	if (counter == 5)
		file.seekg(3, std::ios::cur); //to offset the last moving from the if statement, which is not desired
	else
	{
		file.clear();
		file.seekg(0, std::ios::beg);
	}
		
									  //after the above code, now the file streamer is at the beginning of the last 5 line, proceed to next step

	std::string line; //define a container to hold the content read from the file 
	while (getline(file, line))
		std::cout << line << "\n";

	if (counter == 5)
		std::cout << "The last 5 lines are displayed.\n";
	else
		std::cout << "The entire file is displayed.\n";


	file.close(); //close the file

	return 0;
}


}

}

5. Line numbers
{


#include <string>
#include <fstream>
#include <iostream>

const int LINE_NUM = 5;

int main()
{
	std::string path;
	std::cout << "Please input the path of the file: ";
	getline(std::cin, path);

	//define a file streamer, and open the file 
	std::fstream file(path, std::ios::in);
	while (!file)
	{
		std::cout << "Unable to open the file, please input the path again: ";
		getline(std::cin, path);
		file.open(path, std::ios::in);
	}

	//define a counter and a container to hold content read from the file
	int counter = 1;
	std::string line;

	//load the first line
	getline(file, line);

	while (!file.eof()) //while the end has not been reached
	{
		std::cout << counter++ << ": ";
		std::cout << line << "\n";
		getline(file, line); //load the following line
	}

	std::cout << "The entire file has been displayed.\n";

	return 0;
}

}

6. String search
{

#include <iostream>
#include <string>
#include <fstream>

void get_info(std::fstream &file, std::string &path, std::string &keyword);

int main()
{	
	//define a file stream object, call a function to get path and keyword
	std::fstream file; //file stream object
	std::string path; //to hold path of the file
	std::string keyword; //to hold the keyword to search
	get_info(file, path, keyword);
	
	//search each line of the file, display line that contains the keyword
	std::cout << "Search result:\n";
	int match_counter_total = 0; //hold the total number of matches
	int match_counter_line; //hold number of matches in a specific line 
	std::string line; //define a container to hold data read from the file
	getline(file, line); //store first line into the line variable
	
	while (!file.eof()) //while the end of the file has not been reached
	{
		match_counter_line = 0; //initialize line match_counter
		if (line.find(keyword) != -1) //this indicates match is found, should display the line and find out how many matches in this line 
		{
			std::cout << line << "\n\n"; //display the entire line
			int position = 0; //hold the position where to start searching
			while (position < line.length()-keyword.length()) //while the position is not the end of the string, find the keyword.
			{
				position = line.find(keyword, position); //search for match
				if (position != -1) //this means matches found
				{
					match_counter_line++; //update the line match counter
					position += keyword.length(); //update the position, to the first character after a matched keyword 
				}
			}
			
			std::cout << "Matched record in this line: " << match_counter_line << "\n\n"; //display matched record in this line 
			match_counter_total += match_counter_line; //update the total match number			
		}
		getline(file, line); //read the next line
	}
	
	std::cout << "Total matches: " << match_counter_total << "\n";
	
	file.close();
	return 0;
	
	
}

void get_info(std::fstream &file, std::string &path, std::string &keyword)
{
	path = "D:\\P6.txt";
	
	std::cout << "Please input the keyword: ";
	getline(std::cin, keyword);
	
	file.open(path, std::ios::in);
	
}


}

7. Sentence Filter
{

#include <iostream>
#include <fstream>
#include <cctype>

int main()
{
	/* Define two file stream object, open two files */
	std::fstream cout("D:\\P7_2.txt", std::ios::out); //for output 
	std::fstream cin("D:\\P7_1.txt", std::ios::in); //input

													/* Go over file_1 and turn the first letter after '.', '!' and '?' to upper case, save the data in file_2 */
	char ch; //hold the character read from the file
	cin.get(ch); //read the first character from file into ch
	cout.put(toupper(ch)); //save the upper case into file_2
	cin.get(ch); //read the second character

	while (!cin.eof()) //while the end has not been reached
	{
		if (ch == '.' || ch == '?' || ch == '!') //if a period is encountered.
		{
			while (!isalpha(ch) && !cin.eof()) //while the character is not letter
			{
				std::cout << ch;
				cout.put(ch); //put the character into file_2
				cin.get(ch); //read the next character
			}

			cout.put(toupper(ch)); //after the above loop, ch contains the first letter, save the upper case version into file_2
			cin.get(ch); //read the next character			
		}
		else
		{
			std::cout << ch;
			cout.put(tolower(ch)); //save the lower case into file_2
			cin.get(ch); //read the next character
		}


	}

	/* Close the file stream object */
	cout.close();
	cin.close();
	std::cout << "Process completed.\n";

	return 0;


}

}

8. Array/file functions
{

#include <iostream>
#include <fstream>

void array_to_file(std::string path, int *num, int size);
void file_to_array(std::string path, int *num, int size);

const int SIZE = 10;
int main()
{
	int array1[SIZE] = { 1,2,3,4,5,6,7,8,9,0 };
	int array2[SIZE];
	
	std::string path = "D:\\P8.txt";
	
	/* Call array_to_file function to save array1 into file */
	array_to_file(path, array1, SIZE);
	
	/* Call file_to_array function to read data in file to array2 */
	file_to_array(path, array2, SIZE);
	
	/* Display array2 */
	for (int i=0; i<SIZE; i++)
		std::cout << array2[i] << "\n";
	
	return 0;
}

void array_to_file(std::string path, int *num, int size)
{
	/* Define a file stream object, open the file, write contents in array, then close the file */
	std::fstream file(path, std::ios::out | std::ios::binary); //create file stream object	
	for (int i=0; i<size; i++)
		file.write(reinterpret_cast<char *>(&num[i]), sizeof(num)); //write the whole array into the file
	file.close(); //close the file 
}
void file_to_array(std::string path, int *num, int size)
{
	/* Define a file stream object, open the file, read contents in array, then close the file */
	std::fstream file(path, std::ios::in | std::ios::binary); //create file stream object	
	for (int i=0; i<size; i++)
		file.read(reinterpret_cast<char *>(&num[i]), sizeof(num)); //write the whole array into the file
	file.close(); //close the file 	
}


}

9. 10. File encryption/decryption filter (gain: "\\" is considered \, one character, not two)
{

#include <iostream>
#include <fstream>
#include <string>

void encrypt(std::string path);
void display(std::string path);
void decrypt(std::string path);

int main()
{
	/* Define the file path */
	std::string path = "D:\\P9.txt";

	/* Pass the path of file to encrypt function, creating an encrypted file */
	encrypt(path);

	/* Display encrypted file */
	std::cout << "The original file is:\n";
	display(path);
	std::cout << "The encrypted file is:\n";
	display("D:\\P9_encrypted.txt");

	/* Decrypt the file */
	decrypt("D:\\P9_encrypted.txt");

	/* Display decrypted file */
	std::cout << "The decrypted file is:\n";
	display("D:\\P9_decrypted.txt");

	return 0;
}

void encrypt(std::string path)
{
	/* define file stream object and write data */
	std::ifstream cin(path); //define a file stream object: read
	path.erase(5, 4); //erase .txt
	path += "_encrypted.txt"; //add suffix to path

	std::ofstream cout(path); //define a file stream object: write 
	char ch; //to hold character read from original file
	while (cin.get(ch))
		cout.put(static_cast<char>(ch + 10)); //transfer encrypted info to file

	/* close the file */
	cin.close();
	cout.close();
}

void display(std::string path)
{
	//std::string line;
	char ch;
	std::ifstream cin(path);

	while (cin.get(ch))
		std::cout << ch;

	std::cout << "\n";

	cin.close();
}

void decrypt(std::string path)
{
	/* define file stream object and write data */
	std::ifstream cin(path); //define a file stream object: read
	path.erase(5, 14); //erase redundant data 
	path += "_decrypted.txt"; //add suffix to path

	std::ofstream cout(path); //define a file stream object: write 
	char ch; //to hold character read from original file
	while (cin.get(ch))
		cout.put(static_cast<char>(ch - 10)); //transfer encrypted info to file

											  /* close the file */
	cin.close();
	cout.close();
}

}

11. 12. Corporate sales data output and input
{

1) Trial: the data in structured variable is stored in vicinity
{

#include <iostream>

struct Data
{
	int num1;
	int num2;
};

int main()
{
	Data data = { 1, 2 };
	int *ptr = &data.num1;

	std::cout << "num1 = " << *ptr << "\n";
	ptr++;
	std::cout << "num2 = " << *ptr << "\n";

	return 0;
}

}

2) Code
{

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

const int SIZE = 5;

//hold sale data for one division, one quarter
struct Sale_data
{
	char division[SIZE]; //hold the division name
	int quarter; //hold the quarter number 
	double sale; //the sale number for the division at this quarter
};

//hold the result of a complete sales report
struct Sale_report
{
	double total_qsale_1; //total corporate sales for quarter 1
	double total_qsale_2; //total corporate sales for quarter 2
	double total_qsale_3; //total corporate sales for quarter 3
	double total_qsale_4; //total corporate sales for quarter 4
	int high_quarter; //highest quarter
	int low_quarter; //lowest quarter
	double high_qsale; //highest quarters for the corporation
	double low_qsale; //lowest quarters for the corporation

	double year_sale_E; //year sale for division East
	double year_sale_W; //year sale for division West
	double year_sale_N; //year sale for division North
	double year_sale_S; //year sale for division South

	double avgq_sale_E; //average quarterly sale for division East, year_sale_E/4
	double avgq_sale_W; //average quarterly sale for division West, year_sale_W/4
	double avgq_sale_N; //average quarterly sale for division North, year_sale_N/4
	double avgq_sale_S; //average quarterly sale for division South, year_sale_S/4

	double year_sale; //year sale for corporate (all yearly division sales combined)
};

void get_data(std::fstream &file);
void strcpy2(char *destination, const char *source);
Sale_report analyze(std::fstream &file);
void display(const Sale_report &report);

int main()
{
	/* Define a file stream object and create a data file, then close it and open it again in both read and write mode */
	std::ofstream create("D:\\P11_sale_file.dat"); //create the file
	create.close();
	std::fstream file("D:\\P11_sale_file.dat", std::ios::out | std::ios::in | std::ios::binary); //open it in in|out|binary mode

	/* call get_data function to write in data */
	get_data(file);		

	/* Define a Sale_report variable, use analyze() function to analyze the data */
	Sale_report report;
	//file.close(); //save the file 
	//file.open("D:\\P11_sale_file.dat", std::ios::in | std::ios::binary); //re-open the file
	report = analyze(file);

	/* Display the report */
	std::cout << report.avgq_sale_E << "\n";
	display(report);

	file.close();
	return 0;

}

//getting sales data 
void get_data(std::fstream &file)
{
	for (int division = 1; division <= 4; division++) //four division: East, West, North, South
	{
		for (int quarter = 1; quarter <= 4; quarter++) //four quarter
		{
			std::string div_name; //to hold the name of division
			switch (division) //assign division name according to different division number
			{
			case 1: div_name = "East"; break;
			case 2: div_name = "West"; break;
			case 3: div_name = "North"; break;
			case 4: div_name = "South"; break;
			}

			/* Save division name */
			Sale_data sale_figure; //define a Sale_data structure variable
			strcpy2(sale_figure.division, div_name.c_str()); //copy division name to the structure variable

															 /* Save quarter number */
			sale_figure.quarter = quarter;

			/* Ask for sale figure for this division and quarter */
			std::cout << "What is the sales figure for division " << div_name << " in quarter " << quarter << ": ";
			std::cin >> sale_figure.sale;

			/* store the structure variable into the file */
			file.write(reinterpret_cast<char *>(&sale_figure), sizeof(sale_figure));
		}
	}
}

//string copy function
void strcpy2(char *destination, const char *source)
{
	int i = 0;
	while (source[i] != '\0')
		destination[i] = source[i++];
	destination[i] = '\0';
}

//analyze the data
Sale_report analyze(std::fstream &file)
{


	/* Define a Sale_report variable to hold report, initialize with 0 */
	Sale_report report = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };

	/* Rewind file stream object */
	file.clear();
	file.seekg(0, std::ios::beg);

	/* Step through the data file, deal with every record, save data to corresponding slot in report */
	Sale_data record; //to hold data read from the file
	file.read(reinterpret_cast<char *>(&record), sizeof(record)); //read the first record 

	while (!file.eof()) //while the file has not come to an end
	{
		switch (record.division[0]) //the first character in division can give info of division
		{
		case 'E':
			switch (record.quarter) //quarter info
			{
			case 1:
				report.total_qsale_1 += record.sale; //add sale to total corporate sales
				report.year_sale_E += record.sale; //add sale to year sale for division
				break;
			case 2:
				report.total_qsale_2 += record.sale; //add sale to total corporate sales
				report.year_sale_E += record.sale; //add sale to year sale for division
				break;
			case 3:
				report.total_qsale_3 += record.sale; //add sale to total corporate sales
				report.year_sale_E += record.sale; //add sale to year sale for division
				break;
			case 4:
				report.total_qsale_4 += record.sale; //add sale to total corporate sales
				report.year_sale_E += record.sale; //add sale to year sale for division				
				break;
			}
			break;
		case 'W':
			switch (record.quarter) //quarter info
			{
			case 1:
				report.total_qsale_1 += record.sale; //add sale to total corporate sales
				report.year_sale_W += record.sale; //add sale to year sale for division
				break;
			case 2:
				report.total_qsale_2 += record.sale; //add sale to total corporate sales
				report.year_sale_W += record.sale; //add sale to year sale for division
				break;
			case 3:
				report.total_qsale_3 += record.sale; //add sale to total corporate sales
				report.year_sale_W += record.sale; //add sale to year sale for division
				break;
			case 4:
				report.total_qsale_4 += record.sale; //add sale to total corporate sales
				report.year_sale_W += record.sale; //add sale to year sale for division	
				break;
			}
			break;
		case 'N':
			switch (record.quarter) //quarter info
			{
			case 1:
				report.total_qsale_1 += record.sale; //add sale to total corporate sales
				report.year_sale_N += record.sale; //add sale to year sale for division
				break;
			case 2:
				report.total_qsale_2 += record.sale; //add sale to total corporate sales
				report.year_sale_N += record.sale; //add sale to year sale for division
				break;
			case 3:
				report.total_qsale_3 += record.sale; //add sale to total corporate sales
				report.year_sale_N += record.sale; //add sale to year sale for division
				break;
			case 4:
				report.total_qsale_4 += record.sale; //add sale to total corporate sales
				report.year_sale_N += record.sale; //add sale to year sale for division		
				break;
			}
			break;
		case 'S':
			switch (record.quarter) //quarter info
			{
			case 1:
				report.total_qsale_1 += record.sale; //add sale to total corporate sales
				report.year_sale_S += record.sale; //add sale to year sale for division
				break;
			case 2:
				report.total_qsale_2 += record.sale; //add sale to total corporate sales
				report.year_sale_S += record.sale; //add sale to year sale for division
				break;
			case 3:
				report.total_qsale_3 += record.sale; //add sale to total corporate sales
				report.year_sale_S += record.sale; //add sale to year sale for division
				break;
			case 4:
				report.total_qsale_4 += record.sale; //add sale to total corporate sales
				report.year_sale_S += record.sale; //add sale to year sale for division
				break;
			}
			break;
		}

		/* After saving info, read the next record */
		file.read(reinterpret_cast<char *>(&record), sizeof(record));
	}

	/* Create a double array, to store the total quarter sale for the corporation, this array will be used to find the highest and lowest quarter of the corporation */
	double qsale[4];
	double *ptr1 = &report.total_qsale_1; //create a pointer, point to total_qsale_1 in report
	for (int i = 0; i<4; i++, ptr1++) //update the pointer as well
	{
		qsale[i] = *ptr1;
	}

	//find out highest quarter
	double high_qsale = qsale[0];
	int high_quarter = 0;
	for (int i = 1; i<4; i++)
		if (high_qsale < qsale[i])
		{
			high_qsale = qsale[i];
			high_quarter = i;
		}
	report.high_quarter = high_quarter;
	report.high_qsale = high_qsale;

	//find out lowest quarter
	double low_qsale = qsale[0];
	int low_quarter = 0;
	for (int i = 1; i<4; i++)
		if (low_qsale > qsale[i])
		{
			low_qsale = qsale[i];
			low_quarter = i;
		}
	report.low_quarter = low_quarter;
	report.low_qsale = low_qsale;

	/* Calculate average quarterly sale for each division */
	ptr1 = &report.year_sale_E;
	double *ptr2 = &report.avgq_sale_E;
	for (int i = 0; i<4; i++, ptr1++, ptr2++)
		*ptr2 = *ptr1 / 4;

	/* Calculate year sale */
	ptr1 = &report.year_sale;
	ptr2 = &report.total_qsale_1;
	for (int i = 0; i<4; i++, ptr2++)
		*ptr1 += *ptr2;

	/* Calculation complete, return the report variable */
	return report;


}

//display the report data 
void display(const Sale_report &report)
{
	/* Set display format */
	std::cout << std::setprecision(2) << std::fixed;

	/* Display total corporate sale for each quarter */
	const double *ptr = &report.total_qsale_1;
	for (int i = 0; i<4; i++, ptr++)
	{
		std::cout << "Total corporate sale for quarter " << i + 1 << ": $" << *ptr << "\n";
	}

	/* Display high and low quarter */
	std::cout << "Quarter " << report.high_quarter + 1 << " has highest sale: $" << report.high_qsale << "\n";
	std::cout << "Quarter " << report.low_quarter + 1 << " has lowest sale: $" << report.low_qsale << "\n";

	/* Display year sale for each division */
	ptr = &report.year_sale_E;
	for (int i = 0; i<4; i++, ptr++)
	{
		std::cout << "\nYearly sale for ";
		switch (i)
		{
		case 0: std::cout << "East division: $" << *ptr << "\n"; break;
		case 1: std::cout << "West division: $" << *ptr << "\n"; break;
		case 2: std::cout << "North division: $" << *ptr << "\n"; break;
		case 3: std::cout << "South division: $" << *ptr << "\n"; break;
		}
	}

	/* Display average quarterly sale for each division */
	ptr = &report.avgq_sale_E;
	for (int i = 0; i<4; i++, ptr++)
	{
		std::cout << "\nAverage quarterly sale for ";
		switch (i)
		{
		case 0: std::cout << "East division: $" << *ptr << "\n"; break;
		case 1: std::cout << "West division: $" << *ptr << "\n"; break;
		case 2: std::cout << "North division: $" << *ptr << "\n"; break;
		case 3: std::cout << "South division: $" << *ptr << "\n"; break;
		}
	}

	/* Display total year sale for the corporation */
	std::cout << "Yearly sale for the corporation: $" << report.year_sale << "\n";

}



}

}

13. 14. Inventory program (date check, date print function added)
{

#include <iostream>
#include <fstream>
#include <cstring>
#include <cctype>

const int DESCRIPTION = 101;
const int DATE_NUM = 11;

struct Inventory_item
{
	char descript[DESCRIPTION];
	int stock;
	double cost_wholesale;
	double cost_retail;
	char date[DATE_NUM];
};

void process_database(std::fstream &file);
void display_menu(char &choice);
void add_record(std::fstream &file);
bool date_check(char *date);
void display(const Inventory_item &record);
void display_record(std::fstream &file);
void display_record_after_date(std::fstream &file);
void modify_record(std::fstream &file);
void show_summary(std::fstream &file);
int date_ch_to_int(char *date_ch);

int main()
{
	/* Define a file stream object, open the file in out|in|binary mode */
	std::fstream file;
	//check if "D:\\P13-database.dat" exist, if not, create one
	file.open("D:\\P13-database.dat", std::ios::in);
	if (file.fail()) //file doesn't exist, should create one
	{
		file.close();
		file.open("D:\\P13-database.dat", std::ios::out);
		file.close();
	}
	//open the file with in|out|binary mode
	file.open("D:\\P13-database.dat", std::ios::out | std::ios::in | std::ios::binary);

	/* Call process_database function to manage the database, including add/display/modify/analyze record in data base */
	process_database(file);
	
	file.close();
	
	return 0;


}

void process_database(std::fstream &file)
{
	char choice; //hold the user's choice
	do
	{
		display_menu(choice); //display menu and get user's choice

		switch (choice)
		{
		case '1': //add record to file
			add_record(file); break;
		case '2': //display record
			display_record(file); break;
		case '3': //modify record (including previous record)
			modify_record(file); break;
		case '4': //show summary
			show_summary(file); break;
		case '5': //show record added after a certain date
			display_record_after_date(file);
		case '6':
			break;
		}
	} while (choice != '6');
	
	std::cout << "Quit successfully.\n";
	
}

void display_menu(char &choice)
{
	std::cout << "Welcome to inventory editing program, please select one term below:\n";
	std::cout << "1) Add new records to the database\n"
		<< "2) Display records in database\n"
		<< "3) Modify records in database\n"
		<< "4) Vieww database summary\n"
		<< "5) Display records added after a certain date\n"
		<< "6) Quit\n";
	std::cin >> choice;
	while (choice < 49 || choice > 54)
	{
		std::cout << "Please input 1 ~ 6: ";
		std::cin >> choice;
	}
	std::cin.ignore(); //skip '\n'

}

//add one record to the file
void add_record(std::fstream &file)
{
	/* Move the file stream object to the end of the file to add new record */
	file.clear(); //clear for potential corruption
	file.seekp(0, std::ios::end);

	/* Input record data */
	Inventory_item record; //define a container to hold record data 
						   //description
	std::cout << "Please enter item description (maximum character: 100): ";
	std::cin.getline(record.descript, DESCRIPTION);
	//date added to inventory
	std::cout << "Please enter date added to inventory (in mm/dd/yyyy format): ";
	std::cin.getline(record.date, DATE_NUM);
	while (!date_check(record.date)) //while date format has not met the requirement
	{
		std::cout << "Invalid date format, please input the date again in mm/dd/yyyy format: ";
		std::cin.getline(record.date, DATE_NUM);
	}

	//stock number 
	std::cout << "Please input stock number: ";
	std::cin >> record.stock;
	while (record.stock < 0)
	{
		std::cout << "Invalid input, please input number greater than zero: ";
		std::cin >> record.stock;
	}
	//wholesale cost
	std::cout << "Please input wholesale cost: ";
	std::cin >> record.cost_wholesale;
	while (record.cost_wholesale < 0)
	{
		std::cout << "Invalid input, please input number greater than zero: ";
		std::cin >> record.cost_wholesale;
	}
	//retail cost
	std::cout << "Please input retail cost: ";
	std::cin >> record.cost_retail;
	while (record.cost_retail < 0)
	{
		std::cout << "Invalid input, please input number greater than zero: ";
		std::cin >> record.cost_retail;
	}
	//skip '\n'
	std::cin.ignore();

	/* Save this record to file and clear file stream object */
	file.write(reinterpret_cast<char *>(&record), sizeof(record));

	/* Press enter to continue */
	std::cout << "Add item complete, press enter to continue...";
	std::cin.get();
	std::cout << "\n\n";
}

//date check program, check the inputed date format
// This function check the validity of a date in the format of mm/dd/yyyy
// The argument is an char array, stored with the date to be checked
// It will perform following check:
// 1) Big or small month days number (Big: 1~31; Small: 1~30)
// 2) Month number (1~12)
// 3) Day number in Feburary (leap year: 29; normal year: 28)

bool date_check(char *date)
{
	/* Check if the date array has 10 characters */
	if (strlen(date) != 10)
		return 0;

	/* Check if the third, sixth element is '/' */
	if (date[2] != '/' && date[5] != '/')
		return 0;

	/* Extract month, days and years */
	char month_ch[2] = { date[0], date[1] };
	char day_ch[2] = { date[3], date[4] };
	char year_ch[4] = { date[6], date[7], date[8], date[9] };
	int month = atoi(month_ch);
	int day = atoi(day_ch);
	int year = atoi(year_ch);

	/*
	Check month, day and year:
	1) check month: within 1~12;
	2) month 1, 3, 5, 7, 8, 10, 12 should have days between 1~31;
	3) month 4, 6, 9, 11 should have days between 1~30;
	4) month 2: check year. If its a leap year, day should between 1~29, otherwise 1~28;
	*/
	switch (month)
	{
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:
		if (day < 1 || day > 31)
			return 0;
		else
			return 1;
		break;
	case 4:
	case 6:
	case 9:
	case 11:
		if (day < 1 || day > 30)
			return 0;
		else
			return 1;
		break;
	case 2:
		//check the year is leap year or not
		bool leap_year; //hold wether the year is leap year
		if (year % 4 != 0)
			leap_year = false;
		else if (year % 100 != 0)
			leap_year = true;
		else if (year % 400 != 0)
			leap_year = false;
		else
			leap_year = true;

		//check number of days in Feburary
		if (leap_year)
		{
			if (day < 1 || day > 29)
				return 0;			
		}

		else
			if (day < 1 || day > 28)
				return 0;

		return 1;
	}


}

//display function: display a single record, this function is called by display_record function 
void display(const Inventory_item &record)
{
	std::cout << "Description: " << record.descript << "\n"
		<< "Stock number: " << record.stock << "\n"
		<< "Wholesale cost: $" << record.cost_wholesale << "\n"
		<< "Retail cost: $" << record.cost_retail << "\n"
		<< "Date added to inventory: " << record.date << "\n";
}

//display certain record (ask for record #, if # is -1, display all)
void display_record(std::fstream &file)
{
	std::cout << "\n\n";
	/* Calculate current number of records */
	int file_size;
	int record_size = sizeof(Inventory_item);
	int record_num;
	file.clear();
	file.seekg(0, std::ios::end);
	file_size = file.tellg();
	record_num = file_size / record_size;

	/* Show sub-menu and get input */
	std::cout << "Please input record number from 1 to "
		<< record_num << ", input -1 to show all records: ";
	int display_num;
	std::cin >> display_num;
	while (!(display_num == -1 || (display_num <= record_num && display_num > 0)))
	{
		std::cout << "Invalid input, please input record number from 1 to "
			<< record_num << ", input -1 to show all records: ";
		std::cin >> display_num;
	}
	std::cin.ignore(); //skip '\n'

					   /* Display records based on input */
	Inventory_item record; //hold data read from file 
	switch (display_num)
	{
	case -1: //display all records
		file.clear();
		file.seekg(0, std::ios::beg); //move to beginning
		for (int i = 0; i<record_num; i++)
		{
			file.read(reinterpret_cast<char *>(&record), sizeof(record)); //read to record
			std::cout << "\nRecord #" << i + 1 << "\n";
			display(record);
		}
		std::cout << "\n\n";
		break;
	default: //display specific record
		file.clear();
		file.seekg((display_num - 1) * sizeof(record), std::ios::beg); //move to the record 
		file.read(reinterpret_cast<char *>(&record), sizeof(record));
		std::cout << "\nRecord #" << display_num << "\n";
		display(record);
		std::cout << "\n\n";
		break;
	}

	/* Press enter to continue */
	std::cout << "Display complete, press enter to continue...";
	std::cin.get();
	std::cout << "\n\n";

}

//modify record (ask for inputting record #)
void modify_record(std::fstream &file)
{
	/* Calculate current number of records */
	int file_size;
	int record_size = sizeof(Inventory_item);
	int record_num;
	file.clear();
	file.seekg(0, std::ios::end);
	file_size = file.tellg();
	record_num = file_size / record_size;

	/* Show sub-menu and get input */
	std::cout << "Please input record number from 1 to "
		<< record_num << ": ";
	int modify_num;
	std::cin >> modify_num;
	while (!(modify_num <= record_num && modify_num > 0))
	{
		std::cout << "Invalid input, please input record number from 1 to "
			<< record_num << ": ";
		std::cin >> modify_num;
	}
	std::cin.ignore(); //skip '\n'

	 /* Define a container to hold modify value temporarily, prompt user to input modified data */
	Inventory_item record;
	//description
	std::cout << "Please enter item description (maximum character: 100): ";
	std::cin.getline(record.descript, DESCRIPTION);
	//date added to inventory
	std::cout << "Please enter date added to inventory (in mm/dd/yyyy format): ";
	std::cin.getline(record.date, DATE_NUM);
	while (!date_check(record.date)) //while date format has not met the requirement
	{
		std::cout << "Invalid date format, please input the date again in mm/dd/yyyy format: ";
		std::cin.getline(record.date, DATE_NUM);
	}
	//stock number 
	std::cout << "Please input stock number: ";
	std::cin >> record.stock;
	while (record.stock < 0)
	{
		std::cout << "Invalid input, please input number greater than zero: ";
		std::cin >> record.stock;
	}
	//wholesale cost
	std::cout << "Please input wholesale cost: ";
	std::cin >> record.cost_wholesale;
	while (record.cost_wholesale < 0)
	{
		std::cout << "Invalid input, please input number greater than zero: ";
		std::cin >> record.cost_wholesale;
	}
	//retail cost
	std::cout << "Please input retail cost: ";
	std::cin >> record.cost_retail;
	while (record.cost_retail < 0)
	{
		std::cout << "Invalid input, please input number greater than zero: ";
		std::cin >> record.cost_retail;
	}
	//skip '\n'
	std::cin.ignore();

	/* Move the file stream object to the target position and write in data */
	file.seekp((modify_num - 1) * sizeof(record), std::ios::beg);
	file.write(reinterpret_cast<char *>(&record), sizeof(record));

	/* Press enter to continue */
	std::cout << "Modify complete, press enter to continue...";
	std::cin.get();
	std::cout << "\n\n";
}

//show: 1) total whole sale value; 2) total retail value; 3) total quantity of all items
void show_summary(std::fstream &file)
{
	/* Define container for holding 1) total whole sale value; 2) total retail value; 3) total quantity of all items */
	double total_wholesale = 0, total_retail = 0;
	int total_quantity = 0;
	
	/* Rewind file stream object, go over the file to calculate the result */
	file.clear();
	file.seekg(0, std::ios::beg);
	Inventory_item record; //hold data read from file
	
	file.read(reinterpret_cast<char *>(&record), sizeof(record)); //read the first record	
	while (!file.eof()) //while file end is not met
	{
		//update result
		total_quantity += record.stock;
		total_wholesale += record.stock * record.cost_wholesale;
		total_retail += record.stock * record.cost_retail;
		
		//read the next record
		file.read(reinterpret_cast<char *>(&record), sizeof(record));
	}
	
	/* Display result */
	std::cout << "\n\nTotal wholesale value: $" << total_wholesale << "\n"
	<< "Total retail value: $" << total_retail << "\n"
	<< "Total quantity: " << total_quantity << "\n\n";
	
}

//display record after inputed date
void display_record_after_date(std::fstream &file)
{
	/* Input the date */
	std::cout << "Please input a date in mm/dd/yyyy format, the program will display records that are added on and after this date: ";
	char date_display[DATE_NUM];
	std::cin.getline(date_display, DATE_NUM);
	while (!date_check(date_display)) //while date format has not met the requirement
	{
		std::cout << "Invalid date format, please input the date again in mm/dd/yyyy format: ";
		std::cin.getline(date_display, DATE_NUM);
	}
	int date_display_int = date_ch_to_int(date_display);

	/* Rewind the file stream object, display any record that are added on or after this date */
	file.clear();
	file.seekg(0, std::ios::beg);
	Inventory_item record;
	
	file.read(reinterpret_cast<char *>(&record), sizeof(record));
	int record_counter = 1; //hold the record number
	while (!file.eof())
	{
		if (date_ch_to_int(record.date) >= date_display_int) //meet the requirement
		{
			std::cout << "\nRecord #" << record_counter << "\n";
			display(record);
		}
		
		file.read(reinterpret_cast<char *>(&record), sizeof(record)); //read the next record
		record_counter++; //update the record number
	}
	
	/* Press enter to continue */
	std::cout << "Display complete, press enter to continue...";
	std::cin.get();
	std::cout << "\n\n";	
}

// transform the date stored in char array into integer for easier compariance. For example:
// input: 02/05/1998; output: 19980502
int date_ch_to_int(char *date_ch)
{
	/* Extract month, days and years */
	char month_ch[2] = { date_ch[0], date_ch[1] };
	char day_ch[2] = { date_ch[3], date_ch[4] };
	char year_ch[4] = { date_ch[6], date_ch[7], date_ch[8], date_ch[9] };
	int month = atoi(month_ch);
	int day = atoi(day_ch);
	int year = atoi(year_ch);
	
	/* Calculate the corresponding integer */
	return year*10000 + month*100 + day;
}

}

15. Average number of words
{

#include <iostream>
#include <fstream>
#include <string>

int main()
{
	/* Define a container to hold data read from the file, and the file stream object */
	std::string line; //hold data read from the file
	std::fstream file;
	file.open("D:\\text2.txt", std::ios::in);

	/* Go over the file, calculate the number of words and sentences */
	int num_word = 0; //hold the number of words
	int num_sentence = 0; //hold the number of sentences
	while (getline(file, line))
	{
		num_sentence++; //ipdate sentence number
						//go over the string, find out all the space
		int num_space = 0;
		for (int i = 0; i<line.size(); i++)
		{
			if (line[i] == ' ')
				num_space++;
		}
		//number of words is number of spaces + 1
		num_word += num_space + 1;
	}

	/* Calculate the average number of words per sentence */
	double average_word = num_word / num_sentence;

	/* Display result */
	std::cout << "The average words per sentence is: " << average_word << "\n";

	return 0;
}

}

16. Group Project: Customer Accounts++
{

#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <fstream>
#include <iomanip>
#include <ctime>
#include <cctype>

/* Named Constant */
const int NAME_SIZE = 51;
const int ADDRESS_SIZE = 101;
const int CITY_ZIP_SIZE = 101;
const int PHONE_SIZE = 20;
const int DATE_SIZE = 11;
const int KEYWORD_SIZE = 101;

/* Structure Declaration */
struct Account
{
	bool is_delete; //to hold wether this record has been deleted or not
	int account_number; //account number for each account.
	char name[NAME_SIZE]; //name of account holder
	char address[ADDRESS_SIZE]; //address
	char city_zip[CITY_ZIP_SIZE]; //city, state and zip
	char phone[PHONE_SIZE]; //phone number
	char date[DATE_SIZE]; //last day of payment
	double balance; //account balance
};

/* Function Prototype */
int database_size(std::fstream &file, std::vector<int> deleted_position);
void fill_deleted_position(std::fstream &file, std::vector<int> &deleted_position);
void show_menu(char &choice, int num_record);
void add_account(std::fstream &file, std::vector<int> &deleted_position);
void record_input(Account &record);
bool date_check(char *date);
void display(const Account &record);
int search(std::fstream &file);
void display_account(std::fstream &file);
void delete_account(std::fstream &file, std::vector<int> &deleted_position);
void modify_account(std::fstream &file);
int date_ch_to_int(char *date_ch);
void display_overdue(std::fstream &file);
void clear_deleted(std::fstream &file, std::vector<int> &deleted_position);

int main()
{
	///* Define a File Stream Object, Open the File in out|in|binary Mode */
	std::fstream file;
	////check if "D:\\customer account database.dat" exist, if not, create one
	//file.open("D:\\customer account database.dat", std::ios::in);
	//if (file.fail()) //file doesn't exist, should create one
	//{
	//	file.close();
	//	file.open("D:\\customer account database.dat", std::ios::out);
	//	file.close();
	//}
	//open the file with in|out|binary mode
	file.open("D:\\customer account database.dat", std::ios::out | std::ios::in | std::ios::binary);

	/* Define a Vector of Integer, to Store the Position of Deleted record */
	std::vector<int> deleted_position;
	//call fill_deleted_position() to go over the database and load deleted position into this vector
	fill_deleted_position(file, deleted_position);

	/* Show menu and ask user to choose one term */
	char choice; //hold user's choice
	do
	{
		show_menu(choice, database_size(file, deleted_position));
		switch (choice)
		{
		case '1': //add account
			add_account(file, deleted_position);
			break;
		case '2': //display account
			display_account(file);
			break;
		case '3': //delete account
			delete_account(file, deleted_position);
			break;
		case '4': //modify account
			modify_account(file);
			break;
		case '5': //display overdue account
			display_overdue(file);
			break;
		case '6': //clear deleted account
			clear_deleted(file, deleted_position);
			break;
		case '7':
			break;
		}
	} while (choice != '7');

	std::cout << "Thanks for using account management program!\n";

	return 0;
}

//database_size function. Can return the number of un-deleted records in the file
int database_size(std::fstream &file, std::vector<int> deleted_position)
{
	//rewind the file stream object
	file.clear();
	file.seekg(0, std::ios::end);

	//define container 
	int size_file = file.tellg();
	int size_record = sizeof(Account);
	int num_deleted = deleted_position.size();

	return size_file / size_record - num_deleted;
}

//show menu function
void show_menu(char &choice, int num_record)
{
	std::cout << "\nCustomer Accounts Management System\n"
		<< "Current record in database: " << num_record << "\n"
		<< "1) Add new customer account\n"
		<< "2) Display account\n"
		<< "3) Delete account\n"
		<< "4) Modify account\n"
		<< "5) Display overdue account\n"
		<< "6) Clear all deleted account\n"
		<< "7) Quit\n";

	std::cin >> choice;
	while (choice < 49 || choice > 55)
	{
		std::cout << "Please input 1 ~ 7: ";
		std::cin >> choice;
	}
	std::cin.ignore(); //skip '\n'
}

//account add function. Add record into the file. Will first add to deleted slot. If no deleted slot, add to the end of the file
void add_account(std::fstream &file, std::vector<int> &deleted_position)
{
	Account record; //define a container to hold account info, will be saved to file after inputing information
	record.is_delete = false; //set delete flag to false

							  /* Assign account number */
							  //account number is assigned to every newly created account automatically
	int account_number = time(0) - 555555555555; //initialize account number
	record.account_number = account_number;

	/* Call record_input function to get remaining information */
	record_input(record);

	/* Save record to file */
	//if deleted_position is empty, save to the last position in file 
	//else, save to the position stored in the last element of deleted_position[], and pop_back
	if (deleted_position.size() == 0)
	{

		//rewind the file stream object, move to the end of the file
		file.clear();
		file.seekp(0, std::ios::end);
		//save record to file
		file.write(reinterpret_cast<char *>(&record), sizeof(record));
	}
	else
	{
		//rewind the file, move to the position stored in the last element of deleted_position
		file.clear();
		int position = deleted_position[deleted_position.size() - 1];
		file.seekp(position * sizeof(record), std::ios::beg);
		//save record to file (actually overwrite previous deleted data)
		file.write(reinterpret_cast<char *>(&record), sizeof(record));
		//delete the last element in deleted_position[], because it is already used above
		deleted_position.pop_back();
	}


	/* Press enter to continue */
	std::cout << "Account add successfully, please press enter to continue...";
	std::cin.get();

}

//record_input function. Called by add_account() and modify_account(), will prompt user to input information of an account. 
void record_input(Account &record)
{
	/* Input info */
	std::cout << "Please input following account information\n";
	//name
	std::cout << "Name: ";
	std::cin.getline(record.name, NAME_SIZE);
	//address
	std::cout << "Address: ";
	std::cin.getline(record.address, ADDRESS_SIZE);
	//city, state & zip
	std::cout << "City, state and zip code: ";
	std::cin.getline(record.city_zip, CITY_ZIP_SIZE);
	//phone
	std::cout << "Phone number: ";
	std::cin.getline(record.phone, PHONE_SIZE);
	//last day of payment & date check
	std::cout << "Date of last payment (format: mm/dd/yyyy):  ";
	std::cin.getline(record.date, DATE_SIZE);
	while (!date_check(record.date)) //while date format has not met the requirement
	{
		std::cout << "Invalid date format, please input the date again in mm/dd/yyyy format: ";
		std::cin.getline(record.date, DATE_SIZE);
	}
	//balance
	std::cout << "Account balance: ";
	std::cin >> record.balance;
	std::cin.ignore(); //skip '\n'

}

//date format check function
bool date_check(char *date)
{
	/* Check if the date array has 10 characters */
	if (strlen(date) != 10)
		return 0;

	/* Check if the third, sixth element is '/' */
	if (date[2] != '/' && date[5] != '/')
		return 0;

	/* Extract month, days and years */
	char month_ch[2] = { date[0], date[1] };
	char day_ch[2] = { date[3], date[4] };
	char year_ch[4] = { date[6], date[7], date[8], date[9] };
	int month = atoi(month_ch);
	int day = atoi(day_ch);
	int year = atoi(year_ch);

	/*
	Check month, day and year:
	1) check month: within 1~12;
	2) month 1, 3, 5, 7, 8, 10, 12 should have days between 1~31;
	3) month 4, 6, 9, 11 should have days between 1~30;
	4) month 2: check year. If its a leap year, day should between 1~29, otherwise 1~28;
	*/
	
	if (month > 12 || month < 1)
		return 0;
	
	switch (month)
	{
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:
		if (day < 1 || day > 31)
			return 0;
		else
			return 1;
		break;
	case 4:
	case 6:
	case 9:
	case 11:
		if (day < 1 || day > 30)
			return 0;
		else
			return 1;
		break;
	case 2:
		//check the year is leap year or not
		bool leap_year; //hold wether the year is leap year
		if (year % 4 != 0)
			leap_year = false;
		else if (year % 100 != 0)
			leap_year = true;
		else if (year % 400 != 0)
			leap_year = false;
		else
			leap_year = true;

		//check number of days in Feburary
		if (leap_year)
		{
			if (day < 1 || day > 29)
				return 0;
		}

		else
			if (day < 1 || day > 28)
				return 0;

		return 1;
	}


}

//display function, will display the record of a single account
void display(const Account &record)
{
	std::cout << std::setprecision(2) << std::fixed;
	std::cout << "Account number: " << record.account_number << "\n";
	std::cout << "Name: " << record.name << "\n";
	std::cout << "Address: " << record.address << "\n";
	std::cout << "City, state and zip code: " << record.city_zip << "\n";
	std::cout << "Phone: " << record.phone << "\n";
	std::cout << "Date of last payment: " << record.date << "\n";
	std::cout << "Account balance: $" << record.balance << "\n";
}

// search function, will return the position of specific record (position in file). Ignore deleted file
int search(std::fstream &file)
{
	// work load description: write a search function

	// 1. ask keyword type:
	// 1) account number
	// 2) name
	// 3) address 
	// 4) city, state, zip
	// 5) phone
	// 6) balance
	// 2. ask to input keyword
	// 3. find out all record that match, display, ignore deleted file
	// 4. ask user to pick one
	// 5. return the file position of this record

	/* Show menu, prompt user to input one type of key word to search */
	std::cout << "\nPlease select one type of keyword to search:\n"
		<< "1) Account number\n"
		<< "2) Name\n"
		<< "3) Address\n"
		<< "4) City, state and zip code\n"
		<< "5) Phone\n"
		<< "6) Date of last payment\n"
		<< "7) Balance\n";
	char selection; //hold choice, 1~6
	std::cin >> selection;
	while (selection < 49 || selection > 55)
	{
		std::cout << "Invalid input, please select from 1 ~ 6: ";
		std::cin >> selection;
	}
	std::cin.ignore(); //skip the '\n'

					   /* Input keyword */
	std::string keyword;
	std::cout << "Please input the keyword to search: ";
	getline(std::cin, keyword);

	/* Search the file, store the position of first matching record to a vector */
	std::vector<int> match_position; //to store the position of first general match
	Account record; //to hold record read from the file 
					//rewind file stream object
	file.clear();
	file.seekg(0, std::ios::beg);
	//read first record
	file.read(reinterpret_cast<char *>(&record), sizeof(record));
	//perform search based on selection, ignore deleted records, all match position will be stored in the match_position[] vector
	switch (selection)
	{
	case '1': //search account number
		while (!file.eof())
		{
			//if record is deleted, ignore
			if (record.is_delete == true)
			{
				file.read(reinterpret_cast<char *>(&record), sizeof(record)); //read next record
				continue; //begin next loop
			}

			// search for account number if there is any match of the keyword
			//transform the account number (integer) to string;
			std::string account_number_string = std::to_string(record.account_number);
			//search the account_number_string to see if there is any match of keyword
			if (account_number_string.find(keyword) != -1) //match found
			{
				int position = file.tellg() / sizeof(record) - 1; //unit of position is "record". For example, position = 3 means fourth record in the file
				match_position.push_back(position); //store the position in the vector
			}

			//read the next record
			file.read(reinterpret_cast<char *>(&record), sizeof(record));
		}
		break;

	case '2': //search name
		while (!file.eof())
		{
			if (record.is_delete == true)
			{
				file.read(reinterpret_cast<char *>(&record), sizeof(record));
				continue;
			}

			//transform the name to string;
			std::string name(record.name);
			//search the name string to see if there is any match of keyword
			if (name.find(keyword) != -1) //match found
			{
				int position = file.tellg() / sizeof(record) - 1;
				match_position.push_back(position); //store the position in the vector
			}

			//read the next record
			file.read(reinterpret_cast<char *>(&record), sizeof(record));
		}
		break;

	case '3': //search address
		while (!file.eof())
		{
			if (record.is_delete == true)
			{
				file.read(reinterpret_cast<char *>(&record), sizeof(record));
				continue;
			}

			//transform the address to string;
			std::string address(record.address);
			//search the address string to see if there is any match of keyword
			if (address.find(keyword) != -1) //match found
			{
				int position = file.tellg() / sizeof(record) - 1;
				match_position.push_back(position); //store the position in the vector			
			}

			//read the next record
			file.read(reinterpret_cast<char *>(&record), sizeof(record));
		}
		break;

	case '4': //search city, state, zip
		while (!file.eof())
		{
			if (record.is_delete == true)
			{
				file.read(reinterpret_cast<char *>(&record), sizeof(record));
				continue;
			}

			//transform the city_zip to string;
			std::string city_zip(record.city_zip);
			//search the city_zip string to see if there is any match of keyword
			if (city_zip.find(keyword) != -1) //match found
			{
				int position = file.tellg() / sizeof(record) - 1;
				match_position.push_back(position); //store the position in the vector				
			}

			//read the next record
			file.read(reinterpret_cast<char *>(&record), sizeof(record));
		}
		break;

	case '5': //search phone
		while (!file.eof())
		{
			if (record.is_delete == true)
			{
				file.read(reinterpret_cast<char *>(&record), sizeof(record));
				continue;
			}

			//transform the phone to string;
			std::string phone(record.phone);
			//search the phone string to see if there is any match of keyword
			if (phone.find(keyword) != -1) //match found
			{
				int position = file.tellg() / sizeof(record) - 1;
				match_position.push_back(position); //store the position in the vector			
			}

			//read the next record
			file.read(reinterpret_cast<char *>(&record), sizeof(record));
		}
		break;

	case '6': //search date of last payment 
		while (!file.eof())
		{
			if (record.is_delete == true)
			{
				file.read(reinterpret_cast<char *>(&record), sizeof(record));
				continue;
			}

			//transform the date to string;
			std::string date(record.date);
			//search the date string to see if there is any match of keyword
			if (date.find(keyword) != -1) //match found
			{
				int position = file.tellg() / sizeof(record) - 1;
				match_position.push_back(position); //store the position in the vector				
			}

			//read the next record
			file.read(reinterpret_cast<char *>(&record), sizeof(record));
		}
		break;

	case '7': //search balance
		while (!file.eof())
		{
			//if record is deleted, ignore
			if (record.is_delete == true)
			{
				file.read(reinterpret_cast<char *>(&record), sizeof(record)); //read next record
				continue; //begin next loop
			}

			// search for balance if there is any match of the keyword
			//transform the balance (double) to string;
			std::string balance_string = std::to_string(record.balance);
			//search the balance_string to see if there is any match of keyword
			if (balance_string.find(keyword) != -1) //match found
			{
				int position = file.tellg() / sizeof(record) - 1; //unit of position is "record". For example, position = 3 means fourth record in the file
				match_position.push_back(position); //store the position in the vector			
			}

			//read the next record
			file.read(reinterpret_cast<char *>(&record), sizeof(record));
		}
		break;
	}

	/* Display the first matching record and ask user pick one as final choice */
	std::cout << "\nSearch result:\n";
	if (match_position.size() == 0) //no match result, return -1
		return -1;
	else
	{
		//display match result 
		for (int i = 0; i<match_position.size(); i++)
		{
			std::cout << "\n\nResult " << i + 1 << "\n"; //match result #
														 //rewind file stream object
			file.clear();
			file.seekg(match_position[i] * sizeof(record), std::ios::beg);
			//read to record
			file.read(reinterpret_cast<char *>(&record), sizeof(record));
			//display record, only display the search type
			switch (selection)
			{
			case '1':
				std::cout << "Account number: " << record.account_number << "\n";
				break;
			case '2':
				std::cout << "Name: " << record.name << "\n";
				break;
			case '3':
				std::cout << "Address: " << record.address << "\n";
				break;
			case '4':
				std::cout << "City, state & zip code: " << record.city_zip << "\n";
				break;
			case '5':
				std::cout << "Phone: " << record.phone << "\n";
				break;
			case '6':
				std::cout << "Date of last payment: " << record.date << "\n";
				break;
			case '7':
				std::cout << "Account balance: " << record.balance << "\n";
				break;
			}
		}
	}

	//define a container to hold user's search_choice, ask for choice
	int search_choice;
	std::cout << "Please input the number of your desired result: ";
	std::cin >> search_choice;
	while (search_choice < 1 || search_choice > match_position.size())
	{
		std::cout << "Invalid input, please input again: ";
		std::cin >> search_choice;
	}
	std::cin.ignore(); //skip '\n'

					   //return the position (position's unit is record, if position == 3, that means the third record in file)
	return match_position[search_choice - 1];

}

// display_account function, can:
// 1) display a specific account searched by user
// 2) display entire database
// will ignore records that is_delete == true
void display_account(std::fstream &file)
{
	/* Display menu and make a choice */
	char choice_display; //hold choice
	std::cout << "Please select how you would display account:\n"
		<< "1) Display an account by searching keyword\n"
		<< "2) Display all account\n";
	std::cin >> choice_display;
	while (choice_display != '1' && choice_display != '2')
	{
		std::cout << "Please input 1 or 2: ";
		std::cin >> choice_display;
	}
	std::cin.ignore(); //skip '\n'

					   /* Perform different operations based on choice_display */
	Account record; //hold data read from file

					//choose 2 to display all accounts, ignore deleted account
	if (choice_display == '2')
	{
		int counter = 0;
		//rewind file streamer
		file.clear();
		file.seekg(0, std::ios::beg);
		//read first record
		file.read(reinterpret_cast<char *>(&record), sizeof(record));
		//use loop to go over all account
		while (!file.eof())
		{
			if (!record.is_delete) //if the record is not flagged deleted, display it
			{
				counter++; //found one non-deleted record, update the counter
				std::cout << "\n\nRecord " << counter << "\n";
				display(record);
			}

			//read next record
			file.read(reinterpret_cast<char *>(&record), sizeof(record));
		}

		//display complete, press enter to continue
		std::cout << "Display completed, please press enter to continue...";
		std::cin.get();

		return;
	}

	// choose 1 to display single record
	// call search function to locate the record position
	int display_position; //hold the position to display
	display_position = search(file);
	// if return -1, no record found, notify user and press enter to continue
	if (display_position == -1)
	{
		std::cout << "No record found, please press enter to continue...";
		std::cin.get();
	}
	else
	{
		// rewind file stream object
		file.clear();
		file.seekg(display_position * sizeof(record), std::ios::beg);
		//read and display the record
		file.read(reinterpret_cast<char *>(&record), sizeof(record));
		std::cout << "\n";
		display(record);

		//display complete, press enter to continue
		std::cout << "Display completed, please press enter to continue...";
		std::cin.get();
	}


}

// delete account function
/*
the function will delete an chosen account in the file. It's working process is:
1) ask the user to search an account to delete, call search function. Use an int variable to hold the returned position of files
2) access the corresponding account via file stream object and the position
3) set "is_delete" flag as true, this marks the account as deleted account
4) store the position in deleted_position[] vector, used for future adding account
5) notify the user deletion is complete, press enter to continue
*/
void delete_account(std::fstream &file, std::vector<int> &deleted_position)
{
	/* Define a variable to hold the delete_position, call search function to search */
	int position;
	std::cout << "You have to search for the account to delete.\n";
	position = search(file);

	//if not found, notify the user
	if (position == -1)
	{
		std::cout << "No record found, please press enter to continue...";
		std::cin.get();
	}

	else
	{
		/* Copy the record and display the account, ask for reassurement */
		Account record_delete;
		//move file stream object
		file.clear();
		file.seekp(position * sizeof(record_delete), std::ios::beg);
		file.read(reinterpret_cast<char *>(&record_delete), sizeof(record_delete));
		//ask for second assurement
		std::cout << "\nThe account you choose is:\n";
		display(record_delete);
		std::cout << "\nAre you sure you want to delete this account? (Y/N)";
		char choice_delete;
		std::cin >> choice_delete;
		while (toupper(choice_delete) != 'Y' && toupper(choice_delete) != 'N')
		{
			std::cout << "Invalid input, please input again (Y/N) ";
			std::cin >> choice_delete;
		}
		std::cin.ignore(); //skip the '\n'

		if (toupper(choice_delete) == 'N')
		{
			std::cout << "Press enter to go back to main menu...";
			std::cin.get();
			return;
		}

		/* Access the account, set is_delete to true */
		bool is_delete = true;
		file.clear();
		file.seekp(position * sizeof(record_delete), std::ios::beg);
		file.write(reinterpret_cast<char *>(&is_delete), sizeof(is_delete));

		/* Store the position into deleted_position[] vector, and notify user */
		deleted_position.push_back(position);
		std::cout << "Deletion complete, press enter to continue...";
		std::cin.get();
	}


}

//at startup, initialize deleted_position[] vector, fill it with deleted slot position information
void fill_deleted_position(std::fstream &file, std::vector<int> &deleted_position)
{
	/* If the file's size */
	//define the temporary container 
	Account record;
	int position;

	//read the first record
	file.clear();
	file.seekg(0, std::ios::beg);
	file.read(reinterpret_cast<char *>(&record), sizeof(record));

	while (!file.eof())
	{
		//save the position to deleted_position[] vector if it is deleted
		if (record.is_delete == true)
		{
			position = file.tellg() / sizeof(record) - 1;
			deleted_position.push_back(position);
		}

		//read next record
		file.read(reinterpret_cast<char *>(&record), sizeof(record));

	}
}

// modify the account
// 1) search specific record
// 2) ask for details of modification
// 3) save the record (overwrite)
void modify_account(std::fstream &file)
{
	/* Search record */
	std::cout << "You have to search a record to modify.\n";
	int position_modify;
	position_modify = search(file);

	// do nothing if result not found
	if (position_modify == -1)
	{
		std::cout << "No record found, please press enter to continue...";
		std::cin.get();
		return;
	}

	/* ask for details of modification */
	Account record;
	//copy the target record to this container
	file.clear();
	file.seekg(position_modify * sizeof(record), std::ios::beg);
	file.read(reinterpret_cast<char *>(&record), sizeof(record));
	//call record_input function to input modification	
	record_input(record);

	/* Save the record back to file */
	file.clear();
	file.seekp(position_modify * sizeof(record), std::ios::beg);
	file.write(reinterpret_cast<char *>(&record), sizeof(record));

	/* Press enter to continue */
	std::cout << "Modification complete, press enter to continue...";
	std::cin.get();

}

// transform the date stored in char array into integer for easier compariance. For example:
// input: 02/05/1998; output: 19980502
int date_ch_to_int(char *date_ch)
{
	/* Extract month, days and years */
	char month_ch[2] = { date_ch[0], date_ch[1] };
	char day_ch[2] = { date_ch[3], date_ch[4] };
	char year_ch[4] = { date_ch[6], date_ch[7], date_ch[8], date_ch[9] };
	int month = atoi(month_ch);
	int day = atoi(day_ch);
	int year = atoi(year_ch);

	/* Calculate the corresponding integer */
	return year * 10000 + month * 100 + day;
}

//display overdue account
//1) ask for the date to check
//2) transform the date to integer
//3) go over the file to find out the account that the last payment day is before this date, display the matched account
void display_overdue(std::fstream &file)
{
	/* Ask user to input date to check */
	std::cout << "Please input a date in mm/dd/yyyy format, the program will display all records that the last payment day is prior to the inputed date: ";
	char due_date_ch[DATE_SIZE];
	std::cin.getline(due_date_ch, DATE_SIZE);
	while (!date_check(due_date_ch))
	{
		std::cout << "Invalid date format, please input in mm/dd/yyyy: ";
		std::cin.getline(due_date_ch, DATE_SIZE);
	}

	int due_date = date_ch_to_int(due_date_ch); //transform to integer

												/* Rewind file stream object */
	file.clear();
	file.seekg(0, std::ios::beg);

	/* Go over the file, display account with last payment date before the input date */
	Account record;
	file.read(reinterpret_cast<char *>(&record), sizeof(record));
	int counter = 1;
	while (!file.eof())
	{
		if (date_ch_to_int(record.date) <= due_date)
		{
			std::cout << "\nRecord " << counter++ << ":\n";
			display(record);
		}
		//read the next record 
		file.read(reinterpret_cast<char *>(&record), sizeof(record));
	}
	std::cout << "\n";

}

// clear deleted account
// 1) go over the file, store every un-deleted file to a vector
// 2) disconnect the file stream object, open the file again in out|binary mode 
// 3) write content in the vector to the file
// 4) disconnect the file, then reopen it in out|in|binary mode
// 5) notify user of clearing complete
void clear_deleted(std::fstream &file, std::vector<int> &deleted_position)
{
	/* Define a temporary container to hold un-deleted data */
	std::vector <Account> accounts;

	/* Go over the file, save un-deleted record to the vector */
	//rewind file stream object
	file.clear();
	file.seekg(0, std::ios::beg);
	//define a container, and a counter for number of deleted accounts
	Account record;
	int counter = 0;
	//read first record 
	file.read(reinterpret_cast<char *>(&record), sizeof(record));
	//use loop to go over the file, save un-deleted record to the vector
	while (!file.eof())
	{
		if (record.is_delete == false)
			accounts.push_back(record);
		else
			counter++;
		//read next record
		file.read(reinterpret_cast<char *>(&record), sizeof(record));
	}

	/* close the file, reopen in out|binary mode, write in data */
	file.close();
	file.open("D:\\customer account database.dat", std::ios::out | std::ios::binary);
	for (int i = 0; i<accounts.size(); i++)
		file.write(reinterpret_cast<char *>(&accounts[i]), sizeof(accounts[i]));

	/* close the file, reopen it with out|in|binary mode, also clear deleted_position[] */
	file.close();
	file.open("D:\\customer account database.dat", std::ios::in | std::ios::out | std::ios::binary);
	deleted_position.clear();

	/* Press enter to continue */
	std::cout << "Process completed. " << counter << " deleted accounts are cleared, press enter tp continue...";
	std::cin.get();


}



}





/**********************************************************/
/** Patience and diligence, like faith, remove mountains **/
/**********************************************************/



