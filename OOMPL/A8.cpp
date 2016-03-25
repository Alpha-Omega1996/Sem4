#include <iostream>
#include <iomanip>
using namespace std;

//#define

class Student
{
	protected:
		string name;
		int roll_number;
		string *subject;
	public:
		Student()
		{
			name = "";
			roll_number = 0;
			subject = new string[5];
		}
		void init()
		{
			cout<<"\nEnter Student's Name: ";
			getline(cin,name);
			cin.ignore();
			cout<<"\nEnter "<<name<<"'s roll number: ";
			cin>>roll_number;
			for (int i = 0 ; i < 5 ; i++)
			{
				if (i == 1) cout<<"\nEnter 1st subject name : ";
				else if (i == 2) cout<<"\nEnter 2nd subject name : ";
				else if (i == 3) cout<<"\nEnter 3rd subject name : ";
				else cout<<"\nEnter "<<i<<"th subject name : ";
				getline(cin,subject[i]);
				cin.ignore();
			}
		}
		void details()
		{
			int i;
			cout<<"\n"<<name<<"\t"<<roll_number<<"\nSubjects: \n";
			for (i = 0 ; i < 4 ; i++)
				cout<<subject[i]<<"\t";
			cout<<subject[i]<<endl;
		}
		~Student()
		{
			name = "";
			roll_number = 0;
			delete subject;
		}
};

class College_Record : virtual protected Student
{
	protected:
		int *internal_marks;
	public:
		College_Record()
		{
			internal_marks = new int[5];
		}
		void init()
		{
			for (int i = 0 ; i < 5 ; i++)
			{
				if (i == 1) cout<<"\nEnter "<<subject[i]<<"'s internal marks : ";
				else if (i == 2) cout<<"\nEnter "<<subject[i]<<"'s internal marks : ";
				else if (i == 3) cout<<"\nEnter "<<subject[i]<<"'s internal marks : ";
				else cout<<"\nEnter "<<subject[i]<<"'s interal marks : ";
				cin>>internal_marks[i];
			}
		}
		void details()
		{
			pupil.details();
			cout<<endl;
			for (int i = 0 ; i < 5 ; i++)
				cout<<internal_marks[i]<<"\t";
		}
		~College_Record()
		{
			delete internal_marks;
		}
};

class University_Record : virtual protected Student
{
	protected:
		int *subject_code;
		int *university_marks;
	public:
		University_Record()
		{
			subject_code = new int[5];
			university_marks = new int[5];
		}
		void init()
		{
			for (int i = 0 ; i < 5 ; i++)
			{
				if (i == 1) cout<<"\nEnter "<<subject[i]<<"'s subject code : ";
				else if (i == 2) cout<<"\nEnter "<<subject[i]<<"'s subject code : ";
				else if (i == 3) cout<<"\nEnter "<<subject[i]<<"'s subject code : ";
				else cout<<"\nEnter "<<subject[i]<<"'s subject code : ";

				cin>>subject_code[i];

				if (i == 1) cout<<"\nEnter "<<subject[i]<<"'s university marks : ";
				else if (i == 2) cout<<"\nEnter "<<subject[i]<<"'s university marks : ";
				else if (i == 3) cout<<"\nEnter "<<subject[i]<<"'s university marks : ";
				else cout<<"\nEnter "<<subject[i]<<"'s university marks : ";

				cin>>university_marks[i];
			}
		}
		void details()
		{
			cout<<endl;
			for (int i = 0 ; i < 5 ; i++)
				cout<<subject_code[i]<<"\t";
			cout<<endl;
			for (int i = 0 ; i < 5 ; i++)
				cout<<university_marks[i]<<"\t";
		}
		~University_Record()
		{
			delete university_marks;
			delete subject_code;
		}
};

class Record: protected College_Record, protected University_Record
{
	Record *next;
	public:
		Record()
		{
			Student::init();
			College_Record::init();
			University_Record::init();
		}
};
