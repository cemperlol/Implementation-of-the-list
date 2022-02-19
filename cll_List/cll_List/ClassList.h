namespace Lst
{	
	template <typename T>
	class cll_List
	{
	public:
		cll_List();
		~cll_List();

		void push_back(T data);
		void pop_back();
		int get_size();
		void push_front(T data);
		void pop_front();
		void insert(T data, const int unsigned& index);
		void clear();
		void print();
		void erase(const unsigned int& index);
		void random_fill(const unsigned int& quantity);
		void change_data(const unsigned int& index1, const unsigned int& index2, const bool& unused);
		void change_data(const T data, const unsigned int& index);
		void reverse();
		void sort(bool ReverseMode = false);
		void remove(const T data);
		void unique();
		void assign(const unsigned int& quantity, const T data);

		T& operator[](const int index);

	private:
		template <typename T>
		class Node
		{
		public:
			Node(T data = T(), Node* pNext = nullptr, Node* pPrev = nullptr)
			{
				this->data = data;
				this->pNext = pNext;
				this->pPrev = pPrev;
			}

			T data;
			Node* pNext;
			Node* pPrev;

			Node& operator =(const Node& NodeToCopy)
			{
				this->data = NodeToCopy.data;
				this->pNext = NodeToCopy.pNext;
				this->pPrev = NodeToCopy.pPrev;

				return *this;
			}

		private:

		};

		unsigned int Size;
		Node<T>* Head;
		Node<T>* Tail;

		Node<T>* search_needed_node(const unsigned int index);
		void exchange_chosen_nodes(int& FirstData, int& SecondData);

	};

	template<typename T>
	cll_List<T>::cll_List()
	{
		Size = 0;
		Tail = Head = nullptr;
	}

	template<typename T>
	cll_List<T>::~cll_List()
	{
		clear();
	}

	template<typename T>
	void cll_List<T>::push_back(T data)
	{
		if (Tail == nullptr)
		{
			Head = Tail = new Node<T>(data);
		}
		else
		{
			Tail = Tail->pNext = new Node<T>(data, nullptr, Tail);
		}

		Size++;
	}

	template<typename T>
	void cll_List<T>::pop_back()
	{
		if (Tail == nullptr || Tail->pPrev == nullptr)
		{
		}
		else
		{
			if (Tail->pPrev != nullptr)
			{
				Tail = Tail->pPrev;
				delete Tail->pNext;
				Tail->pNext = nullptr;
			}
			else
			{
				delete Tail;
				Head = Tail = nullptr;
			}

			Size--;
		}
	}

	template<typename T>
	int cll_List<T>::get_size()
	{
		return this->Size;
	}

	template<typename T>
	void cll_List<T>::push_front(T data)
	{
		if (Head == nullptr)
		{
			Head = Tail = new Node<T>(data);
		}
		else
		{
			Head = Head->pPrev = new Node<T>(data, Head);
		}

		Size++;
	}

	template<typename T>
	void cll_List<T>::pop_front()
	{
		if (Head == nullptr)
		{
		}
		else
		{
			if (Head->pNext != nullptr)
			{
				Head = Head->pNext;
				delete Head->pPrev;
				Head->pPrev = nullptr;
			}
			else
			{
				delete Head;
				Tail = Head = nullptr;
			}

			Size--;
		}
	}

	template<typename T>
	void cll_List<T>::clear()
	{
		if (Head != nullptr)
		{
			while (Head->pNext != nullptr)
			{
				Head = Head->pNext;
				delete Head->pPrev;
			}
			delete Head;
			Head = Tail = nullptr;
		}

		Size = 0;
	}

	template<typename T>
	void cll_List<T>::print()
	{
		if (Size == 0)
		{
			std::cout << "List's empty!" << std::endl;
		}
		else
		{
			Node<T>* Temp = Head;
			for (int i = 0; i < Size; i++)
			{
				std::cout << "#" << i << '\t' << Temp->data << std::endl;
				Temp = Temp->pNext;
			}
		}

	}

	template<typename T>
	void cll_List<T>::erase(const unsigned int& index)
	{
		Node<T>* Current;

		if (index == 0)
		{
			pop_front();
		}
		else if (index == Size - 1)
		{
			pop_back();
		}
		else
		{
			Current = search_needed_node(index);

			Current->pPrev->pNext = Current->pNext;
			Current->pNext->pPrev = Current->pPrev;
			delete Current;

			Size--;
		}
	}

	template<typename T>
	void cll_List<T>::random_fill(const unsigned int& quantity)
	{
		for (int i = 0; i < quantity; i++)
		{
			push_back((T)rand()%10);
		}
	}

	template<typename T>
	void cll_List<T>::change_data(const unsigned int& index1, const unsigned int& index2, const bool& unused)
	{
		Node<T>* FirstNode, * SecondNode;
		int TempData;
		FirstNode = search_needed_node(index1);
		SecondNode = search_needed_node(index2);

		TempData = FirstNode->data;
		FirstNode->data = SecondNode->data;
		SecondNode->data = TempData;
	}

	template<typename T>
	void cll_List<T>::change_data(const T data, const unsigned int& index)
	{
		Node<T>* FirstNode = search_needed_node(index);
		FirstNode->data = data;
	}

	template<typename T>
	void cll_List<T>::reverse()
	{
		Node<T>* FirstNode, * SecondNode;
		FirstNode = Head;
		SecondNode = Tail;
		exchange_chosen_nodes(FirstNode->data, SecondNode->data);

		for (int i = 1; i < (int)this->Size / 2; i++)
		{
			FirstNode = FirstNode->pNext;
			SecondNode = SecondNode->pPrev;

			exchange_chosen_nodes(FirstNode->data, SecondNode->data);
		}
	}

	template<typename T>
	void cll_List<T>::sort(bool ReverseMode)
	{
		bool Unsorted;
		T Temp = 0;
		Node<T>* FirstNode;


		do
		{
			Unsorted = false;
			FirstNode = Head;

			while (FirstNode->pNext != nullptr)
			{
				if (FirstNode->data > FirstNode->pNext->data)
				{
					Temp = FirstNode->data;
					FirstNode->data = FirstNode->pNext->data;
					FirstNode->pNext->data = Temp;

					Unsorted = true;
				}

				FirstNode = FirstNode->pNext;
			}
		} while (Unsorted);

		if (ReverseMode)
		{
			reverse();
		}
	}

	template<typename T>
	void cll_List<T>::remove(const T data)
	{
		Node<T>* Current = Head, * TempNode;

		do
		{
			if (Current->data == data)
			{
				if (Current->pNext != nullptr) { Current->pNext->pPrev = Current->pPrev; }
				Current->pPrev->pNext = Current->pNext;
				TempNode = Current->pNext;
				delete Current;
				
				Current = TempNode;
				Size--;
			}
			else
			{
				Current = Current->pNext;
			}
			
		} while (Current != nullptr);
	}

	template<typename T>
	void cll_List<T>::unique()
	{
		Node<T>* Current = Head, * TempNode;
		int count = 0;

		do
		{
			if (Current->data == Current->pNext->data)
			{
				count++;

				if (count > 0)
				{
					Current->pNext->pPrev = Current->pPrev; 
					Current->pPrev->pNext = Current->pNext;
					TempNode = Current->pPrev;
					delete Current;

					Current = TempNode;
					Size--;
				}
			}
			else
			{
				count = 0;
			}
			
			Current = Current->pNext;
		} while (Current->pNext != nullptr);
	}

	template<typename T>
	void cll_List<T>::assign(const unsigned int& quantity, const T data)
	{
		clear();
		Size = 0;

		for (int i = 0; i < quantity; i++)
		{
			push_back(data);
		}
	}

	template<typename T>
	void cll_List<T>::insert(T data, const int unsigned& index)
	{
		Node<T>* Current;

		if (index == 0)
		{
			push_front(data);
		}
		else
		{
			Current = search_needed_node(index);

			Node<T>* InsertedNode = new Node<T>(data, Current, Current->pPrev);
			Current->pPrev = Current->pPrev->pNext = InsertedNode;

			Size++;
		}
	}

	template<typename T>
	T& cll_List<T>::operator[](const int index)
	{
		int count;
		Node<T>* Current;

		if (index < Size / 2)
		{
			Current = Head;
			count = 0;

			while (count < index)
			{
				Current = Current->pNext;
				count++;
			}
		}
		else
		{
			Current = Tail;
			count = Size - 1;

			while (count > index)
			{
				Current = Current->pPrev;
				count--;
			}
		}

		return Current->data;
	}

	template<typename T>
	cll_List<T>::Node<T>* cll_List<T>::search_needed_node(const unsigned int index)
	{
		{
			Node<T>* NeededNode;

			if (index < Size / 2)
			{
				NeededNode = Head;

				for (int i = 0; i < index; i++)
				{
					NeededNode = NeededNode->pNext;
				}
			}
			else
			{
				NeededNode = Tail;

				for (int i = Size - 1; i > index; i--)
				{
					NeededNode = NeededNode->pPrev;
				}
			}

			return NeededNode;
		}
	}

	template<typename T>
	void cll_List<T>::exchange_chosen_nodes(int& FirstData, int& SecondData)
	{
		int TempData = FirstData;
		FirstData = SecondData;
		SecondData = TempData;
	}
}