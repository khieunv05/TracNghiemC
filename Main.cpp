#include<graphics.h>
#include<iostream>
#include<string>
#include<cstdlib>
#include<ctime>
#include<fstream>
#include<vector>
#include<windows.h>
#include "GiaoDien.cpp"
#include "BamChuot.cpp"
#include "xoa.cpp"
string TEXTNAME="mvl.txt";
string processName = "lichon.exe";
string FILENAME = "questions.txt";
string FILENAME2 = "khoaHocTuNhien.txt";
string FILENAME3 = "khoaHocXaHoi.txt";
string FILENAME4 = "ngoaiNgu.txt";
string FILEREAD = "";
//settextstyle(Kieu chu,huong chu,Co chu) (dieu chinh chu)
//outtextxy(vi tri x,vi tri y,text se in ra) (in chu)
//rectangle(x1,y1,x2,y2) (in ra hinh chu nhat theo toa do)
//setfillstyle(SOLID_FILL,mau) (to mau va thuong di cung voi bar de xac dinh vung can to)
//bar(x1,y1,x2,y2) (xac dinh vung to mau)
//ismouseclick(WM_LBUTTONDOWN) (kiem tra xem co duoc bam chuot trai chua) (khong clear trang thai cua chuot)
//getmouseclick(WM_LBUTTONDOWN,x1,y1) (Lay vi tri chuot trai vua bam vao 2 bien x1,y1)
using namespace std;
bool isFileEmpty(string &fileName){
	ifstream file(fileName,ios::ate);
	return file.tellg()==0;
}
void ChucNangLuaChonChuDe(int &chuDe){
	int x1,y1;
	GiaoDien giaoDien;
	BamChuot bamChuot;
	giaoDien.ManHinhLuaChonChuDe();
	while(true){
		getmouseclick(WM_LBUTTONDOWN,x1,y1);
		if(bamChuot.BamChuotManHinhLuaChonChuDe(x1,y1)) break;
		delay(10);
	}
	if((x1>=280 && x1<=1000) && (y1 >= 290 && y1<=390)){
		chuDe = 1;
	}
	if((x1>=280 && x1<=1000) && (y1 >= 490 && y1<=590)){
		chuDe = 2;
	}
	if((x1>=280 && x1<=1000) && (y1 >= 690 && y1<=790)){
		chuDe = 3;
	}
}
void ChucNangSuaCauHoi(int &hienthi,int &chuDe){
	GiaoDien giaoDien;
	bool suaCauHoi=0;
	string cauHoi,cauTraLoi,luaChonA,luaChonB,luaChonC,luaChonD;
	int dapAn;
	char ch;
	int x1,y1;
	cleardevice();
	BamChuot bamChuot;
	string line;
	vector<QA> listQA;
	int heSo=0;
	if(chuDe == 1) FILEREAD = FILENAME2;
	else if(chuDe == 2) FILEREAD = FILENAME3;
	else FILEREAD = FILENAME4;
	ifstream inFile(FILEREAD);
	while(getline(inFile,line)){
		QA a;
		a.setQuestion(line);
		getline(inFile,line);
		a.setAnswer(line);
		getline(inFile,line);
		a.setChoiceA(line);
		getline(inFile,line);
		a.setChoiceB(line);
		getline(inFile,line);
		a.setChoiceC(line);
		getline(inFile,line);
		a.setChoiceD(line);
		listQA.push_back(a);
	}
	inFile.close();
	setfillstyle(SOLID_FILL,WHITE);
	bar(0,0,getmaxx(),getmaxy());
	setbkcolor(LIGHTGRAY);
	setcolor(BLACK);
	for(int i =0;i<listQA.size();i++){
		int j = i%5;
		setfillstyle(SOLID_FILL,LIGHTGRAY);
		bar(290,190+j*100,1200,190+50+j*100);
		outtextxy(300,200+j*100,const_cast<char *>( listQA[i].getQuestion().c_str()));
		rectangle(290,190+j*100,1200,190+50+j*100);
		if((((i%4 ==0 && i<=4 ) || (i%5==4 && i>5) )&& (i!=0)) || (i == listQA.size()-1)){
			giaoDien.ManHinhSuaCauHoi();
			setfillstyle(SOLID_FILL,BLUE);
			bar(getmaxx()-150,getmaxy()-100,getmaxx()-70,getmaxy()-50);
			bar(40,getmaxy()-100,110,getmaxy()-50);
			outtextxy(getmaxx()-140,800,(char *)"->");
			outtextxy(40,800,(char*)"<-");
			while(true){
				getmouseclick(WM_LBUTTONDOWN,x1,y1);
				if(bamChuot.BamChuotManHinhSuaCauHoi(x1,y1))break;
				delay(10);
			}
			setbkcolor(WHITE);
			cleardevice();
			setbkcolor(LIGHTGRAY);
			if(((x1>=getmaxx()-150 && x1<=getmaxx()-70) && (y1>=getmaxy()-100 && y1<=getmaxy()-50))){
				heSo=heSo+5;
				continue;
			}
			if(((x1>=40 && x1<=110) && (y1>=getmaxy()-100 && y1<=getmaxy()-50))){
				if(heSo-5<0) heSo =0;
				else	heSo=heSo-5;
				if((i-5) % 5 !=0){
					int m = (i-5)/5;
					i = m*5;
					i = i-1;
				}
				else{
					i = i-6;
				}
				continue;
			}
			if(((x1>=0 && x1<=150) && (y1>=0 && y1<=150))){
				hienthi=1;
				break;	
			}
			int k = (y1-150)/100+heSo;
			if(k>=listQA.size()) {
				int heSo2 = i/5;
				i = heSo2*5-1;
				continue;
			}
			giaoDien.ManHinhMenuSuaCauHoi(listQA[k].getQuestion(),listQA[k].getChoiceA(),
			listQA[k].getChoiceB(),listQA[k].getChoiceC(),listQA[k].getChoiceD());
			cauHoi=listQA[k].getQuestion();
			cauTraLoi=listQA[k].getAnswer();
			luaChonA=listQA[k].getChoiceA();
			luaChonB=listQA[k].getChoiceB();
			luaChonC=listQA[k].getChoiceC();
			luaChonD=listQA[k].getChoiceD();
			int heSo2 = i/5;
			i = heSo2*5-1;
//			heSo = heSo+5;
			while(true){
				
			getmouseclick(WM_LBUTTONDOWN,x1,y1);
				if(listQA[k].getAnswer()==listQA[k].getChoiceA()){
					setfillstyle(SOLID_FILL,GREEN);
					bar(1120,300,1330,400);
					dapAn=1;
				}
				if(listQA[k].getAnswer()==listQA[k].getChoiceB()){
					setfillstyle(SOLID_FILL,GREEN);
					bar(1120,430,1330,530);
					dapAn=2;
					}
				if(listQA[k].getAnswer()==listQA[k].getChoiceC()){
					setfillstyle(SOLID_FILL,GREEN);
					bar(1120,560,1330,660);
					dapAn=3;
					}
				if(listQA[k].getAnswer()==listQA[k].getChoiceD()){
					setfillstyle(SOLID_FILL,GREEN);
					bar(1120,690,1330,790);
					dapAn=4;
					}
				if((x1>=100 && x1<=900) && (y1>=170 && y1<=270)){
				setfillstyle(SOLID_FILL,GREEN);
				bar(100,170,900,270);
				outtextxy(110,180,const_cast<char*>(listQA[k].getQuestion().c_str()));
				
			}
			
				if((x1>=150 && x1<=850) && (y1>=300 && y1<=400)){
					setfillstyle(SOLID_FILL,GREEN);
					bar(150,300,850,400);
					outtextxy(160,310,const_cast<char*>(listQA[k].getChoiceA().c_str()));
				}
				if((x1>=150 && x1<=850) && (y1>=430 && y1<=530)){
					setfillstyle(SOLID_FILL,GREEN);
					bar(150,430,850,530);
					outtextxy(160,440,const_cast<char*>(listQA[k].getChoiceB().c_str()));
				}
				if((x1>=150 && x1<=850) && (y1>=560 && y1<=660)){
					setfillstyle(SOLID_FILL,GREEN);
					bar(150,560,850,660);
					outtextxy(160,570,const_cast<char*>(listQA[k].getChoiceC().c_str()));
				}
				if((x1>=150 && x1<=850) && (y1>=690 && y1<=790)){
					setfillstyle(SOLID_FILL,GREEN);
					bar(150,690,850,790);
					outtextxy(160,700,const_cast<char*>(listQA[k].getChoiceD().c_str()));
				}
				if(bamChuot.BamChuotMenuThemCauHoi(x1,y1)) break;
				delay(10);
			}
			while(true){
				if((x1>=100 && x1<=900) && (y1>=170 && y1<=270)){
					while(!kbhit()) delay(10);
					if(kbhit()){
						ch=getch();
						if(ch==13) 	{
							clearmouseclick(WM_LBUTTONDOWN);
							setfillstyle(SOLID_FILL,LIGHTGRAY);
							bar(100,170,900,270);
							rectangle(100,170,900,270);
							outtextxy(110,180,const_cast<char*>(listQA[k].getQuestion().c_str()));
							while(true){
								getmouseclick(WM_LBUTTONDOWN,x1,y1);
								if(bamChuot.BamChuotMenuThemCauHoi(x1,y1)) break;
									delay(10);
			}
						}
						else if(ch==8){
							string question =listQA[k].getQuestion();
							question.pop_back(); 
							if(!listQA[k].getQuestion().empty()) listQA[k].setQuestion(question);
						}
						else listQA[k].setQuestion(listQA[k].getQuestion()+ch);
					}
				}
				else if((x1>=150 && x1<=850) && (y1>=300 && y1<=400)){
					while(!kbhit()) delay(10);
					if(kbhit()){
						ch=getch();
							if(ch==13) 	{
								setfillstyle(SOLID_FILL,LIGHTGRAY);
								bar(150,300,850,400);
								rectangle(150,300,850,400);
								outtextxy(160,310,const_cast<char*>(listQA[k].getChoiceA().c_str()));
								while(true){
									getmouseclick(WM_LBUTTONDOWN,x1,y1);
									if(bamChuot.BamChuotMenuThemCauHoi(x1,y1)) break;
									delay(10);
			}
							}
						
							else if(ch==8){
								string cA =listQA[k].getChoiceA();
								cA.pop_back(); 
								if(!listQA[k].getChoiceA().empty()) listQA[k].setChoiceA(cA);
						}
						else listQA[k].setChoiceA(listQA[k].getChoiceA()+ch);
					}
					}
				else if((x1>=150 && x1<=850) && (y1>=430 && y1<=530)){
					while(!kbhit()) delay(10);
					if(kbhit()){
						ch=getch();
							if(ch==13) {
								setfillstyle(SOLID_FILL,LIGHTGRAY);
								bar(150,430,850,530);
								rectangle(150,430,850,530);
								outtextxy(160,440,const_cast<char*>(listQA[k].getChoiceB().c_str()));
								while(true){
									getmouseclick(WM_LBUTTONDOWN,x1,y1);
									if(bamChuot.BamChuotMenuThemCauHoi(x1,y1)) break;
									delay(10);
			}
							}
						else if(ch==8){
							string cB =listQA[k].getChoiceB();
							cB.pop_back(); 
							if(!listQA[k].getChoiceB().empty()) listQA[k].setChoiceB(cB);
						}
						else listQA[k].setChoiceB(listQA[k].getChoiceB()+ch);
					}
				}
				else if((x1>=150 && x1<=850) && (y1>=560 && y1<=660)){
					while(!kbhit()) delay(10);
					if(kbhit()){
						ch=getch();
							if(ch==13) {
								setfillstyle(SOLID_FILL,LIGHTGRAY);
								bar(150,560,850,660);
								rectangle(150,560,850,660);
								outtextxy(160,570,const_cast<char*>(listQA[k].getChoiceC().c_str()));
								while(true){
									getmouseclick(WM_LBUTTONDOWN,x1,y1);
									if(bamChuot.BamChuotMenuThemCauHoi(x1,y1)) break;
									delay(10);
			}
							}
						
						else if(ch==8){
							string cC =listQA[k].getChoiceC();
							cC.pop_back(); 
							if(!listQA[k].getChoiceC().empty()) listQA[k].setChoiceC(cC);
						}
						else listQA[k].setChoiceC(listQA[k].getChoiceC()+ch);
					}
					}
				else if((x1>=150 && x1<=850) && (y1>=690 && y1<=790)){
					while(!kbhit()) delay(10);
					if(kbhit()){
						ch=getch();
							if(ch==13) {
								setfillstyle(SOLID_FILL,LIGHTGRAY);
								bar(150,690,850,790);
								rectangle(150,690,850,790);
								outtextxy(160,700,const_cast<char*>(listQA[k].getChoiceD().c_str()));
								while(true){
									getmouseclick(WM_LBUTTONDOWN,x1,y1);
									if(bamChuot.BamChuotMenuThemCauHoi(x1,y1)) break;
									delay(10);
			}
							}
						else if(ch==8){
							string cD =listQA[k].getChoiceD();
							cD.pop_back(); 
							if(!listQA[k].getChoiceD().empty()) listQA[k].setChoiceD(cD);
						}
						else listQA[k].setChoiceD(listQA[k].getChoiceD()+ch);
					}
				}
				/* TODO (#1#): Fix lai chuc nang nguoi dung
		 */
				
		
				else if((x1>=1300 && x1<=1800) && (y1>=0 && y1<=300)){
					if(listQA[k].getChoiceA() == "" || listQA[k].getChoiceB() == "" ||
					 listQA[k].getChoiceC() == "" || listQA[k].getChoiceD() == "" || listQA[k].getQuestion() == "" || listQA[k].getAnswer() == ""){
						giaoDien.ManHinhThieuThongTin();
						giaoDien.ManHinhMenuSuaCauHoi(listQA[k].getQuestion(),
						listQA[k].getChoiceA(),
						listQA[k].getChoiceB(),
						listQA[k].getChoiceC(),
						listQA[k].getChoiceD());
						if(dapAn==1){
							setfillstyle(SOLID_FILL,GREEN);
							bar(1100,270,1300,370);
							listQA[k].setAnswer(listQA[k].getChoiceA());
						}
						if(dapAn==2){
							setfillstyle(SOLID_FILL,GREEN);
							bar(1100,440,1300,540);
							listQA[k].setAnswer(listQA[k].getChoiceB());
						}
						if(dapAn==3){
							setfillstyle(SOLID_FILL,GREEN);
							bar(1100,610,1300,710);
							listQA[k].setAnswer(listQA[k].getChoiceC());
						}
						if(dapAn==4){
							setfillstyle(SOLID_FILL,GREEN);
							bar(1100,780,1300,880);
							listQA[k].setAnswer(listQA[k].getChoiceD());
						}
						outtextxy(110,180,const_cast<char*>(listQA[k].getQuestion().c_str()));
						outtextxy(160,310,const_cast<char*>(listQA[k].getChoiceA().c_str()));
						outtextxy(160,440,const_cast<char*>(listQA[k].getChoiceB().c_str()));
						outtextxy(160,570,const_cast<char*>(listQA[k].getChoiceC().c_str()));
						outtextxy(160,700,const_cast<char*>(listQA[k].getChoiceD().c_str()));
						delay(10);
						while(true){
							getmouseclick(WM_LBUTTONDOWN,x1,y1);
							if(bamChuot.BamChuotMenuThemCauHoi(x1,y1)) break;
									delay(10);
			}	
					}
					else{
						int x2,y2;
						giaoDien.ManHinhXacNhanSuaCauHoi();
						while(true){
							getmouseclick(WM_LBUTTONDOWN,x2,y2);
							if(bamChuot.BamChuotManHinhXacNhanThemCauHoi(x2,y2)) break;
							delay(10);
						}
						if((x2>=440 && x2<=570) && (y2>=320 && y2<=420)){
			                setbkcolor(WHITE);
			                cleardevice();
		                	setbkcolor(LIGHTGRAY);
							suaCauHoi=1;
							break;
							delay(10);
				}
						else{
							/* TODO (#1#): Sua loi
	 */
							cleardevice();
							giaoDien.ManHinhMenuSuaCauHoi(listQA[k].getQuestion(),
							listQA[k].getChoiceA(),
							listQA[k].getChoiceB(),
							listQA[k].getChoiceC(),
							listQA[k].getChoiceD());
							if(dapAn==1){
								setfillstyle(SOLID_FILL,GREEN);
								bar(1120,300,1330,400);
								listQA[k].setAnswer(listQA[k].getChoiceA());
							}
							if(dapAn==2){
								setfillstyle(SOLID_FILL,GREEN);
								bar(1120,430,1330,530);
								listQA[k].setAnswer(listQA[k].getChoiceB());
							}
							if(dapAn==3){
								setfillstyle(SOLID_FILL,GREEN);
								bar(1120,560,1330,660);
								listQA[k].setAnswer(listQA[k].getChoiceC());
							}
							if(dapAn==4){
								setfillstyle(SOLID_FILL,GREEN);
								bar(1120,690,1330,790);
								listQA[k].setAnswer(listQA[k].getChoiceD());
							}
							
							outtextxy(110,180,const_cast<char*>(listQA[k].getQuestion().c_str()));
							outtextxy(160,310,const_cast<char*>(listQA[k].getChoiceA().c_str()));
							outtextxy(160,440,const_cast<char*>(listQA[k].getChoiceB().c_str()));
							outtextxy(160,570,const_cast<char*>(listQA[k].getChoiceC().c_str()));
							outtextxy(160,700,const_cast<char*>(listQA[k].getChoiceD().c_str()));
							delay(10);
							while(true){
								getmouseclick(WM_LBUTTONDOWN,x1,y1);
								if(bamChuot.BamChuotMenuThemCauHoi(x1,y1)) break;
										delay(10);
			}
				}
			}
				}
				else if((x1>=1120 && x1<=1330) && (y1>=300 && y1<= 400)){
					
					setfillstyle(SOLID_FILL,LIGHTGRAY);
					bar(1120,300,1330,400);
			
					bar(1120,430,1330,530);
					
					bar(1120,560,1330,660);
				
					bar(1120,690,1330,790);
				
					
					setfillstyle(SOLID_FILL,GREEN);
					bar(1120,300,1330,400);
			
					dapAn=1;
					listQA[k].setAnswer(listQA[k].getChoiceA());
					while(true){
						getmouseclick(WM_LBUTTONDOWN,x1,y1);
						if(bamChuot.BamChuotMenuThemCauHoi(x1,y1)) break;
						delay(10);
			}
				}
				else if((x1>=1120 && x1<=1330) && (y1>=430 && y1<= 530)){
					setfillstyle(SOLID_FILL,LIGHTGRAY);
					bar(1120,300,1330,400);
			
					bar(1120,430,1330,530);
					
					bar(1120,560,1330,660);
				
					bar(1120,690,1330,790);
					setfillstyle(SOLID_FILL,GREEN);
					bar(1120,430,1330,530);
					dapAn=2;
					listQA[k].setAnswer(listQA[k].getChoiceB());
					while(true){
						getmouseclick(WM_LBUTTONDOWN,x1,y1);
						if(bamChuot.BamChuotMenuThemCauHoi(x1,y1)) break;
									delay(10);
			}
				}
				else if((x1>=1120 && x1<=1330) && (y1>=560 && y1<= 660)){
					setfillstyle(SOLID_FILL,LIGHTGRAY);
					bar(1120,300,1330,400);
			
					bar(1120,430,1330,530);
					
					bar(1120,560,1330,660);
				
					bar(1120,690,1330,790);
					setfillstyle(SOLID_FILL,GREEN);
					bar(1120,560,1330,660);
					dapAn=3;
					listQA[k].setAnswer(listQA[k].getChoiceC());
					while(true){
						getmouseclick(WM_LBUTTONDOWN,x1,y1);
						if(bamChuot.BamChuotMenuThemCauHoi(x1,y1)) break;
									delay(10);
			}
				}
				else if((x1>=1120 && x1<=1330) && (y1>=690 && y1<= 790)){
					setfillstyle(SOLID_FILL,LIGHTGRAY);
					bar(1120,300,1330,400);
			
					bar(1120,430,1330,530);
					
					bar(1120,560,1330,660);
				
					bar(1120,690,1330,790);
					setfillstyle(SOLID_FILL,GREEN);
					bar(1120,690,1330,790);
					dapAn=4;
					listQA[k].setAnswer(listQA[k].getChoiceD());
					while(true){
						getmouseclick(WM_LBUTTONDOWN,x1,y1);
						if(bamChuot.BamChuotMenuThemCauHoi(x1,y1)) break;
						delay(10);
			}
				}
				else if((x1>=0 && x1<=200) && (y1>=0 && y1<=120)){
					    setbkcolor(WHITE);
			            cleardevice();
		                setbkcolor(LIGHTGRAY);
						break;
					}
				cleardevice();
				giaoDien.ManHinhMenuSuaCauHoi(listQA[k].getQuestion(),
						listQA[k].getChoiceA(),
						listQA[k].getChoiceB(),
						listQA[k].getChoiceC(),
						listQA[k].getChoiceD());
				
				if(dapAn==1){
					setfillstyle(SOLID_FILL,GREEN);
					bar(1120,300,1330,400);
					listQA[k].setAnswer(listQA[k].getChoiceA());
						}
				if(dapAn==2){
					setfillstyle(SOLID_FILL,GREEN);
					bar(1120,430,1330,530);
					listQA[k].setAnswer(listQA[k].getChoiceB());
						}
				if(dapAn==3){
					setfillstyle(SOLID_FILL,GREEN);
					bar(1120,560,1330,660);
					listQA[k].setAnswer(listQA[k].getChoiceC());
						}
				if(dapAn==4){
					setfillstyle(SOLID_FILL,GREEN);
					bar(1120,690,1330,790);
					listQA[k].setAnswer(listQA[k].getChoiceD());
						}
				if((x1>=100 && x1<=900) && (y1>=170 && y1<=270)){
				setfillstyle(SOLID_FILL,GREEN);
				bar(100,170,900,270);
			}
				if((x1>=150 && x1<=850) && (y1>=300 && y1<=400)){
					setfillstyle(SOLID_FILL,GREEN);
					bar(150,300,850,400);
				}
				if((x1>=150 && x1<=850) && (y1>=430 && y1<=530)){
					setfillstyle(SOLID_FILL,GREEN);
					bar(150,430,850,530);
				}
				if((x1>=150 && x1<=850) && (y1>=560 && y1<=660)){
					setfillstyle(SOLID_FILL,GREEN);
					bar(150,560,850,660);
				}
				if((x1>=150 && x1<=850) && (y1>=690 && y1<=790)){
					setfillstyle(SOLID_FILL,GREEN);
					bar(150,690,850,790);
				}
				while(kbhit()){
						getch();
					}
				outtextxy(110,180,const_cast<char*>(listQA[k].getQuestion().c_str()));
				outtextxy(160,310,const_cast<char*>(listQA[k].getChoiceA().c_str()));
				outtextxy(160,440,const_cast<char*>(listQA[k].getChoiceB().c_str()));
				outtextxy(160,570,const_cast<char*>(listQA[k].getChoiceC().c_str()));
				outtextxy(160,700,const_cast<char*>(listQA[k].getChoiceD().c_str()));
				delay(10);
			}
			if(suaCauHoi==0){
				listQA[k].setQuestion(cauHoi);
				listQA[k].setAnswer(cauTraLoi);
				listQA[k].setChoiceA(luaChonA);
				listQA[k].setChoiceB(luaChonB);
				listQA[k].setChoiceC(luaChonC);
				listQA[k].setChoiceD(luaChonD);
		}
			}
		}
			ofstream outFile(FILEREAD);
			for(int i =0;i<listQA.size();i++){
				if(isFileEmpty(FILEREAD)){
				outFile<<listQA[i].getQuestion()<<endl;
				outFile<<listQA[i].getAnswer()<<endl;
				outFile<<listQA[i].getChoiceA()<<endl;
				outFile<<listQA[i].getChoiceB()<<endl;
				outFile<<listQA[i].getChoiceC()<<endl;
				outFile<<listQA[i].getChoiceD();
							}
			else{
				outFile<<endl<<listQA[i].getQuestion()<<endl;
				outFile<<listQA[i].getAnswer()<<endl;
				outFile<<listQA[i].getChoiceA()<<endl;
				outFile<<listQA[i].getChoiceB()<<endl;
				outFile<<listQA[i].getChoiceC()<<endl;
				outFile<<listQA[i].getChoiceD();
						}
			}
			outFile.close();
}
void clickmouse(QA a,int &diem,vector<QA> & wrongQA){
	BamChuot bamChuot;
	string ans;
	int x1,y1;
	while(true){
		getmouseclick(WM_LBUTTONDOWN,x1,y1);
		if(bamChuot.BamChuotManHinhLamBai(x1,y1))
		 break;
		delay(10);
	}
	if((x1>=100 && x1<=1500 ) && (y1>=320 && y1<=420)){
		ans = a.getChoiceA();
	}
	if((x1>=100 && x1<=1500 ) && (y1>=430 && y1<=530)){
		ans = a.getChoiceB();
	}
	if((x1>=100 && x1<=1500 ) && (y1>=540 && y1<=640)){
		ans = a.getChoiceC();
	}
	if((x1>=100 && x1<=1500 ) && (y1>=650 && y1<=750)){
		ans = a.getChoiceD();
	}
	if(a.getAnswer() == a.getChoiceA()){
		setfillstyle(SOLID_FILL,GREEN);
		bar(99,321,getmaxx()-99,419);
		setbkcolor(GREEN);
		settextstyle(GOTHIC_FONT,0,6);
		outtextxy(160,330,const_cast<char*> (a.getChoiceA().c_str()));
	}
	if(a.getAnswer() == a.getChoiceB()){
		setfillstyle(SOLID_FILL,GREEN);
		bar(99,431,getmaxx()-99,529);
		setbkcolor(GREEN);
		settextstyle(GOTHIC_FONT,0,6);
		outtextxy(160,440,const_cast<char*> (a.getChoiceB().c_str()));
	}
	if(a.getAnswer() == a.getChoiceC()){
		setfillstyle(SOLID_FILL,GREEN);
		bar(99,541,getmaxx()-99,639);
		setbkcolor(GREEN);
		settextstyle(GOTHIC_FONT,0,6);
		outtextxy(160,550,const_cast<char*> (a.getChoiceC().c_str()));
	}
	if(a.getAnswer() == a.getChoiceD()){
		setfillstyle(SOLID_FILL,GREEN);
		bar(99,651,getmaxx()-99,749);
		setbkcolor(GREEN);
		settextstyle(GOTHIC_FONT,0,6);
		outtextxy(160,660,const_cast<char*> (a.getChoiceD().c_str()));
	}
	if(ans == a.getAnswer()){
		diem++;
	}
	else{
		wrongQA.push_back(a);
		}
	}
