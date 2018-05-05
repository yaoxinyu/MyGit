#include <mutex>

template<class T>
class singleton
{
protected:
	singleton(void){}
	virtual ~singleton(void){}	
public:
	static inline T* GetSingleton(void);
private:
	singleton(const singleton&);
	const singleton& operator=(const singleton&);
private:
	static T* _instance;
	static std::mutex	_mutex;
};


template <class T>
T* singleton<T>::_instance = NULL;

template <class T>
std::mutex	 singleton<T>::_mutex;

template<class T>
inline T* singleton<T>::GetSingleton(void)
{
	if(NULL==_instance)
	{
		std::lock_guard<std::mutex> lock(_mutex);
		if(NULL == _instance)
		{
			_instance = new T;
		}
	}
	return _instance;
}