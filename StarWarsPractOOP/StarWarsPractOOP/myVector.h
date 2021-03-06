#pragma once
#include <iostream>

template <typename T>

class myVector
{
private:
	T* data;
	int size;
	int capacity;

	void copy(const myVector<T>& other)
	{
		this->data = new T[other.capacity];
		this->size = other.size;
		this->capacity = other.capacity;

		for (int i = 0; i < this->size; i++)
		{
			this->data[i] = other.data[i];
		}
	}

	void resize()
	{
		this->capacity *= 2;

		T* newData = new T[capacity];

		for (int i = 0; i < this->size; i++)
		{
			newData[i] = this->data[i];
		}

		delete[] this->data;
		this->data = newData;
	}

	void destroy()
	{
		delete[] this->data;
		this->data = nullptr;
	}

public:

	myVector()
	{
		this->size = 0;
		this->capacity = 4;
		this->data = new T[capacity];
	}

	myVector(const myVector& other)
	{
		this->copy(other);
	}

	int length()
	{
		return this->size;
	}

	void add(const T& element)
	{
		if (this->size + 1 >= this->capacity)
		{
			this->resize();
		}

		this->data[this->size] = element;
		this->size++;
	}

	const T& operator[](const int index) const
	{
		return this->data[index];
	}

	T& operator[](const int index)
	{
		return this->data[index];
	}

	myVector& operator=(const myVector& other)
	{
		if (this != &other)
		{
			this->destroy();
			this->copy(other);
		}

		return *this;
	}

	myVector& operator+=(const myVector& other)
	{
		int otherSize = other.size;

		for (int i = 0; i < otherSize; i++)
		{
			this->add(other.data[i]);
		}

		return *this;
	}

	myVector operator+(const myVector& other)
	{
		myVector<T> result(*this);
		result += other;

		return result;
	}

	void print()
	{
		for (int i = 0; i < this->size; i++)
		{
			std::cout << this->data[i] << std::endl;
		}

		std::cout << std::endl;
	}

	~myVector()
	{
		this->destroy();
	}
};