#include <iostream>

using namespace std;

class Shape {
public:
    virtual void getShape() = 0;
};

class Point : public Shape {
    double coord_x, coord_y;
public:
    Point(double x, double y) {
      this->coord_x = x;
      this->coord_y = y;
    }

    void getShape() override {
        cout << "\n ------------------- " << endl;
        cout << "Point coordinates are: x = " << this->coord_x << ", and y = " << this->coord_y << endl;
        cout << " ------------------- " << endl;
    }
};

class Circle : public Shape {
    Shape* point;
    double radius;

public:
    Circle(Shape* p, double r) {
        this->point = p;
        this->radius = r;
    }

    void getShape() override {
        cout << "The Circle point is: " << endl;
        point->getShape();
        cout << "And the circle radius is: " << this->radius << endl;
        cout << " ------------------- " << endl;

    }
};

class Rectangle : public Shape {
    Shape* point_one;
    Shape* point_two;
public:
    Rectangle(Shape* p1, Shape* p2) {
        this->point_one = p1;
        this->point_two = p2;
    }

    void getShape() override {
        cout << "The Rectangle points are.." << endl;
        cout << "------- Point one -------" << endl;
        point_one->getShape();
        cout << "------- Point two -------" << endl;
        point_two->getShape();
        cout << " ------------------- " << endl;

    }
};

class Triangle : public Shape {
    Shape* point_one;
    Shape* point_two;
    Shape* point_three;

public:
    Triangle(Shape* p1, Shape* p2, Shape *p3) {
        this->point_one = p1;
        this->point_two = p2;
        this->point_three = p3;
    }

    void getShape() override {
        cout << "The Triangle points are.." << endl;
        cout << "------- Point one -------" << endl;
        point_one->getShape();
        cout << "------- Point two -------" << endl;
        point_two->getShape();
        cout << "------- Point three -------" << endl;
        point_three->getShape();
        cout << " ------------------- " << endl;
    }
};

class AbstractFactory {
public:
    virtual Shape* createPoint(double x, double y) = 0;
    virtual Shape* createCircle(Shape* p, double r) = 0;
    virtual Shape* createRectangle(Shape* p1, Shape* p2) = 0;
    virtual Shape* createTriangle(Shape* p1, Shape* p2, Shape* p3) = 0;
};

class AbstractFactoryConcreta : public AbstractFactory {
public:
    Shape* createPoint(double x, double y) override {
        return new Point(x, y);
    }

    Shape* createCircle(Shape* p, double r) override {
        return new Circle(p, r);
    }

    Shape* createRectangle(Shape* p1, Shape* p2) override {
        return new Rectangle(p1, p2);
    }

    Shape* createTriangle(Shape* p1, Shape* p2, Shape* p3) override {
        return new Triangle(p1, p2, p3);
    }
};

int main() {
    AbstractFactoryConcreta* factory = new AbstractFactoryConcreta();
    Shape* point = factory->createPoint(4.7, 3.5);
    Shape* cirlce = factory->createCircle(point, 6.4);
    Shape* rectangle = factory->createRectangle(point, factory->createPoint(7.2, 5.8));
    Shape* triangle = factory->createTriangle(factory->createPoint(4.6, 8.45),
                                              factory->createPoint(5.27, 9.3),
                                              factory->createPoint(2.55, 6.44));

    point->getShape();
    cirlce->getShape();
    rectangle->getShape();
    triangle->getShape();

    return 0;
}