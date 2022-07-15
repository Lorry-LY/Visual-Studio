
#include<iostream>

#include<iomanip>

#include<fstream>

#include<string>

#include<map>

#include<vector>

#include<algorithm>

using namespace std;

struct some

{

    string snumber;

    string sname;

    string sclas;

    float ps;

    float ks;

};

class course {
public:

    vector<some>sss;

    map<string, int>ss;//ѧ����λ��

    map<string, int>::iterator ss1;

    string name, no, banhao, teacher, where[5];

    int number, time[5], n;//������

    float xuefen, chengji;

public:

    course(string n, string na, float fen, int x, string z) : no(n), name(na), xuefen(fen), number(x), banhao(z) { chengji = 0; teacher = "-1"; }

    course() {
        name = "-1"; no = "-1"; banhao = "-1"; teacher = "-1";

        xuefen = 0; number = 0; chengji = 0;
    }

    string getno() { return no; }

    void setno(string n) { no = n; }

    string getbanhao() { return banhao; }

    void setbanhao(string n) { banhao = n; }

    string getname() { return name; }

    void setname(string n) { name = n; }

    string getteacher() { return teacher; }//�ο���ʦ

    string getsssnumber(int a) { return sss[a].snumber; }//����ѧ��

    string getsssname(int a) { return sss[a].sname; }

    string getsssclas(int a) { return sss[a].sclas; }

    float getsssps(int a) { return sss[a].ps; }

    float getsssks(int a) { return sss[a].ks; }

    void displaystudent();

    int sssn() { return sss.size(); }

    void addstudent(string a, string b, string c, float x, float y);

    void erasestudent(string a);

    void setteacher(string n) { teacher = n; }

    float getxuefen() { return xuefen; }

    void setxuefen(float n) { xuefen = n; }

    int getnumber() { return number; }

    void setnumber(int n) { number = n; }

    float getichengji(string a) { return sss[ss[a]].ps * 0.3 + sss[ss[a]].ks * 0.7; }

    int getn() { return n; }

    void paixv();

    void tianjiaps(string a, float b) { sss[ss[a]].ps = b; }

    void tianjiaks(string a, float b) { sss[ss[a]].ks = b; }

    float getps(string a) { ss1 = ss.find(a); if (ss1 != ss.end()) return sss[ss[a]].ps; else return -1; }

    float getks(string a) { ss1 = ss.find(a); if (ss1 != ss.end()) return sss[ss[a]].ks; else return -1; }

    float getjiji(string a) { ss1 = ss.find(a); if (ss1 != ss.end()) return sss[ss[a]].ps * 0.3 + sss[ss[a]].ks * 0.7; else return -1; }

    int gettime(int a) { return time[a]; }

    string getwhere(int a) { return where[a]; }

    friend ostream& operator<<(ostream& os, course& d);

    friend istream& operator>>(istream& is, course& d);

};

ostream& operator<<(ostream& os, course& d)

{

    int i;

    cout << "�γ̴���\t�γ�����\t�γ�ѧ��\t��������\t��ѧ���\t�ο���ʦ" << endl;

    os << d.no << "\t\t" << d.name << "\t" << d.xuefen << "\t\t" << d.number << "\t\t" << d.banhao << "\t\t";

    if (d.teacher == "-1") cout << "����" << endl;

    else cout << d.teacher;

    cout << endl;

    cout << "�Ͽ�ʱ��\t�Ͽεص�" << endl;//Ӧ�����ļ�����γ���Ϣ����

    if (d.n == 0) cout << "����" << endl;

    for (i = 0; i < d.n; i++)

    {

        cout << "��";

        os << d.time[i] / 10;

        cout << "��";

        os << d.time[i] % 10;

        cout << "��";

        os << "\t" << d.where[i] << endl;

    }

    return os;

}

istream& operator>>(istream& is, course& d)

{
    string a, b, c;

    float x;

    int z, i = 0, k = 0;

    cout << "����������γ̴��š��γ����ơ�ѧ�֡�����������ѧ��ţ�����-1����" << endl;

    is >> a;

    if (a == "-1") { d.setno("-1"); return is; }

    is >> b;

    is >> x;

    is >> z >> c;

    course t(a, b, x, z, c);

    while (1)

    {
        cout << "�����Ͽ�ʱ�䡢�ص㣬����-1����" << endl;

        is >> t.time[i];

        if (t.time[i] == -1) break;

        is >> t.where[i];

        i++;

    }

    d = t;

    d.n = i;

    return is;

}

bool cmp1(course a, course b)//�γ̺��ֵ�����

{

    return a.getno() < b.getno();

}

bool ccc(struct some& a, struct some& b)

{

    return a.snumber < b.snumber;

}

void course::paixv()

{

    //sort(sss.begin(),sss.end(),ccc);

    ss.clear();

    for (int i = 0; i < sss.size(); i++)

        ss.insert(make_pair(sss[i].snumber, i));

}

void course::addstudent(string a, string b, string c, float x, float y)

{

    struct some A = { a,b,c,x,y };

    sss.push_back(A);

    paixv();

}

void course::erasestudent(string a)

{
    paixv();//cout<<sss.size()<<endl;

    ss1 = ss.find(a);

    if (ss1 != ss.end())

    {

        ss.erase(ss1);

        sss.erase(sss.begin() + ss1->second); paixv();
    }

}

void course::displaystudent()

{

    int i;

    cout << "����" << sss.size() << "��ѡ�˴��ſγ�" << endl;

    if (sss.size() == 0) return;

    cout << "ѡ��ѧ����Ϣ��" << endl;

    cout << "ѧ��ѧ��\tѧ������\t�����༶\tƽʱ�ɼ�\t���Գɼ�\t�ۺϳɼ�" << endl;

    for (i = 0; i < sss.size(); i++)

    {
        cout << sss[i].snumber << "\t" << sss[i].sname << "\t\t" << sss[i].sclas << "\t" << sss[i].ps << "\t\t" << sss[i].ks << "\t\t";

        cout << sss[i].ps * 0.3 + sss[i].ks * 0.7 << endl;

    }

    cout << endl;

}

class student {

    vector<course>c;

    vector<course>::iterator it;

    map<string, int>ma;

    map<string, int>::iterator ma1;

    course z;

    string name, number, clas;

    int n;//��ѡ�γ��ܺ�

    float average, jidian, zong;

    float s;//�γ̼����ܺ�

    int rankk;



    string kebiao[6][8];

