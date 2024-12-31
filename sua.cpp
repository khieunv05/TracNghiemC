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
void draw_background();
bool load_file();
void question_chose_screen();
std::fstream file;//tai file cau hoi
std::vector<question> ques_container;//luu cau hoi
void get_and_display_questions(vector<button>&,int);//tai va hien thi cau hoi
void ques_edit(int,int,int);//chinh sua cau hoi
bool complete_edit();//xac nhan chinh sua
bool check_empty_component_of_ques(const typing_board ques_typing,const std::vector<typing_board> ans_arr);//kiem tra thanh phan rong
void ques_update(typing_board content_of_ques,std::vector<typing_board> ans_arr,question& ques,int correct_ans);//cap nhat cau hoi trong ques_container
void hienthi();
void display_empty_component_err();//bang loi nhap thieu thanh phan
void update_file();//cap nhat du lieu moi vao file
int main(){ 
	initwindow(SCREEN_WIDTH,SCREEN_HEIGHT);
	if(load_file()){
		hienthi();
		question_chose_screen();
	}
	closegraph();
	return 0;
}
void hienthi(){
	for(int i=0;i<ques_container.size();i++){
		std::cout<<ques_container[i].get_content()<<std::endl;
	}
}
bool load_file(){
	file.open("text1.txt",std::ios::in|std::ios::out);
	std::string temp_str;
	question temp_ques;
	if(file.is_open()){//kiem tra mo file
		while(!file.eof()){
			getline(file,temp_str);
			temp_ques.set_content(temp_str);
			getline(file,temp_str);
			temp_ques.set_correct_ans(temp_str);
			for(int i=0;i<4;i++){
				getline(file,temp_str);
				temp_ques.set_answer(i,temp_str);
			}
			ques_container.push_back(temp_ques);
		}
		file.close();
		return true;
	}else{//thong bao loi mo file
		draw_background();
		Label file_err_label("Khong mo duoc file!");
		file_err_label.set_position(CENTERX-file_err_label.get_width()/2,130);
		file_err_label.draw();	
		return false;
	}
//	std::cout<<"size:"<<ques_container.size()<<std::endl;
}
void draw_background(){
	cleardevice();
	//ve khung 
	setfillstyle(SOLID_FILL,KHUNG_NGOAI);
	bar(0,0,SCREEN_WIDTH,SCREEN_HEIGHT);
	setfillstyle(SOLID_FILL,WHITE);
	int boder_thickness=30;
	bar(boder_thickness,boder_thickness,SCREEN_WIDTH-boder_thickness,SCREEN_HEIGHT-boder_thickness);
	//nhan tieu de
	Label sua("SUA CAU HOI");
	sua.set_size(SCREEN_WIDTH-2*boder_thickness,40);
	sua.set_position(CENTERX-sua.get_width()/2,boder_thickness);
	sua.set_bgcolor(NHAN);
	sua.draw();
}
void question_chose_screen(){
	cleardevice();
	draw_background();
	const int ques_container_size=ques_container.size();
	int max_display=3;
	vector<button> button_of_ques(max_display);
	//load cac cau hoi va hien thi
	int x,y;//Toa do chuot
	int boder_thickness=30;
	//dieu huong trang hien thi
	button left,right;
	right.set_name("->");
	right.set_size(80,40);
	right.set_text_size(3);
	right.set_location(SCREEN_WIDTH-right.get_width()-boder_thickness,SCREEN_HEIGHT-right.get_height()-boder_thickness-100);
	right.set_bkcolor(NHAN);
	right.draw();
	left.set_name("<-");
	left.set_size(80,40);
	left.set_text_size(3);
	left.set_location(boder_thickness,SCREEN_HEIGHT-left.get_height()-boder_thickness-100);
	left.set_bkcolor(NHAN);
	left.draw();
	//nut quay lai
	button back("Tro lai");
	back.set_size(100,40);
	back.set_bkcolor(NHAN);
	back.set_location(boder_thickness,boder_thickness);
	back.draw();
	bool back_re_draw=false;
	//hoat anh chon nut
	bool some_button_chosen=false;
	std::vector<bool> ques_button_chosen;//nut chon cau hoi
	bool chose_one_ques=false;
	for(int i=0;i<max_display;i++){
		ques_button_chosen.push_back(false);
	}
	bool left_button_chosen=false;//nut sang trai
	bool right_button_chosen=false;//nut sang phai
	static int page=0;//trang hien thi 
	get_and_display_questions(button_of_ques,page);//hien thi trang dau tien
	int max_page=floor((double)ques_container.size()/max_display)-1;
	int ques_order_in_page;
	std::cout<<"max page: "<<max_page<<std::endl;
	int option;
	while(true){
		x=mousex(); y=mousey();
		for(int i=0;i<max_display;i++){
			if(button_of_ques[i].is_chosen(x,y)){
				some_button_chosen=true;
				chose_one_ques=true;
			}
		}
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
					get_and_display_questions(button_of_ques,page);
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
					get_and_display_questions(button_of_ques,page);
				}
			}
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
		}else if(chose_one_ques){
			for(int i=0;i<max_display;i++){
				if(button_of_ques[i].is_chosen(x,y)){
					if(!ques_button_chosen[i]){
					ques_button_chosen[i]=true;
					button_of_ques[i].re_draw();
					}
				}
			}
			if(ismouseclick(WM_LBUTTONDOWN)){
				clearmouseclick(WM_LBUTTONDOWN);
				for(int i=0;i<max_display;i++){
					if(ques_button_chosen[i]==true){
							ques_order_in_page=i;
					}
				}
				option=2;
				break;
			}
			chose_one_ques=false;
		}else{
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
			}else {
				for(int i=0;i<max_display;i++){
					if(ques_button_chosen[i]){
						ques_button_chosen[i]=false;
						button_of_ques[i].draw();
					}
				}
				if(back_re_draw){
					back.draw();
					back_re_draw=false;
				}
			}
		}else{
		}
		some_button_chosen=false;
		if(ismouseclick(WM_LBUTTONDOWN)) clearmouseclick(WM_LBUTTONDOWN);
		}
	}
	switch(option){
		case 1:
			update_file();
			return;
		case 2:
			ques_edit(ques_order_in_page,page,max_display);
			break;
	}
}
void get_and_display_questions(vector<button>& button_of_ques,int page){
//	std::cout<<"Vao ham hien thi"<<std::endl;
//	std::cout<<"Dang o page: "<<page<<std::endl;
	const int max_display=3;
	int current_ques_cursor=page*max_display;
//	std::cout<<current_ques_cursor<<std::endl;
	int start_y=200;
	// load button,so luog max_display
	int break_point=max_display;
	for(int i=0;i<max_display;i++){
		if(current_ques_cursor>=ques_container.size()-1){
			break_point=i;
			break;
		}
		button temp_button(ques_container[current_ques_cursor].get_content());
		button_of_ques[i]=temp_button;
		current_ques_cursor++;
	}
	//hien thi cac nut cau hoi 
	for(int i=0;i<break_point;i++){
		button_of_ques[i].set_size(800,120);
		button_of_ques[i].set_bkcolor(Dap_an);
		button_of_ques[i].set_text_size(3);
		button_of_ques[i].set_location(CENTERX-button_of_ques[i].get_width()/2,start_y+i*button_of_ques[i].get_height()+i*60);
		button_of_ques[i].draw();
	}
	if(break_point!=max_display){
		for(int i=break_point;i<max_display;i++){
			button_of_ques[i].set_enable(false);
			button_of_ques[i].set_visible(false,WHITE);
		}
	}
	std::cout<<"Thoat ham hien thi"<<std::endl;
	return;
}
void ques_edit(int ques_order_in_page,int page,int max_display){
	cleardevice();
	draw_background();
	int ques_order_in_container=max_display*page+ques_order_in_page;
	//bang nhap cau hoi
	typing_board ques_typing("Nhap cau hoi");
	ques_typing.set_size(1000,130);
	ques_typing.set_location(100,100);
	ques_typing.set_color(Dap_an);
	ques_typing.set_text_color(BLACK);
	int boder_thickness=30;
	//bang nhap dan an
	std::vector<typing_board> ans_typing;
	std::string abcd[4]={"A.","B.","C.","D."};
	int start_y=240;
	for(int i=0;i<4;i++){
		typing_board temp_board;
		temp_board.set_size(1000,130);
		temp_board.set_location(100,start_y+i*130+i*20);
		temp_board.set_color(Dap_an);
		temp_board.set_text_color(BLACK);
		ans_typing.push_back(temp_board);
	}
	//nut chon dap an dung
	std::vector<button> correct_ans;
	for(int i=0;i<4;i++){
		button temp_button;
		temp_button.set_size(200,130);
		temp_button.set_bkcolor(Dap_an);
		temp_button.set_location(1150,start_y+i*130+i*20);
		temp_button.draw();
		correct_ans.push_back(temp_button);
	}
	std::vector<bool> correct_ans_button_re_draw={false,false,false,false};
	std::vector<bool> correct_ans_button_chose_truth={false,false,false,false};
	bool chose_some_correct_ans=false;
	int last_correct_ans_chosen;
	//nut hoan thanh
	button done("Xong");
	done.set_size(100,40);
	done.set_location(SCREEN_WIDTH-boder_thickness-80,boder_thickness);
	done.set_bkcolor(NHAN);
	done.set_text_size(2);
	done.draw();
	//nut quay lai
	button back("Tro lai");
	back.set_size(100,40);
	back.set_bkcolor(NHAN);
	back.set_location(boder_thickness,boder_thickness);
	back.draw();
	bool back_re_draw=false;
	//Nhan dap an
	Label ans_label("Dap an");
	ans_label.set_position(1150,100);
	ans_label.set_size(200,130);
	ans_label.set_bgcolor(Dap_an);
	ans_label.draw();
	//load du lieu cho cac bang nhap dap an 
	ques_typing.set_value(ques_container[ques_order_in_container].get_content());
	if(ques_typing.get_value().size()>70) ques_typing.set_textsize(1);
	ques_typing.draw();
	for(int i=0;i<4;i++){
		ans_typing[i].set_value(ques_container[ques_order_in_container].get_answer(i));
		if(ans_typing[i].get_value().size()>70) ans_typing[i].set_textsize(1);
		ans_typing[i].draw();
	}
	int correct_ans_inorder=-1;
	int x,y;//con tro chuot
	bool done_re_draw=false;
	bool chose_some_ans_typing=false;
	bool ques_typing_re_draw=false;
	std::vector<bool> ans_typing_re_draw={false,false,false,false};
	std::vector<bool> ans_typing_chose_truth={false,false,false,false};
	bool chose_something=false;
	char clear_key;
	int option;//chon quay lai hoac chon cau hoi
	//dap an dung hien tai
	for(int i=0;i<4;i++){
		//tim thay dap an dung
		if(ques_container[ques_order_in_container].get_correct_ans()==ans_typing[i].get_value()){
			last_correct_ans_chosen=i;
		//khong co dap an dung/khong co dap an dung trong file
		}else last_correct_ans_chosen=0;
	}
	correct_ans[last_correct_ans_chosen].set_bkcolor(GREEN);
	correct_ans[last_correct_ans_chosen].draw();
	correct_ans_button_re_draw[last_correct_ans_chosen]=false;
	correct_ans[last_correct_ans_chosen].set_enable(false);
//bat dau
	while(true){
		x=mousex();y=mousey();
		if(kbhit()) clear_key=getch();
		for(int i=0;i<4;i++){
			if(ans_typing[i].is_chosen(x,y)){
				chose_some_ans_typing=true;
				ans_typing_chose_truth[i]=true;
			}else {
				ans_typing_chose_truth[i]=false;
			}
		}
		for(int i=0;i<4;i++){
			if(correct_ans[i].is_chosen(x,y)){
				chose_some_correct_ans=true;
				correct_ans_button_chose_truth[i]=true;
			}else{
				correct_ans_button_chose_truth[i]=false;
			}
		}
		if(ques_typing.is_chosen(x,y)){
			chose_something=true;
			if(!ques_typing_re_draw){
				ques_typing.re_draw();
				ques_typing_re_draw=true;
			}
			if(ismouseclick(WM_LBUTTONDOWN)){
				clearmouseclick(WM_LBUTTONDOWN);
				ques_typing.start_typing();
				ques_typing.draw();
				ques_typing_re_draw=false;
			}
		}else if(back.is_chosen(x,y)){
			chose_something=true;
			if(!back_re_draw){
				back.re_draw();
				back_re_draw=true;
			}
			if(ismouseclick(WM_LBUTTONDOWN)){
				clearmouseclick(WM_LBUTTONDOWN);
				option=2;
				break;
			}
		}else if(done.is_chosen(x,y)){
			chose_something=true;
			if(!done_re_draw){
				done.re_draw();
				done_re_draw=true;
			}
			if(ismouseclick(WM_LBUTTONDOWN)){
				clearmouseclick(WM_LBUTTONDOWN);
//				if(check_empty_component_of_ques(ques_typing,ans_typing)){
//					display_empty_component_err();
//					delay(2000);
//				}else{
					option=1;
					break;
//				}
			}
		}else if(chose_some_ans_typing){
			chose_something=true;
			for(int i=0;i<4;i++){
				if(ans_typing_chose_truth[i]==true){
					if(!ans_typing_re_draw[i]){
						ans_typing[i].re_draw();
						ans_typing_re_draw[i]=true;
					}
					if(ismouseclick(WM_LBUTTONDOWN)){
						clearmouseclick(WM_LBUTTONDOWN);
						ans_typing[i].start_typing();
						ans_typing[i].draw();
						ans_typing_re_draw[i]=false;
						break;
					}
				}
			}
			chose_some_ans_typing=false;
		}else if(chose_some_correct_ans){
			chose_something=true;
			for(int i=0;i<4;i++){
				if(correct_ans_button_chose_truth[i]==true){
					if(!correct_ans_button_re_draw[i]){
						correct_ans[i].re_draw();
						correct_ans_button_re_draw[i]=true;
					}
					if(ismouseclick(WM_LBUTTONDOWN)){
						clearmouseclick(WM_LBUTTONDOWN);
						correct_ans[i].set_bkcolor(GREEN);
						correct_ans[i].draw();
						correct_ans_button_re_draw[i]=false;
						correct_ans[i].set_enable(false);
						last_correct_ans_chosen=i;
//						std::cout<<last_correct_ans_chosen<<std::endl;
						for(int j=0;j<4;j++){
							if(j!=last_correct_ans_chosen){
//								std::cout<<"Sua lai nut: "<<j<<std::endl;
								correct_ans[j].set_bkcolor(Dap_an);
								correct_ans[j].draw();
								correct_ans_button_re_draw[j]=false;
								correct_ans[j].set_enable(true);
							}
						}
						break;
					}
				}
			}
			chose_some_correct_ans=false;
		}else if(chose_something){
			//	std::cout<<"sua";
				if(ques_typing_re_draw){
					ques_typing.draw();
					ques_typing_re_draw=false;
				}
				for(int i=0;i<4;i++){
					if(ans_typing_re_draw[i]){
						ans_typing[i].draw();
						ans_typing_re_draw[i]=false;
					}
				}
				if(done_re_draw){
					done.draw();
					done_re_draw=false;
				}
				if(back_re_draw){
					back.draw();
					back_re_draw=false;
				}
				for(int i=0;i<4;i++){
					if(correct_ans_button_re_draw[i]){
						correct_ans[i].draw();
						correct_ans_button_re_draw[i]=false;
					}
				}
				chose_something=false;
		}else
			if(ismouseclick(WM_LBUTTONDOWN))
				clearmouseclick(WM_LBUTTONDOWN);
	}
	switch(option){
		case 1:
			if(complete_edit()){
				ques_update(ques_typing,ans_typing,ques_container[ques_order_in_container],last_correct_ans_chosen);
				ques_edit(ques_order_in_page,page,max_display);
			}else{
				ques_edit(ques_order_in_page,page,max_display);
			}
			break;
		case 2:
			question_chose_screen();
			break;
	}
}
bool complete_edit(){
	cleardevice();
	draw_background();
	setfillstyle(SOLID_FILL,Dap_an);
	int width=500,height=250;
	bar(CENTERX-width/2,CENTERY-height/2-40,CENTERX-width/2+width,CENTERY-height/2+height);
	std::string xacnhan="Luu chinh sua?";
	char* xacnhan_text=new char[xacnhan.size()+1];
	strcpy(xacnhan_text,xacnhan.c_str());
	delete xacnhan_text;
	setbkcolor(Dap_an);
	outtextxy(CENTERX-textwidth(xacnhan_text)/2,CENTERY-height/2-30,xacnhan_text);
	button yes("Co");
	int yes_no_width=100;
	yes.set_size(yes_no_width,50);
	yes.set_bkcolor(Dap_an);
	int space_between_yes_and_no=100;
	yes.set_location(CENTERX-space_between_yes_and_no/2-yes_no_width,CENTERY-20);
	yes.draw();
	button no("Khong");
	no.set_size(yes_no_width,50);
	no.set_location(CENTERX+space_between_yes_and_no/2,CENTERY-20);
	no.set_bkcolor(Dap_an);
	no.draw();
	bool yes_re_draw=false;
	bool no_re_draw=false;
	int x,y;
	bool option;
	while(true){
		x=mousex();y=mousey();
		if(yes.is_chosen(x,y)||no.is_chosen(x,y)){
			if(yes.is_chosen(x,y)){
				if(!yes_re_draw){
					yes.re_draw();
					yes_re_draw=true;
				}
				if(ismouseclick(WM_LBUTTONDOWN)){
					clearmouseclick(WM_LBUTTONDOWN);
					option=true;
					break;
				}
			}else{
				if(!no_re_draw){
					no.re_draw();
					no_re_draw=true;
				}
				if(ismouseclick(WM_LBUTTONDOWN)){
					clearmouseclick(WM_LBUTTONDOWN);
					option=false;
					break;
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
	}
	return option;
}
void ques_update(typing_board content_of_ques,std::vector<typing_board> ans_arr,question& ques,int correct_ans){
	ques.set_content(content_of_ques.get_value());
	for(int i=0;i<4;i++){
		ques.set_answer(i,ans_arr[i].get_value());
	}
	ques.set_correct_ans(ans_arr[correct_ans].get_value());
}
void update_file(){
	//hienthi();
	file.open("text1.txt",std::ios::out);
	if(file.is_open()){//kiem tra mo file
		for(int i=0;i<ques_container.size();i++){
		//	std::cout<<ques_container[i].get_content()<<std::endl;
			file<<ques_container[i].get_content()<<std::endl;
			file<<ques_container[i].get_correct_ans()<<std::endl; 
			for(int j=0;j<4;j++){
				file<<ques_container[i].get_answer(j)<<std::endl; 
			}
			
		}
		file.close();
	}
}
bool check_empty_component_of_ques(typing_board ques_typing,std::vector<typing_board> ans_arr){
	if(ques_typing.get_value()=="") return true;
	for(int i=0;i<4;i++){
		if(ans_arr[i].get_value()=="") return true;
	}
	return false;
}
void display_empty_component_err(){
	draw_background();
	setfillstyle(SOLID_FILL,Dap_an);
	bar(CENTERX-400,CENTERY-400,CENTERX+800,CENTERY+400);
	setbkcolor(Dap_an);
	std::string err="Co thong tin cau hoi/dap an con trong!";
	char* err_text=new char[err.size()+1];
	strcpy(err_text,err.c_str());
	outtextxy(CENTERX-textwidth(err_text)/2,CENTERY-textheight(err_text)/2,err_text);
	delete err_text;
}
