#include "a.h" 
#include "function.h"
#include "bottle.h"
#include<iostream>
#include<cstdlib>
#include<vector>
#include<iomanip>
#include<windows.h> 
#include<ctime>
#include<conio.h>
using namespace std;
using namespace a;
using namespace b;
/*
�@��:�i�Ůp 
��J:�L 
��X:�L 
�\��:�̰�¦���غc�l 
*/
bottle::bottle(){};
/* 
�@��:�i�Ůp
��J:�L 
��X:�L 
�\��:�إ�10�ӬҬ�c����� 
*/ 
bottle::bottle(char c)
{//�j�~�l 
	for(int i=0;i<10;i++)
	cap.push_back(c);
}
/* 
�@��:�i�Ůp
��J:�L 
��X:�L 
�\��:�إ�10�ӬҬ�(a+'A')�r������� 
*/ 
void bottle::set_color(int a)
{
	for(int i=0;i<10;i++)
	cap.push_back(char(a+'A'));
}
/* 
�@��:�i�Ůp
��J:�L 
��X:�L 
�\��:�N�~�l���e���M�� 
*/ 
void bottle::allpop()
{
	cap.clear();
}

/* 
�@��:�i�Ůp
��J:�L 
��X:�L 
�\��:�^��flag���� 
*/ 
int bottle::get_flag()
{
	return flag;
}
/* 
�@��:�i�Ůp
��J:�L 
��X:�L 
�\��:�^��cap[a]
*/ 
char bottle::get(int a)
{
	return cap[a];
}
/* 
�@��:�i�Ůp
��J:�L 
��X:�L 
�\��:�Na��c�r����icap 
*/ 
void bottle::push(int a,char c)
{//��i�P�@�C��() 
	for(int i=0;i<a;i++)
	cap.push_back(c);
}
/* 
�@��:�}���v
��J:�L 
��X:�L 
�\��:�Ncap[]�ᱼa�Ӹ�� 
*/ 
void bottle::pop(int a)
{
    for(int i=0;i<a;i++)
    cap.pop_back();
}
/* 
�@��:�\��
��J:�L 
��X:�L 
�\��:�^��cap[]��Ƽ� 
*/ 
int bottle::size()
{ 
	return cap.size();
}
/* 
�@��:�\�� 
��J:�L 
��X:size(),a,O or X,cap�̨C�Ӹ�ƪ��r�� 
�\��:���ϥΪ̬ݨ�~�l���s�� �e�q �O�_�F���L������ �H�Τ��e���o�C�� 
*/ 
void bottle::showbady(int a)
{//��X�~��  ����C��q�M���A 
	int b=1;
	col(15);
	gotoxy((a+1)*4-1,20);
	cout<<size();
	gotoxy((a+1)*4-1,16);
	cout<<a;
	if(cap.size()==5)
	{
		for(int i=0;i<4;i++)
		{//�P�_�O�_�������B�ҦP�� 
			if(cap[i]==cap[i+1])
			b++;
			else
			break;
		}
		gotoxy((a+1)*4-1,19);
		if(b==5)
		{
			gotoxy((a+1)*4-1,18);
			flag=1;
			cout<<"O";
		}
	}
	else if(cap.size()==0)
	{
		gotoxy((a+1)*4-1,18);
		flag=1;
		cout<<"O";
	}
	else
	{
		gotoxy((a+1)*4-1,18);
		flag=0;
		cout<<"X";
	}
			
	for(int i=0;i<cap.size();i++)
	{
		gotoxy((a)*4+2,15-i);
		col((int(cap[i])-'A'+1)*16);
		cout<<" "<<cap[i]<<" ";
		col(15);
	}
}
/* 
�@��:�\��
��J:�L 
��X:�L 
�\��:�^�ǲ~�l�q�W��U�C��ۦP�B�۾F���Ӽ� 
*/ 
int bottle::samecolor()
{//�����ۦP�C��Ӽ� 
	int n=1;
	for(int i=cap.size()-1;i>0;i--)
	{
		if(cap[i]==cap[i-1])
		n++;
		else
		break;
	}
	return n;
}
/* 
�@��:�d�A�� 
��J: �L 
��X: �L 
�\��:���ô�� 
*/ 

/*
�@��:�\��
��J:c
��X:�L 
�\��:����п�X���C���C��
*/
int col(int c){
 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),c);//����r�C��
  return 0;
}
/*
�@��:�d�A�� 
��J:x,y
��X:�L 
�\��:�]�w��Юy�� 
*/
void gotoxy(int x,int y){
  COORD c;
  c.X=x;
  c.Y=y; 
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
}