    float all;//��ѡѧ��

public:

    student(string num, string na, string cla) :number(num), name(na), clas(cla)

    {

        for (int i = 0; i <= 5; i++)

            for (int j = 0; j <= 7; j++)

                kebiao[i][j] = "--------";

    }

    student() {

        name = "-1"; number = "-1"; clas = "-1";

    }

    string getnumber() { return number; }

    void setnumber(string m) { number = m; }

    string getname() { return name; }

    void setname(string m) { name = m; }

    string getclas() { return clas; }

    void setclas(string m) { clas = m; }

    int getn() { return c.size(); }

    void setn(int a) { n = a; }

    float getxuefen() { return all; }

    float getjidian() { return jidian; }

    void setjidian(float a) { jidian = a; }

    float getaverage() { return average; }

    void NEW();

    int find(string a);

    void add(course a);

    void erasee(string noo);

    float dankechengji(int i) { return c[i].getichengji(number); }

    void xiugai();

    int getfind();

    void paixv();

    void kebiaodisplay();

    void displayalll();

    int chake(int a) { if (kebiao[a % 10][a / 10] != "--------") return 1; else return 0; }

    int chakecheng(string a) { ma1 = ma.find(a); if (ma1 != ma.end()) return ma[a]; else return -1; }

    string courseno(int k) { return c[k].getno(); }

    string coursehao(int j) { return c[j].getbanhao(); }

    friend ostream& operator<<(ostream& os, student& d);

    friend istream& operator>>(istream& is, student& d);

    void displayall();

};

void student::displayalll()

{

    float zong = 0, xuefen = 0;

    int i, j;

    for (int i = 0; i < c.size(); i++)

    {

        if (c[i].getjiji(number) < 60) cout << "0" << endl;

        else {
            cout << (c[i].getjiji(number) / 10 - 5) * c[i].getxuefen() << endl;

            zong += (c[i].getjiji(number) / 10 - 5) * c[i].getxuefen();
        }

        xuefen += c[i].getxuefen();

    }

    if (zong == 0) setjidian(0);

    else

        setjidian(zong / xuefen);

}

void student::displayall()

{
    system("cls");

    float zong = 0, xuefen = 0;

    int i, j;

    cout << "�γ�����\t�γ̳ɼ�\t�γ�ѧ��\t�γ̼���" << endl;

    for (int i = 0; i < c.size(); i++)

    {

        cout << c[i].getname() << "\t" << c[i].getjiji(number) << "\t\t" << c[i].getxuefen() << "\t";

        if (c[i].getjiji(number) < 60) cout << "0" << endl;

        else {
            cout << (c[i].getjiji(number) / 10 - 5) * c[i].getxuefen() << endl;

            zong += (c[i].getjiji(number) / 10 - 5) * c[i].getxuefen();
        }

        xuefen += c[i].getxuefen();

    }

    if (zong == 0) setjidian(0);

    else

        setjidian(zong / xuefen);

    cout << "ƽ��ѧ�ּ���:\t" << getjidian() << endl; system("pause");

}

void student::kebiaodisplay()

{

    int i, j;

    cout << "         ��һ\t\t�ܶ�\t\t����\t\t����\t\t����\t\t����\t\t����" << endl;

    for (i = 1; i <= 5; i++)

    {

        cout << "��" << i << "���\t";

        for (j = 1; j <= 7; j++)

            cout << kebiao[i][j] << "\t";

        cout << endl;

    }

}

ostream& operator<<(ostream& os, student& d)

{

    cout << "-----------------------------------------------" << endl;

    cout << "ѧ��\t\t����\t\t�༶\t\tƽ��ѧ�ּ���\tѡ������" << endl;

    os << d.number << "\t" << d.name << "\t\t" << d.clas << "\t" << d.getjidian() << "\t\t" << d.c.size() << endl;

    for (int i = 0; i < d.c.size(); i++)

    {
        os << d.c[i];

        cout << "�ɼ�:" << d.dankechengji(i) << endl << endl;
    }

    cout << "-----------------------------------------------" << endl << endl;

    return os;

}

istream& operator>>(istream& is, student& d)

{

    string a, b, c, x;

    cout << "��������ѧ��ѧ�š��������༶,��-1��������" << endl;

    is >> a;

    if (a == "-1") { d.setnumber(a); return is; }

    is >> b >> c;

    student t(a, b, c);

    d = t;

    return is;

}

void student::paixv()

{

    ma.clear();

    sort(c.begin(), c.end(), cmp1);

    n = c.size();

    for (int i = 0; i < n; i++)

        ma.insert(make_pair(c[i].getno(), i));

}

void student::NEW()

{

    average = zong / n;

    jidian = s / all;

}

void student::add(course a)

{

    c.push_back(a);

    ma.insert(make_pair(a.getno(), c.size() - 1));

    all += a.getxuefen();

    n = c.size();

    for (int i = 0; i < a.getn(); i++)

        kebiao[a.gettime(i) % 10][a.gettime(i) / 10] = a.getname();

    paixv();

}

void student::erasee(string noo)

{

    ma1 = ma.find(noo); if (ma1 == ma.end()) { cout << "δѡ�˿�" << endl; return; }



    cout << c[ma[noo]] << endl; cout << "��ѡ�ɹ�" << endl;



    for (int i = 0; i < c[ma[noo]].getn(); i++)

        kebiao[c[ma[noo]].gettime(i) % 10][c[ma[noo]].gettime(i) / 10] = "--------";

    c.erase(c.begin() + ma[noo]);

    ma.erase(ma1); n = c.size();

    paixv();

}

bool cmps(student a, student b)//ѧ����ѧ������

{

    return a.getnumber() < b.getnumber();

}

bool cmps1(student a, student b)//ѧ������������

{

    return a.getjidian() > b.getjidian();

}

class teacher {

    string hao;

    string yuanxi;

    string name;

    int number;

    vector<course>c;

    vector<course>::iterator it;

    map<string, int>ma;

    map<string, int>::iterator ma1;

    course z;

    string kebiao[6][8];

public:

    teacher(string a, string b, string c) :hao(a), yuanxi(c), name(b)

    {
        for (int i = 0; i <= 5; i++)

            for (int j = 0; j <= 7; j++)

                kebiao[i][j] = "--------";
    }

    teacher() {

        hao = "-1"; yuanxi = "-1"; name = "-1"; number = 0;
    }

    string gethao() { return hao; }

    void sethao(string a) { hao = a; }

