//8. How Many Widgets
#include <iostream>
using namespace std;
int main()
{
	double pallet_mass, total_mass, widget_num;
	const double widget = 12.5;
	cout << "Please input the mass of pallet: ";
	cin >> pallet_mass;
	cout << "Please input the mass of pallet and widget: ";
	cin >> total_mass;
	widget_num = (total_mass - pallet_mass) / widget;
	cout << "There are " << widget_num << " widgets stack on the pallet.\n";
	return 0;
}