#include <iostream>

using namespace std;
class employee
{
    protected:
    int id;
    string name;
public:
    employee ( string a, int b)
    {

    }
    string getname()
    {
        return name;
    }
    void setname( string a)
    {
        a=name;
    }
    int getid()
    {
        return id;
    }
    void setid( int b)
    {
        b=id;
    }
    virtual double salary(int, int) =0;
};
class salariedEmployee:public employee{

    double weeklySalary;
    int number_of_absent ;
    int Num_of_late ;
public:
    salariedEmployee(string a,int b,double c,int i,int j):employee(a,b)
    {

        i=number_of_absent;
        j=Num_of_late;
    }
    void  setweeklySalary(double c)
    {
        weeklySalary=(c<0.0)?0.0:c;
    }
    double getweeklySalary()
    {
        return weeklySalary;
    }
    salary()
    {
        if( number_of_absent%3==0)
        return (weeklySalary*4)-(weeklySalary/7);

        else if(Num_of_late%3==0)
        return (weeklySalary*4)-(weeklySalary/14);

        else if( number_of_absent%3==0 && Num_of_late%3==0 )
        return (weeklySalary*4)-(weeklySalary/7)-(weeklySalary/14);

    }

};
class HourlyEmployee :public employee
{
    double HoursPerday;
    double Salaryperday;
    int WorkingInDays;
public:
    HourlyEmployee(string a,int b,double d,double e,int f):employee(a,b)
    {
    }
    void setHoursPerday(double d)
    {
        d= HoursPerday;
    }
    double getHoursPerday()
    {
        return HoursPerday;
    }
     void setSalaryperday(double e)
    {
        e= Salaryperday;
    }
    double getSalaryperday()
    {
        return Salaryperday;
    }
    void setWorkingInDays(int f)
    {
         f= WorkingInDays;
    }
    double getWorkingInDays()
    {
        return WorkingInDays;
    }
    salary()
    {
        return HoursPerday*WorkingInDays*Salaryperday;
    }

};

int main()
{
   string a,r;
   int b,f,i,j,g;
   double c, d, e;
   cout<<"Enter name"<<endl;
   getline(cin,a);
   cout<<"Enter ID,number of absent, number of late"<<endl;
   cin>>b>>i>>j;
   cout<<"Enter weekly salary"<<endl;
   cin>>c;
   cout<<"salaried employee"<<endl;

   salariedEmployee s1(a,b,c,i,j);
   cout<<"name : "<<a<<endl<<"ID : "<<b<<endl<<"Salary :"<<s1.salary()<<endl;

   cout<<"Enter name"<<endl;
   getline(cin,r);
   cout<<"Enter ID,working in days"<<endl;
   cin>>g>>f;
   cout<<"Enter hours per day, salary per hour "<<endl;
   cin>>d>>e;
   cout<<"hourly employee"<<endl;
   HourlyEmployee e1(r,g,d,e,f);

   cout<<"name : "<<r<<endl<<"ID : "<<g<<endl<<"Salary :"<<e1.salary()<<endl;

    return 0;
}

