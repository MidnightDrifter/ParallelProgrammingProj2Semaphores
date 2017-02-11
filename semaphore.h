#include <atomic>
#include <thread>
#include <mutex>
#include <condition_variable>
class Semaphore
{
public:



	Semaphore(int m) : maxThreads(m), cv(), threadsInside(0), lock() {}

	int getMaxThreads() const { return maxThreads; }


	void wait();
	void signal();
private:

	const int maxThreads;
	std::atomic<int> threadsInside;
	std::condition_variable cv;
	std::unique_lock<std::mutex> lock;
};
