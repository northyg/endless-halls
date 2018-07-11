/*********************************************************************
** Program name: Endless Halls
** Author: Giselle Northy
** Date: 6/3/2018
** Description: 

This program is a maze of rooms linked together by pointers. Players need
to find orbs in rooms, pick them up and place them on altars in altar rooms
to win. In easy mode, the player has 20 steps before they go "insane" and lose.
In hard mode, they can take 500 steps before they go "insane." 

Easy Map has 9 rooms
Hard Map has 222 rooms
*********************************************************************/


#include <space.hpp>
#include <board.hpp>
#include <orbRoom.hpp>
#include <teleportRoom.hpp>
#include <altarRoom.hpp>
#include <room.hpp>
#include <iostream>



using namespace std;

/********************************************************************
	Board
*********************************************************************/
Board::Board()
{
	
}

/********************************************************************
	Adds rooms to the board
*********************************************************************/
Board::~Board()
{

	Space* room;
	while (!board.empty())
	{
		room = board.back();
		delete room;
		board.pop_back();
	}
}

/********************************************************************
	Resets the board
*********************************************************************/
void Board::resetBoard()
{

	Space* room;
	while (!board.empty())
	{
		room = board.back();
		delete room;
		board.pop_back();
	}
}

/********************************************************************
	Displays the Rooms
*********************************************************************/
void Board::displayRoom(Space* room)
{
	char left, right;
	
	// clear the screen first
	cout << "\033[2J";

	// if up
	if(room->getUp() == NULL)
	{
		cout << SET_YELLOW << " ##### \n" << SET_COLOR_NORMAL;
	}
	else
	{
		cout << SET_GREEN << " ===== \n" << SET_COLOR_NORMAL;
	}
	
	printLeft(room);
	cout << "     ";
	printRight(room);
	printLeft(room);
	cout << "     ";
	printRight(room);

	printLeft(room);
	if(room->hasOrb() == true)
	{

		if(((Orb*)room)->getColorOrb() == "Red")
		{
			cout  << SET_RED << " -0- " << SET_COLOR_NORMAL ;	
		}
		else if(((Orb*)room)->getColorOrb() == "Blue")
		{
			cout  << SET_BLUE << " -0- " << SET_COLOR_NORMAL ;
		}
		else if(((Orb*)room)->getColorOrb() == "Yellow")
		{
			cout  << SET_BOLD_YELLOW << " -0- " << SET_COLOR_NORMAL ;
		}
		else if(((Orb*)room)->getColorOrb() == "Green")
		{
			cout  << SET_BOLD_GREEN << " -0- " << SET_COLOR_NORMAL ;
		}
		else if(((Orb*)room)->getColorOrb() == "Purple")
		{
			cout  << SET_MAGENTA << " -0- " << SET_COLOR_NORMAL ;
		}
	}
	
	else if(room->hasAltar() == true)
	{	
		if(((Altar*)room)->getColorAltar() == "Red")
		{
			cout << SET_RED << " ~+~ " << SET_COLOR_NORMAL ;
		}
		else if(((Altar*)room)->getColorAltar() == "Blue")
		{
			cout << SET_BLUE << " ~+~ " << SET_COLOR_NORMAL ;
		}
		else if(((Altar*)room)->getColorAltar() == "Yellow")
		{
			cout << SET_BOLD_YELLOW << " ~+~ " << SET_COLOR_NORMAL ;
		}
		else if(((Altar*)room)->getColorAltar() == "Green")
		{
			cout << SET_BOLD_GREEN << " ~+~ " << SET_COLOR_NORMAL ;
		}
		else if(((Altar*)room)->getColorAltar() == "Purple")
		{
			cout << SET_MAGENTA << " ~+~ " << SET_COLOR_NORMAL ;
		}
	}
	else
	{
		cout << "     ";
	}
	printRight(room);

	
	printLeft(room);
	cout << "     ";
	printRight(room);
	printLeft(room);
	cout << "     ";
	printRight(room);
	
	// if down
	if(room->getDown() == NULL)
	{
		cout << SET_YELLOW << " #####\n" << SET_COLOR_NORMAL;
	}
	else
	{
		cout << SET_GREEN << " =====\n" << SET_COLOR_NORMAL;
	}

	
}

