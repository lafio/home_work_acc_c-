#include <iostream>
using namespace std;

class Clock {
public:
	Clock(int newH, int newM, int newS);//���캯��
	Clock();//Ĭ�Ϲ��캯��
	void setTime(int newH = 0, int newM = 0, int newS = 0);
	void showTime();
private:
	int hour, minute, second;
};

Clock::Clock(int newH, int newM, int newS) :
	hour(newH), minute(newM), second(newS) {}
//Clock::Clock():hour(0),minute(0),second(0){}
Clock::Clock():Clock(0,0,0){}//ί�й��캯����Ч��ͬ��
void Clock::setTime(int newH, int newM, int newS) {
	hour = newH;
	minute = newM;
	second = newS;
}
void Clock::showTime() {
	cout << hour << ":" << minute << ":" << second<<endl;
}

int main() {
	Clock myclock1(8, 30, 30);
	Clock myclock2;
	myclock1.showTime();
	myclock2.showTime();
	return 0;
}