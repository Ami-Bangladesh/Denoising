#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include "opencv2/opencv.hpp"
#include<iostream>
#include<conio.h>           // may have to modify this line if not using Windows

using namespace std;
using namespace cv;

int main( int argc, char** argv )
{
// Read the source file
Mat src;
src = imread("Monalisa.jpg",IMREAD_COLOR);
// Add some noise
Mat noisy = src.clone();
Mat noise(src.size(), src.type());
randn(noise, 0, 50);
noisy += noise;
// Apply the denoising algorithm
Mat dst;
fastNlMeansDenoisingColored(noisy, dst,30,30,7,21);
// Show the results
namedWindow( " ORIGINAL ", WINDOW_AUTOSIZE );
imshow( " ORIGINAL ", src );
namedWindow( " ORIGINAL WITH NOISE ", WINDOW_AUTOSIZE );
imshow( " ORIGINAL WITH NOISE ", noisy );
namedWindow(" DENOISED ", WINDOW_AUTOSIZE );
imshow( " DENOISED ", dst );
waitKey();
return 0;
}