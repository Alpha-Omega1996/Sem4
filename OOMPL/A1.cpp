#include<iostream>
#include<iomanip>
using namespace std;

#define MAX 31

class weather{
	private:
		int day_of_month;
		float hightemp;
		float lowtemp;
		float amount_rain;
		float amount_snow;
	public:
		weather();
		void feed();
		int getDay() { return day_of_month; }
		float getHtemp() { return hightemp; }
		float getLtemp() { return lowtemp; }
		float getArain() { return amount_rain; }
		float getAsnow() { return amount_snow; }
};

weather::weather()
{
	day_of_month = 99;
	hightemp = 999.0f;
	lowtemp = -999.0f;
	amount_rain = 0.0f;
	amount_snow = 0.0f;
}

void weather::feed()
{
     float temp;
     while (1)
     {
	     cout<<"\nEnter the day number: ";
	     cin>>temp;
	     if( (temp - ((int)temp) != 0) || (temp > 31) || (temp <= 0) )
	     {
		cout<<"\nInvalid day."<<endl;
		continue;
	     }
	     day_of_month = (int)temp;
	     break;
     }
     while(1)
     {
	  cout << "\nEnter the highest temperature recorded: ";
	  cin>>temp;
	  hightemp = temp;
	  cout << "\nEnter the lowest temperature recorded: ";
	  cin>>temp;
	  lowtemp = temp;
	  if (lowtemp > hightemp)
	  {
		cout<<"\nInvalid temperature readings.\n";
		continue;
	  }
	  break;
     }
     while(1)
     {
	  cout << "\nEnter the amount of rain recorded: ";
	  cin>>temp;
	  if (temp < 0)
	  {
		cout<<"\nInvalid rainfall reading.\n";
		continue;
	  }
	  amount_rain = temp;
	  break;
     }
     while(1)
     {
	  cout << "\nEnter the amount of snow recorded: ";
	  cin>>temp;
	  if (temp < 0)
	  {
		cout<<"\nInvalid snowfall reading.\n";
		continue;
	  }
	  amount_snow = temp;
	  break;
     }
}

class recorder{
	private:
	      weather record[MAX];
	      int records;
	public:
	      recorder() { records = 0; }
	      void book();
	      void table();
};

void recorder::book()
{
	cout << "\nThis program will help you construct and view a Weather Report.";
	int option = 1;
	while ( option != 3 )
	{
		cout<<"\n\nChoose from the following options: ";
		cout<<"\n\t1> Enter day record.\n\t2> Display month record.\n\t3> Exit.\n\t>";
		cin>>option;
		switch(option)
		{
			case 1:
				record[records].feed();
				records++;
				break;
			case 2:
				if (records!=0)
					table();
				else
					cout << "\nPlease Enter some Records first!!";
				break;
			case 3:
				break;
			default:
				cout << "\nInvalid Option!!.";
		}
	}

}

void recorder::table()
{
	float avg[4] = {0.0f,0.0f,0.0f,0.0f};
	int count = 0;
	cout << "\n\nDay \t Amt_Rain \t Amt_Snow \t High_Temp \t Low_Temp \n";
	while (count != records)
	{
		cout <<setprecision(3) <<record[count].getDay()<<" \t "<<record[count].getArain()<<" \t\t "<<record[count].getAsnow()<<" \t\t "<<record[count].getHtemp()<<" \t\t "<<record[count].getLtemp()<<" \n";
		avg[0] += record[count].getArain();
		avg[1] += record[count].getAsnow();
		avg[2] += record[count].getHtemp();
		avg[3] += record[count].getLtemp();
		count++;
	}
	cout<<"Avg";
	count = 0;
	while (count != 4)
	{
		if (count == 0)
			cout<<setprecision (3)<<" \t "<< ( avg[count]/(float)records );
		else
			cout<<setprecision (3)<<" \t\t "<< ( avg[count]/(float)records );
		count++;
	}
	cout<<"\n\n";
}

int main()
{
	recorder obj;
	obj.book();
	return 0;
}