void ChucNangMenu(int &hienthi,int &chuDe){
	int x1,y1;
	GiaoDien giaoDien;
	BamChuot bamChuot;
	giaoDien.menu();
	while(true){
		getmouseclick(WM_LBUTTONDOWN,x1,y1);
		if(bamChuot.BamChuotManHinhMenu(x1,y1)) break;
		delay(10);
	}
	
	if((x1>=550 && x1<=1100) && (y1>=320 && y1<=390)){
		ChucNangLuaChonChuDe(chuDe);
		hienthi=2;
	}
	if((x1>=550 && x1<=1100) && (y1>=460 && y1<=530)){
		vector<QA> listQA;
		string line;
		ChucNangLuaChonChuDe(chuDe);
		if(chuDe == 1) FILEREAD = FILENAME2;
		else if (chuDe == 2) FILEREAD = FILENAME3;
		else FILEREAD = FILENAME4;
		ifstream inFile(FILEREAD);
		while(getline(inFile,line)){
		QA a;
		a.setQuestion(line);
		getline(inFile,line);
		a.setAnswer(line);
		getline(inFile,line);
		a.setChoiceA(line);
		getline(inFile,line);
		a.setChoiceB(line);
		getline(inFile,line);
		a.setChoiceC(line);
		getline(inFile,line);
		a.setChoiceD(line);
		listQA.push_back(a);
	}
		if(listQA.size() ==0){
			
			hienthi=5; // Hienthi =5 de hien thi menu thong bao chua co cau hoi
		}
		else hienthi=6; // hienthi=6 sua cau hoi
	}
	if((x1>=550 && x1<=1100) && (y1>=180 && y1<=250)){
		vector<QA> listQA;
		string line;
		ChucNangLuaChonChuDe(chuDe);
		if(chuDe == 1) FILEREAD = FILENAME2;
		else if (chuDe == 2) FILEREAD = FILENAME3;
		else FILEREAD = FILENAME4;
		ifstream inFile(FILEREAD);
		while(getline(inFile,line)){
		QA a;
		a.setQuestion(line);
		getline(inFile,line);
		a.setAnswer(line);
		getline(inFile,line);
		a.setChoiceA(line);
		getline(inFile,line);
		a.setChoiceB(line);
		getline(inFile,line);
		a.setChoiceC(line);
		getline(inFile,line);
		a.setChoiceD(line);
		listQA.push_back(a);
	}
		if(listQA.size() ==0){
			
			hienthi=5; // Hienthi =5 de hien thi menu thong bao chua co cau hoi
		}
		else hienthi=3;
	}

	if((x1>=550 && x1<=1100) && (y1>=600 && y1<=670)){
		ChucNangLuaChonChuDe(chuDe);
		hienthi = 7;
	}
	if((x1>=550 && x1<=1100) && (y1>=740 && y1<=810)){
		ChucNangLuaChonChuDe(chuDe);
		hienthi = 8;
	}
}

