#ifndef SYS_MACOS_INCLUDE_KYTY_SYSSTDIO_H_
#define SYS_MACOS_INCLUDE_KYTY_SYSSTDIO_H_

// IWYU pragma: private

#if defined(__APPLE__)

//#include <stdio.h>
#include <cstdarg>

namespace Kyty {

inline uint32_t sys_vscprintf(const char* format, va_list argptr)
{
	va_list argcopy;
	va_copy(argcopy, argptr);
	int len = vsnprintf(nullptr, 0, format, argcopy);
	va_end(argcopy);
	return len < 0 ? 0 : len;
}

inline uint32_t sys_vsnprintf(char* dest, size_t count, const char* format, va_list args)
{
	int len = vsnprintf(dest, count + 1, format, args);
	return len < 0 ? 0 : len;
}

} // namespace Kyty

#endif

#endif /* SYS_MACOS_INCLUDE_KYTY_SYSSTDIO_H_ */
