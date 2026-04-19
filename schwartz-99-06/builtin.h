// builtin.h
     
#ifndef BUILTIN_H
#define BUILTIN_H
     
#include <iostream.h>
     
template <class T>
class builtin
{
public:
        // these functions are required to be members:
     
        builtin(T new_value = 0);
        builtin(const builtin<T> & other);
        ~builtin(void);
     
        builtin<T> & operator  =(const builtin<T> & other); 
        builtin<T> & operator +=(const builtin<T> & other); 
        builtin<T> & operator -=(const builtin<T> & other); 
        builtin<T> & operator *=(const builtin<T> & other); 
        builtin<T> & operator /=(const builtin<T> & other); 
        builtin<T> & operator %=(const builtin<T> & other); 
        builtin<T> & operator<<=(const builtin<T> & other); 
        builtin<T> & operator>>=(const builtin<T> & other); 
        builtin<T> & operator &=(const builtin<T> & other); 
        builtin<T> & operator |=(const builtin<T> & other); 
        builtin<T> & operator ^=(const builtin<T> & other);
     
        builtin<T> & operator++(void); // prefix  ++. returns an lvalue. 
        builtin<T>   operator++(int);  // postfix ++. returns an rvalue. 
        builtin<T> & operator--(void); // prefix  --. returns an lvalue. 
        builtin<T>   operator--(int);  // postfix --. returns an rvalue.
     
        operator T(void) const;
     
        const T * operator&(void) const;
              T * operator&(void)      ;
     
private:
        T value;
};
     
// members:
     
template <class T>
inline
builtin<T>::builtin(T new_value)
{
        value = new_value;
}
     
template <class T>
inline
builtin<T>::builtin(const builtin<T> & other) 
{
        value = other.value;
}
     
template <class T>
inline
builtin<T>::~builtin(void)
{
}
     
template <class T>
inline
builtin<T> & builtin<T>::operator=(const builtin<T> & other) 
{
        value = other.value;
     
        return *this;
}
     
template <class T>
inline
builtin<T> & builtin<T>::operator+=(const builtin<T> & other) 
{
        value += other.value;
     
        return *this;
}
     
template <class T>
inline
builtin<T> & builtin<T>::operator-=(const builtin<T> & other) 
{
        value -= other.value;
     
        return *this;
}
     
template <class T>
inline
builtin<T> & builtin<T>::operator*=(const builtin<T> & other) 
{
        value *= other.value;
     
        return *this;
}
     
template <class T>
inline
builtin<T> & builtin<T>::operator/=(const builtin<T> & other) 
{
        value /= other.value;
     
        return *this;
}
     
template <class T>
inline
builtin<T> & builtin<T>::operator%=(const builtin<T> & other) 
{
        value %= other.value;
     
        return *this;
}
     
template <class T>
inline
builtin<T> & builtin<T>::operator<<=(const builtin<T> & other) 
{
        value <<= other.value;
     
        return *this;
}
     
template <class T>
inline
builtin<T> & builtin<T>::operator>>=(const builtin<T> & other) 
{
        value >>= other.value;
     
        return *this;
}
     
template <class T>
inline
builtin<T> & builtin<T>::operator&=(const builtin<T> & other) 
{
        value &= other.value;
     
        return *this;
}
     
template <class T>
inline
builtin<T> & builtin<T>::operator|=(const builtin<T> & other) 
{
        value |= other.value;
     
        return *this;
}
     
template <class T>
inline
builtin<T> & builtin<T>::operator^=(const builtin<T> & other) 
{
        value ^= other.value;
     
        return *this;
}
     
template <class T>
inline
builtin<T> & builtin<T>::operator++(void) // prefix ++. returns an lvalue. 
{
        ++value;
     
        return *this;
}
     
template <class T>
inline
builtin<T> builtin<T>::operator++(int) // postfix ++. returns an rvalue. 
{
        // if your compiler doesn't support this syntax: 
        T result(value);
        // try this one:
//      T result = value;
     
        value++;
     
        return result;
}
     
template <class T>
inline
builtin<T> & builtin<T>::operator--(void) // prefix --. returns an lvalue. 
{
        --value;
     
        return *this;
}
     
