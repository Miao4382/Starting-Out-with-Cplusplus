#include "number_list_template_2.h"
#include <iostream>

int main()
{
  NumberList<long> emp_id;
  emp_id.AppendNode(5658845);
  emp_id.AppendNode(4520125);
  emp_id.AppendNode(7895122);
  emp_id.AppendNode(8777541);
  emp_id.AppendNode(8451277);
  emp_id.AppendNode(1302850);
  emp_id.AppendNode(7580489);
  
  // define the rest containers 
  NumberList<int> hours;
  NumberList<double> pay_rate;
  NumberList<double> wages;
  
  // define four pointers to navigate through the four linked list 
  ListNode<long>* id_ptr = emp_id.Begin();
  ListNode<int>* hour_ptr = nullptr;
  ListNode<double>* rate_ptr = nullptr;
  ListNode<double>* wage_ptr = nullptr;
  
  // use a loop to display each emp_id, and then ask the user to enter that employee's hours and pay rate 
  while (id_ptr != nullptr)
  {
    int hour_input;
    double rate_input;
    // input hour 
    std::cout << "Please input the hour for employee " << id_ptr->value << ": ";
    std::cin >> hour_input;
    while (hour_input < 0)
    {
      std::cout << "Invalid input, working hour should be greater than zero, please input again: ";
      std::cin >> hour_input;
    }
    hours.AppendNode(hour_input);
    
    // input pay rate 
    std::cout << "Please input the pay rate for employee " << id_ptr->value << ": ";
    std::cin >> rate_input;
    while (rate_input < 15.00)
    {
      std::cout << "The pay rate should be greater than 15.00, please input again: ";
      std::cin >> rate_input;
    }
    pay_rate.AppendNode(rate_input);
    
    // move to next node 
    id_ptr = id_ptr->next;    
  }
  
  // calculate wage
  hour_ptr = hours.Begin();
  rate_ptr = pay_rate.Begin();
  
  while (hour_ptr != nullptr)
  {
    wages.AppendNode(hour_ptr->value * rate_ptr->value);
    hour_ptr = hour_ptr->next;
    rate_ptr = rate_ptr->next;
  }
  
  // display wage 
  id_ptr = emp_id.Begin();
  wage_ptr = wages.Begin();
  while (id_ptr != nullptr)
  {
    std::cout << "Empid: " << id_ptr->value << "  Wage: $" << wage_ptr->value << "\n";
    id_ptr = id_ptr->next;
    wage_ptr = wage_ptr->next;
  }
  std::cout << "\n";
    
  return 0;
  
  
}