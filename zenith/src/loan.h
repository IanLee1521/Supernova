/**
  * @file loan.cpp
  *
  * @author Ian Lee
  */

#include <iostream>

class Loan {
public:
  Loan();
  ~Loan();

  Loan(float principle, float interest_rate, float minimum_payment);
  float addInterest(int days);
  float makePayment(float extra = 0);

  friend std::ostream& operator<< (std::ostream &out, Loan &loan);
  void print();
  void printBalance();
  float getBalance() {return mPrinciple + mInterest;}
  float getInterestAccrued() {return mInterestAccrued;}
  float getTotalPaid() {return mTotalPaid;}

private:
  float mPrinciple;
  float mInterest;
  float mInterestRate;
  float mInterestAccrued;
  float mMinimumPayment;
  float mTotalPaid;
};
