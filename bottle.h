#include<iostream>
#include<vector>
using namespace std;
class bottle{//�s�y�~�l 
	private:
		vector<char> cap;
		int flag;
	public:
		bottle();
		bottle(char);
		void set_color(int);
		void allpop();
		int get_flag();
		char get(int);
		void push(int,char);
        void pop(int);
		int size();
		void showbady(int);
		int samecolor();
};
namespace b{
	vector<bottle> t;//�Ų~�l
	vector<bottle> color;//�j�~�l 
	bottle te,bt;//�@���p�~�l�M�j�~�l���w�]�Ŷ� 
}
