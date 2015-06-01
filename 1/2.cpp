#include <iostream>
#include <memory>
#include <stdexcept>
#include <utility>
#include <random>
#include <ctime>

class MaxPriorityQueue
{
public:
	MaxPriorityQueue(int num)
	:capacity(num),size(0)
	{
		storage = alloc.allocate(num);
	}
	~MaxPriorityQueue()
	{
		for(int i = size -1;i >= 0;i--)
			alloc.destroy(storage + i);
		alloc.deallocate(storage,capacity);
	}
	MaxPriorityQueue(const MaxPriorityQueue& rhs) = delete;
	MaxPriorityQueue& operator=(MaxPriorityQueue& rhs) = delete;


	//插入元素
	void Insert(const int);
	//返回最大元素引用
	int& Maximum();
	//返回堆顶并删除堆顶元素
	int ExtractMax();
	//增加优先级
	void IncreaseKey(int index,int newValue);
private:
	//堆调整
	void adjust(int index);

	//内存分配子
	std::allocator<int> alloc; 
	//初始指定的最大数组元素个数
	int capacity;
	//当前已经保存的对象数目
	int size;
	//指向原始存储区的指针
	int* storage;
};

int& MaxPriorityQueue::Maximum()
{
	return storage[0];
}

//参数为待调整的索引,从零开始
void MaxPriorityQueue::adjust(int index)
{
	if(index >= size)
		throw std::out_of_range("堆调整根索引超出有效范围");
	else
	{
		int rootval = storage[index];
		//左儿子索引
		int child = 2*index + 1;
		//开始比较
		while(child <= size)
		{
			//找到更大的儿子
			if(child + 1 < size && storage[child] < storage[child+1])
				child++;
			//与根节点比较
			if(storage[child] < rootval)
				break;
			else
			{
				storage[index] = storage[child];
				index = child;
				child = 2*index + 1;
			}
			storage[index] = rootval;
		}
	}
}

void MaxPriorityQueue::Insert(const int value)
{
	if(size >= capacity)
		throw std::out_of_range("堆空间满，插入失败");
	else
	{
		size++;
		int index = size - 1;
		//构造对象
		alloc.construct(storage+index,value);
		//向上调整
		while(index >= 0 && storage[index] > storage[index/2])
		{
			int tmp = storage[index/2];
			storage[index/2] = storage[index];
			storage[index] = tmp;
			index /= 2;
		}
	}
}

void MaxPriorityQueue::IncreaseKey(int index,int newValue)
{
	if(index >= size)
		throw std::out_of_range("索引超出有效范围");
	else if(newValue <= storage[index])
		return;
	else
	{
		storage[index] = newValue;
		while(index >= 0 && storage[index] > storage[index/2])
		{
			int tmp = storage[index/2];
			storage[index/2] = storage[index];
			storage[index] = tmp;
			index /= 2;
		}
	}
}

int MaxPriorityQueue::ExtractMax()
{
	if(size < 1)
		throw std::out_of_range("堆为空");
	int res = storage[0];
	//堆底元素放到堆顶
	storage[0] = storage[size-1];
	//删除堆底元素
	alloc.destroy(storage + size - 1);
	//调整堆
	adjust(0);
	//返回
	return res;
}

int main(int argc,char** argv)
{
	int length = std::stoi(argv[1]);
	MaxPriorityQueue queue(length);
	for(int i = 0;i < length;i++)
	{
		std::default_random_engine engine(time(0));
		std::uniform_int_distribution<unsigned> u(1,length);
		queue.Insert(u(engine));
	}
	std::cout << queue.ExtractMax() << std::endl;
 	queue.IncreaseKey(30,999999);
 	std::cout << queue.ExtractMax() << std::endl;
	return 0;
}