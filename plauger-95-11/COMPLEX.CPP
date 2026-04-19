// complex standard header
#ifndef _COMPLEX_
#define _COMPLEX_
#include <cmath>
#include <istream>
_STD_BEGIN
#define __STD_COMPLEX
		// TEMPLATE CLASS _Ctr
template<class _T> class _Ctr {
public:
	static _T _Cosh(_T _X, _T _Y)
		{return (::_Cosh((double)_X, (double)_Y)); }
	static short _Exp(_T *_P, _T _Y, short _E)
		{double _W = (double)*_P;
		short _Ans = ::_Exp(&_W, (double)_Y, _E);
		*_P = (_T)_W;
		return (_Ans); }
	static _T _Infv(_T)
		{return (_Inf._D); }
	static bool _Isinf(_T _X)
		{double _W = (double)_X;
		return (_Dtest(&_W) == _INF); }
	static bool _Isnan(_T _X)
		{double _W = (double)_X;
		return (_Dtest(&_W) == _NAN); }
	static _T _Nanv(_T)
		{return (_Nan._D); }
	static _T _Sinh(_T _X, _T _Y)
		{return (::_Sinh((double)_X, (double)_Y)); }
	static _T atan2(_T _Y, _T _X)
		{return (::atan2((double)_Y, (double)_X)); }
	static _T cos(_T _X)
		{return (::cos((double)_X)); }
	static _T exp(_T _X)
		{return (::exp((double)_X)); }
	static _T ldexp(_T _R, int _E)
		{return (::ldexp((double)_R, _E)); }
	static _T log(_T _X)
		{return (::log((double)_X)); }
	static _T pow(_T _X, _T _Y)
		{return (::pow((double)_X, (double)_Y)); }
	static _T sin(_T _X)
		{return (::sin((double)_X)); }
	static _T sqrt(_T _X)
		{return (::sqrt((double)_X)); }
	};
		// CLASS _Ctr<float>
class _Ctr<float> {
public:
	typedef float _T;
	static _T _Cosh(_T _X, _T _Y)
		{return (_FCosh(_X, _Y)); }
	static short _Exp(_T *_P, _T _Y, short _E)
		{return (_FExp(_P, _Y, _E)); }
	static _T _Infv(_T)
		{return (_FInf._F); }
	static bool _Isinf(_T _X)
		{return (_FDtest(&_X) == _INF); }
	static bool _Isnan(_T _X)
		{return (_FDtest(&_X) == _NAN); }
	static _T _Nanv(_T)
		{return (_FNan._F); }
	static _T _Sinh(_T _X, _T _Y)
		{return (_FSinh(_X, _Y)); }
	static _T atan2(_T _Y, _T _X)
		{return (atan2f(_Y, _X)); }
	static _T cos(_T _X)
		{return (cosf(_X)); }
	static _T exp(_T _X)
		{return (expf(_X)); }
	static _T ldexp(_T _R, int _E)
		{return (ldexpf(_R, _E)); }
	static _T log(_T _X)
		{return (logf(_X)); }
	static _T pow(_T _X, _T _Y)
		{return (powf(_X, _Y)); }
	static _T sin(_T _X)
		{return (sinf(_X)); }
	static _T sqrt(_T _X)
		{return (sqrtf(_X)); }
	};
		// CLASS _Ctr<double>
