#include <iostream>
#include <fstream>
#include <graphics.h>
#include <vector>
#include <windows.h>
#include <cmath> 
#include <conio.h>
#include "question.h"
#include "button.cpp"
#include "label.cpp"
#include "typing_board.cpp"
#include "color.h"
#define SCREEN_WIDTH 1600
#define SCREEN_HEIGHT 900
#define CENTERX SCREEN_WIDTH/2
#define CENTERY SCREEN_HEIGHT/2
#include "funtion.cpp"
std::vector<question> ques_container;///vector chua cau hoi 
std::vector<bool> mang_cac_nut_xoa_da_chon;//vector danh dau
bool man_hinh_xac_nhan();//xac nhan xoa
void ques_container_update();//cap nhat vector chua cau hoi
fstream file;//file cau hoi
void draw_background();//ve background
void man_hinh_xoa();//man hinh xoa cau hoi
void hien_thi_cau_hoi(std::vector<button>& nut_xoa,int page);//hien thi cau hoi
void update_file();//cap hat file cau hoi
std::string file_working;//file_dang lam viec
int xoa(std::string file_name){
	file_working=file_name;
	cleardevice();
	draw_background();
	if(load_file(file_working,ques_container,file)) {
		man_hinh_xoa();
		update_file();
	}
}
void man_hinh_xoa(){
	cleardevice();
	draw_background();
	//nut quay lai
	int border_thickness=30;
	button back("Back");
	back.set_location(border_thickness,border_thickness);
	back.set_size(100,40);
	back.set_bkcolor(NHAN);
	back.set_text_size(2);
	back.draw();
	bool back_re_draw=false;
	//nut hoan thanh 
	button done("Finish");
	done.set_size(100,40);
	done.set_location(SCREEN_WIDTH-border_thickness-80,border_thickness);
	done.set_bkcolor(NHAN);
	done.set_text_size(2);
	done.draw();
	//dieu huong trang hien thi
	button left,right;
	right.set_name("->");
	right.set_size(80,40);
	right.set_text_size(4);
	right.set_location(SCREEN_WIDTH-right.get_width()-border_thickness,SCREEN_HEIGHT-right.get_height()-border_thickness);
	right.set_bkcolor(NHAN);
	right.draw();
	left.set_name("<-");
	left.set_size(80,40);
	left.set_text_size(4);
	left.set_location(border_thickness,SCREEN_HEIGHT-left.get_height()-border_thickness);
	left.set_bkcolor(NHAN);
	left.draw();
	//hien thi cau hoi
	int max_display=3;
	int max_page=floor((double)ques_container.size()/max_display)-1;
//	if(max_page<0) max_page=0;
	int page=0;
	//std::vector<Label> Label_of_ques(max_display);
	std::vector<button> nut_xoa(max_display);
	int x,y;
	std::vector<bool> mang_chon_nut_xoa;//nut chon cau hoi
	bool chose_one_ques=false;
	for(int i=0;i<max_display;i++){
		mang_chon_nut_xoa.push_back(false);
	}
	for(int i=0;i<ques_container.size();i++){
		mang_cac_nut_xoa_da_chon.push_back(false);
	}
	hien_thi_cau_hoi(nut_xoa,page);
	bool some_button_chosen=false;
	bool chon_nut_xoa=false;
	bool left_button_chosen=false;//nut sang trai
	bool right_button_chosen=false;//nut sang phai
	bool done_button_chose=false;//nut xong
	int option;
	int ques_order_in_page;
	int ques_order_in_container;
	while(true){
		x=mousex(); y=mousey();
		//kiem tra cac cau hoi duoc chon
		for(int i=0;i<max_display;i++){
			if(nut_xoa[i].is_chosen(x,y)){
				some_button_chosen=true;
				chon_nut_xoa=true;
			}
		}
		//kiem tra nut dieu huong
		if(left.is_chosen(x,y)||right.is_chosen(x,y)){
				some_button_chosen=true;
				if(left.is_chosen(x,y)) {
					if(!left_button_chosen){
						left.re_draw();
						left_button_chosen=true;
					}
					if(ismouseclick(WM_LBUTTONDOWN)){
						clearmouseclick(WM_LBUTTONDOWN);
						page=page<=0?page:page-1;
						hien_thi_cau_hoi(nut_xoa,page);
					}
				}
				if(right.is_chosen(x,y)){
					if(!right_button_chosen){
						right.re_draw();
						right_button_chosen=true;
					}
					if(ismouseclick(WM_LBUTTONDOWN)){
						clearmouseclick(WM_LBUTTONDOWN);
						page=(page>=max_page)?page:page+1;
						hien_thi_cau_hoi(nut_xoa,page);
					}
				}
			//kiem tra nut quay lai
		}else if(back.is_chosen(x,y)){
			some_button_chosen=true;
			if(!back_re_draw){
				back.re_draw();
				back_re_draw=true;
			}
			if(ismouseclick(WM_LBUTTONDOWN)){
				clearmouseclick(WM_LBUTTONDOWN);
				option=1;
				break;
			}
		//kiem tra nut hoan thanh
		}else if(done.is_chosen(x,y)){
			some_button_chosen=true;
			if(!done_button_chose){
				done.re_draw();
				done_button_chose=true;
			}
			if(ismouseclick(WM_LBUTTONDOWN)){
				clearmouseclick(WM_LBUTTONDOWN);
					option=2;
					break;
				}
		//xu li cac cau hoi da chon
		}else if(chon_nut_xoa){
			//ve lai cac nut
			for(int i=0;i<max_display;i++){
				if(nut_xoa[i].is_chosen(x,y)){
					if(!mang_chon_nut_xoa[i]){
					mang_chon_nut_xoa[i]=true;
					nut_xoa[i].re_draw();
					}
				}
			}
			//click chuot
			if(ismouseclick(WM_LBUTTONDOWN)){
				clearmouseclick(WM_LBUTTONDOWN);
				for(int i=0;i<max_display;i++){
					if(mang_chon_nut_xoa[i]==true){
						ques_order_in_page=i;
						//lay vi tri cua cau hoi trong vector
						ques_order_in_container=page*max_display+ques_order_in_page;
						//bo chon cau hoi
						if(mang_cac_nut_xoa_da_chon[ques_order_in_container]==true){
							nut_xoa[i].set_bkcolor(Dap_an);
							mang_cac_nut_xoa_da_chon[ques_order_in_container]=false;
						//chon cau hoi
						}else{
							nut_xoa[i].set_bkcolor(XAC_NHAN);
							mang_cac_nut_xoa_da_chon[ques_order_in_container]=true;
						}	
					}
				}
			}
			chon_nut_xoa=false;
		}else 
		// ve lai cac nut da chon
			if(some_button_chosen){
			//	std::cout<<"da chon nut";
				if(right_button_chosen||left_button_chosen){
					if(right_button_chosen){
						right.draw();
						right_button_chosen=false;
					}
					if(left_button_chosen){
						left.draw();
						left_button_chosen=false;
					}
				}else if(done_button_chose){
					done.draw();
					done_button_chose=false;
				}else for(int i=0;i<max_display;i++){
						if(mang_chon_nut_xoa[i]){
							mang_chon_nut_xoa[i]=false;
							nut_xoa[i].draw();
						}
					}
					if(back_re_draw){
						back.draw();
						back_re_draw=false;
					}
			some_button_chosen=false;
			}
			if(ismouseclick(WM_LBUTTONDOWN)) clearmouseclick(WM_LBUTTONDOWN);
			}
	switch(option){
		//chon nut back
		case 1:
			return;
		//chon nut finish
		case 2:
			//update vector
			if(man_hinh_xac_nhan()) ques_container_update();
	}
}
void hien_thi_cau_hoi(std::vector<button>& nut_xoa,int page){
	const int max_display=3;
	int current_ques_cursor=page*max_display;
	int start_y=200;
	int break_point=max_display;
	//nap du lieu cho vector nut_xoa
	for(int i=0;i<max_display;i++){
		if(current_ques_cursor>ques_container.size()-1){
			break_point=i;
			break;
		}
		button temp_but(ques_container[current_ques_cursor].get_content());
		if(mang_cac_nut_xoa_da_chon[current_ques_cursor+i]) temp_but.set_bkcolor(XAC_NHAN);
		nut_xoa[i]=temp_but;
		current_ques_cursor++;
	}
	//hien thi
	for(int i=0;i<break_point;i++){
		nut_xoa[i].set_size(695,99);
		nut_xoa[i].set_location(CENTERX-695/2,start_y+i*99+i*60);
		nut_xoa[i].draw();
	}
	if(break_point!=max_display){
		for(int i=break_point;i<max_display;i++){
			if(ques_container.size()<=3) nut_xoa[i].set_location(2000,2000);
			else nut_xoa[i].set_visible(false,WHITE);
			nut_xoa[i].set_enable(false);
		}
	}

	return;
}
bool man_hinh_xac_nhan(){
	cleardevice();
	draw_background();
	//ve cac chi tiet
	settextstyle(GOTHIC_FONT,0,3);
	setfillstyle(SOLID_FILL,Dap_an);
	bar(CENTERX-692/2,CENTERY-338/2,CENTERX+692/2,CENTERY+338/2);
	std::string xacnhan="Do you want to delete the selected";
	std::string xacnhan1="questions ?";
	char* xacnhan1_text=new char[xacnhan1.size()+1];
	char *xacnhan_text=new char[xacnhan.size()+1];
	strncpy(xacnhan1_text,xacnhan1.c_str(),xacnhan1.size());
	*(xacnhan1_text+xacnhan1.size())='\0';
	strncpy(xacnhan_text,xacnhan.c_str(),xacnhan.size());
	*(xacnhan_text+xacnhan.size())='\0';
	setbkcolor(Dap_an);
	setcolor(BLACK);
	outtextxy(CENTERX-textwidth(xacnhan_text)/2,CENTERY-150,xacnhan_text);
	outtextxy(CENTERX-textwidth(xacnhan_text)/2,CENTERY-150+textheight(xacnhan_text),xacnhan1_text);
	delete xacnhan_text,xacnhan1_text;
	//nut xac nhan
	button yes("Yes");
	int yes_no_width=100;
	yes.set_size(yes_no_width,50);
	yes.set_bkcolor(Dap_an);
	int space_between_yes_and_no=386;
	yes.set_location(CENTERX-space_between_yes_and_no/2-yes_no_width,CENTERY+80);
	yes.draw();
	button no("No");
	no.set_size(yes_no_width,50);
	no.set_location(CENTERX+space_between_yes_and_no/2,CENTERY+80);
	no.set_bkcolor(Dap_an);
	no.draw();
	bool yes_re_draw=false;
	bool no_re_draw=false;
	bool option;
	int x,y;
	while(true){
		x=mousex();y=mousey();
		//kiem tra nut yes va no
		if(yes.is_chosen(x,y)||no.is_chosen(x,y)){
			if(yes.is_chosen(x,y)){
				if(!yes_re_draw){
					yes.re_draw();
					yes_re_draw=true;
				}
				if(ismouseclick(WM_LBUTTONDOWN)){
					clearmouseclick(WM_LBUTTONDOWN);
					return true;
				}
			}else{
				if(!no_re_draw){
					no.re_draw();
					no_re_draw=true;
				}
				if(ismouseclick(WM_LBUTTONDOWN)){
					clearmouseclick(WM_LBUTTONDOWN);
					return false;
				}
			}
		}else{
			if(yes_re_draw){
				yes.draw();
				yes_re_draw=false;
			}
			if(no_re_draw){
				no.draw();
				no_re_draw=false;
			}
		}
		if(ismouseclick(WM_LBUTTONDOWN)) clearmouseclick(WM_LBUTTONDOWN);
	}
}
void update_file(){
	file.open(file_working,std::ios::out);
	if(file.is_open()){//kiem tra mo file
		for(int i=0;i<ques_container.size();i++){
		//	std::cout<<ques_container[i].get_content()<<std::endl;
			file<<ques_container[i].get_content()<<std::endl;
			file<<ques_container[i].get_correct_ans()<<std::endl; 
			for(int j=0;j<4;j++){
				if(i==ques_container.size()-1&&j==3) file<<ques_container[i].get_answer(j);
				else file<<ques_container[i].get_answer(j)<<std::endl; 
			}
			
		}
		file.close();
	}
}
void ques_container_update(){
	for(int i=0;i<ques_container.size();i++){
		if(mang_cac_nut_xoa_da_chon[i]){
			ques_container.erase(ques_container.begin()+i);
			mang_cac_nut_xoa_da_chon.erase(mang_cac_nut_xoa_da_chon.begin()+i);
			i--;
		}
	}
}



