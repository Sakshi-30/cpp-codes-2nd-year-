/*
 * stack.cpp
 *
 *  Created on: 06-May-2021
 *      Author: sakshi
 */
#include<iostream>
#include<string>
using namespace std;
#define MAXSIZE 20
class stack{
	int a[MAXSIZE];
	int top;
public:
	stack(){
		top=-1;
	}
	void push(int d);
	int pop();
	void postfixevaluation();
	bool isEmpty();
	bool isFull();
	void display();
	void prefixevaluation();

};

void stack :: push(int d){
	if(top>=MAXSIZE-1){
		cout<<"\n\tStack Overflow"<<endl;
	}else{
		top++;
		a[top]=d;
	}
}
int stack :: pop(){
	int i;
	if(top==-1){
		cout<<"\n\tStack Underflow"<<endl;
	}else{
		i = a[top];
		top--;

	}
	return i;
}

bool stack :: isFull(){
	if(top==MAXSIZE-1){
		return true;
	}else{
		return false;
	}
}
bool stack :: isEmpty(){
	if(top==-1){
			return true;
		}else{
			return false;
		}
}

void stack :: display(){
	if(top==-1){
		cout<<"\nStack is empty"<<endl;
	}else{
		cout<<"\nStack Elements are : "<<endl;
		for(int i = top ; i>=0 ; i--){
			cout<<"\nData : "<<a[i]<<endl;
		}
	}
}
void stack :: postfixevaluation(){
	string exp;
	  int j;
	  float op1=0.0,op2=0.0,val;
	  char ch;
	  cout<<"\n\tEnter the expression :";
	  cin>>exp;
	     for(j=0;j<exp.length();j++)
	     {
	         ch=exp[j];
	         if(isalpha(ch)) //returns true if ch is alphabetic charachter
	         {
	             cout<<"\nEnter value of "<<""<<exp[j]<<":";
	             cin>>val;
	             push(val);
	         }
	         else
	         {
	                 op2=pop();
	                 op1=pop();
	                 switch(ch)
	                 {
	                 case '+':val=op1+op2;
	                 break;
	                 case '-':val=op1-op2;
	                 break;
	                 case '*':val=op1*op2;
	                 break;
	                 case '/':val=op1/op2;
	                 break;

	                 }
	                 push(val);
	                 }
	}
	     cout<<"\n\tThe value of postfix expression is:"<<pop();
}
void stack :: prefixevaluation(){
	string exp;
		  int j;
		  float op1=0.0,op2=0.0,val;
		  char ch;
		  cout<<"\n\tEnter the expression :";
		  cin>>exp;
		     for(j=exp.size()-1;j>=0;j--)
		     {
		         ch=exp[j];
		         if(isalpha(ch)) //returns true if ch is alphabetic charachter
		         {
		             cout<<"\nEnter value of "<<""<<exp[j]<<":";
		             cin>>val;
		             push(val);
		         }
		         else
		         {
		                 op1=pop();
		                 op2=pop();
		                 switch(ch)
		                 {
		                 case '+':val=op1+op2;
		                 break;
		                 case '-':val=op1-op2;
		                 break;
		                 case '*':val=op1*op2;
		                 break;
		                 case '/':val=op1/op2;
		                 break;

		                 }
		                 push(val);
		                 }
		}
		     cout<<"\n\tThe value of prefix expression is:"<<pop();
	}


int main(){
	int ans,k,d,i;
	stack s;
	do{
		cout<<"\nMENU:\n1.PUSH\n2.POP\n3.ISFULL\n4.ISEMPTY\n5.DISPLAY\n6.POSTFIX EVALUATION\n7.PREFIX"<<endl;
		cout<<"Enter the choice"<<endl;
		cin>>k;
		switch(k){
		case 1:
			cout<<"Enter the data to be entered in stack"<<endl;
			cin>>d;
			s.push(d);
			break;
		case 2:

			d=s.pop();
			if(d!=i){
				cout<<"\nData: "<<d<<endl;
			}
			break;
		case 3:
			s.isEmpty();
			break;
		case 4:
			s.isFull();
			break;
		case 5:
			s.display();
			break;
		case 6:
			s.postfixevaluation();
			break;
		case 7:
			s.prefixevaluation();
			break;
		}

		cout<<"\n\nDo you want to continue?\nPress 1 to continue\nPress 0 to exit : ";
		cin>>ans;
	}while(ans==1);
	{
	       cout<<"Exit.";
	}

	return 0;
}




