#include "dynamic_stack_template.h"
#include "inventory.h"
#include <iostream>

void ShowMenu();
void AddPart(DynamicStack<Item>& inventory_stack);
void TakePart(DynamicStack<Item>& inventory_stack);

int main()
{
  // define a dynamic stack to hold inventory item 
  DynamicStack<Item> bag;
  
  char choice; // to hold user's choice 
  
  // input inventory item
  do 
  {
    ShowMenu();
    std::cin >> choice;
    while (choice != '1' && choice != '2' && choice != '3')
    {
      std::cout << "Invalid input, please select 1, 2 or 3: ";
      std::cin >> choice;
    }
    
    switch (choice)
    {
    case '1':
      AddPart(bag);
      break;
    case '2':
      TakePart(bag);
      break;
    case '3':
      break;
    }
  } while (choice != '3');
  
  // display contents of remaining member values
  if (!bag.IsEmpty())
  {
    std::cout << "\nItems remaining in inventory:\n";
    while (!bag.IsEmpty())
    {
      // define a temporary container and pop 
      Item temp;
      bag.Pop(temp);
      
      // display the content
      std::cout << "Serial number: " << temp.serial_num() << "\n"
      << "Manufacturing date: " << temp.manufac_date() << "\n"
      << "Lot number: " << temp.lot_num() << "\n\n";      
    }      
  }
  else 
    std::cout << "The inventory is empty\n";
  
  return 0;

}

void ShowMenu()
{
  std::cout << "\nInventory Management System\n";
  std::cout << "Please select one term below:\n"
  << "1. Add a part to inventory\n"
  << "2. Take a part from inventory\n"
  << "3. Finish and exit\n";
}

void AddPart(DynamicStack<Item>& inventory_stack)
{
  int s_n, l_n;
  std::string m_d;
  
  std::cout << "Please input the serial number: ";
  std::cin >> s_n;
  std::cout << "Please input the manufacturing date: ";
  std::cin.ignore();
  getline(std::cin, m_d);
  std::cout << "Please input the lot number: ";
  std::cin >> l_n;
  
  // build a new object 
  Item temp(s_n, m_d, l_n);
  
  // push to the stack 
  inventory_stack.Push(temp); // the constructor of StackNode makes this possible
}

void TakePart(DynamicStack<Item>& inventory_stack)
{
  // check if the inventory is empty 
  if (inventory_stack.IsEmpty())
  {
    std::cout << "The inventory is empty!\n";
    return;
  }
  
  // define a temporary container and pop 
  Item temp;
  inventory_stack.Pop(temp);
  
  // display the content 
  std::cout << "Item retrieve successful:\n"
  << "Serial number: " << temp.serial_num() << "\n"
  << "Manufacturing date: " << temp.manufac_date() << "\n"
  << "Lot number: " << temp.lot_num() << "\n";
  
  std::cout << "Press enter to continue...";
  std::cin.ignore();
  std::cin.get();
  std::cout << "\n";
  
}

