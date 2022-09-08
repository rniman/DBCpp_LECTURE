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

//bool타입은 1바이트만 있으면 8개의 배열을 만들수 있음
//비트마스크 이용 
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