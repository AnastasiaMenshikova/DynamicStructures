class deque
{
	struct node
	{
		int value;
		node *next;
		node *prev;
	};

	node *head;	//указатель на начало очереди
	node *tail;	//указатель на конец очереди
	void Del();
	node* find(node *head, int value);
public:
	deque();
	~deque();

	void pushLast(int);
	void pushFirst(int);
	int popFirst();
	int popLast();
	bool Search(int key);
	void RandPush(int amount, int range);
	void Clear();
	typedef node* iterater;
	iterater getHead();
	iterater getTail();
	iterater getNext(iterater a);
	int getInf(iterater a);
	bool IsEmpty();
	void insert_after(node *head, int key, int value);
	void insert_before(node *head, int key, int value); // вставка до ключа
	void sort();

};
