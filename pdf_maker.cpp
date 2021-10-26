#include<iostream>
#include<map>
using namespace std;

void command() {
	// base{当前点名字}{{{{
	cout<<"\\newcommand\\base[3] {"<<endl;
	cout<<"\t\\node (#1) [draw, opacity=0.5, thick, text=black, minimum width=4cm, minimum height=2cm, align=center] at (#2, #3) {#1};"<<endl;
	cout<<"}"<<endl;


	cout<<"\\newcommand\\done[4] {"<<endl;
	cout<<"\t\\node (#1) [draw, opacity=0.5, thick, fill=green, fill opacity=0.7, text=black, minimum width=4cm, minimum height=2cm, align=center] at(#2, #3) {\\href{#4}{#1}};"<<endl;
	cout<<"}"<<endl;

	cout<<"\\newcommand\\todo[3] {"<<endl;
	cout<<"\t\\node (#1) [draw, opacity=0.5, thick, fill=red, fill opacity=0.6, text=black, minimum width=4cm, minimum height=2cm, align=center] at(#2, #3) {#1};"<<endl;
	cout<<"}"<<endl;

	cout<<"\\newcommand\\arrow[2] {"<<endl;
	cout<<"\t\\draw [->, line width=1.2pt] (#1) -- (#2);"<<endl;
	cout<<"}"<<endl;
}/*}}}*/

void start() {/*{{{*/
	freopen("./main.tex", "w", stdout);
	freopen("./node", "r", stdin);
	cout<<"\\documentclass[border=5mm,12pt,tikz]{standalone}"<<endl;
	cout<<"\\usetikzlibrary{3d,calc,backgrounds,patterns}"<<endl;
	cout<<"\\usetikzlibrary{positioning}"<<endl;
	cout<<"\\usepackage{tikz}"<<endl;
	cout<<"\\usepackage{color}"<<endl;
	cout<<"\\usepackage{fouriernc}"<<endl;
	cout<<"\\usepackage{xeCJK}"<<endl;
	cout<<"\\usepackage{amsmath}"<<endl;
	cout<<"\\usepackage[colorlinks,linkcolor=blue]{hyperref}"<<endl;
	
	command();

	cout<<"\\begin{document}"<<endl;
	cout<<"\\begin{tikzpicture}"<<endl;
	cout<<"\t\\node (base) [draw, opacity=0.5, thick, text=black, minimum width=4cm, minimum height=2cm, align=center] at (0,0) {基本的代码/\\\\ Debug能力};"<<endl;
	cout<<"\t\\node (comment) [above=of base,align=center] {白色方框表示一些汇总节点\\\\绿色方框表示已经完成的博客，可以直接点击\\\\红色方框表示尚未完成的博客，欢迎催更};"<<endl;
}/*}}}*/

void end() {
	cout<<"\\end{tikzpicture}"<<endl;
	cout<<"\\end{document}"<<endl;
}
string name, type, prefix_name, url;
int x, y;
map<string,int> xshift, yshift;
int main() {
	start();
	xshift["base"] = 0;
	yshift["base"] = 0;
	while(cin>>name>>type>>x>>y>>prefix_name) {
		xshift[name] = xshift[prefix_name] + x * 8;
		yshift[name] = yshift[prefix_name] + y * 4;
		cout<<"\t\\"<<type<<"{"<<name<<"}"<<"{";
		cout<<xshift[name]<<"}{"<<yshift[name]<<"}";
		if(type=="done") {
			cin>>url;
			cout<<"{"<<url<<"}";
		}
		cout<<";"<<endl;
	}
	freopen("./arrow", "r", stdin);
	cin.clear();
	while(cin>>prefix_name>>name) {
		cout<<"\t\\arrow{"<<prefix_name<<"}{"<<name<<"};"<<endl;
	}
	end();
	return 0;
}
