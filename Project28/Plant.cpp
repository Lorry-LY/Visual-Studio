//Plant.cpp

#include <memory>
#include "Plant.h"

//��ȡPlant����
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
	Clear();//�������
	std::cout << "~Plant()" << std::endl;
}
//������ж���
void Plant::Clear()
{
	//��������
	for (unsigned long i = 0; i < m_pTargets.size(); ++i)
	{
		if (m_pTargets[i])
		{
			//�ͷſռ�
			::delete m_pTargets[i];
			Target::deletes(m_pTargets[i]);
		}
	}
	//�ͷ������ռ�
	m_pTargets.~vector();
}
void Plant::EraseTarget(Target* pTarget)
{
	//�����������ҵ���Ӧ����ɾ��
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
	//��������
	Person* pPerson = (Person*)::operator new(st);
	Plant* pf = Plant::Instance();
	//��Ӷ���������
	pf->AddTarget(pPerson);
	std::cout << "�ڴ�ռ������" << std::endl;
	return pPerson;
}

void Target::deletes(void* pTarget)
{
	//��������
	Plant* pPlant = Plant::Instance();
	//ɾ������
	pPlant->EraseTarget((Target*)pTarget);
	std::cout << "�ڴ�ռ����ͷţ�" << std::endl;
}

void Target::operator delete(void* pTarget)
{
	;//�պ����壬��Ҫʵ������
}