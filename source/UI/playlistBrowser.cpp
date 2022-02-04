#include "gui.h"
#include "imgui.h"
#include "imgui_internal.h"
#include "appwindows.h"
#include "utils.h"
#include "localfiles.h"
#include "Enigma2.h"


namespace Windows {
	
	bool playlistHoverSet = false;
	bool playlistHoverIdx = 0;
	
	void PlaylistWindow(bool *focus, bool *first_item){
		Windows::SetupWindow();
		if (ImGui::Begin("Playlist Browser", nullptr, ImGuiWindowFlags_NoScrollbar|ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoCollapse|ImGuiWindowFlags_MenuBar)) {
			if(item.popupstate == POPUP_STATE_NONE){
				ImGui::SetNextWindowFocus();
			}
			float total_w = ImGui::GetContentRegionAvail().x;
			float total_h = ImGui::GetContentRegionAvail().y;
			std::vector<Playlist::playlist_struct> thislist = playlist->getPlaylist();
			if(thislist.size() >0){
				if (ImGui::BeginListBox("Playlist Browser Menu",ImVec2(total_w, total_h))){
					for(unsigned int n=0;n<thislist.size();n++){
						std::string itemid = "##" + std::to_string(n);
						if (ImGui::Selectable(itemid.c_str(), playlist->getCurrIdx() == n)){
							item.laststate = item.state;
							Playlist::playlist_struct playitem = playlist->getPlaylistItem(n);
							playlist->setPlaylistIdx(n);
							libmpv->loadFile(playitem.fulluri);
							libmpv->getFileInfo()->resume = sqlitedb->getResume(playitem.fulluri);
							if(libmpv->getFileInfo()->resume>0){
								item.popupstate = POPUP_STATE_RESUME;
							}
						}
						if (ImGui::IsItemHovered()){
							item.playlistitemHighlighted = n;
						}
						ImGui::SameLine();
						ImGui::Text("%d. %s",n+1,thislist[n].name.c_str());	
					}
				}
				if(item.playlistUpdateHovered){
					std::string itemid = "##" + std::to_string(item.playlistnewHoverIdx);
					printf("Set hover id %d\n",item.playlistnewHoverIdx);
					fflush(stdout);
					ImGui::SetFocusID(ImGui::GetID((itemid.c_str())), ImGui::GetCurrentWindow());
					item.playlistUpdateHovered = false;
				}
				ImGuiContext& g = *GImGui;
				ImGui::NavMoveRequestTryWrapping(g.CurrentWindow, ImGuiNavMoveFlags_LoopY);
				ImGui::EndListBox();
			}else{
				ImGui::SetCursorPosX((total_w - ImGui::CalcTextSize("Empty Playlist", NULL, true).x) * 0.5f);
				ImGui::SetCursorPosY(total_h  * 0.5f);
				ImGui::Text("Empty Playlist");
			}
			
		}
		Windows::ExitWindow();
	}
	
}