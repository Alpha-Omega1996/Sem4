 #include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

class Complex
{
	public:
		float getR() { return real; }
		float setR(float r) { real = r; }
		float getI() { return imag; }
		float setI(float i) { imag = i; }
		Complex(int r = 0, int i = 0)
		{
			this->real = r;
			this->imag = i;
		}
		void operator-()
		{
			this->real = -this->real;
			this->imag = -this->imag;
		}
		void operator~()
		{
			this->imag = -this->imag;
		}
		float operator%()
		{
			return sqrt(this->real*this->real + this->imag*this->imag);
		}
		void operator=(Complex that)
		{
			this->real = that.getR();
			this->imag = that.getI();
		}
		Complex operator-(Complex that)
		{
			Complex ans();
			ans.setR( this->real - that.getR() );
			ans.setI( this->imag - that.getI() );
			return ans;
		}
		Complex operator+(Complex that)
		{
			Complex ans();
			ans.getR( this->real + that.getR() );
			ans.getI( this->imag + that.getI() );
			return ans;
		}
		Complex operator*(Complex that)
		{
			Complex ans();
			ans.setR( this->real*that.getR() - this->imag*that.getI() );
			ans.setI( this->real*that.getI() + this->imag*that.getR() );
			return ans;
		}
		Complex operator/(Complex that)
		{
			Complex ans();
			ans = (*this)*(~that);
			float factor = (%that)*(%that);
			ans = ans/factor;
			return ans;
		}
		friend istream& operator>> (istream& , Complex& );
		friend ostream& operator<< (ostream&, const Complex&);
	private:
		float real;
		float imag;

};

ostream& operator>>(istream &s, Complex &bag)
{
	cout<<"\nEnter Real part : ";
	s>>bag.real;
	cout<<"\nEnter Imaginary part : ";
	s>>bag.imag;
	return s;
}

ostream& operator<<(ostream &s, const Complex &model)
{
	if (that.imag >= 0)
		here<<model.real<<" + "<<model.imag<<"i";
	else
		here<<model.real<<" - "<<model.imag<<"i";
	return s;
}

int main()
{
	char op = '\0';
	while (op != 'x' || op != 'X')
	{
		cout<<"\n\nNow presenting, Complex Arithmetic!\n\n";
		cout<<"Operations: \n";
		cout<<"\t Addition : +\n\t Subtraction : -\n\t Multiplication : *\n\t Division : /\n\t Exit : x\n";
		cout<<"\tEnter Operation: ";
		cin>>op;
		switch(op)
		{
			case '+': add();
				break;
			case '-': subtract();
				break;
			case '*': multiply();
				break;
			case '/': divide();
				break;
			case 'x':
			case 'X': break;
			default: cout<<"Invalid Entry : "<<op;
		}
	}
}

void add()
{
	char type = '\0';
	Complex a, b;
	int c, d;
	for (int i = 0; i < 2; i++)
	{
		cout<<" \n1> Complex\n2> Real";
		cout<<"\nEnter number type: ";
		cin>>type;
		switch(type)
		{
			case '1':
				cin>>a;
				break;
			case '2':
				cout<<"\nNumber : ";
				cin>>c;
				b = new Complex(c);
				break;
			default: cout<<"Invalid Entry : "<<type
		}
	}
	a = a+b;
	cout<<"Sum is ";
	cout<<a;
	cout<<endl;
}

void subtract()
{
	char type = '\0';
	Complex a, b;
	int c, d;
	for (int i = 0; i < 2; i++)
	{
		cout<<" \n1> Complex\n2> Real";
		cout<<"\nEnter number type: ";
		cin>>type;
		switch(type)
		{
			case '1':
				cin>>a;
				break;
			case '2':
				cout<<"\nNumber : ";
				cin>>c;
				b = new Complex(c);
				break;
			default: cout<<"Invalid Entry : "<<type
		}
	}
	a = a-b;
	cout<<"Difference is ";
	cout<<a;
	cout<<endl;
}

void multiply()
{
	char type = '\0';
	Complex a, b;
	int c, d;
	for (int i = 0; i < 2; i++)
	{
		cout<<" \n1> Complex\n2> Real";
		cout<<"\nEnter number type: ";
		cin>>type;
		switch(type)
		{
			case '1':
				cin>>a;
				break;
			case '2':
				cout<<"\nNumber : ";
				cin>>c;
				b = new Complex(c);
				break;
			default: cout<<"Invalid Entry : "<<type
		}
	}
	a = a*b;
	cout<<"Product is ";
	cout<<a;
	cout<<endl;
}

void divide()
{
	char type = '\0';
	Complex a, b;
	int c, d;
	for (int i = 0; i < 2; i++)
	{
		cout<<" \n1> Complex\n2> Real";
		cout<<"\nEnter number type: ";
		cin>>type;
		switch(type)
		{
			case '1':
				cin>>a;
				break;
			case '2':
				cout<<"\nNumber : ";
				cin>>c;
				b = new Complex(c);
				break;
			default: cout<<"Invalid Entry : "<<type
		}
	}
	a = a/b;
	cout<<"Quotient is ";
	cout<<a;
	cout<<endl;
}
