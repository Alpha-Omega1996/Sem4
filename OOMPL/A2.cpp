#include <iostream>
#include <iomanip>
#include <cstring>

using namespace std;

#define MAXSIZE 100
#define FOUND 0
#define MISSING -1
#define CAPACITY 25
#define FULL -3
#define EMPTY -2
#define NORMAL -4

class book{
	friend void init(book &, char [MAXSIZE], char [MAXSIZE], char [MAXSIZE], float, int);
	private:
		char author[MAXSIZE];
		char title[MAXSIZE];
		char publisher[MAXSIZE];
		float price;
		int stock;
	public:
		char * getname() { return title; }
		char * getauth() { return author; }
		int getstock() { return stock; }
		int getprice() { return price; }
		void details();
		book(int);
		void buy(int);
};

void init(book &empty, char auth[MAXSIZE] , char name[MAXSIZE], char pub[MAXSIZE], float cost, int quantity)
{
	strcpy(empty.author, auth);
	strcpy(empty.title, name);
	strcpy(empty.publisher, pub);
	empty.price = cost;
	empty.stock = quantity;
}

void book::details()
{
	cout<<"\n\tTitle : "<<title;
	cout<<"\n\tAuthor : "<<author;
	cout<<"\n\tPublication : "<<publisher;
	cout<<fixed<<setprecision(2)<<"\n\tPrice : "<<price;
	cout<<"\n\tStock Left : "<<stock<<endl;
	if (stock == 0)
		cout<<"\nALL SOLD OUT!!"<<endl;
	if (stock < 20)
		cout<<"\nHurry! Limited copies left..\nBuy it Now!"<<endl;
	if (stock > 2000)
		cout<<"\nQuite an unpopular book.. :("<<endl;
}

book::book(int real = 0)
{
	if (real)
	{
		cout<<"\nEnter Book Title: ";
		cin.getline(title, MAXSIZE);
		cout<<"\nEnter \""<<title<<"\"'s Author: ";
		cin.getline(author, MAXSIZE);
		cout<<"\nEnter \""<<title<<"\"'s Publisher name: ";
		cin.getline(publisher, MAXSIZE);
		cout<<"\nEnter \""<<title<<"\"'s Price: ";
		cin>>price;
		cout<<"\nEnter \""<<title<<"\"'s Stock available: ";
		cin>>stock;
		cin.ignore();
	}
}

void book::buy(int copies)
{
	stock -= copies;
}

class library{
	private:
		book *stash[CAPACITY + 5];
		int books;
		int errflag;
		void setup();
		void fillstash();
		void clearstash();
		int search(char *, char *);
		void display();
		void seek();
		void billout(book&, int);
	public:
		void control();
};

void library::control()
{
	books = 0;
	int choice = 0;
	setup();
	char command[MAXSIZE];
	cout<<"\nPress Enter to continue.\n";
	cin.getline(command, MAXSIZE);
	while (1)
	{
		//parsing entered commands (if any)
		if (books == 0)
		{
			cout<<"\n\nSorry, the library is empty. Please report this problem to the librarian!\n\n";
			choice = 0;
		}
		else if ( strcmp(command,"build") == 0 )
			break;
		else if ( choice == 1 || strcmp(command,"add book") == 0 )
		{
			fillstash();
			choice = 1;
		}
		else if ( choice == 2 || strcmp(command,"del book") == 0 )
		{
			clearstash();
			choice = 2;
		}
		else
			;

		//parsing errors due to commands (if any)
		if (errflag == FULL)
			cout<<"\n\nCannot add more books, stash full!\n";
		else if (errflag == EMPTY)
			cout<<"\n\nCannot delete more books, stash empty!\n";
		else
			;
			
		//If the command is auto repeated (choice = 1 or 2) or User mode is asked
		if (strlen(command) != 0 || choice != 0)
		{
			cout<<command;
			cout<<"Enter command: ";
			cin.getline(command, MAXSIZE);
		}
		else
			break;
	}
	seek();
}