    string getyuanxi() { return yuanxi; }

    void setyuanxi(string a) { yuanxi = a; }

    string getname() { return name; }

    void setname(string a) { name = a; }

    int getnumber() { return c.size(); }

    void setnumber(int a) { number = a; }

    void paixv();

    void add(course a);

    int chake(int a) { if (kebiao[a % 10][a / 10] != "--------") return 1; else return 0; }

    int chakecheng(string a, string b) { ma1 = ma.find(a); if (ma1 != ma.end() && c[ma[a]].getbanhao() == b) return ma[a]; else return -1; }

    string courseno(int k) { return c[k].getno(); }

    int chakechengm(string a) { ma1 = ma.find(a); if (ma1 != ma.end()) return ma[a]; else return -1; }

    string coursehao(int j) { return c[j].getbanhao(); }

    void erasee(string noo);

    void kebiaodisplay();

    void displaystudent(string a, string b);

    void setpschengji(string a, int i, float ji)

    {
        c[ma[a]].tianjiaps(c[ma[a]].getsssnumber(i), ji);
    }

    void setkschengji(string a, int i, float ji)

    {
        c[ma[a]].tianjiaks(c[ma[a]].getsssnumber(i), ji);
    }

    friend ostream& operator<<(ostream& os, teacher& d);

    friend istream& operator>>(istream& is, teacher& d);

};

void teacher::displaystudent(string a, string b)

{
    ma1 = ma.find(a);

    if (ma1 != ma.end() && c[ma[a]].getbanhao() == b)

        c[ma[a]].displaystudent();

    else cout << "������������������" << endl;

    system("pause");

}

void teacher::kebiaodisplay()

{

    int i, j;

    cout << "         ��һ\t\t�ܶ�\t\t����\t\t����\t\t����\t\t����\t\t����" << endl;

    for (i = 1; i <= 5; i++)

    {

        cout << "��" << i << "���\t";

        for (j = 1; j <= 7; j++)

            cout << kebiao[i][j] << "\t";

        cout << endl;

    }

}

ostream& operator<<(ostream& os, teacher& d)

{
    cout << "-----------------------------------------------" << endl;

    cout << "��ʦ����\t��ʦ����\t����Ժϵ\t���ڿγ�����" << endl;

    os << d.hao << "\t\t" << d.name << "\t\t" << d.yuanxi << "\t\t" << d.c.size() << endl;

    cout << "���ڿγ�:" << endl;

    for (int i = 0; i < d.c.size(); i++)

    {
        os << d.c[i] << endl;

        d.c[i].displaystudent();
    }

    cout << "-----------------------------------------------" << endl;

    return os;

}

istream& operator>>(istream& is, teacher& d)

{

    string a, b, c;

    cout << "���������ʦ���š���ʦ������Ժϵ������-1����" << endl;

    is >> a;

    if (a == "-1") { d.sethao(a); return is; }

    is >> b >> c;

    teacher t(a, b, c);

    d = t;

    return is;

}

bool cmpt(teacher a, teacher b)//ѧ����ѧ������

{

    return a.gethao() < b.gethao();

}

void teacher::paixv()

{

    ma.clear();

    sort(c.begin(), c.end(), cmp1);

    number = c.size();

    for (int i = 0; i < number; i++)

        ma.insert(make_pair(c[i].getno(), i));

}

void teacher::add(course a)

{

    c.push_back(a);

    number = c.size();

    for (int i = 0; i < a.getn(); i++)

        kebiao[a.gettime(i) % 10][a.gettime(i) / 10] = a.getname();

    paixv();

}

void teacher::erasee(string noo)

{

    ma1 = ma.find(noo); if (ma1 == ma.end()) { cout << "δѡ�˿�" << endl; return; }

    cout << c[ma1->second] << endl; cout << "��ѡ�ɹ�" << endl;

    for (int i = 0; i < c[ma[noo]].getn(); i++)

        kebiao[c[ma[noo]].gettime(i) % 10][c[ma[noo]].gettime(i) / 10] = "--------";

    c.erase(c.begin() + ma1->second);

    ma.erase(ma1); number = c.size();

    paixv();



}

class guanli

{



public:

    vector<course>c;

    vector<course>::iterator it;

    map<string, int>ma;

    map<string, int>::iterator ma1;

    vector<student>s;

    vector<student>::iterator its;

    map<string, int>mas;

    map<string, int>::iterator ma1s;

    vector<teacher>t;

    vector<teacher>::iterator itt;

    map<string, int>mat;

    map<string, int>::iterator ma1t;

    void addcourse();

    void addstudent();

    void addteacher();



    int searchcourse(string no, string aa);

    int searchstudent(string no);

    int searchteacher(string no);



    void deletecourse();

    void deletestudent();

    void deleteteacher();



    void querycourse();

    int  qquerycourse(string name, string hao);

    void querystudent();

    int  qquerystudent(string name);

    void queryteacher();

    int  qqueryteacher(string name);



    void chargecourse();

    void chargestudent();

    void chargeteacher();



    void displaycourse(int a);

    void displaystudent();

    void displayteacher();



    void menudisplay1();

    void menudisplay2(int a);

    void menu2(int a);

    void menu1();



    void load1();

    void load2();

    void load3();

    void save1();

    void save2();

    void save3();



    void paixvc();

    void paixvs();

    void paixvt();

};

void guanli::paixvc()

{

    ma.clear();

    sort(c.begin(), c.end(), cmp1);

    for (int i = 0; i < c.size(); i++)

        ma.insert(make_pair(c[i].getno(), i));

}

void guanli::paixvs()

{

    mas.clear();

    sort(s.begin(), s.end(), cmps);

    for (int i = 0; i < s.size(); i++)

        mas.insert(make_pair(s[i].getnumber(), i));

}

void guanli::paixvt()

{

    mat.clear();

    sort(t.begin(), t.end(), cmpt);

    for (int i = 0; i < t.size(); i++)

        mat.insert(make_pair(t[i].gethao(), i));

}

void guanli::addcourse()

{

    int a;

    course z;

    while (1)

    {
        system("cls");

        cin >> z;

        if (z.getno() == "-1") break;

        a = searchcourse(z.getno(), z.getbanhao());

        if (a != -1) cout << "�Ѵ��ڴ��ſγ�" << endl;

        else { c.push_back(z); cout << "�����" << endl; }

        system("pause");

    }

    paixvc();

}

void guanli::addstudent()