void ChucNangThemCauHoi(int &hienthi,int &chuDe){
	GiaoDien giaoDien;
	BamChuot bamChuot;
	int x1,y1,dapAn=0;
	QA a;
	string question;
	string ans,cA,cB,cC,cD;
	char ch;
	giaoDien.ManHinhMenuThemCauHoi(question,cA,cB,cC,cD);
	while(true){
		getmouseclick(WM_LBUTTONDOWN,x1,y1);
		if((x1>=100 && x1<=900) && (y1>=170 && y1<=270)){
			setfillstyle(SOLID_FILL,GREEN);
			bar(100,170,900,270);
		}
		
		if((x1>=150 && x1<=850) && (y1>=300 && y1<=400)){
			setfillstyle(SOLID_FILL,GREEN);
			bar(150,300,850,400);
		}
		if((x1>=150 && x1<=850) && (y1>=430 && y1<=530)){
			setfillstyle(SOLID_FILL,GREEN);
			bar(150,430,850,530);
		}
		if((x1>=150 && x1<=850) && (y1>=560 && y1<=660)){
			setfillstyle(SOLID_FILL,GREEN);
			bar(150,560,850,660);
		}
		if((x1>=150 && x1<=850) && (y1>=690 && y1<=790)){
			setfillstyle(SOLID_FILL,GREEN);
			bar(150,690,850,790);
		}
		if(bamChuot.BamChuotMenuThemCauHoi(x1,y1)) break;
		delay(10);
	}
		
	while(true){
		if((x1>=100 && x1<=900) && (y1>=170 && y1<=270)){
			while(!kbhit()) delay(10);
			if(kbhit()){
				ch=getch();
				if(ch==13) {
					clearmouseclick(WM_LBUTTONDOWN);
					setfillstyle(SOLID_FILL,LIGHTGRAY);
					bar(100,170,900,270);
					rectangle(100,170,900,270);
					outtextxy(110,180,const_cast<char*>(question.c_str()));
					while(true){
						getmouseclick(WM_LBUTTONDOWN,x1,y1);
						if(bamChuot.BamChuotMenuThemCauHoi(x1,y1)) break;
							delay(10);
	}
				}
				else if(ch==8){
					if(!question.empty()) question.pop_back();
				}
				else question = question+ch;
			}
		}
		else if((x1>=150 && x1<=850) && (y1>=300 && y1<=400)){
			while(!kbhit()) delay(10);
			if(kbhit()){
				ch=getch();
					if(ch==13) 	{
						clearmouseclick(WM_LBUTTONDOWN);
						setfillstyle(SOLID_FILL,LIGHTGRAY);
						bar(150,300,850,400);
						rectangle(150,300,850,400);
						outtextxy(160,310,const_cast<char*>(cA.c_str()));
						while(true){
							getmouseclick(WM_LBUTTONDOWN,x1,y1);
							if(bamChuot.BamChuotMenuThemCauHoi(x1,y1)) break;
							delay(10);
	}
					}
				
					else if(ch==8){
						if(!cA.empty()) cA.pop_back();
						
				}
				else cA = cA+ch;
			}
			}
		else if((x1>=150 && x1<=850) && (y1>=430 && y1<=530)){
			while(!kbhit()) delay(10);
			if(kbhit()){
				ch=getch();
					if(ch==13) {
						clearmouseclick(WM_LBUTTONDOWN);
						setfillstyle(SOLID_FILL,LIGHTGRAY);
						bar(150,430,850,530);
						rectangle(150,430,850,530);
						outtextxy(160,440,const_cast<char*>(cB.c_str()));
						while(true){
							getmouseclick(WM_LBUTTONDOWN,x1,y1);
							if(bamChuot.BamChuotMenuThemCauHoi(x1,y1)) break;
							delay(10);
	}
					}
				else if(ch==8){
					if(!cB.empty()) cB.pop_back();
				
				}
				else cB = cB+ch;
			}
		}
		else if((x1>=150 && x1<=850) && (y1>=560 && y1<=660)){
			while(!kbhit()) delay(10);
			if(kbhit()){
				ch=getch();
					if(ch==13) {
						clearmouseclick(WM_LBUTTONDOWN);
						setfillstyle(SOLID_FILL,LIGHTGRAY);
						bar(150,560,850,660);
						rectangle(150,560,850,660);
						outtextxy(160,570,const_cast<char*>(cC.c_str()));
						while(true){
							getmouseclick(WM_LBUTTONDOWN,x1,y1);
							if(bamChuot.BamChuotMenuThemCauHoi(x1,y1)) break;
							delay(10);
	}
					}
				
				else if(ch==8){
					if(!cC.empty()) cC.pop_back();
				
				}
				else cC = cC+ch;
			}
			}
		else if((x1>=150 && x1<=850) && (y1>=690 && y1<=790)){
			while(!kbhit()) delay(10);
			if(kbhit()){
				ch=getch();
					if(ch==13) {
						clearmouseclick(WM_LBUTTONDOWN);
						setfillstyle(SOLID_FILL,LIGHTGRAY);
						bar(150,690,850,790);
						rectangle(150,690,850,790);
						outtextxy(160,700,const_cast<char*>(cD.c_str()));
						while(true){
							getmouseclick(WM_LBUTTONDOWN,x1,y1);
							if(bamChuot.BamChuotMenuThemCauHoi(x1,y1)) break;
							delay(10);
	}
					}
				else if(ch==8){
					if(!cD.empty()) cD.pop_back();
					
				}
				else cD = cD+ch;
			}
		}
		/* TODO (#1#): Fix lai chuc nang nguoi dung
 */
		else if((x1>=1300 && x1<=1800) && (y1>=0 && y1<=300)){
			if(cA == "" || cB == "" || cC == "" || cD == "" || ans == "" || question == ""){
				giaoDien.ManHinhThieuThongTin();
				giaoDien.ManHinhMenuThemCauHoi(question,cA,cB,cC,cD);
				if(dapAn==1){
					setfillstyle(SOLID_FILL,GREEN);
					bar(1120,300,1330,400);
					ans=cA;
				}
				if(dapAn==2){
					setfillstyle(SOLID_FILL,GREEN);
					bar(1120,430,1330,530);
					ans=cB;
				}
				if(dapAn==3){
					setfillstyle(SOLID_FILL,GREEN);
					bar(1120,560,1330,660);
					ans=cC;
				}
				if(dapAn==4){
					setfillstyle(SOLID_FILL,GREEN);
					bar(1120,690,1330,790);
					ans = cD;
				}
				delay(10);
				while(true){
					getmouseclick(WM_LBUTTONDOWN,x1,y1);
					if(bamChuot.BamChuotMenuThemCauHoi(x1,y1)) break;
							delay(10);
	}	
			}
			else{
				int x2,y2;
				giaoDien.ManHinhXacNhanThemCauHoi();
				while(true){
					
					getmouseclick(WM_LBUTTONDOWN,x2,y2);
					if(bamChuot.BamChuotManHinhXacNhanThemCauHoi(x2,y2)) break;
					delay(10);
				}
				if((x2>=440 && x2<=570) && (y2>=320 && y2<=420)){
					cleardevice();
					if(chuDe == 1) FILEREAD = FILENAME2;
					if(chuDe == 2) FILEREAD = FILENAME3;
					if(chuDe == 3) FILEREAD = FILENAME4;
					ofstream outFile(FILEREAD,ios::app);
					a.setChoiceA(cA);
					a.setQuestion(question);
					a.setChoiceB(cB);
					a.setChoiceC(cC);
					a.setChoiceD(cD);
					a.setAnswer(ans);
					if(isFileEmpty(FILEREAD)){
						outFile<<question<<endl;
						outFile<<ans<<endl;
						outFile<<cA<<endl;
						outFile<<cB<<endl;
						outFile<<cC<<endl;
						outFile<<cD;
					}
					else{
						outFile<<endl<<question<<endl;
						outFile<<ans<<endl;
						outFile<<cA<<endl;
						outFile<<cB<<endl;
						outFile<<cC<<endl;
						outFile<<cD;
				}
					outFile.close();
					cA="";
					question="";
					cB="";
					cC="";
					cD="";
					ans="";
					dapAn=0;
					cleardevice();
					giaoDien.ManHinhMenuThemCauHoi(question,cA,cB,cC,cD);
					delay(10);
					clearmouseclick(WM_LBUTTONDOWN);
					while(true){
						getmouseclick(WM_LBUTTONDOWN,x1,y1);
						if(bamChuot.BamChuotMenuThemCauHoi(x1,y1)) break;
							delay(10);
	}
		}
			else{
				
				cleardevice();
				giaoDien.ManHinhMenuThemCauHoi(question,cA,cB,cC,cD);
				if(dapAn==1){
					setfillstyle(SOLID_FILL,GREEN);
					bar(1120,300,1330,400);
					ans=cA;
			}
				if(dapAn==2){
					setfillstyle(SOLID_FILL,GREEN);
					bar(1120,430,1330,530);
					ans=cB;
			}
				if(dapAn==3){
					setfillstyle(SOLID_FILL,GREEN);
					bar(1120,560,1330,660);
					ans=cC;
			}
				if(dapAn==4){
					setfillstyle(SOLID_FILL,GREEN);
					bar(1120,690,1330,790);
					ans = cD;
			}
				delay(10);
				while(true){
					getmouseclick(WM_LBUTTONDOWN,x1,y1);
					if(bamChuot.BamChuotMenuThemCauHoi(x1,y1)) break;
							delay(10);
	}
		}
	}
		}
		else if((x1>=1120 && x1<=1330) && (y1>=300 && y1<= 400)){
			
			setfillstyle(SOLID_FILL,LIGHTGRAY);
			bar(1120,300,1330,400);
		
			bar(1120,430,1330,530);
			
			bar(1120,560,1330,660);
		
			bar(1120,690,1330,790);
		
			
			setfillstyle(SOLID_FILL,GREEN);
			bar(1120,300,1330,400);
			dapAn=1;
			ans = cA;
			clearmouseclick(WM_LBUTTONDOWN);
			while(true){
				getmouseclick(WM_LBUTTONDOWN,x1,y1);
				if(bamChuot.BamChuotMenuThemCauHoi(x1,y1)) break;
				delay(10);
	}
		}
		else if((x1>=1120 && x1<=1330) && (y1>=430 && y1<= 530)){
			setfillstyle(SOLID_FILL,LIGHTGRAY);
			bar(1120,300,1330,400);
		
			bar(1120,430,1330,530);
			
			bar(1120,560,1330,660);
		
			bar(1120,690,1330,790);
			setfillstyle(SOLID_FILL,GREEN);
			bar(1120,430,1330,530);
			dapAn=2;
			ans = cB;
			clearmouseclick(WM_LBUTTONDOWN);
			while(true){
				getmouseclick(WM_LBUTTONDOWN,x1,y1);
				if(bamChuot.BamChuotMenuThemCauHoi(x1,y1)) break;
							delay(10);
	}
		}
		else if((x1>=1120 && x1<=1330) && (y1>=560 && y1<= 660)){
			setfillstyle(SOLID_FILL,LIGHTGRAY);
			bar(1120,300,1330,400);
		
			bar(1120,430,1330,530);
			
			bar(1120,560,1330,660);
		
			bar(1120,690,1330,790);
			setfillstyle(SOLID_FILL,GREEN);
			bar(1120,560,1330,660);
			dapAn=3;
			ans = cC;
			clearmouseclick(WM_LBUTTONDOWN);
			while(true){
				getmouseclick(WM_LBUTTONDOWN,x1,y1);
				if(bamChuot.BamChuotMenuThemCauHoi(x1,y1)) break;
							delay(10);
	}
		}
		else if((x1>=1120 && x1<=1330) && (y1>=690 && y1<= 790)){
			setfillstyle(SOLID_FILL,LIGHTGRAY);
			bar(1120,300,1330,400);
		
			bar(1120,430,1330,530);
			
			bar(1120,560,1330,660);
			bar(1120,690,1330,790);
			setfillstyle(SOLID_FILL,GREEN);
			bar(1120,690,1330,790);
			dapAn=4;
			ans=cD;
			clearmouseclick(WM_LBUTTONDOWN);
			while(true){
				getmouseclick(WM_LBUTTONDOWN,x1,y1);
				if(bamChuot.BamChuotMenuThemCauHoi(x1,y1)) break;
				delay(10);
	}
		}
		else if((x1>=0 && x1<=200) && (y1>=0 && y1<=120)){
				hienthi=1;
				cleardevice();
				break;
			}
		
		giaoDien.ManHinhMenuThemCauHoi(question,cA,cB,cC,cD);
		if(dapAn==1){
			setfillstyle(SOLID_FILL,GREEN);
			bar(1120,300,1330,400);
			ans=cA;
		}
		if(dapAn==2){
			setfillstyle(SOLID_FILL,GREEN);
			bar(1120,430,1330,530);
			ans=cB;
		}
		if(dapAn==3){
			setfillstyle(SOLID_FILL,GREEN);
			bar(1120,560,1330,660);
			ans=cC;
		}
		if(dapAn==4){
			setfillstyle(SOLID_FILL,GREEN);
			bar(1120,690,1330,790);
			ans = cD;
		}
		if((x1>=100 && x1<=900) && (y1>=170 && y1<=270)){
			setfillstyle(SOLID_FILL,GREEN);
			bar(100,170,900,270);
		}
		if((x1>=150 && x1<=850) && (y1>=300 && y1<=400)){
			setfillstyle(SOLID_FILL,GREEN);
			bar(150,300,850,400);
		}
		if((x1>=150 && x1<=850) && (y1>=430 && y1<=530)){
			setfillstyle(SOLID_FILL,GREEN);
			bar(150,430,850,530);
		}
		if((x1>=150 && x1<=850) && (y1>=560 && y1<=660)){
			setfillstyle(SOLID_FILL,GREEN);
			bar(150,560,850,660);
		}
		if((x1>=150 && x1<=850) && (y1>=690 && y1<=790)){
			setfillstyle(SOLID_FILL,GREEN);
			bar(150,690,850,790);
		}
			outtextxy(110,180,const_cast<char*>(question.c_str()));
			outtextxy(160,310,const_cast<char*>(cA.c_str()));
			outtextxy(160,440,const_cast<char*>(cB.c_str()));
			outtextxy(160,570,const_cast<char*>(cC.c_str()));
			outtextxy(160,700,const_cast<char*>(cD.c_str()));
		while(kbhit()){
				getch();
			}
		clearmouseclick(WM_LBUTTONDOWN);
		delay(10);
	}
	}
