#pragma once
#include <graphics.h>
#include <string>
#include <cmath>
#define SHADOW COLOR(122, 122, 82)
#define SKIN COLOR(194, 194, 163)
#include <string.h>
#include <algorithm>//max()
class button{
	private:
		int width,height;
		std::string name;
		int x,y;
		int bkcolor,textcolor;
		int text_size;
		bool visible,enable;
		int border;
	public:
		button(){
			width=100;
			height=50;
			x=0;y=0;
			name="";
			text_size=1;
			bkcolor=WHITE;
			textcolor=BLACK;
			visible=true;
			enable=true;
			border=1;
		}
		button(std::string name){
			this->name=name;
			width=100;
			height=50;
			x=0;y=0;
			text_size=1;
			bkcolor=WHITE;
			textcolor=BLACK;
			visible=true;
			enable=true;
			border=1;
		}
		button(int w,int h){
			width=w;
			height=h;
			name="";
			x=0;y=0;
			text_size=1;
			bkcolor=WHITE;
			textcolor=BLACK;
			visible=true;
			enable=true;
			border=1;
		}
		button(int w,int h,std::string s){
			button(w,h);
			name=s;
			x=0;y=0;
			text_size=1;
			bkcolor=WHITE;
			textcolor=BLACK;
			visible=true;
			enable=true;
			border=1;
		}
		void set_size(int w,int h){
			width=w;
			height=h;
		}
		void set_name(std::string s){
			name=s;
		}
		int get_x(){return x;}
		int get_y(){return y;}
		void set_location(int x,int y){
			this->x=x;
			this->y=y;
		}
		std::string get_name(){
			return name;
		}
		void draw(){
			int default_bkcolor=getbkcolor();
			int default_color=getcolor();
			setfillstyle(SOLID_FILL,BLACK);
			bar(x,y,x+width,y+height);
			setfillstyle(SOLID_FILL,bkcolor);
			bar(x+border,y+border,x+width-border,y+height-border);
			char *text= new char[name.size()+1];
			strcpy(text,name.c_str());
			settextstyle(GOTHIC_FONT,0,text_size);
			int centerx=width/2,centery=height/2;
			setbkcolor(bkcolor);
			setcolor(textcolor);
			const int max_char=40;
			char *final_text=new char[max_char+1];
			if(name.size()>=max_char){
				strncpy(final_text,text,max_char);
				*(final_text+max_char)='\0';
				text=final_text;
			}
		//	std::cout<<*text<<std::endl;
			outtextxy(x+centerx-textwidth(text)/2,y+centery-textheight(text)/2,text);
			setbkcolor(default_bkcolor);
			setcolor(default_color);
			delete text;
			delete final_text;
		}
		bool is_chosen(int x,int y){
			if(!enable) return false;
			if(x>=this->x and x<=this->x+width){
				if(y>=this->y and y<=this->y+height) return true;
				else return false;
			}else return false;
		}
		void re_draw(){
			int default_bkcolor=getbkcolor();
			int default_color=getcolor();
			setfillstyle(SOLID_FILL,SHADOW);
			bar(x,y,x+width,y+height);
			char *text= new char[name.size()+1];
			strcpy(text,name.c_str());
			settextstyle(GOTHIC_FONT,0,text_size);
			const int max_char=40;
			char *final_text=new char[max_char+1];
			if(name.size()>=max_char){
				strncpy(final_text,text,max_char);
				*(final_text+max_char)='\0';
				text=final_text;
			}
			setbkcolor(BLACK);
			setcolor(WHITE);
			int centerx=width/2,centery=height/2;
			outtextxy(x+centerx-textwidth(text)/2,y+centery-textheight(text)/2,text);
			setbkcolor(default_bkcolor);
			setcolor(default_color);
			delete text;
			delete final_text;
		}
		void set_bkcolor(int cl){
			bkcolor=cl;
		}
		void set_text_size(int size){
			text_size=size;
		}
		int get_width(){
			return width;
		}
		int get_height(){
			return height;
		}
		void set_visible(bool vsb,int background_color){
			visible=vsb;
			if(visible){
				draw();
			}
			else{
				setfillstyle(SOLID_FILL,background_color);
				bar(x,y,x+width,y+height);
			}
		}
		void set_enable(bool eab){
			enable=eab;
		}
		void erase(){
			setfillstyle(SOLID_FILL,getbkcolor());
			bar(x,y,x+width,y+height);
		}
		void set_border(int width){
			border=width;
		}
};
