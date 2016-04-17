/*
 * stoper.h
 */

#ifndef STOPER_H_
#define STOPER_H_
#include <sys/time.h>

class stoper {
public:
	stoper();
	virtual ~stoper();
	double getRunTime();
	void setRunTime();
	void sendToFile();
	double getStart();
	void setStart();
	double getStop();
	void setStop();

private:
	timeval time;
	double RunTime_;		//czas wykonania algorytmu
	double start_, stop_;
};

#endif /* STOPWATCH_H_ */
