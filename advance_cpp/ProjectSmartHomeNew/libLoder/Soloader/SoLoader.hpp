/**
 * @file SoLoader.hpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2019-02-05
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#ifdef __SOLOADER_H__
#include <dlfcn.h>

 
template<class T>
T SoLoader<T>::GetCTor(const std::string& _path,const std::string& _funcName)
{
    void* handle = dlopen(_path.c_str(), RTLD_LAZY);
    return  (T)dlsym(handle, _funcName.c_str());
}

#endif //__SOLOADER_H__