/********************************************************************

*********************************************************************/
void Board::printLeft(Space* room)
{
	if(room->getLeft() == NULL)
	{
		// left = '#';
		cout << SET_YELLOW << "#" << SET_COLOR_NORMAL;
	}
	else
	{
		// left = '|';
		cout << SET_GREEN << "|" << SET_COLOR_NORMAL;
	}
}

/********************************************************************
	Prints right
*********************************************************************/
void Board::printRight(Space* room)
{
	if(room->getRight() == NULL)
	{
		// right = '#';	
		cout << SET_YELLOW << "#" << SET_COLOR_NORMAL << endl;		
	}
	else
	{
		// right = '|';
		cout << SET_GREEN << "|" << SET_COLOR_NORMAL << endl;
	}
}


/********************************************************************
	Start room is set to 0
*********************************************************************/
Space* Board::getStartRoom()
{
	return board.at(0);	// return the first room created
}

/********************************************************************
	Get rooms at specific points
*********************************************************************/
Space* Board::getSpecificRoom(int index)
{
	return board.at(index);
}

/********************************************************************
	Returns the board size of rooms
*********************************************************************/
int Board::getNumberOfRooms()
{
	return board.size();
}

/********************************************************************
	Creates the easy board 9 rooms
*********************************************************************/
void Board::createEasyBoard()
{
	Space* room1 = new Room();
	board.push_back(room1);

	Space* room2 = new Room();
	board.push_back(room2);

	Space* room3 = new Altar();
	((Altar*)room3)->setColorAltar("Red");
	board.push_back(room3);

	Space* room4 = new Room();
	board.push_back(room4);

	Space* room5 = new Orb();
	((Orb*)room5)->setColorOrb("Red");
	board.push_back(room5);

	Space* room6 = new Room();
	board.push_back(room6);

	Space* room7 = new Teleport();
	board.push_back(room7);

	Space* room8 = new Room();
	board.push_back(room8);

	Space* room9 = new Room();
	board.push_back(room9);

	room1->connectSpace(room2, RIGHT);
	room1->connectSpace(room9, UP);
	room1->connectSpace(room4, DOWN);
	room2->connectSpace(room3, RIGHT);
	room3->connectSpace(room6, DOWN);
	room6->connectSpace(room9, DOWN);
	room9->connectSpace(room8, LEFT);
	room8->connectSpace(room7, LEFT);
	room4->connectSpace(room5, RIGHT);
}

