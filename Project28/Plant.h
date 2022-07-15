//Plant.h

#ifndef PLANT_H
#define PLANT_H
#include<iostream>
#include<vector>
//单体
class Target
{
public:
	//自定义的new
	static void* operator new(std::size_t);
	//自动义的delete
	void operator delete(void* pTarget);
	static void deletes(void* pVoid);

	virtual ~Target() = 0 {};
};

class Plant
{

private:
	std::vector<Target*> m_pTargets;//申明向量的Target
	//申明Plant的智能指针友元类
	friend class std::auto_ptr<Plant>;
	static std::auto_ptr<Plant> s_plant;
public:
	//获取Plant对象
	static Plant* Instance();
	//增加对象的指针
	void AddTarget(Target* pTarget)
	{
		//添加对象
		m_pTargets.push_back(pTarget);
	};
	//移除对象指针
	void EraseTarget(Target* pTarget);
	//清除所有对象
	void Clear();
	Plant()
	{
		std::cout << "Plant" << std::endl;
	}
	virtual ~Plant();
};
class Person :public Target
{
public:

	//构造函数
	Person()
	{
		std::cout << "Person" << std::endl;
	}
	//析构函数
	~Person()
	{
		std::cout << "~Person()" << std::endl;
	}
};

#endif