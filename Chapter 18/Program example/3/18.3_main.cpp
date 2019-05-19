#include "number_stack_template.h"
#include <string>
#include <iostream>

void DisplayMenu();
void PushItem(NumberStack<std::string>& stack);
void PopItem(NumberStack<std::string>& stack);

int main()
{
  std::cout << "How big should I make the stack: ";
  int size;
  std::cin >> size;

  // create the static stack
  NumberStack<std::string> stack(size);

  char choice;

  do
  {
    DisplayMenu();
    std::cin >> choice;

    switch (choice)
    {
    case '1':
      PushItem(stack);
      break;
    case '2':
      PopItem(stack);
      break;
    case '3':
      break;
    }
  } while (choice != '3');

  return 0;
}

void DisplayMenu()
{
  std::cout << "What do you want to do?\n"
    << "1 - Push an item onto the stack\n"
    << "2 - Pop an item off the stack\n"
    << "3 - Quit the program\n";
}

void PushItem(NumberStack<std::string>& stack)
{
  std::cout << "Please input an item: ";
  std::string item;
  std::cin.ignore(); // to skip the '\n'
  getline(std::cin, item);

  stack.Push(item);
  stack.DisplayUsage();
}

void PopItem(NumberStack<std::string>& stack)
{
  std::string temp;
  stack.Pop(temp);
  std::cout << temp << " was popped.\n";

  stack.DisplayUsage();
}