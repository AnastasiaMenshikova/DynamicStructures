class Stack
{
	struct node
	{
		int value;
		node *next;
	};

	node *top;

public:
	Stack();
	~Stack();

	void push(int);
	int pop();
	bool Search(int key);
	void Del();
	void RandPush(int amount, int range);
	void Clear();
	typedef node* iterater;
	iterater getTop();
	iterater getNext(iterater a);
	int getInf(iterater a);
	bool IsEmpty();
};
