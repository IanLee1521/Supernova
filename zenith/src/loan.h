/**
  * @file loan.cpp
  *
  * @author Ian Lee
  */

class Loan {
public:
  Loan();
  ~Loan();

  Loan(float principle, float interest_rate, float minimum_payment);

private:
  float mPrinciple;
  float mInterestRate;
  float mMinimumPayment;
};
