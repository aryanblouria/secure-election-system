#include<iostream>
#include<fstream>
#include<opencv.hpp>
#include<highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>

using namespace std;
using namespace cv;

bool issetbit(char ch, int pos)
    {
     ch = ch >> pos;
     if(ch & 1)
       {
        return true;
       }
     return false;
    }

int main()
    {
     string ipim,iptxt,opim;
     ipim = "D:/insta.png";
     iptxt = "D:/ElectionWin.txt";
     opim = "D:/ins.png";
       ifstream file(iptxt);
	   if(!file.is_open()) {
		cout << "File Error\n";
		exit(-1);
	    }
     Mat image = imread(ipim);
     if(image.empty())
        {
         cout<<"Image Error\n";
         exit(-1);
        }
     char ch;
     file.get(ch);
     int bit_count = 0;
     bool last_null_char = false;
     bool encoded = false;

     for(int row = 0; row < image.rows;row++)
        {
         for(int col = 0;col < image.cols;col++)
            {
             for(int clr = 0;clr < 3;clr++)
                {

                 Vec3b pixel = image.at<Vec3b>(Point(row,col));

                 if(issetbit(ch,7-bit_count))
                    pixel.val[clr] |= 1;
                 else
                    pixel.val[clr] &= ~1;

                 image.at<Vec3b>(Point(row,col)) = pixel;
                 bit_count++;

                 if(last_null_char && bit_count == 8)
                   {
                    encoded = true;
                    goto OUT;
                   }

                 if(bit_count == 8)
                   {
                    bit_count = 0;
                    file.get(ch);

                    if(file.eof())
                      {
                       last_null_char = true;
                       ch='\0';
                      }
                   }
                }
            }
        }

     OUT:;

     if(!encoded)
       {
        cout<<"Message is too big. try a larger image.";
        exit(-1);
       }

       imwrite(opim,image);
       return 0;
    }
