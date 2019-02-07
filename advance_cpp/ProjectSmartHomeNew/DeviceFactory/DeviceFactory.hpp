/**
 * @file DeviceFactory.hpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2019-02-07
 * 
 * @copyright Copyright (c) 2019
 * 
 
template<class T,class U>
class DeviceFactory
{
public:
    DeviceFactory();
    DeviceFactory(const std::stirng& _path);
    void SetPath(const std::stirng& _path);
    U GetDevice(const std::stirng& _funcName);
    ~DeviceFactory();

private:
    IDynamicLoader<T>* m_Loader;
    std::string     m_Path;
};

 */

template<class T,class U>
DeviceFactory<T,U>::DeviceFactory()
:m_Loader(nullptr)
{
}

template<class T,class U>
DeviceFactory<T,U>::DeviceFactory(const std::string& _path)
:m_Path(_path)
{
}
