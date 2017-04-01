#pragma once

#include <queue>

namespace LFRobot
{
	template <class T>
	class AveragingQueue
	{
	public:

		AveragingQueue()
		{
			capacity = 0;
		}

		AveragingQueue(size_t inCapacity)
		{
			capacity = inCapacity;
		}

		push(T element)
		{
			sum += element;
			q.push(element);

			if (capacity > 0 && q.size() > capacity)
			{
				sum -= q.front();
				q.pop();
			}
		}

		T pop()
		{
			T temp = q.front();
			q.pop();
			return temp;
		}

		T getAverage()
		{
			if (q.empty())
			{
				return DEFAULT_VALUE;
			}

			return sum / q.size();
		}

		size_t getSize()
		{
			return q.size();
		}

		bool isFull()
		{
			return capacity > 0 && q.size() == capacity;
		}

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