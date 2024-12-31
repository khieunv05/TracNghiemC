#include<graphics.h>
#include<iostream>
#include<string>
#include<cstdlib>
#include<ctime>
#include<fstream>
#include<vector>
#include<windows.h>
#include "QA.h"
using namespace std;
class GiaoDien{
	public:
		void ManHinhLamBai(QA listQA){
			setfillstyle(SOLID_FILL,WHITE);
			bar(0,0,getmaxx(),getmaxy());
			setfillstyle(SOLID_FILL,BLUE);
			bar(0,0,getmaxx(),70);
			bar(0,0,30,getmaxy());
			bar(getmaxx(),0,getmaxx()-30,getmaxy());
			bar(0,getmaxy()-30,getmaxx(),getmaxy());
			setfillstyle(SOLID_FILL,LIGHTBLUE);
			bar(30,30,getmaxx()-30,120);
			setbkcolor(LIGHTBLUE);
			setcolor(WHITE);
			settextstyle(GOTHIC_FONT,0,5);
			outtextxy(600,50,(char *)"Take Quiz");
			//cauhoi
			rectangle(200,150,getmaxx()-200,270);
			setfillstyle(SOLID_FILL,LIGHTGRAY);			
			bar(199,151,getmaxx()-199,269);
			//dapan A
			rectangle(100,320,getmaxx()-100,420);
			setfillstyle(SOLID_FILL,LIGHTGRAY);		
			bar(99,321,getmaxx()-99,419);
			//dapanB
			rectangle(100,430,getmaxx()-100,530);
			setfillstyle(SOLID_FILL,LIGHTGRAY);
			bar(99,431,getmaxx()-99,529);
			//dapanC
			rectangle(100,540,getmaxx()-100,640);
			setfillstyle(SOLID_FILL,LIGHTGRAY);
			bar(99,541,getmaxx()-99,639);
			//dapanD
			rectangle(100,650,getmaxx()-100,750);
			setfillstyle(SOLID_FILL,LIGHTGRAY);
			bar(99,651,getmaxx()-99,749);
			
			setcolor(BLACK);
			setbkcolor(LIGHTGRAY);
			outtextxy(230,170,const_cast<char*> (listQA.getQuestion().c_str()));	
			outtextxy(130,340,const_cast<char*> (listQA.getChoiceA().c_str()));
			outtextxy(130,450,const_cast<char*> (listQA.getChoiceB().c_str()));
			outtextxy(130,560,const_cast<char*> (listQA.getChoiceC().c_str()));
			outtextxy(130,670,const_cast<char*> (listQA.getChoiceD().c_str()));
}
		void MenuChuaCoCauHoi(){
			settextstyle(GOTHIC_FONT,0,5);
			setfillstyle(SOLID_FILL,LIGHTGRAY);
			setbkcolor(LIGHTGRAY);
			setcolor(BLACK);
			bar(350,250,1350,600);
			outtextxy(400,400,(char *)"You have no questions yet");
}
		void menu(){
			setfillstyle(SOLID_FILL,WHITE);
			bar(0,0,getmaxx(),getmaxy());
			setbkcolor(BLACK);
			setcolor(BLACK);
			setfillstyle(SOLID_FILL,BLUE);
			bar(0,0,getmaxx(),100);
			int x1,y1;
			settextstyle(GOTHIC_FONT,0,5);
			setbkcolor(YELLOW);
			setfillstyle(SOLID_FILL,YELLOW);
			bar(450,50,1200,120);
			outtextxy(575,70,(char *)"QUIZ PRACTICE");
			bar(550,180,1100,250);
			outtextxy(650,200,(char *)"Take Quiz");
			bar(550,320,1100,390);
			outtextxy(650,340,(char *)"Add Question");
			bar(550,460,1100,530);
			outtextxy(650,480,(char *)"Edit Question");
			bar(550,600,1100,670);
			outtextxy(650,620,(char *)"Del Question");
			bar(550,740,1100,810);
			outtextxy(650,760,(char *)"Set Reminder");
			int point[] = {0,900,0,580,200,900};
			setfillstyle(SOLID_FILL,LIGHTGRAY);
			fillpoly(4,point);
			int point2[]={1600,900,1600,580,1400,900};
			fillpoly(4,point2);
			readimagefile((char *)"XoaCauHoi.bmp",550,600,620,670);
			readimagefile((char *)"DatLich.bmp",550,740,620,810);
			readimagefile((char *)"SuaCauHoi.bmp",550,460,650,530);
			readimagefile((char *)"ThemCauHoi.bmp",550,320,650,390);
			readimagefile((char *)"TrangTri2.bmp",200,650,500,800);
			readimagefile((char *)"TrangTri.bmp",1100,650,1400,800);
			readimagefile((char *)"Lambai.bmp",550,180,650,250);
			setcolor(BLUE);
			setfillstyle(SOLID_FILL,BLUE);
			bar(0,0,30,getmaxy());
			bar(0,0,getmaxx(),30);
			bar(getmaxx()-30,0,getmaxx(),getmaxy());
			bar(0,getmaxy()-30,getmaxx(),getmaxy());
			
	
			//readimagefile("Test2.bmp",0,0,getmaxx(),getmaxy());
}
		void ManHinhMenuThemCauHoi(string question,string cA,string cB,string cC,string cD){
			setfillstyle(SOLID_FILL,WHITE);
			bar(0,0,getmaxx(),getmaxy());
			setfillstyle(SOLID_FILL,BLUE);
			bar(0,0,getmaxx(),70);
			bar(0,0,30,getmaxy());
			bar(getmaxx(),0,getmaxx()-30,getmaxy());
			bar(0,getmaxy()-30,getmaxx(),getmaxy());
			setfillstyle(SOLID_FILL,LIGHTBLUE);
			bar(30,30,getmaxx()-30,120);
			setbkcolor(LIGHTBLUE);
			setcolor(WHITE);
			outtextxy(580,50,(char *)"Add Question");
			setcolor(BLACK);
			outtextxy(getmaxx()-220,50,(char *)"Finish");
			setfillstyle(SOLID_FILL,BLACK);
			bar(getmaxx()-235,30,getmaxx()-230,120);//vach den
			
			setbkcolor(LIGHTGRAY);
			//boi xam phan dap an
			setfillstyle(SOLID_FILL,LIGHTGRAY);
			bar(1100,180,1400,250);
			rectangle(1100,180,1400,250);//dap an
			outtextxy(1120,195,(char *)"Answer");
			//boi xam phan nhap cau hoi
			rectangle(100,170,900,270);
			bar(100,170,900,270);
			bar(150,300,850,400);
			bar(1120,300,1330,400);
			bar(150,430,850,530);
			bar(1120,430,1330,530);
			bar(150,560,850,660);
			bar(1120,560,1330,660);
			bar(150,690,850,790);
			bar(1120,690,1330,790);
			rectangle(150,300,850,400);
			setbkcolor(LIGHTBLUE);
			outtextxy(50,50,(char *)"Back");
			
			rectangle(1120,300,1330,400);//hinh vuong A
			//outtextxy(110,240,(char *)"Nhap lua chon A");
			rectangle(150,430,850,530);
			rectangle(1120,430,1330,530);//hinh vuong B
			//outtextxy(110,410,(char *)"Nhap lua chon B");
			rectangle(150,560,850,660);
			rectangle(1120,560,1330,660);//hinh vuong C
			//outtextxy(110,580,(char *)"Nhap lua chon C");
			rectangle(150,690,850,790);
			rectangle(1120,690,1330,790);//hinh vuong A
			//outtextxy(110,750,(char *)"Nhap lua chon D");
			outtextxy(110,180,const_cast<char*>(question.c_str()));
			outtextxy(160,310,const_cast<char*>(cA.c_str()));
			outtextxy(160,440,const_cast<char*>(cB.c_str()));
			outtextxy(160,570,const_cast<char*>(cC.c_str()));
			outtextxy(160,700,const_cast<char*>(cD.c_str()));
			
}
		void ManHinhMenuSuaCauHoi(string question,string cA,string cB,string cC,string cD){
			setfillstyle(SOLID_FILL,WHITE);
			bar(0,0,getmaxx(),getmaxy());
			setfillstyle(SOLID_FILL,BLUE);
			bar(0,0,getmaxx(),70);
			bar(0,0,30,getmaxy());
			bar(getmaxx(),0,getmaxx()-30,getmaxy());
			bar(0,getmaxy()-30,getmaxx(),getmaxy());
			setfillstyle(SOLID_FILL,LIGHTBLUE);
			bar(30,30,getmaxx()-30,120);
			setbkcolor(LIGHTBLUE);
			setcolor(WHITE);
			outtextxy(580,50,(char *)"Edit question");
			setcolor(BLACK);
			outtextxy(getmaxx()-220,50,(char *)"Finish");
			setfillstyle(SOLID_FILL,BLACK);
			bar(getmaxx()-235,30,getmaxx()-230,120);//vach den
			
			setbkcolor(LIGHTGRAY);
			//boi xam phan dap an
			setfillstyle(SOLID_FILL,LIGHTGRAY);
			bar(1100,180,1400,250);
			rectangle(1100,180,1400,250);//dap an
			outtextxy(1120,195,(char *)"Answer");
			//boi xam phan nhap cau hoi
			rectangle(100,170,900,270);
			bar(100,170,900,270);
			bar(150,300,850,400);
			bar(1120,300,1330,400);
			bar(150,430,850,530);
			bar(1120,430,1330,530);
			bar(150,560,850,660);
			bar(1120,560,1330,660);
			bar(150,690,850,790);
			bar(1120,690,1330,790);
			rectangle(150,300,850,400);
			setbkcolor(LIGHTBLUE);
			outtextxy(50,50,(char *)"Back");
			
			rectangle(1120,300,1330,400);//hinh vuong A
			//outtextxy(110,240,(char *)"Nhap lua chon A");
			rectangle(150,430,850,530);
			rectangle(1120,430,1330,530);//hinh vuong B
			//outtextxy(110,410,(char *)"Nhap lua chon B");
			rectangle(150,560,850,660);
			rectangle(1120,560,1330,660);//hinh vuong C
			//outtextxy(110,580,(char *)"Nhap lua chon C");
			rectangle(150,690,850,790);
			rectangle(1120,690,1330,790);//hinh vuong A
			//outtextxy(110,750,(char *)"Nhap lua chon D");
			outtextxy(110,180,const_cast<char*>(question.c_str()));
			outtextxy(160,310,const_cast<char*>(cA.c_str()));
			outtextxy(160,440,const_cast<char*>(cB.c_str()));
			outtextxy(160,570,const_cast<char*>(cC.c_str()));
			outtextxy(160,700,const_cast<char*>(cD.c_str()));
			
}
		void ManHinhXacNhanThemCauHoi(){
			cleardevice();
			setfillstyle(SOLID_FILL,WHITE);
			bar(0,0,1600,900);
			setfillstyle(SOLID_FILL,BLUE);
			bar(375,150,1225,450);
			setbkcolor(WHITE);
			setfillstyle(SOLID_FILL,YELLOW);
			bar(400,175,1200,425);
			setbkcolor(YELLOW);
			setcolor(BLACK);
			outtextxy(490,200,(char *)"Would you like to add" );outtextxy(490,250,(char *)"a question?");
			outtextxy(450,350,(char *)"Yes");
			outtextxy(980,350,(char *)"No");
			rectangle(440,320,570,420);
			rectangle(970,320,1170,420);
		}
		void ManHinhXacNhanSuaCauHoi(){
			cleardevice();
			setfillstyle(SOLID_FILL,WHITE);
			bar(0,0,1600,900);
			setfillstyle(SOLID_FILL,BLUE);
			bar(375,150,1225,450);
			setbkcolor(WHITE);
			setfillstyle(SOLID_FILL,YELLOW);
			bar(400,175,1200,425);
			setbkcolor(YELLOW);
			setcolor(BLACK);
			outtextxy(490,200,(char *)"Would you like to edit" );outtextxy(490,250,(char *)"a question?");
			outtextxy(450,350,(char *)"Yes");
			outtextxy(980,350,(char *)"No");
			rectangle(440,320,570,420);
			rectangle(970,320,1170,420);
		}
		void ManHinhHoanThanhLamBai(vector<QA> & listQA,int &diem,int &count){
			cleardevice();
			setfillstyle(SOLID_FILL,WHITE);
			bar(0,0,getmaxx(),getmaxy());
			setfillstyle(SOLID_FILL,BLUE);
			bar(0,0,getmaxx(),70);
			bar(0,0,30,getmaxy());
			bar(getmaxx(),0,getmaxx()-30,getmaxy());
			bar(0,getmaxy()-30,getmaxx(),getmaxy());
			setfillstyle(SOLID_FILL,LIGHTBLUE);
			bar(30,30,getmaxx()-30,120);
			setbkcolor(LIGHTBLUE);
			setcolor(WHITE);
			settextstyle(GOTHIC_FONT,0,5);
			//cauhoi
			rectangle(200,150,getmaxx()-200,270);
			setfillstyle(SOLID_FILL,LIGHTGRAY);			
			bar(199,151,getmaxx()-199,269);
			//dapan A
			rectangle(100,320,getmaxx()-100,420);
			setfillstyle(SOLID_FILL,LIGHTGRAY);		
			bar(99,321,getmaxx()-99,419);
			//dapanB
			rectangle(100,430,getmaxx()-100,530);
			setfillstyle(SOLID_FILL,LIGHTGRAY);
			bar(99,431,getmaxx()-99,529);
			//dapanC
			rectangle(100,540,getmaxx()-100,640);
			setfillstyle(SOLID_FILL,LIGHTGRAY);
			bar(99,541,getmaxx()-99,639);
			//dapanD
			rectangle(100,650,getmaxx()-100,750);
			setfillstyle(SOLID_FILL,LIGHTGRAY);
			bar(99,651,getmaxx()-99,749);
			string score = to_string(diem);
			string soCau = to_string(listQA.size());
			string last = score + "/" + soCau;
			setfillstyle(SOLID_FILL,WHITE);
			setfillstyle(SOLID_FILL,BLUE);
			bar(395,150,1205,805);
			setbkcolor(WHITE);
			setfillstyle(SOLID_FILL,LIGHTGRAY);
			bar(400,175,1200,800);
			setbkcolor(LIGHTGRAY);
			setcolor(BLACK);
			settextstyle(GOTHIC_FONT,0,5);
			outtextxy(520,250,(char *)"You have completed " );
			outtextxy(520,400,(char *)"All questions!" );
			settextstyle(GOTHIC_FONT,0,5);
			setcolor(RED);
			setbkcolor(LIGHTGRAY);
			settextstyle(GOTHIC_FONT,0,5);
			setcolor(LIGHTBLUE);
			if(count == 0) 	{
				outtextxy(675,500,(char *)"Score:");
				outtextxy(725,575,const_cast<char*>(last.c_str()));
			}
			setbkcolor(LIGHTGRAY);
			settextstyle(GOTHIC_FONT,0,5);
			setcolor(BLACK);
			outtextxy(450,675,(char *)"Back");
			rectangle(420,650,700,750);
			if(diem != listQA.size() && count==0){
				rectangle(720,650,1200,750);
				outtextxy(730,675,(char *)"Redo wrong");
			}
			setbkcolor(WHITE);
}
		void ManHinhThieuThongTin(){
			cleardevice();
			
			setfillstyle(SOLID_FILL,WHITE);
			bar(0,0,1600,900);
			setfillstyle(SOLID_FILL,BLUE);
			bar(375,150,1225,450);
			setbkcolor(WHITE);
			setfillstyle(SOLID_FILL,YELLOW);
			bar(400,175,1200,425);
			setbkcolor(YELLOW);
			outtextxy(450,350,(char *)"incomplete information!");
			outtextxy(790,250,(char *)"!");
			int i=50,c=0,j=0;
			for(j=0;j<10;j++){
				line(700+i-j,300+c+j,800+i+j,300+c+j);
			line(700+i-j,300+c+j,750+i,200+c-j);
			line(800+i+j,300+c+j,750+i,200+c-j);
			}
			
			delay(2000);
			cleardevice();
		}		
		void ManHinhSuaCauHoi(){
			setfillstyle(SOLID_FILL,BLUE);
			bar(0,0,getmaxx(),70);
			bar(0,0,30,getmaxy());
			bar(getmaxx(),0,getmaxx()-30,getmaxy());
			bar(0,getmaxy()-30,getmaxx(),getmaxy());
			setfillstyle(SOLID_FILL,LIGHTBLUE);
			bar(30,30,getmaxx()-30,120);
			setbkcolor(LIGHTBLUE);
			setcolor(WHITE);
			outtextxy(580,50,(char *)"Edit question");
			setcolor(BLACK);
			setfillstyle(SOLID_FILL,BLACK);
			
			setbkcolor(LIGHTGRAY);
			//boi xam phan dap an
			setbkcolor(LIGHTBLUE);
			outtextxy(50,50,(char *)"Back");
		}
		void ManHinhLuaChonRandom(){
			cleardevice();
			setfillstyle(SOLID_FILL,WHITE);
			bar(0,0,getmaxx(),getmaxy());
			setbkcolor(BLACK);
			setcolor(BLACK);
			setfillstyle(SOLID_FILL,BLUE);
			bar(0,0,getmaxx(),100);
			settextstyle(GOTHIC_FONT,0,5);
			setbkcolor(YELLOW);
			setfillstyle(SOLID_FILL,YELLOW);
			bar(350,50,1100,120);
			outtextxy(500,70,(char *)"QUIZ PRACTICE");
			int point[] = {0,900,0,580,200,900};
			setfillstyle(SOLID_FILL,LIGHTGRAY);
			fillpoly(4,point);
			int point2[]={1600,900,1600,580,1400,900};
			fillpoly(4,point2);
			readimagefile((char *)"TrangTri2.bmp",200,650,500,800);
			readimagefile((char *)"TrangTri.bmp",1100,650,1400,800);
			setcolor(BLUE);
			setfillstyle(SOLID_FILL,BLUE);
			bar(0,0,30,getmaxy());
			bar(0,0,getmaxx(),30);
			bar(getmaxx()-30,0,getmaxx(),getmaxy());
			bar(0,getmaxy()-30,getmaxx(),getmaxy());
			setfillstyle(SOLID_FILL,LIGHTGRAY);
			bar(290,200,1350,500);
			setbkcolor(LIGHTGRAY);
			outtextxy(300,230,(char *)"Do you want questions be shuffled?");
			outtextxy(370,360,(char *)"yes");
			outtextxy(1010,360,(char *)"no");
			rectangle(350,350,500,450);
			rectangle(1000,350,1150,450);
}
		void ManHinhLuaChonChuDe(){
			setbkcolor(BLACK);
			cleardevice();
			setfillstyle(SOLID_FILL,WHITE);
			bar(0,0,getmaxx(),getmaxy());
			setbkcolor(BLACK);
			setcolor(BLACK);
			setfillstyle(SOLID_FILL,BLUE);
			bar(0,0,getmaxx(),100);
			
//			setcolor(WHITE);
			setfillstyle(SOLID_FILL,BLUE);
			bar(0,0,30,getmaxy());
			bar(0,0,getmaxx(),30);
			bar(getmaxx()-30,0,getmaxx(),getmaxy());
			bar(0,getmaxy()-30,getmaxx(),getmaxy());
			settextstyle(GOTHIC_FONT,0,6);
			setbkcolor(BLUE);
			setcolor(WHITE);
			outtextxy(300,20,(char *) "Choose topic!");
			setfillstyle(SOLID_FILL,LIGHTGRAY);
			setbkcolor(LIGHTGRAY);
			setcolor(BLACK);
			bar(280,290,1000,390);
			outtextxy(300,300,(char *) "Natural Sciences");
			bar(280,490,1000,590);
			outtextxy(300,500,(char *) "Social Sciences");
			bar(280,690,1000,790);
			outtextxy(300,700,(char *) "Foreign language");
		}
};
