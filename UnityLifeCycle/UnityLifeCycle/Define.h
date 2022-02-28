#pragma once

template <typename T>
inline void SafeRelease(T& _Obj)
{
	if (_Obj)
	{
		delete _Obj;
		_Obj = nullptr;
	}
}