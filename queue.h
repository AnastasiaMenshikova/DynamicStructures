class queue
{
	struct node
	{
		int value;
		node *next;
	};

	node *pbeg;
	node *pend;

public:
	queue();
	~queue();

	void push(int);
	int pop();
	bool Search(int key);
	void Del();
	void RandPush(int amount, int range);
	void Clear();
	typedef node* iterater;
	iterater getBegin();
	iterater getNext(iterater a);
	int getInf(iterater a);
	bool IsEmpty();
};
