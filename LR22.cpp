#include <iostream>
#include <Windows.h>
#include <windowsx.h>
#include <tchar.h>

using namespace std;
class point
{
private:
    int x, y;
public:

    point(int x, int y)//конструктор с параметрами Х,У
    {
        this->x = x;
        this->y = y;
        //      cout << "  Constructor c parametrami X,Y" << endl;
    }

    point()
    {
    }

    void print()
    {
        cout << "  x=" << x << ";  y=" << y << endl;
    }
    void position()
    {
        if (x > 0 and y > 0)
            cout << "   1 четверти" << endl;
        else
            if (x < 0 and y>0)
                cout << "   2 четверти" << endl;
            else
                if (x < 0 and y < 0)
                    cout << "   3 четверти" << endl;
                else
                    if (x > 0 and y < 0)
                        cout << "   4 четверти" << endl;
    }

    int Get_x()
    {
        return x;
    }

    int Get_y()
    {
        return y;
    }
    void Set_x(int valueX)
    {
        this->x = valueX;
    }
    void Set_y(int valuey)
    {
        this->y = valuey;
    }
    ~point()
    {
        //     cout << "destruktor Point" << endl;
    }
};

class Line
{
private:
double a, b;

public:
    // double x, y;
    Line(double a, double b)
    {
        this->a = a;
        this->b = b;
    }

    Line()
    {
    }

    Line Creat_line(double a, point p)					//линия которая проходит через точку с заданным угловым коэфициентом
    {
        Line l;
        l.a = a;
        l.b = p.Get_y() - l.a * p.Get_x();
        return l;
    }
    Line creat_line_to(point& p1, point& p2)                 //линия которая проходит через  точки
    {
        Line l;
        l.a = (p2.Get_y() - p1.Get_y()) / (p2.Get_x() - p1.Get_x());
        l.b = p1.Get_y() - l.a * p1.Get_x();
        return l;
    }
    Line creat_line_par(point p, Line L)			//линия которая проходит через точку и параллельна линии
    {
        Line ll;
        ll.a = L.a;
        ll.b = p.Get_y() - ll.a * p.Get_x();
        return ll;
    }
    Line creat_line_perpen(Line L, point p)                //линия которая проходит через точку и перпендикулярна линии
    {
        Line ll;
        ll.a = -1 * L.a;
        ll.b = p.Get_y() - ll.a * p.Get_x();
        return ll;
    }
    void print()
    {
        cout << "  a=" << a << ";  b=" << b << endl;
    }
    void parall(Line l1, Line l2)  //  проверка на параллельность линий   +
    {
        if (l1.a == l2.a)
            cout << "l1 и l2 параллельны" << endl;
        else
            cout << "l1 и l2 не параллельны" << endl;
    }

    void perpendicular(Line l1, Line l2)   //  проверка на перпендикулярность линий  +
    {
        if (l1.a == -l2.a)
            cout << "l1 и l2 перпендикулярны" << endl;
        else
            cout << "l1 и l2 не перпендикулярны" << endl;
    }
};
int main()
{
    setlocale(LC_ALL, "Rus");
    point p1(5, 5), p2(3, 4), p3;
    cout << "p1 = " << endl;
    p1.print();
    cout << "p2 = " << endl;
    p2.print();
    Line l1(1, 3), l2(-1, 7), l3(2, 6), l4, l5, l6, l7;
    cout << "l1 = " << endl;
    l1.print();
    cout << "l2 = " << endl;
    l2.print();
    cout << "l3 = " << endl;
    l3.print();
    cout << "\n " << endl;
    cout << "p2 относится к  " << endl;

    p2.position();
    cout << "\n " << endl;
    cout << "линия, которая проходит через точку с заданным угловым коэфициентом  " << endl;
    l4 = l4.Creat_line(5, p2);
    l4.print();

    cout << "\n " << endl;
    cout << "линия, которая проходит через  точки (5, 5), (1, 4) " << endl;
    l5 = l5.creat_line_to(p1, p2);
    l5.print();

    cout << "\n " << endl;
    cout << "линия которая проходит через точку (1, 4) и параллельна линии (2,6) " << endl;
    l6 = l6.creat_line_par(p2, l3);
    l6.print();

    cout << "\n " << endl;
    cout << "линия которая проходит через точку (1, 4) и перпендикулярна линии (2,6)" << endl;
    l7 = l7.creat_line_perpen(l3, p2);
    l7.print();

    cout << "\n " << endl;
    l1.parall(l1, l2);

    cout << "\n " << endl;
    l1.perpendicular(l1, l2);
}