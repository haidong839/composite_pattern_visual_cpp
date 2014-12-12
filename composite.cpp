// composite.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <cliext/list> 
using namespace std;
using namespace System;



ref class Shape abstract
{ 
public:
	Shape(void)	{;}		
	virtual void draw(String^ fillColor) = 0;  
};

ref class Rectangle : Shape
{  
public:
	Rectangle(void){;}
	virtual void draw(String^ fillColor) override 
	{  
		Console::Write("Rectangle filled with "); 
		Console::Write(fillColor);
		Console::WriteLine(); 
	}  
	~Rectangle(void){;}
};

ref class Circle : Shape
{  
public:
	Circle(void){;}
	~Circle(void){;}
	virtual void draw(String^ fillColor) override 
	{  
		Console::Write("Circle filled with "); 
		Console::Write(fillColor);
		Console::WriteLine(); 
	}   
};


ref class Drawing : Shape {
private:
	cliext::list<Shape^>^ shapes;	

public:    
	Drawing(){
		shapes = gcnew cliext::list<Shape^>;
	}
	~Drawing(){;}
	virtual void draw(String^ fillColor) override {		
		for each (Shape^ elem in shapes) 
		{
			elem->draw(fillColor);
		}
	}

	void add(Shape^ s){
		this->shapes->push_back(s);
	}

	void remove(Shape^ s){
		shapes->remove(s);
	}

	void clear(){
		Console::WriteLine("Clearing all the shapes from drawing");
		this->shapes->clear();
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	Shape^ tri = gcnew Rectangle();
	Shape^ tri1 = gcnew Rectangle();
	Shape^ cir = gcnew Circle();

	Drawing^ drawing = gcnew Drawing();
	drawing->add(tri1);
	drawing->add(tri1);
	drawing->add(cir);

	drawing->draw("Red");

	drawing->clear();

	drawing->add(tri);
	drawing->add(cir);
	drawing->draw("Green");
	Console::ReadLine();
	return 0;
}