/********************************************************************
	Creates the hard board 222 rooms
*********************************************************************/
void Board::createHardBoard()
{
	Space* room1 = new Room();
	board.push_back(room1);

	Space* room2 = new Room();
	board.push_back(room2);

	Space* room3 = new Room();
	board.push_back(room3);

	Space* room4 = new Room();
	board.push_back(room4);

	Space* room5 = new Room();
	board.push_back(room5);

	Space* room6 = new Room();
	board.push_back(room6);

	Space* room7 = new Room();
	board.push_back(room7);

	Space* room8 = new Room();
	board.push_back(room8);

	Space* room9 = new Room();
	board.push_back(room9);

	Space* room10 = new Room();
	board.push_back(room10);

	Space* room11 = new Room();
	board.push_back(room11);

	Space* room12 = new Room();
	board.push_back(room12);

	Space* room13 = new Room();
	board.push_back(room13);

	Space* room14 = new Room();
	board.push_back(room14);

	Space* room15 = new Room();
	board.push_back(room15);

	Space* room16 = new Altar();
	((Altar*)room16)->setColorAltar("Yellow");
	board.push_back(room16);

	Space* room17 = new Room();
	board.push_back(room17);

	Space* room18 = new Room();
	board.push_back(room18);

	Space* room19 = new Room();
	board.push_back(room19);

	Space* room20 = new Room();
	board.push_back(room20);

	Space* room21 = new Room();
	board.push_back(room21);

	Space* room22 = new Room();
	board.push_back(room22);

	Space* room23 = new Room();
	board.push_back(room23);

	Space* room24 = new Room();
	board.push_back(room24);

	Space* room25 = new Room();
	board.push_back(room25);

	Space* room26 = new Room();
	board.push_back(room26);

	Space* room27 = new Room();
	board.push_back(room27);

	Space* room28 = new Room();
	board.push_back(room28);

	Space* room29 = new Room();
	board.push_back(room29);

	Space* room30 = new Room();
	board.push_back(room30);

	Space* room31 = new Room();
	board.push_back(room31);

	Space* room32 = new Room();
	board.push_back(room32);

	Space* room33 = new Room();
	board.push_back(room33);

	Space* room34 = new Room();
	board.push_back(room34);

	Space* room35 = new Room();
	board.push_back(room35);

	Space* room36 = new Room();
	board.push_back(room36);

	Space* room37 = new Room();
	board.push_back(room37);

	Space* room38 = new Room();
	board.push_back(room38);

	Space* room39 = new Room();
	board.push_back(room39);

	Space* room40 = new Room();
	board.push_back(room40);

	Space* room41 = new Room();
	board.push_back(room41);

	Space* room42 = new Room();
	board.push_back(room42);

	Space* room43 = new Room();
	board.push_back(room43);

	Space* room44 = new Room();
	board.push_back(room44);

	Space* room45 = new Orb();
	((Orb*)room45)->setColorOrb("Blue");
	board.push_back(room45);

	Space* room46 = new Room();
	board.push_back(room46);

	Space* room47 = new Room();
	board.push_back(room47);

	Space* room48 = new Room();
	board.push_back(room48);

	Space* room49 = new Room();
	board.push_back(room49);

	Space* room50 = new Altar();
	((Altar*)room50)->setColorAltar("Purple");
	board.push_back(room50);

	Space* room51 = new Room();
	board.push_back(room51);

	Space* room52 = new Room();
	board.push_back(room52);

	Space* room53 = new Room();
	board.push_back(room53);

	Space* room54 = new Room();
	board.push_back(room54);

	Space* room55 = new Room();
	board.push_back(room55);

	Space* room56 = new Room();
	board.push_back(room56);

	Space* room57 = new Room();
	board.push_back(room57);

	Space* room58 = new Teleport();
	board.push_back(room58);

	Space* room59 = new Room();
	board.push_back(room59);

	Space* room60 = new Room();
	board.push_back(room60);

	Space* room61 = new Room();
	board.push_back(room61);

	Space* room62 = new Room();
	board.push_back(room62);

	Space* room63 = new Room();
	board.push_back(room63);

	Space* room64 = new Altar();
	((Altar*)room64)->setColorAltar("Blue");
	board.push_back(room64);

	Space* room65 = new Room();
	board.push_back(room65);

	Space* room66 = new Room();
	board.push_back(room66);

	Space* room67 = new Room();
	board.push_back(room67);

	Space* room68 = new Room();
	board.push_back(room68);

	Space* room69 = new Room();
	board.push_back(room69);

	Space* room70 = new Room();
	board.push_back(room70);

	Space* room71 = new Room();
	board.push_back(room71);

	Space* room72 = new Room();
	board.push_back(room72);

	Space* room73 = new Room();
	board.push_back(room73);

	Space* room74 = new Room();
	board.push_back(room74);

	Space* room75 = new Room();
	board.push_back(room75);

	Space* room76 = new Orb();
	((Orb*)room76)->setColorOrb("Red");
	board.push_back(room76);

	Space* room77 = new Room();
	board.push_back(room77);

	Space* room78 = new Room();
	board.push_back(room78);

	Space* room79 = new Room();
	board.push_back(room79);

	Space* room80 = new Room();
	board.push_back(room80);

	Space* room81 = new Room();
	board.push_back(room81);

	Space* room82 = new Room();
	board.push_back(room82);

	Space* room83 = new Room();
	board.push_back(room83);

	Space* room84 = new Room();
	board.push_back(room84);

	Space* room85 = new Room();
	board.push_back(room85);

	Space* room86 = new Room();
	board.push_back(room86);

	Space* room87 = new Room();
	board.push_back(room87);

	Space* room88 = new Room();
	board.push_back(room88);

	Space* room89 = new Room();
	board.push_back(room89);

	Space* room90 = new Room();
	board.push_back(room90);

	Space* room91 = new Room();
	board.push_back(room91);

	Space* room92 = new Room();
	board.push_back(room92);

	Space* room93 = new Room();
	board.push_back(room93);

	Space* room94 = new Room();
	board.push_back(room94);

	Space* room95 = new Room();
	board.push_back(room95);

	Space* room96 = new Room();
	board.push_back(room96);

	Space* room97 = new Room();
	board.push_back(room97);

	Space* room98 = new Room();
	board.push_back(room98);

	Space* room99 = new Room();
	board.push_back(room99);

	Space* room100 = new Room();
	board.push_back(room100);

	Space* room101 = new Room();
	board.push_back(room101);

	Space* room102 = new Room();
	board.push_back(room102);

	Space* room103 = new Room();
	board.push_back(room103);

	Space* room104 = new Room();
	board.push_back(room104);

	Space* room105 = new Room();
	board.push_back(room105);

	Space* room106 = new Room();
	board.push_back(room106);

	Space* room107 = new Room();
	board.push_back(room107);

	Space* room108 = new Room();
	board.push_back(room108);

	Space* room109 = new Room();
	board.push_back(room109);

	Space* room110 = new Room();
	board.push_back(room110);

	Space* room111 = new Room();
	board.push_back(room111);

	Space* room112 = new Room();
	board.push_back(room112);

	Space* room113 = new Orb();
	((Orb*)room113)->setColorOrb("Yellow");
	board.push_back(room113);

	Space* room114 = new Room();
	board.push_back(room114);

	Space* room115 = new Room();
	board.push_back(room115);

	Space* room116 = new Room();
	board.push_back(room116);

	Space* room117 = new Room();
	board.push_back(room117);

	Space* room118 = new Room();
	board.push_back(room118);

	Space* room119 = new Room();
	board.push_back(room119);

	Space* room120 = new Room();
	board.push_back(room120);

	Space* room121 = new Room();
	board.push_back(room121);

	Space* room122 = new Altar();
	((Altar*)room122)->setColorAltar("Green");
	board.push_back(room122);

	Space* room123 = new Room();
	board.push_back(room123);

	Space* room124 = new Room();
	board.push_back(room124);

	Space* room125 = new Room();
	board.push_back(room125);

	Space* room126 = new Room();
	board.push_back(room126);

	Space* room127 = new Room();
	board.push_back(room127);

	Space* room128 = new Room();
	board.push_back(room128);

	Space* room129 = new Room();
	board.push_back(room129);

	Space* room130 = new Room();
	board.push_back(room130);

	Space* room131 = new Room();
	board.push_back(room131);

	Space* room132 = new Room();
	board.push_back(room132);

	Space* room133 = new Room();
	board.push_back(room133);

	Space* room134 = new Altar();
	((Altar*)room134)->setColorAltar("Red");
	board.push_back(room134);

	Space* room135 = new Room();
	board.push_back(room135);

	Space* room136 = new Room();
	board.push_back(room136);

	Space* room137 = new Room();
	board.push_back(room137);

	Space* room138 = new Room();
	board.push_back(room138);

	Space* room139 = new Room();
	board.push_back(room139);

	Space* room140 = new Room();
	board.push_back(room140);

	Space* room141 = new Room();
	board.push_back(room141);

	Space* room142 = new Room();
	board.push_back(room142);

	Space* room143 = new Room();
	board.push_back(room143);

	Space* room144 = new Room();
	board.push_back(room144);

	Space* room145 = new Room();
	board.push_back(room145);

	Space* room146 = new Room();
	board.push_back(room146);

	Space* room147 = new Room();
	board.push_back(room147);

	Space* room148 = new Room();
	board.push_back(room148);

	Space* room149 = new Room();
	board.push_back(room149);

	Space* room150 = new Room();
	board.push_back(room150);

	Space* room151 = new Room();
	board.push_back(room151);

	Space* room152 = new Room();
	board.push_back(room152);

	Space* room153 = new Room();
	board.push_back(room153);

	Space* room154 = new Room();
	board.push_back(room154);

	Space* room155 = new Room();
	board.push_back(room155);

	Space* room156 = new Room();
	board.push_back(room156);

	Space* room157 = new Room();
	board.push_back(room157);

	Space* room158 = new Room();
	board.push_back(room158);

	Space* room159 = new Room();
	board.push_back(room159);

	Space* room160 = new Room();
	board.push_back(room160);

	Space* room161 = new Room();
	board.push_back(room161);

	Space* room162 = new Room();
	board.push_back(room162);

	Space* room163 = new Room();
	board.push_back(room163);

	Space* room164 = new Room();
	board.push_back(room164);

	Space* room165 = new Room();
	board.push_back(room165);

	Space* room166 = new Orb();
	((Orb*)room166)->setColorOrb("Green");
	board.push_back(room166);

	Space* room167 = new Room();
	board.push_back(room167);

	Space* room168 = new Room();
	board.push_back(room168);

	Space* room169 = new Room();
	board.push_back(room169);

	Space* room170 = new Room();
	board.push_back(room170);

	Space* room171 = new Room();
	board.push_back(room171);

	Space* room172 = new Room();
	board.push_back(room172);

	Space* room173 = new Room();
	board.push_back(room173);

	Space* room174 = new Room();
	board.push_back(room174);

	Space* room175 = new Orb();
	((Orb*)room175)->setColorOrb("Purple");
	board.push_back(room175);

	Space* room176 = new Room();
	board.push_back(room176);

	Space* room177 = new Room();
	board.push_back(room177);

	Space* room178 = new Room();
	board.push_back(room178);

	Space* room179 = new Room();
	board.push_back(room179);

	Space* room180 = new Room();
	board.push_back(room180);

	Space* room181 = new Room();
	board.push_back(room181);

	Space* room182 = new Room();
	board.push_back(room182);

	Space* room183 = new Room();
	board.push_back(room183);

	Space* room184 = new Room();
	board.push_back(room184);

	Space* room185 = new Room();
	board.push_back(room185);

	Space* room186 = new Room();
	board.push_back(room186);

	Space* room187 = new Room();
	board.push_back(room187);

	Space* room188 = new Room();
	board.push_back(room188);

	Space* room189 = new Room();
	board.push_back(room189);

	Space* room190 = new Room();
	board.push_back(room190);

	Space* room191 = new Room();
	board.push_back(room191);

	Space* room192 = new Room();
	board.push_back(room192);

	Space* room193 = new Room();
	board.push_back(room193);

	Space* room194 = new Room();
	board.push_back(room194);

	Space* room195 = new Room();
	board.push_back(room195);

	Space* room196 = new Room();
	board.push_back(room196);

	Space* room197 = new Room();
	board.push_back(room197);

	Space* room198 = new Room();
	board.push_back(room198);

	Space* room199 = new Room();
	board.push_back(room199);

	Space* room200 = new Room();
	board.push_back(room200);

	Space* room201 = new Room();
	board.push_back(room201);

	Space* room202 = new Room();
	board.push_back(room202);

	Space* room203 = new Room();
	board.push_back(room203);

	Space* room204 = new Room();
	board.push_back(room204);

	Space* room205 = new Room();
	board.push_back(room205);

	Space* room206 = new Room();
	board.push_back(room206);

	Space* room207 = new Room();
	board.push_back(room207);

	Space* room208 = new Room();
	board.push_back(room208);

	Space* room209 = new Room();
	board.push_back(room209);

	Space* room210 = new Room();
	board.push_back(room210);

	Space* room211 = new Room();
	board.push_back(room211);

	Space* room212 = new Room();
	board.push_back(room212);

	Space* room213 = new Room();
	board.push_back(room213);

	Space* room214 = new Room();
	board.push_back(room214);

	Space* room215 = new Room();
	board.push_back(room215);

	Space* room216 = new Room();
	board.push_back(room216);

	Space* room217 = new Room();
	board.push_back(room217);

	Space* room218 = new Room();
	board.push_back(room218);

	Space* room219 = new Room();
	board.push_back(room219);

	Space* room220 = new Room();
	board.push_back(room220);

	Space* room221 = new Room();
	board.push_back(room221);

	Space* room222 = new Room();
	board.push_back(room222);

	// connects the rooms
/********************************************************************
 Due to the nature of the map, not all rooms connect exactly in sequence
*********************************************************************/
	room1->connectSpace(room2, UP);
	room2->connectSpace(room3, UP);
	room3->connectSpace(room4, UP);
	room4->connectSpace(room5, UP);
	room4->connectSpace(room163, LEFT);
	room5->connectSpace(room6, UP);
	room6->connectSpace(room7, UP);
	room7->connectSpace(room8, UP);
	room8->connectSpace(room9, UP);
	room9->connectSpace(room10, UP);
	room10->connectSpace(room11, LEFT);
	room11->connectSpace(room12, LEFT);
	room12->connectSpace(room13, LEFT);
	room13->connectSpace(room14, UP);
	room14->connectSpace(room15, UP);
	room15->connectSpace(room16, UP);
	// Room 16 is yellow altar room
	room16->connectSpace(room17, UP);
	room16->connectSpace(room213, LEFT);
	room17->connectSpace(room18, UP);
	room18->connectSpace(room19, UP);
	room19->connectSpace(room20, RIGHT);
	room20->connectSpace(room21, RIGHT);
	room21->connectSpace(room22, RIGHT);
	room22->connectSpace(room23, DOWN);
	room23->connectSpace(room24, DOWN);
	room24->connectSpace(room25, DOWN);
	room25->connectSpace(room26, RIGHT);
	room26->connectSpace(room27, RIGHT);
	room27->connectSpace(room28, RIGHT);
	room28->connectSpace(room29, RIGHT);
	room29->connectSpace(room30, RIGHT);
	room30->connectSpace(room31, RIGHT);
	room31->connectSpace(room32, RIGHT);
	room31->connectSpace(room42, DOWN);
	room32->connectSpace(room33, RIGHT);
	room33->connectSpace(room34, RIGHT);
	room34->connectSpace(room35, DOWN);
	room34->connectSpace(room164, UP);
	room35->connectSpace(room36, DOWN);
	room36->connectSpace(room37, DOWN);
	room37->connectSpace(room38, LEFT);
	room37->connectSpace(room165, RIGHT);
	room38->connectSpace(room39, LEFT);
	room39->connectSpace(room40, LEFT);
	room40->connectSpace(room41, UP);
	room40->connectSpace(room43, LEFT);
	room41->connectSpace(room42, UP);
	// Room 42 does not connect 41 and 43
	room43->connectSpace(room44, LEFT);
	room44->connectSpace(room45, LEFT);
	//45 is blue orb room
	room45->connectSpace(room46, UP);
	room46->connectSpace(room47, UP);
	room47->connectSpace(room48, UP);
	room48->connectSpace(room49, UP);
	room49->connectSpace(room50, UP);
	//50 is a purple altar
	room50->connectSpace(room51, RIGHT);
	room51->connectSpace(room52, RIGHT);
	room52->connectSpace(room53, RIGHT);
	room53->connectSpace(room54, UP);
	room54->connectSpace(room55, UP);
	room55->connectSpace(room56, UP);
	room56->connectSpace(room57, UP);
	room57->connectSpace(room58, UP);
	// 58 is teleport room
	room58->connectSpace(room59, LEFT);
	room59->connectSpace(room60, LEFT);
	room60->connectSpace(room61, LEFT);
	room61->connectSpace(room62, UP);
	room61->connectSpace(room219, DOWN);
	room62->connectSpace(room63, UP);
	room63->connectSpace(room64, UP);
	// 64 is an altar room
	room64->connectSpace(room65, UP);
	room64->connectSpace(room209, RIGHT);
	room65->connectSpace(room66, UP);
	room66->connectSpace(room67, UP);
	room67->connectSpace(room68, RIGHT);
	room67->connectSpace(room208, UP);
	room68->connectSpace(room69, RIGHT);
	room69->connectSpace(room70, RIGHT);
	room70->connectSpace(room71, UP);
	room71->connectSpace(room72, UP);
	room72->connectSpace(room73, UP);
	room73->connectSpace(room74, RIGHT);
	room74->connectSpace(room75, RIGHT);
	room75->connectSpace(room76, RIGHT);
	// 76 is a red orb room
	room76->connectSpace(room77, RIGHT);
	room77->connectSpace(room78, RIGHT);
	room78->connectSpace(room79, RIGHT);
	room79->connectSpace(room80, UP);
	room80->connectSpace(room81, UP);
	room81->connectSpace(room82, UP);
	room82->connectSpace(room83, LEFT);
	room82->connectSpace(room105, UP);
	room83->connectSpace(room84, LEFT);
	room84->connectSpace(room85, LEFT);
	room85->connectSpace(room86, LEFT);
	room86->connectSpace(room87, LEFT);
	room87->connectSpace(room88, LEFT);
	room88->connectSpace(room89, UP);
	room89->connectSpace(room90, UP);
	room90->connectSpace(room91, UP);
	room91->connectSpace(room92, RIGHT);
	room91->connectSpace(room218, UP);
	room92->connectSpace(room93, RIGHT);
	room93->connectSpace(room94, RIGHT);
	room94->connectSpace(room95, UP);
	room95->connectSpace(room96, UP);
	room96->connectSpace(room97, UP);
	room97->connectSpace(room98, RIGHT);
	room98->connectSpace(room99, RIGHT);
	room99->connectSpace(room100, RIGHT);
	room100->connectSpace(room101, DOWN);
	room100->connectSpace(room106, UP);
	room101->connectSpace(room102, DOWN);
	room102->connectSpace(room103, DOWN);
	room103->connectSpace(room104, DOWN);
	room104->connectSpace(room105, DOWN);

	room106->connectSpace(room107, UP);
	room107->connectSpace(room108, UP);
	room108->connectSpace(room109, UP);
	room109->connectSpace(room110, UP);
	room110->connectSpace(room111, LEFT);
	room111->connectSpace(room112, LEFT);
	room112->connectSpace(room113, LEFT);
	// 113 is a yellow orb room
	room113->connectSpace(room114, UP);
	room114->connectSpace(room115, UP);
	room115->connectSpace(room116, UP);
	room116->connectSpace(room117, RIGHT);
	room116->connectSpace(room195, LEFT);
	room117->connectSpace(room118, RIGHT);
	room118->connectSpace(room119, RIGHT);
	room119->connectSpace(room120, UP);
	room120->connectSpace(room121, UP);
	room121->connectSpace(room122, UP);
	// 122 is green altar room
	room122->connectSpace(room123, LEFT);
	room123->connectSpace(room124, LEFT);
	room124->connectSpace(room125, LEFT);
	room125->connectSpace(room126, LEFT);
	room126->connectSpace(room127, LEFT);
	room127->connectSpace(room128, LEFT);
	room128->connectSpace(room129, LEFT);
	room129->connectSpace(room130, LEFT);
	room130->connectSpace(room131, LEFT);
	room131->connectSpace(room132, DOWN);
	room131->connectSpace(room222, UP);
	room132->connectSpace(room133, DOWN);
	room133->connectSpace(room134, DOWN);
	room134->connectSpace(room135, DOWN);
	// 3 way room connection
	room134->connectSpace(room191, RIGHT);
	room135->connectSpace(room136, DOWN);
	room136->connectSpace(room137, DOWN);
	room137->connectSpace(room138, DOWN);
	room137->connectSpace(room190, RIGHT);
	room138->connectSpace(room139, DOWN);
	room139->connectSpace(room140, DOWN);
	room140->connectSpace(room141, RIGHT);
	room141->connectSpace(room142, RIGHT);
	room142->connectSpace(room143, RIGHT);
	room143->connectSpace(room144, RIGHT);
	room144->connectSpace(room145, RIGHT);
	room145->connectSpace(room146, RIGHT);
	room146->connectSpace(room147, RIGHT);
	room147->connectSpace(room148, RIGHT);
	room148->connectSpace(room149, RIGHT);
	room149->connectSpace(room150, RIGHT);
	room150->connectSpace(room151, RIGHT);
	room151->connectSpace(room152, RIGHT);
	room152->connectSpace(room153, RIGHT);
	room153->connectSpace(room154, RIGHT);
	room154->connectSpace(room155, RIGHT);
	room155->connectSpace(room156, RIGHT);
	room156->connectSpace(room157, RIGHT);
	room157->connectSpace(room158, RIGHT);
	room158->connectSpace(room159, DOWN);
	room159->connectSpace(room160, DOWN);
	room160->connectSpace(room161, DOWN);
	room161->connectSpace(room162, RIGHT);
	room161->connectSpace(room164, DOWN);
	room162->connectSpace(room163, RIGHT);


	// room164->connectSpace(room165, DOWN);
	room165->connectSpace(room166, RIGHT);
	// 166 is a green orb room
	room166->connectSpace(room167, RIGHT);
	room166->connectSpace(room203, DOWN);
	room167->connectSpace(room168, RIGHT);
	room168->connectSpace(room169, RIGHT);
	room169->connectSpace(room170, UP);
	room170->connectSpace(room171, UP);
	room171->connectSpace(room172, UP);
	room172->connectSpace(room173, UP);
	room173->connectSpace(room174, UP);
	room174->connectSpace(room175, UP);
	// 175 is a purple orb room
	room175->connectSpace(room176, UP);
	room175->connectSpace(room214, RIGHT);
	room176->connectSpace(room177, UP);
	room177->connectSpace(room178, UP);
	room178->connectSpace(room179, RIGHT);
	room179->connectSpace(room180, RIGHT);
	room180->connectSpace(room181, RIGHT);
	room181->connectSpace(room182, DOWN);
	room181->connectSpace(room196, RIGHT);
	room182->connectSpace(room183, DOWN);
	room183->connectSpace(room184, DOWN);
	room184->connectSpace(room185, DOWN);
	room185->connectSpace(room186, DOWN);
	room186->connectSpace(room187, DOWN);
	room187->connectSpace(room188, DOWN);
	room188->connectSpace(room189, LEFT);
	room189->connectSpace(room190, LEFT);

	room191->connectSpace(room192, RIGHT);
	room192->connectSpace(room193, RIGHT);
	room193->connectSpace(room194, RIGHT);
	room194->connectSpace(room195, RIGHT);

	room196->connectSpace(room197, RIGHT);
	room197->connectSpace(room198, RIGHT);
	room198->connectSpace(room199, RIGHT);
	room199->connectSpace(room200, RIGHT);
	room200->connectSpace(room201, RIGHT);
	room201->connectSpace(room202, UP);
	room201->connectSpace(room204, RIGHT);
	room202->connectSpace(room203, UP);

	room204->connectSpace(room205, RIGHT);
	room205->connectSpace(room206, RIGHT);
	room206->connectSpace(room207, DOWN);
	room207->connectSpace(room208, DOWN);

	room209->connectSpace(room210, RIGHT);
	room210->connectSpace(room211, RIGHT);
	room211->connectSpace(room212, RIGHT);
	room212->connectSpace(room213, RIGHT);

	room214->connectSpace(room215, RIGHT);
	room215->connectSpace(room216, RIGHT);
	room216->connectSpace(room217, DOWN);
	room217->connectSpace(room218, DOWN);

	room219->connectSpace(room220, DOWN);
	room220->connectSpace(room221, DOWN);
	room221->connectSpace(room222, DOWN);
}

