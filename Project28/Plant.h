//Plant.h

#ifndef PLANT_H
#define PLANT_H
#include<iostream>
#include<vector>
//����
class Target
{
public:
	//�Զ����new
	static void* operator new(std::size_t);
	//�Զ����delete
	void operator delete(void* pTarget);
	static void deletes(void* pVoid);

	virtual ~Target() = 0 {};
};

class Plant
{

private:
	std::vector<Target*> m_pTargets;//����������Target
	//����Plant������ָ����Ԫ��
	friend class std::auto_ptr<Plant>;
	static std::auto_ptr<Plant> s_plant;
public:
	//��ȡPlant����
	static Plant* Instance();
	//���Ӷ����ָ��
	void AddTarget(Target* pTarget)
	{
		//��Ӷ���
		m_pTargets.push_back(pTarget);
	};
	//�Ƴ�����ָ��
	void EraseTarget(Target* pTarget);
	//������ж���
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

	//���캯��
	Person()
	{
		std::cout << "Person" << std::endl;
	}
	//��������
	~Person()
	{
		std::cout << "~Person()" << std::endl;
	}
};

#endif