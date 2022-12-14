#include <Time.h>

using namespace std;
class Timer {


public:
	Timer() { reset(); }
	void start() { begin = clock(); }
	void finish() { end = clock(); }

	void reset() {
		begin = 0;
		end = 0;
	}

	double getElapsedTimeMs() {
		double e = ((double)(end - begin)) / CLOCKS_PER_SEC;
		return e * 1000;
	}

private:
	clock_t begin, end;
};