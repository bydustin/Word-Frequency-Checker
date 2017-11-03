#include <iostream>
#include <algorithm>
//#include <iterator>
using namespace std;

template
	<class Key, class T> 
class MapArray {
	int size = 100;
	pair <Key, T> *buf;
public:
	struct iterator {
		typedef random_access_iterator_tag iterator_category;
		typedef iterator self_type;
		typedef pair<const Key, T> value_type;
		typedef Key keyType; // key_type
		typedef T infoType; // mapped_type
		typedef value_type& reference;
		typedef value_type* pointer;
		typedef ptrdiff_t difference_type;
	private:
		pointer buf;
	public:
		iterator(pointer ptr) : buf(ptr) { }
	};
	T& operator[] (const Key& k){
		//return (*((this->insert(make_pair(k, mapped_type()))).first)).second
	}

	iterator begin() { return iterator(buf); }
	iterator end() { return iterator(buf + size); }

	MapArray() {
		pair <Key, T> * PairArray = new pair<Key, T>[size];
	}
	~MapArray() {}
};
