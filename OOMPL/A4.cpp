#include <iostream>
#include <cmath>

using namespace std;

class Complex
{
	private:
		float real;
		float imag;
	public:
		float getR() { return real; }
		void setR(float r) { real = r; }
		float getI() { return imag; }
		void setI(float i) { imag = i; }
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
		float operator%(Complex that)
		{
			return sqrt(that.getR()*that.getR() + that.getI()*that.getI());
		}
		void print()
		{
			cout<<this->real;
			if (this->imag > 0)
				cout<<" + ";
			else
				cout<<" - ";
			cout<<this->imag;
		}
		Complex operator-(Complex that)
		{
			Complex ans;
			ans.setR( this->real - that.getR() );
			ans.setI( this->imag - that.getI() );
			return ans;
		}
		Complex operator+(Complex that)
		{
			Complex ans;
			ans.setR( this->real + that.getR() );
			ans.setI( this->imag + that.getI() );
			return ans;
		}
		Complex operator*(Complex that)
		{
			Complex ans;
			ans.setR( this->real*that.getR() - this->imag*that.getI() );
			ans.setI( this->real*that.getI() + this->imag*that.getR() );
			return ans;
		}
		Complex operator/(Complex that)
		{
			Complex ans;
			ans = (*this)*( ~that );
			float factor = (%that)*(%that);
			ans = ans/factor;
			return ans;
		}
};

void add()
{
	char type = '\0';
	Complex a, b;
	Complex *temp;
	int c, d;
	for (int i = 0; i < 2; i++)
	{
		cout<<" \n1> Complex\n2> Real";
		cout<<"\nEnter number type: ";
		cin>>type;
		switch(type)
		{
			case '1':
				cout<<"\nReal : ";
				cin>>c;
				cout<<"\nImaginary : ";
				cin>>d;
				temp = new Complex(c,d);
				if (&a == NULL)
					a = *temp;
				else
					b = *temp;
				break;
			case '2':
				cout<<"\nNumber : ";
				cin>>c;
				temp = new Complex(c);
				b = *temp;
				break;
			default: cout<<"Invalid Entry : "<<type;
		}
	}
	a = a+b;
	cout<<"Sum is ";
	a.print();
	cout<<endl;
}

void subtract()
{
	char type = '\0';
	Complex a, b;
	Complex *temp;
	int c, d;
	for (int i = 0; i < 2; i++)
	{
		cout<<" \n1> Complex\n2> Real";
		cout<<"\nEnter number type: ";
		cin>>type;
		switch(type)
		{
			case '1':
				cout<<"\nReal : ";
				cin>>c;
				cout<<"\nImaginary : ";
				cin>>d;
				temp = new Complex(c,d);
				if (&a == NULL )
					a = *temp;
				else
					b = *temp;
				break;
			case '2':
				cout<<"\nNumber : ";
				cin>>c;
				temp = new Complex(c);
				b = *temp;
				break;
			default: cout<<"Invalid Entry : "<<type;
		}
	}
	a = a-b;
	cout<<"Difference is ";
	a.print();
	cout<<endl;
}

void multiply()
{
	char type = '\0';
	Complex a, b;
	Complex *temp;
	int c, d;
	for (int i = 0; i < 2; i++)
	{
		cout<<" \n1> Complex\n2> Real";
		cout<<"\nEnter number type: ";
		cin>>type;
		switch(type)
		{
			case '1':
				cout<<"\nReal : ";
				cin>>c;
				cout<<"\nImaginary : ";
				cin>>d;
				temp = new Complex(c,d);
				if (&a == NULL )
					a = *temp;
				else
					b = *temp;
				break;
			case '2':
				cout<<"\nNumber : ";
				cin>>c;
				temp = new Complex(c);
				b = *temp;
				break;
			default: cout<<"Invalid Entry : "<<type;
		}
	}
	a = a*b;
	cout<<"Product is ";
	a.print();
	cout<<endl;
}

void divide()
{
	char type = '\0';
	Complex a, b;
	Complex *temp;
	int c, d;
	for (int i = 0; i < 2; i++)
	{
		cout<<" \n1> Complex\n2> Real";
		cout<<"\nEnter number type: ";
		cin>>type;
		switch(type)
		{
			case '1':
				cout<<"\nReal : ";
				cin>>c;
				cout<<"\nImaginary : ";
				cin>>d;
				temp = new Complex(c,d);
				if (&a == NULL )
					a = *temp;
				else
					b = *temp;
				break;
			case '2':
				cout<<"\nNumber : ";
				cin>>c;
				temp = new Complex(c);
				b = *temp;
				break;
			default: cout<<"Invalid Entry : "<<type;
		}
	}
	a = a/b;
	cout<<"Quotient is ";
	a.print();
	cout<<endl;
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
	return 0;
}
