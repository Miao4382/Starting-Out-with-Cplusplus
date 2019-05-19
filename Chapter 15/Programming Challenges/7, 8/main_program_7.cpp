#include <iostream>
#include "customer_data.h"

void DisplayCustomerInfo(const CustomerData& c);

int main()
{
  CustomerData c1;
  
  std::cout << "Before assigning info:\n";
  DisplayCustomerInfo(c1);
  
  c1.SetInfo("Miao", "Yu", "1839 Portland Ave", "Tallahassee", "Florida", "32303", "8505245269");
  c1.set_customer_number(100001);
  c1.set_mailing_list(true);
  
  std::cout << "\n\nAfter assigning info:\n";
  DisplayCustomerInfo(c1);
  
  return 0;
}

void DisplayCustomerInfo(const CustomerData& c)
{
  std::cout << "Name: " << c.last_name() << ", " << c.first_name() << "\n"
  << "Address: " << c.address() << "\n"
  << "City: " << c.city() << "\n"
  << "State: " << c.state() << "\n"
  << "Zip: " << c.zip() << "\n"
  << "Phone: " << c.phone() << "\n"
  << "Customer Number: " << c.customer_number() << "\n"
  << "Mailing List: " << (c.mailing_list() == 1 ? "In the mailing list" : "Not in the mailing list") << "\n";
}