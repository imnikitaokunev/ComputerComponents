#include "OutputIterator.h"

template< class T>
OutputIterator<T>& OutputIterator<T>::operator=(T& value)
{
	*stream << value;
	if (delim != nullptr)
		* stream << delim;

	return *this;
}

template<class T>
OutputIterator<T>& OutputIterator<T>::operator*()
{
	return *this;
}

template<class T>
OutputIterator<T>& OutputIterator<T>::operator++()
{
	return *this;
}
