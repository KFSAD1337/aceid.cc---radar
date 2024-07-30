#pragma once

#ifndef HELPERS_HPP
#define HELPERS_HPP

template <typename _Ty, typename ..._Ta>
auto __vtbl(void* __ptr64 ptr, int index, _Ta... arguments) {
	return ((*reinterpret_cast<_Ty(__thiscall***)(void*, _Ta...)>(ptr))[index])(ptr, arguments...);
}

using EntityId = unsigned int;

#endif // !HELPERS_HPP