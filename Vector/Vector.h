#pragma once

template <typename T>
class Vector
{
public:
	Vector();
	Vector(size_t size);
	Vector(size_t size, T fill);
	Vector(T* ptr, size_t size);

	void push_back(T elem);
	void pop_back();
	void resize(size_t size);
	void reserve(size_t size);
	void clear();

	size_t size();
	size_t capacity();
	T* data();
	bool empty();
	T& front();
	T& back();

	T& operator[](size_t ind);
	~Vector();
private:
	void alloc_more();
	void check_alloc();
	size_t _size;
	size_t _capacity;
	T* _data;
};

#define ALLOC_MUL 1.5

template <typename T>
Vector<T>::Vector() : _data(nullptr), _size(0), _capacity(0)
{
}

template <typename T>
Vector<T>::Vector(size_t size) : _size(size), _capacity(size), _data(new T[size])
{
}
template<typename T>
inline Vector<T>::Vector(size_t size, T fill) : _size(size), _capacity(size), _data(new T[size])
{
	for (size_t i = 0; i < size; i++)
		_data[i] = fill;
}

template <typename T>
Vector<T>::Vector(T* ptr, size_t size) : _size(size), _capacity(size), _data(new T[size])
{
	for (size_t i = 0; i < size; i++)
		_data[i] = ptr[i];
}

template <typename T>
void Vector<T>::push_back(T elem)
{
	check_alloc();
	_data[_size] = elem;
	_size++;
}

template <typename T>
void Vector<T>::pop_back()
{
	_size--;
	check_alloc();
}

template <typename T>
void Vector<T>::resize(size_t size)
{
	_size = size;
	check_alloc();
}

template <typename T>
void Vector<T>::reserve(size_t size)
{
	if (size < _capacity)
		return;

	_capacity = size;
	T* buf = _data;
	_data = new T[size];
	for (size_t i = 0; i < _size; i++)
		_data[i] = buf[i];
}

template <typename T>
void Vector<T>::clear()
{
	delete _data;
	_size = _capacity = 0;
}

template<typename T>
size_t Vector<T>::size()
{
	return _size;
}

template<typename T>
inline size_t Vector<T>::capacity()
{
	return _capacity;
}

template <typename T>
T* Vector<T>::data()
{
	return _data;
}

template <typename T>
bool Vector<T>::empty()
{
	return _size == 0;
}

template <typename T>
T& Vector<T>::front()
{
	return _data[_size - 1];
}

template <typename T>
T& Vector<T>::back()
{
	return _data[0];
}

template <typename T>
T& Vector<T>::operator[](size_t ind)
{
	if (ind >= _size)
		throw std::exception();
	return _data[ind];
}


template <typename T>
void Vector<T>::alloc_more()
{
	if (int(_size * ALLOC_MUL) == _size)
		_capacity = _size + 1;
	else
		_capacity = _size * ALLOC_MUL;
	reserve(_capacity);
}

template <typename T>
void Vector<T>::check_alloc()
{
	if (_size >= _capacity)
		alloc_more();
}

template<typename T>
inline Vector<T>::~Vector()
{
	delete _data;
}

#undef ALLOC_MUL


