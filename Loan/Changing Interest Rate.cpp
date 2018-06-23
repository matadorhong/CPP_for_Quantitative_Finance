
//** C++ For Quantitative Finance
//** Loan Calculation (Changing Interest Rate)


#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

//int getInput(string msg, int min, int max);
//double getInput(string msg, double min, double max);
void printT(double aT[][5], int);

int main()
{
	double intRate1, intRate2, intRate3, maxInt, minInt;
	int loanLife1, loanLife2, loanLife3, loanLife, prd, iter, i, j;
	double loanAmnt, prdPmnt, stepSize, tolerance;
	const int maxPrds = 50;
	double aT[maxPrds][5]; // amortization table

	string intRateMsg = "Enter periodic interest rate in decimal: ";
	string loanLifeMsg = "Enter loan life in periods: ";
	string loanAmntMsg = "Enter initial loan amount: ";

	int begC = 0; // column number for period beginning balance
	int pmntC = 1; // column number for constant periodic payments
	int intC = 2; // column number for interest component
	int prinC = 3; // column number for principal component
	int endC = 4; // column number for period ending balance
	
	
	
	//*******************************************************************
	// Inputs:
	//   - intRate
	//   - loanLife
	//   - loanAmnt
	//*****************************************************************
	
	
			for (int i = 1; i <= 5; i++)
		{
			cout << "Enter periodic interest rate1 in decimal: ";
			cin >> intRate1;

			if ((intRate1 < 0.0) || (intRate1 > 0.15))
			{
				if (i == 5)
				{
					cout << "\nThis program is being terminated\n";
					system("PAUSE");
					return 0;
				}

				else
				{
					cout << "You must enter a value between ";
					cout << "0.0 and 0.15. Please try again." << endl;
				}

			}
			else { break; }

		}
	
	
			for (int i = 1; i <= 5; i++)
		{
			cout << "Enter periodic interest rate2 in decimal: ";
			cin >> intRate2;

			if ((intRate2 < 0.0) || (intRate2 > 0.15))
			{
				if (i == 5)
				{
					cout << "\nThis program is being terminated\n";
					system("PAUSE");
					return 0;
				}

				else
				{
					cout << "You must enter a value between ";
					cout << "0.0 and 0.15. Please try again." << endl;
				}

			}
			else { break; }

		}
		
		
				for (int i = 1; i <= 5; i++)
		{
			cout << "Enter periodic interest rate in decimal: ";
			cin >> intRate3;

			if ((intRate3 < 0.0) || (intRate3 > 0.15))
			{
				if (i == 5)
				{
					cout << "\nThis program is being terminated\n";
					system("PAUSE");
					return 0;
				}

				else
				{
					cout << "You must enter a value between ";
					cout << "0.0 and 0.15. Please try again." << endl;
				}

			}
			else { break; }

		}
		
		
		for (int i = 1; i <= 5; i++)
		{
			cout << "Enter loanlife1 in periods: ";
			cin >> loanLife1;

			if ((loanLife1 < 0) || (loanLife1 > 50))
			{
				if (i == 5)
				{
					cout << "\nThis program is being terminated\n";
					system("PAUSE");
					return 0;
				}
				else
				{
					cout << "You must enter a value between ";
					cout << "0 and 50. Please try again." << endl;
				}
			}
			else { break; }
		}
		
		
		for (int i = 1; i <= 5; i++)
		{
			cout << "Enter loanlife2 in periods: ";
			cin >> loanLife1;

			if ((loanLife2 < 0) || (loanLife2 > 50))
			{
				if (i == 5)
				{
					cout << "\nThis program is being terminated\n";
					system("PAUSE");
					return 0;
				}
				else
				{
					cout << "You must enter a value between ";
					cout << "0 and 50. Please try again." << endl;
				}
			}
			else { break; }
		}
		
		
		for (int i = 1; i <= 5; i++)
		{
			cout << "Enter loanlife3 in periods: ";
			cin >> loanLife1;

			if ((loanLife3 < 0) || (loanLife3 > 50))
			{
				if (i == 5)
				{
					cout << "\nThis program is being terminated\n";
					system("PAUSE");
					return 0;
				}
				else
				{
					cout << "You must enter a value between ";
					cout << "0 and 50. Please try again." << endl;
				}
			}
			else { break; }
		}
		
		
				for (int i = 1; i <= 5; i++)
		{
			cout << "Enter initial loan amount: ";
			cin >> loanAmnt;

			if ((loanAmnt < 0.0) || (loanAmnt > 1000000.0))
			{
				if (i == 5)
				{
					cout << "\nThis program is being terminated\n";
					system("PAUSE");
					return 0;
				}
				else
				{
					cout << "You must enter a value between ";
					cout << "0.0 and 1000000.0. Please try again." << endl;
				}
			}
			else break;
		}
		
		
		
		 tolerance = 1.0;
 
 
loanLife =loanLife1 + loanLife2 +loanLife3;

for(i=0; i<maxPrds; i++) for(j=0; j<5; j++) aT[i][j] = 0.;
aT[loanLife -1][endC] = 1000.;

minInt = intRate1;
if (intRate2 < minInt) minInt = intRate2;
if (intRate3 < minInt) minInt = intRate3;

maxInt = intRate1;
if (intRate2 > maxInt) maxInt = intRate2;
if (intRate3 < maxInt) maxInt = intRate3;

stepSize = 0.; // initial value
prdPmnt = loanAmnt*minInt; //initial guess for payment
		
		
		
		
		
//*****************************************************************
// Iteration to determine required periodic payment
//*****************************************************************
for(iter = 1; aT[loanLife -1][endC] >= tolerance; iter++)
{
prdPmnt += stepSize;
aT[0][begC] = loanAmnt;

for(prd = 0; prd < loanLife; prd++)
{
if (prd != 0) aT[prd][begC] = aT[prd -1][endC];
aT[prd][pmntC] = prdPmnt;

aT[prd][intC] = aT[prd][begC] * intRate1;
if(prd > loanLife1-1) aT[prd][intC] = aT[prd][begC] *intRate2;
if(prd > (loanLife1 + loanLife2 -1))
aT[prd][intC] = aT[prd][begC] * intRate3;

aT[prd][prinC] = aT[prd][pmntC] - aT[prd][intC];
aT[prd][endC] = aT[prd][begC] - aT[prd][prinC];
}

stepSize = aT[loanLife-1][endC]/pow((1 + maxInt), loanLife)/loanLife; 

cout << iter << ". " << aT[loanLife-1][endC] << endl;
}


//*****************************************************************
// Output
//*****************************************************************
cout << endl;
cout << "Required periodic payment: " << prdPmnt << endl;
cout << "Number of iterations needed: " << iter - 1 << endl;
cout << "Remaining balance: ";
cout << aT[loanLife-1][endC] << endl << endl;

printT(aT, loanLife);
cout << endl << endl;

//Wait for the user to read the output on the console
system("PAUSE");
return 0;
}


void printT(double aT[][5], int loanLife)
{
int i, j;

cout << " Year";
cout << " Beg. Bal.";
cout << " Payment";
cout << " Interest";
cout << " Principal";
cout << " End. Bal." << endl;

cout.precision(2);
cout.setf (ios::fixed);
cout.setf(ios::showpoint);

for(i = 0; i < loanLife; i++)
{
cout.width(12);
cout << endl << i+1;

for(j = 0; j <5; j++)
{
cout.width(12);
cout << aT[i][j];
}
 
}
return;
} 





