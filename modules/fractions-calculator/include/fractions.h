// Copyright 2019 Pinaev Danil

class Fraction {
 public:
    Fraction();
    Fraction(const double real, const double imaginary);
    Fraction(const Fraction& z);

    Fraction& operator=(const Fraction& z);

    int getNum() const;
    int getDen() const;
    void setNum(const int numerator);
    void setDen(const int denominator);

    Fraction operator + (const Fraction& z) const;
    Fraction operator - (const Fraction& z) const;
    Fraction operator * (const Fraction& z) const;
    Fraction operator / (const Fraction& z) const;

    bool operator == (const Fraction& z) const;
    bool operator != (const Fraction& z) const;

 private:
    int numerator_;
    int denominator_;
};
