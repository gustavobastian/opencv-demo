#include <opencv4/opencv2/imgcodecs.hpp>
#include <opencv4/opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>
using namespace cv;
//simple example from opencv page

int main()
{
    /*
    std::string image_path = samples::findFile("../resources/brasil.png");
    Mat img = imread(image_path, IMREAD_COLOR);
    if(img.empty())
    {
        std::cout << "Could not read the image: " << image_path << std::endl;
        return 1;
    }
    imshow("Display window", img);
    int k = waitKey(0); // Wait for a keystroke in the window
    if(k == 's')
    {
        std::cout << "saving"<<"\n";
        imwrite("../resources/brasil.png", img);
    }*/

    std::string image_path = samples::findFile("../resources/german.jpg");
    std::string window_gray = "gray_image";
    std::string window_common = "common_image";
    std::string window_median = "median_image";
    std::string window_edges = "edges_image";

    Mat img = imread(image_path, IMREAD_COLOR);//original
    Mat img2;//gray_image
    Mat img3;//median blur_image
    Mat img3b;
    Mat img4;//edges image

     // let's downscale the image using new  width and height
    int down_width = 174*2;
    int down_height = 158*2;
    Mat resized_down;
    Mat resized_down2;
    Mat resized_down3;
    Mat resized_down4;
     
    
    if(img.empty())
    {
        std::cout << "Could not read the image: " << image_path << std::endl;
        return 1;
    }
    
    

    cvtColor(img,img2,cv::COLOR_BGR2GRAY);

    medianBlur(img,img3,15);

    


    //adaptiveThreshold(img3,img4,126,ADAPTIVE_THRESH_MEAN_C,THRESH_BINARY,10,10);
    bilateralFilter(img3,img4,15,75,75);

    resize(img, resized_down, Size(down_width, down_height), INTER_LINEAR);
    resize(img2, resized_down2, Size(down_width, down_height), INTER_LINEAR);
    resize(img3, resized_down3, Size(down_width, down_height), INTER_LINEAR);
    resize(img4, resized_down4, Size(down_width, down_height), INTER_LINEAR);
    

    cv::namedWindow(window_common,cv::WINDOW_AUTOSIZE);
    cv::namedWindow(window_gray,cv::WINDOW_AUTOSIZE);
    cv::namedWindow(window_median,cv::WINDOW_AUTOSIZE);
    cv::namedWindow( window_edges,cv::WINDOW_AUTOSIZE);

    
    imshow(window_common, resized_down);
    imshow(window_gray, resized_down2);
    imshow(window_median, resized_down3);
    imshow(window_edges, resized_down4);
    int k = waitKey(0); // Wait for a keystroke in the window

    return 0;
}