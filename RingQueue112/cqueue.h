#pragma once
#include <iostream>

using namespace std;

class c_queue112 {
	char* arr = nullptr;
	int size = 0;
public:
	c_queue112() = default;

	c_queue112(const c_queue112& qq) {
		if (qq.arr == nullptr)
			return;
		this->size = qq.size;
		this->arr = new char[this->size];
		for (size_t i = 0; i < this->size; i++)
		{
			this->arr[i] = qq.arr[i];
		}
	}

	c_queue112& operator=(const c_queue112& qq) {
		if (this == &qq)
			return *this;
		this->~c_queue112();
		if (qq.arr == nullptr)
			return *this;
		this->size = qq.size;
		this->arr = new char[this->size];
		for (size_t i = 0; i < this->size; i++)
		{
			this->arr[i] = qq.arr[i];
		}
	}

	c_queue112(c_queue112&& cq) {
		swap(this->arr, cq.arr);
		swap(this->size, cq.size);
	}

	c_queue112& operator=(c_queue112&& cq) {
		swap(this->arr, cq.arr);
		swap(this->size, cq.size);
		return *this;
	}

	void push(char ch) {
		this->size++;
		char* n_arr = new char[this->size];
		for (size_t i = 0; i < this->size - 1; i++)
		{
			n_arr[i + 1] = this->arr[i];
		}
		n_arr[0] = ch;
		if (this->arr != nullptr)
			delete[] this->arr;
		this->arr = n_arr;
	}

	void print() const {
		for (size_t i = 0; i < this->size; i++)
		{
			cout << this->arr[i] << "\t";
		}
		cout << endl;
	}

	void pop(bool to_end = true) {
		if (this->arr == nullptr)
			return;
		if (to_end == true) {
			char tmp = this->arr[this->size - 1];
			for (size_t i = this->size - 1; i > 0; i--)
			{
				swap(this->arr[i], this->arr[i - 1]);
			}
			return;
		}

		else if (to_end == false) {
			if (this->size == 1) {
				this->~c_queue112();
			}
			char* n_arr = new char[this->size - 1];
			for (size_t i = 0; i < this->size - 1; i++)
			{
				n_arr[i] = this->arr[i];
			}
			delete[] this->arr;
			this->size--;
			this->arr = n_arr;
		}
	}

	char back() const {
		return this->arr[0];
	}

	char& back() {
		return this->arr[0];
	}

	char front() const {
		return this->arr[this->size - 1];
	}

	char& front() {
		return this->arr[this->size - 1];
	}

	bool empty() const {
		return this->size == 0;
	}

	int get_size() const {
		return this->size;
	}

	~c_queue112() {
		if (this->arr != nullptr) {
			delete[] this->arr;
			this->arr = nullptr;
			this->size = 0;
		}
	}

};
