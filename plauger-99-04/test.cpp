const char *fname = "myfile";

bool write_file(wchar_t code = 0)
    {locale loc = _ADDFAC(locale::classic(), new Mycodecvt);
    wofstream myostr;
    myostr.imbue(loc);
    myostr.open(fname, ios_base::binary);
    if (!myostr.is_open())
        {cerr << "can't write to " << fname << endl;
        return (false); }
    if (code != 0 && !myostr.write(&code, 1))
        {cerr << "failed for code = " << (int)code << endl;
        return (false); }
    for (wchar_t i = 0; i < 0xfff; ++i)
        if (!myostr.write(&i, 1))
            {cerr << "write failed for i = " << (int)i << endl;
            return (false); }
    return (true); }

bool read_file()
    {locale loc = _ADDFAC(locale::classic(), new Mycodecvt);
    wifstream myistr;
    myistr.imbue(loc);
    myistr.open(fname, ios_base::binary);
    if (!myistr.is_open())
        {cerr << "can't read from " << fname << endl;
        return (false); }
    for (wchar_t i = 0; i < 0xfff; ++i)
        {wchar_t n = 0;
        if (!myistr.read(&n, 1) || n != i)
            {cerr << "read failed for i = " << (int)i << endl;
            return (false); }}
    return (true); }

int main(int argc, char **argv)
    {wchar_t arg = argc < 2 ? 0
        : *argv[1] == 'b' ? 0xfeff : 0xfffe;
    return (write_file(arg) && read_file()); }
