#include <iostream>
#include <conio.h>
#include <string>

using namespace std;

int ReturnDays(int month)
{
	int days=0;

	if(month==1)
	{
		days=29;
		return days;
	}

	else if(month==7)
	{
		days=31;
		return days;
	}

	else if(month%2!=0)
	{
		days=31;
		return days;
	}

	else if(month%2==0)
	{
		days=30;
		return days;
	}

}

bool CheckActivities(char****calendar)
{
	bool check=0;

	for(int i=0;i<12;i++)
	{
		for(int j=0;j<ReturnDays(i);j++)
		{
			for(int k=0;k<24;k++)
			{
				if(calendar[i][j][k]!=0)
				{
					check=1;
				}
			}
		}
	
	}

	return check;
	
}


int StringSize(char*buffer)
{
	int size=0;

	for(char* temp=buffer;*temp!=0;temp++)
	{
		size++;
	}

	return size+1;
}


char* CreateActivity()
{
	char* buffer=new char[80];

	cout<<"Enter Activity Statement: ";
	cin.ignore();
	cin.getline(buffer, 100);


	int size=StringSize(buffer);

	char*Activity=new char[size];

	char*temp2=Activity;

	for(char*temp=buffer;*temp!=0;temp++)
	{
		*temp2=*temp;
		temp2++;
	}

	Activity[StringSize(buffer)-1]=0;

	return Activity;
}

void AddNewActivity(char****calendar)
{
	int day=0,month=0,hour=0;

	cout<<"Enter Month :";
	cin>>month;

	while(month<1 || month>12)
	{
		cout<<"Invalid Month Entered, Enter Month Again: ";
		cin>>month;
	}

	cout<<endl<<"Enter Day :";
	cin>>day;

	while(day<1 || day>ReturnDays(month-1))
	{
		cout<<"Invalid Day Entered, Enter Day Again: ";
		cin>>day;
	}


	cout<<endl<<"Enter Hour :";
	cin>>hour;

	while(hour<1 || hour>24)
	{
		cout<<"Invalid Hour Entered, Enter Hour Again: ";
		cin>>hour;
	}

	if(calendar[month-1][day-1][hour-1]!=0)
	{
		cout<<"There is already an activity during this hour on this day: "<<endl;
	}

	else if(calendar[month-1][day-1][hour-1]==0)
	{
		calendar[month-1][day-1][hour-1]=CreateActivity();
	}


}

void DeleteActivity(char****calendar)
{
	if(CheckActivities(calendar)==0)
	{
		cout<<"There are no Activities in your Calendar";
	}

	else
	{
		int day,month,hour=0;
		char command=0;

		cout<<"Enter Month :";
		cin>>month;

		while(month<1 || month>12)
		{
			cout<<"Invalid Month Entered, Enter Month Again: ";
			cin>>month;
		}

		cout<<endl<<"Enter Day :";
		cin>>day;

		while(day<1 || day>ReturnDays(month-1))
		{
			cout<<"Invalid Day Entered, Enter Day Again: ";
			cin>>day;
		}

		cout<<endl<<"Enter Hour :";
		cin>>hour;

		while(hour<1 || hour>24)
		{
			cout<<"Invalid Hour Entered, Enter Hour Again: ";
			cin>>hour;
		}

		if(calendar[month-1][day-1][hour-1]==0)
		{
			cout<<"There is no activity during this hour on this day: "<<endl;
		}

		else if(calendar[month-1][day-1][hour-1]!=0)
		{
			cout<<"Are you sure you want to delete this Activity, Y=YES, N=NO.";
			cin>>command;

			if(command=='Y' || command=='y')
			{
				calendar[month-1][day-1][hour-1]=0;
			}

		else
		{
			while(command!='N')
			{
				cout<<"Invalid Command, Enter Y or N"<<endl;
				cin>>command;
			}
		}

	}

}

}





char**** Allocation()
{
	char****Calendar=new char***[12];

	for(int months=0;months<12;months++)
	{
		Calendar[months]=new char**[ReturnDays(months)];

			for(int days=0;days<ReturnDays(months);days++)
			{
				Calendar[months][days]=new char*[24];

					for(int hours=0;hours<24;hours++)
					{
						Calendar[months][days][hours]=0;
					}
			}
	}

	return Calendar;

}

