#include "ATM.h"
#include<iostream>
#include<string>
#include<fstream>
#include<cstdlib>
#include<cstring>
#include<ctime>
#include<conio.h>
using namespace std;

ATM::ATM() :client_name(" "), account_password(0), account_pin(0), account_value(0)
{
	cout << "\n\n";
	cout << "\t\t================================================================" << endl;
	cout << "\t\t= *            *  ****  *     *****   ****   **     **  ****   =" << endl;
	cout << "\t\t=  *          *   *     *     *      *    *  * *   * *  *      =" << endl;
	cout << "\t\t=   *   **   *    ****  *     *      *    *  *  * *  *  ****   =" << endl;
	cout << "\t\t=    * *  * *     *     *     *      *    *  *   *   *  *      =" << endl;
	cout << "\t\t=     *    *      ****  ****  *****   ****   *       *  ****   =" << endl;
	cout << "\t\t= *****  ****    ***** *    * ****      *     ***** **     **  =" << endl;
	cout << "\t\t=   *   *    *     *   *    * *        * *      *   * *   * *  =" << endl;
	cout << "\t\t=   *   *    *     *   ****** ****    *****     *   *  * *  *  =" << endl;
	cout << "\t\t=   *   *    *     *   *    * *      *     *    *   *   *   *  =" << endl;
	cout << "\t\t=   *    ****      *   *    * ****  *       *   *   *       *  =" << endl;
	cout << "\t\t=                                                              =" << endl;
	cout << "\t\t================================================================" << endl;

	cout << "\n\n\t\tPlease follow the instruction to have a better experience ..";
	_getch();
};

ATM::~ATM()
{
	system("cls");
	fstream file;
	string filename;
	filename = to_string(account_pin);
	filename = filename + ".txt";
	//cout << client_name << endl << account_value << endl << account_pin << endl << account_password << endl;
	file.open(filename.c_str(), ios::out | ios::trunc);
	file << client_name << endl << account_value << endl << account_pin << endl << account_password << endl;
	cout << "\n\n\n\n\n\n\n\t\t_____________________________________________"<<endl;
	cout << "\n\t\tWe hope you had a pleasent experience ." << endl;
	cout << "\n\t\tThis program was made by SE\\Abdullah Adime .";
	_getch();
	cout << "\n\n\n\n\n\n\n";
}

void ATM::setaccount(string name, double money )
{
	int pass;
	client_name = name;
	account_value = money;
	fstream file;
	string filename;
	srand(time(0));
	account_pin = rand() % 99999 + 99990;
	cout <<"\n\t\tYour new account pin number is :"<< account_pin << endl;
	cout << "\n\t\tPlease enter a new password for your account :" << endl;
	cout << "\n\t\tNOTE!:It must be numbers and not higher than four(4) digits..:";
	cin >> account_password;
	while (account_password > 9999)
	{
		system("cls");
		cout << "\t\tThe password input is wrong ..." << endl;
		cout << "\t\tPlease enter your password again." << endl;
		cout << "\t\tNOTE!:It must be numbers and not higher than four(4) digits..\n\t\t" ;
		cin >> account_password;

	};
	filename = to_string(account_pin);
	filename = filename + ".txt";
	file.open(filename.c_str(), ios::out);
	file << client_name << endl << account_value << endl << account_pin << endl << account_password << endl;
	cout << "\n\n\n\t\tYour account information was seccessfully saved..!!";
	_getch();
	
	//cout << client_name << account_value << account_pin << account_password;

}

void ATM::findaccount(int pin,double& money, string &name)
{
	system("cls");
	ifstream file;
	string filename;
	int tempassword;
	filename = to_string(pin);
	filename = filename + ".txt";
	file.open(filename.c_str());
	while (!file) {
		system("cls");
		cout << "\n\n\t\tThere is no account with this pin nummber . Try again :" << endl;
		cout << "\n\t\tIf you want to exit click 0.." << endl;
		cin >> pin;
		filename = to_string(pin);
		filename = filename + ".txt";
		file.open(filename.c_str());
		if (pin == 0)
		{
			exit(0);
		}
	}
	
		getline(file, client_name);
		file >> account_value >> account_pin >> account_password;
		system("cls");
	cout << "\n\t\tPlease enter your account password:";
	cin >> tempassword;
	while (tempassword != account_password)
	{
		cout << "\n\t\tthe password was wrong please try again." << endl;
		cout << "\n\t\tIf you want to exit click 0 .." << endl;
		cin >> tempassword;
		if (tempassword == 0)
			exit(0);
	}
	//cout << client_name << account_value << account_pin << account_password;
	name = client_name;
	money = account_value;

}
void ATM::printaccountinfo()
{
	system("cls");
	cout << "\n\t\t      account information.                ";
	cout <<"\n\t\t============================================\n" << endl;
	cout << "\t\tclient name :" << client_name << endl;
	cout << "\n\t\taccount pin number : " << account_pin << endl;
	cout << "\n\t\taccount value :"<<account_value <<"RY"<< endl;
	cout << "\n\t\t============================================\n" << endl;
	cout << "\n\t\tpress any key to continue..!!";
	_getch();
	
}
void ATM::draw(double money)
{
	system("cls");
	if (money > account_value)
	{
		cout << "\n\n\t\tsorry the account balance cant afford this draw please try again." << endl;

	}
	else if (money <= account_value)
	{
		account_value = account_value - money;
		cout << "\n\t\tyour draw was seccessful please take the money." << endl;
		
	}
	_getch();
}
void ATM::tranform(string name,int phonenum, double money)
{
	system("cls");
	
	if (money > account_value)
	{
		cout << "\n\n\t\tyour account value cant afford this transnition." << endl;
		
	}
	else if (money <= account_value)
	{
		account_value = account_value - money;
		cout << "\n\t\t========================" << endl;
		cout << "\n\t\treceptor name: " << name << endl;
		cout << "\n\t\tthe receptor phone number: " << phonenum << endl;
		cout << "\n\t\tthe amount of money tranformeted : " << money<< "RY" << endl;
		cout << "\n\t\tpress any key to continue..";
		
	}
	_getch();
	//cout << client_name << account_value << account_pin << account_password;

}
void ATM::addmoney(double money)
{
	system("cls");
	account_value = account_value + money;
	cout << "\n\n\t\tthe money was seccessfully add to your account ." << endl;
	cout << "\n\t\tpress any key to continue..";
	_getch();
	//cout << client_name << account_value << account_pin << account_password;

}




