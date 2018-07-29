 #include <iostream>
 #include<cmath>
 #include<conio.h>

using namespace std;


class ComplexNumber
{
private:
    int real;
    int imaginary;
public:
    ComplexNumber();
    ComplexNumber(int,int);
    ~ComplexNumber(); //Does Nothing
    void Input();
    void Output();
    bool IsEqual(ComplexNumber);
    ComplexNumber Conjugate();
    ComplexNumber add(ComplexNumber);
    ComplexNumber subtract(ComplexNumber);
    ComplexNumber multiplication(ComplexNumber);
    float magnitude();
};


ComplexNumber::ComplexNumber()
{
    real = imaginary = 0;
}

ComplexNumber::~ComplexNumber()
{

}


ComplexNumber::ComplexNumber(int r,int i)
{
    real = r;
    imaginary = i;
}



void ComplexNumber::Input()
{
    cout<<"Enter Real ";
    cin>>real;

    cout<<endl;

    cout<<"Enter Imaginary ";
    cin>>imaginary;

    cout<<endl;
}



void ComplexNumber::Output()
{
   if(imaginary>=0)
        {
            cout<<real<<"+"<<imaginary<<"i";
        }

    else if(imaginary<0)
        {
            cout<<real<<imaginary<<"i";
        }
}

float ComplexNumber::magnitude()
{
    int baseReal=real;
    int power=2;

    int squarer=pow(baseReal,power);
    int baseImag=imaginary;
    int squarei=pow(baseImag,power);

    int sum=squarei+squarer;

    float mag=sqrt(sum);

    return mag;
}

bool ComplexNumber::IsEqual(ComplexNumber num)
{
    if(real == num.real)
    {
        if(imaginary == num.imaginary)
        {
                return 1;
        }
            else{return 0;}
    }

    else{return 0;}
}

ComplexNumber ComplexNumber::Conjugate()
{
    ComplexNumber con;

    con.real = real;
    con.imaginary = -1*(imaginary);

    return con;
}

ComplexNumber ComplexNumber:: add(ComplexNumber num )
{
    ComplexNumber sum;

    sum.real=num.real+real;
    sum.imaginary=num.imaginary+imaginary;

    return sum;
}

ComplexNumber ComplexNumber:: subtract(ComplexNumber num )
{
    ComplexNumber sub;

    sub.real=real-num.real;
    sub.imaginary=imaginary-num.imaginary;

    return sub;
}

ComplexNumber ComplexNumber:: multiplication(ComplexNumber num )
{
    ComplexNumber mul;

   mul.real=(real*num.real)-(imaginary*num.imaginary);

   mul.imaginary=(real*num.imaginary)+(imaginary*num.real);

    return mul;
}



int main()
{

    ComplexNumber c1;
    ComplexNumber c2(1,2);

    cout<<"Enter c1: \n\n";
    c1.Input();

    cout<<"Enter c2: \n\n";
    c2.Input();

    cout<<" c1 = ";
    c1.Output();

    cout<<"\n\n c2 = ";
    c2.Output();

if(c1.IsEqual(c2)==1)
    {
        cout<<"\n\n c1 is EQUAL to c2"<<endl;
    }

else if (c1.IsEqual(c2)==0)
    {
        cout<<"\n\n c1 is NOT EQUAL to c2"<<endl;
    }

    cout<<"\n\n Conjugate of c1 = ";
    c1.Conjugate().Output();

    cout<<"\n\n Conjugate of c2 = ";
    c2.Conjugate().Output();

    cout<<"\n\n c1 + c2 = ";
    c1.add(c2).Output();

    cout<<"\n\n c1 - c2 = ";
    c1.subtract(c2).Output();

    cout<<"\n\n c1 * c2 = ";
    c1.multiplication(c2).Output();

    cout<<"\n\n Magnitude of c1 =";
    cout<<c1.magnitude();

    cout<<"\n\n Magnitude of c2 =";
    cout<<c2.magnitude();




_getch();

}

