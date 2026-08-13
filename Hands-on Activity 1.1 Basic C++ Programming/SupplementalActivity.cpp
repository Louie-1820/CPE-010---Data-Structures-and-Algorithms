#include <iostream>
#include <cmath>
#include <string>

void numSwap();
double kelvinToFahrenheit(double kelvin);
void calculateDistance();
double distanceCalculator(double x1, double x2, double y1, double y2);

class Triangle {
private:
    double sideA, sideB, sideC;
    double angleA, angleB, angleC;
    double totalAngle;
public:
    Triangle(double sA, double sB, double sC,
             double A, double B, double C);
    void setTriangle(double sA, double sB, double sC,
                     double A, double B, double C);
    bool validateTriangle();
    double getArea();
    double getPerimeter();
    std::string triangleType();
};

int main() {
    double kelvin;
    Triangle tri(5, 6, 7, 40, 50, 90);
    std::cout << "\n=======================================================";
    std::cout << "\nProblem 1: Swap two numbers in different variables." << std::endl;
    numSwap();
    std::cout << "\nProblem 2: Conversion of temperature in Kelvin to Fahrenheit.\n" << std::endl;
    std::cout << "Enter temperature you want to convert in Kelvin: ";
    std::cin >> kelvin;
    std::cout << "\nTemperature converted to Fahrenheit: "
              << kelvinToFahrenheit(kelvin) << " Fahrenheit" << std::endl;
    std::cout << "\n========================================";
    std::cout << "\nProblem 3: Calculating the distance between two points" << std::endl;
    calculateDistance();
    std::cout << "\nProblem 4: A function calculating the area of a triangle, perimeter of a triangle, the triangle is acute-angled and obtused-angled\n" << std::endl;

    if (tri.validateTriangle()) {
        std::cout << "The triangle is valid.\n";
        std::cout << "Perimeter : " << tri.getPerimeter() << std::endl;
        std::cout << "Area      : " << tri.getArea() << std::endl;
        std::cout << "Type      : " << tri.triangleType() << std::endl;
        std::cout << "========================================";
    }
    else {  
        std::cout << "The triangle is NOT valid.\n";
    }
    
    return 0;
}

void numSwap() {
    int a, b, temp;
    std::cout << "\nEnter any integer value for A and B" << std::endl;
    std::cout << "A = ";
    std::cin >> a;
    std::cout << "B = ";
    std::cin >> b;
    std::cout << "\nThe values of A and B Before Swapping.\n";
    std::cout << "A = " << a << std::endl;
    std::cout << "B = " << b << std::endl;
    temp = a;
    a = b;
    b = temp;
    std::cout << "\nThe values of A and B after swapping." << std::endl;
    std::cout << "A = " << a << std::endl;
    std::cout << "B = " << b << std::endl;
    std::cout << "\n========================================";
}

double kelvinToFahrenheit(double kelvin) {
    return (kelvin - 273.15) * 9 / 5 + 32;
}

void calculateDistance() {
    double x1, x2, y1, y2;
    std::cout << "Enter x1: ";
    std::cin >> x1;
    std::cout << "Enter y1: ";
    std::cin >> y1;
    std::cout << "Enter x2: ";
    std::cin >> x2;
    std::cout << "Enter y2: ";
    std::cin >> y2;
    std::cout << "\nDistance Calculated:" << std::endl;
    std::cout << "X1 : " << x1 << std::endl;
    std::cout << "Y1 : " << y1 << std::endl;
    std::cout << "X2 : " << x2 << std::endl;
    std::cout << "Y2 : " << y2 << std::endl;
    std::cout << "Distance = " << distanceCalculator(x1, x2, y1, y2) << std::endl;
    std::cout << "========================================";
}

double distanceCalculator(double x1, double x2, double y1, double y2) {
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));

}

Triangle::Triangle(double sA, double sB, double sC,
                   double A, double B, double C)
{
    sideA = sA;
    sideB = sB;
    sideC = sC;
    angleA = A;
    angleB = B;
    angleC = C;
    totalAngle = A + B + C;
}

void Triangle::setTriangle(double sA, double sB, double sC,
                           double A, double B, double C)
{
    sideA = sA;
    sideB = sB;
    sideC = sC;
    angleA = A;
    angleB = B;
    angleC = C;
    totalAngle = A + B + C;
}

bool Triangle::validateTriangle()
{
    return totalAngle == 180;
}

double Triangle::getPerimeter()
{
    return sideA + sideB + sideC;
}

double Triangle::getArea()
{
    double s = getPerimeter() / 2;
    return sqrt(s * (s - sideA) * (s - sideB) * (s - sideC));
}

std::string Triangle::triangleType()
{
    if (angleA < 90 && angleB < 90 && angleC < 90)
        return "Acute-Angled";
    else if (angleA > 90 || angleB > 90 || angleC > 90)
        return "Obtuse-Angled";
    else
        return "Others";
}