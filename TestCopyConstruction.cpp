#include <iostream>
using namespace std;

class MyString
{
public:
	MyString(const char* str); // ��ͨ���캯��
	MyString(const MyString& other); // �������캯��
	~MyString(); // ��������
	MyString& operator=(const MyString& other); // ��ֵ����
	
	void fun(const MyString& str); // ���������з���˽�г�Ա�ĺ���

private:
	char* m_String;
};


// ��ͨ���캯��
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

// �������캯��
MyString::MyString(const MyString& other)
{
	cout<<"copy construction"<<endl;

	int len = strlen(other.m_String);
	m_String = new char[len+1];
	strcpy(m_String, other.m_String); // ע��˴���˽�б���m_String����ֱ�ӷ��ʣ���Ϊ��������MyString�ڲ������ʵ�Ҳ�Ǹ����˽�г�Ա
}

// ��������
MyString::~MyString()
{
	if (m_String!=NULL)
	{
		delete[] m_String;
		m_String = NULL;
	}
}

// ��ֵ����
MyString& MyString::operator=(const MyString& other)
{
	cout << "assignment function"<<endl;

	// ��һ�����жϵ�ǰ���������ô��ݶ����Ƿ���ͬһ��
	if (this == &other)
	{
		return *this;
	}

	// �ڶ������ͷŵ�ǰ����Ķ��ڴ�
	delete[] m_String;

	// ����������������
	int len = strlen(other.m_String);
	cout << other.m_String<< endl;
	m_String = new char[len+1];
	strcpy(m_String, other.m_String);

	return *this;
}

// ͨ���˺������Կ����������ж���ĺ���������ֱ��ͨ����������.˽�б������ķ�ʽ����˽�б���
void MyString::fun(const MyString& str)
{
	cout<<str.m_String<<endl; // ���������������hello��
}

int main()
{
	MyString str1("hello");
	//cout<<str1.m_String<<endl; // error!������ⲿ�ĺ���������ֱ�ӷ������˽�г�Ա
	MyString str2 = str1; // ���ƹ��캯��
	MyString str3(str1); // ���ƹ��캯��

	MyString str4("aaa"); // ��ʼ������str4
	str4 = str1; // ��ֵ����
	str4.fun(str1); // �����������У����"hello"

	

	return 0;
}

