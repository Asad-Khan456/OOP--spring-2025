#include "iostream"
#include "string"
using namespace std;

class Shape{
protected:
    int position;
    string color;
    float border_thickness;
public:
    Shape(int position, string color, float border_thickness)
        : position(position), color(color), border_thickness(border_thickness) {}
    virtual void draw()= 0;
    virtual void calculateArea() =0;
    virtual void calcPerimeter() = 0;
    virtual ~Shape(){}
};
class Circle :public Shape{
    float radius;
    int origin;
public:
    Circle(int position, string color, float border_thickness, float radius, int origin)
        : Shape(position, color, border_thickness), radius(radius), origin(origin) {}
    void draw()override{
        cout << "Drawing Circle at positoin " << position << ", color: " << color
             << ", border thickness: " << border_thickness << ", radius: " << radius << endl;
    }


    
    void calculateArea()override{
        float area = 3.142f * radius * radius; 
        cout << "Area of Circle:" << area << endl;
    }
    void calcPerimeter()override{
        float perimeter = 2 * 3.142f * radius;
        cout << "Perimeter of Circle: " << perimeter << endl;
    }
};
class Rectangle : public Shape{
    float width, height;
public:
    Rectangle(int position, string color, float border_thickness, float width, float height)
        : Shape(position, color, border_thickness), width(width), height(height) {}
    void draw() override {
        cout << "Drawing Rectangle at position " << position << ", color: " << color
             << ", border thickness: " << border_thickness << ", width: " << width << ", height: " << height << endl;
    }
    void calculateArea() override{
        float area = width * height;
        cout << "Area of Rectangle: " << area << endl;
    }
    void calcPerimeter()override{
        float perimeter = 2 * (width + height);
        cout << "Perimeter of Rectangle: " << perimeter << endl;
    }
};
int main(){
    Circle circle(0, "Yellow", 1.5, 6.0, 0);
    Rectangle rectangle(1, "Blue", 2.0, 4.0, 6.0);
    Shape* shapes[2];
    shapes[0] = &circle;
    shapes[1] = &rectangle;
    for (int i = 0; i < 2; ++i) {
        shapes[i]->draw();
        shapes[i]->calculateArea();
        shapes[i]->calcPerimeter();
        cout << endl;
    }
    return 0;
}
