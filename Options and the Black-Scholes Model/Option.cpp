
//** C++ For Quantitative Finance
//** Option                         
//** Author: David Li 

#include <iostream>
using namespace std;

double termVal(char iType, double strkPr, double termPr);

int main()
{
char iType; // instrument type, c, p, or u (underlying)
double K; // strike price or underlying purchase price
double s; // terminal price of stock or underlying

cout << "Enter instrument type. c for call, p for put, and ";
cout << "u for stock: ";
cin >> iType;

cout << "Enter strike price or stock purchase price: ";
cin >> K;

cout << "Enter terminal price of stock: ";
cin >> s;

cout << "\nTerminal value of position is: ";
cout << termVal(iType, K, s) << endl << endl;

//Wait for the user to read the output on the console
system("PAUSE");
return 0;
}

double termVal(char iType, double strkPr, double termPr)
{
double posVal = 0.;

switch (iType)
{
case 'u':
posVal = termPr - strkPr;
break;

case 'c':
if(termPr > strkPr) posVal = termPr - strkPr;

break;

case 'p':
if(termPr < strkPr) posVal = strkPr - termPr;
break;
}

return posVal;
}