class _Ctr<double> {
public:
	typedef double _T;
	static _T _Cosh(_T _X, _T _Y)
		{return (::_Cosh(_X, _Y)); }
	static short _Exp(_T *_P, _T _Y, short _E)
		{return (::_Exp(_P, _Y, _E)); }
	static _T _Infv(_T)
		{return (_Inf._D); }
	static bool _Isinf(_T _X)
		{return (_Dtest(&_X) == _INF); }
	static bool _Isnan(_T _X)
		{return (_Dtest(&_X) == _NAN); }
	static _T _Nanv(_T)
		{return (_Nan._D); }
	static _T _Sinh(_T _X, _T _Y)
		{return (::_Sinh(_X, _Y)); }
	static _T atan2(_T _Y, _T _X)
		{return (::atan2(_Y, _X)); }
	static _T cos(_T _X)
		{return (::cos(_X)); }
	static _T exp(_T _X)
		{return (::exp(_X)); }
	static _T ldexp(_T _R, int _E)
		{return (::ldexp(_R, _E)); }
	static _T log(_T _X)
		{return (::log(_X)); }
	static _T pow(_T _X, _T _Y)
		{return (::pow(_X, _Y)); }
	static _T sin(_T _X)
		{return (::sin(_X)); }
	static _T sqrt(_T _X)
		{return (::sqrt(_X)); }
	};
		// CLASS _Ctr<long double>
class _Ctr<long double> {
public:
	typedef long double _T;
	static _T _Cosh(_T _X, _T _Y)
		{return (_LCosh(_X, _Y)); }
	static short _Exp(_T *_P, _T _Y, short _E)
		{return (_LExp(_P, _Y, _E)); }
	static _T _Infv(_T)
		{return (_LInf._L); }
	static bool _Isinf(_T _X)
		{return (_LDtest(&_X) == _INF); }
	static bool _Isnan(_T _X)
		{return (_LDtest(&_X) == _NAN); }
	static _T _Nanv(_T)
		{return (_LNan._L); }
	static _T _Sinh(_T _X, _T _Y)
		{return (_LSinh(_X, _Y)); }
	static _T atan2(_T _Y, _T _X)
		{return (atan2l(_Y, _X)); }
	static _T cos(_T _X)
		{return (cosl(_X)); }
	static _T exp(_T _X)
		{return (expl(_X)); }
	static _T ldexp(_T _R, int _E)
		{return (ldexpl(_R, _E)); }
	static _T log(_T _X)
		{return (logl(_X)); }
	static _T pow(_T _X, _T _Y)
		{return (powl(_X, _Y)); }
	static _T sin(_T _X)
		{return (sinl(_X)); }
	static _T sqrt(_T _X)
		{return (sqrtl(_X)); }
	};
		// TEMPLATE CLASS _Complex_base
template<class _T> class complex;
class complex<float>;
class complex<double>;
class complex<long double>;
template<class _T>
	class _Complex_base {
public:
	typedef _Complex_base<_T> _Myt;
	_Complex_base(const _T& _R, const _T& _I)
		: _Re(_R), _Im(_I) {}
#if _HAS_MEMBER_TEMPLATES
	template class<U>
		_Myt& operator=(const complex<_U>& _X)
		{_Re = (_T)_X.real();
		_Im = (_T)_X.imag();
		return (*this); }
	template<class _U>
		_Myt& operator+=(const complex<_U>& _X)
		{_Re += (_T)_X.real();
		_Im += (_T)_X.imag();
		return (*this); }
	template<class _U>
		_Myt& operator-=(const complex<_U>& _X)
		{_Re -= (_T)_X.real();
		_Im -= (_T)_X.imag();
		return (*this); }
	template<class _U>
		_Myt& operator*=(const complex<_U>& _X)
		{_T _Xre = (_T)_X.real();
		_T _Xim = (_T)_X.imag();
		_T _W = _Re * _Xre - _Im * _Xim;
		_Im = _Re * _Xim + _Im * _Xre;
		_Re = _W;
		return (*this); }
	template class<U>
		_Myt& operator/=(const complex<_U>& _X)
		{_T _Xre = (_T)_X.real();
		_T _Xim = (_T)_X.imag();
		if (_Ctr<_T>::_Isnan(_Xre) || _Ctr<_T>::_Isnan(_Xim))
			_Re = _Ctr<_T>::_Nanv(_Xre), _Im = _Re;
		else if ((_Xim < 0 ? -_Xim : +_Xim)
			< (_Xre < 0 ? -_Xre : +_Xre))
			{_T _Wr = _Xim / _Xre;
			_T _Wd = _Xre + _Wr * _Xim;
			if (_Ctr<_T>::_Isnan(_Wd) || _Wd == 0)
				_Re = _Ctr<_T>::_Nanv(_Xre), _Im = _Re;
			else
				{_T _W = (_Re + _Im * _Wr) / _Wd;
				_Im = (_Im - _Re * _Wr) / _Wd;
				_Re = _W; }}
		else if (_Xim == 0)
			_Re = _Ctr<_T>::_Nanv(_Xre), _Im = _Re;
		else
			{_T _Wr = _Xre / _Xim;
			_T _Wd = _Xim + _Wr * _Xre;
			if (_Ctr<_T>::_Isnan(_Wd) || _Wd == 0)
				_Re = _Ctr<_T>::_Nanv(_Xre), _Im = _Re;
			else
				{_T _W = (_Re * _Wr + _Im) / _Wd;
				_Im = (_Im * _Wr - _Re) / _Wd;
				_Re = _W; }}
		return (*this); }
#else
	_T real(_T _X)
		{return (_Re = _X); }
	_T imag(_T _X)
		{return (_Im = _X); }
#endif
	_T real() const
		{return (_Re); }
	_T imag() const
		{return (_Im); }
private:
	_T _Re, _Im;
	};
		// CLASS complex<float>
