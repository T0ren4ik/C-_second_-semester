#include "Header.h"


//2  Функция создания списка заданной длины, элементы списка вводятся с консоли.
//Порядок следования элементов должен совпадать с порядком ввода.
list* sp_create_to_tail() {
	list* head, * p, * tail;
	int n, el;
	cout << "size list->";
	cin >> n; head = tail = nullptr;

	if (n > 0) {
		cout << "list item -> ";
		cin >> el;
		head = tail = new list(el, nullptr);
	}
	for (int i = 1; i < n; ++i) {
		cout << "list item -> ";
		cin >> el;
		p = new list(el, nullptr);
		tail->next = p;
		tail = p;
	}
	return head;
}

//3 Функция вывода списка на консоль
void erase(list*& L) {
	list* t;
	t = L;
	while (t != NULL) {
		L = t->next;
		delete t;
		t = L;
	}
}


//4 Функция удаления списка. (Можно ли без создания нового списка, поидее L адресс не должен менятся)
void print_sp(list* L) {
	if (L) {
		list* p;
		p = L;
		for (; p; p = p->next) {
			cout << p->inf << " ";
		}
		cout << "\n";
	}
	else throw "Список пуст!";
}


//5 (Количество элементов списка)
int count_element_list(list* L) {
	list* p;
	p = L;
	int count = 0;
	for (; p; p = p->next) {
		count++;
	}
	return count;
}


//6 Функция поиска элемента
list* find_el(list* L, int x) {
	if (L != nullptr) {
		while (L && L->inf != x) {
			L = L->next;
		}
		if (L) return L;
		else throw "Элемент отсутствует";
	}
	else throw "Error";
}


//7 Значение первого элемента спискa
int first_el(const list* L) {
	if (L != nullptr) {
		return L->inf;
	}
	else throw "Список пуст";
}


//8 Вставка элемента в начало списка
void add_first(list*& pn, int x) {
	pn = new list(x, pn);
}

//9 Вставка элемента в конец списка. (Зачем передовать по ссылке, ведь, мы меняем только элемент, а не адрес начала)
void add_end(list* &L, int x) {
	list* p;
	p = L;

	while (p && p->next) p = p->next;
	
	list* end_el = new list(x, nullptr);
	p->next = end_el;
}


//10 Вставка нового значения перед указанным элементом списка.
list* add_el_i_position(list* &L, list* position, int x) {
	if (L != nullptr) {
		list* p;
		p = L;

		while (p && p->next != position) p = p->next;

		if (position == nullptr || p) {
			list* new_el = new list(x, position);
			p->next = new_el;
		}
		else throw "Элемент отсуттствует";
	}
	else throw "Error";

}


//11 Удаление элемента после указанного элемента списка
void remove_after(list* &L) {
	if (L != nullptr && L->next != nullptr) {
		list* p = L->next;
		L->next = L->next->next;
		delete p;

	}
	else throw "Элемент отсуттствует";
	
}


//12 Вставить новый элемент в список за первым элементом с заданным значением. Если
//вставить невозможно, функция должна выбрасывать исключение.
void add_i_past_pos(list*& L, int pos, int x) {
	list* p;
	p = L;

	while (p && p->inf != pos) p = p->next;
	if (p) {
		list* new_el = new list(x, p->next);
		p->next = new_el;
	}
	else throw "Элемент отстутствует!";
}

//13 Удалить из списка все элементы с заданным значением.
void remove_after_el(list*& L, int el) {
	if (L) {
		list* p;
		while (L && L->next && L->inf == el) {
			p = L;
			L = L->next;
			delete p;
		}

		p = L;
		list* pr;
		if (p) {
			for (; p->next;) {
				if (p->next->inf == el) {
					pr = p->next;
					p->next = p->next->next;
					delete pr;
				}
				else p = p->next;
			}
		}

		if (p->next == nullptr && p->inf == el) {
			delTail(L);
		}
	}
	else throw "Список пуст!";
}
//Удаление хвоста для 13
void delTail(list* &L) {
	if (L) {
		if (L->next) {
			list* p = L;
			while (p->next->next) //предпоследний элемент
				p = p->next;
			delete p->next;
			p->next = nullptr;
		}
		else {
			delete L;
			L = nullptr;
		}
	}
}


//14Проверка, что лист упорядочен по возростанию
bool vozr_list(list* L) {
	while (L && L->next && L->inf < L->next->inf) {
		L = L->next;
	}
	return (L->next == nullptr);
}


//15 Проверить список на выполнение условия для элементов списка, условие задается
//функцией –параметром.
bool pred_list(list* L, bool (*f)(int)){
	while (L && f(L->inf))
		L = L->next;

	return(L == nullptr);
}
bool all_zero(int x) {
	return x == 0 ? 1 : 0;
}

//16 «Перевернуть» список, не используя операций выделения/освобождения
//динамической памяти.
list* revers_list(list* &L) {	
	int i = 0;
	list* prhead = nullptr; // Здесь в итоге окажется указатель на голову перевёрнутого списка.
	list* p;
	while (L != nullptr){
		p = L->next;
		if ((p->next) && (L->next->next))
			cout << "p = " << p->inf << " | Lni = " << L->next->inf << " | i =" << i << endl;

		L->next = prhead;
		prhead = L;
		L = p;
		i++;
	}

	return prhead;
}