
#include "stdafx.h"

#include <pos/cpputil.h>

namespace pos {

	namespace debug {

#if __POS__DEBUG > 0
		auto_var_usage_list g_auto_vars;
#endif

	} // namespace debug

	namespace util {

#if __POS__DEBUG > 0
		// ...
#endif

	} // namespace util
}
