//4. Areas of Rectangles
#include <iostream>
using namespace std;

int main()
{
	double length_1, length_2, width_1, width_2;
	cout << "Please input the length and width of the first rectangle:";
	cin >> length_1 >> width_1;
	cout << "Please input the length and width of the second rectangle:";
	cin >> length_2 >> width_2;
	if (length_1*width_1 == length_2*width_2)
		cout << "Their area is the same!\n";
	else if (length_1 > 0 && length_2 > 0 && width_1 > 0 && width_2 > 0)
		cout << (length_1*width_1 > length_2*width_2 ? "Rectangle 1 has greater area\n" : "Rectangle 2 has greater area\n");
	else
		cout << "Invalid input!\n";
	return 0;
}




//4-(2): Area of Rectangle, switch method
#include <iostream>
using namespace std;
int main()
{
	double length_1, width_1, length_2, width_2;
	double area_1, area_2;
	int flag;
	cout << "Please input the length and width of the first and second rectangle:";
	cin >> length_1 >> width_1 >> length_2 >> width_2;
	area_1 = length_1*width_1;
	area_2 = length_2*width_2;
	if (area_1 - area_2)
		flag = (area_1 > area_2 ? 1 : 2);
	else
		flag = 0;

	switch (flag)
	{
	case 0: cout << "Their area is the same\n"; break;
	case 1: cout << "Rectangle 1 has greater area\n"; break;
	case 2: cout << "Rectangle 2 has greater area\n"; break;
	default: cout << "Invalid input!\n";
	}

	return 0;
}