{

    student z;

    while (1)

    {
        system("cls");

        cin >> z;

        if (z.getnumber() == "-1") break;

        if (searchstudent(z.getnumber()) != -1) cout << "�Ѵ��ڴ�ѧ��ѧ��" << endl;

        else { s.push_back(z); cout << "ѧ����ӳɹ�" << endl; }

        system("pause");

    }paixvs();

}

void guanli::addteacher()

{

    teacher z;

    while (1)

    {
        system("cls");

        cin >> z;

        if (z.gethao() == "-1") break;

        if (searchteacher(z.gethao()) != -1) cout << "�Ѵ��ڴ˹��Ž�ʦ" << endl;

        else { t.push_back(z); cout << "��ʦ��ӳɹ�" << endl; }

        system("pause");

    }paixvt();

}

int guanli::searchcourse(string no, string aa)

{

    int i;

    for (i = 0; i < c.size(); i++)

        if (c[i].getno() == no && c[i].getbanhao() == aa)

            return i;

    return -1;

}

int guanli::searchstudent(string no)

{

    int i;

    for (i = 0; i < s.size(); i++)

        if (s[i].getnumber() == no)

            return i;

    return -1;

}

int guanli::searchteacher(string no)

{

    int i;

    for (i = 0; i < t.size(); i++)

        if (t[i].gethao() == no)

            return i;

    return -1;

}

void guanli::querycourse()

{

    int k;

    string a;

    string name; system("cls");

    while (1)

    {

        cout << "��������γ̵Ŀγ̺źͽ�ѧ���,����-1����" << endl;

        cin >> name;

        if (name == "-1") break;

        cin >> a;

        k = searchcourse(name, a);

        if (k != -1) { cout << c[k] << endl; c[k].displaystudent(); }

        else cout << "�γ̺�������������������" << endl;

    }

}



void guanli::querystudent()

{

    int k;

    string name; system("cls");

    while (1)

    {
        cout << "��������ѧ����ѧ��,����-1����" << endl;

        cin >> name;

        if (name == "-1") break;

        k = searchstudent(name);

        if (k != -1) cout << s[k] << endl;

        else cout << "ѧ��������������������" << endl;

    }



}

int guanli::qquerycourse(string name, string hao)

{

    int k;

    k = searchcourse(name, hao);

    return k;

}

int guanli::qquerystudent(string name)

{

    int k;

    k = searchstudent(name);

    return k;

}

int guanli::qqueryteacher(string name)

{

    int k;

    k = searchteacher(name);

    return k;

}

void guanli::queryteacher()

{

    int k;

    string name; system("cls");

    while (1)

    {
        cout << "���������ʦ�Ĺ���,����-1����" << endl;

        cin >> name;

        if (name == "-1") break;

        k = searchteacher(name);

        if (k != -1) cout << t[k] << endl;

        else cout << "����������������������" << endl;

    }

}

void guanli::deletecourse()

{

    int k;

    string na, hao; system("cls");

    while (1)

    {

        cout << "����Ҫɾ���Ŀγ̵Ŀγ̺źͰ��,����-1����" << endl;

        cin >> na;

        if (na == "-1") break;

        cin >> hao;

        k = searchcourse(na, hao);

        if (k != -1) c.erase(c.begin() + k);

        else cout << "�γ̺�������������������" << endl;

    }

}

void guanli::deletestudent()

{

    int k;

    string na; system("cls");

    while (1)

    {

        cout << "����Ҫɾ����ѧ����ѧ��,����-1����" << endl;

        cin >> na;

        if (na == "-1") break;

        k = searchstudent(na);

        if (k != -1) s.erase(s.begin() + k);

        else cout << "ѧ��������������������" << endl;

    }

}

void guanli::deleteteacher()

{

    int k;

    string na; system("cls");

    while (1)

    {

        cout << "����Ҫɾ���Ľ�ʦ�Ĺ���,����-1����" << endl;

        cin >> na;

        if (na == "-1") break;

        k = searchteacher(na);

        if (k != -1) t.erase(t.begin() + k);

        else cout << "����������������������" << endl;

    }

}

void guanli::chargecourse()

{

    int k;

    string na, hao;

    course zz; system("cls");

    while (1)

    {

        cout << "����Ҫ�޸ĵĿγ̵Ŀγ̺źͰ��,����-1����" << endl;

        cin >> na >> hao;

        if (na == "-1") break;

        k = searchcourse(na, hao);

        if (k != -1)

        {

            cout << c[k] << endl;

            cin >> zz;

            c[k] = zz;

            cout << "�޸ĺ����Ϣ��" << endl;

            cout << c[k] << endl;

        }

        else cout << "�γ̺�������������������" << endl;

    }

    paixvc();

}

void guanli::chargestudent()

{

    int k;

    string na;

    student zz; system("cls");

    while (1)

    {

        cout << "����Ҫ�޸ĵ�ѧ����ѧ��,����-1����" << endl;

        cin >> na;

        if (na == "-1") break;

        k = searchstudent(na);

        if (k != -1)

        {

            cout << s[k] << endl;

            cin >> zz;

            s[k] = zz;

            cout << "�޸ĺ����Ϣ��" << endl;

            cout << s[k] << endl;

        }

        else cout << "ѧ��������������������" << endl;

    }paixvs();

}

void guanli::chargeteacher()

{

    int k;

    string na; system("cls");

    teacher zz;

    while (1)

    {

        cout << "����Ҫ�޸ĵĽ�ʦ�Ĺ���,����-1����" << endl;

        cin >> na;

        if (na == "-1") break;

        k = searchteacher(na);

        if (k != -1)

        {

            cout << t[k] << endl;

            cin >> zz;

            t[k] = zz;

            cout << "�޸ĺ����Ϣ��" << endl;

            cout << t[k] << endl;

        }

        else cout << "����������������������" << endl;

    }paixvt();

}

void guanli::displaycourse(int a)

{
    system("cls");

    string ss;



    for (int i = 0; i < c.size(); i++)

    {
        cout << "-----------------------------------------------" << endl;

        cout << c[i] << endl;

        if (a)

        {

            //cout<<"����"<<c[i].sssn()<<"��ѡ�˴˿�"<<endl;

            if (c[i].sssn() != 0)

            {

                c[i].displaystudent();

            }
        }cout << "-----------------------------------------------" << endl;

    }



}

void guanli::displaystudent()

{
    system("cls");

    for (int i = 0; i < s.size(); i++)

        cout << s[i] << endl;

}

