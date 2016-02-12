//Database of personal items
//info: all taken!
//use new&delete, static&normal (use this ptr too)mem func.

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

#define VALID 5
#define INVALID 0

class help;

class person
{
	private:
		string name;
		string blood;		//check this
		string address;
		string drivinglicno;
		string telno;		//check this
		string DoB;		//check this
		long policyno;
		float height;
		float weight;
		person *next;
	public:
		person();
		person(person &);
		~person();
		
	friend help;
};

person::person()
{
	string temp;
	string::sizetype st;

	cout<<"Enter your Name.\n >";
	getline(cin,name);

	cout<<"Enter your Date of Birth (use -, example: 1-1-1000).\n >";
	getline(cin,temp);
	help::checkdate(*this,temp);			//checks and corrects errors
	DoB = temp;

	cout<<"Enter your Address.\n >";
	getline(cin,address);

	cout<<"Enter your Telephone number.\n >";
	getline(cin,temp);
	help::checktelno(*this,temp);			//checks and corrects errors
	telno = temp;

	cout<<"Enter your Blood Group.\n >";
	getline(cin,temp);
	help::checkblood(*this,temp);			//checks and corrects errors
	blood = temp;

	while (1)
	{
		cout<<"Enter your Height in cm.\n >";
		cin>>height;
		if (height > 0)
			break;
		else
		{
			cout<<"Please, PLEASE enter the right height!! (it's positive ya know..)";
		}
	}

	while (1)
	{
		cout<<"Enter your Weight in kgs.\n >";
		cin>>weight;
		if (weight > 0)
			break;
		else
		{
			cout<<"Please, PLEASE enter the right weight!! (it's positive ya know..)";
		}
	}

	cout<<"Enter your Insurance number.\n >";
	cin.ignore();
	getline(cin,policyno);

	cout<<"Enter your Driving Licence number.\n >";
	getline(cin,drivinglicno);
}

person::person(person &b)
{
	help::copy(*this, b);
}

person()::~person()
{
	name = address = telno = blood = policyno = drivinglicno = NULL;
	height = weight = 0;
	next = NULL;
}

class help
{
	public:
		static void checkdate(person &guy, string &date)
		{
			int count = 0, err = -1;
			while(1)
			{
				;
			}
		}
		static void checkblood(person &guy, string &type)
		{
			while(1)
			{
				if (type.length() > 2)
				{
					switch(type)
					{}
				}
			}
		}
		static void checktelno(person &guy, person &number)
		{
		}
		static void copy(person &destination, person &source)
		{
		}
};