template <class T>
inline
builtin<T> builtin<T>::operator--(int) // postfix --. returns an rvalue. 
{
        // if your compiler doesn't support this syntax: 
        T result(value);
        // try this one:
//      T result = value;
     
        value--;
     
        return result;
}
     
template <class T>
inline
T builtin<T>::operator T(void) const 
{
        return value;
}
     
template <class T>
inline
const T * builtin<T>::operator&(void) const 
{
        return &value;
}
     
template <class T>
inline
T * builtin<T>::operator&(void)
{
        return &value;
}
     
// non-members:
     
// unary:
     
template <class T>
inline
builtin<T> operator+(const builtin<T> & bi) 
{
        return bi;
}
     
template <class T>
inline
builtin<T> operator-(const builtin<T> & bi) 
{
        return -((T) bi);
}
     
template <class T>
inline
builtin<T> operator~(const builtin<T> & bi) 
{
        return ~((T) bi);
}
     
template <class T>
inline
builtin<T> operator!(const builtin<T> & bi) 
{
        return !((T) bi);
}
     
// binary:
     
template <class T>
inline
istream & operator>>(istream & s, builtin<T> & bi) 
{
        T local_t;
        s >> local_t;
        bi = local_t;
     
        return s;
}
     
template <class T>
inline
ostream & operator<<(ostream & s, const builtin<T> & bi) 
{
        s << ((T) bi);
     
        return s;
}
     
template <class T>
inline
builtin<T> operator>>(const builtin<T> & bi, int i) // bit shift. 
{
        return ((T) bi) >> i;
}
     
template <class T>
inline
builtin<T> operator<<(const builtin<T> & bi, int i) // bit shift. 
{
        return ((T) bi) << i;
}
     
template <class T>
inline
bool operator==(const builtin<T> & bi1, const builtin<T> & bi2) 
{
        return ((T) bi1) == ((T) bi2);
}
     
template <class T>
inline
bool operator!=(const builtin<T> & bi1, const builtin<T> & bi2) 
{
        return ((T) bi1) != ((T) bi2);
}
     
template <class T>
inline
bool operator<(const builtin<T> & bi1, const builtin<T> & bi2) 
{
        return ((T) bi1) < ((T) bi2);
}
     
template <class T>
inline
bool operator<=(const builtin<T> & bi1, const builtin<T> & bi2) 
{
        return ((T) bi1) <= ((T) bi2);
}
     
template <class T>
inline
bool operator>(const builtin<T> & bi1, const builtin<T> & bi2) 
{
        return ((T) bi1) > ((T) bi2);
}
     
template <class T>
inline
bool operator>=(const builtin<T> & bi1, const builtin<T> & bi2) 
{
        return ((T) bi1) >= ((T) bi2);
}
     
template <class T>
inline
builtin<T> operator+(const builtin<T> & bi1, const builtin<T> & bi2) 
{
        return ((T) bi1) + ((T) bi2);
}
     
template <class T>
inline
builtin<T> operator-(const builtin<T> & bi1, const builtin<T> & bi2) 
{
        return ((T) bi1) - ((T) bi2);
}
     
template <class T>
inline
builtin<T> operator*(const builtin<T> & bi1, const builtin<T> & bi2) 
{
        return ((T) bi1) * ((T) bi2);
}
     
template <class T>
inline
builtin<T> operator/(const builtin<T> & bi1, const builtin<T> & bi2) 
{
        return ((T) bi1) / ((T) bi2);
}
     
template <class T>
inline
builtin<T> operator%(const builtin<T> & bi1, const builtin<T> & bi2) 
{
        return ((T) bi1) % ((T) bi2);
}
     
template <class T>
inline
builtin<T> operator&(const builtin<T> & bi1, const builtin<T> & bi2) 
{
        return ((T) bi1) & ((T) bi2);
}
     
template <class T>
inline
builtin<T> operator^(const builtin<T> & bi1, const builtin<T> & bi2) 
{
        return ((T) bi1) ^ ((T) bi2);
}
     
template <class T>
inline
builtin<T> operator|(const builtin<T> & bi1, const builtin<T> & bi2) 
{
        return ((T) bi1) | ((T) bi2);
}
     
#endif

