#include<iostream>
#include<math.h>
#include<vector>
#include<random>
#include<string>
#include<unordered_map>
#include<algorithm>
#include<cmath>
#include<stack>
#include<fstream>
#include <iomanip>
using namespace std;


template<typename T>
void outToFile(vector<T>result) {
	string filePath = "C:/Users/ma138/Desktop/daan.txt";
	ofstream outFile(filePath);
	if (!outFile.is_open()) {
		std::cerr << "无法打开文件: " << filePath << std::endl;
		return;
	}
	for (int i = 0; i < result.size(); i++) {
		outFile << result[i] << endl;
	}




}



class Createnokh {
public:
	//没有括号没有小数
	vector<string>generateint(int n, int minnum, int maxnum, vector<int>op) {
		string filePath = "C:/Users/ma138/Desktop/timu.txt";
		ofstream outFile(filePath);
		if (!outFile.is_open()) {
			std::cerr << "无法打开文件: " << filePath << std::endl;
		}

		random_device rd;
		mt19937 gen(rd());
		uniform_int_distribution<>firstnum(minnum, maxnum);
		uniform_int_distribution<>secondnum(minnum, maxnum);
		vector<char>allcau({ '+', '-', '*', '/' });
		vector<char>cau;
		for (int i = 0; i < op.size(); i++) {
			cau.push_back(allcau[op[i]]);
		}
		uniform_int_distribution<>fh(0, op.size() - 1);
		vector<string>ans(0);
		int cnt = 0;

		for (int i = 0; i < n;) {
			int t = fh(gen);
			int f = firstnum(gen);
			int s = secondnum(gen);
			string t_ans;
			if (cau[t] == '/') {
				if (s == 0) continue;
				if (f % s == 0) {
					outFile << f << " " << "÷" << " " << s << " = " << endl;
					t_ans = to_string(f / s);
					ans.push_back(t_ans);
					i++;
				}
				else {
					if (f < s)cnt++;
					if (cnt > n / 2 && f < s)swap(f, s);
					outFile << f << " " << "÷" << " " << s << " = " << endl;
					t_ans = to_string(f / s);
					t_ans.append("......");
					t_ans.append(to_string(f % s));
					ans.push_back(t_ans);
					i++;
				}

			}
			else if (cau[t] == '-') {
				if (f - s < 0) {
					outFile << s << " " << cau[t] << " " << f << " = " << endl;
					t_ans = to_string(getansjjc(s, cau[t], f));
					ans.push_back(t_ans);
					i++;
				}
				else {
					outFile << f << " " << cau[t] << " " << s << " = " << endl;
					t_ans = to_string(getansjjc(f, cau[t], s));
					ans.push_back(t_ans);
					i++;
				}

			}
			else if (cau[t] == '*') {

				outFile << f << " " << "×" << " " << s << " = " << endl;
				t_ans = to_string(getansjjc(f, cau[t], s));
				ans.push_back(t_ans);
				i++;
			}
			else {
				outFile << f << " " << "+" << " " << s << " = " << endl;
				t_ans = to_string(getansjjc(f, cau[t], s));
				ans.push_back(t_ans);
				i++;
			}

		}

		return ans;
	}
	//没有括号但是带小数
	vector<float>generatefloat(int n, int minnum, int maxnum, vector<int>op, int xsw) {
		string filePath = "C:/Users/ma138/Desktop/timu.txt";
		ofstream outFile(filePath);
		if (!outFile.is_open()) {
			std::cerr << "无法打开文件: " << filePath << std::endl;
		}

		random_device rd;
		mt19937 gen(rd());
		uniform_real_distribution<>firstnum(minnum, maxnum);
		uniform_real_distribution<>secondnum(minnum, maxnum);
		vector<char>allcau({ '+', '-', '*', '/' });
		vector<char>cau;
		for (int i = 0; i < op.size(); i++) {
			cau.push_back(allcau[op[i]]);
		}
		uniform_int_distribution<>fh(0, op.size() - 1);
		vector<float>ans(0);
		int cnt = 0;
		for (int i = 0; i < n;) {
			int t = fh(gen);
			float f = firstnum(gen);
			float s = secondnum(gen);
			f = roundToPrecision(f, xsw);
			s = roundToPrecision(s, xsw);
			float t_ans;
			if (cau[t] == '/') {
				if (s == 0) continue;
				else {
					outFile << f << " " << "÷" << " " << s << " = " << endl;
					float anschu = roundToPrecision(f / s, xsw);
					ans.push_back(anschu);
					i++;
				}

			}
			else if (cau[t] == '-') {
				if (f - s < 0) {
					outFile << s << " " << cau[t] << " " << f << " = " << endl;
					t_ans = floatans(s, cau[t], f);
					ans.push_back(t_ans);
					i++;
				}
				else {
					outFile << f << " " << cau[t] << " " << s << " = " << endl;
					t_ans = floatans(f, cau[t], s);
					ans.push_back(t_ans);
					i++;
				}

			}
			else if (cau[t] == '*') {

				outFile << f << " " << "×" << " " << s << " = " << endl;
				t_ans = floatans(s, cau[t], f);
				ans.push_back(t_ans);
				i++;


			}
			else {
				outFile << f << " " << "+" << " " << s << " = " << endl;
				t_ans = floatans(s, cau[t], f);
				ans.push_back(t_ans);
				i++;
			}

		}
		outFile.close();

		return ans;
	}



private:
	int getansjjc(int f, char ch, int s) {
		if (ch == '+')return f + s;
		else if (ch == '*')return f * s;
		else if (ch == '-')return f - s;

	}
	float roundToPrecision(float number, int precision) {
		float factor = pow(10.0, precision);
		return round(number * factor) / factor;

	}

