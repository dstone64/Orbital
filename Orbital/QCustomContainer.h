#pragma once

#include <initializer_list>
#include <QVector>
#include <QMap>

template<typename T, typename U>
class QCustomContainer
{
public:
	typedef struct { T x; U y; } QCustomContainer_t;
	QCustomContainer(std::initializer_list<QCustomContainer_t> init) : QCustomContainer(init.begin(), init.end()) {}
	template<class It>
	QCustomContainer(It first, It last) {
		for (auto it = first; it != last; ++it) {
			T t = ((QCustomContainer_t)(*it)).x;
			U u = ((QCustomContainer_t)(*it)).y;
			this->k.push_back(t);
			this->v.push_back(u);
			this->m[t] = u;
		}
	}
	const U& operator[](const T& t) { return this->m[t]; }
	const QVector<T>& keys() const { return this->k; }
	const QVector<U>& values() const { return this->v; }
	int indexOfKey(const T& t) const { return this->k.indexOf(t); }
	int indexOfValue(const U& u) const { return this->v.indexOf(u); }
	const U value(const T& t) const { return this->m.value(t); }

private:
	QVector<T> k;
	QVector<U> v;
	QMap<T, U> m;
};