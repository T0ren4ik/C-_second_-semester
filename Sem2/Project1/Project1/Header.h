#pragma once
#include <iostream>
#include <stdexcept>

using namespace std;

template<typename type>
class List {
private:
	// ��������� �������� ������
	struct node;
	typedef node* node_ptr;
	struct node {
		type data;
		node_ptr next;
		node_ptr prev;
		node(type data, node_ptr prev, node_ptr next) {
			this->data = data;
			this->next = next;
			this->prev = prev;
		}
		node() :data(0), next(0), prev(0) {}
		friend ostream& operator<<(ostream& out, const node& X) {
			out << X.data;
			return out;
		}
	};
	// ��������� �� ������ � ����� ������
	node_ptr head;
	node_ptr tail;

	void removeDuplicates(node_ptr head)
	{
		node_ptr current = head;
		node_ptr next_next;

		if (current == nullptr)
			return;

		while (current->next != nullptr)
		{
			if (current->data == current->next->data)
			{
				next_next = current->next->next;
				free(current->next);
				current->next = next_next;
			}
			else 
			{
				current = current->next;
			}
		}
	}
public:
	class listIterator;
	// �����������
	List() {
		head = 0; tail = 0;
	}
	// ����������� �����
	List(const List& l) {
		head = 0; tail = 0;
		node_ptr q = l.head;
		while (q) {
			inTail(q->data);
			q = q->next;
		}
	}
	// ����������
	~List() {
		while (head) {
			node_ptr cur = head;
			head = head->next;
			delete cur;
		}
		tail = head = nullptr;
	}

	// �������� �� �������
	bool isEmpty() const {
		return (head == nullptr);
	}
	// ���������� � ������ ������
	void inHead(type val) {
		node_ptr t = new node(val, nullptr, head);
		if (!head)
			tail = t;
		else
			head->prev = t;
		head = t;
	}
	// ���������� � ����� ������
	void inTail(type val) {
		node* t = new node(val, tail, nullptr);
		if (head) {
			tail->next = t;
			tail = t;
		}
		else {
			head = tail = t;
		}
	}
	// ������ ������
	int size()
	{
		int size = 0;
		node_ptr cur = head;
		while (cur) {
			size++;
			cur = cur->next;
		}
		return size;
	}
	// �������� ������� ��., ���� ������ ���� ������
	void delFirst() {
		if (head) {
			node* t = head;
			head = head->next;
			head->prev = nullptr;
			delete t;
		}
		else
			throw exception("��������� ���� ������� ��� ������! (������� �������� ��������������� ��������)");
	}
	// �������� ���������� ��., ���� ������ ���� ������
	void delLast() {
		if (head) {
			if (head == tail) { delete tail; tail = head = nullptr; }
			else {
				node* t = tail->prev;
				delete tail;
				tail = t;
				t->next = nullptr;
			}
		}
		else
			throw exception("��������� ���� ������� ��� ������! (������� �������� ��������������� ��������)");
	}
	
	// ���� � ����� �� ������
	friend ostream& operator<<(ostream& os, const List& l) {
		node* p = l.head;
		while (p) { os << *p << " "; p = p->next; }
		os << endl;
		return os;
	}
	friend istream& operator>>(istream& os, List& l) {
		cout << "������� �������� ����� ������: ";
		type n;
		while (cin.peek() != '\n') {
			cin >> n;
			l.inTail(n);
		}
		return os;
	}

	// ������� ����� � ����� ����������
	void insert_prev(listIterator i, type el) {
		if (i.collection != this) throw logic_error("��������� ���� ������� ��� ������! (������� ������� � ������ ���������)");
		// ���� ������� � ����� � ������ ������
		if (i.empty())
		{
			inTail(el);
			return;
		}
		else if (i == begin())
		{
			inHead(el);
			return;
		}

		// ������� � ������������ �����
		node_ptr temp = new node(el, i.cur->prev, i.cur);

		i.cur->prev->next = temp;
		i.cur->prev = temp;	
	}
	void insert_next(listIterator i, type el) {
		if (i.collection != this) throw logic_error("��������� ���� ������� ��� ������! (������� ������� � ������ ���������)");
		// ���� ������� � ����� � ������ ������
		if (i.empty())
		{
			throw out_of_range("����� �� ������� ������!");
		}
		else if (i == begin())
		{
			node_ptr temp = new node(el, i.cur, i.cur->next);
			i.cur->next->prev = temp;
			i.cur->next = temp;
			return;
		}

		// ������� � ������������ �����
		node_ptr temp = new node(el, i.cur, i.cur->next);

		i.cur->next->prev = temp;
		i.cur->next = temp;
	}

