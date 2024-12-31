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
class BamChuot{
	public:
		bool BamChuotMenuThemCauHoi(int x1,int y1){
			if((x1>=100 && x1<=900) && (y1>=170 && y1<=270) ||(x1>=150 && x1<=850) && (y1>=300 && y1<=400) ||
				(x1>=150 && x1<=850) && (y1>=430 && y1<=530) ||
				(x1>=150 && x1<=850) && (y1>=560 && y1<=660) ||
				(x1>=150 && x1<=850) && (y1>=690 && y1<=790) ||
				( (x1>=1120 && x1<=1330) && (y1>=300 && y1<=400))||
				( (x1>=1120 && x1<=1330) && (y1>=430 && y1<=530))||
				( (x1>=1120 && x1<=1330) && (y1>=560 && y1<=660))||
				( (x1>=1120 && x1<=1330) && (y1>=690 && y1<=790))||
				( (x1>=1365 && x1<=1600) && (y1>=0 && y1<=120))
				||( (x1>=0 && x1<=200) && (y1>=0 && y1<=120))
				) return true;
			return false;
}
		bool BamChuotManHinhSuaCauHoi(int x1,int y1){
			if(((x1>=290 && x1<=1200) && (y1>=190 && y1<=240))||
					((x1>=290 && x1<=1200) && (y1>=290 && y1<=340))||
					((x1>=290 && x1<=1200) && (y1>=390 && y1<=440))||
					((x1>=290 && x1<=1200) && (y1>=490 && y1<=540))||
					((x1>=290 && x1<=1200) && (y1>=590 && y1<=640))||
					((x1>=getmaxx()-150 && x1<=getmaxx()-70) && (y1>=getmaxy()-100 && y1<=getmaxy()-50))||
					((x1>=0 && x1<=150) && (y1>=0 && y1<=150))||
					((x1>=0 && x1<=110) && (y1>=getmaxy()-100 && y1<=getmaxy()-50))
				 ) return true;
				return false;
		}
		bool BamChuotManHinhLamBai(int x1,int y1){
			if(((x1>=100 && x1<=1500 ) && (y1>=320 && y1<=420))||
			((x1>=100 && x1<=1500 ) && (y1>=430 && y1<=530))||
			((x1>=100 && x1<=1500 ) && (y1>=540 && y1<=640))||
			((x1>=100 && x1<=1500 ) && (y1>=650 && y1<=750))
			) return true;
			return false;
}
		bool BamChuotManHinhChuaCoCauHoi(int x1,int y1){
			if((x1>=0 && x1<=600) && (y1>=500 && y1<=700)) return true;
			return false;
		}
		bool BamChuotManHinhMenu(int x1,int y1){
			
			if(((x1>=550 && x1<=1100) && (y1>= 180 && y1<=250))||
				((x1>=550&& x1<=1100) && (y1>=320 && y1<=390))||
				((x1>=550&& x1<=1100) && (y1>=460 && y1<=530))||
				((x1>=550&& x1<=1100) && (y1>=600 && y1<=670))||
				((x1>=550&& x1<=1100) && (y1>=740 && y1<=810))
			) return true;
			return false;
}
		bool BamChuotManHinhXacNhanThemCauHoi(int x1,int y1){
			if((x1>=440 && x1<=570) && (y1>=320 && y1<=420) || ((x1>=970 && x1<=1170) && (y1>=320 && y1<=420))) return true;
			return false;
		}
		bool BamChuotManHinhHoanThanhLamBai(int x1,int y1,int &diem,int &count,vector<QA> &listQA){
			if(((x1>=420 && x1<=700) && (y1>=650 && y1<=750) )||
			((x1>=780 && x1<=1200) && (y1>=650 && y1<=750) && count==0 && diem !=listQA.size())
			 )return true;
			return false;
}
		bool BamChuotManHinhLuaChonRandom(int x1,int y1){
			if((x1>=350 && x1<=500) && (y1 >= 350 && y1<=450) || ((x1>=1000 && x1<=1150) && (y1>=350 && y1<=450)) ) return true;
			return false;
		}
		bool BamChuotManHinhLuaChonChuDe(int x1,int y1){
			if((x1>=280 && x1<=1000) && (y1 >= 290 && y1<=390) || ((x1>=280 && x1<=1000) && (y1>=490 && y1<=590))
			|| ((x1>=280 && x1<=1000) && (y1>=690 && y1<=790))
			 ) return true;
			return false;
		}
};
