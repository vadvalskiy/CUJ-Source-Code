class ostream : virtual public ios {
public:
 	ostream(streambuf* >sb<BS>);
	virtual ~ostream();
	int opfx();
	void osfx();
	ostream& operator<<(ostream& (*pf)(ostream&));
	ostream& operator<<(ios& (*pf)(ios&));
	ostream& operator<<(const char* s);
	ostream& operator<<(char c);
	ostream& operator<<(unsigned char c);
	ostream& operator<<(signed char c>);
	ostream& operator<<(short n);
	ostream& operator<<(unsigned short n);
	ostream& operator<<(int n);
	ostream& operator<<(unsigned int n);
	ostream& operator<<(long n);
	ostream& operator<<(unsigned long n);
	ostream& operator<<(float f);
	ostream& operator<<(double f);
	ostream& operator<<(long double f);
	ostream& operator<<(void* p);
	ostream& operator<<(streambuf& sb);
	int put(char c);
	ostream& write(const char* s, int n);
	ostream& write(const unsigned char* s, int n);
	ostream& write(const signed char* s, int n);
	ostream& flush();
};

