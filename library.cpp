/*
 * library.cpp
 *
 *  Created on: 12-May-2021
 *      Author: sakshi
 */

#include<iostream>
#include<string>
using namespace std;

class book{
	string title;
	string author;
	int isbn;
	friend class library;
public:
	void acceptbook();
};
class library{
	int n;
	book b[40];
public:
	void acceptNobooks();
	void displayNobooks();
	void insertnewbook();
	void searchbook();
	void sortbook();
	void enlistbooks();
};
void book :: acceptbook(){
        cout<<"---------------------------------------------"<<endl;
        cout<<endl;
	    cout<<"Enter title of book "<<endl;
		cin>>title;
		cout<<"Enter author of book "<<endl;
		cin>>author;
		cout<<"Enter ISPN number "<<endl;
		cin>>isbn;
		cout<<endl;
		cout<<"---------------------------------------------"<<endl;
}
void library :: acceptNobooks(){
	    cout<<"Enter number of books "<<endl;
	    cin>>n;
		for(int i=0;i<n;i++)
		{
			cout<<"\tBOOK : \t"<<endl;
		    b[i].acceptbook();
		}
		cout<<endl;
}
void library :: displayNobooks(){
	for(int i=0;i<n;i++)
	    {
		cout<<"*****************************************************"<<endl;
		cout<<endl;
	    cout<<"BOOK "<<(i+1)<<":"<<endl;
		cout<<endl;
		cout<<"TITLE : "<<b[i].title<<endl;
		cout<<"AUTHOR : "<<b[i].author<<endl;
		cout<<"ISPN Number : "<<b[i].isbn<<endl;
		cout<<endl;
		cout<<"*****************************************************"<<endl;
	    }
}
void library :: insertnewbook(){
	string t1,a1;
		int is1,i,pos;
		    cout<<"Add details of new book to be added "<<endl;
		    cout<<"Enter title of book "<<endl;
			cin>>t1;
			cout<<"Enter author of book "<<endl;
			cin>>a1;
			cout<<"Enter ISPN number "<<endl;
			cin>>is1;
			cout<<"Enter position at which book is to be added "<<endl;
			cin>>pos;
			for(i=(n-1);i>=(pos-1);i--)
			{
				b[i+1].title=b[i].title;
				b[i+1].author=b[i].author;
				b[i+1].isbn=b[i].isbn;
			}
				b[pos-1].title=t1;
				b[pos-1].author=a1;
				b[pos-1].isbn=is1;
				n=n+1;
}
void library :: searchbook(){
	string a1,t1;
	  int x1=0,x2=0,flag=0,i;
	  cout<<"Enter details of book to be searched "<<endl;
	  cout<<"Enter title of book "<<endl;
	  cin>>t1;
	  cout<<"Enter author of book "<<endl;
	  cin>>a1;
	 for(i=0;i<n;i++)
	 {
	     x1=(b[i].title).compare(t1);
	     x2=(b[i].author).compare(a1);
	     if(x1==0 && x2==0)
	     {
	         flag=1;
	         break;
	     }
	 }
	 if(flag==1)
	 cout<<"Book Found Successfully!! "<<endl;
	 if(flag==0)
	 cout<<"Book not found "<<endl;
}

void library :: sortbook(){          //bubble sort implementation for sorting books
	int i,j,temp=0;
		for(i=0;i<n;i++)
		{
			for(j=0;j<(n-i);j++)
			{
				if(b[j].isbn>b[j+1].isbn)
				{
					temp=b[j].isbn;
					b[j].isbn=b[j+1].isbn;
					b[j+1].isbn=temp;
				}
			}
		}
}

void library ::enlistbooks(){
	string a1;
		int x1=0;
		cout<<"Enter author to enlist the books "<<endl;
		cin>>a1;
		for(int i=0;i<n;i++)
		{
			x1=(b[i].author).compare(a1);
			if(x1==0)
			{
				cout<<"TITLE : "<<b[i].title<<endl;
				cout<<"AUTHOR : "<<b[i].author<<endl;
				cout<<"ISPN Number : "<<b[i].isbn<<endl;
				cout<<endl;
			}
		}
}

int main(){
	int x;
		library l;
		l.acceptNobooks();
		l.displayNobooks();
		do
		{
		cout<<endl;
		cout<<" 1. To add new book details "<<endl;
		cout<<" 2. To search a book in library "<<endl;
		cout<<" 3. To sort books "<<endl;
		cout<<" 4. To list books of given author "<<endl;
		cout<<" 5. To Exit"<<endl;
		cout<<" Enter your choice"<<endl;
		cin>>x;
	    switch(x)
		{
		case 1:
			l.insertnewbook();
			l.displayNobooks();
			break;
		case 2:
		  l.searchbook();
		  break;
		case 3:
			cout<<endl;
			cout<<"Books sorted according to ISPN number "<<endl;
			l.sortbook();
			l.displayNobooks();
			break;
		case 4:
			l.enlistbooks();
			//l.displayNobooks();
			break;
		case 5:
			cout<<"\tTHANKYOU\t"<<endl;
			break;
		}
		}while(x!=4);
		return 0;
}
