#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

int main() {

ifstream indata;
ofstream outdata;

indata.open("sampleinput.txt");
outdata.open("output.txt");

string lastName, firstName; 
double salary;
double percent; 
double pre_commission;
double expenses;


indata >> firstName >> lastName;
indata >> salary;
indata >> percent;
indata >> pre_commission;
indata >> expenses; 

//

double commission = pre_commission * percent / 100;
double total_pay = salary + commission + expenses;

// Used set precision to set maximum for decimal place (hundredths).

outdata << setprecision(2) << fixed;

// Using set width to align dollar values properly.

outdata << "Payroll data for " << firstName << " " << lastName << endl;
outdata << left << setw(15) << "Base Salary: " << right << setw(15) << salary << endl;

// Used setprecision(1) to adjust percent from hundredths to tenths (3.25 -> 3.2), then used setprecision(2) for everything else that's dollar value.

outdata << left << setw(15) << "Commission: " << right << setw(15) << commission << "(" << setprecision(1)<< percent << "% of " << setprecision(2) << pre_commission << ")" << endl;
outdata << left << setw(15) << "Expenses: " << right << setw(15) << expenses << endl;
outdata << right << setw(30) << "--------" << endl;
outdata << left << setw(15) << "Total: " << right << setw(15) << total_pay << endl;

indata.close();

}
