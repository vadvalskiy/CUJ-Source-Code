// simple stream buffer
#include <istream>
#include <stdio.h>
using std::endl;
using std::iostream;
using std::istream;
using std::ostream;
using std::streambuf;

      // CLASS simple_filebuf
class simple_filebuf : public streambuf {
public:
   simple_filebuf()
      : saved(-1)
      {}
   virtual ~simple_filebuf()
      {}

protected:
   virtual int_type overflow(int_type ch = traits_type::eof())
      {if (traits_type::eq_int_type(traits_type::eof(), ch))
         return (traits_type::not_eof(ch));
      else
         return (putchar(traits_type::to_char_type(ch)) != EOF
            ? ch : traits_type::eof()); }

   virtual int_type pbackfail(int_type ch = traits_type::eof())
      {if (0 <= saved)
         return (traits_type::eof());   // buffer in use
      else if (traits_type::eq_int_type(traits_type::eof(), ch))
         return (traits_type::eof());   // can't just backup
      else
         {saved = (unsigned char)traits_type::to_char_type(ch);
         return (ch); }}

   virtual int_type underflow()
      {return (pbackfail(uflow())); }

   virtual int_type uflow()
      {int_type ch = saved;
      if (0 <= ch)
         {saved = -1;   // erase saved char
         return (ch); }
      else
         return ((ch = getchar()) != EOF ? ch
            : traits_type::eof()); }

private:
   int saved;   // negative ==> no saved char
   };

      // CLASS simple_ifstream
class simple_ifstream : public istream {
public:
   simple_ifstream()
      : istream(&mybuf)
      {}
   virtual ~simple_ifstream()
      {}
   simple_filebuf *rdbuf() const
      {return ((simple_filebuf *)&mybuf); }

private:
   simple_filebuf mybuf;
   };

      // CLASS simple_ofstream
class simple_ofstream : public ostream {
public:
   simple_ofstream()
      : ostream(&mybuf)
      {}
   virtual ~simple_ofstream()
      {}
   simple_filebuf *rdbuf() const
      {return ((simple_filebuf *)&mybuf); }

private:
   simple_filebuf mybuf;
   };

      // CLASS simple_fstream
class simple_fstream : public iostream {
public:
   simple_fstream()
      : iostream(&mybuf)
      {}
   virtual ~simple_fstream()
      {}
   simple_filebuf *rdbuf() const
      {return ((simple_filebuf *)&mybuf); }

private:
   simple_filebuf mybuf;
   };


// Test it
int main(void)
   {simple_ofstream ofs;
   ofs << "hello world" << endl;

   int x;
   simple_ifstream ifs;
   ifs >> x;
   ofs << "x = " << x << endl;

   simple_fstream fs;
   fs << "hello again" << endl;
   fs >> x;
   fs << "x = " << x << endl;
   return (0); }
