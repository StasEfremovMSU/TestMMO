#include "Human.h"
Human::Human()
{
	root = new  DecHaveFood();
	root->left = new DecHaveNearFood();
	root->rigth = new DecStayHome();
}

void Human::MakeStep()
{
	root->MakeDecision(*this);
	// �������� ����������
	UpdatePatametres();
	// ���������� ������
	Eat();
}