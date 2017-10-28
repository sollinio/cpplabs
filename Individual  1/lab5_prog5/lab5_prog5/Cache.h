#pragma once

#include <vector>
#include <map>
#include <iterator>
#include <string>

template <class Type>
class Cache
{
	std::vector<Type> vType;

public:

	void put(Type inner)
	{
		vType.push_back(inner);
	}

	bool contains(Type elem)
	{
		for (auto i = vType.begin(); i != vType.end(); i++) // std::vector<Type>::iterator
			if (elem == *i)
				return true;
		return false;
	}

	void operator+=(Type elem)
	{
		vType.push_back(elem);
	}

	Cache() { }
	~Cache() { }
};


template <>
class Cache <std::string>
{
	std::vector<std::string> vString;

public:

	void put(std::string inner)
	{
		vString.push_back(inner);
	}

	bool contains(std::string elem)
	{
		for (auto i = vString.begin(); i != vString.end(); i++) // std::vector<std::string>::iterator
			if (elem.substr(0, 1) == (i)->substr(0,1))
				return true;
		return false;
	}

	void add()
	{
		if (vString.size() > 100)
			throw;
	}

	void operator+=(std::string elem)
	{
		vString.push_back(elem);
	}

	Cache() { }
	~Cache() { }
};