class complex<float> : public _Complex_base<float> {
public:
	typedef float _T;
	explicit complex(const complex<double>&);
	explicit complex(const complex<long double>&);
	complex(const _T& _R = 0, const _T& _I = 0)
		: _Complex_base<_T>(_R, _I) {}
	};
		// CLASS complex<double>
class complex<double> : public _Complex_base<double> {
public:
	typedef double _T;
	complex(const complex<float>&);
	explicit complex(const complex<long double>&);
	complex(const _T& _R = 0, const _T& _I = 0)
		: _Complex_base<_T>(_R, _I) {}
	};
		// CLASS complex<long double>
class complex<long double> : public _Complex_base<long double> {
public:
	typedef long double _T;
	complex(const complex<float>&);
	complex(const complex<double>&);
	complex(const _T& _R = 0, const _T& _I = 0)
		: _Complex_base<_T>(_R, _I) {}
	};
		// CONSTRUCTORS FOR complex SPECIALIZATIONS
complex<float>::complex(const complex<double>& _X)
	: _Complex_base<float>((_T)_X.real(), (_T)_X.imag()) {}
complex<float>::complex(const complex<long double>& _X)
	: _Complex_base<float>((_T)_X.real(), (_T)_X.imag()) {}
complex<double>::complex(const complex<float>& _X)
	: _Complex_base<double>((_T)_X.real(), (_T)_X.imag()) {}
complex<double>::complex(const complex<long double>& _X)
	: _Complex_base<double>((_T)_X.real(), (_T)_X.imag()) {}
complex<long double>::complex(const complex<float>& _X)
	: _Complex_base<long double>((_T)_X.real(), (_T)_X.imag()) {}
complex<long double>::complex(const complex<double>& _X)
	: _Complex_base<long double>((_T)_X.real(), (_T)_X.imag()) {}
		// TEMPLATE CLASS complex
template<class _T>
	class complex : public _Complex_base<_T> {
public:
	complex(const _T& _R = 0, const _T& _I = 0)
		: _Complex_base<_T>(_R, _I) {}
#if _HAS_MEMBER_TEMPLATES
	template<class _U>
#else
	typedef _T _U;
#endif
		complex(const complex<_U>& _X)
		: _Complex_base<_T>((_T)_X.real(), (_T)_X.imag()) {}
	};
#if !_HAS_MEMBER_TEMPLATES
		// TEMPLATE complex OPERATORS
template<class _T, class _U> inline
	complex<_T>& operator=(complex<_T>& _X, const complex<_U>& _Y)
	{_X.real((_T)_X.real());
	_X.imag((_T)_X.imag());
	return (_X); }
