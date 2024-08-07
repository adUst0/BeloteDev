#pragma once
#include <vector>
#include "Utils.h"

template <typename Data>
class Subject;

template <typename Data>
class Observer
{
	friend Subject<Data>;
public:
	virtual ~Observer();
	virtual void notify(const Data& data) = 0;

private:
	std::vector<Subject<Data>*> m_subjects;
};


template <typename Data>
class Subject
{
	friend Observer<Data>;
public:
	virtual ~Subject();

	void registerObserver(Observer<Data>& observer);
	void unregisterObserver(Observer<Data>& observer);
	void notifyObservers(const Data& data);

private:
	std::vector<Observer<Data>*> m_observers;
};

template <typename Data>
Observer<Data>::~Observer<Data>()
{
	for (Subject<Data>* subject : m_subjects)
	{
		std::erase(subject->m_observers, this);
	}
}

template <typename Data>
void Subject<Data>::registerObserver(Observer<Data>& observer)
{
	Utils::emplaceBackUnique(m_observers, &observer);
	Utils::emplaceBackUnique(observer.m_subjects, this);
}

template <typename Data>
void Subject<Data>::unregisterObserver(Observer<Data>& observer)
{
	std::erase(m_observers, &observer);
}

template <typename Data>
void Subject<Data>::notifyObservers(const Data& data)
{
	for (Observer<Data>* observer : m_observers)
	{
		observer->notify(data);
	}
}

template <typename Data>
Subject<Data>::~Subject<Data>()
{
	for (Observer<Data>* observer : m_observers)
	{
		std::erase(observer->m_subjects, this);
	}
}