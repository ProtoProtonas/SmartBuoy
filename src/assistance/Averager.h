

#ifndef AVERAGER_H
#define AVERAGER_H

template <class T>
class Averager
{
    public:

        // constructor
        Averager(short size);

        // public methods
        void updateWithNewValue(T newValue);
        T getAverage();

    private:
        T* _sampleArray;
        short _currentWriteIndex = 0;
        short _arraySize;
};

template <class T>
Averager<T>::Averager(short size)
{
    _sampleArray = new T[size];
    _arraySize = size;
}

template <class T>
void Averager<T>::updateWithNewValue(T newValue)
{
    if(_currentWriteIndex < _arraySize)
    {
        _sampleArray[_currentWriteIndex] = newValue;
    }

    // update write index
    _currentWriteIndex++;
    if(_currentWriteIndex >= _arraySize)
    {
        _currentWriteIndex = 0;
    }
}

template <class T>
T Averager<T>::getAverage()
{
    T average = 0;
    T sum = 0;

    for(uint8_t i = 0; i < _arraySize; i++)
    {
        sum += _sampleArray[i];
    }
    average = sum / _arraySize;

    return average;
}

#endif