void ChucNangHoanThanhLamBai(vector<QA> & listQA,int &diem,int &hienthi,int &count){
	int x1,y1;
	GiaoDien giaoDien;
	BamChuot bamChuot;
	giaoDien.ManHinhHoanThanhLamBai(listQA,diem,count);
	while(true){
		getmouseclick(WM_LBUTTONDOWN,x1,y1);
		if(bamChuot.BamChuotManHinhHoanThanhLamBai(x1,y1,diem,count,listQA)) break;
		delay(10);
	}
	rectangle(420,650,700,750);
	if((x1>=420 && x1<=700) && (y1>=650 && y1<=750)){
		hienthi=1;
		cleardevice();
		diem = 0;
		count=0;
	}
	if(diem != listQA.size() && count ==0 ){
		if((x1>=780 && x1<=1200) && (y1>=650 && y1<=750)){
		count = 1;
		hienthi=4;
		cleardevice();
		diem=0;
		}
	}
	/* TODO (#1#): Sua lai loi
 */
}
void ChucNangLuaChonRandom(bool &random){
	int x1,y1;
	GiaoDien giaoDien;
	BamChuot bamChuot;
	giaoDien.ManHinhLuaChonRandom();
	while(true){
		getmouseclick(WM_LBUTTONDOWN,x1,y1);
		if(bamChuot.BamChuotManHinhLuaChonRandom(x1,y1) ) break;
		delay(10);
	}
	if((x1>=350 && x1<=500) && (y1>=350 && y1<=450)) random=1;
	else random=0;
	cleardevice();
}
//dat lich


