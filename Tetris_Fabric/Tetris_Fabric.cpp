#include <iostream>
using namespace std;

class Shape abstract
{
public:
	virtual void Print() abstract;
};


class shapeYellow : public Shape
{
public:

	bool s[4][4] = {{0,1,0,0},
					{1,1,1,0},
					{0,0,0,0},
					{0,0,0,0}};

	unsigned char color[3] = { ' ',' ',' ' };

	string sName = "yellow";

	void Print() override
	{
		cout << "YellowShape\n";
	}
};

class shapeRed : public Shape
{
public:

	bool s[4][4] = {{1,1,0,0},
					{0,1,1,0},
					{0,0,0,0},
					{0,0,0,0}};

	unsigned char color[3] = { 'r','r','r' };

	string sName = "red";

	void Print() override
	{
		cout << "RedShape\n";
	}
};

class shapeBlue : public Shape
{
public:

	bool s[4][4] = {{1,0,0,0},
					{1,1,1,1},
					{0,0,0,0},
					{0,0,0,0} };

	unsigned char color[3] = { 'b','b','b' };

	string sName = "blue";

	void Print() override
	{
		cout << "YellowShape\n";
	}
};

class shapeLine : public Shape
{
public:

	bool s[4][4] = {{0,1,0,0},
					{0,1,0,0},
					{0,1,0,0},
					{0,1,0,0} };

	unsigned char color[3] = { 'b','b','b' };

	string sName = "line";

	void Print() override
	{
		cout << "LineShape\n";
	}
};

class shapeGreen : public Shape
{
public:

	bool s[4][4] = {{0,1,1,0},
					{0,1,0,0},
					{1,1,0,0},
					{0,0,0,0} };

	unsigned char color[3] = { 'g','g','g' };

	string sName = "green";

	void Print() override
	{
		cout << "GreenShape\n";
	}
};

class shapeBrown : public Shape
{
public:

	bool s[4][4] = {{1,1,1,0},
					{1,0,0,0},
					{0,0,0,0},
					{0,0,0,0} };

	unsigned char color[3] = { 'r','b','b' };

	string sName = "brown";

	void Print() override
	{
		cout << "BrownShape\n";
	}
};

class Developer abstract
{

public:
	virtual Shape* Create() = 0;
};


class YellowShapeDeveloper : public Developer
{
public:
	Shape* Create() override
	{
		return new shapeYellow;
	}
};

class BlueShapeDeveloper : public Developer
{
public:
	Shape* Create() override
	{
		return new shapeBlue;
	}
};

class BrownShapeDeveloper : public Developer
{
public:
	Shape* Create() override
	{
		return new shapeBrown;
	}
};

class GreenShapeDeveloper : public Developer
{
public:
	Shape* Create() override
	{
		return new shapeGreen;
	}
};

class LineShapeDeveloper : public Developer
{
public:
	Shape* Create() override
	{
		return new shapeLine;
	}
};

class RedShapeDeveloper : public Developer
{
public:
	Shape* Create() override
	{
		return new shapeRed;
	}
};

class Client
{
	Developer* pDev;

public:
	Client(Developer* p)
	{
		pDev = p;
	}
	Shape* Create()
	{
		return pDev->Create();
	}
};

void ClientFunc(Developer* pDev)
{
	Client* client = nullptr;
	client = new Client(pDev);
	Shape* pShape = client->Create();
	pShape->Print();
	delete pShape;
	delete client;
}

void main()
{
	Developer* blueDev = new BlueShapeDeveloper();
	ClientFunc(blueDev);
	delete blueDev;

	Developer* brownDev = new BrownShapeDeveloper();
	ClientFunc(brownDev);
	delete brownDev;

	Developer* greenDev = new GreenShapeDeveloper();
	ClientFunc(greenDev);
	delete greenDev;

	Developer* lineDev = new LineShapeDeveloper();
	ClientFunc(lineDev);
	delete lineDev;

	Developer* redDev = new RedShapeDeveloper();
	ClientFunc(redDev);
	delete redDev;

	Developer* yellowDev = new YellowShapeDeveloper();
	ClientFunc(yellowDev);
	delete yellowDev;


	system("pause");
}