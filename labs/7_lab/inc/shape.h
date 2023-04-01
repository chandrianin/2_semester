#pragma once

class Shape {
protected:
    std::string Color;
    double XCoordinates, YCoordinates;
public:
    Shape(const std::string& color, double xCoordinates, double yCoordinates) : Color(color), XCoordinates(xCoordinates), YCoordinates(yCoordinates) {};
    [[nodiscard]] virtual double getArea() const{
        std::cout << "ShapeArea";
        return 0;
    }
};

class Circle : public Shape {
protected:
    double Radius;

public:
    Circle(const std::string& color, double xCoordinates, double yCoordinates, double radius) : Shape(color, xCoordinates, yCoordinates), Radius(radius) {}
    [[nodiscard]] double getArea() const override {
        std::cout << "CircleArea ";
        return acos(-1) * Radius * Radius;
    }
};

class Triangle : public Shape {
protected:
    double FirstSide, SecondSide, ThirdSide;
public:
    Triangle(const std::string& color, double xCoordinates, double yCoordinates, double firstSide, double secondSide, double thirdSide) : Shape(color, xCoordinates, yCoordinates), FirstSide(firstSide), SecondSide(secondSide), ThirdSide(thirdSide) {}
    [[nodiscard]] double getArea() const override {
        std::cout << "TriangleArea ";
        double p = (FirstSide + SecondSide + ThirdSide) / 2;
        return pow(p * (p - FirstSide) * (p - SecondSide) * (p - ThirdSide), 1/2);
    }
};

class Rectangle : public Shape {
protected:
    double Width, Height;
public:
    Rectangle(const std::string& color, double xCoordinates, double yCoordinates, double width, double height) : Shape(color, xCoordinates, yCoordinates), Width(width), Height(height){}
    [[nodiscard]] double getArea() const override {
        std::cout << "RectangleArea ";
        return Width * Height;
    }
};

