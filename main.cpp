#include"function.h"
#include<iostream>
#include<cstdlib>
#include<vector>
#include<iomanip>
#include<windows.h> 
#include<ctime>
#include<conio.h>
using namespace std;
/*
�@��:�d�A�� 
��J: �L 
��X: �~�l�ˤ��C�� 
�\��: �Q�ΩI�s�Ҳժ���ơA�����@��Ӳ~�l�ˤ��C�����t�� 
�ϥμҲ�:function.h�H�Ψ�L�禡�w 
*/
int main(){
	system("mode con cols=100 lines=35");//����x�e��
	srand(time(0));// srand��ƬO�H���ƥͦ�������l�ƨ�ơA�`�ήɶ�(���)�@���ؤl
	welcometogame();
	while(1){//�ˤ�
		input();
		if(de_ch()==1){
			system("cls");
			startup();
			continue;
		}
		outinput();
		if(de_end()==1){//�Ҧ��~�l����z�n�F 
			endgame();//�L�� 
		}
	}
	return 0;
}
