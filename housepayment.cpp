#include <iostream>
#include <iomanip>
#include <math.h> 
using namespace std;
void printline(int month, double payment,double principal_paid, double total_pay, double mir, double p_paid, double remaining)
 {
	 cout<<"|"<<right
		 <<setw(4)<<month
		 <<setw(9)<<payment
		 <<setw(12)<<total_pay
		 <<setw(10)<<mir
		 <<setw(12)<<p_paid
		 <<setw(11)<<principal_paid
		 <<setw(12)<<remaining
		 <<"   |"
		 <<endl;
 }

void setheader(double yir, double principal, double years)
	 {
		cout<<fixed<<setprecision(2);
		cout<<" ------------------------------------------------------------------------- "<<endl;
		cout<<"|"<<" Principal " 
			<<left
			<<setw(12) 
		    << principal;
		cout<<fixed<<setprecision(4);
		cout<<"Interest "
		    <<left
		    <<setw(9)
		    <<yir;
		cout<<fixed<<setprecision(3);
		cout<<"Years "
		    <<left
		    <<setw(10)
		    <<years;
		double mir = yir /1200;
		double f =principal * mir;
		double a = 1 + mir;
		double b = 1 / a;
		double c = 12 * years;
		double d = pow(b, c);
		double e = 1 - d;
		//double payment = floor((f / e) * 100.0 + .5)/100.0;
		double payment = f/e;
		cout<<fixed<<setprecision(2);
		const char space = ' ';
		cout<<"Payment "
		    << left
		    <<setw(8)
		    <<payment<<"|";
		    cout<<endl;
	//GAP For Formatting
	cout<< "|"<<right<<setw(74)<<"|"<<endl;
	// column heade
	cout 	<< left 
		<< setw(10) << "| Month" 
		<< setw(10) << "Pay"
		<< setw(10) << "Total" 
		<< setw(10) << "Monthly"
		<< setw(13) << "Principal"
		<< setw(10) << "Total" 
		<< setw(11) << "Remaining"
		<< "|"
		<<endl;
	cout	<<"|"<<right
		<<setw(23)	<<"Paid"
		<<setw(13)	<<"Interest"
		<<setw(10)	<<"Paid"
		<<setw(13)	<<"Principal"
		<<setw(11)	<<"Balance"
		<<"   |"
		<<endl;
	cout	<<"|"<<right
		<<setw(57)<<"Paid"
		<<setw(17)<<"|"<<endl;
	cout<<"|"<<setw(74)<<"|"<<endl;
	 double Total_Payments = 0;
	 double principal_paid = 0;
	 double total_interest = 0;
	 for(int i = 0; i < c; i++)
	 {
		double mir = yir /1200;
		//double f = floor((principal * mir) * 100.0 + .5)/100.0;
		f = principal * mir;
		double a = 1 + mir;
		double b = 1 / a;
		double c = 12 * years;
		double d = pow(b, c);
		double e = 1 - d;
		Total_Payments += payment;
		double cal = payment- f;
		cout<<fixed<<setprecision(2);
		//cout<< "Payment " << payment<< "-" << f <<"="<<cal<<endl;
		principal_paid += cal;
		principal -= cal;
		total_interest += f;
		int months = c - 8;
		if (principal < 0){
		principal =0;
		}
		if(i < 8 || i >= months)
		 {
			printline(i+1, payment,principal_paid, Total_Payments, f, cal, principal); 
		 }
		else if( i == 9) 
		 {
			cout <<right
				<<"|"
				<<setw(4) << "-"
				<<setw(7)<< "-"
				<<setw(12)<< "-"
				<<setw(10)<< "-"
				<<setw(12)<< "-"
				<<setw(11)<< "-"
				<<setw(12)<< "-"
				<<setw(6)<<"|"
				<<endl; 
		 }
	  }
	 cout<<" ------------------------------------------------------------------------- "<<endl;
	 cout<<"Total Interest Paid: " << total_interest<<endl;
	 }	 
int main()
{
	double principal, yir,years;
	cout<< "Enter Principal"<<endl;
	cin>>	principal;
	cout<< "Enter in Monthly Interest"<<endl;
	cin>>	yir;
	cout<<"Enter Years" <<endl;
	cin>>	years;
	setheader(yir,principal,years);
}

