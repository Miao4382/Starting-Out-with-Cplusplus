//Program 3-21_1: Study of cin.get()
#include <iostream>
#include <string>
using namespace std;
int main()
{
	char ch;
	ch = cin.get();
	cout << "To check if the [enter] has been recorded" << ch << ch << ch << ch << "any thought?\n";
	return 0;
}

//To pause a program
#include <iostream>
using namespace std;
int main()
{
	char ch;
	cout << "This program has paused, please press enter to continue!";
	ch = cin.get();
	cout << "This program has paused again, please press enter to continue!!";
	cin.get(ch);
	cout << "This program is useless, it paused again. Please press enter to save it!";
	cin.get();
	cout << "Thanks for your effort. You will be remembered for your kindness!\n";
	return 0;
}


//To find out when do cin.ignore stop, before the stated character or after?
#include <iostream>
using namespace std;

int main()
{
	char a, b;
	cin >> a;
	cin.ignore(20, '3');
	cin >> b;
	cout << b << endl;
	return 0;
}




//find out if getline function will put the cin to the very end of the keyboard buffer
#include <iostream>
#include <string>
using namespace std;
int main()
{
	string A;
	char C;
	char B;
	getline(cin, A);
	//cin >> C;
	cin.get(B);
	cout << "1234" << B << B << B << "6789\n";
	return 0;
}
//according to the result, the getline function will force the cin reader (in the keyboard buffer) forward to the place after the last \n