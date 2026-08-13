#include <iostream>

int sumOfTwoNum(int fNum, int sNum);
bool isGreater(int a, int b);
bool displayLogicalOperations(bool c, bool d);

class Triangle {
    private:
        double totalAngle, angleA, angleB, angleC;
    public:
        Triangle(double A, double B, double C);
        void setAngles(double A, double B, double C);
        const bool validateTriangle();
};

int main () {
    std::cout << "The sum of all numbers is : " << sumOfTwoNum(10,22) << std::endl;
    
    int x = 500;
    int y = 400;

   if (isGreater(x, y)) {
        std::cout << "x is greater than y" << std::endl;
    } else {
        std::cout << "x is not greater than y" << std::endl;
    }

    bool success = displayLogicalOperations(true, false);
   
    std::cout << "Function execution status: " << std::boolalpha << success << std::endl;

    Triangle setl(40,30,110);
    if(setl.validateTriangle()){
        std::cout << "The shape is a valid Triangle \n.";
    }
    else{
        std::cout << "The shape is NOT a valid Triangle \n.";
    }

    return 0;
}

int sumOfTwoNum(int fNum, int sNum){
    int sum = fNum + sNum;
    return sum;
}

bool isGreater(int a, int b){
    return a > b;
}

bool displayLogicalOperations(bool c, bool d) {
    std::cout << std::boolalpha;   
    std::cout << "Logical Operations Table " << std::endl;
    std::cout << "Inputs: A = " << c << ", B = " << d << std::endl;
    std::cout << "Not A      : " << (!c) << std::endl;
    std::cout << "Not B      : " << (!d) << std::endl;
    std::cout << "Logical AND : " << (c && d) << std::endl;
    std::cout << "Logical OR : " << (c || d) << std::endl;
    std::cout << "Logical XOR : " << (c ^ d) << std::endl;
    std::cout << "Logical NAND: " << !(c && d) << std::endl;
    std::cout << "Logical NOR: " << !(c || d) << std::endl;
    std::cout << "Logical XNOR: " << !(c ^ d) << std::endl;
    return true;
}

Triangle::Triangle(double A, double B, double C){
    angleA = A;
    angleB = B;
    angleC = C;
    totalAngle = A + B + C;
}

void Triangle::setAngles(double A, double B, double C){
    angleA = A;
    angleB = B;
    angleC = C;
    totalAngle = A+B+C;
}

const bool Triangle::validateTriangle(){
    return (totalAngle <= 180);
}