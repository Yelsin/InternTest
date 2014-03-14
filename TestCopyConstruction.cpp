#include <iostream>
using namespace std;

class MyString
{
public:
	MyString(const char* str); // 普通构造函数
	MyString(const MyString& other); // 拷贝构造函数
	~MyString(); // 析构函数
	MyString& operator=(const MyString& other); // 赋值函数
	
	void fun(const MyString& str); // 测试在类中访问私有成员的函数

private:
	char* m_String;
};


// 普通构造函数
MyString::MyString(const char* str)
{
	cout<<"commen construction"<<endl;

	if (NULL == str)
	{
		m_String = new char[1];
		*m_String = '\0';
	}
	else
	{
		int len = strlen(str);
		m_String = new char[len+1];
		strcpy(m_String, str);
	}
}

// 拷贝构造函数
MyString::MyString(const MyString& other)
{
	cout<<"copy construction"<<endl;

	int len = strlen(other.m_String);
	m_String = new char[len+1];
	strcpy(m_String, other.m_String); // 注意此处！私有变量m_String可以直接访问，因为这是在类MyString内部，访问的也是该类的私有成员
}

// 析构函数
MyString::~MyString()
{
	if (m_String!=NULL)
	{
		delete[] m_String;
		m_String = NULL;
	}
}

// 赋值函数
MyString& MyString::operator=(const MyString& other)
{
	cout << "assignment function"<<endl;

	// 第一步：判断当前对象与引用传递对象是否是同一个
	if (this == &other)
	{
		return *this;
	}

	// 第二步：释放当前对象的堆内存
	delete[] m_String;

	// 第三步：拷贝数据
	int len = strlen(other.m_String);
	cout << other.m_String<< endl;
	m_String = new char[len+1];
	strcpy(m_String, other.m_String);

	return *this;
}

// 通过此函数可以看出，在类中定义的函数，可以直接通过“对象名.私有变量”的方式访问私有变量
void MyString::fun(const MyString& str)
{
	cout<<str.m_String<<endl; // 程序正常，输出“hello”
}

int main()
{
	MyString str1("hello");
	//cout<<str1.m_String<<endl; // error!在类的外部的函数，不能直接访问类的私有成员
	MyString str2 = str1; // 复制构造函数
	MyString str3(str1); // 复制构造函数

	MyString str4("aaa"); // 初始化对象str4
	str4 = str1; // 赋值函数
	str4.fun(str1); // 可以正常运行，输出"hello"

	

	return 0;
}

