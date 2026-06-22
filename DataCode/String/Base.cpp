#include <iostream>
using namespace std;

class Base
{
protected:
    char Name[10];

public:
    void GetName()
    {
        cin >> Name;
    }

    virtual void Display()
    {
        cout << Name << endl;
    }

    virtual bool IsGood() = 0;
    virtual ~Base() {}
};

class Teacher : public Base
{
private:
    int Paper;

public:
    void GetPaper()
    {
        cin >> Paper;
    }

    void Display()
    {
        cout << "Teacher: "
             << Name
             << " Paper=" << Paper << endl;
    }

    bool IsGood()
    {
        return Paper >= 5;
    }
};

class Student : public Base
{
private:
    int Degree;

public:
    void GetDegree()
    {
        cin >> Degree;
    }

    void Display()
    {
        cout << "Student: "
             << Name
             << " Degree=" << Degree << endl;
    }

    bool IsGood()
    {
        return Degree >= 90;
    }
};

int main()
{
    Base *p[100];
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int type;
        cin >> type;

        if (type == 1)
        {
            Teacher *t = new Teacher;
            p[i] = t;

            p[i]->GetName();    // 对象指针调用成员函数
            t->GetPaper();
        }
        else
        {
            Student *s = new Student;
            p[i] = s;

            p[i]->GetName();    // 对象指针调用成员函数
            s->GetDegree();
        }
    }

    cout << "优秀教师和优秀学生名单：" << endl;

    for (int i = 0; i < n; i++)
    {
        if (p[i]->IsGood())     // 对象指针调用虚函数
        {
            p[i]->Display();    // 对象指针调用虚函数
        }
    }

    for (int i = 0; i < n; i++)
        delete p[i];

    return 0;
}