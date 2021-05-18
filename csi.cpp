/*
 * csi.cpp
 *
 *  Created on: 04-May-2021
 *      Author: sakshi
 */
#include <iostream>
#include<string.h>
#include<stdio.h>
using namespace std;
class node
{
	node *next;
	string name,roll;
	int year;
	public :
	node(string n,string r,int y)
	{
		name=n;
		roll=r;
		year=y;
		next=NULL;
	}
	friend class list;
};
class list        //create class list
{
	node *head;
	node *temp;
	node *next;
public:
	void create();
	void insert();
	void compute();//function declarartion
	void delet();
	void search();
	void display();

    public:list()
	{
		head=NULL;
	}
};

void list :: create(){
	        int y;
			string n,r;
			char ch;
			do
			{
			cout<<"Enter name of member "<<endl;
			cin>>n;
			cout<<"Enter C.no "<<endl;
			cin>>r;
			cout<<"Enter year of member "<<endl;
			cin>>y;
			temp=new node(n,r,y);
				   if(head==NULL)
				  {
					head=temp;
				  }
				else
				{
					node *ptr;
					ptr=head;
					while(ptr->next!=NULL)
					{
						ptr=ptr->next;
					}
					ptr->next=temp;
				}
				cout<<"Do you want to add more members? "<<endl;
				cout<<"Enter y for yes and n for no "<<endl;
				cin>>ch;
			}while(ch=='y');

}
void list :: insert(){
	int y;
			string n,m,r;
			node *ptr;   //temporary variable to traverse list
		   cout<<endl<<"Enter details of new member "<<endl;
		    cout<<"Enter name "<<endl;
				  cin>>n;
				  cout<<"Enter C.no "<<endl;
				  cin>>r;
				  cout<<"Enter year "<<endl;
				   cin>>y;
			    	temp=new node(n,r,y);
				   if(head==NULL)
				  {
					head=temp;
				  }
				else
				{
					int pos;
					cout<<"Enter position where new member is to be added"<<endl;
					cin>>pos;
					if(pos==1)
					{
						temp->next=head;
						head=temp;
					}
					else
					{
						//temporary variable is new node which is to be inserted in list
						int i=1;
						ptr=head;
						while(i<(pos-1) && ptr->next!=NULL)
						{
							ptr=ptr->next;
							i++;
						}
						temp->next=ptr->next;
						ptr->next=temp;
					}
		}
}
void list :: compute(){
	int c1=0,c2=0,c3=0;
			node *temp;
			node *ptr;
			ptr=head;
			while(ptr!=NULL)
			{
				if(ptr->year==2)
				{
					c1++;
				}
				else
					if(ptr->year==3)
					{
						c2++;
					}
					else
						if(ptr->year==4)
						{
							c3++;
						}
				ptr=ptr->next;
			}
			int c=c1+c2+c3;
			cout<<endl;
			cout<<"No. of members in branch are "<<c<<endl;
			cout<<"Members of 2nd year are "<<c1<<endl;
			cout<<"Members of 3rd year are "<<c2<<endl;
			cout<<"Members of 4th year are "<<c3<<endl;
}
void list :: delet(){
	node *prev;
				    node *ptr;
				    string a;
				    int r,r1;
				    	cout<<"Enter C.No to be deleted "<<endl;
				    		    cin>>a;
				    		   ptr=head;
				    		   prev=head;
				    		   while(ptr!=NULL)
				    		    {
				    			   r1=head->roll.compare(a);
				    			   if(r1==0)
				    			   {
				    				   head=head->next;
				    				   delete(prev);
				    				   break;
				    			   }
				    			   r=a.compare(ptr->roll);
				    		    	if(r==0)
				    		    	{
				    		    		prev->next=ptr->next;
				    		    		ptr->next=NULL;
				    		    		delete ptr;
				    		    		break;
				    		    	}
				    		    	else
				    		    	{
				    		    		prev=ptr;
				    		    		ptr=ptr->next;
				    		    	}
				    		   }
				    		   if(r!=0)
				    			   cout<<"Member not found "<<endl;
}
void list :: search(){
	string s1;
			node *ptr;
			int flag=0;
			cout<<"Enter C.No of member whose information is needed "<<endl;
			cin>>s1;
			for(ptr=head;ptr!=NULL;ptr=ptr->next)
					{
				int r=(s1).compare(ptr->roll);
						if(r==0)
						{
						cout<<"Member found "<<endl;
						cout<<"NAME:"<<ptr->name<<endl;
					     cout<<"C.NO:"<<ptr->roll<<endl;
						cout<<"YEAR:"<<ptr->year<<endl;

						 cout<<endl;
						 flag=1;
							break;
						}
					}
			if(flag==0)
				cout<<"Member not found "<<endl;
}
void list:: display(){

	                 node *ptr;
				    int i=1;
				    for(ptr=head;ptr!=NULL;ptr=ptr->next)
				    {
				        cout<<endl;
				        cout<<"STUDENT "<<i<<endl;
				        cout<<"NAME:"<<ptr->name<<endl;
				         cout<<"C.NO:"<<ptr->roll<<endl;
				          cout<<"YEAR:"<<ptr->year<<endl;
				          cout<<endl;
				          i++;
				    }
	}
int main()
{
	list l;
	l.create();
	l.display();
	int n;
	do
	{
		cout<<endl;
		cout<<"Enter 1. to insert new member "<<endl;
		cout<<"Enter 2. to count total no of members "<<endl;
		cout<<"Enter 3. to search member information "<<endl;
		cout<<"Enter 4. to remove a member details \n5.WXIT"<<endl;
		cin>>n;
	     switch(n)
	     {
	     case 1:
	    	 l.insert();
	    	 l.display();
	    	 break;
	     case 2:
	    	 l.compute();
	    	 break;
	     case 3 :
	    	 l.search();
	    	 break;
	     case 4 :
	    	 l.delet();
	    	 l.display();
	    	 break;
	     }
	}while(n>0 && n<=4);
	return 0;
}
