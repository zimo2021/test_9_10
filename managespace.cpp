#include<iostream>
using namespace std;
#include"managespace.h"
void manage::printmenu()
{
	cout << "***************************************" << endl;
	cout << "*****      欢迎参加演讲比赛       *****" << endl;
	cout << "************1.开始演讲比赛*************" << endl;
	cout << "************2.查看往届比赛记录*********" << endl;
	cout << "************3.清空比赛记录*************" << endl;
	cout << "************0.退出比赛程序*************" << endl;
	cout << "***************************************" << endl;
}
class person
{
public:
	int num;
};
void manage::creatmem()
{
	string seeds = "ABCDEFGHIJKL";

}
void manage::exitsystem()
{
	cout << "欢迎下次使用！" << endl;
	exit(0);
}
void manage::initcontainer()
{
	this->v1.clear();
	this->v2.clear();
	this->victory.clear();
	this->m_speaker.clear();
	this->index = 1;
	this->m_Record.clear();
}
manage::~manage()
{
	
}

manage::manage()
{
	this->initcontainer();
	this->creatspeaker();
	this->loadRecord();
}
void manage::creatspeaker()
{
	string nameseed = "ABCDEFGHIJKL";
	int i;
	for (i = 0; i < (int)nameseed.size(); i++)
	{
		string name = "选手";
		name += nameseed[i];
		speaker sp;
		sp.m_name = name;
		for (int j = 0; j < 2; j++)
		{
			sp.m_score[j] = 0;
		}
		this->v1.push_back(1001 + i);
		this->m_speaker.insert(make_pair(i + 1001, sp));
	}
}
void print(int val)
{
	cout << val << " ";
}
void manage::startspeech()
{
	vector<int>vp1;//盛放第一组选手编号
	vector<int>vp2;//盛放第二组选手编号
	vector<double>vs1;//盛放第一组分数
	vector<double>vs2;//盛放第二组分数
	/*vp1.resize(this->v1.size() / 2);
	vp2.resize(this->v1.size() / 2);*///没必要
	cout << "第<<" << this->index << ">>轮比赛正在抽签" << endl;
	cout << "------------------------------" << endl;
	cout << "抽签结果如下：" << endl;
	if (this->index == 1)
	{
		random_shuffle(v1.begin(), v1.end());
		for (vector<int>::iterator it = this->v1.begin(); it != this->v1.end(); it++)
		{
			cout << *it << " ";
		}
		cout << endl;
		for (int i = 0; i < (int)(this->v1.size() / 2); i++)
		{
			vp1.push_back(v1[i]);
			vp2.push_back(v1[i + (this->v1.size() / 2)]);
		}
		cout << "第一组：" << " ";
		for_each(vp1.begin(), vp1.end(), print);
		cout << endl;
		cout << "第二组：" << " ";
		for_each(vp2.begin(), vp2.end(), print);
		cout << endl;
		cout << "------------------------------" << endl;
		cout << "请三位评委打分" << endl;
		system("pause");
		cout << "第一轮评委打分结果如下：" << endl;
		srand((unsigned int)time(NULL));
		double sum1 = 0;
		double sum2 = 0;
		for (int j = 0; j < (int)(this->v1.size() / 2); j++)
		{
			sum1 = 0;
			sum2 = 0;
			for (int i = 0; i < 3; i++)
			{
				double num1 = (rand() % 401 + 600) / 10.f;
				sum1 += num1;
				double num2 = (rand() % 401 + 600) / 10.f;
				sum2 += num2;
			}
			/*this->m_speaker[vp1[j]].m_score[this->index - 1] = (sum1 / 3);
			this->m_speaker[vp2[j]].m_score[this->index - 1] = (sum2 / 3);*/
			vs1.push_back(sum1);
			vs2.push_back(sum2);
		}
		sort(vs1.begin(), vs1.end(), greater<double>());
		sort(vs2.begin(), vs2.end(), greater<double>());
		for (int i = 0; i < (int)(this->v1.size() / 2); i++)
		{
			this->m_speaker[vp1[i]].m_score[this->index - 1] = vs1[i]/3;
			this->m_speaker[vp2[i]].m_score[this->index - 1] = vs2[i]/3;
		}
		cout << "第一组" << endl;
		for (int i = 0; i < (int)(this->v1.size() / 2); i++)
		{
			cout << "编号：" << vp1[i] << " 姓名：" << this->m_speaker[vp1[i]].m_name << " 分数：" << this->m_speaker[vp1[i]].m_score[index - 1] << endl;
		}
		cout << endl;
		cout << "第二组" << endl;
		for (int i = 0; i < (int)(this->v1.size() / 2); i++)
		{
			cout << "编号：" << vp2[i] << " 姓名：" << this->m_speaker[vp2[i]].m_name << " 分数：" << this->m_speaker[vp2[i]].m_score[index - 1] << endl;
		}
		//将每组前三名存入v2中
		for (int i = 0; i < 3; i++)
		{
			this->v2.push_back(vp1[i]);
			this->v2.push_back(vp2[i]);
		}
		cout << "---------------------------- 第<<" << this->index << ">>轮比赛完毕------------------------------" << endl;
		cout << "第一轮比赛晋级情况如下:" << endl;
		for (vector<int>::iterator it = v2.begin(); it != v2.end(); it++)
		{
			cout << "编号：" << *it << " 姓名：" << this->m_speaker[*it].m_name << " 分数：" << this->m_speaker[*it].m_score[index - 1] << endl;
		}
		cout << "--------------------------------------------------------------------" << endl;
		this->index++;
	}
	else
	{
		vector<double>vs3;//用于盛放第二轮评委打分
		random_shuffle(v2.begin(), v2.end());
		cout << endl;
		cout << "请三位评委打分" << endl;
		system("pause");
		cout << "第二轮评委打分结果如下：" << endl;
		srand((unsigned int)time(NULL));
		double sum1 = 0;
		double sum2 = 0;
		for (int j = 0; j < (int)v2.size(); j++)
		{
			sum1 = 0;
			sum2 = 0;
			for (int i = 0; i < 3; i++)
			{
				double num1 = (rand() % 401 + 600) / 10.f;
				sum1 += num1;
			}
			vs3.push_back(sum1/3);
		}
		sort(vs3.begin(), vs3.end(), greater<double>());
		for (int i = 0; i < (int)vs3.size(); i++)
		{
			this->m_speaker[this->v2[i]].m_score[this->index - 1] = vs3[i];
		}
		cout << "评委打分结果如下：" << endl;
		for (vector<int>::iterator it = v2.begin(); it != v2.end(); it++)
		{
			cout << "编号：" << *it << " 姓名：" << this->m_speaker[*it].m_name << " 分数：" << this->m_speaker[*it].m_score[this->index - 1] << endl;
		}
		for (int i = 0; i < 3; i++)
		{
			this->victory.push_back(v2[i]);
		}
		cout << "---------------------------- 第<<" << this->index << ">>轮比赛完毕------------------------------" << endl;
		cout << "第二轮比赛晋级情况如下:" << endl;
		for (vector<int>::iterator it = this->victory.begin(); it != this->victory.end(); it++)
		{
			cout << "编号：" << *it << " 姓名：" << this->m_speaker[*it].m_name << " 分数：" << this->m_speaker[*it].m_score[index - 1] << endl;
		}
		cout << "--------------------------------------------------------------------" << endl;
	}
	system("pause");
}
void manage::savespeech()
{
	ofstream ofs;
	ofs.open("speech.csv", ios::out | ios::app);//其中app为append:追加的意思
	for (vector<int>::iterator it = this->victory.begin(); it != this->victory.end(); it++)
	{
		ofs << *it << "," << this->m_speaker[*it].m_score[1] << ",";
	}
	ofs << endl;
	ofs.close();
	cout << "记录已经保存！" << endl;//在相应的文件夹中会创建一个csv文件 可以在excel中打开
	system("pause");
}

