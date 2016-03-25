#include <iostream>
#include <string>

using namespace std;

#define MAX(x,y) ( (x > y) ? x : y )
#define MIN(x,y) ( (x < y) ? x : y )
#define SWAP(x,y) { char temp = x; x = y; y = temp; }

class String
{
	private:
		string s;
	public:
		String(int mode = 0)
		{
			if (!mode)
			{
				cout<<"\nEnter your string: ";
				cin.ignore();
				getline(cin,s);
			}
		}
		string toString()
		{
			return s;
		}
		int operator= (String test)
		{
			char* c_test = (char* )test.toString().c_str();
			char* c_s = (char* )s.c_str();
			int size = MIN( test.toString().length(), s.length() );
			int ret_val, i = 0;
			for (ret_val = 0; i < size ; i++)
			{
				ret_val = (int)c_test[i] - c_s[i];
				if (ret_val != 0)
					break;
			}
			if (ret_val != 0)
				return ret_val;
			if ( size != MAX( test.toString().length(), s.length() ) )
			{
				if (size == s.length())
					return (int)c_test[i];
				else
					return (int)c_s[i];
			}
			return 0;
		}
		void operator== (String &src)
		{
			string s_src = src.toString();
			s.assign(s_src);
		}
		String operator+ (String dest)
		{
			String temp;
			string s_temp = temp.toString();
			s_temp.assign(s);
			s_temp.append(dest.toString());
			return temp;
		}
		int operator~ ()
		{
			string s_rev;
			char* c_s = (char*)s.c_str();
			char temp;
			for (int i = 0; i < s.length()/2; i++)
			{
				temp = c_s[i];
				c_s[i] = c_s[s.length()-i-1];
				c_s[s.length()-i-1] = temp;
			}
			s_rev.assign(c_s);
			if ( s.compare(s_rev) )
				return 1;
			else
				return 0;
		}
		int operator> (String str)
		{
			string s_str = str.toString();
			return s_str.find(s);
		}
		friend istream & operator>> (istream &, String&);
		friend ostream & operator<< (ostream &, String&);
};

istream & operator>> (istream &here, String &inside_out)
{
	char* c_s = (char*)(inside_out.s).c_str();
	char temp;
	for (int i = 0; i < inside_out.s.length()/2; i++)
	{
		temp = c_s[i];
		c_s[i] = c_s[inside_out.s.length()-i-1];
		c_s[inside_out.s.length()-i-1] = temp;
	}
	inside_out.s.assign(c_s);
	return here;
}

ostream & operator<< (ostream &here, String &model)
{
	here<<model.s;
	return here;
}

int main()
{
	cout<<"\nThis program will demonstrate Modification of Operator meanings using the Concept of Operator Overloading.\n";
	int op = 1;
	while (op != 0)
	{
		cout<<"\nChoose one of the operations below: ";
		cout<<"\n\t1 : Equality\n\t2 : Copy\n\t3 : Concatenate\n\t4 : Display\n\t5 : Reverse\n\t6 : Check for Palindrome\n\t7 : Check for substring\n\t0 : Exit";
		cin>>op;
		switch(op)
		{
			case 0:
				break;
			case 1:
				{
					String a();
					String b();
					if ( !(a=b) )
						cout<<"\nThey are Equal! \"a=b\"\n";
				}
				break;
			case 2:
				String a();
				String b();
				a==b;
				cout<<"\nCopy accomplished. \"a==b\""<<a<<endl;
				break;
			case 3:
				String a();
				String b();
				String c(1);
				c==(a+b);
				cout<<"\nConcatenation accomplished.\"a+b\" "<<c<<endl;
				break;
			case 4:
				String a();
				cout<<"\nDisplaying : \"cout<<a\"";
				cout<<a;
				cout<<endl;
				break;
			case 5:
				String a();
				cin>>a;
				cout<<"\nReversing accomplished : \"cin>>a\""<<a<<endl;
				break;
			case 6:
				String a();
				if (~a)
					cout<<"\nThis was a palindrome! ";
				else
					cout<<"\nThis wasn't a palindrome! ";
				cout<<"\"~a\"\n";
				break;
			case 7:
				cout<<"Enter main string: ";
				String a();
				cout<<"Enter substring to check: ";
				String b();
				if ( (b>a) != -1)
					cout<<"\nSubstring exists at "<<(b>a)<<".";
				else
					cout<<"\nSubstring doesn't exist.";
				cout<<"\"b>a\"\n";
				break;
			default:
		}
	}
	return 0;
}