void ViewAllActivities(char****calendar)
{
	if(CheckActivities(calendar)==0)
	{
		cout<<"There are no Activities in your Calendar";
	}

	else if(CheckActivities(calendar)==1)
	{
		for(int i=0;i<12;i++)
		{
			for(int j=0;j<ReturnDays(i);j++)
			{
				for(int k=0;k<24;k++)
				{
					if(calendar[i][j][k]!=0)
					{
						cout<<j+1<<"/"<<i+1<<"/"<<"16"<<" "<<k+1<<":00"<<" "<<calendar[i][j][k]<<endl;
					}
				}
			}
		}
	}
}

void ViewByMonth(char****calendar)
{
	bool check=0;
	int month=0;

	if(CheckActivities(calendar)==0)
	{
		cout<<"There are no Activities in your Calendar";
	}

	else if(CheckActivities(calendar)==1)
	{
		
		cout<<"Enter Month you want to view"<<endl;
		cin>>month;

		while(month<1 || month>12)
		{
			cout<<"Invalid Month Entered, Enter Month Again: ";
			cin>>month;
		}

		

		
			for(int j=0;j<ReturnDays(month-1);j++)
			{
				for(int k=0;k<24;k++)
				{
					if(calendar[month-1][j][k]!=0)
					{
						cout<<j+1<<"/"<<month<<"/"<<"16"<<" "<<k+1<<":00"<<" "<<calendar[month-1][j][k]<<endl;
						check=1;
					}
				}
			}
		
	}

	if(check==0) 
	{
		cout<<"There are no activities in this month"<<endl;
	}

	
}

void ViewByDay(char****calendar)
{
	bool check=0;
	int day,month=0;

	if(CheckActivities(calendar)==0)
	{
		cout<<"There are no Activities in your Calendar";
	}

	else if(CheckActivities(calendar)==1)
	{

		cout<<"Enter Month"<<endl;
		cin>>month;

			while(month<1 || month>12)
			{
				cout<<"Invalid Month Entered, Enter Month Again: ";
				cin>>month;
			}

		cout<<endl<<"Enter Day you want to view :";
		cin>>day;

			while(day<1 || day>ReturnDays(month-1))
			{
				cout<<"Invalid Day Entered, Enter Day Again: ";
				cin>>day;
			}

	
				for(int k=0;k<24;k++)
				{
					if(calendar[month-1][day-1][k]!=0)
					{
						cout<<day<<"/"<<month<<"/"<<"16"<<" "<<k<<":00"<<" "<<calendar[month-1][day-1][k]<<endl;
						check=1;
					}
				}
			
	}

	if(check==0)
	{
		cout<<"There are no activities on this day"<<endl;
	}

}

void DeAllocateCalendar(char****calendar)
{
	for(int months=0; months<12; months++)
	{
		for(int days=0; days<ReturnDays(months); days++ )
		{
			for(int hours=0; hours<24; hours++)
			{
				delete calendar [months][days][hours];
				calendar [months][days][hours];
			}

			delete[] calendar [months][days];
			calendar [months][days];
		}
		
		delete[] calendar [months];
		calendar[months]=0;
	}

	delete[] calendar;

	calendar=0;

}

void Menu(char****calendar)
{
	cout<<"********************XTREME CALENDAR 2K16******************"<<endl<<endl<<endl;
char i=0;
while(i!='8')
{
	cout<<endl<<endl;
	cout<<"1. View All Activities \n";
	cout<<"2. View Activities by Month \n";
	cout<<"3. View Activities by Day \n";
	cout<<"4. Add New Activity \n";
	cout<<"5. Remove an activity \n";
	cout<<"8. Exit \n \n";

	cout<<"Choose an option: ";
	cin>>i;

	cout<<endl<<endl;
	system("cls");

	if(i=='1')
	{
		ViewAllActivities(calendar);
	}

	else if(i=='2')
	{
		ViewByMonth(calendar);
	}

	else if(i=='3')
	{
		ViewByDay(calendar);
	}

	else if(i=='4')
	{
		AddNewActivity(calendar);
	}

	else if(i=='5')
	{
		DeleteActivity(calendar);
	}

	else if(i=='8')
	{
		DeAllocateCalendar(calendar);
		exit(0);
	}

	else
	{
		cout<<"Wrong Input Entered"<<endl;
	}
}

}

void main()
{
	char**** Calendar=Allocation();
	Menu(Calendar);
	DeAllocateCalendar(Calendar);

}
