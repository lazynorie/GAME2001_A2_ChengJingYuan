#pragma once

#include <iostream>
#include "PriorityQueue.h"
using namespace std;

template<class T>
class less_cmp // Less than compare with nonpointer types
{
public:
	inline bool operator()(T lVal, T rVal)
	{
		return (lVal < rVal);
	}
};

template<class T>
class less_cmp_pointer // Less than compare with pointer types
{
public:
	inline bool operator()(T lVal, T rVal)
	{
		return ((*lVal) < (*rVal));
	}
};

template<class T>
class greater_cmp // Less than compare with nonpointer types
{
public:
	inline bool operator()(T lVal, T rVal)
	{
		return !(lVal < rVal);
	}
};

template<class T>
class greater_cmp_pointer // Less than compare with pointer types
{
public:
	inline bool operator()(T lVal, T rVal)
	{
		return !((*lVal) < (*rVal));
	}
};

class NetworkMessage
{
public:
	NetworkMessage() : m_priority(0), m_id(0) {}
	NetworkMessage(int p, int id) : m_priority(p), m_id(id) {}
	~NetworkMessage() {}

	int GetPriority()
	{
		return m_priority;
	}
	int GetID()
	{
		return m_id;
	}
	// Overload operators
	bool operator<(NetworkMessage& m)
	{
		// Check again the priority level of both network messages
		if (m_priority < m.GetPriority())
		{
			return true;
		}
		else if (m_priority > m.GetPriority())
		{
			return false;
		}
		/*else if (m_id < m.GetID())
		{
			return true;
		}*/

		return false;
	}
	bool operator>(NetworkMessage& m)
	{
		return !(*this < m);
	}
private:
	int m_priority;
	int m_id;
};

int main()
{
	cout << "Lower number has higher priority!" << endl;
	cout << "Priority queue data structure example!" << endl << endl;

	const int SIZE = 15;
	PriorityQueue<NetworkMessage, less_cmp<NetworkMessage> > que(SIZE);

	que.push(NetworkMessage(3, 100));
	que.push(NetworkMessage(2, 286));
	que.push(NetworkMessage(1, 362));
	que.push(NetworkMessage(3, 435));
	que.push(NetworkMessage(1, 99));
	que.push(NetworkMessage(2, 394));
	que.push(NetworkMessage(4, 999));
	que.push(NetworkMessage(22, 99));
	que.push(NetworkMessage(8, 78));

	



	// Display the priority queue
	cout << "Priority queue content (Size - " << que.GetSize() << ") : " << endl;

	while (que.isEmpty() == false)
	{
		cout << "   Priority: " << que.front().GetPriority();
		cout << "   ID: " << que.front().GetID();
		cout << endl;

		que.pop();
	}

	cout << endl;

	if (que.isEmpty() == true)
	{
		cout << "The container is empty" << endl;
	}
	else
	{
		cout << "The container is NOT empty" << endl;
	}

	return 0;
}