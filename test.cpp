#include<iostream>
using namespace std;
#include"managespace.h"
#include<ctime>
/*
����һ���ݽ�����ϵͳ
���ܰ�����
1.��ʼ�ݽ�����
2.�鿴���������¼
3.��ձ�����¼
4.�˳���������
*/
int main()
{
	manage m1;//��Ϊ���� ��������m
	manage m;
	int choice;
	while (true)
	{
		m = m1;
		system("cls");
		m.printmenu();
		cout << "��ѡ��" << endl;
		cin >> choice;
		switch (choice)
		{
		case 1:
			m.startspeech();
			m.startspeech();
			break;
		case 2:
			m.showRecord();
			system("pause");
			break;
		case 3:
			m.clearRecord();
			break;
		case 0:
			m.exitsystem();
			break;
		default:
			break;
		}
		m.savespeech();
		m.index = 1;
	}
	//���Դ���ѡ���Ƿ�ɹ�
	/*manage m;
	for (map<int, speaker>::iterator it = m.m_speaker.begin(); it != m.m_speaker.end(); it++)
	{
		cout << it->first << " ������" << it->second.m_name << " ��һ�ַ�����" << it->second.m_score[0] << " �ڶ��ַ�����" << it->second.m_score[1] << endl;
	}*/
	/*srand((unsigned int)time(NULL));
	for (int i = 0; i < 10; i++)
	{
		double num = (rand() % 401 + 600) / 10.f;
		cout << num << " ";
	}
	cout << endl;*/
	return 0;
}
























