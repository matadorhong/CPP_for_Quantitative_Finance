//** C++ For Quantitative Finance
//** Loan Calculation (Constant Annuities)
//** Author: David Li 

#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

int getInput(string msg, int min, int max);
double getInput(string msg, double min, double max);

int main()
{
int nprd, i, ansInd, pvfvInd, typeInd;
double pv, fv, accPv, accFv, intRate, pmnt, intN;

string ansIndMsg = "";
string pvMsg = "Enter present value of annuity: ";
string fvMsg = "Enter future value of annuity: ";
string pmntMsg = "Enter annuity amount: ";
string nprdMsg = "Enter number of payments in whole numbers: ";
string intRateMsg = "Enter periodic interest rate in decimal: ";
string pvfvIndMsg = "Enter 1 for pv and 2 for fv: ";
string typeIndMsg = "";

//*****************************************************************
// Get user inputs
//*****************************************************************
cout << "Indicate which answer you want: " << endl;
cout << "For present value of annuity enter 1" << endl;
cout << "For future value of annuity enter 2" << endl;
cout << "For annuity amount enter 3" << endl;
cout << "For number of payments needed enter 4" << endl;

ansInd = getInput(ansIndMsg, 1, 4);
if(ansInd <= 0) return 0;

if((ansInd != 1) && (ansInd != 2))
 {
cout << "Will you provide present value or future value?" << endl;
 pvfvInd = getInput(pvfvIndMsg, 1, 2);
if(ansInd <= 0) return 0;
}

if((ansInd > 2) && (pvfvInd == 1))
{
pv = getInput(pvMsg, 0.0, 100000000.0);
if (pv <= 0.) return 0;
}

if((ansInd > 2) && (pvfvInd == 2))
{
fv = getInput(fvMsg, 0.0, 100000000.0);
if (fv <= 0.) return 0;
}

if(ansInd != 3)
 {
pmnt = getInput(pmntMsg, 0.0, 100000000.0);
if (pmnt <= 0.) return 0;
}

if(ansInd != 4)
{
nprd = getInput(nprdMsg, 0, 500);
if (nprd <= 0) return 0;
}

if(ansInd != 5)
{
intRate = getInput(intRateMsg, 0.0, 0.20);
if (intRate <= 0.) return 0;
}

cout << "Enter 1 for regular (in arrears) annuity and ";
cout << "2 for annuity in advance: " << endl;
typeInd = getInput(typeIndMsg, 1, 2);
if (typeInd <=0) return 0;

//*****************************************************************
// Calculate PV of annuity
//*****************************************************************
if (ansInd == 1)
{
intN = pow((1+intRate), nprd); // intermediate calculation
pv = pmnt*(1 - 1/intN)/intRate;
if(typeInd == 2) pv = pv *(1+ intRate);
cout << "Present value of annuity is: " << pv << endl;
}

//*****************************************************************
// Calculate FV of annuity
//*****************************************************************
if (ansInd == 2)
{
intN = pow((1+intRate), nprd); // intermediate calculation
fv = pmnt*(intN-1)/intRate;
if(typeInd == 2) fv = fv *(1+ intRate);
cout << "Future value of annuity is: " << fv << endl;
}

//*****************************************************************
// Calculate annuity amount required given PV
//*****************************************************************
if ((ansInd == 3) && (pvfvInd == 1))
{
intN = pow((1+intRate), nprd); // intermediate calculation
pmnt = pv/((1 - 1/intN)/intRate);

if(typeInd == 2) pmnt = pmnt / (1+ intRate);
cout << "Required annuity amount is: " << pmnt << endl;
}

//*****************************************************************
// Calculate annuity amount required given FV
//*****************************************************************
if ((ansInd == 3) && (pvfvInd == 2))
{
intN = pow((1+intRate), nprd); // intermediate calculation
pmnt = fv/((intN-1)/intRate);
if(typeInd == 2) pmnt = pmnt / (1+ intRate);
cout << "Required annuity amount is: " << pmnt << endl;
}

//*****************************************************************
// Required number of payments given PV
//*****************************************************************
accPv = 0.;
if ((ansInd == 4) && (pvfvInd == 1))
{
for (i = 1; (accPv < pv) && (i < 500); i++)
{
nprd = i;
intN = pow((1+intRate), nprd); // intermediate calculation
accPv = pmnt*(1 - 1/intN)/intRate;
if(typeInd == 2) accPv = accPv *(1+ intRate);
}

if (i == 500)
{
cout << "It will take over 500 payments." << endl;
}
else
{
cout << "Between " << (i-2) << " and " << (i-1);
cout << " payments will be required" << endl;
}
}

//*****************************************************************
// Required number of payments given FV
//*****************************************************************
accFv = 0.;
if ((ansInd == 4) && (pvfvInd == 2))
{
for (i = 1; (accFv < fv) && (i < 500); i++)

{
 nprd = i;
 intN = pow((1+intRate), nprd); // intermediate calculation
 accFv = pmnt*(intN - 1)/intRate;
 if(typeInd == 2) accPv = accPv *(1+ intRate);
 }

 if (i == 500)
 {
 cout << "It will take over 500 payments." << endl;
 }
 else
 {
 cout << "Between " << (i-2) << " and " << (i-1);
 cout << " payments will be required" << endl;
 }
 }

 system("PAUSE");
 return 0;
 }



 int getInput(string msg, int min, int max)
 {
int in;

 for (int i = 1; i <= 5; i++)
 {
 cout << msg;
 cin >> in;

 if((in < min) || (in > max))
 {
 if (i == 5)
 {
 cout << "\nThis program is being terminated\n";
 system("PAUSE");
 return -1;
 }
 else
 {
 cout << "You must enter a value between ";
 cout << min << " and " << max << endl;
 }
 }
 else {break;}
 }
 return in;
 }


 double getInput(string msg, double min, double max)
 {
 double in;

 for (int i = 1; i <= 5; i++)
 {
cout << msg;
 cin >> in;

 if((in < min) || (in > max))
 {
 if (i == 5)
 {
 cout << "\nThis program is being terminated\n";
 system("PAUSE");
 return -1.0;
}
 else
 {
 cout << "You must enter a value between ";
 cout << min << " and " << max << endl;
 }
 }
 else {break;}
}
 return in;
}