	float floatans(float f, char ch, float s) {
		if (ch == '+')return f + s;
		else if (ch == '*')return f * s;
		else if (ch == '-')return (f - s);

	}

};

class Createyoukh {
public:
	//括号不带小数
	vector<int>ObtainKhEq(int n, int minnum, int maxnum, vector<int>op) {
		string filePath = "C:/Users/ma138/Desktop/timu.txt";
		ofstream outFile(filePath);
		if (!outFile.is_open()) {
			std::cerr << "无法打开文件: " << filePath << std::endl;
		}




		random_device rd;
		mt19937 gen(rd());
		uniform_int_distribution<>firstnum(minnum, maxnum);
		uniform_int_distribution<>secondnum(minnum, maxnum);
		uniform_int_distribution<>thirdnum(minnum, maxnum);
		vector<char>allcau({ '+', '-', '*', '/' });
		vector<char>cau;
		for (int i = 0; i < op.size(); i++) {
			cau.push_back(allcau[op[i]]);
		}
		uniform_int_distribution<>fh1(0, op.size() - 1);
		uniform_int_distribution<>fh2(0, op.size() - 1);

		uniform_int_distribution<>khindex(0, 1);


		vector<int>ans(0);
		for (int i = 0; i < n; i++) {
			int t1 = fh1(gen);
			int t2 = fh2(gen);
			int num1 = firstnum(gen);
			int num2 = secondnum(gen);
			int num3 = thirdnum(gen);
			string tstr;
			tstr.push_back(' ');
			string temp = to_string(num1);
			tstr.append(temp);
			tstr.push_back(' ');
			tstr.push_back(cau[t1]);
			tstr.push_back(' ');
			temp = to_string(num2);
			tstr.append(temp);
			tstr.push_back(' ');
			tstr.push_back(cau[t2]);
			tstr.push_back(' ');
			temp = to_string(num3);
			tstr.append(temp);
			tstr.push_back(' ');


			unordered_map<int, vector<int>>hashkh = AddKhAlgorithm(tstr);
			int khlocate = khindex(gen);
			tstr[hashkh[khlocate][0]] = '(';
			tstr[hashkh[khlocate][1]] = ')';

			if (evaluate(tstr) < 0) {
				i--;
				continue;
			}

			outFile << tstr << endl;
			ans.push_back(evaluate(tstr));

		}
		outFile.close();


		return ans;
	}







