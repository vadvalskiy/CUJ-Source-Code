---------------- Listing 1: The header <streambuf> --------------

// streambuf standard header
#ifndef _STREAMBUF_
#define _STREAMBUF_
#include <ios>
		// macros
#define EOF	(-1)
		// type streamoff
typedef long streamoff;
const streamoff _BADOFF = -1;
		// class streampos
class streampos {
public:
	streampos(streamoff = 0, const _Fpost * = 0);
	streamoff offset() const;
	streamoff operator-(const streampos&) const;
	streampos& operator+=(streamoff _O)
		{_Pos += _O; return (*this); }
	streampos& operator-=(streamoff _O)
		{_Pos -= _O; return (*this); }
	streampos operator+(streamoff _O) const
		{return (streampos(*this) += _O); }
	streampos operator-(streamoff _O) const
		{return (streampos(*this) -= _O); }
	_Bool operator==(const streampos&) const;
	_Bool operator!=(const streampos& _R) const
		{return (!(*this == _R)); }
	_Fpost *_Fpos()
		{return (&_Fp); }
private:
	streamoff _Pos;
	_Fpost _Fp;
	};
		// class streambuf
class streambuf {
public:
	virtual ~streambuf();
	streampos pubseekoff(streamoff _O, ios::seekdir _W,
		ios::openmode _M = ios::in | ios::out)
		{return (seekoff(_O, _W, _M)); }
	streampos pubseekpos(streampos _P,
		ios::openmode _M = ios::in | ios::out)
		{return (seekpos(_P, _M)); }
	streambuf *pubsetbuf(char *_S, int _N)
		{return (setbuf(_S, _N)); }
	int pubsync()
		{return (sync()); }
	int sbumpc()
		{return (gptr() != 0 && gptr() < egptr()
			? *_Gn()++ : uflow()); }
	int sgetc()
		{return (gptr() != 0 && gptr() < egptr()
			? *_Gn() : underflow()); }
	int sgetn(char *_S, int _N)
		{return (xsgetn(_S, _N)); }
	int snextc()
		{return (sbumpc() == EOF ? EOF : sgetc()); }
	int sputbackc(char _C)
		{return (gptr() != 0 && eback() < gptr()
			&& _C == gptr()[-1]
			? *--_Gn() : pbackfail((unsigned char)_C)); }
	int sungetc()
		{return (gptr() != 0 && eback() < gptr()
			? *--_Gn() : pbackfail()); }
	int sputc(int _C)
		{return (pptr() != 0 && pptr() < epptr()
			? (*_Pn()++ = _C) : overflow(_C)); }
	int sputn(const char *_S, int _N)
		{return (xsputn(_S, _N)); }
#if _HAS_ENUM_OVERLOADING
	streampos pubseekoff(streamoff _O, ios::seek_dir _W,
		ios::open_mode _M = ios::in | ios::out)
		{return (pubseekoff(_O, (seekdir)_W, (openmode)_M)); }
	streampos pubseekpos(streampos _P,
		ios::open_mode _M = ios::in | ios::out)
		{return (seekpos(_P, (openmode)_M)); }
#endif
protected:
	streambuf()
		{_Init(); }
	streambuf(_Uninitialized)
		{}
	char *eback() const
		{return (*_IGbeg); }
	char *gptr() const
		{return (*_IGnext); }
	char *egptr() const
		{return (*_IGend); }
	void gbump(int _N)
		{*_IGnext += _N; }
	void setg(char *_B, char *_N, char *_E)
		{*_IGbeg = _B, *_IGnext = _N, *_IGend = _E; }
	char *pbase() const
		{return (*_IPbeg); }
	char *pptr() const
		{return (*_IPnext); }
	char *epptr() const
		{return (*_IPend); }
	void pbump(int _N)
		{*_IPnext += _N; }
	void setp(char *_B, char *_E)
		{*_IPbeg = _B, *_IPnext = _B, *_IPend = _E; }
	unsigned char *&_Gn()
		{return ((unsigned char *&)*_IGnext); }
	unsigned char *&_Pn()
		{return ((unsigned char *&)*_IPnext); }
	virtual int overflow(int = EOF);
	virtual int pbackfail(int = EOF);
	virtual int underflow();
	virtual int uflow();
	virtual int xsgetn(char *, int);
	virtual int xsputn(const char *, int);
	virtual streampos seekoff(streamoff, ios::seekdir,
		ios::openmode = ios::in | ios::out);
	virtual streampos seekpos(streampos,
		ios::openmode = ios::in | ios::out);
	virtual streambuf *setbuf(char *, int);
	virtual int sync();
	void _Init();
	void _Init(char **, char **, char **, char **, char **,
		char **);
private:
	char *_Gbeg, *_Gnext, *_Gend;
	char *_Pbeg, *_Pnext, *_Pend;
	char **_IGbeg, **_IGnext, **_IGend;
	char **_IPbeg, **_IPnext, **_IPend;
	};
#endif


