#include <iostream>
#include <string>

using namespace std;

// -----Task 1
class Figure {
protected:
  string name;
public:
    virtual void area()=0;
};

class Parallelogram : public Figure {
private:
    int a, b;
protected:
    Parallelogram(int m_A, int m_B, string m_Name) {
      a=m_A;
      b=m_B;
      name=m_Name;
    };
public:
    Parallelogram(int m_A, int m_B) {
      a=m_A;
      b=m_B;
      name="Parallelogram";
    };

    void area() {
        cout << name <<"\'s area = " << a*b << endl;
    };
};

class Rectangle: public Parallelogram {
public:
    Rectangle(int m_A, int m_B): Parallelogram(m_A,m_B, "Rectangle") {};
};

class Square: public Parallelogram {
public:
    Square(int m_X): Parallelogram(m_X,m_X,"Square") {};
};

class Rhombus: public Parallelogram {
public:
    Rhombus(int m_A, int m_B): Parallelogram(m_A,m_B,"Rhombus") {};
};

class Circle : public Figure {
private:
    int r;
public:
    Circle(int m_R) {
      r=m_R;
      name="Circle";
    };
    void area() {
        cout << name <<"\'s area = " << 3.14*r*r << endl;
    };
};

// -----Task 2
class Car {
private:
 string company;
 string model;
public:
 Car (string m_com,string m_mod) {
  company=m_com;
  model=m_mod;
  cout<< "Car Company " << company << " Model " << model << "->" << endl;
 }
};

class PassengerCar:virtual public Car {
public:
    PassengerCar(string m_com,string m_mod): Car(m_com,m_mod) {
        cout << "PassengerCar->";
    }
};

class Bus:virtual public Car {
public:
    Bus(string m_com,string m_mod): Car(m_com,m_mod) {
        cout << "Bus->";
    }
};

class Minivan: public PassengerCar, public Bus {
public:
    Minivan(string m_com,string m_mod) : PassengerCar(m_com,m_mod), Bus(m_com,m_mod), Car(m_com,m_mod) {
        cout<<"Minivan->";
    }
};

// -----Task 3
class Fraction {
private:
 int numerator;
 int denominator;
public:
 bool isZero=false;
 Fraction(int m_Num, int m_Den) {
//     numerator=m_Num;
//     denominator=m_Den;
   setNumerator(m_Num);
   setDenomirator(m_Den);
 };
 ~Fraction() {};
 void setNumerator(int m_Num) { numerator=m_Num;};
 int getNumerator() {return numerator;};
 void setDenomirator(int m_Den)
  { denominator=m_Den;
    if (m_Den==0)
     {cout << "denominator is zero!!!\n"; isZero=true;}
  };
 int getDenomirator() { return denominator;};
 string getFraction() {
   return ( to_string(getNumerator()) + '/' + to_string(getDenomirator()));
 };

 Fraction operator-() const {
     return Fraction(-numerator, denominator);
 };

 bool operator==(const Fraction& f) const {
     return (numerator == f.numerator && denominator == f.denominator);
 };

 bool operator!=(const Fraction& f) const {
     return !(*this == f);
 };

 bool operator<(const Fraction& f) const {
     return (this->numerator < f.numerator && this->denominator > f.denominator);
 };

 bool operator>(const Fraction& f) const {
     return (this->numerator > f.numerator && this->denominator < f.denominator);
 };

 bool operator>=(const Fraction& f) const {
     return !(*this < f);
 };

 bool operator<=(const Fraction& f) const {
     return !(*this > f);
 };
};

Fraction operator+(Fraction &f1, Fraction &f2) {
    return Fraction((f1.getNumerator()*f2.getDenomirator()+f2.getNumerator()*f1.getDenomirator()),(f1.getDenomirator()*f2.getDenomirator()));
};
Fraction operator-(Fraction &f1, Fraction &f2) {
    return Fraction((f1.getNumerator()*f2.getDenomirator()-f2.getNumerator()*f1.getDenomirator()),(f1.getDenomirator()*f2.getDenomirator()));
};
Fraction operator*(Fraction &f1, Fraction &f2) {
    return Fraction((f1.getNumerator()*f2.getNumerator()),(f1.getDenomirator()*f2.getDenomirator()));
};
Fraction operator/(Fraction &f1, Fraction &f2) {
    return Fraction((f1.getNumerator()*f2.getDenomirator()),(f1.getDenomirator()*f2.getNumerator()));
};

// -----Task 4

