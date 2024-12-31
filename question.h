#pragma once
#include <string> 
#include <iostream>
//#include "source/question.cpp"
using namespace std;
class question{
	private:
		string content;
		string answer[4];
		string correct_ans;
	public:
		question();
		void set_content(string);
		string get_content();
		string get_answer(int i);
		void set_answer(int,string);
		void show();
		void set_correct_ans(string);
		string get_correct_ans();
};
string question::get_answer(int i){
	return answer[i];
}
question::question(){
}
void question::set_content(string s){
	content=s;
}
string question::get_content(){
	return content;
}
void question::set_answer(int ans,string s){
	answer[ans]=s;
}
void question::show(){
	std::cout<<"Cau hoi:"<<content<<std::endl;
	for(int i=0;i<4;i++){
		std::cout<<"Cau tra loi:  "<<answer[i]<<std::endl;
	}
}
void question::set_correct_ans(string correctAns){
	correct_ans=correctAns;
}
string question::get_correct_ans(){
	return correct_ans;
}



