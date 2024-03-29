#include "opencv2/opencv.hpp"
#include <iostream>
using namespace std;
using namespace cv;


int main()
{
	Mat src1, src2, dst;
	double gamma = 0.5;
	src1 = imread("C:/Users/Chan's Victus/Documents/class/Project/image/gamma1.jpg");
	if (src1.empty()) { cout << "영상을 읽을 수 없습니다." << endl; return -1; }

	Mat table(1, 256, CV_8U);
	uchar* p = table.ptr();
	for (int i = 0; i < 256; ++i)
		p[i] = saturate_cast <uchar> (pow(i / 255.0, gamma) * 255.0);

	LUT(src1, table, dst);
	imshow("src1", src1);
	imshow("dst", dst);
	waitKey(0);
	return 0;
}