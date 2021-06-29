#include <iostream>
#include <cstdint>

using namespace std;

//=======================================================================================================================

class Power {
private:
    float a, b, rez;
public:
    void setNum() {
        a = 2;
        b = 3;
    }
    void setNum(float c, float d) {
        a = c;
        b = d;
    }
    void calculate() {
       rez = pow(a, b);
       cout << " Result: " << rez << endl;
    }
};

//=======================================================================================================================

class RGBA {
private:
    uint8_t m_red = 0, m_green = 0, m_blue = 0, m_alpha = 255;
public:
    RGBA() {

    }
    RGBA(int red, int green, int blue, int alpha) 
    : m_red(red), m_green(green), m_blue(blue), m_alpha(alpha) {

    }

    void print() {
        cout << " Red: " << m_red << "   Green: " << m_green << "   Blue: " << m_blue 
            << "   Alpha: " << m_alpha << endl;
    }
};

//=======================================================================================================================

class Stack {
private:    
    int arr[10];
    size_t arrsize = 10;
    size_t length = 0;
public:
    Stack() {
        for (size_t i = 0; i < arrsize; i++)
        {
            arr[i] = 0;
        }
    }
    void reset() {   
        length = 0;
        for (size_t i = 0; i < 10; i++)
        {
            arr[i] = 0;
        }        
    }
    bool push(int a) {
        if (length < arrsize) {       
            length++;
            arr[arrsize - length] = a;
            
            return true;
        }
        else {
            return false;
        }
    }
    void pop() {
        if (length != 0) {
            arr[arrsize - length] = 0;
            length--;
        }
        else { cout << "Stack empty"; }

    }
    void print() {
        cout << " ( ";
        for (size_t i = arrsize; i > 0; i--)
        {
            if (arr[i-1] != 0) {
                cout << arr[i-1] << " ";
            }
        }
        cout << ")" << endl;
    }
};

//=======================================================================================================================

int main()
{
    //==========================================

    cout << " Ex 1" << endl;
    float a1, b1;
    Power number;
    number.setNum();
    number.calculate();
    cout << " Enter number: ";
    cin >> a1;
    cout << " Enter degree: ";
    cin >> b1;
    number.setNum(a1,b1);
    number.calculate();

    //==========================================

    cout << endl << " Ex 2" << endl;        
    int red, green, blue, alpha;
    cout << " Enter red (0..255): ";
    cin >> red;
    cout << " Enter green (0..255): ";
    cin >> green;
    cout << " Enter blue (0..255): ";
    cin >> blue;
    cout << " Enter alpha (0..255): ";
    cin >> alpha;
    RGBA color(red, green, blue, alpha);
    color.print();

    //==========================================

    cout << endl << " Ex 3" << endl;
    Stack stack;    
    stack.reset();
    stack.print();

    stack.push(3);
    stack.push(7);
    stack.push(5);
    stack.push(3);
    stack.push(7);
    stack.push(5);
    stack.print();

    stack.pop();
    stack.print();

    stack.pop();
    stack.pop();
    stack.print();


    //==========================================

    return 0;
}


