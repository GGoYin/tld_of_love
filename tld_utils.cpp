#include <math.h>
#include <opencv.hpp>
#include "tld_utils.h"
using namespace cv;
using namespace std;


void drawBox(Mat& image, CvRect box, Scalar color, int thick){
  rectangle( image, cvPoint(box.x, box.y), cvPoint(box.x+box.width,box.y+box.height),color, thick);
} 
//love function:17x^2-16|x|y+17y^2=225
void drawLove(Mat& image, CvRect box, Scalar color){
	//the center of the box,also,it is the translate vector from the origin.
	Point2f trans_vec(box.x + box.width/2.0,box.y + box.height/2.0);
	double scal_para = box.width / (BASE_HALF_WIDTH * 2);
	double step = (BASE_HALF_WIDTH * 2) / POINTS_NO;
	vector<Point2f> points;
	for(double x = -BASE_HALF_WIDTH;x < BASE_HALF_WIDTH;x += step){
		double fst_part = 8 * abs(x) / 17.0;
		double sec_part = sqrt(225/17.0-225/289.0*x*x); 
		points.push_back(Point2f(x*scal_para+trans_vec.x,(-fst_part-sec_part)*scal_para+trans_vec.y));
		points.push_back(Point2f(x*scal_para+trans_vec.x,(-fst_part+sec_part)*scal_para+trans_vec.y));
		drawPoints(image,points,color);
	}	
}
void drawPoints(Mat& image, vector<Point2f> points,Scalar color){
  for( vector<Point2f>::const_iterator i = points.begin(), ie = points.end(); i != ie; ++i )
      {
      Point center( cvRound(i->x ), cvRound(i->y));
      circle(image,*i,2,color,1);
      }
}

Mat createMask(const Mat& image, CvRect box){
  Mat mask = Mat::zeros(image.rows,image.cols,CV_8U);
  drawBox(mask,box,Scalar::all(255),CV_FILLED);
  return mask;
}

float median(vector<float> v)
{
    int n = floor(v.size() / 2.0f);
    nth_element(v.begin(), v.begin()+n, v.end());
    return v[n];
}

vector<int> index_shuffle(int begin,int end){
  vector<int> indexes(end-begin);
  for (int i=begin;i<end;i++){
    indexes[i]=i;
  }
  random_shuffle(indexes.begin(),indexes.end());
  return indexes;
}

