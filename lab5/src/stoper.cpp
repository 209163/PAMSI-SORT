/*
 * Stopwatch.cpp
 *
 *  Created on: 13 mar 2016
 *      Author: paula
 */
#include <iostream>
#include <fstream>
#include <sys/time.h>
using namespace std;
#include "stoper.h"


/**
 * konstruktor
 */
stoper::stoper() {
	start_=0;
	stop_=0;
	RunTime_=0;
}
/**
 * destruktor
 */
stoper::~stoper() {
}
/**
 * funkcja zwracajaca czas wykonania
 * @return RunTime_
 */
double stoper::getRunTime()
{
	setRunTime();
	return RunTime_;
}
/**
 * funkcja obliczajaca czas wykonania algorytmu
 */
void stoper::setRunTime()
{
	RunTime_=float(stop_-start_);		//double czas_wyk1 = float(koniec-start)/CLOCKS_PER_SEC;
}
/**
 * funkcja zapisujaca pomiar w pliku
 * @param number - liczba elementow dla ktorych dzialal algorytm
 */
void stoper::sendToFile(int numb)
{
	FILE *pFile;
	pFile=fopen("dane.txt","a");		//otwiera plik do dopisywania (jesli nie istnieje, to go tworzy)
	fprintf (pFile, "%.8f sek\t %d\n", RunTime_ , numb);
	fclose(pFile);

}
/**
 * funkcja zwracajaca czas rozpoczecia pomiaru
 * @return start_
 */
double stoper::getStart()
{
	return start_;
}
/**
 * funkcja wlaczajaca stoper
 */
void stoper::setStart()
{
	gettimeofday(&time, NULL);
	start_=time.tv_sec+(time.tv_usec/1000000.0);;
}
/**
 * funkcja zwracajaca czas zakonczenia pomiaru
 * @return stop_
 */
double stoper::getStop()
{
	return stop_;
}
/**
 * funkcja wylaczajaca stoper
 */
void stoper::setStop()
{
	gettimeofday(&time, NULL);
	stop_=time.tv_sec+(time.tv_usec/1000000.0);
}

void stoper::displayRunTime(int numb)
{
	printf("%.8f sek\t %d\n", getRunTime(), numb);
}
