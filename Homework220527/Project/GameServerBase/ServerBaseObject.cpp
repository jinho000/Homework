#include "pch.h"
#include "ServerBaseObject.h"
#include "ServerDebug.h"

ServerBaseObject::ServerBaseObject()
	: m_parent(nullptr)
{
	m_linkObject.resize(16);
}

ServerBaseObject::~ServerBaseObject()
{
}

ServerBaseObject::ServerBaseObject(ServerBaseObject&& _other) noexcept
	: m_parent(_other.m_parent)
{
}

bool ServerBaseObject::IsLowLevelValid()
{
	if (nullptr != this)
	{
		return true;
	}

	return false;
}

void ServerBaseObject::SetParent(ServerBaseObject* _parent)
{
	// �ڱ� �ڽ��� �θ�� ���� �� ����
	if (this == _parent)
	{
		return;
	}

	// �ѹ��� ó��
	m_parent = _parent;
}


void ServerBaseObject::SetLink(size_t _index, std::shared_ptr<ServerBaseObject> _ptr)
{
	// �������� �ε����� ����ũ�⺸�� ū��� ���� ������ ����
	if (_index >= m_linkObject.size())
	{
		m_linkObject.resize(_index + 1);
	}

	if (_index >= 128)
	{
		ServerDebug::AssertDebugMsg("is Big Index Index Not Over 128.");
		return;
	}

	// �ڸ��� �̹� �ִ°�� 
	if (nullptr != m_linkObject[_index])
	{
		ServerDebug::AssertDebugMsg("is OverLap Link Data");
		return;
	}

	// �ڱ� �ڽ��� link�� ���� �� ����
	if (this == _ptr.get())
	{
		return;
	}

	m_linkObject[_index] = _ptr;
}

const std::vector<std::shared_ptr<ServerBaseObject>>& ServerBaseObject::GetAllLink() const
{
	return m_linkObject;
}

void ServerBaseObject::ClearLinkObject()
{
	m_linkObject.clear();
}
