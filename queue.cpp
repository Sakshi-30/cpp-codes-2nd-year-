/*
 * queue.cpp
 *
 *  Created on: 06-May-2021
 *      Author: sakshi
 */
#include<iostream>
using namespace std ;

class Passenger//class Passenger
{
public:
string name ;
int age ;
char gender ;

friend class Queue ;//friend class Queue
Passenger()
{
name = "" ;
age = 0 ;
gender = '\0' ;
}
void add() ;// add passenger details
void display() ;//display ticket
bool canceltkt(string s) ;//
};
class Queue//class Queue
{
//instance variables
Passenger wait[10] ;
int front ;
int rear ;
public:
Queue()//default constructor
{
front = 0 ;
rear = -1 ;
}
//functions
int isfull() ;
int isempty() ;
void enque() ;  //to add passenger to waiting list
Passenger deque() ;
void displaywait() ;
};

void Passenger::add()////function defination of add
{
cout<<"-------------------------------------------------------------------"<<endl;
cout<<"Enter your name: ";
cin>>name;
cout<<"Enter your gender: ";
cin>>gender;
cout<<"Enter your age: ";
cin>>age;
cout<<"-------------------------------------------------------------------"<<endl;

}

void Passenger::display()//function defination of display
{
cout<<"-------------------------------------------------------------------"<<endl;
cout<<"Name: "<<name<<endl;
cout<<"Age: "<<age<<endl;
cout<<"Gender: "<<gender<<endl;
cout<<"-------------------------------------------------------------------"<<endl;
}

bool Passenger::canceltkt(string s)//function defination of canceltkt
{
bool flag = false ;
if(s == name)
{
cout<<"Your ticket is cancelled"<<endl ;
flag = true ;
}
return flag ;
}


int Queue::isfull()//function defination of isfull
{
if(rear == 9)
{
return 1 ;
}
else
{
return 0 ;
}
}

int Queue::isempty()//function defination of isempty
{
if(front == (rear + 1))
{
return 1 ;
}

else
{
return 0 ;
}
}

void Queue::enque()//function defination of enque to add passenger to waiting list
{
if(isfull() == 0)
{
cout<<"-------------------------------------------------------------------"<<endl;
cout<<endl;
cout<<"You are being put to waiting list"<<endl;
cout<<endl;
rear ++ ;
wait[rear].add() ;//adding to waiting list
}
else
{
cout<<endl;
cout<<"No further reservations are possible...."<<endl;
cout<<endl;
}
}
Passenger Queue::deque()//function defination of deque
{
Passenger a ;
if(isempty() == 1)
{
cout<<"No passengers in waiting list......"<<endl;
}
else
{
a = wait[front] ;//deleting from waiting list
front ++ ;
}
return a ;
}
void Queue::displaywait()
{
if(isempty()==1)
{
cout<<" No Registrations"<<endl ;
}
else
{
for(int i = front ; i <= rear ; i++)
{
wait[i].display() ;//display
}
}
}
int main()
{
Passenger h[5] ;
Queue f ;
int pos=0;
string s;
Passenger m;
int cnt = 0  ;
int ch ;
do
{
//display menu
cout<<endl;
cout<<"Railway Rservation System"<<endl;
cout<<"MENU  : "<<endl;
cout<<"\n" ;
cout<<"1.Book Ticket"<<endl;
cout<<"2.Cancel Ticket"<<endl;
cout<<"3.Confirm Ticket List"<<endl ;
cout<<"4.Waiting list"<<endl ;
cout<<"0.EXIT"<<endl;
cout<<endl;
cout<<"Enter your choice: ";
cin>>ch;
switch(ch)
{
case 1:
if(cnt < 5)
{
cout<<"\n";
cout<<"Passenger No. :"<<cnt+1<<endl ;
h[cnt].add() ;
cout<<"Your Ticket is confirmed"<<endl ;
cnt++ ;
}
else
{
f.enque() ;//calling enque to add passengers in waiting list
}
break ;
case 2:

cout<<"Enter name of the passenger: ";
cin>>s;
for(int i=0;i<5;i++)
{
if(h[i].canceltkt(s)==true)//canceling ticket
{
pos = i;
break;
}
}
cout<<"\n" ;
m = f.deque();//calling deque to delete passenger from waiting list
//inserting the passenger in confirmed ticket list
h[pos].name = m.name;
h[pos].gender = m.gender;
h[pos].age = m.age;
break ;
case 3 :
cout<<"CONFIRM RESERVATIONS: "<<endl;
cout<<endl;
for(int j=0;j<5;j++)
{
h[j].display();//display confirmed list
}
cout<<endl;
break ;
case 4:
cout<<"WAITING LIST: "<<endl;
f.displaywait();//display waiting list


break;
case 0:
cout<<"Thank you !!"<<endl ;
break ;
default:
cout<<"Invalid choice"<<endl ;
break ;

}

}while(ch != 0) ;

}
