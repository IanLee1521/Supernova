/**
 * @file main.cpp
 *
 * @brief  Main Function for Loan Calculator
 * 
 * @author Ian Lee
 **/

#include <iostream>
#include <map>
#include <string>

#include "loan.h"

int main() {
  // Effective April 1, 2013
  std::map<std::string, Loan> loans;
  float extra = 0.0f;

  loans["ford"]     = Loan(11352.00f, 0.00f,  500.00f);
  loans["ford_esp"] = Loan( 1369.60f, 0.00f,  105.35f);
  loans["mancini"]  = Loan( 2000.00f, 0.00f,  200.00f);
  loans["ucsc"]     = Loan(63609.87f, 0.068f, 750.00f);
  loans["crv"]      = Loan( 5054.00f, 0.030f, 107.47f);
  loans["calpoly"]  = Loan(13988.00f, 0.068f, 219.34f);
  loans["bauman"]   = Loan();
  loans["house"]    = Loan();
  Loan big_loan = Loan(10000000.0f, 0.0f, 0.0f);

  printf("    -- ");
  for(std::map<std::string, Loan>::iterator it = loans.begin(); it != loans.end(); ++it) {
    printf("%12s  ", it->first.c_str());
  }
  std::cout << std::endl;

	for(int month = 0; month < 180; ++month) {
    if(month == 12) {
      loans["bauman"] = Loan(10000.00f, 0.00f, 555.55f);
    }
    if(month == 24) {
      loans["house"] = Loan(500000.00f, 0.035f, 2500.00f);
    }

    extra += 120.00;
    printf("%03d -- ", month);
    Loan *extra_target = &big_loan;
    for(std::map<std::string, Loan>::iterator it = loans.begin(); it != loans.end(); ++it) {
      if(it->second.getBalance() > 0) {
        if(it->second.getBalance() < extra_target->getBalance()) {
          extra_target = &(it->second);
        }
      }
    }

	  for(std::map<std::string, Loan>::iterator it = loans.begin(); it != loans.end(); ++it) {
		  Loan *loan = &(it->second);
      loan->printBalance();

		  loan->addInterest(30);
      if(loan == extra_target) {
        extra = loan->makePayment(extra);
      } else {
        extra += loan->makePayment();
      }
	  }
    std::cout << std::endl;
	}

  for(std::map<std::string, Loan>::iterator it = loans.begin(); it != loans.end(); ++it) {
    printf("%12s -- \n", it->first.c_str());
    printf("             --  Total Paid:       %8.2f\n", it->second.getTotalPaid());
    printf("             --  Interest Accrued: %8.2f\n", it->second.getInterestAccrued());
    std::cout << std::endl;
  }

  return 0;
}