template<class _T, class _U> complex<_T>& operator+=(
	complex<_T>& _X,
	const complex<_U>& _Y)
	{_X.real(_X.real() + (_T)_Y.real());
	_X.imag(_X.imag() + (_T)_Y.imag());
	return (_X); }
template<class _T, class _U> complex<_T>& operator-=(
	complex<_T>& _X,
	const complex<_U>& _Y)
	{_X.real(_X.real() - (_T)_Y.real());
	_X.imag(_X.imag() - (_T)_Y.imag());
	return (_X); }
template<class _T, class _U> complex<_T>& operator*=(
	complex<_T>& _X,
	const complex<_U>& _Y)
	{_T _Yre = (_T)_Y.real();
	_T _Yim = (_T)_Y.imag();
	_T _W = _X.real() * _Yre - _X.imag() * _Yim;
	_X.imag(_X.real() * _Yim + _X.imag() * _Yre);
	_X.real(_W);
	return (_X); }
template<class _T, class _U> complex<_T>& operator/=(
	complex<_T>& _X,
	const complex<_U>& _Y)
	{_T _Yre = (_T)_Y.real();
	_T _Yim = (_T)_Y.imag();
	if (_Ctr<_T>::_Isnan(_Yre) || _Ctr<_T>::_Isnan(_Yim))
		_X.real(_Ctr<_T>::_Nanv(_Yre)), _X.imag(_X.real());
	else if ((_Yim < 0 ? -_Yim : +_Yim)
		< (_Yre < 0 ? -_Yre : +_Yre))
		{_T _Wr = _Yim / _Yre;
		_T _Wd = _Yre + _Wr * _Yim;
		if (_Ctr<_T>::_Isnan(_Wd) || _Wd == 0)
			_X.real(_Ctr<_T>::_Nanv(_Yre)), _X.imag(_X.real());
		else
			{_T _W = (_X.real() + _X.imag() * _Wr) / _Wd;
			_X.imag((_X.imag() - _X.real() * _Wr) / _Wd);
			_X.real(_W); }}
	else if (_Yim == 0)
		_X.real(_Ctr<_T>::_Nanv(_Yre)), _X.imag(_X.real());
	else
		{_T _Wr = _Yre / _Yim;
		_T _Wd = _Yim + _Wr * _Yre;
		if (_Ctr<_T>::_Isnan(_Wd) || _Wd == 0)
			_X.real(_Ctr<_T>::_Nanv(_Yre)), _X.imag(_X.real());
		else
			{_T _W = (_X.real() * _Wr + _X.imag()) / _Wd;
			_X.imag((_X.imag() * _Wr - _X.real()) / _Wd);
			_X.real(_W); }}
	return (_X); }
#endif
		// TEMPLATE FUNCTION imag
template<class _T> inline
	_T imag(const complex<_T>& _X)
	{return (_X.imag()); }
		// TEMPLATE FUNCTION real
template<class _T> inline
	_T real(const complex<_T>& _X)
	{return (_X.real()); }
		// TEMPLATE FUNCTION _Fabs
template<class _T> inline
	_T _Fabs(const complex<_T>& _X, int *_Pexp)
	{*_Pexp = 0;
	_T _A = real(_X);
	_T _B = imag(_X);
	if (_Ctr<_T>::_Isnan(_A))
		return (_A);
	else if (_Ctr<_T>::_Isnan(_B))
		return (_B);
	else
		{if (_A < 0)
			_A = -_A;
		if (_B < 0)
			_B = -_B;
		if (_A < _B)
			{_T _W = _A;
			_A = _B, _B = _W; }
		if (_A == 0 || _Ctr<_T>::_Isinf(_A))
			return (_A);
		if (1 <= _A)
			*_Pexp = 2, _A *= 0.25, _B *= 0.25;
		else
			*_Pexp = -2, _A *= 4, _B *= 4;
		_T _W = _A - _B;
		if (_W == _A)
			return (_A);
		else if (_B < _W)
			{const _T _Q = _A / _B;
			return (_A + _B
				/ (_Q + _Ctr<_T>::sqrt(_Q * _Q + 1))); }
		else
			{static const _T _R2 = 1.4142135623730950488L;
			static const _T _Xh = 2.4142L;
			static const _T _Xl = 0.0000135623730950488016887L;
			const _T _Q = _W / _B;
			const _T _R = (_Q + 2) * _Q;
			const _T _S = _R / (_R2 + _Ctr<_T>::sqrt(_R + 2))
				+ _Xl + _Q + _Xh;
			return (_A + _B / _S); }}}
		// TEMPLATE FUNCTION operator+
