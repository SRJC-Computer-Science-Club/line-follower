#pragma once

#include <queue>

namespace LFRobot
{
	/*
	AveragingQueue functions as a normal queue, with two added features.

	1. It keeps track of the average of all the values in the queue, 
	so that it can be found in constant time.

	2. It has a maximum size, called capacity. When the capacity is reached,
	the oldest element is removed from the queue and from the average.

	If capcity is zero, then the queue has unlimited size.
	*/
	template <class T>
	class AveragingQueue
	{
	public:
		/*
		Initializes an empty queue with unlimited size.
		*/
		AveragingQueue()
		{
			capacity = 0;
		}

		/*
		Initializes an empty queue with a given maximum size.
		*/
		AveragingQueue(size_t inCapacity)
		{
			capacity = inCapacity;
		}

		/*
		Pushes a new element onto the queue and into the average.
		If the queue is full, the oldest element is removed.
		*/
		void push(T element)
		{
			sum += element;
			q.push(element);

			if (capacity > 0 && q.size() > capacity)
			{
				sum -= q.front();
				q.pop();
			}
		}

		/*
		Removes the oldest element from the queue and from the average.
		That element is returned.
		*/
		T pop()
		{
			T temp = q.front();
			q.pop();
			return temp;
		}

		/*
		Returns the average of all the elements in the queue.
		*/
		T getAverage()
		{
			if (q.empty())
			{
				return DEFAULT_VALUE;
			}

			return sum / q.size();
		}

		/*
		Returns the number of elements currently in the queue.
		*/
		size_t getSize()
		{
			return q.size();
		}

		/*
		True if the capacity is limited and the size is equal to it.
		*/
		bool isFull()
		{
			return capacity > 0 && q.size() == capacity;
		}

		/*
		True if there are no elements in the queue.
		*/
		bool isEmpty()
		{
			return q.empty();
		}

	private:
		const T DEFAULT_VALUE;

		std::queue<T> q;
		size_t capacity;
		T sum = DEFAULT_VALUE;
	};
}