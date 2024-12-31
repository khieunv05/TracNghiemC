#pragma once
#include <iostream>
#include <conio.h>
#include <string>
#include <graphics.h>
#include <string.h>
#define ENTER 13
#define SHADOW COLOR(122, 122, 82)
#define BACKSPACE 8
class typing_board{
	public:
		std::string content;
		int width,height,x,y;
		std::string value;
		int color,text_color;
		int text_size;
		int font;
	public:
		typing_board():content(""),width(100),height(50),x(0),y(0),value(""),color(BLACK),text_color(WHITE),text_size(2),font(GOTHIC_FONT){	
		}
		typing_board(std::string s):content(s),width(100),height(50),x(0),y(0),value(""),color(BLACK),text_color(WHITE),text_size(2),font(GOTHIC_FONT){
		}
		typing_board(int w,int h):content(""),width(w),height(h),x(0),y(0),value(""),color(BLACK),text_color(WHITE),text_size(2),font(GOTHIC_FONT){
		}
		void set_content(std::string s){
			content=s;
		}
		std::string get_content(){
			return content;
		}
		void draw(){
			setfillstyle(SOLID_FILL,color);
			bar(x,y,x+width,y+height);
			char *text= new char[content.size()+1];
			strcpy(text,content.c_str());
			int midw=width/2;
			int midh=height/2;
			int midtextw=textwidth(text)/2;
			int midtexth=textheight(text)/2;
			setbkcolor(color);
			settextstyle(font,0,text_size);
			setcolor(text_color);
			char *text_value= new char[value.size()+1];
			strcpy(text_value,value.c_str());
		//	std::cout<<x+midw-midtextw<<":"<<y+midh-midtexth+5<<std::endl;
			if(value=="")
			outtextxy(x+midw-midtextw,y+midh-midtexth,text);
			else
			outtextxy(x+10,y+midh-midtexth,text_value);
			delete text,text_value;
		}
		void re_draw(){
			setfillstyle(SOLID_FILL,SHADOW);
			bar(x,y,x+width,y+height);
			char *text= new char[content.size()+1];
			strcpy(text,content.c_str());
			int midw=width/2;
			int midh=height/2;
			int midtextw=textwidth(text)/2;
			int midtexth=textheight(text)/2;
			setbkcolor(SHADOW);
			settextstyle(font,0,text_size);
			setcolor(text_color);
			char *text_value= new char[value.size()+1];
			strcpy(text_value,value.c_str());
		//	std::cout<<x+midw-midtextw<<":"<<y+midh-midtexth+5<<std::endl;
			if(value=="")
			outtextxy(x+midw-midtextw,y+midh-midtexth,text);
			else
			outtextxy(x+10,y+midh-midtexth,text_value);
			delete text,text_value;
		}
		void set_location(int x,int y){
			this->x=x;
			this->y=y;
		}
		void set_size(int w,int h){
			width=w;
			height=h;
		}
		void start_typing(){
			std::cout<<"Dnag nhap";
			setcolor(WHITE);
			settextstyle(font,0,text_size);
			bool enter=false;
			char key; 
			char *charstring=new char[71];
			std::string typingtext=value;
			int x1, y1;
			bool out_clicked=false;
			setfillstyle(SOLID_FILL,SHADOW);
			bar(x,y,x+width,y+height);
			strncpy(charstring,typingtext.c_str(),70);
			*(charstring+70)='\0';
			outtextxy(this->x+10,this->y+10,charstring);
			while(!out_clicked&&!enter&&typingtext.size()<70){
				if(kbhit()){
				key=getch();
				if(key==BACKSPACE){
					if(!typingtext.empty()) typingtext.pop_back();
					//draw();
					bar(x,y,x+width,y+height);
				}else typingtext.push_back(key);
//					typingtext.push_back('_');
				strcpy(charstring,typingtext.c_str());
				outtextxy(this->x+10,this->y+10,charstring);
				if(key==ENTER) enter=true;
			}else{
				x1=mousex();y1=mousey();
				if(ismouseclick(WM_LBUTTONDOWN)&&!is_chosen(x1,y1)){
					clearmouseclick(WM_LBUTTONDOWN);
					out_clicked=true;
				}
			}
		}
			std::cout<<"Thoat nhap";
			value=typingtext;
			delete[] charstring;
		//	std::cout<<mousex()<<":"<<mousey()<<std::endl;
			return;
		}
		bool is_chosen(int x,int y){
			if(x>=this->x and x<=this->x+width){
				if(y>=this->y and y<=this->y+height) return true;
				else return false;
			}else return false;
		}
		std::string get_value(){
			return value;
		}
		void set_color(int cl){
			color=cl;
		}
		void set_text_color(int cl){
			text_color=cl;
		}
		void set_value(std::string vl){
			value=vl;
		}
		void set_textsize(int size){
			text_size=size;
		}
		void set_font(int f){
			font=f;
		}
};