void guanli::displayteacher()

{
    system("cls");

    for (int i = 0; i < t.size(); i++)

        cout << t[i] << endl;

}

void guanli::load1()

{
    fstream filename;
    filename.open("course.txt");
    if (filename)
    {
        c.clear();
        while (!filename.eof())
        {
            string no, name, banhao;
            int number;
            float grade;
            filename >> no >> name >> banhao >> number >> grade;
            course x1(no, name, grade, number, banhao);
            c.push_back(x1);
        }

    }
    else
    {
        cout << "�ļ���ʧ�ܣ�\n";
    }
    filename.close();
    /*course x1;

    int n;

    string m, z, l, a;

    float b, x, y;

    ifstream infile("d:\\20164235-course.txt", ios::in);

    if (!infile) return;

    c.clear();

    while (infile >> x1)

    {
        if (x1.getno() == "-1") break;

        infile >> m;

        x1.setteacher(m);

        infile >> n;

        for (int i = 0; i < n; i++)

        {

            infile >> m >> z >> l >> x >> y;

            x1.addstudent(m, z, l, x, y);

        }

        c.push_back(x1);

        ma.insert(make_pair(x1.getno(), c.size() - 1));

    }

    infile.close(); system("cls");*/

}

void guanli::load2()

{

    int a;

    course x;

    string zz, hao;

    student x1;

    float l;

    ifstream infile("d:\\20164235-student.txt", ios::in);

    if (!infile) return;

    s.clear();

    while (infile >> x1)

    {



        if (x1.getnumber() == "-1") break;

        infile >> l;

        x1.setjidian(l);

        infile >> a;

        while (a--)

        {
            infile >> zz >> hao;

            x1.add(c[qquerycourse(zz, hao)]);

        }

        x1.setn(a); x1.displayalll();

        s.push_back(x1);

        mas.insert(make_pair(x1.getnumber(), s.size() - 1));

    }

    infile.close(); system("cls");

}

void guanli::load3()

{

    int a;

    course x;

    string zz, hao;

    teacher x1;

    ifstream infile("d:\\20164235-teacher.txt", ios::in);

    if (!infile) return;

    t.clear();

    while (infile >> x1)

    {



        if (x1.gethao() == "-1") break;

        infile >> a;

        while (a--)

        {
            infile >> zz >> hao;



            x1.add(c[qquerycourse(zz, hao)]);

        }x1.setnumber(a);

        t.push_back(x1);

        mat.insert(make_pair(x1.gethao(), t.size() - 1));

    }

    infile.close(); system("cls");

}

void guanli::save1()

{
    fstream filename;
    filename.open("course.txt", ios::trunc);
    for (int i = 0; i < c.size(); i++)
    {
        course x1 = c.back();
        c.pop_back();
        filename << x1.no << ' ' << x1.name << ' ' << x1.banhao << ' ' << x1.number << ' ' << x1.chengji << endl;
        delete &x1;
    }
    filename.close();
    /*int j, k;

    ofstream outfile("d:\\20164235-course.txt", ios::out);

    if (!outfile) return;

    for (int i = 0; i < c.size(); i++)

    {
        outfile << c[i].getno() << "\t\t" << c[i].getname() << "\t\t" << c[i].getxuefen();

        outfile << "\t\t" << c[i].getnumber() << "\t\t" << c[i].getbanhao() << "\t\t";

        for (k = 0; k < c[i].getn(); k++)

        {

            outfile << c[i].gettime(k) << "\t" << c[i].getwhere(k) << endl;



        }

        outfile << "-1" << endl;

        outfile << c[i].getteacher() << endl;

        outfile << c[i].sssn() << endl;

        if (c[i].sssn() != 0)

        {

            for (j = 0; j < c[i].sssn(); j++)

            {
                outfile << c[i].getsssnumber(j) << "\t" << c[i].getsssname(j) << "\t" << c[i].getsssclas(j);

                outfile << "\t" << c[i].getsssps(j) << "\t" << c[i].getsssks(j) << endl;

            }
        }
    }

    outfile << "-1" << endl;

    outfile.close(); */system("cls");

}

void guanli::save2()

{

    ofstream outfile("d:\\20164235-student.txt", ios::out);

    if (!outfile) return;



    for (int i = 0; i < s.size(); i++)

    {

        outfile << s[i].getnumber() << "\t" << s[i].getname() << "\t" << s[i].getclas() << "\t" << s[i].getjidian() << "\t" << s[i].getn() << endl;

        for (int j = 0; j < s[i].getn(); j++)

            outfile << s[i].courseno(j) << "\t" << s[i].coursehao(j) << endl;

    }

    outfile << "-1" << endl;

    outfile.close(); system("cls");

}

void guanli::save3()

{

    ofstream outfile("d:\\20164235-teacher.txt", ios::out);

    if (!outfile) return;

    for (int i = 0; i < t.size(); i++)

    {
        outfile << t[i].gethao() << "\t" << t[i].getname() << "\t";

        outfile << t[i].getyuanxi() << "\t" << t[i].getnumber() << endl;



        for (int j = 0; j < t[i].getnumber(); j++)

            outfile << t[i].courseno(j) << "\t" << t[i].coursehao(j) << endl;

    }

    outfile << endl << "-1" << endl;

    outfile.close(); system("cls");

}

void guanli::menudisplay1()

{

    cout << "*******************************************" << endl;

    cout << "             ��ӭʹ��ѡ��ϵͳ              " << endl;

    cout << " 0:              �˳�                      " << endl;

    cout << " 1:              �γ̹���                  " << endl;

    cout << " 2:              ѧ������                  " << endl;

    cout << " 3:              ��ʦ����                  " << endl;

    cout << "*******************************************" << endl;

    return;

}

void guanli::menudisplay2(int a)

