#pragma once

template <class T>
class Storage
{
private:
	T m_array[8];

public:
	void set(int index, const T& value)
	{
		m_array[index] = value;
	}

	const T& get(int index)
	{
		return m_array[index];
	}

};

//boolŸ���� 1����Ʈ�� ������ 8���� �迭�� ����� ����
//��Ʈ����ũ �̿� 
template <>
class Storage<bool>
{
private:
	unsigned char m_data;

public:
	Storage() 
		:m_data(0)
	{}

	void set(int index, bool value)
	{
		unsigned char mask = 1 << index;

		if (value)
			m_data |= mask;
		else
			m_data &= ~mask;
	}

	bool get(int index)
	{
		unsigned char mask = 1 << index;
		return (m_data & mask) != 0;
	}


};