template<class _T> inline
	complex<_T> operator+(const complex<_T>& _L,
		const complex<_T>& _R)
	{return (complex<_T>(_L) += _R); }
template<class _T> inline
	complex<_T> operator+(const complex<_T>& _L, const _T& _R)
	{complex<_T> _W(_L);
	_W.real(_W.real() + _R);
	return (_W); }
template<class _T> inline
	complex<_T> operator+(const _T& _L, const complex<_T>& _R)
	{return (complex<_T>(_L) += _R); }
		// TEMPLATE FUNCTION operator-
template<class _T> inline
	complex<_T> operator-(const complex<_T>& _L,
		const complex<_T>& _R)
	{return (complex<_T>(_L) -= _R); }
template<class _T> inline
	complex<_T> operator-(const complex<_T>& _L, const _T& _R)
	{complex<_T> _W(_L);
	_W.real(_W.real() - _R);
	return (_W); }
template<class _T> inline
	complex<_T> operator-(const _T& _L, const complex<_T>& _R)
	{return (complex<_T>(_L) -= _R); }
		// TEMPLATE FUNCTION operator*
template<class _T> inline
	complex<_T> operator*(const complex<_T>& _L,
		const complex<_T>& _R)
	{return (complex<_T>(_L) *= _R); }
template<class _T> inline
	complex<_T> operator*(const complex<_T>& _L, const _T& _R)
	{complex<_T> _W(_L);
	_W.real(_W.real() * _R);
	_W.imag(_W.imag() * _R);
	return (_W); }
template<class _T> inline
	complex<_T> operator*(const _T& _L, const complex<_T>& _R)
	{return (complex<_T>(_L) *= _R); }
		// TEMPLATE FUNCTION operator/
template<class _T> inline
	complex<_T> operator/(const complex<_T>& _L,
		const complex<_T>& _R)
	{return (complex<_T>(_L) /= _R); }
template<class _T> inline
	complex<_T> operator/(const complex<_T>& _L, const _T& _R)
	{complex<_T> _W(_L);
	_W.real(_W.real() / _R);
	_W.imag(_W.imag() / _R);
	return (_W); }
template<class _T> inline
	complex<_T> operator/(const _T& _L, const complex<_T>& _R)
	{return (complex<_T>(_L) /= _R); }
		// TEMPLATE FUNCTION UNARY operator+
template<class _T> inline
	complex<_T> operator+(const complex<_T>& _L)
	{return (complex<_T>(_L)); }
		// TEMPLATE FUNCTION UNARY operator-
template<class _T> inline
	complex<_T> operator-(const complex<_T>& _L)
	{return (complex<_T>(-real(_L), -imag(_L))); }
		// TEMPLATE FUNCTION operator==
template<class _T> inline
	bool operator==(const complex<_T>& _L, const complex<_T>& _R)
	{return (real(_L) == real(_R) && imag(_L) == imag(_R)); }
template<class _T> inline
	bool operator==(const complex<_T>& _L, const _T& _R)
	{return (real(_L) == _R && imag(_L) == 0); }
template<class _T> inline
	bool operator==(const _T& _L, const complex<_T>& _R)
	{return (_L == real(_R) && 0 == imag(_R)); }
		// TEMPLATE FUNCTION operator!=