void manhinhlichontap(int &hienthi){
	//nen xam
	setfillstyle(SOLID_FILL, WHITE);
	bar(0,0,getmaxx(),getmaxy());
	//xanh nhat Loi nhac
	setfillstyle(SOLID_FILL, LIGHTBLUE);
	bar(0,0,getmaxx(),100);
	//Vien xanh
	setfillstyle(SOLID_FILL, BLUE);
	bar(0,0,getmaxx(),30);
	bar(0,0,30,getmaxy());
	bar(0,getmaxy()-30,getmaxx(),getmaxy());
	bar(getmaxx()-30,0,getmaxx(),getmaxy());
	//tro ve
	setfillstyle(SOLID_FILL,BLACK);
	bar(200,30,202,100);
	settextstyle(6,0,5);
	setbkcolor(LIGHTBLUE);
	setcolor(WHITE);
	outtextxy(35,50,(char*)"Back" );
	outtextxy(630,50,"Set Reminder");
	//chon thu
	int z=-20,x=0,y=-100;
	setfillstyle(SOLID_FILL,BLACK);
	
	bar(99+x,219+y,501+x,321+y);
	setfillstyle(SOLID_FILL,YELLOW);
	bar(100+x,220+y,500+x,320+y);
	setcolor(BLACK);
	setbkcolor(YELLOW);
	outtextxy(175,150,"Select day");
					//thu 2

					setbkcolor(YELLOW);
		       		setcolor(BLACK);
					bar(150,230,450,310);
					outtextxy(225-60,250,"Monday");	 //	bar(150+x,330+y,450+x,410+y);bar(150+x,420+y,450+x,500+y);bar(150+x,510+y,450+x,590+y);	bar(150+x,510+y,450+x,590+y);bar(150+x,600+y,450+x,680+y);bar(150+x,690+y,450+x,770+y);bar(150+x,780+y,450+x,860+y);bar(150+x,870+y,450+x,950+y);
					//thu 3											
					bar(150,320,450,400);			
					outtextxy(225-60,340,"Tuesday"); 
					//thu 4
					bar(150,410,450,490);
					outtextxy(225-60,430,"Wednesday");
					//thu 5
					bar(150,500,450,580);
					outtextxy(225-60,520,"Thursday");
					//thu 6
					bar(150,590,450,670);
					outtextxy(225-60,610,"Friday");
					//thu 7
					bar(150,680,450,760);
					outtextxy(225-60,690,"Saturday");
					//chu nhat
					bar(150,770,450,850);
					outtextxy(225-60,780,"Sunday");
		       	
	//nhap thoi gian 
	setfillstyle(SOLID_FILL,BLACK);
	bar(590-1,219+y-1,1500+1,300+1);
	setfillstyle(SOLID_FILL,YELLOW);
	bar(590,219+y,1500,300);
	outtextxy(610,239+y,"Enter time:");
	settextstyle(6,0,5);
	outtextxy(594,239+80+y,"Hrs:");
	outtextxy(985,239+80+y,"Mins:");
	//bao lai
	/*setfillstyle(SOLID_FILL,BLACK);
	bar(600-1,500+y-1,1500+1,550+1);
	setfillstyle(SOLID_FILL,YELLOW);
	bar(600,500+y,1500,550);
	outtextxy(610,520+y+40,"Bao lai:");
	setfillstyle(SOLID_FILL,YELLOW);*/
	
	//xac nhan
	setfillstyle(SOLID_FILL,BLUE);
	setcolor(WHITE);
	setbkcolor(BLUE);
	bar(1290-1,800+y-1+10,1550,900+y-1+10);
	outtextxy(1300,800+y+40,"Confirm");
	setbkcolor(BLUE);
	setcolor(WHITE);

	bar(560,430,1450+10,530);
	outtextxy(570,460,"ON/OFF: ");
	setbkcolor(BLUE);
	setcolor(WHITE);
	//gio, phut
	setfillstyle(SOLID_FILL,BLACK);
	bar(719,209,981,271);
	setfillstyle(SOLID_FILL,LIGHTGRAY);
	bar(720,210,980,270);
	//phut
	setfillstyle(SOLID_FILL,BLACK);
	bar(1130,209,1451,271);
	setfillstyle(SOLID_FILL,LIGHTGRAY);
	bar(1131,210,1450,270);
	//loi bao cao 
	/*setfillstyle(SOLID_FILL,BLACK);
	bar(820,429+10,1451,531-10);
	setfillstyle(SOLID_FILL,LIGHTGRAY);
	bar(821,430+10,1450,530-10);*/
	//bar(720,210,980,270);
	//bar(1131,210,1450,270);
	//bar(821,430+10,1450,530-10);
	

	
}
void manhinhxacnhan(){
	cleardevice();
	setfillstyle(SOLID_FILL, WHITE);
	bar(0,0,getmaxx(),getmaxy());
	//xanh nhat Loi nhac
	setfillstyle(SOLID_FILL, LIGHTBLUE);
	bar(0,0,getmaxx(),100);
	//Vien xanh
	setfillstyle(SOLID_FILL, BLUE);
	bar(0,0,getmaxx(),30);
	bar(0,0,30,getmaxy());
	bar(0,getmaxy()-30,getmaxx(),getmaxy());
	bar(getmaxx()-30,0,getmaxx(),getmaxy());	
	//xac nhan 
	setfillstyle(SOLID_FILL, LIGHTGRAY);
	setbkcolor(LIGHTGRAY);
	setcolor(BLACK);
	bar(300,300,1300,600);
	outtextxy(400,350,"Do you want to set a reminder? ");
	rectangle(420,480,600,550);
	rectangle(1000,480,1180,550);
	outtextxy(460,490,"Yes");
	outtextxy(1050,490,"No ");
	setbkcolor(BLUE);
	setcolor(WHITE);
}
void xacnhan(int &hienthi){
	
	cleardevice();
			int x,y;
			manhinhxacnhan();
			getmouseclick(WM_LBUTTONDOWN,x,y);
			while(true){
				if((x>=420&&x<=600)&&(y>=480&&y<=550)||(x>=1000&&x<=1180)&&(y>=480&&y<=550)){
					bar(0,0,1600,900);
					break;
				}
				
			}while(true){
				
				if((x>=1000&&x<=1180)&&(y>=480&&y<=550)){
					hienthi=8;
					break;
				}
			
			}
}
void manhinhloi(){
	setfillstyle(SOLID_FILL, WHITE);
	bar(0,0,getmaxx(),getmaxy());
	//xanh nhat Loi nhac
	setfillstyle(SOLID_FILL, LIGHTBLUE);
	bar(0,0,getmaxx(),100);
	//Vien xanh
	setfillstyle(SOLID_FILL, BLUE);
	bar(0,0,getmaxx(),30);
	bar(0,0,30,getmaxy());
	bar(0,getmaxy()-30,getmaxx(),getmaxy());
	bar(getmaxx()-30,0,getmaxx(),getmaxy());
	//setfillstyle(SOLID_FILL, LIGHTGRAY);
	setbkcolor(LIGHTGRAY);
	setcolor(WHITE);
	setbkcolor(BLUE);
	bar(300,300,1300,600);
	outtextxy(450,350,"The information you entered");
	outtextxy(600,400," is incorrect ");
}
void removeFromStartup() {
    const char* subKey = "Software\\Microsoft\\Windows\\CurrentVersion\\Run";
    HKEY hKey;
    if (RegOpenKeyExA(HKEY_CURRENT_USER, subKey, 0, KEY_WRITE, &hKey) == ERROR_SUCCESS) {
        RegDeleteValueA(hKey, "MyAppNotification");
        RegCloseKey(hKey);
    }
}
bool chuongtrinhdangchay() {
	string command = "tasklist | findstr /i \"lichon.exe\"";

    int result = system(command.c_str());
    return (result == 0); 
}
void lichontap(int &hienthi){
	string command = "taskkill /F /IM " + processName;
	int x,y,d;
	char ch;
	manhinhlichontap(hienthi);
	int thu;
	string mess,hours,min;if(chuongtrinhdangchay()==false){
			setfillstyle(SOLID_FILL,RED);
			d=1;
			
		}else{
			setfillstyle(SOLID_FILL,GREEN);
			d=0;
		}bar(821,430+10,1450,530-10);
	while(true){
			
		
		
		thu=10;
		if(ismouseclick(WM_LBUTTONDOWN)){
			getmouseclick(WM_LBUTTONDOWN,x,y);
			if((x>=720&&x<=980)&&(y>=210&&y<=270)){
			setfillstyle(SOLID_FILL,GREEN);
				bar(720,210,980,270);	
				
				
			} if((x>=1131&&x<=1450)&&(y>=210&&y<=270)){
			//	setfillstyle(SOLID_FILL,GREEN);
				///bar(1131,210,1450,270);
			}
				//bar(720,210,980,270);
	//bar(1131,210,1450,270);
	//bar(821,430+10,1450,530-10);
		if((x>=30 &&x<=200)&&(y>=30&&y<200)||//tro ve
			(x>=1290&& x<=1550)&&(y>=709&&y<=809)||//xac nhan
			(x>=720&&x<=980)&&(y>=210&&y<=270)||(x>=1131&&x<=1450)&&(y>=210&&y<=270)||(x>=821&&x<=1450)&&(y>=440&&y<=520)|| //nhap gio phut bao cao
			(x>=150&& x<=450)&&(y>=230&&y<=310)||//thu2
			(x>=150&& x<=450)&&(y>=320&&y<=400)||//thu 3
			(x>=150&& x<=450)&&(y>=410&&y<=490)||//thu 4
			(x>=150&& x<=450)&&(y>=500&&y<=580)||//thu 5
			(x>=150&& x<=450)&&(y>=590&&y<=670)||// thu 6
			(x>=150&& x<=450)&&(y>=680&&y<=760)||// thu 7
			(x>=150&& x<=450)&&(y>=770&&y<=850)){ //chu nhat
				//bar(720,210,980,270);
	//bar(1131,210,1450,270);
	//bar(821,430+10,1450,530-10);
			break;
		}
			
		}
	}

	/*while(true){
		if(ismouseclick(WM_LBUTTONDOWN)){
			getmouseclick(WM_LBUTTONDOWN,x,y);
			if((x>=30 &&x<=200)&&(y>=30&&y<200)||//tro ve
			(x>=1290&& x<=1550)&&(y>=709&&y<=809)||//xac nhan
			(x>=720&&x<=980)&&(y>=210&&y<=270)||(x>=1131&&x<=1450)&&(y>=210&&y<=270)||(x>=821&&x<=1450)&&(y>=440&&y<=520)|| //nhap gio phut bao cao
			(x>=150&& x<=450)&&(y>=230&&y<=310)||//thu2
			(x>=150&& x<=450)&&(y>=320&&y<=400)||//thu 3
			(x>=150&& x<=450)&&(y>=410&&y<=490)||//thu 4
			(x>=150&& x<=450)&&(y>=500&&y<=580)||//thu 5
			(x>=150&& x<=450)&&(y>=590&&y<=670)||// thu 6
			(x>=150&& x<=450)&&(y>=680&&y<=760)||// thu 7
			(x>=150&& x<=450)&&(y>=770&&y<=850)){ //chu nhat
				//bar(720,210,980,270);
	//bar(1131,210,1450,270);
	//bar(821,430+10,1450,530-10);
			break;
		}		
	}
}*/
	while (true){
			
		/*if((x>=720 && x<=980) && (y>=210 && y<=270)){
			while(!kbhit()) delay(10);
			if(kbhit()){setcolor(WHITE);
				ch=getch();
				if(ch==13) 	{
					setfillstyle(SOLID_FILL,GREEN);
				
					bar(720,210,980,270);	break;
				}
				else if(ch==8){
					if(!hours.empty()) hours.pop_back();
				}
				else hours = hours+ch;
	 	}
		}*/
			if((x>=720&&x<=980)&&(y>=210&&y<=270)){
				setfillstyle(SOLID_FILL,GREEN);
				bar(720,210,980,270);
				outtextxy(720,215,const_cast<char*>(hours.c_str()));
					
				while(!kbhit()) delay(10);
				
				if(kbhit()){
					ch=getch();
					
					if (ch == '\r') { 
						setfillstyle(SOLID_FILL,LIGHTGRAY);
						bar(720,210,980,270);
						setbkcolor(LIGHTGRAY);
						outtextxy(720,215,const_cast<char*>(hours.c_str()));
						while(true){
							getmouseclick(WM_LBUTTONDOWN,x,y);
							if((x>=30 &&x<=200)&&(y>=30&&y<200)||//tro ve
									(x>=1290&& x<=1550)&&(y>=709&&y<=809)||//xac nhan
									(x>=720&&x<=980)&&(y>=210&&y<=270)||(x>=1131&&x<=1450)&&(y>=210&&y<=270)||(x>=821&&x<=1450)&&(y>=440&&y<=520)|| //nhap gio phut bao cao
									(x>=150&& x<=450)&&(y>=230&&y<=310)||//thu2
									(x>=150&& x<=450)&&(y>=320&&y<=400)||//thu 3
									(x>=150&& x<=450)&&(y>=410&&y<=490)||//thu 4
									(x>=150&& x<=450)&&(y>=500&&y<=580)||//thu 5
									(x>=150&& x<=450)&&(y>=590&&y<=670)||// thu 6
									(x>=150&& x<=450)&&(y>=680&&y<=760)||// thu 7
									(x>=150&& x<=450)&&(y>=770&&y<=850)){ //chu nhat
				//bar(720,210,980,270);
	//bar(1131,210,1450,270);
	//bar(821,430+10,1450,530-10);
			break;
		}outtextxy(720,215,const_cast<char*>(hours.c_str()));
						}
            		}
            		else if (ch == '\b' && !hours.empty()) {
               			 hours.pop_back();
           		 	}else hours+=ch;		
				}
				
			}
				
			if((x>=1131&&x<=1450)&&(y>=210&&y<=270)){
				setfillstyle(SOLID_FILL,GREEN);
				bar(1131,210,1450,270);
				outtextxy(1131,215,const_cast<char*>(min.c_str()));
				while(!kbhit()) delay(10);
				if(kbhit()){
					ch =getch();
					
					if(ch =='\r'){	
					setfillstyle(SOLID_FILL,LIGHTGRAY);
						bar(1131,210,1450,270);
						setbkcolor(LIGHTGRAY);
						outtextxy(1131,215,const_cast<char*>(min.c_str()));
						while(true){
							getmouseclick(WM_LBUTTONDOWN,x,y);
							if((x>=30 &&x<=200)&&(y>=30&&y<200)||//tro ve
									(x>=1290&& x<=1550)&&(y>=709&&y<=809)||//xac nhan
									(x>=720&&x<=980)&&(y>=210&&y<=270)||(x>=1131&&x<=1450)&&(y>=210&&y<=270)||(x>=821&&x<=1450)&&(y>=440&&y<=520)|| //nhap gio phut bao cao
									(x>=150&& x<=450)&&(y>=230&&y<=310)||//thu2
									(x>=150&& x<=450)&&(y>=320&&y<=400)||//thu 3
									(x>=150&& x<=450)&&(y>=410&&y<=490)||//thu 4
									(x>=150&& x<=450)&&(y>=500&&y<=580)||//thu 5
									(x>=150&& x<=450)&&(y>=590&&y<=670)||// thu 6
									(x>=150&& x<=450)&&(y>=680&&y<=760)||// thu 7
									(x>=150&& x<=450)&&(y>=770&&y<=850)){ //chu nhat
				//bar(720,210,980,270);
	//bar(1131,210,1450,270);
	//bar(821,430+10,1450,530-10);
			break;
		}
	}
					}else if(ch == '\b' && !min.empty()) {
               			 min.pop_back();
           		 	}else min+=ch;
						
				}
					
			}
			
			
			outtextxy(1131,215,const_cast<char*>(min.c_str()));
			outtextxy(720,215,const_cast<char*>(hours.c_str()));
			//bat tat
			if((x>=821&&x<=1450)&&(y>=440&&y<=520)){
				if(d==1){
					d=0;
					system("start lichon.exe");
					
					setfillstyle(SOLID_FILL,GREEN);
					bar(821,430+10,1450,530-10);
				}else if(d==0){
					system(command.c_str());
					removeFromStartup();
					d=1;
					setfillstyle(SOLID_FILL,RED);
					bar(821,430+10,1450,530-10);
				}
				while(true){
					while(!ismouseclick(WM_LBUTTONDOWN)) delay(10); 
					getmouseclick(WM_LBUTTONDOWN,x,y);
							if((x>=30 &&x<=200)&&(y>=30&&y<200)||//tro ve
									(x>=1290&& x<=1550)&&(y>=709&&y<=809)||//xac nhan
									(x>=720&&x<=980)&&(y>=210&&y<=270)||(x>=1131&&x<=1450)&&(y>=210&&y<=270)||(x>=821&&x<=1450)&&(y>=440&&y<=520)|| //nhap gio phut bao cao
									(x>=150&& x<=450)&&(y>=230&&y<=310)||//thu2
									(x>=150&& x<=450)&&(y>=320&&y<=400)||//thu 3
									(x>=150&& x<=450)&&(y>=410&&y<=490)||//thu 4
									(x>=150&& x<=450)&&(y>=500&&y<=580)||//thu 5
									(x>=150&& x<=450)&&(y>=590&&y<=670)||// thu 6
									(x>=150&& x<=450)&&(y>=680&&y<=760)||// thu 7
									(x>=150&& x<=450)&&(y>=770&&y<=850)){ //chu nhat
				//bar(720,210,980,270);
	//bar(1131,210,1450,270);
	//bar(821,430+10,1450,530-10);
			break;
		}
				}
			}
			/*(x>=150&& x<=450)&&(y>=230&&y<=310)||//thu2
			(x>=150&& x<=450)&&(y>=320&&y<=400)||//thu 3
			(x>=150&& x<=450)&&(y>=410&&y<=490)||//thu 4
			(x>=150&& x<=450)&&(y>=500&&y<=580)||//thu 5
			(x>=150&& x<=450)&&(y>=590&&y<=670)||// thu 6
			(x>=150&& x<=450)&&(y>=680&&y<=760)||// thu 7
			(x>=150&& x<=450)&&(y>=770&&y<=850)*/
			if((x>=150&& x<=450)&&(y>=230&&y<=310)){
				thu = 1;
				//
				setfillstyle(SOLID_FILL,YELLOW);
		       		setbkcolor(YELLOW);
		       		setcolor(BLACK);
					bar(150,230,450,310);
					outtextxy(225-60,250,"Monday");	 //	bar(150+x,330+y,450+x,410+y);bar(150+x,420+y,450+x,500+y);bar(150+x,510+y,450+x,590+y);	bar(150+x,510+y,450+x,590+y);bar(150+x,600+y,450+x,680+y);bar(150+x,690+y,450+x,770+y);bar(150+x,780+y,450+x,860+y);bar(150+x,870+y,450+x,950+y);
					//thu 3											
					bar(150,320,450,400);			
					outtextxy(225-60,340,"Tuesday"); 
					//thu 4
					bar(150,410,450,490);
					outtextxy(225-60,430,"Wednesday");
					//thu 5
					bar(150,500,450,580);
					outtextxy(225-60,520,"Thursday");
					//thu 6
					bar(150,590,450,670);
					outtextxy(225-60,610,"Friday");
					//thu 7
					bar(150,680,450,760);
					outtextxy(225-60,690,"Saturday");
					//chu nhat
					bar(150,770,450,850);
					outtextxy(225-60,780,"Sunday");
		       	
		       	setcolor(WHITE);
				//
				setfillstyle(SOLID_FILL,GREEN);
				bar(150,230,450,310);
				setbkcolor(GREEN);	
				outtextxy(225-60,250,"Monday");
				setbkcolor(LIGHTGRAY);	
				while(true){
					while(!ismouseclick(WM_LBUTTONDOWN)) delay(10); 
					getmouseclick(WM_LBUTTONDOWN,x,y);
							if((x>=30 &&x<=200)&&(y>=30&&y<200)||//tro ve
									(x>=1290&& x<=1550)&&(y>=709&&y<=809)||//xac nhan
									(x>=720&&x<=980)&&(y>=210&&y<=270)||(x>=1131&&x<=1450)&&(y>=210&&y<=270)||(x>=821&&x<=1450)&&(y>=440&&y<=520)|| //nhap gio phut bao cao
									(x>=150&& x<=450)&&(y>=230&&y<=310)||//thu2
									(x>=150&& x<=450)&&(y>=320&&y<=400)||//thu 3
									(x>=150&& x<=450)&&(y>=410&&y<=490)||//thu 4
									(x>=150&& x<=450)&&(y>=500&&y<=580)||//thu 5
									(x>=150&& x<=450)&&(y>=590&&y<=670)||// thu 6
									(x>=150&& x<=450)&&(y>=680&&y<=760)||// thu 7
									(x>=150&& x<=450)&&(y>=770&&y<=850)){ //chu nhat
				//bar(720,210,980,270);
	//bar(1131,210,1450,270);
	//bar(821,430+10,1450,530-10);
			break;
		}
				}
				  
				
		       }
		       if((x>=150&& x<=450)&&(y>=320&&y<=400)){
		       	//
		       		setfillstyle(SOLID_FILL,YELLOW);
		       		setbkcolor(YELLOW);
		       		setcolor(BLACK);
					bar(150,230,450,310);
					outtextxy(225-60,250,"Monday");	 //	bar(150+x,330+y,450+x,410+y);bar(150+x,420+y,450+x,500+y);bar(150+x,510+y,450+x,590+y);	bar(150+x,510+y,450+x,590+y);bar(150+x,600+y,450+x,680+y);bar(150+x,690+y,450+x,770+y);bar(150+x,780+y,450+x,860+y);bar(150+x,870+y,450+x,950+y);
					//thu 3											
					bar(150,320,450,400);			
					outtextxy(225-60,340,"Tuesday"); 
					//thu 4
					bar(150,410,450,490);
					outtextxy(225-60,430,"Wednesday");
					//thu 5
					bar(150,500,450,580);
					outtextxy(225-60,520,"Thursday");
					//thu 6
					bar(150,590,450,670);
					outtextxy(225-60,610,"Friday");
					//thu 7
					bar(150,680,450,760);
					outtextxy(225-60,690,"Saturday");
					//chu nhat
					bar(150,770,450,850);
					outtextxy(225-60,780,"Sunday");
		       	
		       	setcolor(WHITE);
		       	
		       	//
				thu = 2;
				setfillstyle(SOLID_FILL,GREEN);
				bar(150,320,450,400);
				setbkcolor(GREEN);	
				outtextxy(205-40,340,"Tuesday");
				setbkcolor(LIGHTGRAY);	
				while(true){
					while(!ismouseclick(WM_LBUTTONDOWN)) delay(10); 
					getmouseclick(WM_LBUTTONDOWN,x,y);
							if((x>=30 &&x<=200)&&(y>=30&&y<200)||//tro ve
									(x>=1290&& x<=1550)&&(y>=709&&y<=809)||//xac nhan
									(x>=720&&x<=980)&&(y>=210&&y<=270)||(x>=1131&&x<=1450)&&(y>=210&&y<=270)||(x>=821&&x<=1450)&&(y>=440&&y<=520)|| //nhap gio phut bao cao
									(x>=150&& x<=450)&&(y>=230&&y<=310)||//thu2
									(x>=150&& x<=450)&&(y>=320&&y<=400)||//thu 3
									(x>=150&& x<=450)&&(y>=410&&y<=490)||//thu 4
									(x>=150&& x<=450)&&(y>=500&&y<=580)||//thu 5
									(x>=150&& x<=450)&&(y>=590&&y<=670)||// thu 6
									(x>=150&& x<=450)&&(y>=680&&y<=760)||// thu 7
									(x>=150&& x<=450)&&(y>=770&&y<=850)){ //chu nhat
				//bar(720,210,980,270);
	//bar(1131,210,1450,270);
	//bar(821,430+10,1450,530-10);
			break;
		}
				}
				  
				
		       }
		if((x>=150&& x<=450)&&(y>=410&&y<=490)){
		       	//
		       		setfillstyle(SOLID_FILL,YELLOW);
		       		setbkcolor(YELLOW);
		       		setcolor(BLACK);
					bar(150,230,450,310);
					outtextxy(225-60,250,"Monday");	 //	bar(150+x,330+y,450+x,410+y);bar(150+x,420+y,450+x,500+y);bar(150+x,510+y,450+x,590+y);	bar(150+x,510+y,450+x,590+y);bar(150+x,600+y,450+x,680+y);bar(150+x,690+y,450+x,770+y);bar(150+x,780+y,450+x,860+y);bar(150+x,870+y,450+x,950+y);
					//thu 3											
					bar(150,320,450,400);			
					outtextxy(225-60,340,"Tuesday"); 
					//thu 4
					bar(150,410,450,490);
					outtextxy(225-60,430,"Wednesday");
					//thu 5
					bar(150,500,450,580);
					outtextxy(225-60,520,"Thursday");
					//thu 6
					bar(150,590,450,670);
					outtextxy(225-60,610,"Friday");
					//thu 7
					bar(150,680,450,760);
					outtextxy(225-60,690,"Saturday");
					//chu nhat
					bar(150,770,450,850);
					outtextxy(225-60,780,"Sunday");
		       	
		       	setcolor(WHITE);
		       	
		       	//
				thu = 3;
				setfillstyle(SOLID_FILL,GREEN);
				bar(150,410,450,490);
				setbkcolor(GREEN);	
				outtextxy(205-40,430,"Wednesday");
				setbkcolor(LIGHTGRAY);	
				while(true){
					while(!ismouseclick(WM_LBUTTONDOWN)) delay(10); 
					getmouseclick(WM_LBUTTONDOWN,x,y);
							if((x>=30 &&x<=200)&&(y>=30&&y<200)||//tro ve
									(x>=1290&& x<=1550)&&(y>=709&&y<=809)||//xac nhan
									(x>=720&&x<=980)&&(y>=210&&y<=270)||(x>=1131&&x<=1450)&&(y>=210&&y<=270)||(x>=821&&x<=1450)&&(y>=440&&y<=520)|| //nhap gio phut bao cao
									(x>=150&& x<=450)&&(y>=230&&y<=310)||//thu2
									(x>=150&& x<=450)&&(y>=320&&y<=400)||//thu 3
									(x>=150&& x<=450)&&(y>=410&&y<=490)||//thu 4
									(x>=150&& x<=450)&&(y>=500&&y<=580)||//thu 5
									(x>=150&& x<=450)&&(y>=590&&y<=670)||// thu 6
									(x>=150&& x<=450)&&(y>=680&&y<=760)||// thu 7
									(x>=150&& x<=450)&&(y>=770&&y<=850)){ //chu nhat
				//bar(720,210,980,270);
	//bar(1131,210,1450,270);
	//bar(821,430+10,1450,530-10);
			break;
		}
				}
				  
				
		       }
		    if((x>=150&& x<=450)&&(y>=500&&y<=580)){
		       	//
		       		setfillstyle(SOLID_FILL,YELLOW);
		       		setbkcolor(YELLOW);
		       		setcolor(BLACK);
					bar(150,230,450,310);
					outtextxy(225-60,250,"Monday");	 //	bar(150+x,330+y,450+x,410+y);bar(150+x,420+y,450+x,500+y);bar(150+x,510+y,450+x,590+y);	bar(150+x,510+y,450+x,590+y);bar(150+x,600+y,450+x,680+y);bar(150+x,690+y,450+x,770+y);bar(150+x,780+y,450+x,860+y);bar(150+x,870+y,450+x,950+y);
					//thu 3											
					bar(150,320,450,400);			
					outtextxy(225-60,340,"Tuesday"); 
					//thu 4
					bar(150,410,450,490);
					outtextxy(225-60,430,"Wednesday");
					//thu 5
					bar(150,500,450,580);
					outtextxy(225-60,520,"Thursday");
					//thu 6
					bar(150,590,450,670);
					outtextxy(225-60,610,"Friday");
					//thu 7
					bar(150,680,450,760);
					outtextxy(225-60,690,"Saturday");
					//chu nhat
					bar(150,770,450,850);
					outtextxy(225-60,780,"Sunday");
		       	
		       	setcolor(WHITE);
		       	
		       	//
				thu = 4;
				setfillstyle(SOLID_FILL,GREEN);
				bar(150,500,450,580);
				setbkcolor(GREEN);	
				outtextxy(205-40,520,"Thursday");
				setbkcolor(LIGHTGRAY);	
				while(true){
					while(!ismouseclick(WM_LBUTTONDOWN)) delay(10); 
					getmouseclick(WM_LBUTTONDOWN,x,y);
							if((x>=30 &&x<=200)&&(y>=30&&y<200)||//tro ve
									(x>=1290&& x<=1550)&&(y>=709&&y<=809)||//xac nhan
									(x>=720&&x<=980)&&(y>=210&&y<=270)||(x>=1131&&x<=1450)&&(y>=210&&y<=270)||(x>=821&&x<=1450)&&(y>=440&&y<=520)|| //nhap gio phut bao cao
									(x>=150&& x<=450)&&(y>=230&&y<=310)||//thu2
									(x>=150&& x<=450)&&(y>=320&&y<=400)||//thu 3
									(x>=150&& x<=450)&&(y>=410&&y<=490)||//thu 4
									(x>=150&& x<=450)&&(y>=500&&y<=580)||//thu 5
									(x>=150&& x<=450)&&(y>=590&&y<=670)||// thu 6
									(x>=150&& x<=450)&&(y>=680&&y<=760)||// thu 7
									(x>=150&& x<=450)&&(y>=770&&y<=850)){ //chu nhat
				//bar(720,210,980,270);
	//bar(1131,210,1450,270);
	//bar(821,430+10,1450,530-10);
			break;
		}
				}
				  
				
		       }
		    if((x>=150&& x<=450)&&(y>=590&&y<=670)){
		       	//
		       		setfillstyle(SOLID_FILL,YELLOW);
		       		setbkcolor(YELLOW);
		       		setcolor(BLACK);
					bar(150,230,450,310);
					outtextxy(225-60,250,"Monday");	 //	bar(150+x,330+y,450+x,410+y);bar(150+x,420+y,450+x,500+y);bar(150+x,510+y,450+x,590+y);	bar(150+x,510+y,450+x,590+y);bar(150+x,600+y,450+x,680+y);bar(150+x,690+y,450+x,770+y);bar(150+x,780+y,450+x,860+y);bar(150+x,870+y,450+x,950+y);
					//thu 3											
					bar(150,320,450,400);			
					outtextxy(225-60,340,"Tuesday"); 
					//thu 4
					bar(150,410,450,490);
					outtextxy(225-60,430,"Wednesday");
					//thu 5
					bar(150,500,450,580);
					outtextxy(225-60,520,"Thursday");
					//thu 6
					bar(150,590,450,670);
					outtextxy(225-60,610,"Friday");
					//thu 7
					bar(150,680,450,760);
					outtextxy(225-60,690,"Saturday");
					//chu nhat
					bar(150,770,450,850);
					outtextxy(225-60,780,"Sunday");
		       	
		       	setcolor(WHITE);
		       	
		       	//
				thu = 5;
				setfillstyle(SOLID_FILL,GREEN);
				bar(150,590,450,670);
				setbkcolor(GREEN);	
				outtextxy(205-40,610,"Friday");
				setbkcolor(LIGHTGRAY);	
				while(true){
					while(!ismouseclick(WM_LBUTTONDOWN)) delay(10); 
					getmouseclick(WM_LBUTTONDOWN,x,y);
							if((x>=30 &&x<=200)&&(y>=30&&y<200)||//tro ve
									(x>=1290&& x<=1550)&&(y>=709&&y<=809)||//xac nhan
									(x>=720&&x<=980)&&(y>=210&&y<=270)||(x>=1131&&x<=1450)&&(y>=210&&y<=270)||(x>=821&&x<=1450)&&(y>=440&&y<=520)|| //nhap gio phut bao cao
									(x>=150&& x<=450)&&(y>=230&&y<=310)||//thu2
									(x>=150&& x<=450)&&(y>=320&&y<=400)||//thu 3
									(x>=150&& x<=450)&&(y>=410&&y<=490)||//thu 4
									(x>=150&& x<=450)&&(y>=500&&y<=580)||//thu 5
									(x>=150&& x<=450)&&(y>=590&&y<=670)||// thu 6
									(x>=150&& x<=450)&&(y>=680&&y<=760)||// thu 7
									(x>=150&& x<=450)&&(y>=770&&y<=850)){ //chu nhat
				//bar(720,210,980,270);
	//bar(1131,210,1450,270);
	//bar(821,430+10,1450,530-10);
			break;
		}
				}
				  
				
		       }
		    if((x>=150&& x<=450)&&(y>=680&&y<=760)){
		       	//
		       		setfillstyle(SOLID_FILL,YELLOW);
		       		setbkcolor(YELLOW);
		       		setcolor(BLACK);
					bar(150,230,450,310);
					outtextxy(225-60,250,"Monday");	 //	bar(150+x,330+y,450+x,410+y);bar(150+x,420+y,450+x,500+y);bar(150+x,510+y,450+x,590+y);	bar(150+x,510+y,450+x,590+y);bar(150+x,600+y,450+x,680+y);bar(150+x,690+y,450+x,770+y);bar(150+x,780+y,450+x,860+y);bar(150+x,870+y,450+x,950+y);
					//thu 3											
					bar(150,320,450,400);			
					outtextxy(225-60,340,"Tuesday"); 
					//thu 4
					bar(150,410,450,490);
					outtextxy(225-60,430,"Wednesday");
					//thu 5
					bar(150,500,450,580);
					outtextxy(225-60,520,"Thursday");
					//thu 6
					bar(150,590,450,670);
					outtextxy(225-60,610,"Friday");
					//thu 7
					bar(150,680,450,760);
					outtextxy(225-60,690,"Saturday");
					//chu nhat
					bar(150,770,450,850);
					outtextxy(225-60,780,"Sunday");
		       	
		       	setcolor(WHITE);
		       	
		       	//
				thu = 6;
				setfillstyle(SOLID_FILL,GREEN);
				bar(150,680,450,760);
				setbkcolor(GREEN);	
				outtextxy(205-40,690,"Saturday");
				setbkcolor(LIGHTGRAY);	
				while(true){
					while(!ismouseclick(WM_LBUTTONDOWN)) delay(10); 
					getmouseclick(WM_LBUTTONDOWN,x,y);
							if((x>=30 &&x<=200)&&(y>=30&&y<200)||//tro ve
									(x>=1290&& x<=1550)&&(y>=709&&y<=809)||//xac nhan
									(x>=720&&x<=980)&&(y>=210&&y<=270)||(x>=1131&&x<=1450)&&(y>=210&&y<=270)||(x>=821&&x<=1450)&&(y>=440&&y<=520)|| //nhap gio phut bao cao
									(x>=150&& x<=450)&&(y>=230&&y<=310)||//thu2
									(x>=150&& x<=450)&&(y>=320&&y<=400)||//thu 3
									(x>=150&& x<=450)&&(y>=410&&y<=490)||//thu 4
									(x>=150&& x<=450)&&(y>=500&&y<=580)||//thu 5
									(x>=150&& x<=450)&&(y>=590&&y<=670)||// thu 6
									(x>=150&& x<=450)&&(y>=680&&y<=760)||// thu 7
									(x>=150&& x<=450)&&(y>=770&&y<=850)){ //chu nhat
				//bar(720,210,980,270);
	//bar(1131,210,1450,270);
	//bar(821,430+10,1450,530-10);
			break;
		}
				}
				  
				
		       }
		    if((x>=150&& x<=450)&&(y>=770&&y<=850)){
		       	//
		       		setfillstyle(SOLID_FILL,YELLOW);
		       		setbkcolor(YELLOW);
		       		setcolor(BLACK);
					bar(150,230,450,310);
					outtextxy(225-60,250,"Monday");	 //	bar(150+x,330+y,450+x,410+y);bar(150+x,420+y,450+x,500+y);bar(150+x,510+y,450+x,590+y);	bar(150+x,510+y,450+x,590+y);bar(150+x,600+y,450+x,680+y);bar(150+x,690+y,450+x,770+y);bar(150+x,780+y,450+x,860+y);bar(150+x,870+y,450+x,950+y);
					//thu 3											
					bar(150,320,450,400);			
					outtextxy(225-60,340,"Tuesday"); 
					//thu 4
					bar(150,410,450,490);
					outtextxy(225-60,430,"Wednesday");
					//thu 5
					bar(150,500,450,580);
					outtextxy(225-60,520,"Thursday");
					//thu 6
					bar(150,590,450,670);
					outtextxy(225-60,610,"Friday");
					//thu 7
					bar(150,680,450,760);
					outtextxy(225-60,690,"Saturday");
					//chu nhat
					bar(150,770,450,850);
					outtextxy(225-60,780,"Sunday");
		       	
		       	setcolor(WHITE);
		       	
		       	//
				thu = 0;
				setfillstyle(SOLID_FILL,GREEN);
				bar(150,770,450,850);
				setbkcolor(GREEN);	
				outtextxy(205-40,780,"Sunday");
				setbkcolor(LIGHTGRAY);	
				while(true){
					while(!ismouseclick(WM_LBUTTONDOWN)) delay(10); 
					getmouseclick(WM_LBUTTONDOWN,x,y);
							if((x>=30 &&x<=200)&&(y>=30&&y<200)||//tro ve
									(x>=1290&& x<=1550)&&(y>=709&&y<=809)||//xac nhan
									(x>=720&&x<=980)&&(y>=210&&y<=270)||(x>=1131&&x<=1450)&&(y>=210&&y<=270)||(x>=821&&x<=1450)&&(y>=440&&y<=520)|| //nhap gio phut bao cao
									(x>=150&& x<=450)&&(y>=230&&y<=310)||//thu2
									(x>=150&& x<=450)&&(y>=320&&y<=400)||//thu 3
									(x>=150&& x<=450)&&(y>=410&&y<=490)||//thu 4
									(x>=150&& x<=450)&&(y>=500&&y<=580)||//thu 5
									(x>=150&& x<=450)&&(y>=590&&y<=670)||// thu 6
									(x>=150&& x<=450)&&(y>=680&&y<=760)||// thu 7
									(x>=150&& x<=450)&&(y>=770&&y<=850)){ //chu nhat
				//bar(720,210,980,270);
	//bar(1131,210,1450,270);
	//bar(821,430+10,1450,530-10);
			break;
		}
				}
				  
				
		       }
			if((x>=1290&& x<=1550)&&(y>=709&&y<=809)){
				int h= atoi(hours.c_str());
				int m = atoi(min.c_str());
				if(m<0||m>59||h>24||h<1||hours==""||min==""||thu==10||d==1){
					
					manhinhloi();
					delay(3000);
					cleardevice();
					hienthi=8;
					break;
				}
				else{
					cleardevice(); 
							manhinhxacnhan();
							while(true){
								while(!ismouseclick(WM_LBUTTONDOWN)) delay(10); 
								getmouseclick(WM_LBUTTONDOWN,x,y);
										if(((x>=420 && x<=600)&&(y>=480&&y<=550))||((x>=1000 && x<=1180)&&(y>=480&&y<=550))){ //chu nhat
							//bar(720,210,980,270);
						break;
						}
						
				//bar(1131,210,1450,270);
				//bar(821,430+10,1450,530-10);
				
							}
							if((x>=420 && x<=600)&&(y>=480&&y<=550)){
								ofstream file(TEXTNAME,ios::app);
								file<<thu<<endl;
								file<<hours<<endl;
								file<<min<<"\n";
								system(command.c_str());
								system( "start lichon.exe");
								hienthi=8;
								break;
								
							}	if((x>=1000 && x<=1180)&&(y>=480&&y<=550)){
								hienthi=8;
								break;
							}
					
				}
				
				
				
							
			
			
		}

			if((x>=30 &&x<=200)&&(y>=30&&y<200)){
				cleardevice();	
				hienthi=1;
				break;
				}

		
}
		
}










