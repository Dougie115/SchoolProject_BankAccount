//libraries
#include <iostream>
using namespace std;

//classdeclarationdefention
class BankAccount
{
public:
	int accountNumber;
	double Balance;
	

public :BankAccount(int Accno, double Bal)
	{
		accountNumber = Accno;
		Balance = Bal;
	}
	

public:
	double getBal()
	{
		return(Balance);
	}
	int getAccNo()
	{
		return(accountNumber);
	}
	void setBal(double amount)
	{
		Balance = amount;
	}
	void setAccNo(int Accno)
	{
		accountNumber = Accno;
	}


	//account information section 
	void virtual showAccI()
	{
		cout << " ---------------------------------" << endl;
		cout << " ||        Account Info           " << endl;
		cout << " ---------------------------------" << endl;
		cout << " || Account Number :" << accountNumber << endl;
		cout << " || Account Balance:" << Balance << endl;
		cout << " ---------------------------------" << endl;
		cout << endl;
	}

	double virtual depAmnt(double dAmnt)
	{
		Balance = Balance + dAmnt;
		return(Balance);
	}

	double virtual wdrawAmnt(double wAmnt)
	{
		Balance = Balance - wAmnt;
		return(Balance);
	}
};


//This is the Checking account class
class CheckingAccount : BankAccount
{
	double Intrst;
	double minBal;
	

public:
	CheckingAccount(int pAccno, double pAmnt, double pIntrst) :BankAccount(pAccno, pAmnt)
	{
		Intrst = pIntrst;
		minBal = 500;//normal start formost banks
	}

	void setIntRate(double intRate)
	{
		Intrst = intRate;
	}

	double retIntRate()
	{
		return(Intrst);
	}

	void setMinBal(double mBal)
	{
		minBal = mBal;
	}

	double retMinBal()
	{
		return(minBal);
	}
	
	double depAmnt(double dAmnt)
	{
		Balance = Balance + dAmnt;
		return(Balance);
	}

	double wdrawAmnt(double wAmnt)
	{
		if (wAmnt <= Balance)
			Balance = Balance - wAmnt;
		else
			cout << "You have insufficient funds!" << endl;
		return(Balance);
	}

	void showAccI()
	{
		cout << " ---------------------------------" << endl;
		cout << " ||        Account Info           " << endl;
		cout << " ---------------------------------" << endl;
		cout << " || Account Number :" << accountNumber << endl;
		cout << " || Account Balance: $" << Balance << endl;
		cout << " ---------------------------------" << endl;
		cout << endl;
	}
};
//This is the Saving Account Class
class SavingAccount :BankAccount
{
	double minBal;
public:
	SavingAccount(int pAccno, double pAmnt) :BankAccount(pAccno, pAmnt)
	{
		minBal = 500;
	}
	double depAmnt(double dAmnt)
	{
		Balance = Balance + dAmnt;
		return(Balance);
	}
	double wdrawAmnt(double wAmnt)
	{
		if (wAmnt <= Balance)
			Balance = Balance - wAmnt;
		else
			cout << "You have in sufficient funds!\n" << endl;
		return(Balance);
	}
	void setMinBal(double mBal)
	{
		minBal = mBal;
	}
	void showAccI()
	{
		cout << endl;
		cout << " ---------------------------------" << endl;
		cout << " ||        Account Info           " << endl;
		cout << " ---------------------------------" << endl;
		cout << " || Account Number :" << accountNumber << endl;
		cout << " || Account Balance: $" << Balance << endl;
		cout << " ---------------------------------" << endl;
		cout << endl;
	}
};


//main function
int main()
{
	double amount;
	int choice;
	do
	{
		//Description Header
		cout << "================================================" << endl;
		cout << "BankAccount Inheritance " << endl;
		cout << "Long Beach City College" << endl;
		cout << "Douglas Lopez" << endl;
		cout << "March 24 2018" << endl;
		cout << "================================================" << endl;


		//Output
		cout << endl;
		cout << "       Create an Account      " << endl;
		cout << " *****************************" << endl;
		cout << " ** 1 - Checking Account   **" << endl;
		cout << " ** 2 - Saving Account     **" << endl;
		cout << " ** 3 - Exit               **" << endl;
		cout << " *****************************" << endl;
		cin >> choice;
		cout << endl;


		//functiondefenition
		if (choice == 1)
		{
			int Accno;
			double newBal;
			double intRate;
			int accChoice;

			cout << "Enter account number: " << endl;
			cin >> Accno;
			cout << "Enter opening balance: " << endl << "$";
			cin >> newBal;
			cout << "Enter interest rate: " << endl;
			cin >> intRate;
			
			CheckingAccount obj(Accno, newBal, intRate);
			do
			{
				cout << endl;
				cout << " *************************" << endl;
				cout << " ** 1 - Deposit      $+ **" << endl;
				cout << " ** 2 - Withdraw     $- **" << endl;
				cout << " ** 3 - Account Info $? **" << endl;
				cout << " ** 4 - Exit            **" << endl;
				cout << " *************************" << endl;
				cin >> accChoice;
				cout << endl;

				//Depending on the case the result is different
				switch (accChoice)
				{

				case 1:
					cout << "Enter amount:" << endl << "$";
					cin >> amount;
					double dAmnt;
					cout << endl;
					dAmnt = obj.depAmnt(amount);
					cout << "Available balance: $" << dAmnt << endl;
					break;

				case 2:
					cout << "Enter amount:" << endl << "$";
					cin >> amount;
					double wAmnt;
					cout << endl;
					wAmnt = obj.wdrawAmnt(amount);
					cout << "Available balance: $" << wAmnt << endl;
					break;

				case 3:
					obj.showAccI();
					break;

				default:
					cout << "Invalid choice!" << endl;
					break;

				}
			}

			while (accChoice != 4);
		}

		else if (choice == 2)
		{
			double pnewBal;
			int pAccno;
			double _irate;
			int pChoice;

			cout << "Enter account number: " << endl;
			cin >> pAccno;

			cout << "Enter opening balance:" << endl <<"$";
			cin >> pnewBal;
			
			cout << "Enter interest rate:" << endl;
			cin >> _irate;

			SavingAccount sObj(pAccno, pnewBal);
			
			do
			{
				cout << endl;
				cout << " *************************" << endl;
				cout << " ** 1 - Deposit      $+ **" << endl;
				cout << " ** 2 - Withdraw     $- **" << endl;
				cout << " ** 3 - Account Info $? **" << endl;
				cout << " ** 4 - Exit            **" << endl;
				cout << " *************************" << endl;
				cin >> pChoice;
				cout << endl;
				switch (pChoice)
				{
				case 1:
					cout << "Enter amount:" << endl <<"$";
					cin >> amount;
					double _dAmnt;
					_dAmnt = sObj.depAmnt(amount);
					cout << "Available balance: $" << _dAmnt<<endl;
					break;

				case 2:
					cout << "Enter amount:" << endl<<"$";
					cin >> amount;
					double _wamount;
					_wamount = sObj.wdrawAmnt(amount);
					cout << "Available balance: $" << _wamount <<endl;
					break;

				case 3:
					sObj.showAccI();
					break;

				case 4:
					break;

				default:
					cout << "Invalid choice!" << endl;
					break;
				}
			} 
			while (pChoice != 4);
		}
	} 
	while (choice != 3);
}