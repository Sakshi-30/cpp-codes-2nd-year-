/*
 * sorting.cpp
 *
 *  Created on: 10-May-2021
 *      Author: sakshi
 */
#include<iostream>
#include<string>
using namespace std;

class student{
	string name;
	double cgpa;
	long cno;
	int rollno;
	friend class sort;
public:
	void acceptStudent();    //accept details for one student
	void displayStudent();   //display details for one student;


};
void student :: acceptStudent(){
	cout<<"-----------------------------------------------------"<<endl;
	cout<<endl;
	cout<<"Enter Name of Student : "<<endl;
	cin>>name;
	cout<<"Enter Roll No. of Student : "<<endl;
	cin>>rollno;
	cout<<"Enter C. No. of Student : "<<endl;
	cin>>cno;
	cout<<"Enter CGPA of Student : "<<endl;
	cin>>cgpa;
	cout<<endl;
	cout<<"-----------------------------------------------------"<<endl;
}

void student :: displayStudent(){
	cout<<"*****************************************************"<<endl;
	cout<<endl;
	cout<<" NAME : "<<name<<endl;
	cout<<" ROLL NO. : "<<rollno<<endl;
	cout<<" C. NO. :"<<cno<<endl;
	cout<<" CGPA : "<<cgpa<<endl;
	cout<<endl;
	cout<<"*****************************************************"<<endl;
}

class sort{
	student s[100];
	student temp;
	int n;               //total number of student
public:
	void acceptNoStudent();
	void displayNoStudent();
	void bubblesort();
	void selectionsort();
	void insertionsort();
	void quicksort();
	void mergesort();
};

void sort :: acceptNoStudent(){
	cout<<"Enter the Total number of in Class :  "<<endl;
	cin>>n;
	for(int i=1 ; i<=n ; i++){
		cout<<"STUDENT : "<<endl;
		s[i].acceptStudent();
	}
}

void sort :: displayNoStudent(){
	for(int i = 0 ; i<=n ;i++) {
			s[i].displayStudent();
	}
}

void sort :: bubblesort(){
	for(int i = 0 ; i<n-1 ; i++){
		for(int j = i+1 ; j<n-1 ; j++){
			if(s[i].cgpa > s[j].cgpa){
				temp = s[i];
				s[i] = s[j];
				s[j] = temp;
			}
		}
	}
}

void sort :: selectionsort(){
	int i,j;
	for( i = 0 ; i<n-1; i++){
		int min = i;
		for(j = i+1 ; j<n ; j++){
			if(s[j].cgpa < s[min].cgpa){
				min = j;
			}
		}
		if(min!=i){
			temp = s[i];
			s[i] = s[min];
			s[min] = temp;
		}
	}
}

void sort :: insertionsort(){
	int i , j;
	for(i=1; i<n ; i++){
		temp = s[i];
		double l = s[i].cgpa;
		j = i-1;
		while (j >= 0 && s[j].cgpa>l){
			s[j+1] = s[j];
			j--;
			}
		s[j+1] = temp;
	}
}


void sort :: quicksort(){
	int pivot;
			pivot=s[0].cgpa;
			int i=1;
			int j=n-1;
			while(i<j)
			{
				while(s[i].cgpa<=pivot)
			     {
					   i++;
				}
				while(s[j].cgpa>=pivot)
				{
					j--;
				}
				if(i<=j)
				{
					temp=s[i];
					s[i]=s[j];
					s[j]=temp;
				}
			}
			temp=s[0];
			s[0]=s[j];
			s[j]=temp;
}


int main(){
	sort k;
	k.acceptNoStudent();
	int ch;
	do{
		cout<<"\tSTUDENT CGPA SORTING ALGORITHM\t"<<endl;
		cout<<"\n1.DISPLAY STUDENT DETAILS \n2.BUBBLE SORT \n3.SELECTION SORT \n4.INSERTION SORT \n4.QUICK SORT"<<endl;
		cout<<"Enter your choice"<<endl;
		cin>>ch;
		switch(ch){
		case 1:
			k.displayNoStudent();
			break;
		case 2:
			k.bubblesort();
			break;
		case 3 :
			k.selectionsort();
			break;
		case 4 :
			k.insertionsort();
			break;
		case 5 :
			k.quicksort();
			break;
		case 6 :
			cout<<"\tTHANKYOU\t"<<endl;
			break;
		default :
			cout<<"INVALID INPUT"<<endl;
			break;
		}
	}while(ch!=6);

}



