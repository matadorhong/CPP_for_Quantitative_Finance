/* C++ For Quantitative Finance            */
/* Loan Calculation (Fixed Interest Rate)  */
/* Author: David Li                        */

#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

int getInput(string msg, int min, int max);
double getInput(string msg, double min, double max);
void printT(double aT[][5], int);
double remainBal(int life, double loan, double rate, double pmnt);

int main()
{
	double intRate, loanAmnt;
	int loanLife, prd, i, j, itStage;
	double prdPmnt, stepSize, tolerance, fBalL, fBalH;
	const int maxPrds = 50, maxIter = 50;
	double bT[maxIter][5]; // to track iteration results

	string intRateMsg = "Enter periodic interest rate in decimal: ";
	string loanLifeMsg = "Enter loan life in periods: ";
	string loanAmntMsg = "Enter initial loan amount: ";
	
/*****************************************************************/
/* Inputs:                                                       */
/*   - intRate                                                   */
/*   - loanLife                                                  */
/*   - loanAmnt                                                  */
/*****************************************************************/
for (int i = 1; i <= 5; i++) {
     cout << "Enter periodic interest rate in decimal: ";
     cin >> intRate;

 if ((intRate < 0.0) || (intRate > 0.15)) {
   if (i == 5) {
      cout << "\nThis program is being terminated\n";
      system("PAUSE");
      return 0; } else {
      cout << "You must enter a value between ";
      cout << "0.0 and 0.15. Please try again." << endl; } }
 else { break; } }

 for (int i = 1; i <= 5; i++) {
      cout << "Enter loan life in periods: ";
      cin >> loanLife;
 
    if ((loanLife < 0) || (loanLife > 50)) {
      if (i == 5) {
          cout << "\nThis program is being terminated\n";
          system("PAUSE");
          return 0;} else {
          cout << "You must enter a value between ";
          cout << "0 and 50. Please try again." << endl; } }
    else { break; } }

 for (int i = 1; i <= 5; i++) {
      cout << "Enter initial loan amount: ";
      cin >> loanAmnt;

      if ((loanAmnt < 0.0) || (loanAmnt > 1000000.0)) {
        if (i == 5) {
            cout << "\nThis program is being terminated\n";
            system("PAUSE");
            return 0; } else {
     cout << "You must enter a value between ";
     cout << "0.0 and 1000000.0. Please try again." << endl; } }
 else break; }
	
 tolerance = loanAmnt / 100000.;
	
 itStage = 1; // used to distinguish stage 1 from stage 2

 stepSize = loanAmnt / 100.; // increment to use in each iteration
 for (i = 0; i<maxIter; i++) for (j = 0; j<5; j++) bT[i][j] = 0.;
 prdPmnt = loanAmnt * intRate; //initial guess for payment
 fBalH = 1000.;

 fBalL = remainBal(loanLife, loanAmnt, intRate, prdPmnt);

 for (i = 1; fabs(fBalH) > tolerance; i++) {
      fBalH = remainBal(loanLife, loanAmnt, intRate, prdPmnt + stepSize);

		bT[i - 1][0] = prdPmnt;
		bT[i - 1][1] = stepSize;
		bT[i - 1][2] = prdPmnt + stepSize;
		bT[i - 1][3] = fBalL;
		bT[i - 1][4] = fBalH;

  if ((fBalL * fBalH) > 0) {
       prdPmnt += stepSize;
       fBalL = fBalH;
   if (itStage != 1) stepSize = stepSize / 2.; } else {
       itStage = 2;
       stepSize = stepSize / 2.; }
     if (i > maxIter) {
	cout << "Iteration did not converge in " << maxIter;
	cout << " passes, the maximum allowed." << endl;
	break;} }

/******************************************************************/
/* Print out iteration table                                      */
/******************************************************************/
	printT(bT, i - 1);
	cout << endl << endl;

 /* Wait for the user to read the output on the console          */
	system("PAUSE");
	return 0; }

double remainBal(int life, double loan, double rate, double pmnt)
{
	double begBal, intPart, princPart;
	int i;

	begBal = loan;
	for (i = 1; i <= life; i++)
	{
		intPart = begBal * rate;
		princPart = pmnt - intPart;
		begBal -= princPart;
	}
	return begBal;
}

void printT(double aT[][5], int loanLife)
{
	int i, j;

	cout << " Iter. No.";
	cout << " Lo Guess";
	cout << " Step Size";
	cout << " Hi Guess";
	cout << " Lo End Bal.";
	cout << " Hi End Bal." << endl;

	cout.precision(2);
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);

	for (i = 0; i < loanLife; i++)
	{
		cout.width(12);
		cout << endl << i + 1;

		for (j = 0; j <5; j++)
		{
			cout.width(12);
			cout << aT[i][j];
		}
	}
	return;
}
