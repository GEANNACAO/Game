#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/opencv.hpp>
using namespace cv;

#define WINDOW_NAME "»æÖÆÍ¼"
#define WINDOW_WIDTH 600

Mat tempImage;
Mat rookImage = Mat::zeros(WINDOW_WIDTH, WINDOW_WIDTH, CV_8UC3);

void inCircle(Mat img, Point center);
void on_MouseHandle(int event, int x, int y, int flags, void* param);
void DrawLine(Mat img, Point start, Point end);
int main(int argc, char** argv)
{
	rookImage = Scalar::all(255);
	rectangle(rookImage,
		Point(3 * WINDOW_WIDTH / 9, 6 * WINDOW_WIDTH / 9),
		Point(6 * WINDOW_WIDTH / 9, 3 * WINDOW_WIDTH / 9),
		Scalar(0,255, 255),
		-1,
		8);
	DrawLine(rookImage, Point(4 * WINDOW_WIDTH / 9, 6 * WINDOW_WIDTH / 9), Point(4 * WINDOW_WIDTH / 9, 3 * WINDOW_WIDTH / 9));
	DrawLine(rookImage, Point(5 * WINDOW_WIDTH / 9, 6 * WINDOW_WIDTH / 9), Point(5 * WINDOW_WIDTH / 9, 3 * WINDOW_WIDTH / 9));
	DrawLine(rookImage, Point(6 * WINDOW_WIDTH / 9, 4 * WINDOW_WIDTH / 9), Point(3 * WINDOW_WIDTH / 9, 4 * WINDOW_WIDTH / 9));
	DrawLine(rookImage, Point(6 * WINDOW_WIDTH / 9, 5 * WINDOW_WIDTH / 9), Point(3 * WINDOW_WIDTH / 9, 5 * WINDOW_WIDTH / 9));
	moveWindow(WINDOW_NAME, WINDOW_WIDTH, 200);
	rookImage.copyTo(tempImage);
	namedWindow(WINDOW_NAME);
	setMouseCallback(WINDOW_NAME, on_MouseHandle, (void*)&rookImage);
	imshow(WINDOW_NAME,tempImage);
	waitKey(0);
	return (0);
}

void DrawLine(Mat img, Point start, Point end)
{
	int thickness = 2;
	int linetype = 8;
	line(img, start, end, Scalar(255, 255, 255), thickness, linetype);
}

void on_MouseHandle(int event, int x, int y,int flags, void* param)
{
	Mat&image = *(cv::Mat*)param;
	switch (event)
	{
	case EVENT_MOUSEMOVE:
	{}break;
	case CV_EVENT_LBUTTONDOWN:
	{rookImage.copyTo(tempImage);
	if (x >= 3 * WINDOW_WIDTH / 9 && x <= 4 * WINDOW_WIDTH / 9 && y >= 3 * WINDOW_WIDTH / 9 && y <= 4 * WINDOW_WIDTH / 9)
	{inCircle(tempImage, Point(7 * WINDOW_WIDTH / 18, 7 * WINDOW_WIDTH / 18)); }
	if (x >= 3 * WINDOW_WIDTH / 9 && x <= 4 * WINDOW_WIDTH / 9 && y >= 4 * WINDOW_WIDTH / 9 && y <= 5 * WINDOW_WIDTH / 9)
	{inCircle(tempImage, Point(7 * WINDOW_WIDTH / 18, 9 * WINDOW_WIDTH / 18));	}
	if (x >= 3 * WINDOW_WIDTH / 9 && x <= 4 * WINDOW_WIDTH / 9 && y >= 5 * WINDOW_WIDTH / 9 && y <= 6 * WINDOW_WIDTH / 9)
	{inCircle(tempImage, Point(7 * WINDOW_WIDTH / 18, 11 * WINDOW_WIDTH / 18));}
	if (x >= 4 * WINDOW_WIDTH / 9 && x <= 5 * WINDOW_WIDTH / 9 && y >= 3 * WINDOW_WIDTH / 9 && y <= 4 * WINDOW_WIDTH / 9)
	{inCircle(tempImage, Point(9 * WINDOW_WIDTH / 18, 7 * WINDOW_WIDTH / 18));}
	if (x >= 4 * WINDOW_WIDTH / 9 && x <= 5 * WINDOW_WIDTH / 9 && y >= 4 * WINDOW_WIDTH / 9 && y <= 5 * WINDOW_WIDTH / 9)
	{inCircle(tempImage, Point(9 * WINDOW_WIDTH / 18, 9 * WINDOW_WIDTH / 18));}
	if (x >= 4 * WINDOW_WIDTH / 9 && x <= 5 * WINDOW_WIDTH / 9 && y >= 5 * WINDOW_WIDTH / 9 && y <= 6 * WINDOW_WIDTH / 9)
	{inCircle(tempImage, Point(9 * WINDOW_WIDTH / 18, 11 * WINDOW_WIDTH / 18));	}
	if (x >= 5 * WINDOW_WIDTH / 9 && x <= 6 * WINDOW_WIDTH / 9 && y >= 3 * WINDOW_WIDTH / 9 && y <= 4 * WINDOW_WIDTH / 9)
	{inCircle(tempImage, Point(11 * WINDOW_WIDTH / 18, 7 * WINDOW_WIDTH / 18));	}
	if (x >= 5 * WINDOW_WIDTH / 9 && x <= 6 * WINDOW_WIDTH / 9 && y >= 5 * WINDOW_WIDTH / 9 && y <= 6 * WINDOW_WIDTH / 9)
	{inCircle(tempImage, Point(11 * WINDOW_WIDTH / 18, 11 * WINDOW_WIDTH / 18));}	
	if (x >= 5 * WINDOW_WIDTH / 9 && x <= 6 * WINDOW_WIDTH / 9 && y >= 4 * WINDOW_WIDTH / 9 && y <= 5 * WINDOW_WIDTH / 9)
	{inCircle(tempImage, Point(11 * WINDOW_WIDTH / 18, 9 * WINDOW_WIDTH / 18));	}
	imshow(WINDOW_NAME, tempImage); 
	}break;
	case CV_EVENT_LBUTTONUP:
	{}break;
	}
}

void inCircle(Mat img, Point center)
{
	int thickness = -1;
	int lineType = 8;
	circle(img, center, WINDOW_WIDTH / 300, Scalar(0, 0, 0), thickness, lineType);
}

