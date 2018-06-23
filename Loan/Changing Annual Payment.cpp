//** C++ For Quantitative Finance
//** Loan Calculation (Changing Annual Payment)


#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

void printT(double aT[][5], int );

int main()
{
int jumpPrd1, jumpPrd2, loanLife, prd, iter, i, j;
double intRate, jumpSize1, jumpSize2;
double loanAmnt, initPmnt, prdPmnt, stepSize, tolerance;
const int maxPrds = 50;
double aT[maxPrds][5]; // amortization table

int begC = 0; // column number for period beginning balance
int pmntC = 1; // column number for constant periodic payments
int intC = 2; // column number for interest component
int prinC = 3; // column number for principal component
int endC = 4; // column number for period ending balance

			for (int i = 1; i <= 5; i++)
		{
			cout << "Enter periodic interest rate in decimal: ";
			cin >> intRate;

			if ((intRate < 0.0) || (intRate > 0.15))
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
			cout << "Enter periodic jumpSize1 in decimal: ";
			cin >> jumpSize1;

			if ((jumpSize1 < 0.0) || (jumpSize1 > 0.3))
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
					cout << "0.0 and 0.3. Please try again." << endl;
				}

			}
			else { break; }

		}
		
		
						for (int i = 1; i <= 5; i++)
		{
			cout << "Enter periodic jumpSize2 in decimal: ";
			cin >> jumpSize2;

			if ((jumpSize2 < 0.0) || (jumpSize2 > 0.3))
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
					cout << "0.0 and 0.3. Please try again." << endl;
				}

			}
			else { break; }

		}	
		
		
		
			for (int i = 1; i <= 5; i++)
		{
			cout << "Enter loanlife in periods: ";
			cin >> loanLife;

			if ((loanLife < 0) || (loanLife > 50))
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
		
		
		
	for(i=0; i<maxPrds; i++) for(j=0; j<5; j++) aT[i][j] = 0.;
    aT[loanLife -1][endC] = 1000.;

    stepSize = 0.; // initial value
    initPmnt = (loanAmnt*intRate)/(1+jumpSize1)/(1+jumpSize2);	
		

//*****************************************************************
// Iteration to determine required periodic payment
//*****************************************************************
for(iter = 1; aT[loanLife -1][endC] >= tolerance; iter++)
{
initPmnt += stepSize;
aT[0][begC] = loanAmnt;

for(prd = 0; prd < loanLife; prd++)
{
if (prd != 0) aT[prd][begC] = aT[prd -1][endC];

prdPmnt = initPmnt;
if(prd > jumpPrd1-2) prdPmnt = initPmnt * (1 + jumpSize1);
if(prd > jumpPrd2-2) prdPmnt = initPmnt * (1 + jumpSize1)*
(1 + jumpSize2);

aT[prd][pmntC] = prdPmnt;

aT[prd][intC] = aT[prd][begC] * intRate;
aT[prd][prinC] = aT[prd][pmntC] - aT[prd][intC];
aT[prd][endC] = aT[prd][begC] - aT[prd][prinC];
}

stepSize = aT[loanLife-1][endC]/pow((1 + intRate), loanLife)/loanLife /(1+jumpSize1)/(1+jumpSize2);
cout << iter << ". " << aT[loanLife-1][endC] << endl;
}

//*****************************************************************
// Output
//*****************************************************************
cout << endl;
cout << "Number of iterations needed: " << iter - 1 << endl;
cout << "Remaining balance: ";
		

 cout << aT[loanLife-1][endC] << endl << endl;

 printT(aT, loanLife);
 cout << endl <<endl;

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
		
		
		
