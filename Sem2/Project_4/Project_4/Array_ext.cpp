// Изменения и дополнения к классу Array для реализации механизма move

//Изменение деструктора
//Деструктор
Array::~Array() {
	if (values != nullptr){
	  delete[] values;
	  cout << "Array deleted!" << endl;
	}
}

//move- конструктор
Array::Array(Array&& other){
	n = other.n;
	values = other.values;
	other.values = nullptr;	// Не позволит сразу деструктору удалить массив, перемещенный в другой объект
}

//move- оператор присваивания

Array& Array::operator= ( Array&& arr) {
	//if (this != &arr) { - здесь не бывает самоприсваивания
	if (values != nullptr)	
		delete[] values;
	n = arr.n;
	values = arr.values;
	arr.values = nullptr;	// Не позволит сразу деструктору удалить массив, перемещенный в другой объект
	return *this;
}