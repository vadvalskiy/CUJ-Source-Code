Standard C/C++
P. J. Plauger
Library Update
After nearly four years of describing the draft Standard C++ library, our Senior Editor takes time out to provide an overview of this ambitious specification and how the library can most safely be used with today's implementations.

Introduction
I began describing the draft Standard C++ library in these monthly columns nearly four years ago. (See "Standard C/C++: Developing the Standard C++ Library," CUJ, October 1993.) Way back then, it looked like the whole standardization effort — or at least all the invention that has accompanied it — would be brought to a close within a matter of months. I was even foolish enough to believe the official party line and produced a book on what I thought would be the definitive description of the Standard C++ library. (See P.J. Plauger, The Draft Standard C++ Library, Prentice-Hall, 1995.)

I was ridiculously optimistic, as it turned out. No sooner had I completed that book but Committees X3J16 (ANSI) and WG21 (ISO) began a major round of additions to the draft Standard C++ library. They "templatized" iostreams, the string class, and complex arithmetic. They added a very ambitious, and inventive, mechanism for specifying culture-specific locales. They added the Standard Template Library (STL), which has been the subject of this column for the past year and a half. And along the way, they tossed in a few other odds and ends, almost as an afterthought.

The book I wrote is still a useful reference. It describes the portion of the library that most resembles existing practice. That also happens to be the portion of the library that is still most widely used. But it is hardly a complete reference to the entire library now. To supplement the most important omission from that work, I began working on an STL book. My coauthors are Alex Stepanov, Meng Lee, and Dave Musser, the folks who developed the original STL. We expected to have that book on the market by now, but the Committees keep making changes. (I've been reading about still more proposed changes to the STL portion of the draft Standard C++ library even as I write this installment.) I certainly don't want to make yet another major effort that has only transient authority.

The draft C++ Standard is nevertheless settling down, despite the ongoing pressures for continuing invention and experimentation. The Committees nominally have only two more meetings to make changes, in July and November 1997. And those changes are nominally constrained in nature and scope. (I say "nominally" because the Committees have been notoriously elastic in how they interpret and carry out ISO procedures for developing standards.) Perhaps a better harbinger is the attitude of commercial compiler vendors. They have begun to take seriously the business of matching the draft C++ Standard in detail. As someone who makes a living implementing libraries that match standards, I can only welcome this trend.

I'm willing to believe, once again, that the draft Standard C++ library is a reasonably well defined entity, however large. In the interest of completeness, I intend to try once again to describe it in its entirety. No, I don't plan to revisit in detail all of iostreams, for example. I'll confine myself to just outlining the major changes that it has suffered over the past few years. But I will devote some attention, in the last few installments of this protracted survey, to those "odds and ends" I haven't really touched on to date.

To begin the final wrapup, I provide here an overview of the library as it is now constituted, both in theory and in practice.

The Standard Headers
As you probably know, all C++ library entities are declared or defined in one or more standard headers. To make use of a library entity in a program, you write an include directive that names the relevant standard header. The declarations and definitions within each header tend to be more or less logically related. For all these reasons, I tend to think of the library, and describe it, in terms of its headers.

A full conforming implementation of the draft C++ Standard library requires 69 headers. (Yes, that many.) Fifteen of these are the old familiar headers defined by the C Standard since 1989. Most of these, in turn, derive from the first C libraries developed in the early 1970s:

<assert.h>	<ctype.h>	<errno.h>
<float.h>	<limits.h>	<locale.h>
<math.h>	<setjmp.h>	<signal.h>
<stdarg.h>	<stddef.h>	<stdio.h>
<stdlib.h>	<string.h>	<time.h>
Another three are the headers defined by Amendment 1 to the C Standard, approved in 1995:

<iso646.h>	<wchar.h>	<wctype.h>
The header <iso646.h> is there for completeness only. All of its functionality has been captured in keywords in C++.

These headers aren't defined exactly the same as for Standard C, however:

The headers must not define macros that hide function declarations, since only signatures are reserved in C++, not function names.
The header <math.h> must supply the standard math functions in all three floating-point precisions, not just double.
Many functions in <math.h> and <stdlib.h>, such as abs, are overloaded on multiple arithmetic types.
Several signatures in <string.h> are each replaced by a pair of slightly different signatures.
More important, and still controversial, is the interaction of these headers with namespaces, which I discuss further below. At this point, I'll simply observe that C++ adds 18 variants of the C headers listed above:

<cassert>    <cctype>    <cerrno>
<cfloat>     <ciso646>   <climits>
<clocale>    <cmath>     <csetjmp>
<csignal>    <cstdarg>   <cstddef>
<cstdio>     <cstdlib>   <cstring>
<ctime>      <cwchar>    <cwctype>
The idea is that new C++ programs should include these headers, rather than the older C headers, because they add no terms to the global namespace. (Macros fare no better, of course, because they ride roughshod over the whole concept of name scoping in C and C++.)

The remaining 33 headers are what we tend to think of as the C++ library. They have no real roots in C. Four can be though of as language support. They define the exceptions that the library throws, and supporting functions for the operators delete, new, and typeid:

<exception>	<new>	<stdexcept>
<typeinfo>
Of these, only <new> derives from "existing practice." It is the modern successor to the header <new.h> that has accompanied C++ implementations since time immemorial.

Speaking of old friends, another mostly familiar batch of headers implements the family of related classes traditionally called iostreams. They are now ten in number:

<fstream>    <iomanip>    <ios>
<iosfwd>     <iostream>   <istream>
<ostream>    <sstream>    <streambuf>
<strstream>
Of these new additions, several simply divvy up the contents of the extensive traditional header <iostream.h> — <ios>, <istream>, <iostream>, <ostream>, and streambuf. The header <iosfwd> supplies forward references to numerous classes, mostly in iostreams, to break up some nasty dependency loops within the library. You should seldom, if ever, have occasion to explicitly include any of these headers except <iostream>.

On the other hand, you might well want to include <sstream>. It is a more modern version of <strstream> (still retained, but branded as obsolescent) that deals in string objects rather than less structured character buffers. And, of course, <fstream> is the modern descendant of the old header <fstream.h>, for reading and writing named files.

Then there are the thirteen headers that constitute the Standard Template Library, as standardized by ISO:

<algorithm>    <deque>    <functional>
<iterator>     <list>     <map>
<memory>       <numeric>  <queue>
<set>          <stack>    <utility>
<vector>
Early users of STL will recognize none of these. They were all invented as part of the standardization process, after STL was voted into the draft. They are the headers I've been describing for the past year and a half in these pages.

Finally comes half a dozen headers that I persist in calling "odds and ends:"

<bitset>  <complex>  <limits>
<locale>  <string>   <valarray>
I described earlier versions of half of these creatures in previous years:

<bitset> defines a template class intended to replace all those flag words you've defined with enumerations and macros in older code.
<complex> defines a template class intended to support complex arithmetic in at least the three flavors of floating-point arithmetic.
<string> defines an ambitious template class intended to replace all the string classes of yore.
The other half are more recent additions:

<limits> defines a template class, and numerous explicit specializations, aimed at providing the information that <float.h> and <limits.h> have long supplied, only in a more object-oriented, and extensible, way.
<locale> defines a class locale, and a whole host of "facet" template classes, designed to support locales in a much more object-oriented way than the C library ever intended.
<valarray> defines a template class valarray, and a handful of auxiliary classes, designed as a hook for compilers that want to implement numerical array operations optimized for hardware that supports vector operations.
That's the lot. I should also point out that the draft C++ Standard retains, and extends, the C notion of a freestanding implementation. Presumably intended for embedded applications, such an implementation need not supply the full library. For a freestanding implementation, C++ requires:

the C headers <cstdarg> and <cstddef> in full
<cstdlib>, declaring at least the functions abort, atexit, and exit
the C++ headers <exception>, <limits>, <new>, and <typeinfo>
Using The Headers
As I'm sure you know, you include the contents of a standard header by naming it in an include directive, as in:

#include <iostream>  /* include I/O facilities */
You may not know many of the more subtle rules associated with using library headers, however. Here is a brief summary of those rules.

You can include the standard headers in any order, a standard header more than once, or two or more standard headers that define the same macro or the same type. Do not include a standard header within a declaration. Do not define macros that have the same names as keywords before you include a standard header. These are all rules inherited from Standard C, for using the standard headers.

A Standard C header never includes another standard header. But unlike in C, a C++ library header includes any other C++ library headers it needs to define needed types. This is because of the mythical One Definition Rule in C++, which outlaws the use of parallel definitions or synonyms in many places that are permissible in C. I suggest that you always include explicitly any C++ library headers needed in a translation unit, however, lest you guess wrong about its actual dependencies. A standard header declares or defines only the entities described for it in the draft C++ Standard.

Every function in the library is declared in a standard header. As I mentioned earlier, unlike in Standard C, the standard header never provides a masking macro, with the same name as the function, that masks the function declaration and achieves the same effect. A good implementation will use function inlining to achieve much the same benefit as most masking macros.

An implementation has certain latitude in how it declares types and functions in the C++ library:

Names of functions in the Standard C library may have either extern "C++" or extern "C" linkage. You have to include the appropriate Standard C header rather than declare a library entity inline, to be sure to get the proper declaration for a given implementation.
A member function name in a library class may have additional function signatures over those required by the Standard. So you cannot reliably take the address of a library member function. (The type may not be what you expect.)
A library class may have undocumented (non-virtual) base classes. A class documented as derived from another class may, in fact, be derived from that class through other undocumented classes.
A type defined as a synonym for some integer type may be the same as one of several different integer types.
A library function that has no exception specification can throw an arbitrary exception, unless its definition clearly restricts such a possibility.
On the other hand, there are some restrictions you can count on:

A library function name outside a class will not have additional, undocumented, function signatures. You can reliably take its address.
Base classes and member functions described as virtual are assuredly virtual, while those described as non-virtual are assuredly non-virtual.
Two types defined by the C++ library are always different unless the Standard explicitly suggests otherwise.
Functions supplied by the library, including the default versions of replaceable functions (such as operator new(size_t)), can throw at most those exceptions listed in any exception specification. (Functions in the Standard C library may propagate an exception, as when qsort calls a comparison function that throws an exception, but they do not otherwise throw exceptions.)
Namespaces
Another overarching consideration in using the draft Standard C++ library is the use of namespaces. Namespaces were added to the language four years ago. A principal justification for their addition was the perceived need to partition the standard library so that it can be selectively replaced by user, or third party, code. The Committees have since adopted, and later rejected, several schemes for achieving this end. The current use of namespaces in the standard library fails to do so, however, at least to my knowledge. I find it ironic that the proponents of namespaces have still failed to articulate how they should be used for one of their principal purposes.

Namespaces can also be justified as a way to improve code hygiene. The basic idea is to cut down on the clutter of names in the global name space, particularly by entities defined in the standard library. This idea is simple enough, and apparently an unmitigated Good Thing. The problem lies in its implementation, more specifically in the politics of how C and C++ are supported in the commercial world. But first, let's look at the good intentions behind the current specification.

The current draft requires that all names other than operator delete and operator new in the standard library headers be defined in the std namespace, or in a namespace nested within the std namespace. You refer to the name cin for example, as std::cin. Alternatively, you can write the declaration:

using namespace std;
after all the include directives, to promote all library names into the current namespace. Note once again that macro names are not subject to the rules for nesting namespaces.

Unless specifically indicated otherwise, you as a user of the library may not define names in the std namespace, or in a namespace nested within the std namespace. It is reserved to library implementors.

So you basically have two choices of coding style:

Prefix all library names with std::. The global namespace is then pretty much yours to command.
Write the declaration shown above and mostly forget about the presence of the std namespace.
That's fine for the C++ headers, but not so easy a discipline to impose on the older C headers. Here the rules are messier. For example:

If you include the header <stdio.h>, names such as FILE are defined in the std namespace, then "hoisted" into the global namespace with an explicit declaration like using std::FILE (written somewhere in the global namespace).
If you include the header<cstdio>, on the other hand, names such as FILE are defined only in the std namespace. No hoisting occurs.
To carry out these rules, an implementor has to alter the Standard C library headers themselves. And here is where the politics comes in. Many vendors of C and C++ compilers have different divisions maintaining the two products. There are also third-party vendors, like me, who sell C++ libraries as add-ons to existing C libraries. In both cases, the C++ library implementor can't necessarily dictate the form of the Standard C library headers. Aside from the politics, I also question the wisdom, or usefulness, of trying to stuff the Standard C library inside a namespace after all these years.

So despite what the draft C++ Standard says, a widespread practice is to define in the global namespace all names in the Standard C headers, period. Unless and until the Committees resolve this dispute, you can't reliably write std::FILE as a recipe for naming this ancient data structure. The only safe approach is to write the blanket using directive to hoist all names. o

P.J. Plauger is Senior Editor of C/C++ Users Journal and President of Dinkumware, Ltd. He is the author of the Standard C++ Library shipped with Microsoft's Visual C++, v5.0. For eight years, he served as convener of the ISO C standards committee, WG14. He remains active on the C++ committee, WG21. His latest books are The Draft Standard C++ Library, Programming on Purpose (three volumes), and Standard C (with Jim Brodie), all published by Prentice-Hall. You can reach him at pjp@plauger.com.















Columns in The C/C++ Users Journal by P.J. Plauger
Declaring Functions [Dec 1987/Jan 1988]
What's in a Name?
Data Object Types [Mar/Apr 1988]
Touching Memory
Expression Classes [Jun/Jun 1988]
Value Preserving Rules
Grouping [Sep/Oct 1988]
Typing Expressions

Locales [Dec 1988/Jan 1989]
Large Character Sets
Phases of Translation [Mar/Apr 1989]
Defining and Expanding Macros
Conditional Translation [Jun/Jul 1989]
Evolution of the C I/O Model
Streams [Sep/Oct 1989]
Formatted Output

Formatted Input [Dec 1989/Jan 1990]
Quiet Changes, Part I
Quiet Changes, Part II
Wha Gang Agley
Wha Gang Agley, Part 2
A Matter of Interpretation
Interpreting the Nasties
Library Ground Rules
With Gun and Reel
Character Classification Functions
Implementing <ctype.h>
The Header <errno.h>

The Header <float.h> [Jan 1991]
The Header <limits.h>
The Header <locale.h>
Implementing <locale.h>
Build Your Own Locales
Formatting Monetary Values
Math Functions
Math Primitives
A Math Sampler
The Header <setjmp.h>
The Header <stdarg.h>
The Header <stddef.h>

Implementing <stdio.h> [Jan 1992]
Primitives for <stdio.h>
The Header <signal.h>
The Header <stdlib.h>
Text to Numeric Conversions
Storage Allocation Functions
Multibyte Functions
C and the Environment
Bugs
The Header <string.h>
Comparing Strings
Searching Strings

The Header <time.h> [Jan 1993]
Time Conversion Functions
Time Formatting Functions
Formal Changes to C
Large Character Set Support
Large Character Set Functions
Wide Character Streams
Numerical C Extensions Group
Floating-Point C Extensions
Developing the Standard C++ Library
C++ Library Ground Rules
The C Library in C++

Technical Corrigendum 1 [Jan 1994]
The Header <exception>
C++ Language Support Library
Introduction to Iostreams
The Header <ios>
The Header <streambuf>
The Header <istream>
Extractors
The Header <ostream>
Inserters
Implementing <ostream>
The Header <iomanip>

The Header <strstream> [Jan 1995]
Implementing <strstream>
The Header <sstream>
The Header <fstream>
Implementing <fstream>
The Header <iostream>
The Header <string>
Implementing <string>
The Header <bitset>
The Header <complex>
Implementing <complex>
The Standard Template Library

STL Headers -- An Overview [Jan 1996]
Iterators
The Header <utility>
The Header <iterator>, Part 1
The Header <iterator>, Part 2
Allocators
The Header <memory>
Algorithms
Introduction to <algorithm>
Ordering Algorithms
Last of the Algorithms
Containers

The Header <vector> [Jan 1997]
The Header <list>
The Header <deque>
Associative Containers
Implementing Associative Containers
Container Adapters
Library Update
The Header <valarray>
The Header <limits>
Introduction to Locales
The Facet ctype
The Facet codecvt

The Facets num_put and numpunct [Jan 1998]
The Facet num_get
The Facet moneypunct
The Facet money_put
The Facet money_get
The Facet time_put
The Facet time_get
The Facet collate
Last of the Facets
Exception Safety in STL
Hash Tables
Thread Safety

Revising Standard C [Jan 1999]
Embedded C++ Update
Simple Iostreams
Unicode Files
Multibyte Files
A Better Deque
A Better Red-Black Tree
A Better List
Why 2K?
A Better Sort
Frequently Answered Questions
Frequently Answered Questions: STL

Java Standard Time [Jan 2000]
A Singly Linked List
Testing Conformance
Testing C++ Library Conformance
exit(0)
