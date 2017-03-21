class queue
{
	struct node
	{
		int value; 
		node *next;
	};

	node *pbeg;	//указатель на начало очереди
	node *pend;	//указатель на конец очереди

public:
	queue();
	~queue();

	void push(int);
	int pop();
	bool Search(int key);
	void RandPush(int amount, int range);
	void Clear();
	typedef node* iterater;
	iterater getBegin();
	iterator getEnd();
	iterater getNext(iterater a);
	int getInf(iterater a);
	bool IsEmpty();
};
