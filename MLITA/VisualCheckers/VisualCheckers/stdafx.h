#ifndef __STDAFX_H
#define __STDAFX_H

#define _CRT_SECURE_NO_WARNINGS

#ifdef _WIN32
#include <SDKDDKVer.h>
#include <tchar.h>
#endif

#include <stdio.h>
#include <string>
#include <vector>
#include <iostream>
#include <functional>
#include <unordered_set>
#include <queue>
#include <memory>

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#ifdef _WIN32
#pragma warning (disable: 4512)
#pragma warning (disable: 4458)
#pragma warning (disable: 4459)
#endif



#ifndef _WIN32
namespace std
{
template <class T, class ...TArgs>
std::unique_ptr<T> make_unique(TArgs&&... args)
{
    return std::unique_ptr<T>(new T(std::forward<TArgs>(args)...));
}
}
#endif

#endif // __STDAFX_H
