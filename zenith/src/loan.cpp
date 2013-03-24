/**
  * @file loan.cpp
  *
  * @author Ian Lee
  */

#include "loan.h"

Loan::Loan()
  : mPrinciple(0.0f)
  , mInterestRate(0.0f)
  , mMinimumPayment(0.0f)
{ }

Loan::Loan(float principle, float interest_rate, float minimum_payment)
  : mPrinciple(principle)
  , mInterestRate(interest_rate)
  , mMinimumPayment(minimum_payment)
{ }

Loan::~Loan() { }
