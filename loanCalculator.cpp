#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
using namespace std;

int main()
{
	string name, institution, date;
	double loanAmount, air, term;

	cout << "Loan Payment Calculator ..." << endl << endl << "Please enter the following information" << endl << endl;
	
	//Ask for borrower's name, and the loaning institution
	cout << "Borrower's Name:		";
	getline(cin, name);
	cout << "Loaning Institution:		";
	cin.ignore();
	getline(cin, institution);

	//Get the loan amount
	cout << endl << "Loan Amount ($):		";
	cin >> loanAmount;

	//get the annual interest rate 
	cout << "Annual Interest Rate (%):	";
	cin >> air;

	//Get the term of loan in years
	cout << "Term of Loan (years):		";
	cin >> term;

	//Ask for Date of report
	cout << endl << "Date of Report:			";
	cin >> date;
	
	//beginning of loan payment summary report
	cout << "\n\n-----------------------------------------------------\n" << "Loan Payment Summary Report" << endl << endl;
	
	//formulas 
	double monthlyInterestRate = air / 1200;
	double numberOfPayments = term * 12;
	double rate = air / 12 / 100;
	double monthlyPayment = (((rate) * pow((1 + rate), numberOfPayments)) * loanAmount / (pow((1 + rate), numberOfPayments) - 1));
	double totalAmount = monthlyPayment * numberOfPayments;
	double totalInterest = totalAmount - loanAmount;

	cout << fixed << setprecision(2);

	//show results
	cout << left << setw(37) << institution << name << endl
		<< "Annual Interest Rate: " << air << "%" << endl
		<< "Date: " << date << " 2022" << endl << endl;

	// Display results of calculations
	cout << left << setw(40) << "Loan Amount:" << "$" << right << setw(12) << showpoint << loanAmount << endl;
	cout << left << setw(40) << "Monthly Interest Rate:" << right << setw(12) << monthlyInterestRate * 100 << "%" << endl;
	cout << left << setw(40) << "Number of Payments:" << right << setw(13) << setprecision(0) << numberOfPayments << endl;
	cout << left << setw(40) << "Monthly Payment:" << "$" << right << setw(12) << setprecision(2) << fixed << monthlyPayment << endl << endl;
	cout << left << setw(40) << "Total Amount to Pay:" << "$" << right << setw(12) << totalAmount << endl;
	cout << left << setw(40) << "Total Interest:" << "$" << right << setw(12) << totalInterest;

	//end of loan payment summary report
	cout << "\n\n-----------------------------------------------------\n" << "Loan Payment Summary Report";

	return 0;

}
