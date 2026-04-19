Listing 3 -- class xlogic

class xlogic : public xmsg {
protected:
	virtual void do_raise();
public:
	xlogic(const char *what_arg = 0, const char *where_arg 
= 0,
		const char *why_arg = 0);
	virtual ~xlogic();
	};