{

    cout << "*******************************************" << endl;



    if (a == 1)

    {

        cout << "            ��ӭʹ�ÿγ̹���ϵͳ           " << endl;

        cout << " 0:              �˳�                      " << endl;

        cout << " 1:              ���ӿγ�                  " << endl;

        cout << " 2:              ɾ���γ�                  " << endl;

        cout << " 3:              �޸Ŀγ�                  " << endl;

        cout << " 4:              ��ѯ�γ�                  " << endl;

        cout << " 5:              չʾ���пγ̼�ѡ�ν��    " << endl;

    }

    if (a == 2)

    {

        cout << "            ��ӭʹ��ѧ������ϵͳ           " << endl;

        cout << " 0:              �˳�                      " << endl;

        cout << " 1:              ����ѧ��                  " << endl;

        cout << " 2:              ɾ��ѧ��                  " << endl;

        cout << " 3:              �޸�ѧ��                  " << endl;

        cout << " 4:              ��ѯѧ��                  " << endl;

        cout << " 5:              չʾ����ѧ��              " << endl;

    }

    if (a == 3)

    {

        cout << "            ��ӭʹ�ý�ʦ����ϵͳ           " << endl;

        cout << " 0:              �˳�                      " << endl;

        cout << " 1:              ���ӽ�ʦ                  " << endl;

        cout << " 2:              ɾ����ʦ                  " << endl;

        cout << " 3:              �޸Ľ�ʦ                  " << endl;

        cout << " 4:              ��ѯ��ʦ                  " << endl;

        cout << " 5:              չʾ������ʦ              " << endl;

    }

    cout << "*******************************************" << endl;

}

void guanli::menu1()

{

    int x;

    while (1)

    {
        system("cls");

        menudisplay1();

        cout << "���������ѡ��" << endl;

        cin >> x;

        if (!x) break;

        system("cls");

        menu2(x);

    }

}

void guanli::menu2(int a)

{

    int x;

    system("cls");

    if (a == 1)

    {

        while (1)

        {

            menudisplay2(a);

            cout << "���������ѡ��" << endl;

            cin >> x;

            if (!x) break;

            switch (x)

            {

            case 1:

                addcourse();

                break;

            case 2:

                deletecourse();

                break;

            case 3:

                chargecourse();

                break;

            case 4:

                querycourse();

                break;

            case 5:

                displaycourse(1);

                break;

            }

            system("pause");

            system("cls");

        }

    }

    if (a == 2)

    {

        while (1)

        {

            menudisplay2(a);

            cout << "���������ѡ��" << endl;

            cin >> x;

            if (!x) break;

            switch (x)

            {

            case 1:

                addstudent();

                break;

            case 2:

                deletestudent();

                break;

            case 3:

                chargestudent();

                break;

            case 4:

                querystudent();

                break;

            case 5:

                displaystudent();

                break;

            }

            system("pause");

            system("cls");

        }

    }

    if (a == 3)

    {

        while (1)

        {

            menudisplay2(a);

            cout << "���������ѡ��" << endl;

            cin >> x;

            if (!x) break;

            switch (x)

            {

            case 1:

                addteacher();

                break;

            case 2:

                deleteteacher();

                break;

            case 3:

                chargeteacher();

                break;

            case 4:

                queryteacher();

                break;

            case 5:

                displayteacher();

                break;

            }

            system("pause");

            system("cls");

        }
    }



}

class studentcaozuo

{

    student s;

    vector<course>c;

    vector<course>::iterator it;

    map<string, int>ma;

    map<string, int>::iterator ma1;

public:

    void displaycourse();

    void addc();

    void erasec();

    void load1();

    student A() { return s; }

    void xuanze();

    void jieguo();

    void save1();

    studentcaozuo(student a) :s(a) { load1(); xuanze(); save1(); }

};

void studentcaozuo::save1()

{
    int j, k;

    ofstream outfile("d:\\20164235-course.txt", ios::out);

    if (!outfile) return;

    for (int i = 0; i < c.size(); i++)

    {
        outfile << c[i].getno() << "\t\t" << c[i].getname() << "\t\t" << c[i].getxuefen();

        outfile << "\t\t" << c[i].getnumber() << "\t\t" << c[i].getbanhao() << "\t\t";

        for (k = 0; k < c[i].getn(); k++)

        {

            outfile << c[i].gettime(k) << "\t" << c[i].getwhere(k) << endl;



        }

        outfile << "-1" << endl;

        outfile << c[i].getteacher() << endl;

        outfile << c[i].sssn() << endl;//cout<<c[i].sssn()<<endl;system("pause");

        if (c[i].sssn() != 0)

        {

            for (j = 0; j < c[i].sssn(); j++)

            {
                outfile << c[i].getsssnumber(j) << "\t" << c[i].getsssname(j) << "\t" << c[i].getsssclas(j);

                outfile << "\t" << c[i].getsssps(j) << "\t" << c[i].getsssks(j) << endl;

            }
        }
    }

    outfile << "-1" << endl;

    outfile.close(); system("cls");

}

void studentcaozuo::displaycourse()

{

    for (int i = 0; i < c.size(); i++)

    {
        cout << "-----------------------------------------------" << endl;

        cout << c[i] << endl;

        cout << "-----------------------------------------------" << endl << endl;

    }

}

void studentcaozuo::xuanze()

{
    int a;

    while (1)

    {

        system("cls");

        s.kebiaodisplay();

        cout << "###################################################################" << endl;

        cout << "   0:                               �˳�" << endl;

        cout << "   1:                               ѡ��" << endl;

        cout << "   2:                               �˿�" << endl;

        cout << "   3:                               ���Գɼ�" << endl;

        cout << "   4:                               ѡ�����" << endl;

        cout << "###################################################################" << endl;

        cin >> a;

        if (a == 0) break;

        else if (a == 1) addc();

        else if (a == 2) erasec();

        else if (a == 3) s.displayall();

        else if (a == 4) { system("cls"); cout << s << endl; system("pause"); }

    }

}

void studentcaozuo::load1()

{
    fstream filename;
    filename.open("course.txt");
    if (filename)
    {
        c.clear();
        while (!filename.eof())
        {
            string no, name, banhao;
            int number;
            float grade;
            filename >> no >> name >> banhao >> number >> grade;
            course x1(no, name, grade, number, banhao);
            c.push_back(x1);
        }

    }
    else
    {
        cout << "�ļ���ʧ�ܣ�\n";
    }
    filename.close();
    /*course x1;

    int n;

    string m, z, l, a;

    float b, x, y;

    ifstream infile("d:\\20164235-course.txt", ios::in);

    if (!infile) return;

    c.clear();

    while (infile >> x1)

    {
        if (x1.getno() == "-1") break;

        infile >> m;

        x1.setteacher(m);

        infile >> n;

        for (int i = 0; i < n; i++)

        {

            infile >> m >> z >> l >> x >> y;

            x1.addstudent(m, z, l, x, y);

        }

        c.push_back(x1);

        ma.insert(make_pair(x1.getno(), c.size() - 1));

    }

    infile.close(); system("cls");*/

}

void studentcaozuo::addc()

