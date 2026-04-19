/* test wctype functions */
#include <assert.h>
#include <limits.h>
#include <stdio.h>
#include <wchar.h>
#include <wctype.h>

#define _L(x)   L ## x

static void prclass(const char *name, int (*fn)(wint_t))
    {       /* display a printable character class */
    int i;
    wchar_t wc;

    fputs(name, stdout), fputs(":\t", stdout);
    for (wc = WCHAR_MIN, i = 0; wc <= UCHAR_MAX; ++wc)
        if (iswprint(wc) && (*fn)(wc))
            {       /* print 32 chars to a row */
            if (0 < i && i % 32 == 0)
                fputs("\t\t", stdout);
            fputc(wctob(wc), stdout);
            if (++i % 32 == 0)
                fputc('\n', stdout);
            }
    if (i == 0 || i % 32 != 0)
        fputc('\n', stdout);
    }

static void prtrans(const char *name, wint_t (*fn)(wint_t))
    {       /* display a printable character translation */
    int i;
    wchar_t wc;

    fputs(name, stdout), fputs(":\t", stdout);
    for (wc = WCHAR_MIN, i = 0; wc <= UCHAR_MAX; ++wc)
        if (iswprint((*fn)(wc)))
            {       /* print 32 chars to a row */
            if (0 < i && i % 32 == 0)
                fputs("\t\t", stdout);
            fputc(wctob((*fn)(wc)), stdout);
            if (++i % 32 == 0)
                fputc('\n', stdout);
            }
    if (i == 0 || i % 32 != 0)
        fputc('\n', stdout);
    }

int main()
    {       /* test wctype functions */
    char *s;
    wchar_t wc;

    /* display all printable chars by class */
    prclass("iswalpha", &iswalpha);
    prclass("iswalnum", &iswalnum);
    prclass("iswcntrl", &iswcntrl);
    prclass("iswdigit", &iswdigit);
    prclass("iswgraph", &iswgraph);
    prclass("iswlower", &iswlower);
    prclass("iswprint", &iswprint);
    prclass("iswpunct", &iswpunct);
    prclass("iswspace", &iswspace);
    prclass("iswupper", &iswupper);
    prclass("iswxdigit", &iswxdigit);
    prtrans("towlower", &towlower);
    prtrans("towupper", &towupper);
        /* test for required characters */
    for (s = "0123456789"; *s; ++s)
        assert(iswdigit(btowc(*s)) && iswxdigit(btowc(*s)));
    for (s = "abcdefABCDEF"; *s; ++s)
        assert(iswxdigit(btowc(*s)));
    for (s = "abcdefghijklmnopqrstuvwxyz"; *s; ++s)
        assert(iswlower(btowc(*s)));
    for (s = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"; *s; ++s)
        assert(iswupper(btowc(*s)));
    for (s = "!\"#%&'();<=>?[\\]*+,-./:^_{|}~"; *s; ++s)
        assert(iswpunct(btowc(*s)));
    for (s = "\f\n\r\t\v"; *s; ++s)
        assert(iswspace(btowc(*s)) && iswcntrl(btowc(*s)));
    assert(iswspace(_L(' ')) && iswprint(_L(' ')));
    assert(iswcntrl(_L('\a')) && iswcntrl(_L('\b')));
        /* test functions for all valid codes */
    for (wc = WCHAR_MIN; wc <= UCHAR_MAX; ++wc)
        {       /* test for proper class membership */
        wctrans_t tr = wctrans("toupper");
        wctype_t ty = wctype("alnum");
        wint_t weof = WEOF;

        assert(tr != 0 && ty != 0);
        assert(iswalnum(wc)
            == iswctype(wc, wctype("alnum")));
        assert(iswalpha(wc)
            == iswctype(wc, wctype("alpha")));
        assert(iswcntrl(wc)
            == iswctype(wc, wctype("cntrl")));
        assert(iswdigit(wc)
            == iswctype(wc, wctype("digit")));
        assert(iswgraph(wc)
            == iswctype(wc, wctype("graph")));
        assert(iswlower(wc)
            == iswctype(wc, wctype("lower")));
        assert(iswprint(wc)
            == iswctype(wc, wctype("print")));
        assert(iswpunct(wc)
            == iswctype(wc, wctype("punct")));
        assert(iswspace(wc)
            == iswctype(wc, wctype("space")));
        assert(iswupper(wc)
            == iswctype(wc, wctype("upper")));
        assert(iswxdigit(wc)
            == iswctype(wc, wctype("xdigit")));
        assert(towlower(wc)
            == towctrans(wc, wctrans("tolower")));
        assert(towupper(wc)
            == towctrans(wc, wctrans("toupper")));
        if (iswdigit(wc))
            assert(iswalnum(wc));
        if (iswupper(wc))
            assert(iswalpha(wc));
        if (iswlower(wc))
            assert(iswalpha(wc));
        if (iswalpha(wc))
            assert(iswalnum(wc) && !iswdigit(wc));
        if (iswalnum(wc))
            assert(iswgraph(wc) && !iswpunct(wc));
        if (iswpunct(wc))
            assert(iswgraph(wc));
        if (iswgraph(wc))
            assert(iswprint(wc));
        if (iswspace(wc))
            assert(wc == _L(' ') || !iswprint(wc));
        if (iswcntrl(wc))
            assert(!iswalnum(wc));
        assert(towlower(wc) == wc || wctob(towlower(wc))
            == "abcdefghijklmnopqrstuvwxyz"[wc - _L('A')]);
        assert(towupper(wc) == wc || wctob(towupper(wc))
            == "ABCDEFGHIJKLMNOPQRSTUVWXYZ"[wc - _L('a')]);
        }
    puts("SUCCESS testing <wctype.h>");
    return (0);
    }
