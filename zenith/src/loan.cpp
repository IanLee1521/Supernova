/**
  * @file loan.cpp
  *
  * @author Ian Lee
  */

#include "loan.h"

Loan::Loan()
  : mPrinciple(0.0f)
  , mInterest(0.0f)
  , mInterestRate(0.0f)
  , mInterestAccrued(0.0f)
  , mMinimumPayment(0.0f)
  , mTotalPaid(0.0f)
{ }

Loan::Loan(float principle, float interest_rate, float minimum_payment)
  : mPrinciple(principle)
  , mInterest(0.0f)
  , mInterestRate(interest_rate)
  , mInterestAccrued(0.0f)
  , mMinimumPayment(minimum_payment)
  , mTotalPaid(0.0f)
{ }

Loan::~Loan() { }

float Loan::addInterest(int days) {
  mInterest = mInterestRate/365.25f * days * mPrinciple;
  mInterestAccrued += mInterest;
  return mInterest;
}

float Loan::makePayment(float extra) {
  float payment = mMinimumPayment + extra;
  float balance = mPrinciple + mInterest;

  if(balance == 0.0f) {
    return payment;
  }

  if(balance >= payment) {
    mTotalPaid += payment;
    mPrinciple -= (payment - mInterest);
    mInterest = 0;
    return 0.0f;
  } else {
    mTotalPaid += balance;
    mPrinciple = mInterest = 0;
    return payment - balance;
  }
}

void Loan::print() {
  printf("%8.2f  %6.2f  %0.4f  %5.2f \n", mPrinciple, mInterest, mInterestRate, mMinimumPayment);
}

void Loan::printBalance() {
  printf("%12.2f  ", mPrinciple);
}

std::ostream& operator<< (std::ostream &out, Loan &loan) {
  out
    << loan.mPrinciple << "  "
    << loan.mInterest << "  "
    << loan.mInterestRate << "  "
    << loan.mMinimumPayment;
  return out;
}
