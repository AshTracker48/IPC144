/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #2 (P2)
Full Name  :AYUSHKUMAR VIPULBHAI PATEL
Student ID#:114473226
Email      :apatel574@myseneca.ca
Section    :G
Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void)
{
    const double TAX = 0.13;
    const char patSize = 'S', salSize = 'M', tomSize = 'L';

    double s = 17.96;
    double m = 26.96;
    double l = 35.97;

    int iP = 6;
    int iT = 3;
    int iS = 4;

    double stP = iP * s;
    double stT = iT * l;
    double stS = iS * m;

    double taxP = TAX * stP;
    double taxT = TAX * stT;
    double taxS = TAX * stS;

    double totalP = stP + taxP;
    double totalT = stT + taxT;
    double totalS = stS + taxS;

    double sttotal = stP + stT + stS;
    double taxtotal = taxP + taxT + taxS;
    double totaltotal = totalP + totalT + totalS;


    printf("Set Shirt Prices\n");
    printf("================\n");


    printf("Enter the price for a SMALL shirt: $%.2lf\n", s);
    printf("Enter the price for a MEDIUM shirt: $%.2lf\n", m);
    printf("Enter the price for a LARGE shirt: $%.2lf\n\n", l);


    printf("Shirt Store Price List\n");
    printf("======================\n");
    printf("SMALL  : $%.2lf\n", s);
    printf("MEDIUM : $%.2lf\n", m);
    printf("LARGE  : $%.2lf\n\n", l);



    printf("Patty's shirt size is '%c'\n", patSize);
    printf("Number of shirts Patty is buying: %d\n\n", iP);

    printf("Tommy's shirt size is '%c'\n", tomSize);
    printf("Number of shirts Tommy is buying: %d\n\n", iT);

    printf("Sally's shirt size is '%c'\n", salSize);
    printf("Number of shirts Sally is buying: %d\n\n", iS);

    printf("Customer Size Price Qty Sub-Total       Tax     Total\n");
    printf("-------- ---- ----- --- --------- --------- ---------\n");
    printf("Patty %4c    %.2lf %3d  %.4lf   %.2lf00  %.2lf00\n", patSize, s, iP, stP, taxP, totalP);
    printf("Sally %4c    %.2lf %3d  %.4lf   %.2lf00  %.2lf00\n", salSize, m, iS, stS, taxS, totalS);
    printf("Tommy %4c    %.2lf %3d  %.4lf   %.2lf00  %.2lf00\n", tomSize, l, iT, stT, taxT, totalT);
    printf("-------- ---- ----- --- --------- --------- ---------\n");
    printf("                         %.4lf   %.2lf00  %.2lf00\n\n", sttotal, taxtotal, totaltotal);

    double toonieprice = 2;
    double loonieprice = 1;
    double quarterprice = 0.25;
    double dimeprice = 0.1;
    double nickelprice = 0.05;
    double pennyprice = 0.01;


    int toonies = 161;
    int loonies = 1;
    int quarters = 2;
    int dimes = 0;
    int nickels = 0;
    int pennies = 1;

    double balance = 323.5100;
    int a = 32351 % 161;
    double dbl = (double)a;
    double tbalance = dbl / 100;

    double lbalance = tbalance - (loonies * loonieprice);
    double qbalance = lbalance - (quarters * quarterprice);
    double dbalance = qbalance - (dimes * dimeprice);
    double nbalance = dbalance - (nickels * nickelprice);
    double pbalance = nbalance - (pennies * pennyprice);

    printf("Daily retail sales represented by coins\n");
    printf("=======================================\n\n");

    printf("Sales EXCLUDING tax\n");
    printf("Coin     Qty   Balance\n");
    printf("-------- --- ---------\n");
    printf("              %.4lf\n", balance);

    printf("Toonies  %d    %.4lf\n", toonies, tbalance);
    printf("Loonies    %d    %.4lf\n", loonies,   lbalance);
    printf("Quarters   %d    %.4lf\n", quarters,   qbalance);
    printf("Dimes      %d    %.4lf\n", dimes,   dbalance);
    printf("Nickels    %d    %.4lf\n", nickels,   nbalance);
    printf("Pennies    %d    %.4lf\n\n", pennies,  pbalance);

    double avgcost = balance / (iP + iT + iS);

    printf("Average cost/shirt: $%.4lf\n\n", avgcost);

    double balance2 = 365.5700;

    int toonies2 = 182;
    int loonies2 = 1;
    int quarters2 = 2;
    int dimes2 = 0;
    int nickels2 = 1;
    int pennies2 = 2;

    double tbalance2 = balance2  - (toonies2 * toonieprice);
    double lbalance2 = tbalance2 - (loonies2 * loonieprice);
    double qbalance2 = lbalance2 - (quarters2 * quarterprice);
    double dbalance2 = qbalance2 - (dimes2 * dimeprice);
    double nbalance2 = dbalance2 - (nickels2 * nickelprice);
    double pbalance2 = nbalance2 - (pennies2 * pennyprice);

    printf("Sales INCLUDING tax\n");
    printf("Coin     Qty   Balance\n");
    printf("-------- --- ---------\n");
    printf("              %.2lf00\n", balance2);

    printf("Toonies  %d    %.4lf\n", toonies2, tbalance2);
    printf("Loonies    %d    %.4lf\n", loonies2, lbalance2);
    printf("Quarters   %d    %.4lf\n", quarters2, qbalance2);
    printf("Dimes      %d    %.4lf\n", dimes2, dbalance2);
    printf("Nickels    %d    %.4lf\n", nickels2, nbalance2);
    printf("Pennies    %d    %.4lf\n\n", pennies2, (pbalance2 * -1));

    double avgcost2 = balance2 / (iP + iT + iS);

    printf("Average cost/shirt: $%.4lf\n\n", avgcost2);

    return 0;
}
