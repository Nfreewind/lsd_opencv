/*----------------------------------------------------------------------------*/
/** @file lsd_opencv.h
    LSD OpenCV module header
    @author dani
 */
/*----------------------------------------------------------------------------*/

#ifndef LSD_OPENCV_H_
#define LSD_OPENCV_H_

#include <opencv2/core/core.hpp>

typedef struct lineSegment_s
{
    cv::Point2f begin;
    cv::Point2f end;
    double width;
    double p;
    double NFA;
} lineSegment;


class LSD
{
public:
    void flsd(const cv::Mat& image, const double& scale, std::vector<cv::Point2f>& begin, std::vector<cv::Point2f>& end, 
        std::vector<double>& width, std::vector<double>& prec, std::vector<double>& nfa, cv::Rect roi = cv::Rect());
    void flsd(const cv::Mat& image, const double& scale, std::vector<lineSegment>& lines, cv::Rect roi = cv::Rect());

private:
    void ll_angle(const cv::Mat& in, const double& threshold, cv::Mat& angles);

};

#endif /* !LSD_OPENCV_H_ */
/*----------------------------------------------------------------------------*/