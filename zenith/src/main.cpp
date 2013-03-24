/**
  * foo
  *
  * @author Ian Lee
  */

#include <iostream>
#include <map>
#include <string>

#include "loan.h"

int main() {
  // Effective April 1, 2013
  std::map<std::string, Loan> loans;
  
  Loan ford     = Loan(11000.00f, 0.0f, 500.00f);
  Loan ford_esp = Loan(1369.60f, 0.0f, 105.35f);
  Loan mancini  = Loan(2000.00f, 0.0f, 200.00f);
  Loan ucsc     = Loan(60000.00f, 0.068f, 750.00f);
  Loan crv      = Loan(5000.00f, 0.03f, 107.47f);
  Loan calpoly  = Loan(14000.00f, 0.068f, 219.34f);

  loans.insert(loans.begin(), std::pair<std::string,Loan>("ford", ford));
  loans.insert(loans.begin(), std::pair<std::string,Loan>("ford_esp", ford_esp));
  loans.insert(loans.begin(), std::pair<std::string,Loan>("mancini", mancini));
  loans.insert(loans.begin(), std::pair<std::string,Loan>("ucsc", ucsc));
  loans.insert(loans.begin(), std::pair<std::string,Loan>("crv", crv));
  loans.insert(loans.begin(), std::pair<std::string,Loan>("calpoly", calpoly));

  std::cout << "Hello World" << std::endl;



  return 0;
}