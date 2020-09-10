#pragma once
#include<string>
using namespace std;
class ATM
{
private:
	string  client_name;
	double account_value;
	int account_pin, account_password;
public:

	ATM();
	~ATM();
	void setaccount(string, double);
	void findaccount(int,double&,string&);
	void printaccountinfo();
	void draw(double);
	void tranform(string, int, double);
	void addmoney(double);

};

