#pragma once
#include <thread>
#include <typeinfo>

#include "ServerNameBase.h"
#include "ServerDebug.h"
#include "ServerTime.h"

// �뵵 :
// �з� :
// ÷�� :
class ServerThread : public ServerNameBase
{
private:
	// thread������ ����� �޸𸮿���
	static thread_local std::string THREAD_NAME;
	static thread_local unsigned int THREAD_OREDER;
	static thread_local const std::type_info* LOCAL_DATA_TYPE;
	static thread_local void* LOCAL_DATA;

protected:
	static thread_local ServerTime Timer;

private: // member var
	std::thread m_thread;

public: // default
	ServerThread();

	template <class _Fn, class... _Args, std::enable_if_t<!std::is_same_v<std::_Remove_cvref_t<_Fn>, std::thread>, int> = 0>
	explicit ServerThread(std::string _name, _Fn&& _Fx, _Args&&... _Ax)
	{
		m_thread = std::thread(_Fx, _Ax...);
	}

	template <class _Fn, class... _Args, std::enable_if_t<!std::is_same_v<std::_Remove_cvref_t<_Fn>, std::thread>, int> = 0>
	explicit ServerThread(_Fn&& _Fx, _Args&&... _Ax)
		: ServerNameBase("default thread")
	{
		m_thread = std::thread(_Fx, _Ax...);
	}

	~ServerThread();

	ServerThread(const ServerThread& _other) = delete;
	ServerThread(const ServerThread&& _other) noexcept;
	

protected:
	ServerThread& operator=(const ServerThread& _other) = delete;
	ServerThread& operator=(const ServerThread&& _other) = delete;

private:

public: // static
	static void SetThreadName(const std::string& _Name);
	static std::string GetName();

public: // inline
	inline std::thread::id ThreadId()
	{
		return m_thread.get_id();
	}

	inline void SetThreadOrder(unsigned int _Order)
	{
		THREAD_OREDER = _Order;
	}


public: // member Func
	void Join();

	template <class _Fn, class... _Args, std::enable_if_t<!std::is_same_v<std::_Remove_cvref_t<_Fn>, std::thread>, int> = 0>
	void Start(_Fn&& _Fx, _Args&&... _Ax)
	{
		m_thread = std::thread(_Fx, _Ax...);
	}

public:
	template<typename LocalDataType>
	static LocalDataType* CreateThreadLocalData()
	{
		// �̹� ��������ִ��� üũ
		if (nullptr != LOCAL_DATA_TYPE)
		{
			ServerDebug::AssertDebugMsg("Local Data Is Not Null");
			return nullptr;
		}

		// RTTI�� ���� Ÿ��üũ
		LOCAL_DATA_TYPE = &typeid(LocalDataType);
		LOCAL_DATA = new LocalDataType;

		return reinterpret_cast<LocalDataType*>(LOCAL_DATA);
	}

	template<typename LocalDataType>
	static LocalDataType* GetLocalData()
	{
		if (LOCAL_DATA_TYPE != &typeid(LocalDataType))
		{
			ServerDebug::AssertDebugMsg("Local Data Type Is Not Equal");
			return nullptr;
		}

		return reinterpret_cast<LocalDataType*>(LOCAL_DATA);
	}

	template<typename LocalDataType>
	static void DeleteThreadLocalData()
	{

		delete reinterpret_cast<LocalDataType*>(LOCAL_DATA);
	}
};

