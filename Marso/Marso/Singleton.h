#pragma once

template<class T>
class Singleton
{
private:
	static T* Inst;

public:
	Singleton() {

	}
	~Singleton()
	{
	}

public:
	static T* Get()
	{
		if (Inst == nullptr)
		{
			Inst = new T();
		}
		return Inst;
	}

	static void ReleaseInst()
	{
		SAFE_DELETE(Inst);
	}
};

template<class T>
T*Singleton<T>::Inst = NULL;