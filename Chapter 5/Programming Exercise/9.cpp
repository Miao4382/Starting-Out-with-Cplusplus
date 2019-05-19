//9. Hotel Occupancy
#include <iostream>
#include <fstream>
int main()
{
	//variable definition
	int room, room_total=0, floor, room_ocu, room_ocu_total=0;

	//create a file stream operator and link to the text file
	std::ofstream cout;
	cout.open("D:\\9.txt");

	//input floor, record in file
	std::cout << "How many floors in this hotel: ";
	std::cin >> floor;
	while (floor < 1)
	{
		std::wcout << "floor number must equal or greater than 1, please input again: ";
		std::wcin >> floor;
	}
	cout << "Total numbers of the floor: " << floor << std::endl;

	for (int i = 1; i <= floor; i++)
	{
		if (i == 13)
			continue;
		std::cout << "How many rooms in floor " << i << ": ";
		std::cin >> room;
		while (room < 10)
		{
			std::cout << "Room number should be equal or greater than 10, please input again: ";
			std::cin >> room;
		}
		room_total += room;
		std::cout << "How many rooms are occupied: ";
		std::cin >> room_ocu;
		room_ocu_total += room_ocu;
	}

	cout << "Total numbers of room: " << room_total << std::endl;
	cout << "Total number of occupied room: " << room_ocu_total << std::endl;
	cout << "Total number of unoccupied room: " << room_total - room_ocu_total << std::endl;
	cout << "Occupancy: " << static_cast<double>(room_ocu_total) / room_total * 100 << "%\n";
	cout.close();
	std::cout << "The result has been successfully stored in the file.\n";

	return 0;
}