/*// explore how type casting works
#include <iostream>
using namespace std;

int main()
{
	int a=1;
	double b;
	//b = static_cast<double>(a)/ 2;
	b = a / 2;
	cout << b << endl;
	return 0;
}*/

// Example program: applying type cast
#include <iostream>
using namespace std;

int main()
{
	int books, month; //books=number of books to read, months=number of month spent on reading
	double book_per_month;

	cout << "Please input the number of books to read:\n";
	cin >> books;
	cout << "Great! Now input the number of months you wish to spend on reading:\n";
	cin >> month;
	book_per_month = static_cast<double>(books) / month;
	cout << "On average, every month you should read: " << book_per_month << " books! Do it now!" << endl;
	return 0;

}