//template<class _T> inline
//	bool operator!=(const complex<_T>& _L, const complex<_T>& _R)
//	{return (!(_L == _R)); }
template<class _T> inline
	bool operator!=(const complex<_T>& _L, const _T& _R)
	{return (!(_L == _R)); }
template<class _T> inline
	bool operator!=(const _T& _L, const complex<_T>& _R)
	{return (!(_L == _R)); }
		// TEMPLATE FUNCTION operator>>
template<class _T> inline
	istream& operator>>(istream& _I, complex<_T>& _X)
	{char _Ch;
	long double _Re, _Im;
	if (_I >> _Ch && _Ch != '(')
		_I.putback(_Ch), _I >> _Re, _Im = 0;
	else if (_I >> _Re >> _Ch && _Ch != ',')
		if (_Ch == ')')
			_Im = 0;
		else
			_I.putback(_Ch), _I.setstate(ios_base::failbit);
	else if (_I >> _Im >> _Ch && _Ch != ')')
			_I.putback(_Ch), _I.setstate(ios_base::failbit);
	if (!_I.fail())
		_X = complex<_T>((_T)_Re, (_T)_Im);
	return (_I); }
		// TEMPLATE FUNCTION operator<<
template<class _T> inline
	ostream& operator<<(ostream& _O, const complex<_T>& _X)
	{return (_O << '(' << real(_X) << ',' << imag(_X) << ')'); }
		// TEMPLATE FUNCTION abs
template<class _T> inline
	_T abs(const complex<_T>& _X)
	{int _Xexp;
	_T _Rho = _Fabs(_X, &_Xexp);
	return (_Xexp == 0 ? _Rho : _Ctr<_T>::ldexp(_Rho, _Xexp)); }
		// TEMPLATE FUNCTION arg
template<class _T> inline
	_T arg(const complex<_T>& _X)
	{return (_Ctr<_T>::atan2(imag(_X), real(_X))); }
		// TEMPLATE FUNCTION conjg
template<class _T> inline
	complex<_T> conj(const complex<_T>& _X)
	{return (complex<_T>(real(_X), -imag(_X))); }
		// TEMPLATE FUNCTION cos
template<class _T> inline
	complex<_T> cos(const complex<_T>& _X)
	{return (complex<_T>(
		_Ctr<_T>::_Cosh(imag(_X), _Ctr<_T>::cos(real(_X))),
		-_Ctr<_T>::_Sinh(imag(_X), _Ctr<_T>::sin(real(_X))))); }
		// TEMPLATE FUNCTION cosh
template<class _T> inline
	complex<_T> cosh(const complex<_T>& _X)
	{return (complex<_T>(
		_Ctr<_T>::_Cosh(real(_X), _Ctr<_T>::cos(imag(_X))),
		_Ctr<_T>::_Sinh(real(_X), _Ctr<_T>::sin(imag(_X))))); }
		// TEMPLATE FUNCTION exp
template<class _T> inline
	complex<_T> exp(const complex<_T>& _X)
	{_T _Re(real(_X)), _Im(real(_X));
	_Ctr<_T>::_Exp(&_Re, _Ctr<_T>::cos(imag(_X)), 0);
	_Ctr<_T>::_Exp(&_Im, _Ctr<_T>::sin(imag(_X)), 0);
	return (complex<_T>(_Re, _Im)); }
		// TEMPLATE FUNCTION log
template<class _T> inline
	complex<_T> log(const complex<_T>& _X)
	{int _Xexp;
	_T _Rho = _Fabs(_X, &_Xexp);
	if (_Ctr<_T>::_Isnan(_Rho))
		return (complex<_T>(_Rho, _Rho));
	else
		{static const _T _Cm = 22713.0 / 32768.0;
		static const _T _Cl = 1.428606820309417232e-6L;
		_T _Xn = _Xexp;
		complex<_T> _W(_Rho == 0 ? -_Ctr<_T>::_Infv(_Rho)
			: _Ctr<_T>::_Isinf(_Rho) ? _Rho
			: _Ctr<_T>::log(_Rho) + _Xn * _Cl + _Xn * _Cm,
				_Ctr<_T>::atan2(imag(_X), real(_X)));
		return (_W); }}
		// TEMPLATE FUNCTION log10
