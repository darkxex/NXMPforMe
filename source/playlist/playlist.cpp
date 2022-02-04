#include "playlist.h"


void playlistmove(std::vector<Playlist::playlist_struct>& v, size_t oldIndex, size_t newIndex)
{
    if (oldIndex > newIndex)
        std::rotate(v.rend() - oldIndex - 1, v.rend() - oldIndex, v.rend() - newIndex);
    else        
        std::rotate(v.begin() + oldIndex, v.begin() + oldIndex + 1, v.begin() + newIndex + 1);
}

Playlist::Playlist(){
	
}

std::vector<Playlist::playlist_struct> Playlist::getPlaylist(){
	return currplaylist;
}

void Playlist::clearPlaylist(){
	currplaylist.clear();
	currentidx = 0;
}

void Playlist::appendFile(std::string name,std::string fulluri){
	Playlist::playlist_struct addentry;
	addentry.name = name;
	addentry.fulluri = fulluri;
	currplaylist.push_back(addentry);
}

void Playlist::removeFile(std::string name,std::string fulluri){
	for(int i=0;i<currplaylist.size();i++){
		if(currplaylist[i].name == name && currplaylist[i].fulluri == fulluri){
			currplaylist.erase (currplaylist.begin() + i);
		}
	}
	
}

Playlist::playlist_struct Playlist::getNext(){
	if(currentidx+1 <currplaylist.size()){
		currentidx = currentidx+1;
	}
	return currplaylist[currentidx];
}
Playlist::playlist_struct Playlist::getPrev(){
	if(currentidx-1 >=0){
		currentidx = currentidx-1;
	}
	return currplaylist[currentidx];
}

Playlist::playlist_struct Playlist::getPlaylistItem(int pos){
	return currplaylist[pos];
}

void Playlist::setPlaylistIdx(int pos){
	if(pos >=0 && pos < currplaylist.size()){
		currentidx = pos;
	}
}

int Playlist::getCurrIdx(){
	return currentidx;
}

void Playlist::moveBack(int eleidx){
	if(eleidx > 0){
		playlistmove(currplaylist,eleidx,eleidx-1);
	}
}

void Playlist::moveForw(int eleidx){
	if(eleidx+1 < currplaylist.size()){
		playlistmove(currplaylist,eleidx,eleidx+1);
	}
}

bool Playlist::isPresent(std::string name,std::string fulluri){
	for(int i=0;i<currplaylist.size();i++){
		if(currplaylist[i].name == name && currplaylist[i].fulluri == fulluri){
			return true;
		}
	}
	return false;
}