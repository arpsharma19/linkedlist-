#include <iostream>
using namespace std;
class Student{
    private:
    int rollno;
    void sayhello(){
        cout<<"hello"<<endl;
    }
    public:
    void setrollno(int r1){
        rollno=r1;
    }
    int getrollno(){
        return rollno;
    }
    void display(){
        sayhello();
    }

};
int main(){
    Student S1;
    S1.setrollno(14);
    cout<<"roll no of S1 is:"<<S1.getrollno()<<endl;
    S1.display();
    return 0;
}