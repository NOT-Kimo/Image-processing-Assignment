#include "Image_Class.h"
#include <iostream>
#include <string>

using namespace std;

Image B_and_W(const Image &img, string &OutputName)
{

    Image output = img;
    for (int i = 0; i < img.width; i++)
    {

        for (int j = 0; j < img.height; j++)
        {
            int value = (img(i, j, 0) + img(i, j, 1) + img(i, j, 2)) / 3;
            int bw;
            if (value >= 128)
                bw = 255;
            else
                bw = 0;

            for (int k = 0; k < 3; k++)
            {
                output(i, j, k) = bw;
            }
        }
    }
    output.saveImage("Results/" + OutputName);
    return output;
}
Image flip(Image &img, string &OutputName)
{

    Image output = img;
    for (int i = 0; i < img.width; i++)
    {

        for (int j = 0; j < img.height; j++)
        {
            for (int k = 0; k < 3; k++)
            {
                output(i, j, k) = img((img.width - i), j, k);
            }
        }
    }
    output.saveImage("Results/" + OutputName);
    return output;
}
void menu()
{
    cout << "Please enter the Imagename.extension\n";
    string ImageName;
    getline(cin, ImageName);

    Image img(ImageName);
    int choice;
    cout << "1- ....... \n2-black and white\n3-Invert filter\n5-Horizontal Flip\n";
    cin >> choice;
    cin.ignore();
    if (choice == 2)
    {
        string OutputName;
        cout << "Please enter the NewImageName.extension\n";
        getline(cin, OutputName);
        cout << "\n";
        B_and_W(img, OutputName);
    }
    else if (choice == 5)
    {
        string OutputName;
        cout << "Please enter the NewImageName.extension\n";
        getline(cin, OutputName);
        cout << "\n";
        flip(img, OutputName);
    }
}

int main()
{

    menu();
    return 0;
}