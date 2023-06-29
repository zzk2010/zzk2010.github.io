#include "date.h"
using namespace std;
struct node {
	string a, m;
	int lst, all, t;
	bool ok;
};
int n, ad, ly, lm, ld, gd;
char op;
node words[1000005];
bool cmp(node a, node b) {
	if (a.ok != b.ok) return a.ok < b.ok;
	if (a.t != b.t) return a.t > b.t;
	if (a.lst != b.lst) return a.lst > b.lst;
	if (a.all != b.all) return a.all > b.all;
	return a.a < b.a;
}
void init() {
	tim tmp = gettime();
	freopen("words.txt", "r", stdin);
	cin >> ly >> lm >> ld;
	if (ly == -1) ly = tmp.y, lm = tmp.m, ld = tmp.d;
	gd = gap(ly, lm, ld, tmp.y, tmp.m, tmp.d);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> words[i].a >> words[i].m >> words[i].lst >> words[i].all >> words[i].t >> words[i].ok;
		words[i].lst += gd;
		words[i].all += gd;
	}
	freopen("words.txt", "w", stdout);
	cout << tmp.y << ' ' << tmp.m << ' ' << tmp.d << '\n';
	cout << n << '\n';
	sort(words+1, words+n+1, cmp);
	for (int i = 1; i <= n; i++) cout << words[i].a << ' ' << words[i].m << ' ' << words[i].lst << ' ' << words[i].all << ' ' << words[i].t << ' ' << words[i].ok << '\n';
	freopen("CON", "w", stdout);
	freopen("CON", "r", stdin);
	cin.clear();
	cout.clear();
	return;
}
void add() {
	string New, Mean;
	cout << "请输入您要添加的单词（一行一个，单词+意思，结束时另起一行输入“结束”）：\n";
	while (cin >> New) {
		if (New == "结束") break;
		cin >> Mean;
		words[++n].a = New;
		words[n].m = Mean;
		words[n].all = words[n].lst = words[n].t = 0;
	}
	freopen("words.txt", "w", stdout);
	cout << ly << ' ' << lm << ' ' << ld << '\n';
	cout << n << '\n';
	sort(words+1, words+n+1, cmp);
	for (int i = 1; i <= n; i++) cout << words[i].a << ' ' << words[i].m << ' ' << words[i].lst << ' ' << words[i].all << ' ' << words[i].t << ' ' << words[i].ok << '\n';
	cout.clear();
	freopen("CON", "w", stdout);
	cout << "添加成功！\n\n"; 
	return;
}
void learn() {
	int cnt = 0, cnt1 = 0, cnt2 = 0;
	double be = time(0), en;
	for (int i = 1, know; i <= n; i++) {
		if (words[i].ok) continue;
		++cnt;
		words[i].t++;
		cout << "\n			" << words[i].a << '\n';
		cout << "你认识这个单词吗？  1.认识   2.不认识   3.退出背词模式\n";
		cin >> know;
		if (know == 1) {
			cout << "你真棒！\n";
			words[i].ok = 1;
			++cnt1;
		}
		else if (know == 2) {
			words[i].ok = 0;
			cout << words[i].a << "的意思是：" << words[i].m << '\n';
			++cnt2;
		}
		else if (know == 3) {
			goto label;
		}
		else {
			while (know != 1 && know != 2) {
				cout << "输入错误，请重试：\n";
				cin >> op;
			}
		}
	}
	en = time(0);
label:
	if (!cnt) {
		cout << "词库里还没有生词哦，快去添加吧！\n";
		return;
	}
	cout << "\n这轮学习总共用时" << en-be << "秒，总共认识了" << cnt1 << "个生词，还剩" << cnt2 << "个生词。\n";
	freopen("words.txt", "w", stdout);
	cout << ly << ' ' << lm << ' ' << ld << '\n';
	cout << n << '\n';
	for (int i = 1; i <= n; i++) cout << words[i].a << ' ' << words[i].m << ' ' << words[i].lst << ' ' << words[i].all << ' ' << words[i].t << ' ' << words[i].ok << '\n';
	cout.clear();
	freopen("CON", "w", stdout);
	return;
}
void print() {
	if (!n) {
		cout << "词库里还没有词哦，快去添加吧！\n";
		return;
	}
	cout << "词库中共有" << n << "个词：\n";
	for (int i = 1; i <= n; i++) cout << i << "." << words[i].a << ' ' << words[i].m << '\n';
	return;
}
void printsheng() {
	int sheng = 0;
	for (int i = 1; i <= n; i++) sheng += (!words[i].ok);
	if (!sheng) cout << "生词有" << sheng << "个！\n";
	else cout << "生词有" << sheng << "个：\n";
	for (int i = 1, tmp = 0; i <= n; i++) {
		if (!words[i].ok) {
			cout << ++tmp << "." << words[i].a << ' ' << words[i].m << '\n';
		}
	}
	return;
}
int work() {
	init();
	cout << "\n请问您想进行哪项操作？\n1.添加生词    2.背单词    3.查看词库   4.查看生词   5.退出\n";
	cin >> op;
	while (op < '1' || op > '5') {
		cout << "输入错误，请重试：\n";
		cin >> op;
	}
	switch(op) {
		case '1': add(); break;
		case '2': learn(); break;
		case '3': print(); break;
		case '4': printsheng(); break;
		case '5': return 0; break;
	}
	return 1;
}
int main() {
	cout << "=================================\n";
	cout << "欢迎使用英语背词！\n";
	cout << "Copyright: 赵泽恺  2023-2023\n版权所有，特此声明。\n\n";
	while (work());
	cout << "\n感谢您的使用！\n";
	return 0;
}