{

    string z, hao;

    int i, j, t = 0;

    while (1)

    {
        system("cls");

        load1();

        displaycourse();

        cout << s << endl; int l;

        cout << "��������ѡ�γ̵Ŀγ̺š����,����-1����" << endl;

        cin >> z;

        if (z == "-1") break;

        else

        {
            cin >> hao;

            if (s.chakecheng(z) != -1) { cout << "���ſγ���ѡ��" << endl; system("pause"); }

            else

            {
                system("cls");

                for (i = 0; i < c.size(); i++)

                    if (c[i].getno() == z && c[i].getbanhao() == hao) { cout << c[i] << endl; break; }

                if (i != c.size()) {

                    if (c[i].sssn() == c[i].getnumber()) cout << "���ſγ�����,������ѡ��" << endl;

                    else {

                        for (j = 0; j < c[i].getn(); j++)

                        {
                            l = c[i].gettime(j);

                            if (s.chake(c[i].gettime(j))) { cout << "ʱ���ͻ" << endl; t = 1; break; }
                        }

                        if (t == 0) {

                            c[i].addstudent(s.getnumber(), s.getname(), s.getclas(), 0, 0);//;

                            cout << "��ѡ�˿γ�" << endl;

                            s.add(c[i]); save1();//c[i].displaystudent();system("pause");

                        }
                    }system("pause");

                }

                else {

                    cout << "�γ̺���������,���������룬����-1����" << endl; system("pause");
                }

            }

        }
    }

}

void studentcaozuo::erasec()

{

    string z;

    while (1)

    {
        system("cls");

        cout << s << endl;

        cout << "���������˿γ̵Ŀγ̺�,����-1����" << endl;

        cin >> z;

        if (z == "-1") break;

        else

        {
            ma1 = ma.find(z);

            if (ma1 != ma.end())

            {//cout<<"!"<<endl;

                c[ma1->second].erasestudent(s.getnumber());

                s.erasee(z);

                //ma.erase(ma1);

                //cout<<"����ѡ���ſγ�"<<endl;

                save1();

                system("pause");

            }

            else {

                cout << "�γ̺�������������������,����-1����" << endl; system("pause");

            }
        }

    }

}

class teachercaozuo

{

    teacher t;

    vector<course>c;

    vector<course>::iterator it;

    map<string, int>ma;

    map<string, int>::iterator ma1;

public:

    void addc();

    void erasec();

    void xuanze();

    void displaycourse();

    teacher A() { return t; }

    void load1();

    void save1();

    void pschengji(string a, string b);

    void kschengji(string a, string b);

    teachercaozuo(teacher a) :t(a) { load1(); xuanze(); save1(); }

};

void teachercaozuo::pschengji(string a, string b)

{
    system("cls");

    string k;

    int j;

    float ji;

    for (j = 0; j < c.size(); j++)

        if (c[j].getno() == a && c[j].getbanhao() == b)

        {

            cout << "���Ӧ����ѧ��ƽʱ�ɼ�" << endl;

            cout << "ѧ��\t\t����\t\tƽʱ�ɼ�" << endl;

            for (int i = 0; i < c[j].sssn(); i++)

            {
                cout << c[j].getsssnumber(i) << "\t" << c[j].getsssname(i) << "\t\t";

                cin >> ji;

                cout << endl;

                c[j].tianjiaps(c[j].getsssnumber(i), ji);

                t.setpschengji(a, i, ji);

            }break;

        }

    if (j == c.size()) cout << "������������������" << endl; system("pause");



}

void teachercaozuo::kschengji(string a, string b)

{
    system("cls");

    string k;

    int j;

    float ji;

    for (j = 0; j < c.size(); j++)

        if (c[j].getno() == a && c[j].getbanhao() == b)

        {

            cout << "���Ӧ����ѧ�����Գɼ�" << endl;

            cout << "ѧ��\t\t����\t\t���Գɼ�" << endl;

            for (int i = 0; i < c[j].sssn(); i++)

            {
                cout << c[j].getsssnumber(i) << "\t" << c[j].getsssname(i) << "\t\t";

                cin >> ji;

                cout << endl;

                c[j].tianjiaks(c[j].getsssnumber(i), ji);

                t.setkschengji(a, i, ji);

            }break;

        }

    if (j == c.size()) cout << "������������������" << endl; system("pause");

}

void teachercaozuo::save1()

{
    int j, k;

    ofstream outfile("d:\\20164235-course.txt", ios::out);

    if (!outfile) return;

    for (int i = 0; i < c.size(); i++)

    {
        outfile << c[i].getno() << "\t\t" << c[i].getname() << "\t\t" << c[i].getxuefen();

        outfile << "\t\t" << c[i].getnumber() << "\t\t" << c[i].getbanhao() << "\t\t";

        for (k = 0; k < c[i].getn(); k++)

        {

            outfile << c[i].gettime(k) << "\t" << c[i].getwhere(k) << endl;



        }

        outfile << "-1" << endl;

        outfile << c[i].getteacher() << endl;

        outfile << c[i].sssn() << endl;

        if (c[i].sssn() != 0)

        {

            for (j = 0; j < c[i].sssn(); j++)

            {
                outfile << c[i].getsssnumber(j) << "\t" << c[i].getsssname(j) << "\t" << c[i].getsssclas(j);

                outfile << "\t" << c[i].getsssps(j) << "\t" << c[i].getsssks(j) << endl;

            }
        }
    }

    outfile << "-1" << endl;

    outfile.close(); system("cls");

}

void teachercaozuo::displaycourse()

{

    for (int i = 0; i < c.size(); i++)

    {
        cout << "-----------------------------------------------" << endl;

        cout << c[i] << endl;

        cout << "-----------------------------------------------" << endl;

    }

}

void teachercaozuo::xuanze()