//
int main(){
	GiaoDien giaoDien;
	string line;
	ifstream inFile(FILENAME);
	int x,y,count=0,chuDe=0;
	int hienthi=1; // Menu bat dau
	char temp[20];// hien thi diem
	srand(time(0));//sinh random
	int diem = 0;
	vector<QA> wrongQA;
	initwindow(1600,900);
	HWND hwnd = FindWindow(NULL, "Windows BGI");
	SetWindowText(hwnd, "Phan mem cau hoi trac nghiem");
	while(true){
		setbkcolor(BLACK);
		setfillstyle(SOLID_FILL,BLACK);
		setcolor(WHITE);
		if(hienthi==1){
			ChucNangMenu(hienthi,chuDe);
			delay(10);
		}
		else if(hienthi==2){ // Menu them cau hoi => hienthi=2
			int theLoai=0;
			cleardevice();
			settextstyle(GOTHIC_FONT,0,5);
			ChucNangThemCauHoi(hienthi,chuDe);
		//	clearmouseclick(WM_LBUTTONDOWN);
			continue;
		}
		else if(hienthi==3){// Menu lam bai hien thi =3
			vector<QA> listQA;
			if(chuDe == 1) FILEREAD = FILENAME2;
			else if (chuDe == 2) FILEREAD = FILENAME3;
			else FILEREAD = FILENAME4;
			ifstream inFile(FILEREAD);
			while(getline(inFile,line)){
				QA a;
				a.setQuestion(line);
				getline(inFile,line);
				a.setAnswer(line);
				getline(inFile,line);
				a.setChoiceA(line);
				getline(inFile,line);
				a.setChoiceB(line);
				getline(inFile,line);
				a.setChoiceC(line);
				getline(inFile,line);
				a.setChoiceD(line);
				listQA.push_back(a);
	}
			inFile.close();
			vector<QA> tempQA(listQA);
			bool coRandom;
			ChucNangLuaChonRandom(coRandom);
			if(coRandom==1){
				while(true){
					int random = 0 + rand() % (tempQA.size());
					setbkcolor(BLACK);
					setfillstyle(SOLID_FILL,BLACK);
					cleardevice();
					sprintf(temp, "%d", diem);
					tempQA[random].TronDapAn();
					giaoDien.ManHinhLamBai(tempQA[random]);
					setbkcolor(LIGHTBLUE);
					outtextxy(1200,50,(char*)"Score: ");
					setcolor(RED);
					settextstyle(GOTHIC_FONT,0,8);
					outtextxy(1465,30,temp);
					setcolor(BLACK);
					clearmouseclick(WM_LBUTTONDOWN);
					while(!ismouseclick(WM_LBUTTONDOWN)){
					delay(10);
			}
					clickmouse(tempQA[random],diem,wrongQA);
					tempQA.erase(tempQA.begin()+random);
					if(tempQA.size() == 0){
						delay(2000);
						ChucNangHoanThanhLamBai(listQA,diem,hienthi,count);
						break;
					}
					else{
						delay(2000);
					}
			}
		}
			else{
				int i =0;
				while(true){
					setbkcolor(BLACK);
					setfillstyle(SOLID_FILL,BLACK);
					cleardevice();
					sprintf(temp, "%d", diem);
					giaoDien.ManHinhLamBai(tempQA[i]);
					clearmouseclick(WM_LBUTTONDOWN);
					setbkcolor(LIGHTBLUE);
					outtextxy(1200,50,(char*)"Score: ");
					setcolor(RED);
					settextstyle(GOTHIC_FONT,0,8);
					outtextxy(1465,30,temp);
					setcolor(BLACK);
					while(!ismouseclick(WM_LBUTTONDOWN)){
					delay(10);
					}
					clickmouse(tempQA[i],diem,wrongQA);
					i++;
					if(tempQA.size() == i){
						delay(2000);
						ChucNangHoanThanhLamBai(listQA,diem,hienthi,count);
						break;
					}
					else{
						delay(2000);
					}
			}
		}	
	}
		else if(hienthi == 4){// Menu lam lai cau hoi hienthi=4
			vector<QA> listQA;
			if(chuDe == 1) FILEREAD = FILENAME2;
			else if (chuDe == 2) FILEREAD = FILENAME3;
			else FILEREAD = FILENAME4;
			ifstream inFile(FILEREAD);
			while(getline(inFile,line)){
				QA a;
				a.setQuestion(line);
				getline(inFile,line);
				a.setAnswer(line);
				getline(inFile,line);
				a.setChoiceA(line);
				getline(inFile,line);
				a.setChoiceB(line);
				getline(inFile,line);
				a.setChoiceC(line);
				getline(inFile,line);
				a.setChoiceD(line);
				listQA.push_back(a);
	}
			inFile.close();
			while(true){
				int random = 0 + rand() % (wrongQA.size());
				setbkcolor(BLACK);
				setfillstyle(SOLID_FILL,BLACK);
				cleardevice();
				setcolor(RED);
				sprintf(temp, "%d", diem);
				wrongQA[random].TronDapAn();
				giaoDien.ManHinhLamBai(wrongQA[random]);
				setbkcolor(LIGHTBLUE);
				outtextxy(1200,50,(char*)"Score: ");
				setcolor(RED);
				settextstyle(GOTHIC_FONT,0,8);
				outtextxy(1465,30,temp);
				setcolor(BLACK);
				clearmouseclick(WM_LBUTTONDOWN);
				while(!ismouseclick(WM_LBUTTONDOWN)){
				delay(10);
		}
				clickmouse(wrongQA[random],diem,wrongQA);
				wrongQA.erase(wrongQA.begin()+random);
				if(wrongQA.size() == 0){
					delay(2000);
					ChucNangHoanThanhLamBai(listQA,diem,hienthi,count);
					break;
				}
				else{
					delay(2000);
				}
			}
		}
		else if(hienthi==5){ // Hienthi=5 menu chua co cau hoi
			giaoDien.MenuChuaCoCauHoi();
			delay(2000);
			cleardevice();
			hienthi=1;
		}
		else if(hienthi==6) {// Hienthi =6 sua cau hoi
			settextstyle(GOTHIC_FONT,0,5);
			ChucNangSuaCauHoi(hienthi,chuDe);
		}
		else if(hienthi == 7){ //Hien thi =7 xoa cau hoi
			if(chuDe == 1) FILEREAD = FILENAME2;
			else if (chuDe == 2) FILEREAD = FILENAME3;
			else FILEREAD = FILENAME4;
			xoa(FILEREAD);
			hienthi=1;
}
		else if(hienthi ==8){//Hien thi =8 dat lich
			lichontap(hienthi);
			continue;
		}
}
	getch();
	closegraph();
	return 0;
}
