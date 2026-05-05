//整体的三处改良：
//1.使用了new和delete来申请和释放空间
//2.使用了this指针来标记成员变量
//3.向量的一些基础运算使用的是常成员函数的定义，能够在不修改成员变量的前提下，得到运算结果
#include <iostream>
#include <cmath>
#include <climits>
using namespace std;

typedef double ElemType;

class NVector
{
public:
    // 无参构造
    NVector();
    // 带参构造（动态分配空间）
    NVector(size_t sz);
    // 析构函数：释放动态内存
    ~NVector();

    // 设置向量数据
    void SetVector(ElemType* data, size_t sz);
    // 打印向量
    void Print() const;
    // 获取维度
    size_t Size() const;
    // 向量和
    NVector Plus(const NVector& v) const;
    // 向量差
    NVector Sub(const NVector& v) const;
    // 向量模长
    ElemType Mode() const;
    // 点乘
    ElemType DotProduct(const NVector& v) const;

private:
    ElemType* arr;    // 动态数组指针
    size_t sz;      // 向量维度
};

// 无参构造
NVector::NVector() : arr(nullptr), sz(0) {}

// 带参构造：动态分配n维空间
NVector::NVector(size_t sz)
{
    this->sz = sz;//使用this指针，减小记忆成本
    arr = new ElemType[this->sz]; // 动态申请内存，使用new申请空间
    // 初始化为0
    for (size_t i = 0; i < this->sz; ++i)
        arr[i] = 0.0;
}

// 析构函数：释放动态数组
NVector::~NVector()
{
    if (arr != nullptr)
    {
        delete[] arr;//delete释放申请的空间
        arr = nullptr;//将指针赋值为空指针
    }
    this->sz = 0;
}

// 设置向量数据
void NVector::SetVector(ElemType* data, size_t sz)
{
    // 如果已有空间，先释放
    if (arr != nullptr)
    {
        delete[] arr;
    }
    this->sz = sz;
    arr = new ElemType[this->sz];
    for (size_t i = 0; i < this->sz; ++i)
        arr[i] = data[i];
}

// 打印向量
void NVector::Print() const
{
    cout << "(";
    for (size_t i = 0; i < this->sz; ++i)
    {
        cout << arr[i];
        if (i != this->sz - 1)
            cout << ", ";
    }
    cout << ")";
}

// 获取维度
size_t NVector::Size() const
{
    return this->sz;
}
//将向量的加法、减法、点乘和模运算都定义为常成员函数，在函数中不能改变成员变量，防止成员变量发生该改变

// 向量加法
NVector NVector::Plus(const NVector& v) const
{
    if (v.Size() != this->sz)
    {
        cout << "错误：两个向量维度不同，无法相加！" << endl;
        return NVector();
    }

    NVector res(this->sz);
    for (size_t i = 0; i < this->sz; ++i)
        res.arr[i] = arr[i] + v.arr[i];
    return res;
}

// 向量减法
NVector NVector::Sub(const NVector& v) const
{
    if (v.Size() != this->sz)
    {
        cout << "错误：两个向量维度不同，无法相减！" << endl;
        return NVector();
    }

    NVector res(this->sz);
    for (size_t i = 0; i < this->sz; ++i)
        res.arr[i] = arr[i] - v.arr[i];
    return res;
}

// 向量模长
ElemType NVector::Mode() const
{
    ElemType sum = 0.0;
    for (size_t i = 0; i < this->sz; ++i)
        sum += arr[i] * arr[i];
    return sqrt(sum);
}

// 点乘
ElemType NVector::DotProduct(const NVector& v) const
{
    if (v.Size() != this->sz)
    {
        cout << "错误：两个向量维度不同，无法点乘！" << endl;
        return INT_MAX;
    }

    ElemType sum = 0.0;
    for (size_t i = 0; i < this->sz; ++i)
        sum += arr[i] * v.arr[i];
    return sum;
}

// 输入一个n维向量
void InputVector(NVector& v, size_t n)
{
    ElemType* data = new ElemType[n];
    cout << "请输入 " << n << " 个坐标值：";
    for (size_t i = 0; i < n; ++i)
        cin >> data[i];

    v.SetVector(data, n);
    delete[] data;
}

int main()
{
    size_t n;
    //n维向量运算程序
    cout << endl;
    cout << "请输入向量维度 n：";
    cin >> n;

    // 创建两个n维向量
    NVector v1(n);
    NVector v2(n);

    cout << "\n输入第一个向量 v1：" << endl;
    InputVector(v1, n);

    cout << "\n输入第二个向量 v2：" << endl;
    InputVector(v2, n);

    // 输出信息
    cout << endl;
    cout << "v1 = "; v1.Print(); cout << endl;
    cout << "v2 = "; v2.Print(); cout << endl;

    cout << "\nv1 的维度：" << v1.Size() << endl;
    cout << "v1 的模长：" << v1.Mode() << endl;
    cout << "v2 的模长：" << v2.Mode() << endl;

    // 运算
    NVector vAdd = v1.Plus(v2);
    NVector vSub = v1.Sub(v2);
    ElemType dot = v1.DotProduct(v2);
    cout << endl;
    cout << "v1 + v2 = "; vAdd.Print(); cout << endl;
    cout << "v1 - v2 = "; vSub.Print(); cout << endl;
    cout << "v1 * v2 = " << dot << endl;

    return 0;
}