#ifndef PRIORITY_INCLUDE_H
#define PRIORITY_INCLUDE_H

#include <map>
#include <list>

using namespace std;

template <class K, class V>
class PriorityCache
{
	public:
		PriorityCache(int top);
		PriorityCache(int top, bool (*func)(K, K));
		virtual ~PriorityCache();

		void add(const K& key, const V& val);
		void erase(const K& key);
		bool containsKey(const K& key) const;

		typedef typename map<K, V>::iterator iterator;

		iterator begin();
		iterator end();
		void erase(iterator position);
		void clear();

		typedef typename map<K,V>::size_type size_type;

		size_type size() const;

		iterator operator[](const K& key);
		iterator get(const K& key);

	protected:
	private:
		void erasePriority(const K& key);
		typename list<K>::iterator findPriority(const K& key);

	private:
		map<K, V> _elements;
		list<K> _priority;
		int _top;
		bool (*_keyComparator)(K, K);

	private:
		/*
		class CacheElement {
			CacheElement(K k) {
				_k = k;
			};

			K element() const {
				return _k;
			};

			K _k;
		};
		*/
};

	template <class K, class V>
PriorityCache<K, V>::PriorityCache(int top)
{
	_top = top;
	_keyComparator = NULL;
}

	template <class K, class V>
PriorityCache<K, V>::PriorityCache(int top, bool (*keyComparator)(K, K))
{
	_top = top;
	_keyComparator = keyComparator;
}

	template <class K, class V>
PriorityCache<K, V>::~PriorityCache()
{
}

template <class K, class V>
typename PriorityCache<K, V>::iterator PriorityCache<K,V>::begin() {
	return _elements.begin();
}

template <class K, class V>
typename PriorityCache<K, V>::iterator PriorityCache<K,V>::end() {
	return _elements.end();
}

template <class K, class V>
void PriorityCache<K,V>::erase(iterator position) {
	_elements.erase(position);
	erasePriority(position->first);
}

template <class K, class V>
void PriorityCache<K,V>::clear() {
	_priority.clear();
	_elements.clear();
}

template <class K, class V>
typename PriorityCache<K, V>::size_type PriorityCache<K, V>::size() const {
	return _elements.size();
}

	template <class K, class V>
void PriorityCache<K, V>::erase(const K& key)
{
	// look at http://www.parashift.com/c++-faq-lite/templates.html#faq-35.18 (Whoa new for me)
	typename map<K,V>::iterator i = _elements.find(key);
	if (i != _elements.end()) {
		_elements.erase(i);
	}

	erasePriority(key);
}

template <class K, class V>
typename list<K>::iterator PriorityCache<K, V>::findPriority(const K& key) {
	typename list<K>::iterator itPriority = _priority.begin();
	for (; itPriority != _priority.end(); itPriority++) {
		K k = *itPriority;

		bool found = false;

		if (_keyComparator) {
			found = _keyComparator(key, k);
		} else {
			found = key == k;
		}

		if (found) {
			break;
		}
	}
	return itPriority;
}

template <class K, class V>
void PriorityCache<K, V>::erasePriority(const K& key) {
	if (_keyComparator == NULL) {
		_priority.remove(key);
	} else {
		typename std::list<K>::iterator itPriority = findPriority(key);
		if (itPriority != _priority.end()) {
			_priority.erase(itPriority);
		}
	}
}

template <class K, class V>
void PriorityCache<K, V>::add(const K& key, const V& val) {
	if (_priority.size() == _top) {
		K keyPriority = _priority.back();
		erase(keyPriority);
	}
	erase(key);
	typename map<K,V>::const_iterator i = _elements.find(key);
	if (i != _elements.end()) {
		_elements.erase(key);
	}
	_elements.insert(pair<K, V> (key, val));

	_priority.push_front(key);
}

template <class K, class V>
typename PriorityCache<K, V>::iterator PriorityCache<K,V>::get(const K& key) {
	typename map<K,V>::iterator i = _elements.find(key);
	// Priorize the element
	if (i != _elements.end()) {
		erasePriority(key);
		_priority.push_front(key);
	}
	return i;
}

template <class K, class V>
typename PriorityCache<K, V>::iterator PriorityCache<K,V>::operator [](const K& key) {
	return get(key);
}

template <class K, class V>
bool PriorityCache<K, V>::containsKey(const K& key) const {
	typename map<K,V>::const_iterator i = _elements.find(key);
	if (i != _elements.end()) {
		return true;
	} else {
		return false;
	}
}
#endif // PRIORITY_INCLUDE_H
