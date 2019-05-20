#include <string>
#include <vector>
#include <stdlib.h>
#include <functional>
#include <dirent.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <filesystem>
#include <algorithm>
#include <iterator>

//#define SOURCE "/home/yassir/Documents/programs/smloadr/DOWNLOADS/"
//Made this in a handful of minutes, please don't expect much
struct Song
{
	std::string name;
	std::string artist;
	std::string fullpath;
};

void listFiles(const std::string &path, std::function<void(const std::string &)> cb) {
    if (auto dir = opendir(path.c_str())) {
        while (auto f = readdir(dir)) {
            if (!f->d_name || f->d_name[0] == '.') continue;
            if (f->d_type == DT_DIR) 
                listFiles(path + f->d_name + "/", cb);

            if (f->d_type == DT_REG)
                cb(path + f->d_name);
        }
        closedir(dir);
    }
}

 
template <class Container>
void split2(const std::string& str, Container& cont, char delim = ' ')
{
    std::stringstream ss(str);
    std::string token;
    while (std::getline(ss, token, delim)) {
        cont.push_back(token);
    }
}

void copy_file( const char* srce_file, const char* dest_file )
{
    std::ifstream srce( srce_file, std::ios::binary ) ;
    std::ofstream dest( dest_file, std::ios::binary ) ;
    dest << srce.rdbuf() ;
}


int main(int argc, char** argv)
{
	std::vector<std::string> paths;
	std::vector<Song> songs;
	if(argc<=0) return 1;
	char* SOURCE=argv[1];
	if(sizeof(SOURCE)<=0) return 1;
	
	
	listFiles(SOURCE, [&paths](const std::string &path) {
		paths.push_back(path);
	});
	
	for(int i=0;i<paths.size();i++)
	{
		std::cout << paths[i] << std::endl;
		std::vector<std::string> patharray;
		split2< std::vector<std::string> >(paths[i],patharray,'/');
		Song current;
		bool valid = false;
		if(!patharray.empty())
		{
			current.name=patharray.back().substr(3);
			if(current.name.find("mp3")!= std::string::npos) valid = true;
			current.artist=patharray[patharray.size()-3];
			current.fullpath=paths[i];
		}
		if(valid == true)
			songs.push_back(current);
	}
	std::string outputfolder=std::string(SOURCE)+"transfer/";
	if(system(("mkdir -p "+outputfolder).c_str())==0);
	{
		for(int i=0;i<songs.size();i++)
		{
			std::cout << "Artist:" << songs[i].artist << "\tName:" << songs[i].name << std::endl;
			copy_file(songs[i].fullpath.c_str(), (outputfolder+songs[i].artist+" - "+songs[i].name).c_str());
		}
	}
}

