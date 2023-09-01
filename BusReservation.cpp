#include<iostream>
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
#include<fstream>

using namespace std;

class TICKETS
{
	int ticketID, ticketPrice, count, busID, busStops, busKM, busFare, busTime, seatNo;
	
	public:
		void loadDetails(void);
		void bookTicket(void);
		void busDetails(void);
		void displayTicket(void);
		void displayTickets(void);
};

void TICKETS :: bookTicket(void)
{
	int x=0;
	srand (time(NULL));
	ticketID = rand() % 9999 + 1111;
	seatNo = rand() % 50 + 1;
	char filename[ ] = "bookHistory.txt";
    ofstream outputfile;
    outputfile.open(filename, ios::out|ios::app);
    if(outputfile.fail())
    {
		cout << "The file does not exist!";
	}
	else
	{
		cout << "\nPlease review the deatails before booking.";
		cout << "\n\n[Ticket ID]\t[Bus No:]\t[Stops No.]\t[Seat]\t[KMS]\t[Fare]\t[Time]\n";
		cout << ticketID << "\t\t" << busID << "\t\t" << busStops << "\t\t" << seatNo << "\t" << busKM << "\t" << busFare << "\t" << busTime;
		cout << "\n\nAre you sure want to book? YES = 1 || NO = any number\nEnter your choice : ";
		cin >> x;
		if (x==1)
		{
			outputfile << ticketID << "  ";
			outputfile << busID << "  ";
			outputfile << busStops << "  ";
			outputfile << seatNo << "  ";
			outputfile << busKM << "  ";
			outputfile << busFare << "  ";
			outputfile << busTime << "  ";
			outputfile << endl;
			cout << "\n\nCongratulation!!! Your ticket has been successfully booked.\nPlease note down the Ticket ID : " << ticketID << "\nYou can review your ticket details anytime from our main menu.\nHave a safe journey! :)";
		}
		else
		{
			cout << "\n\nYour ticket has not been booked. Please try again from our main menu. Thank you.";
		}
		outputfile.close();
	}
	cout << "\n\nPress any key to continue...";
	getch();
}

void TICKETS :: loadDetails(void)
{
	int flag = 0;
	char filename[] = "busInfo.txt";
	ifstream inputfile;
	inputfile.open(filename, ios::in);
	if(inputfile.fail())
		cout << "The file could not be opened!";
	else
	{
		int e;
		cout << "\n\nEnter the Bus number : ";
		cin >> busID;
       	inputfile >> e;
		while(!inputfile.eof())
   	    {
			if(e==busID)
			{
				inputfile >> e;
				busStops = e;
				inputfile >> e;
				busKM = e;
				inputfile >> e;
				busFare = e;
				inputfile >> e;
				busTime = e;
				flag = 1;
			}
			inputfile >> e;
		}
		inputfile.close();
		
		if(flag==0)
		{
			cout << "\n\nThe bus number could not be found in the system.\nPlease try again later with proper bus number.\nThank you.";
			exit(1);
		}
	}
}

void TICKETS :: displayTicket(void)
{
	int flag = 0, temp;
	char filename[] = "bookHistory.txt";
	ifstream inputfile;
	inputfile.open(filename, ios::in);
	if(inputfile.fail())
		cout << "The file could not be opened!";
	else
	{
		int e;
		cout << "\n\nEnter the ticket ID : ";
		cin >> temp;
       	inputfile >> e;
		while(!inputfile.eof())
   	    {
			if(e==temp)
			{
				ticketID = e;
				inputfile >> e;
				busID = e;
				inputfile >> e;
				busStops = e;
				inputfile >> e;
				seatNo = e;
				inputfile >> e;
				busKM = e;
				inputfile >> e;
				busFare = e;
				inputfile >> e;
				busTime = e;
				flag = 1;
			}
			inputfile >> e;
		}
		inputfile.close();
		if(flag==0)
		{
			cout << "\n\nThe bus number could not be found in the system.\nPlease try again later with proper bus number.\nThank you.";
			exit(1);
		}
	}
	cout << "\nThe details are as follows :";
	cout << "\n\n[Ticket ID]\t[Bus No:]\t[Stops No.]\t[Seat]\t[KMS]\t[Fare]\t[Time]\n";
	cout << temp << "\t\t" << busID << "\t\t" << busStops << "\t\t" << seatNo << "\t" << busKM << "\t" << busFare << "\t" << busTime;
	cout << "\n\nPress any key to continue...";
	getch();
}

void TICKETS :: displayTickets(void)
{
	char filename[] = "bookHistory.txt";
	ifstream inputfile;
	inputfile.open(filename, ios::in);
	if(inputfile.fail())
		cout << "The file could not be opened!";
	else
	{
		int e;
		cout << "\nFull ticket database :";
		cout << "\n\n[Ticket ID]\t[Bus No:]\t[Stops No.]\t[Seat]\t[KMS]\t[Fare]\t[Time]\n\n";
       	inputfile >> e;
		while(!inputfile.eof())
   	    {
			ticketID = e;
			inputfile >> e;
			busID = e;
			inputfile >> e;
			busStops = e;
			inputfile >> e;
			seatNo = e;
			inputfile >> e;
			busKM = e;
			inputfile >> e;
			busFare = e;
			inputfile >> e;
			busTime = e;
			inputfile >> e;
			cout << ticketID << "\t\t" << busID << "\t\t" << busStops << "\t\t" << seatNo << "\t" << busKM << "\t" << busFare << "\t" << busTime << "\n";
		}
	}
	inputfile.close();
	cout << "\n\nPress any key to continue...";
	getch();
}

void TICKETS :: busDetails(void)
{
	int array_size = 1024, temp=0;
	char * array = new char[array_size];
	int position = 0;
	ifstream myfile;
	myfile.open("busDetails.txt");
	if (myfile.is_open())
	{
		while(!myfile.eof() && position < array_size)
		{
			myfile.get(array[position]);
			position++;
		}
		array[position-1] = '\0';
		cout << "\n\n[Bus No:]\t[Source]\t[Destination]\t[Stops No.]\t[KMS]\t[Fare]\n\n";
		for(int i = 0; array[i] != '\0'; i++)
		{
				cout << array[i];
				temp++;
		}
		cout << "\n\nPress any key to continue...";
		getch();
	}
	else
		cout << "File not found";
}

int main()
{
	TICKETS order;
	int x;
	do
	{
		cout << "\n\n\n*********************************************\n* Welcome to the ABC Bus Reservation System *\n*********************************************\n\nPlease choose the appropiate option from the following:\n";
		cout << "\n\t1 : Book a ticket";
		cout << "\n\t2 : Display bus details";
		cout << "\n\t3 : Display the details of a booked ticket";
		cout << "\n\t4 : Display all booked tickets in the system";
		cout << "\n\t5 : Quit";
		cout << "\n\nSelect an option : ";
		cin >> x;
		switch(x)
		{
			case 1 : order.busDetails(); order.loadDetails(); order.bookTicket(); break;
			case 2 : order.busDetails(); break;
			case 3 : order.displayTicket(); break;
			case 4 : order.displayTickets(); break;
			case 5 : break;
			default : cout << "Error in input; please try again\n";
		}
	}
	while(x != 5);
	return 0;
}
