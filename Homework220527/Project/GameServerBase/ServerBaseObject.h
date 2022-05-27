#pragma once

// �뵵 : 
// �з� :
// ÷�� :
// ���� �����ӿ�ũ���� ����� ��� Ŭ������ �θ� ������Ʈ
// ��� ������Ʈ���� ����� ����� ����
class ServerBaseObject : public std::enable_shared_from_this<ServerBaseObject>
{
private: // member var
	ServerBaseObject*								m_parent;		// �θ� ������Ʈ
	std::vector<std::shared_ptr<ServerBaseObject>>	m_linkObject;	// ������Ʈ�� ����� �ٸ� ������Ʈ

public: // default
	ServerBaseObject();
	virtual ~ServerBaseObject(); // �����Լ� ���̺��� ���

	ServerBaseObject(const ServerBaseObject& _other) = delete;
	ServerBaseObject(ServerBaseObject&& _other) noexcept;

protected:
	ServerBaseObject& operator=(const ServerBaseObject& _other) = delete;
	ServerBaseObject& operator=(const ServerBaseObject&& _other) = delete;

private:

public: // member Func
	bool IsLowLevelValid();
	void ClearLinkObject();

	template<typename ConvertType>
	std::shared_ptr<ConvertType> DynamicCast()
	{
		return std::dynamic_pointer_cast<ConvertType>(shared_from_this());
	}

	///////////
	// Parent 
	///////////

	void SetParent(ServerBaseObject* _parent);

	// Ÿ���� �߸��Ǿ��ų� �θ�ü�� ���°�� nullptr
	template<typename ParentType>
	ParentType* GetParent() const
	{
		return dynamic_cast<ParentType*>(m_parent);
	}


	///////////
	// SetLink
	///////////

	template<typename EnumData>
	void SetLink(EnumData _Index, std::shared_ptr<ServerBaseObject> _Ptr)
	{
		SetLink(static_cast<size_t>(_Index), _Ptr);
	}

	void SetLink(size_t _index, std::shared_ptr<ServerBaseObject> _ptr);


	///////////
	// Link Get
	///////////

	template<typename DataType>
	std::shared_ptr<DataType> GetLink(size_t _Index)
	{
		if (m_linkObject.size() <= _Index)
		{
			return nullptr;
		}

		return std::dynamic_pointer_cast<DataType>(m_linkObject[_Index]);
	}

	template<typename DataType, typename EnumType>
	std::shared_ptr<DataType> GetLink(EnumType _Index)
	{
		return GetLink<DataType>(static_cast<size_t>(_Index));
	}


	const std::vector<std::shared_ptr<ServerBaseObject>>& GetAllLink() const;

};

