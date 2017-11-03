#include <iostream>
#include <algorithm>
#include <iterator>
using namespace std;

template
	<typename T>
class SetList
{	
public:
	struct ListNode {
		T info;
		ListNode * next;
		ListNode(T newInfo, ListNode * newNext)
			: info(newInfo), next(newNext) {}
	};
	ListNode * head;
	struct iterator {
		typedef forward_iterator_tag iterator_category;
		typedef iterator self_type;
		typedef T value_type;
		typedef T& reference;
		typedef ListNode * pointer;
		typedef ptrdiff_t difference_type;
	private:
		pointer buf;
	public:
		iterator(pointer ptr) : buf(ptr) {}
		self_type operator++ () {
			head = head->next;
			buf = head;
			return *this;
		} 
		bool operator==(const self_type & rhs) const { 
			return buf == rhs.buf; 
		}
	};
	struct const_iterator {
		typedef forward_iterator_tag iterator_category;
		typedef const_iterator self_type;
		typedef T value_type;
		typedef T& reference;
		typedef ListNode * pointer;
		typedef ptrdiff_t difference_type;
	private:
		pointer buf;
	public:
		const_iterator(pointer ptr) : buf(ptr) {}
		self_type operator++ () {
			head = head->next;
			buf = head;
			return *this;
		}
		bool operator==(const self_type & rhs) const { 
			return buf == rhs.buf; 
		}
	};
	iterator begin() {
		return iterator(head);
	}
	iterator end() {
		return iterator(nullptr);
	}
	const_iterator begin() const {
		return const_iterator(head);
	}
	const_iterator end() const {
		return const_iterator(nullptr);
	}
	void insert(T input) {
		ListNode * temp = head;

		head = new ListNode(input, temp);
	}
	iterator find(const T &x) {
		for (SetList<T>::ListNode*p = head; p; p = p->next) {
			if (p->info == x) {
				return iterator(p);
			}
		}
		return nullptr;
	}
	const_iterator find(const T &x) const {
		for (SetList<T>::ListNode*p = head; p; p = p->next) {
			if (p->info == x) {
				return const_iterator(p);
			}
		}
		return nullptr;
	}
	SetList(){
		head = new ListNode("", nullptr);
	}
	~SetList() {
	}
};


