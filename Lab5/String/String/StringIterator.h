#pragma once
template <typename T>
class CStringIterator : std::iterator<std::random_access_iterator_tag, T>
{
public:
	CStringIterator() = default;
	CStringIterator(T * ptr, bool isReverse = false);
	CStringIterator(CStringIterator const& other);

	bool operator==(CStringIterator const& other) const;
	bool operator!=(CStringIterator const& other) const;

	typename CStringIterator::reference operator*() const;
	typename CStringIterator::pointer operator->() const;

	CStringIterator & operator++();
	CStringIterator & operator--();

	CStringIterator & operator+=(size_t digit);
	CStringIterator & operator-=(size_t digit);

	typename CStringIterator::reference operator[](size_t pos) const;

	~CStringIterator() = default;


private:
	T * m_ptr;
	bool m_isReverse;
};

template <typename T>
CStringIterator<T>::CStringIterator(T * ptr, bool isReverse = false)
{
	assert(ptr);
	m_ptr = ptr;
	m_isReverse = isReverse;
}

template <typename T>
CStringIterator<T>::CStringIterator(CStringIterator const& other)
	:m_ptr(other.m_ptr)
	, m_isReverse(other.m_isReverse)
{

}

template <typename T>
bool CStringIterator<T>::operator==(CStringIterator const& other) const
{
	return m_ptr == other.m_ptr;
}

template <typename T>
bool CStringIterator<T>::operator!=(CStringIterator const& other) const
{
	return m_ptr != other.m_ptr;
}

template <typename T>
typename CStringIterator<T>::reference CStringIterator<T>::operator*() const
{
	return *m_ptr;
}

template <typename T>
typename CStringIterator<T>::pointer CStringIterator<T>::operator->() const
{
	return m_ptr;
}

template <typename T>
CStringIterator<T> & CStringIterator<T>::operator++()
{
	m_isReverse ? m_ptr-- : m_ptr++;
	return *this;
}

template <typename T>
CStringIterator<T> & CStringIterator<T>::operator--()
{
	m_isReverse ? m_ptr++ : m_ptr--;
	return *this;
}

template <typename T>
CStringIterator<T> & CStringIterator<T>::operator+=(size_t digit)
{
	if (m_isReverse)
	{
		m_ptr -= digit;
	}
	else
	{
		m_ptr += digit;
	}
	return *this;
}

template <typename T>
CStringIterator<T> & CStringIterator<T>::operator-=(size_t digit)
{
	if (m_isReverse)
	{
		m_ptr += digit;
	}
	else
	{
		m_ptr -= digit;
	}

	return *this;
}

template <typename T>
typename CStringIterator<T>::reference CStringIterator<T>::operator[](size_t pos) const
{
	return *(m_ptr + pos);
}

template <typename T>
ptrdiff_t const operator-(CStringIterator<T> const& it1, CStringIterator<T> const& it2)
{
	if (&*it1 < &*it2)
	{
		return 0;
	}
	return (&*it1 - &*it2);
}

template <typename T>
CStringIterator<T> operator+(size_t pos, CStringIterator<T> it)
{
	return it += pos;
}


template <typename T>
CStringIterator<T> operator+(CStringIterator<T> it, size_t pos)
{
	return it += pos;
}
