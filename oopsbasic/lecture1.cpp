//creating a class for beginning:
#include <iostream>
using namespace std;
class Teacher{
    //properties/attributes:
    //by default they are created in private member class.
    public:
    string name;
    string dept;
    string subject;
    double salary;
    //methods/member function:
    void changedept(string newdept){
        dept=newdept;
    }
};
int main(){
    Teacher t1;//object creation
    t1.name="arpit";
    t1.dept="mechanical engineering";
    t1.subject="physics";
    t1.salary=25000;

    cout<<t1.name<<endl;
    cout<<t1.dept<<endl;
    cout<<t1.subject<<endl;
    cout<<t1.salary<<endl;
    return 0;

}