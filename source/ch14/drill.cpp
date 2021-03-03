#include "../std_lib_facilities.h"

class B1 
{
	public: virtual void vf() const
	{
		cout << "Function called: 'B1::vf()'" << endl;

	}

	public: void f() const
	{
		cout << "Function called: 'B1::f()'" << endl;
	}

	public: virtual void pvf() = 0;

};

class D1 : public B1
{
	public: virtual void vf() const override
	{
		cout << "Function called: 'D1::vf()'" << endl;

	}

	public: void f()
	{
		cout << "Function called: 'D1::f()'" << endl;
	}

	public: virtual void pvf()
	{
		cout << "Function called: 'D1::pvf()'" << endl;
	}

};


class D2 : public D1
{
	public: virtual void pvf() override
	{
		cout << "Function called: 'D2::pvf()'" << endl;
	}
};

class B2
{
	public: virtual void pvf() = 0;
};

class D21 : public B2
{
	public: string str;

	public: void pvf()
	{
		cout << "Msg: " << str << endl;
	}
};

class D22 : public B2
{
	public: int i;

	public: void pvf()
	{
		cout << "Int: " << i << endl;
	}
};

int main()
{
	//B1 b1;
	//b1.vf();
	//b1.f();

	cout << endl;

	D1 d1;
	d1.vf();
	d1.f();
	d1.pvf();

	cout << endl;
	
	B1 &br = d1;
	br.vf();
	br.f();
	br.pvf();

	cout << endl;

	D2 d2;
	d2.vf();
	d2.f();
	d2.pvf();

	cout << endl;

	D21 d21;
	d21.pvf();

	cout << endl;

	D22 d22;
	d22.pvf();
	
	return 0;
}