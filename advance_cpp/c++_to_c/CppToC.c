#include <stdlib.h>
#include <stdio.h>

/********************************************
*                    EMPTY                  *
********************************************/

typedef struct 
{
}Empty;

typedef struct 
{
	Empty m_empty;
	int m_i;	
}EmptyEmpty;

typedef struct 
{
	Empty m_e1;
	Empty m_e2;
	EmptyEmpty m_ee;
}EmptyBag;

/*************empty***********/

void Empty_Create(Empty* _empty)
{
	printf("Empty::Empty(0)\n");
}

void Empty_Create_int(Empty* _empty, int _id)
{
	printf("Empty::Empty(%d)\n", _id);
}

void Empty_Destroy(Empty* _empty)
{
	puts("Empty::~Empty()");
}

/**********empty empty*********/

void EmptyEmpty_Create(EmptyEmpty* _ee, int _id)
{
	Empty_Create(&(_ee->m_empty));
	_ee->m_i = _id;
	printf("EmptyEmpty::EmptyEmpty(%d)\n", _ee->m_i); 
}

void EmptyEmpty_Destroy(EmptyEmpty* _ee)
{
	Empty_Destroy(&(_ee->m_empty));
}

/***********empty bag**********/

void EmptyBag_Create(EmptyBag* _eb)
{
	Empty_Create_int(&(_eb->m_e1), 1);
	Empty_Create_int(&(_eb->m_e2), 2);
	EmptyEmpty_Create(&(_eb->m_ee), 2);
	
	puts("EmptyBag::EmptyBag()");
}

void EmptyBag_Destroy(EmptyBag* _eb)
{
	puts("EmptyBag::~EmptyBag");
	
	EmptyEmpty_Destroy(&(_eb->m_ee));
	Empty_Destroy(&(_eb->m_e2));
	Empty_Destroy(&(_eb->m_e1));	
}

/********************************************
*                SCALEABLE                  *
********************************************/

typedef enum { RED, GREEN, DEFAULT }ColorEnum;
static void setColor(ColorEnum color)
{		
	static const char * pallete[] = { "\x1B[31m", "\x1B[32m", "\033[0m" };
	puts(pallete[color]);
}

typedef int(*VirtualFunc)(int);
static VirtualFunc* scaleableFuncArr = 0;

typedef struct
{
	VirtualFunc* m_funcArr;
}Scaleable;

void Scaleable_Destroy(Scaleable* _s);
void Scaleable_Scale(Scaleable* _s);
void Scaleable_Scale_double(Scaleable* _s, double _d);

void Scaleable_Init()
{
	scaleableFuncArr = (VirtualFunc*)calloc(3, sizeof(VirtualFunc));
	if(scaleableFuncArr)
	{
		scaleableFuncArr[0] = (VirtualFunc)Scaleable_Destroy;
		scaleableFuncArr[1] = (VirtualFunc)Scaleable_Scale;
		scaleableFuncArr[2] = (VirtualFunc)Scaleable_Scale_double;
	}
}

void Scaleable_Create(Scaleable* _s)
{
	_s->m_funcArr = scaleableFuncArr;
}

void Scaleable_Destroy(Scaleable* _s)
{
	_s->m_funcArr = 0;
}
	
void Scaleable_Scale(Scaleable* _s)
{}

void Scaleable_Scale_double(Scaleable* _s, double _d)
{}

/********************************************
*                   SHAPE                   *
********************************************/

static int NumOfShapes = 0;
static VirtualFunc* shapeFuncArr = 0;

typedef struct 
{
	Scaleable m_scaleable;
	int m_id;
}Shape;

void Shape_Destroy(Shape* _shape);
void Shape_Scale(Shape* _shape);
void Shape_Scale_double(Shape* _shape, double _f);
void Shape_Draw(const Shape* _shape);
void Shape_Draw_color(const Shape* _shape, ColorEnum _c);
double Shape_Area(const Shape* _shape);

void Shape_Init()
{
	shapeFuncArr = (VirtualFunc*)calloc(6, sizeof(VirtualFunc));
	if(shapeFuncArr)
	{
		shapeFuncArr[0] = (VirtualFunc)Shape_Destroy;
		shapeFuncArr[1] = (VirtualFunc)Shape_Scale;
		shapeFuncArr[2] = (VirtualFunc)Shape_Scale_double;
		shapeFuncArr[3] = (VirtualFunc)Shape_Draw;
		shapeFuncArr[4] = (VirtualFunc)Shape_Draw_color;
		shapeFuncArr[5] = (VirtualFunc)Shape_Area;
	}
}

