Listing 5 -- class xdomain

class xdomain : public xlogic {
protected:
	virtual void do_raise();
public:
	xdomain(const char *what_arg = 0, const char *where_arg 
= 0,
		const char *why_arg = 0);
	virtual ~xdomain();
	};