	//括号带小数
	vector<string>ObtainKhEqfloat(int n, int minnum, int maxnum, vector<int>op, int xsw) {
		string filePath = "C:/Users/ma138/Desktop/timu.txt";
		ofstream outFile(filePath);
		if (!outFile.is_open()) {
			std::cerr << "无法打开文件: " << filePath << std::endl;
		}




		random_device rd;
		mt19937 gen(rd());
		uniform_real_distribution<>firstnum(minnum, maxnum);
		uniform_real_distribution<>secondnum(minnum, maxnum);
		uniform_real_distribution<>thirdnum(minnum, maxnum);
		vector<char>allcau({ '+', '-', '*', '/' });
		vector<char>cau;
		for (int i = 0; i < op.size(); i++) {
			cau.push_back(allcau[op[i]]);
		}
		uniform_int_distribution<>fh1(0, op.size() - 1);
		uniform_int_distribution<>fh2(0, op.size() - 1);


		uniform_int_distribution<>khindex(0, 1);


		vector<string>ans(0);
		for (int i = 0; i < n; i++) {
			int t1 = fh1(gen);
			int t2 = fh2(gen);
			float num1 = firstnum(gen);
			num1 = roundToPrecision(num1, xsw);
			float num2 = secondnum(gen);
			num2 = roundToPrecision(num2, xsw);
			float num3 = thirdnum(gen);
			num3 = roundToPrecision(num3, xsw);
			string tstr;
			tstr.push_back(' ');
			string temp = to_string(num1);
			tstr.append(temp);
			tstr.push_back(' ');
			tstr.push_back(cau[t1]);
			tstr.push_back(' ');
			temp = to_string(num2);
			tstr.append(temp);
			tstr.push_back(' ');
			tstr.push_back(cau[t2]);
			tstr.push_back(' ');
			temp = to_string(num3);
			tstr.append(temp);
			tstr.push_back(' ');

			tstr = retidystr(tstr, xsw);

			unordered_map<int, vector<int>>hashkh = AddKhAlgorithm(tstr);
			int khlocate = khindex(gen);
			tstr[hashkh[khlocate][0]] = '(';
			tstr[hashkh[khlocate][1]] = ')';

			if (evaluate(tstr) < 0) {
				i--;
				continue;
			}
			outFile << tstr << endl;
			ans.push_back(tstr);

		}



		return ans;
	}

	vector<int>GetAnswer(vector<string>train) {
		vector<int>result;
		for (int i = 0; i < train.size(); i++) {
			result.push_back(evaluate(train[i]));
		}
		return result;
	}
	vector<float>GetAnswerfloat(vector<string>train, int xsw) {
		vector<float>result;
		for (int i = 0; i < train.size(); i++) {

			result.push_back(roundToPrecision(evaluate(train[i]), xsw));
		}
		return result;
	}

private:
	unordered_map<int, vector<int>>AddKhAlgorithm(string str) {
		vector<int>kh1 = { 0 };
		vector<int>kh2;
		unordered_map<int, vector<int>>res;
		int cnt = 0;
		for (int i = 0; i < str.size(); i++) {
			if (str[i] == ' ')cnt++;
			if (cnt == 3 && kh2.size() < 1) {
				kh2.push_back(i);
			}
			if (cnt == 4 && kh1.size() < 2) {
				kh1.push_back(i);
			}
		}
		kh2.push_back(str.size() - 1);
		res.insert({ 0, kh1 });
		res.insert({ 1, kh2 });
		return res;


	}
	float roundToPrecision(float number, int precision) {
		float factor = pow(10.0, precision);
		return round(number * factor) / factor;

	}


	//计算不带小数
	int precedence(char op) {
		if (op == '+' || op == '-') return 1;
		if (op == '*' || op == '/') return 2;
		return 0;
	}

	float applyOp(float a, float b, char op) {
		switch (op) {
		case '+': return a + b;
		case '-': return a - b;
		case '*': return a * b;
		case '/':
			if (b == 0) throw std::runtime_error("Cannot divide by zero.");
			return a / b;
		default: return 0;
		}
	}

	float evaluate(const std::string& s) {
		std::stack<float> values;
		std::stack<char> ops;

		for (size_t i = 0; i < s.length(); i++) {
			if (s[i] == ' ') continue;

			if (s[i] == '(') {
				ops.push(s[i]);
			}
			else if (isdigit(s[i]) || s[i] == '.') {
				float value = 0;
				int decimal = 0;
				while (i < s.length() && (isdigit(s[i]) || s[i] == '.')) {
					if (s[i] == '.') {
						decimal = 1;
						i++;
						continue;
					}
					value = value * 10 + (s[i] - '0');
					if (decimal) decimal *= 10;
					i++;
				}
				if (decimal) value /= decimal;
				values.push(value);
				i--;
			}
			else if (s[i] == ')') {
				while (!ops.empty() && ops.top() != '(') {
					float val2 = values.top();
					values.pop();
					float val1 = values.top();
					values.pop();
					char op = ops.top();
					ops.pop();
					values.push(applyOp(val1, val2, op));
				}
				if (!ops.empty()) ops.pop(); // Remove '('
			}
			else {
				while (!ops.empty() && precedence(ops.top()) >= precedence(s[i])) {
					float val2 = values.top();
					values.pop();
					float val1 = values.top();
					values.pop();
					char op = ops.top();
					ops.pop();
					values.push(applyOp(val1, val2, op));
				}
				ops.push(s[i]);
			}
		}

		while (!ops.empty()) {
			float val2 = values.top();
			values.pop();
			float val1 = values.top();
			values.pop();
			char op = ops.top();
			ops.pop();
			values.push(applyOp(val1, val2, op));
		}

		return values.top();
	}

