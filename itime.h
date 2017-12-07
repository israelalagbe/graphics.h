
#include <ctime>
	class timer
{
	double t1, t2;
  public:

	double get()
	{
		t2 = (double)std::clock() / CLOCKS_PER_SEC * 1000;
		return (double)t2 - t1;
	}
	double clock()
	{
		return (double)std::clock() / CLOCKS_PER_SEC * 1000;
	}
	timer()
	{
		t1 = (double)std::clock() / CLOCKS_PER_SEC * 1000;
	}
	void start()
	{
		t1 = (double)std::clock() / CLOCKS_PER_SEC * 1000;
	}
	void pause(double len)
	{
		double temp = clock();
		while ((clock() - temp) < len);
	}


};