	// �������� ?????(i = begin())
	void del(listIterator& i)
	{
		if (i.collection != this) throw logic_error("��������� ���� ������� ��� ������! (������� ������� � ������ ���������)");
		if (i.empty())
		{
			delLast();
			i = begin();
			return;
		}
		else if (i == begin())
		{
			delFirst();
			i = begin();
			return;
		}

		node_ptr temp = i.cur;
		i.cur->prev->next = i.cur->next;
		delete temp;
		i = begin();
	}

	void Sort()
	{
		node_ptr temp = head;
		while (temp->next)
		{
			if (temp->data > temp->next->data)
			{
				swap(temp->data, temp->next->data);
				temp = temp->next;
				Sort();
			}
			else
				temp = temp->next;
		}
	}
	void delDubl() {
		removeDuplicates(head);
	}

	//����� �������� � ���������� ������
	listIterator find(type DataItem) {
		node_ptr cur = head;
		while (cur) { //���� �� ����� ������
			if (DataItem == cur->data) return listIterator(this, cur);
			else cur = cur->next;
		}
		return listIterator(this, nullptr);
	}

	// ��������� �� ������ � �����
	listIterator begin() const { return listIterator(this, head); }
	listIterator end() const {
		listIterator iter(this, nullptr);
		return iter;
	}

	// ����� ���������
	class listIterator {
		friend class List;
	protected:
		// ��������� � ������
		const List* collection;
		node_ptr cur;
	public:
		// �����������
		listIterator(const List* s, node_ptr e) :collection(s), cur(e) {}
		// �������� �������������
		const int operator *() { 
			if (!cur) throw exception("��������� ���� ������� ��� ������! (������� ������������� nullptr)");;
			return cur->data; }
		//���������� ++
		listIterator operator++() {
			if (cur) {
				cur = cur->next;
				return *this;
			}
			else throw out_of_range("����� �� ������� ������!");
		}
		//���������� --
		listIterator operator--() {
			if (cur) {
				cur = cur->prev;
				return *this;
			}
			else if (collection->head != collection->tail) {
				cur = collection->tail;
				return *this;
			}
			else throw out_of_range("����� �� ������� ������!");
		}
		//����������� ++
		listIterator operator++(int) {
			if (cur) {
				listIterator temp = *this;
				cur = cur->next;
				return temp;
			}
			else throw out_of_range("����� �� ������� ������!");
		}
		//����������� --
		listIterator operator--(int) {
			if (cur) {
				listIterator temp = *this;
				cur = cur->prev;
				return temp;
			}
			else if (collection->head != collection->tail) {
				listIterator temp = *this;
				cur = collection->tail;
				return temp;
			}
			else throw out_of_range("����� �� ������� ������!");
		}
		// �������� �� �������
		bool empty() { return *this == (*collection).end(); }
		// ��������� ���������
		int operator == (const listIterator& ri) const { return ((collection == ri.collection) && (cur == ri.cur)); }
		int operator != (const listIterator& ri) const { return !(*this == ri); }
		bool operator < (const listIterator& ri) const { 
			if (ri.collection != this->collection) throw logic_error("��������� ���� ������� ��� ������!");
			return (this->cur->data < ri.cur->data);
		}
		bool operator <= (const listIterator& ri) const {
			if (ri.collection != this->collection) throw logic_error("��������� ���� ������� ��� ������!");
			return (this->cur->data <= ri.cur->data);
		}
	};
};

