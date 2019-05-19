#include <iostream>
#include "Divsale.h"
#include <iomanip>

void PrintReport(Divsale s[]);

int main()
{
	Divsale divsale[6];

	double s1, s2, s3, s4;
	//data input
	for (int i = 0; i < 6; i++)
	{
		std::cout << "Please input sale figure for four quarters for each division, separate by space: ";
		std::cin >> s1 >> s2 >> s3 >> s4;
		divsale[i].SetSale(s1, s2, s3, s4);
	}

	//print
	PrintReport(divsale);
	
	return 0;
}

void PrintReport(Divsale s[])
{
	using namespace std;
	
	cout << "Division sale figure\n"
	<< "---------------------\n\n"
	<< "Division#               Q1               Q2               Q3               Q4\n"
	<< "----------------------------------------------------------------------------------\n";
	
	cout << setprecision(2) << fixed;
	
	for (int i=0; i<6; i++)
	{
		cout << setw(5) << i+1 << setw(20) << "$" << setw(11) << s[i][0] << setw(7) << "$" << setw(11) << s[i][1] << setw(7) << "$" << setw(11) << s[i][2] << setw(7) << "$" << setw(11) << s[i][3] << endl;
	}
	
	cout << "----------------------------------------------------------------------------------\n\n";
	cout << "Total sale: " << s[0].GetTotal() << "\n\n";
}