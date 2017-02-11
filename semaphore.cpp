#include "semaphore.h"

void Semaphore::wait()
{
	if (threadsInside < maxThreads)
	{
		threadsInside++;
		return;
	}
	else {
		cv.wait(lock, [=] {return threadsInside < maxThreads; });
		}
}

void Semaphore::signal()
{
	threadsInside--;
	lock.unlock;
	cv.notify_all();
}