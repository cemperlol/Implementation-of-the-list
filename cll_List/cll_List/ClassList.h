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
		int GetSize();
		void push_front(T data);
		void pop_front();
		void insert(T data, int index);
		void clear();
		void show_all();
		void remove_at(const int index);
		void random_fill(const unsigned int quantity);
		void change_data(const int index1, const int index2, bool unused);
		void change_data(const int data, const int index);

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
				this->data = NodeToCopy->data;
				this->pNext = NodeToCopy->pNext;
				this->pPrev = NodeToCopy->pPrev;

				return *this;
			}

		private:

		};

		unsigned int Size;
		Node<T>* Head;
		Node<T>* Tale;

		Node<T>* search_needed_node(const int index);

	};

	template<typename T>
	cll_List<T>::cll_List()
	{
		Size = 0;
		Tale = Head = nullptr;
	}

	template<typename T>
	cll_List<T>::~cll_List()
	{
		clear();
	}

	template<typename T>
	void cll_List<T>::push_back(T data)
	{
		if (Tale == nullptr)
		{
			Head = Tale = new Node<T>(data);
		}
		else
		{
			Tale = Tale->pNext = new Node<T>(data, nullptr, Tale);
		}

		Size++;
	}

	template<typename T>
	void cll_List<T>::pop_back()
	{
		if (Tale == nullptr || Tale->pPrev == nullptr)
		{
		}
		else
		{
			if (Tale->pPrev != nullptr)
			{
				Tale = Tale->pPrev;
				delete Tale->pNext;
				Tale->pNext = nullptr;
			}
			else
			{
				delete Tale;
				Head = Tale = nullptr;
			}

			Size--;
		}
	}

	template<typename T>
	int cll_List<T>::GetSize()
	{
		return this->Size;
	}

	template<typename T>
	void cll_List<T>::push_front(T data)
	{
		if (Head == nullptr)
		{
			Head = Tale = new Node<T>(data);
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
				Tale = Head = nullptr;
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
			Head = nullptr;
		}

		Size = 0;
	}

	template<typename T>
	void cll_List<T>::show_all()
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
	void cll_List<T>::remove_at(int index)
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
	void cll_List<T>::random_fill(const unsigned int quantity)
	{
		for (int i = 0; i < quantity; i++)
		{
			push_back((T)rand());
		}
	}

	template<typename T>
	void cll_List<T>::change_data(const int index1, const int index2, bool unused)
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
	void cll_List<T>::change_data(const int data, const int index)
	{
		Node<T>* FirstNode = search_needed_node(index);
		FirstNode->data = data;
	}

	template<typename T>
	void cll_List<T>::insert(T data, int index)
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
			Current = Tale;
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
	cll_List<T>::Node<T>* cll_List<T>::search_needed_node(const int index)
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
				NeededNode = Tale;

				for (int i = Size - 1; i > index; i--)
				{
					NeededNode = NeededNode->pPrev;
				}
			}

			return NeededNode;
		}
	}
}