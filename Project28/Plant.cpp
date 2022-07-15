//Plant.cpp

#include <memory>
#include "Plant.h"

//获取Plant对象
std::auto_ptr<Plant> Plant::s_plant;
Plant* Plant::Instance()
{
	if (s_plant.get() == 0)
	{
		s_plant.reset(new Plant);
	}
	return s_plant.get();
}
Plant::~Plant()
{
	Clear();//清除对象
	std::cout << "~Plant()" << std::endl;
}
//清除所有对象
void Plant::Clear()
{
	//遍历对象
	for (unsigned long i = 0; i < m_pTargets.size(); ++i)
	{
		if (m_pTargets[i])
		{
			//释放空间
			::delete m_pTargets[i];
			Target::deletes(m_pTargets[i]);
		}
	}
	//释放向量空间
	m_pTargets.~vector();
}
void Plant::EraseTarget(Target* pTarget)
{
	//遍历容器，找到相应对象删除
	std::vector<Target*>::iterator iter = m_pTargets.begin();
	for (iter = m_pTargets.begin(); iter != m_pTargets.end(); ++iter)
	{
		if (*iter == pTarget)
		{
			iter = m_pTargets.erase(iter);
			return;
		}
	}
}
void* Target::operator new(std::size_t st)
{
	//创建对象
	Person* pPerson = (Person*)::operator new(st);
	Plant* pf = Plant::Instance();
	//添加对象入向量
	pf->AddTarget(pPerson);
	std::cout << "内存空间已添加" << std::endl;
	return pPerson;
}

void Target::deletes(void* pTarget)
{
	//创建对象
	Plant* pPlant = Plant::Instance();
	//删除对象
	pPlant->EraseTarget((Target*)pTarget);
	std::cout << "内存空间已释放！" << std::endl;
}

void Target::operator delete(void* pTarget)
{
	;//空函数体，主要实现析构
}