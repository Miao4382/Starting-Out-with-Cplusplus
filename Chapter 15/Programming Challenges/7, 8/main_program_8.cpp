#include <iostream>
#include "preferred_customer.h"

void DisplayCustomerInfo(const PreferredCustomer& c);

int main()
{
  PreferredCustomer p1;
  
  std::cout << "Before assigning info:\n";
  DisplayCustomerInfo(p1);
  
  p1.SetInfo("Miao", "Yu", "1839 Portland Ave", "Tallahassee", "Florida", "32303", "8505245269");
  p1.set_customer_number(100001);
  p1.set_mailing_list(true);
  p1.SetPreferredCustomerInfo(5000.0);
  
  std::cout << "\n\nAfter assigning info:\n";
  DisplayCustomerInfo(p1);
  
  return 0;
}

void DisplayCustomerInfo(const PreferredCustomer& c)
{
  std::cout << "Name: " << c.last_name() << ", " << c.first_name() << "\n"
  << "Address: " << c.address() << "\n"
  << "City: " << c.city() << "\n"
  << "State: " << c.state() << "\n"
  << "Zip: " << c.zip() << "\n"
  << "Phone: " << c.phone() << "\n"
  << "Customer Number: " << c.customer_number() << "\n"
  << "Mailing List: " << (c.mailing_list() == 1 ? "In the mailing list" : "Not in the mailing list") << "\n"
  << "Purchased Amount: $" << c.purchase_amount() << "\n"
  << "Discount Level: " << c.discount_level() << "\n";
}