void Shape_Create(Shape* _shape)
{
	Scaleable_Create(&(_shape->m_scaleable));
	(_shape->m_scaleable).m_funcArr = shapeFuncArr;
	_shape->m_id = ++NumOfShapes;
	printf("Shape::Shape() - %d\n", _shape->m_id);
}

void Shape_Destroy(Shape* _shape)
{
	Shape_Draw(_shape);
	--NumOfShapes; 
	printf("Shape::~Shape - %d\n", _shape->m_id);
	Scaleable_Destroy(&(_shape->m_scaleable));
}

void Shape_Create_shape(Shape* _shape, const Shape* _other)
{
	Scaleable_Create(&(_shape->m_scaleable));
	(_shape->m_scaleable).m_funcArr = shapeFuncArr;
	_shape->m_id = ++NumOfShapes;	
	printf("Shape::Shape(Shape&) - %d from - %d\n", _shape->m_id, _other->m_id);
}

void Shape_Draw(const Shape* _shape)
{
	printf("Shape::draw() - %d\n", _shape->m_id);
}

void Shape_Draw_color(const Shape* _shape, ColorEnum _c)	
{
	printf("Shape::draw(c) - %d\n", _shape->m_id);
	setColor(_c);
	Shape_Draw(_shape);
	setColor(DEFAULT);
}
	
void Shape_Scale(Shape* _shape)
{
	printf("Shape::scale(%f)\n", (double)1);
}

void Shape_Scale_double(Shape* _shape, double _f)
{
	printf("Shape::scale(%f)\n", _f);
}

double Shape_Area(const Shape* _shape)
{
	return -1;
}	
	
static void Shape_PrintInventory() 
{
	printf("Shape::printInventory - %d\n", NumOfShapes);
}

/*Shape& operator=(const Shape &);*/

/********************************************
*                  CIRCLE                   *
********************************************/

static VirtualFunc* circleFuncArr = 0;

typedef struct
{
	Shape m_shape;
	double m_radius;
}Circle; 

void Circle_Destroy(Circle* _circle);
void Circle_Draw(const Circle* _circle);
void Circle_Scale(Circle* _circle);
void Circle_Scale_double(Circle* _circle, double _r);
double Circle_Area(const Circle* _circle);

void Circle_Init()
{
	circleFuncArr = (VirtualFunc*)calloc(6, sizeof(VirtualFunc));
	if(circleFuncArr)
	{
		circleFuncArr[0] = (VirtualFunc)Circle_Destroy;
		circleFuncArr[1] = (VirtualFunc)Circle_Scale;
		circleFuncArr[2] = (VirtualFunc)Circle_Scale_double;
		circleFuncArr[3] = (VirtualFunc)Circle_Draw;
		circleFuncArr[4] = shapeFuncArr[4];
		circleFuncArr[5] = (VirtualFunc)Circle_Area;
	}
}

void Circle_Create(Circle* _circle)
{
	Shape_Create(&(_circle->m_shape));
	(_circle->m_shape).m_scaleable.m_funcArr = circleFuncArr;
	_circle->m_radius = 1;
	printf("Circle::Circle() - %d, r:%f\n", (_circle->m_shape).m_id, _circle->m_radius); 
}

void Circle_Create_double(Circle* _circle, double _r)
{
	Shape_Create(&(_circle->m_shape));
	(_circle->m_shape).m_scaleable.m_funcArr = circleFuncArr;
	_circle->m_radius = _r;
	printf("Circle::Circle(double) - %d, r:%f\n", (_circle->m_shape).m_id, _circle->m_radius);
}

void Circle_Create_circle(Circle* _circle, const Circle* _other)
{
	Shape_Create_shape(&(_circle->m_shape), &(_other->m_shape));
	(_circle->m_shape).m_scaleable.m_funcArr = circleFuncArr;
	_circle->m_radius = _other->m_radius;
	printf("Circle::Circle(Circle&) - %d, r:%f\n", (_circle->m_shape).m_id, _circle->m_radius);
}

void Circle_Destroy(Circle* _circle)
{
	printf("Circle::~Circle() - %d, r:%f\n", (_circle->m_shape).m_id, _circle->m_radius);
	Shape_Destroy(&(_circle->m_shape));
}

void Circle_Draw(const Circle* _circle)
{
	printf("Circle::draw()  - %d, r:%f\n", (_circle->m_shape).m_id, _circle->m_radius);
}

