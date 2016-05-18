#pragma once

template <typename T>
class CStringIterator : std::iterator<std::random_access_iterator_tag, T>
{
public:
	CStringIterator() = default;
	explicit CStringIterator(T * ptr, bool isReverse = false);

	bool operator==(CStringIterator const& other) const;
	bool operator!=(CStringIterator const& other) const;

	typename CStringIterator::reference operator*() const;
	typename CStringIterator::pointer operator->() const;

	CStringIterator & operator++();
	CStringIterator & operator--();

	CStringIterator operator++(int);
	CStringIterator operator--(int);

	CStringIterator & operator+=(ptrdiff_t digit);
	CStringIterator & operator-=(ptrdiff_t digit);

	typename CStringIterator::reference operator[](size_t pos) const;

private:
	T * m_ptr;
	ptrdiff_t m_sign;
};

template <typename T>
CStringIterator<T>::CStringIterator(T * ptr, bool isReverse = false)
	: m_sign(isReverse ? -1 : 1)
{
	assert(ptr);
	m_ptr = ptr;
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
	m_ptr += m_sign;
	return *this;
}

template <typename T>
CStringIterator<T> & CStringIterator<T>::operator--()
{
	m_ptr += -m_sign;
	return *this;
}

template <typename T>
CStringIterator<T> CStringIterator<T>::operator--(int)
{
	auto tmp = *this;
	--(*this);
	return tmp;
}

template <typename T>
CStringIterator<T> CStringIterator<T>::operator++(int)
{
	auto tmp = *this;
	++(*this);
	return tmp;
}

template <typename T>
CStringIterator<T> & CStringIterator<T>::operator+=(ptrdiff_t digit)
{
	m_ptr += m_sign * digit;
	return *this;
}

template <typename T>
CStringIterator<T> & CStringIterator<T>::operator-=(ptrdiff_t digit)
{
	m_ptr += -m_sign * digit;
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
CStringIterator<T> operator+(ptrdiff_t pos, CStringIterator<T> it)
{
	return it += pos;
}


template <typename T>
CStringIterator<T> operator+(CStringIterator<T> it, ptrdiff_t pos)
{
	return it += pos;
}
