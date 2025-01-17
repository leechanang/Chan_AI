#include <opencv2/opencv.hpp>
using namespace cv;
using namespace std;
int main()
{
	Scalar orange(0, 165, 255), blue(255, 0, 0), magenta(255, 0, 255);
	Mat image(300, 500, CV_8UC3, Scalar(255, 255, 255)); //흰색 컬러 영상
	
	Point center = (Point)image.size() / 2; // 영상 중심좌표
	Point pt1(70, 50), pt2(350, 220);

	circle(image, center, 100, blue); //원그리기
	circle(image, pt1, 80, orange, 2); 
	circle(image, pt2, 60, magenta, -1); //원 내부 채움

	int font = FONT_HERSHEY_COMPLEX;
	putText(image, "center_blue", center, font, 1.2, blue);
	putText(image, "pt1_orange", pt1, font, 0.8, orange);
	putText(image, "pt2_magenta", pt2 + Point(2, 2), font, 0.5, Scalar(0,0,0), 2);
	putText(image, "pt2_magenta", pt2, font, 0.5, magenta, 1);

	imshow("원그리기", image);
	waitKeyEx(0);
	return 0;
}