void library::setup()
{
	books = 5;
	for (int i = 0; i < CAPACITY ; i++)
		stash[i] = new book(0);
	init(*stash[0], "Leo Tolstoy", "War and Peace", "The Russian Messenger", 650, 883);
	init(*stash[1], "Mark Twain", "The Adventures of Huckleberry Finn", "Penguin Classics", 159, 1034);
	init(*stash[2], "Leo Tolstoy", "Anna Karenina", "Barnes & Noble Classics", 244, 1325);
	init(*stash[3], "Jonathan Swift", "Gulliver's Travels", "Dover Thrift Editions", 119, 1503);
	init(*stash[4], "Charles Dickens", "David Copperfield", "Penguin Classics", 189, 4869);
}

void library::fillstash()
{
	if (books < CAPACITY)
	{
		book *temp = new book(1);
		stash[books++] = temp;
		errflag = NORMAL;
	}
	else
		errflag = FULL;
}

void library::clearstash()
{
	int pos = -1;
	char auth[MAXSIZE], name[MAXSIZE];
	cout<<"\nEnter the Book Name: ";
	cin.getline(name, MAXSIZE);
	cout<<"\nEnter the Author Name: ";
	cin.getline(auth, MAXSIZE);
	pos = search(name,auth);
	if (pos == MISSING)
		cout<<"\n\nBook not found!\n";
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
		cout<<"\nBook Deleted!\n";
		errflag = NORMAL;
	}
}

int library::search(char name[MAXSIZE], char auth[MAXSIZE])
{
	int i = -1, testauth = 0, testname = 0;
	while (++i < books)
	{
		testauth = strcmp(auth,stash[i]->getauth());
		testname = strcmp(name, stash[i]->getname());
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
	{
		if (i != 0 && (i+1) % 3 == 0)
		{
			cout<<"\nPress enter to continue..";
			cin.get();
		}
		stash[i++]->details();
	}
}

void library::seek()
{
	int pos = -1, count = 0;
	char op = 'y';
	char auth[MAXSIZE], name[MAXSIZE];
	cout<<"\n\nThis program will aid you to Search a book and buy it!.";
	while(1)
	{
		cout<<"\n\nHere is the entire Library:\n";
		display();
		cout<<"\nEnter the Book Name: ";
		cin.getline(name, MAXSIZE);
		cout<<"\nEnter the Author Name: ";
		cin.getline(auth, MAXSIZE);
		pos = search(name,auth);
		if (pos == EMPTY)
		{
			cout<<"\n\nSorry, the library is empty. Please report this problem to the librarian!\n\n";
		}
		if (pos == MISSING)
		{
			pos = -1;
			while(++pos < books)
				if (strcmp(auth,stash[pos]->getauth()) == 0)
					++count;
			if (count != 0)
			{
				cout<<"\nWe do not have the book you want.\nYou may try these books instead: \n";
				for (pos = 0; pos < books; pos++)
					if(strcmp(auth,stash[pos]->getauth()) == 0)
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
		ask_again:
		cout<<"\nWanna buy another book? [y/n]: ";
		cin>>op;
		cin.ignore();
		if (op == 'y' || op == 'Y')
			continue;
		else if (op == 'n' || op == 'N')
			break;
		else
			cout<<"Invalid input "<<op<<endl;
		goto ask_again;
	}
	
}

void library::billout(book &favourite, int copies)
{
	float price = favourite.getprice();
	int stock = favourite.getstock();
	char op = '\0';
	if (stock != 0)
	{
		if (copies > stock)
		{
			cout<<"\nWoah! You're a fan! We'll sell out our entire stock to you..";
			copies = stock;
		}
		cout<<"\nThe purchase costs: "<<fixed<<setprecision(2)<<copies*price<<endl;
		cout<<"\nDo you want to buy? (y/n) : ";
		cin>>op;
		cin.ignore();
		if (op == 'y' || op == 'Y')
			favourite.buy(copies);
		else if (op == 'n' || op == 'N')
			;
		else
			cout<<"\nAssuming that you don't want to buy the book..\n";
	}
	else
		cout<<"\nSorry. This book is so popular, we don't have it in stock anymore!\nPlease contact the librarian for this issue.";
}

int main()
{
	library run;
	run.control();
	return 0;
}
