#include<graphics.h>
#include<iostream>
#include<string>
#include<cstdlib>
#include<ctime>
#include<fstream>
using namespace std;
string TEXTNAME="mvl.txt";
string processName = "lichon.exe";
class QA{
	private:
		string question;	
		string answer;
		string choiceA;
		string choiceB;
		string choiceC;
		string choiceD;
	
	public:
		QA():question(""),answer(""),choiceA(""),choiceB(""),choiceC(""),choiceD(""){
		};
		QA(string q,string a,string cA,string cB,string cC,string cD): question(q),answer(a),choiceA(cA),choiceB(cB),choiceC(cC),choiceD(cD){
		};
		void setQuestion(string q){
			question = q;
		}
		void setAnswer(string a){
			answer = a;
		}
		void setChoiceA(string cA){
			choiceA = cA;
		}
		void setChoiceB(string cB){
			choiceB = cB;
		}
		void setChoiceC(string cC){
			choiceC = cC;
		}
		void setChoiceD(string cD){
			choiceD = cD;
		}
		string getQuestion(){
			return question;
		}
		string getAnswer(){
			return answer;
		}
		string getChoiceA(){
			return choiceA;
		}
		string getChoiceB(){
			return choiceB;
		}
		string getChoiceC(){
			return choiceC;
		}
		string getChoiceD(){
			return choiceD;
		}
	};
void menu(int &hienthi){
	int x1,y1;
	settextstyle(6,0,5);
	outtextxy(400,600,"3.Lich nhac on tap");
	if(ismouseclick(WM_LBUTTONDOWN)){
		getmouseclick(WM_LBUTTONDOWN,x1,y1);
		if((x1>=100 && x1<=1000) && (y1>=300 && y1<=500)){
			hienthi=2;
	}if((x1>=100 && x1<=1000) && (y1>=500 && y1<=700)){
			hienthi=3;
	}
}
}

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
					hienthi=3;
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
					hienthi=3;
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
								hienthi=3;
								break;
								
							}	if((x>=1000 && x<=1180)&&(y>=480&&y<=550)){
								hienthi=3;
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


int main(){
	int x,y;
	int hienthi=1;
	initwindow(1600,900);
	while(true){
		if(hienthi==1){
			menu(hienthi);
			delay(10);
			continue;
		}if(hienthi==3){
			lichontap(hienthi );
			
		continue;
	}		
		
	delay(1500);}
	getch();
	closegraph();
	return 0;
}

