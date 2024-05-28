
#include <iostream>
#include <string>
#include <Windows.h>


class Shape {
private:
    //std::string name;
public:
    void virtual Scale(float scaleFactor) = 0;

    void virtual ShowInfo() = 0;

    std::string virtual GetName() = 0;

};

class Shape2D : public Shape {
protected:
    float area = 0;
    void virtual CalculateArea() = 0;

public:

    float GetArea() {
        CalculateArea();
        return area;
    }

    bool operator> (Shape2D* shape) {
        return area > shape->GetArea(); // a->f = *(&(a)).f
    }

    bool operator< (Shape2D* shape) {
        return !(area > shape->GetArea());
    }

    bool operator== (Shape2D* shape) {
        return area == shape->area;
    }
};

class Circle : public Shape2D {

private:
    float radius;
    void CalculateArea() override {
        area = radius * radius * 3, 1415;
    }

public:
    Circle(float radius)
        :radius(radius) {}

    void Scale(float scaleFactor) override
    {

        radius *= scaleFactor;
        CalculateArea();

    };

    void ShowInfo() override
    {
        std::cout << "Я - " << GetName() << "Моя площадь - " << GetArea() << "!\n\tМой радиус - " << radius << "!\n";
    }

    std::string GetName() override
    {
        return "круг!\n\t";
    }

};

class Triangle : public Shape2D {

private:

    float base;
    float height;

    void CalculateArea() override {
        area = base * height / 2;
    }

public:

    Triangle(float base, float height)
        : base(base), height(height) {}

    void Scale(float scaleFactor) override
    {

        base *= scaleFactor;
        height *= scaleFactor;
        CalculateArea();

    };

    void ShowInfo() override
    {
        std::cout << "Я - " << GetName() << "Моя площадь - " << GetArea() << "!\n\tМоё основание - " << base << "!\n\tМоя высота - " << height << "!\n";
    }

    std::string GetName() override
    {
        return "треугольник!\n\t";
    }



};

class Square :public Shape2D {
private:
    float side;
    void CalculateArea() override {
        area = side * side;
    }
public:
    Square(float side)
        : side(side) {}

    void Scale(float scaleFactor) override
    {

        side *= scaleFactor;
        CalculateArea();

    };

    void ShowInfo() override
    {
        std::cout << "Я - " << GetName() << "Моя площадь - " << GetArea() << "!\n\tМоя сторона - " << side << "!\n";
    }

    std::string GetName() override
    {
        return "квадрат!\n\t";
    }


};

class Shape3D : public Shape
{
protected:
    float volume = 0;
    void virtual CalculateVolume() = 0;
public:
    void GetVolume() {
        CalculateVolume();
        std::cout << "\n\tМой объём - " << volume << "!!!\n\t";
    }

    bool operator> (Shape3D* shape) {
        return volume > shape->volume;
    }

    bool operator< (Shape3D* shape) {
        return !(volume > shape->volume);
    }

    bool operator== (Shape3D* shape) {
        return volume == shape->volume;
    }
};

class TriangularPiramid : public Shape3D
{
private:
    Triangle* triangle;
    float height;
    void CalculateVolume() override {
        volume = triangle->GetArea() * height / 3;
    }
public:
    TriangularPiramid(Triangle* triangle, float height)
        : triangle(triangle), height(height) {}

    void Scale(float scaleFactor) override
    {

        triangle->Scale(scaleFactor);
        height *= scaleFactor;
        CalculateVolume();

    };

    void ShowInfo() override
    {
        std::cout << "Я - " << GetName();
        GetVolume();
        std::cout << "Площадь моего основания - " << triangle->GetArea() << "!\n\tМоя высота - " << height << "!\n";
    }

    std::string GetName() override
    {
        return "треугольная пирамида!\n\t";
    }



};

class Cylinder : public Shape3D
{
private:
    Circle* circle;
    float height;
    void CalculateVolume() override {
        volume = circle->GetArea() * height;
    }
public:
    Cylinder(Circle* circle, float height)
        : circle(circle), height(height) {}

    void Scale(float scaleFactor) override
    {

        circle->Scale(scaleFactor);
        height *= scaleFactor;
        CalculateVolume();

    };

    void ShowInfo() override
    {
        std::cout << "Я - " << GetName();
        GetVolume();
        std::cout << "Площадь моего основания - " << circle->GetArea() << "!\n\tМоя высота - " << height << "!\n";
    }

    std::string GetName() override
    {
        return "цилиндр!\n\t";
    }

};

class Sphere : public Shape3D
{
private:
    float radius;
    void CalculateVolume() override {
        volume = 4 * 3.1415 * pow(radius, 2) / 3;
    }
public:
    Sphere(float radius)
        : radius(radius) {}

    void Scale(float scaleFactor) override
    {

        radius *= scaleFactor;
        CalculateVolume();;

    };

    void ShowInfo() override
    {
        std::cout << "Я - " << GetName();
        GetVolume();
        std::cout << "Мой радиус - " << radius << "!\n";
    }

    std::string GetName() override
    {
        return "шар!\n\t";
    }


};

void test() {

    Triangle triangle(3.2, 4);
    triangle.ShowInfo();
    std::cout << std::endl;
    triangle.Scale(5);
    triangle.ShowInfo();
    std::cout << std::endl;

    Circle circle(5.5);
    circle.ShowInfo();
    std::cout << std::endl;
    circle.Scale(5);
    circle.ShowInfo();
    std::cout << std::endl;

    Square square(7.5);
    square.ShowInfo();
    std::cout << std::endl;
    square.Scale(5);
    square.ShowInfo();
    std::cout << std::endl;

    TriangularPiramid piramid(&triangle, 14);
    piramid.ShowInfo();
    std::cout << std::endl;
    piramid.Scale(1.5);
    piramid.ShowInfo();
    std::cout << std::endl;
    triangle.Scale(0.67);
    piramid.ShowInfo();
    std::cout << std::endl;

    Cylinder cylinder(&circle, 8);
    cylinder.ShowInfo();
    std::cout << std::endl;
    cylinder.Scale(1.5);
    cylinder.ShowInfo();
    std::cout << std::endl;
    circle.Scale(0.67);
    cylinder.ShowInfo();
    std::cout << std::endl;

    Sphere sphere(4.9);
    sphere.ShowInfo();
    std::cout << std::endl;
    sphere.Scale(1.5);
    sphere.ShowInfo();
    std::cout << std::endl;

    if (circle > &triangle) std::cout << "проверка оператора >" << std::endl;
    if (triangle < &circle) std::cout << "проверка оператора <" << std::endl;
    if (!(circle == &triangle)) std::cout << "проверка оператора ==" << std::endl;

    if (cylinder > &piramid) std::cout << "проверка оператора >" << std::endl;
    if (piramid < &cylinder) std::cout << "проверка оператора <" << std::endl;
    if (!(cylinder == &piramid)) std::cout << "проверка оператора ==" << std::endl;

}

int main()
{
    setlocale(LC_ALL, "rus");     // Изменение кодировки программы
    SetConsoleOutputCP(1251);     // Изменение кодировки консоли
    SetConsoleCP(1251);
    system("chcp 1251");

    test();
}