template<class _T> inline
	complex<_T> log10(const complex<_T>& _X)
	{return (log(_X) * (_T)0.4342944819032518276511289L); }
		// TEMPLATE FUNCTION norm
template<class _T> inline
	_T norm(const complex<_T>& _X)
	{return (real(_X) * real(_X) + imag(_X) * imag(_X)); }
		// TEMPLATE FUNCTION polar
template<class _T> inline
	complex<_T> polar(const _T& _Rho, const _T& _Theta)
	{return (complex<_T>(_Rho * _Ctr<_T>::cos(_Theta),
		_Rho * _Ctr<_T>::sin(_Theta))); }
		// TEMPLATE FUNCTION pow
template<class _T> inline
	complex<_T> pow(const complex<_T>& _X, const complex<_T>& _Y)
	{return (imag(_Y) == 0 ? pow(_X, real(_Y))
		: imag(_X) == 0 ? complex<_T>(pow(real(_X), _Y))
		: exp(_Y * log(_X))); }
template<class _T> inline
	complex<_T> pow(const complex<_T>& _X, const _T& _Y)
	{return (imag(_X) == 0 ? complex<_T>(
		_Ctr<_T>::pow(real(_X), _Y))
		: exp(_Y * log(_X))); }
template<class _T> inline
	complex<_T> pow(const complex<_T>& _X, int _Y)
	{if (imag(_X) == 0)
		return (complex<_T>(pow(real(_X), _Y)));
	else
		return (_Pow_int(complex<_T>(_X), _Y)); }
template<class _T> inline
	complex<_T> pow(const _T& _X, const complex<_T>& _Y)
	{return (imag(_Y) == 0
		? complex<_T>(_Ctr<_T>::pow(_X, real(_Y)))
		: exp(_Y * _Ctr<_T>::log(_X))); }
		// TEMPLATE FUNCTION sin
template<class _T> inline
	complex<_T> sin(const complex<_T>& _X)
	{return (complex<_T>(
		_Ctr<_T>::_Cosh(imag(_X), _Ctr<_T>::sin(real(_X))),
		_Ctr<_T>::_Sinh(imag(_X), _Ctr<_T>::cos(real(_X))))); }
		// TEMPLATE FUNCTION sinh
template<class _T> inline
	complex<_T> sinh(const complex<_T>& _X)
	{return (complex<_T>(
		_Ctr<_T>::_Sinh(real(_X), _Ctr<_T>::cos(imag(_X))),
		_Ctr<_T>::_Cosh(real(_X), _Ctr<_T>::sin(imag(_X))))); }
		// TEMPLATE FUNCTION sqrt
template<class _T> inline
	complex<_T> sqrt(const complex<_T>& _X)
	{int _Xexp;
	_T _Rho = _Fabs(_X, &_Xexp);
	if (_Xexp == 0)
		return (complex<_T>(_Rho, _Rho));
	else
		{_T _Remag = _Ctr<_T>::ldexp(real(_X) < 0
			? - real(_X) : real(_X), -_Xexp);
		_Rho = _Ctr<_T>::ldexp(_Ctr<_T>::sqrt(
			2 * (_Remag + _Rho)), _Xexp / 2 - 1);
		if (0 <= real(_X))
			return (complex<_T>(_Rho, imag(_X) / (2 * _Rho)));
		else if (imag(_X) < 0)
			return (complex<_T>(-imag(_X) / (2 * _Rho), -_Rho));
		else
			return (complex<_T>(imag(_X) / (2 * _Rho), _Rho)); }}
_STD_END
#endif /* _COMPLEX_ */



