/* $Id$ */
/*
   Copyright (C) 2003 - 2007 by David White <dave@whitevine.net>
   Part of the Battle for Wesnoth Project http://www.wesnoth.org/

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License version 2.
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY.

   See the COPYING file for more details.
*/
#ifndef GAME_CONFIG_H_INCLUDED
#define GAME_CONFIG_H_INCLUDED

class config;

#include "color_range.hpp"
#include "tstring.hpp"

#include <string>
#include <vector>
#include <map>

//basic game configuration information is here.
namespace game_config
{
	extern int base_income;
	extern int village_income;
	extern int poison_amount;
	extern int rest_heal_amount;
	extern int recall_cost;
	extern int kill_experience;
	extern unsigned lobby_refresh;
	extern const std::string version;
#ifdef SVNREV
	extern const std::string svnrev;
#endif /* SVNREV */

	extern bool debug, editor, ignore_replay_errors, mp_debug, exit_at_end, no_delay, disable_autosave;

	extern std::string path;

	struct server_info {
		std::string name;
		std::string address; //may include ':' followed by port number
	};
	extern std::vector<server_info> server_list;

	extern std::string game_icon, game_title, game_logo, title_music,
	  moved_ball_image, unmoved_ball_image, partmoved_ball_image,
	  enemy_ball_image, ally_ball_image, energy_image,
	  flag_image, flag_icon_image, cross_image,
	  terrain_mask_image, grid_image, unreachable_image, void_image, fog_image,
	  observer_image, tod_bright_image,
	  checked_menu_image, unchecked_menu_image, wml_menu_image, level_image, ellipsis_image, tome_title;

	extern std::string flag_rgb;
	extern std::vector<Uint32> defense_color_scale;

	extern std::vector<std::string> foot_left_nw,foot_left_n,foot_right_nw,foot_right_n;

	extern int title_logo_x, title_logo_y, title_buttons_x, title_buttons_y, title_buttons_padding, title_tip_x, title_tip_width, title_tip_padding;

	extern std::map<std::string, color_range> team_rgb_range;
	extern std::map<std::string, t_string> team_rgb_name;
	
	extern std::map<std::string, std::vector<Uint32> > team_rgb_colors;
	namespace sounds {
		extern const std::string turn_bell, receive_message, user_arrive, user_leave;
		extern const std::string button_press, checkbox_release, slider_adjust,
			menu_expand, menu_contract, menu_select;
	}
	
        void load_config(const config* cfg);
        
	const void add_color_info(const config& v);
	const std::vector<Uint32>& tc_info(const std::string& name);

	struct game_version {
		game_version(std::string str);
	
		//Note gcc 4.1.2(prerelease) as shipped in Debian etch doesn't 
		//like the name major and minor :( so make gcc happy
		unsigned int major_nr;
		unsigned int minor_nr;
		unsigned int patch;
		std::string extra;

		std::string full;
	};

	// Note the < <= > and >= operator ignore the extra version the == and != do
	// use the extra version.
	bool operator<(const struct game_version& a, const struct game_version& b); 
	bool operator<=(const struct game_version& a, const struct game_version& b); 
	bool operator>(const struct game_version& a, const struct game_version& b); 
	bool operator>=(const struct game_version& a, const struct game_version& b); 
	bool operator==(const struct game_version& a, const struct game_version& b);
	bool operator!=(const struct game_version& a, const struct game_version& b);

	extern const struct game_version wesnoth_version;
	extern const struct game_version min_savegame_version;

}

#endif