void Circle_Scale(Circle* _circle)
{
	printf("Circle::scale(%f)\n", (double)1);
	_circle->m_radius *= 1;
}

void Circle_Scale_double(Circle* _circle, double _r)
{
	printf("Circle::scale(%f)\n", _r);
	_circle->m_radius *= _r;
}

double Circle_Area(const Circle* _circle)
{
	return _circle->m_radius * _circle->m_radius * 3.1415;
}
    
double Circle_Radius(const Circle* _circle)
{
	printf("Circle::draw()  - %d, r:%f\n", (_circle->m_shape).m_id, _circle->m_radius);
	return _circle->m_radius;
}

/********************************************
*                RECTANGLE                  *
********************************************/

static VirtualFunc* rectangleFuncArr = 0;

typedef struct
{
	Shape m_shape;
	int m_a;
	int m_b;
}Rectangle;

void Rectangle_Destroy(Rectangle* _rectangle);
void Rectangle_Draw(const Rectangle* _rectangle);
void Rectangle_Draw_color(const Rectangle* _rectangle, ColorEnum _c);
void Rectangle_Scale(Rectangle* _rectangle);
void Rectangle_Scale_double(Rectangle* _rectangle, double _f);
double Rectangle_Area(const Rectangle* _rectangle);

void Rectangle_Init()
{
	rectangleFuncArr = (VirtualFunc*)calloc(6, sizeof(VirtualFunc));
	if(rectangleFuncArr)
	{
		rectangleFuncArr[0] = (VirtualFunc)Rectangle_Destroy;
		rectangleFuncArr[1] = (VirtualFunc)Rectangle_Scale;
		rectangleFuncArr[2] = (VirtualFunc)Rectangle_Scale_double;
		rectangleFuncArr[3] = (VirtualFunc)Rectangle_Draw;
		rectangleFuncArr[4] = (VirtualFunc)Rectangle_Draw_color;
		rectangleFuncArr[5] = (VirtualFunc)Rectangle_Area;
	}
}

void Rectangle_Create(Rectangle* _rectangle)
{
	Shape_Create(&(_rectangle->m_shape));
	(_rectangle->m_shape).m_scaleable.m_funcArr = rectangleFuncArr;
	_rectangle->m_a = 1;
	_rectangle->m_b = 1;
	printf("Rectangle::Rectangle() - %d, [%d, %d]\n", (_rectangle->m_shape).m_id, _rectangle->m_a, _rectangle->m_b);
}

void Rectangle_Create_int(Rectangle* _rectangle, int _a)
{
	Shape_Create(&(_rectangle->m_shape));
	(_rectangle->m_shape).m_scaleable.m_funcArr = rectangleFuncArr;
	_rectangle->m_a = _a;
	_rectangle->m_b = _a;
	printf("Rectangle::Rectangle(int) - %d, [%d, %d]\n", (_rectangle->m_shape).m_id, _rectangle->m_a, _rectangle->m_b);
}

void Rectangle_Create_int_int(Rectangle* _rectangle, int _a, int _b)
{
	Shape_Create(&(_rectangle->m_shape));
	(_rectangle->m_shape).m_scaleable.m_funcArr = rectangleFuncArr;
	_rectangle->m_a = _a;
	_rectangle->m_b = _b;
	printf("Rectangle::Rectangle(int, int) - %d, [%d, %d]\n", (_rectangle->m_shape).m_id, _rectangle->m_a, _rectangle->m_b);
}

void Rectangle_Create_rectangle(Rectangle* _rectangle, const Rectangle* _other)
{
	Shape_Create_shape(&(_rectangle->m_shape), &(_other->m_shape));
	(_rectangle->m_shape).m_scaleable.m_funcArr = rectangleFuncArr;
	_rectangle->m_a = _other->m_a;
	_rectangle->m_b = _other->m_b;
	printf("Rectangle::Rectangle(Rectangle&) - %d, a:%d/%d\n", (_rectangle->m_shape).m_id, _rectangle->m_a, _rectangle->m_b);
}
	
void Rectangle_Destroy(Rectangle* _rectangle)
{
	printf("Rectangle::~Rectangle() - %d, [%d, %d]\n", (_rectangle->m_shape).m_id, _rectangle->m_a, _rectangle->m_b);
	Shape_Destroy(&(_rectangle->m_shape));
}
	
