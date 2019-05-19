//7-17, 18, 19 Pass entire array to function
#include<iostream>
void double_array(int num[],int);
//void double_array(int num[]);
int main()
{
	int num[5] = { 1,4,2,3,6 };
	int size = sizeof(num) / sizeof(int);
	//std::cout << "In main, size = " << size << std::endl;
	double_array(num, size);
	for (int i = 0; i < 5; i++)
		std::cout << num[i] << std::endl;
	return 0;
}

void double_array(int num[], int size)
//void double_array(int num[])
{
	for (int i = 0; i < size; i++)
		num[i] *= 2;
}