#include <iostream>
#include <conio.h>
#include <windows.h>
#include <string>
#include <fstream>
#include <list>
struct aList
{
	std::list <std::string> list;
	std::string FolderName;
	std::string file_path;
};
void cmd(std::string cmd){
	system((const char*)cmd.c_str());
}
void wget(std::string file,std::string path)
{
	cmd("wget.exe -q --no-check-certificate -P \"%cd%\\"+path+"\" "+ file);
}
std::string getFilePath(void){
			std::string file_path;
			std::cout<<"Enter file path: ";
			std::cin>>file_path;
			return file_path;
}
std::string getFolderName(void){
			std::string fname;
			std::cout<<"Enter folder name: ";
			std::cin>>fname;
			return fname;
}
void startDownload(aList mylist)
{
			std::cout<<"Downloading "+mylist.file_path+" [";
			auto ib = mylist.list.begin(), ie = mylist.list.end();
			cmd("md "+mylist.FolderName);
				while(ie != ib)
				{
					std::cout<<"-";
					wget(*ib, mylist.FolderName);
					++ib;
				}
			std::cout<<"]\n";
}
aList getList(void){
tryAgain:

	aList mylist;
	mylist.file_path = getFilePath();
	mylist.FolderName = getFolderName();

		std::ifstream File(mylist.file_path);
		if(File.is_open()){
		
			boolean x = true;
			std::string temp;
			std::string backtemp;
			
			while (x)
			{
				getline(File,temp);
				if(temp != backtemp){
					mylist.list.push_back(temp);
				}else{x=false;}
				backtemp = temp;
			}
		}else
		{
			std::cout<<"error: File "+mylist.file_path+" !found"<<std::endl;
			goto tryAgain;
		}

		return mylist;
};
int main()
{
	startDownload(getList());
		std::cout<<"Press any key to exit...";
		_getch();
	return 0;
}
