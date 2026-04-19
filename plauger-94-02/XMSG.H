Listing 1 -- class xmsg

class xmsg {
public:
	typedef void(*raise_handler)(xmsg&);
private:
	const char *what, *where, *why;	// exposition 
only
	int alloced;					// exposition only
	static raise_handler handler;	// exposition only
protected:
	virtual void do_raise();
	xmsg(const char *what_arg, const char *where_arg,
const char *why_arg, int copyfl);
public:
	xmsg(const char *what_arg = 0, const char *where_arg 
= 0,
		const char *why_arg = 0);
	virtual ~xmsg();
	void raise();
	const char *what() const;
	const char *where() const;
	const char *why() const;
	static raise_handler set_raise_handler(raise_handler handler_arg);
	};
