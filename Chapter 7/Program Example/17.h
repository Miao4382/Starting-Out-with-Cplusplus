//7-17 Pass entire array to function
#include<iostream>
void double_array(int num[],int);
int main()
{
	int num[5] = { 1,4,2,3,6 };
	int size = sizeof(num) / sizeof(int);
	std::cout << "In main, size = " << size << std::endl;
	double_array(num,size);
	for (int i = 0; i < 5; i++)
		std::cout << num[i] << std::endl;
	return 0;
}

void double_array(int num[], int size)
{
	for (int i = 0; i < size; i++)
		num[i] *= 2;
}