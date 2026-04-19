Listing 4 -- class xruntime

class xruntime : public xmsg {
protected:
	virtual void do_raise();
	xruntime(const char *what_arg, const char *where_arg,
		const char *why_arg, int copyfl);
public:
	xruntime(const char *what_arg = 0, const char *where_arg 
= 0,
		const char *why_arg = 0);
	virtual ~xruntime();
	};
