        // CLASS _Lockit
class _Lockit
    {    // lock while object in existence
public:
    explicit _Lockit(int = 0)
        {}    // DUMMY -- turn on lock here
    ~_Lockit()
        {}    // DUMMY -- turn off lock here
    };
