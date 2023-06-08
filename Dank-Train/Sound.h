/*
 * Created: 24-05-2023 12:37:00
 *  Author: Thomas Bov�
 */ 

#pragma once

class Sound {
	private: 
	unsigned char START, FEEDBACK, END, CMD, PARA1, PARA2, CHECKSUM1, CHECKSUM2;
	unsigned int CHECKSUM;
	void send();
	void checksum();
	public:
	void play(unsigned char);
	void pause();
	void volume(unsigned char);
	
	
    Sound();

};