{



    int a;

    while (1)

    {

        system("cls");

        t.kebiaodisplay();

        cout << "###################################################################" << endl;

        cout << "   0:                               �˳�" << endl;

        cout << "   1:                               ѡ��" << endl;

        cout << "   2:                               �˿�" << endl;

        cout << "   3:                               ѧ��ѡ�ν�����ɼ�" << endl;

        cout << "   4:                               ��д�ɼ�" << endl;

        cout << "   5:                               ����ѡ�����" << endl;

        cout << "###################################################################" << endl;

        cin >> a;

        if (a == 0) break;

        else if (a == 1) addc();

        else if (a == 2) erasec();

        else if (a == 3)

        {
            string aa, b;

            while (1)

            {
                system("cls");

                cout << "������γ̺źͽ�ѧ���,����-1�˳�" << endl;

                cin >> aa;

                if (aa == "-1") { break; }

                cin >> b;

                if (t.chakecheng(aa, b) == -1) { cout << "������������������" << endl; system("pause"); }

                else t.displaystudent(aa, b);



            }

        }

        else if (a == 4)

        {
            string aa, b; int z;

            while (1)

            {
                system("cls");

                cout << "������Ҫ��д�ɼ��Ŀγ̺źͽ�ѧ���,����-1�˳�" << endl;

                cin >> aa;

                if (aa == "-1") break;

                cin >> b;

                if (t.chakecheng(aa, b) == -1) cout << "������������������" << endl;

                //ma1=ma.find(aa);if(ma1==ma.end()||c[ma[aa]].getbanhao()!=b) {cout<<"������������������"<<endl;system("pause");system("cls");}

                else

                {
                    while (1)

                    {
                        cout << "����ƽʱ�ɼ���1�����뿼�Գɼ���2���˳���-1" << endl;

                        cin >> z;

                        if (z == -1) break;

                        else if (z == 1)

                            pschengji(aa, b);

                        else if (z == 2) kschengji(aa, b);

                    }

                }

                system("pause");
            }

        }

        else if (a == 5) { system("cls"); cout << t << endl; system("pause"); }

    }

}

void teachercaozuo::addc()

{

    string z, hao;

    int i, j, l, tt = 0;

    while (1)

    {
        system("cls");

        displaycourse(); cout << t << endl;

        cout << "��������ѡ�γ̵Ŀγ̺š����,����-1����" << endl;

        cin >> z;

        if (z == "-1") break;

        else {
            cin >> hao;

            if (t.chakechengm(z) != -1) { cout << "��ѡ�����ſγ�" << endl; system("pause"); }

            else {
                for (j = 0; j < c.size(); j++)

                    if (c[j].getno() == z && c[j].getbanhao() == hao) { break; }

                if (j != c.size())

                {

                    if (c[j].getteacher() != "-1") cout << "���н�ʦѡ�˴��ſγ�,������ѡ��" << endl;

                    else {

                        for (i = 0; i < c[j].getn(); i++)

                        {
                            l = c[j].gettime(i);

                            if (t.chake(c[j].gettime(i))) { cout << "ʱ���ͻ" << endl; tt = 1; break; }
                        }

                        if (tt == 0) {

                            //c[j].addstudent(s.getnumber());

                            cout << "ѡ�γɹ�" << endl;

                            c[j].setteacher(t.getname()); t.add(c[j]); cout << c[j] << endl;
                        }
                    }

                    system("pause");

                }

                else {

                    cout << "��������,���������룬����-1����" << endl; system("pause");
                }

            }

        }

    }

}

void teachercaozuo::erasec()

{

    string z;

    while (1)

    {
        system("cls");

        cout << t << endl;

        cout << "���������˿γ̵Ŀγ̺�,����-1����" << endl;

        cin >> z;

        if (z == "-1") break;

        else

        {
            ma1 = ma.find(z);

            if (ma1 != ma.end())

            {

                c[ma1->second].setteacher("-1");

                t.erasee(z);

                //ma.erase(ma1);

                //cout<<"����ѡ�˿γ�"<<endl;

                system("pause");
            }

            else {

                cout << "�γ̺�������������������,����-1����" << endl; system("pause");

            }
        }

    }

}

void teachercaozuo::load1()

{
    fstream filename;
    filename.open("course.txt");
    if (filename)
    {
        c.clear();
        while (!filename.eof())
        {
            string no, name, banhao;
            int number;
            float grade;
            filename >> no >> name >> banhao >> number >> grade;
            course x1(no, name, grade, number, banhao);
            c.push_back(x1);
        }

    }
    else
    {
        cout << "�ļ���ʧ�ܣ�\n";
    }
    filename.close();

    /*course x1;

    int n;

    string m, z, l, a;

    float b, x, y;

    ifstream infile("d:\\20164235-course.txt", ios::in);

    if (!infile) return;

    c.clear();

    while (infile >> x1)

    {
        if (x1.getno() == "-1") break;

        infile >> m;

        x1.setteacher(m);

        infile >> n;

        for (int i = 0; i < n; i++)

        {

            infile >> m >> z >> l >> x >> y;

            x1.addstudent(m, z, l, x, y);

        }

        c.push_back(x1);

        ma.insert(make_pair(x1.getno(), c.size() - 1));

    }

    infile.close(); system("cls");*/

}

class caozuo :public guanli

{

public:

    void menu1();

};

void caozuo::menu1()

{
    load1(); load3(); load2(); system("cls");

    cout << "*******************************************" << endl;

    cout << "             ��ӭʹ��ѡ��ϵͳ" << endl;

    cout << "             �û���¼" << endl;

    string a, b;

    cout << "�����룺" << endl;

    cout << "�û���(ѧ�Ż򹤺�),����-1�˳�" << endl;

    cin >> a;

    if (a != "-1")

    {



        cout << "����(������ȷ)" << endl;

        cin >> b;

        int ttt;

        ttt = qquerystudent(a);//tt==-1���в���ѧ��

        if (ttt != -1)

        {
            cout << "ѧ��" << a << "��½�ɹ�" << endl; system("pause");

            studentcaozuo ss(s[ttt]);

            s[ttt] = ss.A();

            save2();

            //save1();

        }

        else

        {

            ttt = qqueryteacher(a);

            if (ttt != -1) {
                cout << "��ʦ" << a << "��½�ɹ�" << endl; system("pause");

                teachercaozuo tt(t[ttt]);

                t[ttt] = tt.A();

                save3();

                //save1();

            }

            else { cout << "�û�������,����������" << endl; system("pause"); menu1(); }

        }



    }

}

int main()

{

    int a;

    guanli s;

    caozuo ll;

    while (1)

    {
        system("cls");

        cout << "����Ա����1���û���½����0���˳�����-1" << endl;

        cin >> a;

        if (a == 1)

        {
            s.load1();

            s.load3();

            s.load2();

            s.load3();

            s.menu1();

            
        }

        else if (a == -1) break;

        else if (a == 0)

        {

            ll.load1();

            ll.load3();

            ll.load2();

            ll.load3();

            ll.menu1();

            s.save1();

            s.save2();

            s.save3();


        }



    }
    return 0;
}
