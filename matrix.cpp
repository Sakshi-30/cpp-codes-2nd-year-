/*
 * matrix.cpp
 *
 *  Created on: 02-May-2021
 *      Author: sakshi
 */

#include <iostream>
using namespace std;

class matrix
{
public:
  int A[20][20];
  int r,c;
 public:
  void accept();
  void display();
  void add(int M[20][20],int N[20][20]);
  void multiplication(int M[20][20],int N[20][20]);
  void transpose(int M[20][20]);
  void square(int M[20][20]);
  void uppertraingular(int M[20][20]);
  void lowertriangular(int M[20][20]);
};

void matrix::accept()
{
	cout<<"Enter the number of rows and columns for  Matrix"<<endl<<endl;
	cin>>r>>c;
	cout<<"Enter Elements for  Matrix"<<endl;
    for(int i=0;i<r;i++){
    	for(int j=0;j<c;j++){
    		cin>>A[i][j];
    	}
    }



}
void matrix::display()
{
    cout<<"The Matrix is: "<<endl<<endl;
	for(int i=0;i<r;i++){
	    	for(int j=0;j<c;j++){
	    		cout<<A[i][j]<<" ";
	    	}
	        cout<<endl;
	   }


}
 void matrix ::add(int M[20][20],int N[20][20])
{
    int sum[20][20];
    cout<<"The Addition of Matrix 1st and Matrix 2nd"<<endl<<endl;

	 for (int i = 0; i < r ; i++)
	{
	for (int j = 0; j < c; j++)
		{
		sum[i][j] = M[i][j] + N[i][j];
		cout << sum[i][j] <<" ";
		}
		cout << endl;
	}

}
void matrix ::multiplication(int M[20][20],int N[20][20])
 {
 	   int  k;
 	   int mul[20][20];
 	   cout<<"The multiplication of Matrix 1st and Matrix 2nd"<<endl<<endl;
   for(int i=0;i<r;i++)
   {
      for(int j=0;j<c;j++)
      {
        mul[i][j]=0;
        for(k=0;k<c;k++)
       {
       mul[i][j]+=M[i][k]*N[k][j];
       }
     }
   }
   for(int i=0;i<r;i++)
    {
      for(int j=0;j<c;j++)
      {
      cout<<mul[i][j]<<" ";
       }
     cout<<"\n";
 }

}


 void matrix :: square(int M[20][20]){
	 if(r==c){
	     cout<<"The given matrix is a square matrix"<<endl<<endl;
	 }else{
	     cout<<"The given matrix is not a square matrix"<<endl<<endl;
	 }


 }

 void matrix :: uppertraingular(int M[20][20]) {
 	 int isupper = 0;
	 for(int i=0; i<r; i++){
	 	for(int j=0; j<c; j++){
	 		if(j<i && A[i][j]!=0){
	 			isupper = 1;
			 }
		 }
	 }
	 if(isupper==1){
	 	cout<<"Matrix is not Upper triangular"<<endl<<endl;
	 }
	 else{
	 	cout<<"Matrix is upper triangular"<<endl<<endl;
	 }


  }
 void matrix :: lowertriangular(int M[20][20]) {
  	 int islower = 0;
 	 for(int i=0; i<r; i++){
 	 	for(int j=i+1; j<c; j++){
 	 		if(i>j && A[i][j]!=0){
 	 			islower = 1;
 			 }
 		 }
 	 }
 	 if(islower==1){
 	 	cout<<"Matrix is not Lower triangular"<<endl<<endl;
 	 }
 	 else{
 	 	cout<<"Matrix is Lower triangular"<<endl<<endl;
 	 }


   }

void matrix :: transpose(int M[20][20])
    { int T[20][20];
    cout<<"The transpose of the matrix is:-"<<endl<<endl;
    	if(r==c){
    		for(int i=0; i<r; i++){
    			for(int j=0; j<c; j++){
    				int temp = A[i][j];
    				A[i][j] = A[j][i];
    				A[j][i] = temp;
				}
			}
			for(int i=0; i<r; i++){
    			for(int j=0; j<c; j++){
    				cout<<A[j][i]<<" ";
				}
				cout<<endl;
			}
		}
		else{
			for(int i=0; i<r; i++){
    			for(int j=0; j<c; j++){
    				T[j][i] = A[i][j];
				}
			}
			for(int i=0; i<r; i++){
    			for(int j=0; j<c; j++){
    				cout<<T[i][j]<<" ";
				}
    			cout<<endl;
			}


		}

    }



int main()
{
matrix m1;
m1.accept();
m1.display();
m1.square(m1.A);
m1.uppertraingular(m1.A);
m1.lowertriangular(m1.A);
m1.transpose(m1.A);
matrix m2;
m2.accept();
m2.display();
m1.add(m1.A , m2.A);
m1.multiplication(m1.A , m2.A);

return 0;
}
