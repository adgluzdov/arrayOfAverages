#include"MassAverage.h"
#include <queue>;

using namespace std;

int* sred(int*a, int k, int n) {

		if( (k > 0)&& (k <= n) && (a != 0) && (n > 0) )
		{
			queue<int> queue_;
			int *res = new int[n - k + 1];
			int sum, old;
			sum = 0;
			old = 0;
			for (int i=0;i<k;i++)
				queue_.push(a[i]);
			for (int i = 0; i < n - k + 1; i++)
			{
				for (int j = 0; j < k; j++)
				{
					sum += queue_.front(); 
					old = queue_.front();
					queue_.push(old);
					queue_.pop();
				}
				queue_.push(a[i + k]);
				queue_.pop();
				res[i] = sum / k;
				sum = 0;
			}
			return res;
		}
		else throw 1;
}