/* 
�@��:�\��
��J: �L 
��X: �L 
�\��:���ô�� 
*/ 
void HideCursor()
{
	CONSOLE_CURSOR_INFO cursor_info={1,0};//�ĤG�ӭȬ��s=���ô��
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE),&cursor_info); 
}
/* 
�@��:�d�A�� 
��J: �L 
��X: �L 
�\��:�^�ǽd���H���� 
*/ 
int random(int M,int m){
	return (M-m)*rand()/(RAND_MAX+1.0)+m;
}
/* 
�@��:�d�A�� 
��J:n
��X:��椶�� 
�\��:�C����椶�� ��J1:�C���}�l ��J3:��X�I�s���� ��J4:�h�X�C�� 
*/ 
void welcometogame(){ 
	HideCursor();
	char n;
    col(14);
	gotoxy(42,10);
	cout<<"�~�l�C��";
	col(240);
	gotoxy(31,13);
	cout<<" 1.START ";
	gotoxy(51,13);
    cout<<" 2.DOD ";
	gotoxy(31,15);
    cout<<" 3.Explation ";
	gotoxy(51,15);
	cout<<" 4.END ";
	n=getch();
	
	
	switch(n){
	 	case '1':
	 		col(144);
			gotoxy(31,13);
			cout<<" 1.START ";
	 		break;
	 	case '2': 
	 		col(144);
			gotoxy(51,13);
    		cout<<" 2.DOD ";
			break;
	 	case '3':
	 		col(144);
	 		gotoxy(31,15);
    		cout<<" 3.Explation ";
	 		break;
		case '4':
			col(144);
			gotoxy(51,15);
			cout<<" 4.END ";
	 		break;
	default:
		col(12);
		gotoxy(40,18);
		cout<<"��J1��4���Ʀr";
		_getch();//��J���N��
		system("cls");//�M��
	    welcometogame();
	}
	char enter;
	bool de=1;
	while(de){
		col(10);
		gotoxy(34,18);
		cout<<"�I��Enter�T�{  Esc����";
		enter=getch();
		if(enter==13){
			de=0;
		}
		if(enter==27){
			col(7);
			system("cls");
			welcometogame();
			break;
		} 
	}
	

	
	
	
	
	
	if((enter==13)&&(de==0)){
	switch(n){
	 	case '1':
	 		system("cls");
			change();
	 		break;
	 	case '2': 
			system("cls");
			dod();
			break;
	 	case '3':
	 		explation();
	 		break;
		case '4':
			system("cls");
	 		col(10);
	 		gotoxy(30,10);
	 		cout<<"�P�±z���C��";
	 		
	 		Sleep(1000);
	 		system("cls");
	 		gotoxy(30,10);
	 		cout<<"���ݱz�U�������";
	 		
	 		Sleep(1000);
	 		system("cls");
	 		col(10);
	 		gotoxy(30,10);
	 		cout<<"�A�|!!!!";
	 		Sleep(1000);
	 		system("cls");
	 		exit(0);
	 		break;
	}
	}
	col(7);
}
/* 
�@��:�d�A�� 
��J:n
��X:�����פ��� 
�\��:��������סA��J1~3�C��JEsc:��^��� 
*/ 
void dod(){
	col(14);
	gotoxy(42,10);
	cout<<"���������";
	col(11);
	gotoxy(22,13);
	cout<<"1.NORMAL";
	col(13);
	gotoxy(44,13);
    cout<<"2.HARD";
	col(12);
	gotoxy(62,13);
	cout<<"3.EXTREME";
	col(10);
	gotoxy(45,16);
	cout<<"��^";
	char n;
	n=getch();
	 
	 switch(n){
	 	case '1':
	 		big=(rand()%5)+1;
	 		small=(rand()%8)+(big*2+5);
	 		break;
	 	case '2':
	 		big=(rand()%5)+6;
	 		small=(rand()%2)+(big*2+2);
	 		break;
	 	case '3':
	 		big=(rand()%5)+11;
	 		small=big*2+1;
	 		break;
	 	case 27:
	 		system("cls");
	 		welcometogame();
	 		break;
	default:
		col(12);
		gotoxy(40,28);
		cout<<"��J1��3���Ʀr";
		_getch();//��J���N��
		system("cls");//�M��
	    dod();
	}
	system("cls");
	startup();
}
/* 
�@��:�d�A�� 
��J:�L 
��X:�������� 
�\��:��¿�X����  �H�K��(�O��������)��h�^��� 
*/ 
void explation(){ 
	int i,j=1;
	system("cls");
	col(10);
	gotoxy(35,1);
	cout<<"����";
	col(2);
  
  for(i=18;i<=55;i++){
  	for(j=3;j<=25;j++){
  		gotoxy(i,j);
  	if(i==18||i==55){
  		cout<<"=";
  	}
  	else if(j==3||j==25){
  		cout<<"||";
	}
  }
  }
  col(6);
  gotoxy(20,5);
  cout<<"1.�~�l���U��ܪ��Ʀr���s��";
  col(10);
  gotoxy(20,8);
  cout<<"2.�~�l���U��ܪ�O�������AX��������";
  col(14);
  gotoxy(20,11);
  cout<<"3.��JA!B�i�~�P�AAB�����N���";
  col(8);
  gotoxy(20,14);
  cout<<"���z���o�r��!!!";
  col(7);
  gotoxy(22,17);
  cout<<"/*****�����N���^�D����*****/";
  _getch();
  system("cls");
  welcometogame();  
}
/* 
�@��:�\��
��J:big,small
��X: �L 
�\��:input big and small�A��J�����I�s�O����� 
*/ 
void change(){
	cout<<"��J�C���:";
	cin>>big;
	cout<<"��J�j�~�l�Ӽ�(>"<<big*2<<"):";
	cin>>small;
	while(small<=(big*2)){
		cout<<"ERROR!!!  �Э��s��J:";
		cin>>small;
	}
	system("cls");
	startup();
}
/* 
�@��:�\��
��J:�L 
��X:�L 
�\��:�ͦ��j�~�l�p�~�l�A����j�~�l�H�����t�C�⵹�p�~�l 
*/ 
void startup(){
	for(int i=0;i<small;i++){//�s�y�Ų~�l 
		t.push_back(te);
	}
	for(int i=0;i<big;i++){//�s�y�j�~�l 
		bt.set_color(i);
		color.push_back(bt);
		bt.allpop();
	}
	int num=1;
	system("mode con cols=140 lines=35");
	temp2=1;
	while(num>0){//����j�~�l���O�Ū� 
		num=0;
		
		for(int i=0;i<big;i++){
		if(color[i].size()>0){
		temp1=random(small,0);//�Ų~�s�� 
		
		while((temp2+t[temp1].size())>5){
			temp1=random(small,0);
		}
		t[temp1].push(temp2,color[i].get(color[i].size()-1));
		color[i].pop(temp2);
		num+=1;
		for(int j=0;j<small;j++){
		t[j].showbady(j);
		}
		Sleep(50);
		}
		
		}
	}
	color.clear();
	
}
/* 
�@��:�}���v 
��J:temp1,ch,temp2 
��X:
�\��:��¿�J 
*/ 
void input(){
	pass=0;
	gotoxy(4,22);
	col(14);
	cout<<"input A to B(A-B):";
	cin>>temp1>>ch>>temp2;
	if(ch=='!'){
	}
	else {
		while((ch!='-')||(temp1>small-1)||(temp2>small-1)||(t[temp1].samecolor()+t[temp2].size()>5)){//�s�����i�W�L�~�l�`��-1     ���i�˹L�h��overflow(�W�L�e�q) 
			cout<<"ERROR!!!"<<endl<<"�Э��s��J:";
			cin>>temp1>>ch>>temp2;
	}
	}
}
/* 
�@��:�}���v
��J:�L 
��X:�L 
�\��:�ˤ����A�I�sshowbady������� 
*/ 
void outinput(){
	t[temp2].push(t[temp1].samecolor(),t[temp1].get(t[temp1].size()-1));//�NA�W���ۦP���C����B    t[temp2].push(A�W���ۦP���C��,A�̤W�����r��) 
	t[temp1].pop(t[temp1].samecolor());//�NA�W���@�˪��r����X 
	system("cls");
	for(int j=0;j<small;j++){//��ܥ᧹�����G 
		t[j].showbady(j);
		if(t[j].get_flag()==1){//�P�_�O�_�~�l�O�Ū��A�Υ����B�P�@�C�� 
			pass++;
		}
	}
}
/* 
�@��:�}���v
��J: n
��X: �L���e�� 
�\��:��X�L���e����A�I�swelcometogame��� 
*/ 
void endgame(){//�����e�� 
	col(7);
 	system("cls");
 	col(6);
 	gotoxy(35,12);
 	cout<<"���߹L��!!!";
 	Sleep(1000);
 	system("cls");
 	col(6);
 	gotoxy(35,12);
 	cout<<"�аݬO�_�~��C��";
 	gotoxy(33,16);
 	col(12);
 	cout<<"1.�_";
 	col(11);
 	gotoxy(49,16);
 	cout<<"2.�O";
 	char n;
 	n=getch();
 	switch(n){
 		case '1':
 			system("cls");
	 		col(10);
	 		gotoxy(37,12);
	 		cout<<"�P�±z���C��";
	 		
	 		Sleep(1000);
	 		system("cls");
	 		gotoxy(35,12);
	 		cout<<"���ݱz�U�������";
	 		
	 		Sleep(1000);
	 		system("cls");
	 		col(10);
	 		gotoxy(49,12);
	 		cout<<"�A�|!!!!";
	 		Sleep(1000);
	 		system("cls");
	 		exit(0);
	 		break;
	 	case '2':
	 		system("cls");
	 		welcometogame();
	 		break;
	}
 	
}
/* 
�@��:�}���v
��J: �L 
��X: �L 
�\��:�P�_ch�O�_��!�A�O���ܡA�Nt�M�Ũæ^��1�A�_�h�u�^��0 
*/ 
int de_ch(){
	if(ch=='!'){
		t.clear();
		return 1;
	}
	else{
		return 0;
	}
}
/* 
�@��:�}���v
��J: �L 
��X: �L 
�\��:�P�_pass�O�_����small�A�O���ܡA�Nt�M�Ũæ^��1�A�_�h�u�^��0 
*/ 
int de_end(){
	if(pass==small){
		t.clear();
		return 1;
	}
	else{
		return 0;
	}
}
