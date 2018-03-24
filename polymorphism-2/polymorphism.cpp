#include <iostream>

using namespace std;
class shape
{
	protected:
	    int width, hight;
	 
	public:
	    shape(int a=0, int b=0)
		{
			width = a;
			hight = b;
		}
		
		virtual int area()
		{
			cout<<"parent class area:"<<endl;
			return 0;
		}
};

class rectangle: public shape
{
	public:
	    rectangle(int a=0, int b=0):shape(a,b)
		{
			width = a;
			hight = b;
		}
		
		int set_rectangle_area(int a, int b)
		{
			width = a;
			hight = b;
			return 0;
		}
		
		int get_rectangle_area()
		{
			return width*hight;
		}
		
		int area()
		{			
			cout <<"rectangle class area:"<<get_rectangle_area()<<endl;
			return get_rectangle_area();
		}
		
	private:
		int width, hight;
};

class triangle: public shape
{
	public:
	    triangle(int a=0, int b=0):shape(a, b)
		{
			width = a;
			hight = b;
		}
		
		int set_triangle_area(int a, int b)
		{
			width = a;
			hight = b;
			return 0;
		}
		
		int get_triangle_area()
		{
			return width*hight/2;
		}
		
		int area()
		{	
			cout<<"triangle class area:"<<get_triangle_area()<<endl;
			return get_triangle_area();
		}
		
	private:
		int width, hight;
		
};

int main()
{
	shape *sha;
	rectangle rec(10, 7);
	triangle tri(10,5);
	
	sha = &rec;
	sha->area();
	
	rec.set_rectangle_area(20, 7);
	rec.area();
	
	sha = &tri;
	sha->area();
	
	tri.set_triangle_area(20, 5);
	tri.area();
}
