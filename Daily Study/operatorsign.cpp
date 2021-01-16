#include <iostream>

using namespace std;
class Complex{
	public:
		Complex(){real=0;image=0;}
		Complex(double r,double i){
			real=r;
			image=i;
		}
		Complex operator+(Complex& c);/*重载+*/
		/*或者*/
		friend Complex operator+(Complex& c1,Complex& c2);
		friend ostream& operator<<(ostream&,Complex&);
		friend istream& operator>>(istream&,Complex&);
	private:
		double real;
		double image;
};
Complex Complex::operator+(Complex& c){
	
	return Complex(real+c.real,image+c.image);
}

Complex Complex::operator+(Complex& c1,Complex& c2){
	/*
	 *Complex c;
	 c.real=c1.real+c2.real;
	 c.image=c1.image+c2.image;
	 return c;
	 * */
	return Complex(c1.real+c2.real,c1.image+c2.image);
}


ostream& operator<<(ostream& ocout,Complex& c){
	/*重载“<<”只能为友元函数或者普通函数,不能为类的成员函数*/
	ocout<<"("<<c.real<<"+"<<c.image<<"i)"<<endl;
	return ocout;
}

istream& operator>>(istream& icin,Complex& c){
	icin>>c.real>>c.image;
	return icin;
}

int main(int argc,char* argv[]){
	Complex c,c1(2,4),c2(6,10);
	c=c1+c2;
	cout<<c<<c1<<endl;
        Complex c3;
	cin>>c3;
	cout<<c3<<endl;
	return 0;
}
