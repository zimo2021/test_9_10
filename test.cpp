#include<iostream>
using namespace std;
#include"managespace.h"
#include<ctime>
/*
创建一个演讲比赛系统
功能包括：
1.开始演讲比赛
2.查看往届比赛记录
3.清空比赛记录
4.退出比赛程序
*/
int main()
{
	manage m1;//作为备份 用于重置m
	manage m;
	int choice;
	while (true)
	{
		m = m1;
		system("cls");
		m.printmenu();
		cout << "请选择：" << endl;
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
	//测试创建选手是否成功
	/*manage m;
	for (map<int, speaker>::iterator it = m.m_speaker.begin(); it != m.m_speaker.end(); it++)
	{
		cout << it->first << " 姓名：" << it->second.m_name << " 第一轮分数：" << it->second.m_score[0] << " 第二轮分数：" << it->second.m_score[1] << endl;
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
























