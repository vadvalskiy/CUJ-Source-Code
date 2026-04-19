---------------- Listing 1: The header <istream> --------------
// istream standard header
#ifndef _ISTREAM_
#define _ISTREAM_
#include <streambuf>
		// class istream
class istream : virtual public ios {
public:
	istream(streambuf *_S)
		: _Chcount(0), ios(_S) {}
	istream(_Uninitialized)
		: ios(_Noinit) {}
	virtual ~istream();
	_Bool ipfx(int = 0);
	void isfx()
		{}
	istream& operator>>(istream& (*_F)(istream&))
		{return ((*_F)(*this)); }
	istream& operator>>(ios& (*_F)(ios&))
		{(*_F)(*(ios *)this); return (*this); }
	istream& operator>>(char *);
	istream& operator>>(unsigned char *_S)
		{return (*this >> (char *)_S); }
	istream& operator>>(char&);
	istream& operator>>(unsigned char& _C)
		{return (*this >> *(char *)&_C); }
	istream& operator>>(short&);
	istream& operator>>(unsigned short&);
	istream& operator>>(int&);
	istream& operator>>(unsigned int&);
	istream& operator>>(long&);
	istream& operator>>(unsigned long&);
	istream& operator>>(float&);
	istream& operator>>(double&);
	istream& operator>>(long double&);
	istream& operator>>(void *&);
	istream& operator>>(streambuf&);
	int get();
	istream& get(char *, int, char = '\n');
	istream& get(unsigned char *_S, int _N, char _D = '\n')
		{return(get((char *)_S, _N, _D)); }
	istream& get(char&);
	istream& get(unsigned char& _C)
		{return (get((char&)_C)); }
	istream& get(streambuf&, char = '\n');
	istream& getline(char *, int, char = '\n');
	istream& getline(unsigned char *_S, int _N, char _D = '\n')
		{return(getline((char *)_S, _N, _D)); }
	istream& ignore(int = 1, int = EOF);
	istream& read(char *, int);
	istream& read(unsigned char *_S, int _N)
		{return(read((char *)_S, _N)); }
	int peek();
	istream& putback(char);
	istream& unget();
	int gcount() const
		{return (_Chcount); }
	int sync();
#if _SIGNED_CHAR_IS_DISTINCT
	istream& operator>>(signed char *_S)
		{return (*this >> (char *)_S); }
	istream& operator>>(signed char& _C)
		{return (*this >> *(char *)&_C); }
	istream& get(signed char *_S, int _N, char _D = '\n')
		{return (get((char *)_S, _N, _D)); }
	istream& get(signed char& _C)
		{return (get((char&)_C); }
	istream& getline(signed char *_S, int _N, char _D = '\n')
		{return (getline((char *)_S, _N, _D)); }
	istream& read(signed char *_S, int _N)
		{return (read((char *)_S, _N)); }
#endif /* _SIGNED_CHAR_IS_DISTINCT */
protected:
	int _Getffld(char [_MAX_EXP_DIG+_MAX_SIG_DIG+16]);
	int _Getifld(char [_MAX_INT_DIG]);
private:
	int _Chcount;
	};
		// manipulators
istream& ws(istream&);
#endif
