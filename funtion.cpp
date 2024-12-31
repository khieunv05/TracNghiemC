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
void draw_background(){
	cleardevice();
	//ve khung 
	setfillstyle(SOLID_FILL,KHUNG_NGOAI);
	bar(0,0,SCREEN_WIDTH,SCREEN_HEIGHT);
	setfillstyle(SOLID_FILL,WHITE);
	int boder_thickness=30;
	bar(boder_thickness,boder_thickness,SCREEN_WIDTH-boder_thickness,SCREEN_HEIGHT-boder_thickness);
	//nhan tieu de
	Label sua("Delete questions");
	sua.set_size(SCREEN_WIDTH-2*boder_thickness,40);
	sua.set_position(CENTERX-sua.get_width()/2,boder_thickness);
	sua.set_bgcolor(NHAN);
	sua.draw();
}
bool load_file(const std::string file_name,std::vector<question> &ques_container,fstream &file){
	file.open(file_name,std::ios::in|std::ios::out);
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
		delay(2000);
		file_err_label.draw();	
		return false;
	}
//	std::cout<<"size:"<<ques_container.size()<<std::endl;
}
void ques_update(typing_board content_of_ques,std::vector<typing_board> ans_arr,question& ques,int correct_ans){
	ques.set_content(content_of_ques.get_value());
	for(int i=0;i<4;i++){
		ques.set_answer(i,ans_arr[i].get_value());
	}
	ques.set_correct_ans(ans_arr[correct_ans].get_value());
}

