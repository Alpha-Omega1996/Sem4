#include <iostream>
#include <iomanip>
#include <cstring>

using namespace std;

#define FOUND 0
#define MISSING -1
#define CAPACITY 25
#define FULL -3
#define EMPTY -2
#define NORMAL -4

class book{
	private:
		string author;
		string title;
		string publisher;
		float price;
		int stock;
	public:
		string getname() { return title; }
		string getauth() { return author; }
		int getstock() { return stock; }
		int getprice() { return price; }
		void details();
		book();
		void buy(int);
};

void book::details()
{
	cout<<"\n\tTitle : "<<title;
	cout<<"\n\tAuthor : "<<author;
	cout<<"\n\tPublication : "<<publisher;
	cout<<setprecision(2)<<"\n\tPrice : "<<price;
	cout<<"\n\n\tStock Left : "<<stock;
	if (stock < 20)
		cout<<"\nHurry! Limited copies left..\nBuy it Now!";
	if (stock > 100)
		cout<<"\nQuite an unpopular book.. :(";
	cout<<endl;
}

book::book()
{
	cout<<"\nEnter Book Title: ";
	getline(cin,title);
	cout<<"\nEnter \""<<title<<"\"'s Author: ";
	getline(cin,author);
	cout<<"\nEnter \""<<title<<"\"'s Publisher name: ";
	getline(cin,publisher);
	cout<<"\nEnter \""<<title<<"\"'s Price: ";
	cin>>price;
	cout<<"\nEnter \""<<title<<"\"'s Stock available: ";
	cin>>stock;
	cin.ignore();
}

void book::buy(int copies)
{
	stock -= copies;
}

class library{
	private:
		book *stash[CAPACITY];
		int books;
		int errflag;
		void fillstash();
		void clearstash();
		int search(string, string);
		void display();
		void seek();
		void billout(book&, int);
	public:
		void control();
};

void library::control()
{
	books = 0;
	string command;
	cout<<"\nPress Enter to continue.\n";
	getline(cin,command);
	while (1)
	{
		if ( command.compare("add book") == 0 )
			fillstash();
		else if ( command.compare("del book") == 0 )
			clearstash();
		else if ( command.compare("build") == 0)
			break;
		else if (books == 0)
			cout<<"\n\nSorry, the library is empty. Please report this problem to the librarian!\n\n";
		else
			break;

		if (errflag == FULL)
			cout<<"\n\nCannot add more books, stash full!\n";
		else if (errflag == EMPTY)
			cout<<"\n\nCannot delete more books, stash empty!\n";
		else
			;

		cout<<"Enter command: ";
		getline(cin,command);
	}
	seek();
}

void library::fillstash()
{
	if (books < CAPACITY)
	{
		book *temp = new book();
		stash[books++] = temp;
		errflag = NORMAL;
	}
	else
		errflag = FULL;
}

void library::clearstash()
{
	int pos = -1;
	string auth, name;
	cout<<"\nEnter the Book Name: ";
	getline(cin,name);
	cout<<"\nEnter the Author Name: ";
	getline(cin,auth);
	pos = search(name,auth);
	if (pos == MISSING)
	{
		cout<<"\n\nBook not found!\n";
		errflag = NORMAL;
	}
	else if (pos == EMPTY)
		errflag = EMPTY;
	else
	{
		while(pos <= books - 1)
		{
			if (pos != books-1)
				stash[pos] = stash[pos+1];
			else
				stash[pos] = NULL;
			pos++;
		}
		books--;
		cout<<"\n\nBook Deleted!";
		errflag = NORMAL;
	}
}

int library::search(string name, string auth)
{
	int i = -1, testauth = 0, testname = 0;
	while (++i < books)
	{
		testauth = auth.compare(stash[i]->getauth());
		testname = name.compare(stash[i]->getname());
		if ( testauth == 0 && testname == 0 )
				break;
	}
	if (i == books)
		return MISSING;
	else if (i == -1)
		return EMPTY;
	else
		return i;
}

void library::display()
{
	int i = 0;
	if (books == 0)
		cout<<"\n\nSorry, the library is empty. Please report this problem to the librarian!\n\n";
	while (i < books)
		stash[i++]->details();
}

void library::seek()
{
	int pos = -1, count = 0;
	char op = 'y';
	string auth, name;
	cout<<"\n\nThis program will aid you to Search a book and buy it!.";
	while(op == 'y' || op == 'Y')
	{
		cout<<"\n\nHere is the entire Library:\n";
		display();
		cout<<"\nEnter the Book Name: ";
		getline(cin,name);
		cout<<"\nEnter the Author Name: ";
		getline(cin,auth);
		pos = search(name,auth);

		if (pos == EMPTY)
		{
			cout<<"\n\nSorry, the library is empty. Please report this problem to the librarian!\n\n";
		}
		if (pos == MISSING)
		{
			pos = -1;
			while(++pos < books)
				if (auth.compare(stash[pos]->getauth()) == 0)
					++count;
					if (count != 0)
					{
						cout<<"\nWe do not have the book you want.\nYou may try these books instead: \n";
						for (pos = 0; pos < books; pos++)
						if(auth.compare(stash[pos]->getauth()))
						stash[pos]->details();
					}
					else
						cout<<"\n\nSorry, we do not have the book you want. Please do notify the librarian to place your order for it!\n\n";
		}
		else
		{
			stash[pos]->details();
			cout<<"\nEnter the number of copies you want to buy: ";
			cin>>count;
			billout(*stash[pos], count);
		}
		cout<<"\nLooking for more books? (y/n) :";
		cin>>op;
		cin.ignore();
	}
}

void library::billout(book &favourite, int copies)
{
	int price = favourite.getprice();
	int stock = favourite.getstock();
	char op = '\0';
	if (copies > stock)
	{
		cout<<"\nWoah! You're a fan! We'll sell out our entire stock to you..";
		copies = stock;
	}
	cout<<"\nThe purchase costs: "<<setprecision(2)<<copies*price<<endl;
	cout<<"\nDo you want to buy? (y/n) : ";
	cin>>op;
	cin.ignore();
	if (op == 'y' || op == 'Y')
	{
		favourite.buy(copies);
	}
}

int main()
{
	library run;
	run.control();
	return 0;
}
