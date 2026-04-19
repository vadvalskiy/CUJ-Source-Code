class sentry {
public:
    explicit sentry(istream& _Is, bool _Noskip = false)
        : _Lk(_LOCK_STREAM), _Ok(_Is.ipfx(_Noskip))
        {}
    operator bool() const
        {return (_Ok); }
private:
    sentry(const sentry&);    // not defined
    sentry& operator=(const sentry&);    // not defined
    bool _Ok;
    _Lockit _Lk;
    };


