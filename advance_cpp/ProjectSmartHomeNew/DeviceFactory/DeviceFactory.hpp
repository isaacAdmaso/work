/**
 * @file DeviceFactory.hpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2019-02-07
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#ifdef __DEVICEFACTORY_H__

template<class T,class U>
DeviceFactory<T,U>::DeviceFactory(IDynamicLoader<U>* _loader)
:m_Loader(_loader)
{
}

template<class T,class U>
DeviceFactory<T,U>::~DeviceFactory()
{
   delete m_Loader;
}
#ifdef TEST_DEVICE
template<class T,class U>
T DeviceFactory<T,U>::GetDevice(const std::string& _path,const std::string& _funcName)
{
   U func = m_Loader->GetCTor(_path, _funcName);
   //test//
   int k = 3,j = 4;

   return (T)func(&k,&j);
}
#else
template<class T,class U>
T DeviceFactory<T,U>::GetDevice(const std::string& _path,const std::string& _funcName)
{
   U func = m_Loader->GetCTor(_path, _funcName);
   return (T)func();
}
#endif

#endif //__DEVICEFACTORY_H__