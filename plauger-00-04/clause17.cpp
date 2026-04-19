#include "defs.h"

/* _17421T22 may be included more than once (except <assert.h>) */
#if !defined(SKIP_17421T22)&&(!defined(ONLY)|| \
   defined(CASE_17421T22))
#include <cstddef>
#include <cstddef>
#include <iostream>
#include <iostream>

#undef NDEBUG
#include <cassert>
static int fun1_17421T22() {assert(1); return (1); }

#define NDEBUG
#include <cassert>
static int fun2_17421T22() {assert(0); return (1); }

#undef NDEBUG
#include <cassert>
static int fun3_17421T22() {assert(1); return (1); }
#endif /* CASE_17421T22 */

int main(int, char *[])
{
enter_chk("t17421t22.cpp");

/* _17421T22 may be included more than once (except <assert.h>) */
#if !defined(SKIP_17421T22)&&(!defined(ONLY)|| \
   defined(CASE_17421T22))
        begin_chk("_17421T22");
        {
        ieq(fun1_17421T22(), 1);
        ieq(fun2_17421T22(), 1);
        ieq(fun3_17421T22(), 1);
        }
        end_chk("_17421T22");
#else
        skip_chk("_17421T22");
#endif /* CASE_17421T22 */

return leave_chk("t17421t22");
}
