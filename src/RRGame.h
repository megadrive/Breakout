
#ifndef __RRGAME_H
#define __RRGAME_H

enum RR_RESULT;

class RRGame
{
public:
	RRGame();
	~RRGame();

	void Create();
	void Destroy();

	RR_RESULT Run();

private:
	bool m_bRunning;
};

#endif