	string retidystr(string str, int xsw) {
		string ans;
		for (int i = 0; i < str.size(); ) {
			if (str[i] != '.') {
				ans.push_back(str[i]);
				i++;
			}
			else {
				ans.push_back(str[i]);
				i++;
				for (int j = 0; j < xsw; j++) {
					ans.push_back(str[i]);
					i++;
				}
				while (1) {
					if (str[i] >= '0' && str[i] <= '9')i++;
					else break;
				}

			}


		}


		return ans;
	}







};




vector<int>unrepeatedop(unordered_map<char, int>hashmap, string str) {
	unordered_map<char, int>unrepop;
	for (int i = 0; i < str.size(); i++) {
		if (hashmap.count(str[i]) == 1)unrepop.insert({ str[i],hashmap[str[i]] });
		else continue;

	}
	vector<int>res;
	for (auto it = unrepop.begin(); it != unrepop.end(); it++) {
		res.push_back(it->second);
	}
	return res;
}//用户输入的运算符字符串去重函数








void CreateResult(int n, int minnum, int maxnum, vector<int>state, vector<int>op) {
	Createnokh CNK;
	Createyoukh CK;


	string statevector;
	statevector.append(to_string(state[3]));
	statevector.append(to_string(state[4]));
	if (statevector.compare("00") == 0) {
		vector<string>rescnk = CNK.generateint(n, minnum, maxnum, op);
		outToFile(rescnk);
	}
	else if (statevector.compare("01") == 0) {
		vector<float>rescnk = CNK.generatefloat(n, minnum, maxnum, op, state[5]);
		outToFile(rescnk);
	}
	else if (statevector.compare("10") == 0) {
		vector<int>resck = CK.ObtainKhEq(n, minnum, maxnum, op);
		outToFile(resck);
	}
	else if (statevector.compare("11") == 0) {
		vector<string>resck = CK.ObtainKhEqfloat(n, minnum, maxnum, op, state[5]);
        vector<float>answer = CK.GetAnswerfloat(resck, state[5]);
		outToFile(answer);
	}



	return;
}




int main() {
	int n = 0;//用户输入的题目数量
	string useroperater;//用户输入的运算符字符串
	int minnum = 0;
	int maxnum = 0;//maxnum和minnum为用户界定的输入数据的范围
	int kh = 0;//是否带括号
	int xs = 0;//是否带小数

	unordered_map<char, int>hashmap;
	hashmap.insert({ '+',0 });
	hashmap.insert({ '-',1 });
	hashmap.insert({ '*',2 });
	hashmap.insert({ '/',3 });

	vector<int>statecau(6);//四则运算状态寄存器 0:n；1:min；2:max；3:是否有括号；4:是否有小数；5:小数点的位数 
	cout << "请输入题目的个数：";
	cin >> n;
	cin.ignore();
	cout << endl;
	statecau[0] = n;


	cout << "请输入需要生成的算式所包含的运算符：";
	string op;
	getline(cin, op);
	cout << endl;
	vector<int>relop = unrepeatedop(hashmap, op);


	cout << "请输入算式中数据的最小值：";
	cin >> minnum;
	cout << endl;
	statecau[1] = minnum;


	cout << "请输入算式中数据的最大值：";
	cin >> maxnum;
	cout << endl;
	statecau[2] = maxnum;


	cout << "请输入是否带括号（带括号输入1，不带括号输入0）：";
	cin >> kh;
	cout << endl;
	statecau[3] = kh;



	cout << "请输入是否带小数（带小数输入1，不带小数输入0）：";
	cin >> xs;
	cout << endl;
	statecau[4] = xs;
	if (xs == 1) {
		cout << "请输入您所需要的小数点的位数：";
		int xsw = 0;
		cin >> xsw;
		statecau[5] = xsw;
		cout << endl;
	}
	else statecau[5] = 0;




	CreateResult(n, minnum, maxnum, statecau, relop);




	return 0;
}
