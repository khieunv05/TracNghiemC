#pragma once
#include <string>
#include <graphics.h>
#include <cstring>
#define LIGHT_GREEN COLOR(128, 255, 170)
#define LIGHT_RED COLOR(255, 77, 77)
#define LIGHT_BROWN COLOR(234, 234, 225)
#define BROWN COLOR(171, 171, 135)
class Label{
	private:
		std::string name;
		int x,y;
		int width,height;
		int textsize;
		int bgcolor,textcolor;
	public:
		Label(){
			name="";
			x=0;y=0;
			width=100;
			height=50;
			textsize=1;
			bgcolor=WHITE;
			textcolor=BLACK;
		}
		Label(std::string s):name(s){
			width=100;
			height=50;
			x=0;y=0;
			textsize=1;
			bgcolor=WHITE;
			textcolor=BLACK;
		}
		Label(int w,int h){
			name="";
			width=w;
			height=h;
			x=0;y=0;
			textsize=1;
			bgcolor=WHITE;
			textcolor=BLACK;
		}
		std::string get_name(){
			return name;
		}
		void set_name(std::string s){
			name=s;
		}
		void set_position(int x,int y){
			this->x=x;
			this->y=y;
		}
		void set_size(int w,int h){
			width=w;
			height=h;
		}
		void draw(){
			int default_bkcolor=getbkcolor();
			int default_color=getcolor();
			setfillstyle(SOLID_FILL,bgcolor);	
			bar(x,y,x+width,y+height);
			char *text= new char[51];
			std::strncpy(text,name.c_str(),50);
			*(text+50)='\0';
			settextstyle(GOTHIC_FONT,0,textsize);
			int centerx=width/2,centery=height/2;
			setbkcolor(bgcolor);
			setcolor(textcolor);
			outtextxy(x+centerx-textwidth(text)/2,y+centery-textheight(text)/2,text);
			setbkcolor(default_bkcolor);
			setcolor(default_color);
			delete text;
		}
		void settextsize(int size){
			textsize=size;
		}
		int get_height(){
			return height;
		}
		int get_width(){
			return width;
		}
		void set_bgcolor(int color){
			bgcolor=color;
		}
		void set_textcolor(int color){
			textcolor=color;
		}
};