int main()
{
    cout << "Task 1" << endl;
    //Создать абстрактный класс Figure (фигура).
    //Его наследниками являются классы Parallelogram (параллелограмм) и Circle (круг).
    //Класс Parallelogram — базовый для классов Rectangle (прямоугольник), Square (квадрат),
    //Rhombus (ромб). Для всех классов создать конструкторы.
    //Для класса Figure добавить чисто виртуальную функцию area() (площадь).
    //Во всех остальных классах переопределить эту функцию, исходя из геометрических формул
    //нахождения площади.
    Parallelogram p1(3,4);
    Rectangle r1(4,5);
    Square s1(3);
    Rhombus rh1(1,2);
    Circle c1(3);
    Figure *f1=&p1;
    f1->area();
//    Figure *f2=&r1;
//    f2->area();
    f1=&r1;
    f1->area();

    Figure *f3=&s1;
    f3->area();
    Figure *f4=&rh1;
    f4->area();
//    Figure *f5=&c1;
//    f5->area();
//    f4=&c1;
//    f4->area();
    c1.area();

    cout << "Task 2" << endl;
    //Создать класс Car (автомобиль) с полями company (компания) и model (модель).
    //Классы-наследники: PassengerCar (легковой автомобиль) и Bus (автобус).
    //От этих классов наследует класс Minivan (минивэн).
    //Создать конструкторы для каждого из классов, чтобы они выводили данные о классах.
    //Создать объекты для каждого из классов и посмотреть, в какой последовательности выполняются
    //конструкторы. Обратить внимание на проблему «алмаз смерти».
    Car c("-","SUV");  //Выполняетcя конструктор Car
    cout<<endl<<endl;
    PassengerCar p("Skoda", "SUPERB");
    cout<<endl<<endl;
    Bus b("DM","B-320");
    cout<<endl<<endl;
    Minivan m("Ford","Galaxy");
    cout<<endl<<endl;

    cout << "Task 3" << endl;
//  Создать класс: Fraction (дробь). Дробь имеет числитель и знаменатель (например, 3/7 или 9/2).
//  Предусмотреть, чтобы знаменатель не был равен 0.
//  Перегрузить:
//  - математические бинарные операторы (+, -, *, /) для выполнения действий с дробями
//  - унарный оператор (-)
//  - логические операторы сравнения двух дробей (==, !=, <, >, <=, >=).
//  Примечание: Поскольку операторы < и >=, > и <= — это логические противоположности,
//  попробуйте перегрузить один через другой.
//  Продемонстрировать использование перегруженных операторов.
    Fraction fr(1,0);
    cout<<fr.getFraction()<<endl<<endl;
    Fraction fr1(1,9);
    Fraction fr2(3,8);
    fr1=-fr1;
    cout << fr1.getFraction() << " = " << fr1.getFraction() << endl;
    Fraction fr3=fr1+fr2;
    cout << fr1.getFraction() << " + " << fr2.getFraction() << " = " << fr3.getFraction() << endl;
    Fraction fr4=fr2-fr1;
    cout << fr2.getFraction() << " - " << fr1.getFraction() << " = " << fr4.getFraction() << endl;
    fr3=fr1*fr2;
    cout << fr1.getFraction() << " * " << fr2.getFraction() << " = " << fr3.getFraction() << endl;
    fr4=fr1/fr2;
    cout << fr1.getFraction() << " / " << fr2.getFraction() << " = " << fr4.getFraction() << endl<< endl;

    if (fr3==fr3) cout << fr3.getFraction() << " == " << fr3.getFraction() << " is true " << endl;
    else cout << fr3.getFraction() << " == " << fr3.getFraction() << " is false " << endl;
    if (fr3!=fr4) cout << fr3.getFraction() << " != " << fr4.getFraction() << " is true " << endl;
    else cout << fr3.getFraction() << " != " << fr4.getFraction() << " is false " << endl;
    if (fr3!=fr4) cout << fr3.getFraction() << " != " << fr4.getFraction() << " is true " << endl;
    else cout << fr3.getFraction() << " != " << fr4.getFraction() << " is false " << endl;
    if (fr1<fr2) cout << fr1.getFraction() << " < " << fr2.getFraction() << " is true " << endl;
    else cout << fr1.getFraction() << " < " << fr2.getFraction() << " is false " << endl;
    if (fr1>fr2) cout << fr1.getFraction() << " > " << fr2.getFraction() << " is true " << endl;
    else cout << fr1.getFraction() << " > " << fr2.getFraction() << " is false " << endl;
    fr1=-fr1;
    if (fr1>=fr2) cout << fr1.getFraction() << " >= " << fr2.getFraction() << " is true " << endl;
    else cout << fr1.getFraction() << " >= " << fr2.getFraction() << " is false " << endl;
    fr2=fr1;
    if (fr1<=fr2) cout << fr1.getFraction() << " <= " << fr2.getFraction() << " is true " << endl;
    else cout << fr1.getFraction() << " <= " << fr2.getFraction() << " is false " << endl<<endl;

// Task 4
    cout << endl << "Task 4" << endl << "See code" << endl;
// Создать класс Card, описывающий карту в игре БлэкДжек.
// У этого класса должно быть три поля: масть, значение карты и положение карты
// (вверх лицом или рубашкой).
// Сделать поля масть и значение карты типом перечисления (enum).
// Положение карты - тип bool. Также в этом классе должно быть два метода:
// - метод Flip(), который переворачивает карту, т.е. если она была рубашкой вверх,
//   то он ее поворачивает лицом вверх, и наоборот.
// - метод GetValue(), который возвращает значение карты, пока можно считать, что туз = 1.
class Card {
public:
  enum znashen {ACE = 1, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN,
           JACK, QUEEN, KING};
  enum mast {CLUBS, DIAMONDS, HEARTS, SPADES};

  Card(znashen r, mast s, bool ifUp): m_Znashen(r), m_Mast(s), m_IsFaceUp(ifUp)
  {}

  // возвращает значение карты, пока можно считать, что туз = 1
  int GetValue() const
  {
   int value = 0;
   if (m_IsFaceUp)
    {
      value = m_Znashen;
      if (value > 10) value = 10;
    }
   return value;
  };

  // переворачивает карту
  void Flip()
  {
     m_IsFaceUp = !(m_IsFaceUp);
  };

private:
  znashen m_Znashen;
  mast m_Mast;
  bool m_IsFaceUp;
};
// end Task 4

  return 0;
}
