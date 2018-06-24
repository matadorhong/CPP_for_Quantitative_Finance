/* C++ For Quantitative Finance           */
/* Options Portfolio Profit at Expiration */                  
/* Author: David Li                       */

#include <iostream>
using namespace std;

double termVal(char iType, double strkPr, double termPr);

int main() {
const int maxPos = 50;       /* maximum number of different positions   */
char iType[maxPos];         /* instrument type, c, p, or u (underlying) */
double aPos[maxPos][3];     /* col 0 number of contracts                */

/* col 1 strike or stock purchase price*/
/* col 2 option premium or 0 for stock */
 
double s;                /* terminal price of stock or underlying */
double portVal = 0.;     /* terminal portfolio value              */
double contSize = 100;   /* contract size, e.g., 100 for stocks    */

int i, j, numPos;
char more;

/*****************************************************************/
/* User Inputs                                                   */
/*****************************************************************/
for( i = 0; i < maxPos; i++) for(j = 0; j < 3; j++)
aPos[i][j] = 0.;

for(i = 0; i < 50; i++)
{
cout << "Enter instrument type. c for call, p for put, and ";
cout << "u for stock: ";
cin >> iType[i];

cout << "Enter number of contracts (negative for short): ";
cin >> aPos[i][0];

cout << "Enter strike price or stock purchase price: ";
cin >> aPos[i][1];

cout << "Enter premium paid/received. ";
cout << " Enter 0 for positions in the stock: ";
cin >> aPos[i][2];
if (aPos[i][2] < 0) aPos[i][2] = -aPos[i][2];
if (iType[i] == 'u') aPos[i][2] = 0.;

cout << "Enter Y to add more positions, anything else to end: ";
cin >> more;
if((more != 'y') && (more != 'Y')) break;
cout << endl;
}

cout << "\nEnter terminal price of stock: ";
cin >> s;

/*****************************************************************/
/* Calculate terminal value at option expiration                 */
/*****************************************************************/
numPos = i + 1;

for(i = 0; i < numPos; i++) {
portVal += aPos[i][0]*(termVal(iType[i], aPos[i][1], s) - aPos[i][2]) * contSize; }

cout << "\nProfit on portfolio at option expiration will be: ";
cout << portVal<< endl << endl;


/*     Wait for the user to read the output on the console   */
system("PAUSE");
return 0; }

double termVal(char iType, double strkPr, double termPr) {

double posVal = 0.;
switch (iType) {
case 'u':
posVal = termPr - strkPr;
break;

case 'c':
if(termPr > strkPr) posVal = termPr - strkPr;
break;

case 'p':
if(termPr < strkPr) posVal = strkPr - termPr;
break; }

return posVal; }