void manage::loadRecord()
{
	ifstream ifs;
	ifs.open("speech.csv", ios::in);
	//判断文件是否存在
	if (!ifs.is_open())
	{
		cout << "文件不存在！" << endl;
		this->fileisEmpty = true;
		ifs.close();
		return;
	}
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		cout << "文件为空！" << endl;
		this->fileisEmpty = true;
		ifs.close();
		return;
	}
	//文件有效
	this->fileisEmpty = false;
	ifs.putback(ch);//将上面用于测试的ch读回来
	string data;
	int num = 0;
	while (ifs >> data)
	{
		vector<string>v;//用于存放截取的字符串 必须放在这个位置 否则会有重复的数据被载入
		int pos = -1;
		int start = 0;
		while (true)
		{
			pos = data.find(",", start);
			if (pos == -1)
			{
				//没有找到的情况
				break;
			}
			else 
			{
				string temp = data.substr(start, pos-start);
				v.push_back(temp);
				start = pos + 1;
			}
		}
		this->m_Record.insert(make_pair(num, v));
		num++;
	}
	ifs.close();
	cout << endl;
}

void manage::showRecord()
{
	int i;
	for (i = 0; i < (int)this->m_Record.size(); i++)
	{
		cout << "第<<" << i+1 << ">>届比赛记录：" << endl;
		cout << " 冠军编号：" << this->m_Record[i][0] << " 成绩 ：" << this->m_Record[i][1]
			<< " 亚军编号：" << this->m_Record[i][2] << " 成绩 ：" << this->m_Record[i][3]
			<< " 季军编号：" << this->m_Record[i][4] << " 成绩 ：" << this->m_Record[i][5] << endl;
	}
}
void manage::clearRecord()
{
	int choice;
	cout << "确认清空吗？" << endl;
	cout << "1.是" << endl;
	cout << "2.否" << endl;
	cin >> choice;
	if (choice == 1)
	{
		ofstream ofs("speech.csv", ios::trunc);//ios::trunc 如果前面文件中有数据 则清空全部数据 并且创建一个新的文件
		ofs.close();
		//重置文件
		this->initcontainer();
		//创建新的选手
		this->creatspeaker();
		//更新数据
		this->loadRecord();
		cout << "清空成功" << endl;
	}
	else
	{
		cout << "已取消！" << endl;
	}
}