void Rectangle_Draw(const Rectangle* _rectangle)
{
	printf("Rectangle::draw()  - %d, [%d, %d]\n", (_rectangle->m_shape).m_id, _rectangle->m_a, _rectangle->m_b);
}

void Rectangle_Draw_color(const Rectangle* _rectangle, ColorEnum _c)
{
	printf("Rectangle::draw(%d)  - %d, [%d, %d]\n", _c, (_rectangle->m_shape).m_id, _rectangle->m_a, _rectangle->m_b);
}

void Rectangle_Scale(Rectangle* _rectangle)
{
	printf("Rectangle::scale(%f)\n", (double)1);
	_rectangle->m_a *= 1;
	_rectangle->m_b *= 1;
}

void Rectangle_Scale_double(Rectangle* _rectangle, double _f)
{
	printf("Rectangle::scale(%f)\n", _f);
	_rectangle->m_a *= _f;
	_rectangle->m_b *= _f;
}

double Rectangle_Area(const Rectangle* _rectangle)
{
	return _rectangle->m_a * _rectangle->m_b;
}

/********************************************
*                 FUNCTIONS                 *
********************************************/

enum VirtFunctions{DESTROY = 0, SCALE, SCALED, DRAW, DRAWC, AREA};
static Circle unit1;
static Circle unit2;

void FreeAll()
{
	free(scaleableFuncArr);
	free(shapeFuncArr);
	free(circleFuncArr);
	free(rectangleFuncArr);
}

void Report(const Shape* _s) 
{
	puts("-----report-----");
	((void(*)(const Shape*))((_s->m_scaleable).m_funcArr[DRAW]))(_s); 
	Shape_PrintInventory();
	puts("-----report-----");
}

void Draw_shape(Shape* _s) 
{ 
	static int i = 0;
	
	puts("-----draw(Shape&)-----");
	((void(*)(Shape*))((_s->m_scaleable).m_funcArr[SCALE]))(_s);
	((void(*)(const Shape*))((_s->m_scaleable).m_funcArr[DRAW]))(_s); 
	
	static Circle unit;
	if(!i)
	{
		Circle_Create_double(&unit, 4);
	}
	
	puts("-----draw(Shape&)-----");
	++i;
	unit1 = unit;
}

void Draw_circle(Circle _c) 
{ 
	Circle c;
	Circle_Create_circle(&c, &_c);
	
	static int i = 0;
	
	puts("-----draw(Circle)-----");

    if(Circle_Area(&c) > 3.14)
    {
		static Circle unit;
    	if(!i)
    	{
			Circle_Create_double(&unit, 1);
    	}
	    
	    Circle_Draw(&unit);
	    Circle_Scale_double(&unit, 3);
		unit2 = unit;
    }
    
    Circle_Draw(&c);
	puts("-----draw(Circle)-----");
	
	Circle_Destroy(&c);
	++i;
}

void DoObjArray()
{
	Circle c1;
	Circle_Create(&c1);
	
	Shape s1;
	Shape_Create_shape(&s1, &(c1.m_shape));
	
    Circle_Destroy(&c1);
	
	Rectangle r;
	Rectangle_Create_int(&r, 4);
	
	Shape s2;
	Shape_Create_shape(&s2, &(r.m_shape));
	
	Rectangle_Destroy(&r);
		
	Circle c2;
	Circle_Create_double(&c2, 9);
	
	Shape s3;
	Shape_Create_shape(&s3, &(c2.m_shape));
	
	Circle_Destroy(&c2);
	
	Shape objects[] = {(Shape)s1, (Shape)s2, (Shape)s3};

    for(int i = 0; i < 3; ++i) 
    {
    	((void(*)(const Shape*))((objects[i].m_scaleable).m_funcArr[DRAW]))(&(objects[i]));
    }
    
	Shape_Destroy(&s3);
	Shape_Destroy(&s2);
    Shape_Destroy(&s1);
}

void Disappear() 
{
	puts("-----disappear-----");

	Circle defaultCircle();

	puts("-----disappear-----");
}


double DiffWhenDoubled_shape(Shape* _shape)
{
	double a0 = ((double(*)(const Shape*))((_shape->m_scaleable).m_funcArr[AREA]))(_shape); 
	((void(*)(Shape*, double))((_shape->m_scaleable).m_funcArr[SCALED]))(_shape, 2); 
	double a1 = ((double(*)(const Shape*))((_shape->m_scaleable).m_funcArr[AREA]))(_shape); 
	return a1 - a0;
}

