#pragma once

enum Mood
{
	Excelent, Good, Bad
};

class Lecturer
{
private:
	Mood mood;
	
public:
	void setMood(Mood inner_mood);
	Mood getMood();
	Lecturer();
	~Lecturer();
};

