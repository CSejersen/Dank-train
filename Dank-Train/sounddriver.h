/*
 * Created: 24-05-2023 12:37:00
 *  Author: Thomas Bové
 */ 

#pragma once

class SoundDriver {
private: 
	unsigned char START, FEEDBACK, END, CMD, PARA1, PARA2, CHECKSUM1, CHECKSUM2;
	unsigned int CHECKSUM;
	void send();
	void checksum();

public:
	void play(unsigned char);
	void volume(unsigned char);
	
	
    SoundDriver();

};