double DiffWhenDoubled_circle(Circle* _circle)
{
	double a0 = Circle_Area(_circle);
	Circle_Scale_double(_circle, 2);
	double a1 = Circle_Area(_circle);
	return a1 - a0;
}

void DoPointerArray()
{
	puts("-----doPointerArray-----");
	
	Circle* c1 = malloc(sizeof(Circle));
	if(!c1)
	{
		return;
	}
	
	Circle_Create(c1);
	
	Rectangle* r = malloc(sizeof(Rectangle));
	if(!r)
	{
		free(c1);
		return;
	}
	
	Rectangle_Create_int(r, 3);
	
	Circle* c2 = malloc(sizeof(Circle));
	if(!c2)
	{
		return;
	}
	
	Circle_Create_double(c2, 4);
	
	Shape *array[] = {(Shape*)c1, (Shape*)r, (Shape*)c2};

    for(int i = 0; i < 3; ++i)
    { 
    	((void(*)(Shape*))((array[i]->m_scaleable).m_funcArr[SCALE]))(array[i]);
		((void(*)(const Shape*))((array[i]->m_scaleable).m_funcArr[DRAW]))(array[i]);
	}

	printf("area: %f\n", DiffWhenDoubled_shape(array[2]));

    for(int i = 0; i < 3; ++i) 
    { 
		((void(*)(Shape*))((array[i]->m_scaleable).m_funcArr[DESTROY]))(array[i]);
		free(array[i]);
		array[i] = 0; 
	}

	puts("-----doPointerArray-----");
}

void Dispose(Rectangle* _p, int _size)
{
	for(int i = _size - 1; i >= 0; --i)
	{
		Rectangle_Destroy(_p + i);
	}
	free(_p);
}


/********************************************
*                    MAIN                   *
********************************************/

int main(int argc, char **argv, char **envp)
{
	Scaleable_Init();
	Shape_Init();
	Circle_Init();
	Rectangle_Init();
	
	printf("---------------Start----------------\n"); 
    Circle c;
    Circle_Create(&c);
	Rectangle s;
	Rectangle_Create_int(&s, 4);
	
	printf("0.-------------------------------\n"); 
	Draw_circle(c);

	printf("+..............\n"); 		
	Draw_circle(c);

	printf("+..............\n"); 	
    Draw_shape((Shape*)&s);
	
	printf("+..............\n"); 		
	Report((Shape*)&c);
	
	printf("1.-------------------------------\n"); 
	
    DoPointerArray();
	
	printf("2.-------------------------------\n"); 

    DoObjArray();

	printf("3.-------------------------------\n"); 

    Shape_PrintInventory();
    Circle c2;
    Circle_Create_circle(&c2, &c);
    Shape_PrintInventory();
    
    printf("4.-------------------------------\n"); 
   
    Circle olympics[5];
    Circle_Create(olympics);
    Circle_Create(olympics + 1);
    Circle_Create(olympics + 2);
    Circle_Create(olympics + 3);
    Circle_Create(olympics + 4);
    
	printf("olympic diff %f\n", DiffWhenDoubled_circle(olympics + 1));

	printf("5.-------------------------------\n"); 

    Rectangle *fourRectangles = malloc(4 * sizeof(Rectangle));
    if(!fourRectangles)
    {
    	return -1;
    }
    
    Rectangle_Create(fourRectangles);
    Rectangle_Create(fourRectangles + 1);
    Rectangle_Create(fourRectangles + 2);
    Rectangle_Create(fourRectangles + 3);
    
    Dispose(fourRectangles, 4);

	printf("6.-------------------------------\n"); 
	EmptyBag eb;
	EmptyBag_Create(&eb);
	printf("Empty things are: %zu %zu %zu\n", sizeof(Empty), sizeof(EmptyEmpty), sizeof(EmptyBag));
	
	printf("7.-------------------------------\n"); 
	Disappear();
	
	printf("---------------END----------------\n"); 
	
	EmptyBag_Destroy(&eb);
    Circle_Destroy(olympics + 4);
    Circle_Destroy(olympics + 3);
    Circle_Destroy(olympics + 2);
    Circle_Destroy(olympics + 1);
    Circle_Destroy(olympics);
    
    Circle_Destroy(&c2);	
	Rectangle_Destroy(&s);
	Circle_Destroy(&c);
	FreeAll();
	
	Circle_Destroy(&unit1);
	Circle_Destroy(&unit2);
	return 0;
}


