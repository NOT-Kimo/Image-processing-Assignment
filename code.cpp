/* Team Details:
Section: Not Registered yet but attended in S7/S8 with TA/ Marwa Ahmed

Member 1:
Name: Omar Ahmed Mostafa Allam
ID: 20240362
Filter 1 Graysacling
Filter 4 Merge two images

Member 2:
Name: Karim Mohamed Ramadan
ID: 20240423
Filter 2 black and white
Filter 5 horizontal and vertical flip

Member 3:
Name: Youssef Aly El-Sayed
ID: 20242408
Filter 3 Inverted
Filter 4 Rotate
_________________________________________________________________________________

File Detials:
-> The .cpp file contains all the required details that was mentioned in the assignment pdf

-> Note that: some filters require more than 1 option like Filter 5 (Flip) and Filter 6 (Rotate) each option
has its own function while Filter 4 (Merge) options are in the same function

*/

#include "Image_Class.h"
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

string CurrentName;

Image load_image()
{
    Image inp;
    string ImageName;
    cout << "Please enter the Imagename.extension ex: (.png , .bmp , .jpg , .jpeg , .tga )" << '\n';

    while (true)
    {
        getline(cin, ImageName);
        try
        {
            if (inp.loadNewImage(ImageName))
            {
                cout << "Image loaded successfully!" << endl;
                CurrentName = ImageName;
                break;
            }
        }
        catch (const invalid_argument &e)
        {
            cout << "Please check the filename or extension and try again." << '\n';
        }
    }
    return inp;
}
Image Grayscaling(Image &img)
{

    Image output = img;
    for (int i = 0; i < img.width; i++)
    {

        for (int j = 0; j < img.height; j++)
        {

            int average = (img(i, j, 0) + img(i, j, 1) + img(i, j, 2)) / 3;

            for (int k = 0; k < 3; k++)
            {
                output(i, j, k) = average;
            }
        }
    }
    return output;
}
Image B_and_W(Image &img)
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
    return output;
}
Image InvertedImg(Image &img)
{

    Image output = img;
    for (int i = 0; i < img.width; i++)
    {

        for (int j = 0; j < img.height; j++)
        {

            for (int k = 0; k < 3; k++)
            {
                output(i, j, k) = 255 - img(i, j, k);
            }
        }
    }

    return output;
}
Image merge(Image &img1)
{
    Image img2;
    cout << "For 2nd image :";
    img2 = load_image();

    int w1 = img1.width, h1 = img1.height;
    int w2 = img2.width, h2 = img2.height;

    if (w1 == w2 && h1 == h2)
    {
        Image output(w1, h1);
        for (int i = 0; i < w1; i++)
        {
            for (int j = 0; j < h1; j++)
            {
                for (int k = 0; k < 3; k++)
                {
                    output(i, j, k) = (img1(i, j, k) + img2(i, j, k)) / 2;
                }
            }
        }
        return output;
    }

    else
    {
        cout << "choose an option \n1-Biggest area \n2-Common area" << endl;
        int op;
        cin >> op;

        if (op == 1)
        {
            int w = max(w1, w2);
            int h = max(h1, h2);
            Image output(w, h);
            for (int i = 0; i < w; i++)
            {
                for (int j = 0; j < h; j++)
                {
                    for (int k = 0; k < 3; k++)
                    {
                        output(i, j, k) = 0;
                    }
                }
            }
            for (int i = 0; i < w1; i++)
            {
                for (int j = 0; j < h1; j++)
                {
                    for (int k = 0; k < 3; k++)
                    {
                        output(i, j, k) = img1(i, j, k);
                    }
                }
            }
            for (int i = 0; i < w2; i++)
            {
                for (int j = 0; j < h2; j++)
                {
                    for (int k = 0; k < 3; k++)
                    {
                        output(i, j, k) = (output(i, j, k) + img2(i, j, k)) / 2;
                    }
                }
            }
            return output;
        }

        else if (op == 2)
        {
            int w = min(w1, w2);
            int h = min(h1, h2);
            Image output(w, h);
            for (int i = 0; i < w; i++)
            {
                for (int j = 0; j < h; j++)
                {
                    for (int k = 0; k < 3; k++)
                    {
                        output(i, j, k) = (img1(i, j, k) + img2(i, j, k)) / 2;
                    }
                }
            }
            return output;
        }

        else
        {
            cout << "please choose an option from the list";
            return img1;
        }
    }
}
Image Hflip(Image &img)
{

    Image output = img;
    for (int i = 0; i < img.width; i++)
    {

        for (int j = 0; j < img.height; j++)
        {
            for (int k = 0; k < 3; k++)
            {
                output(i, j, k) = img((img.width - i - 1), j, k);
            }
        }
    }
    return output;
}
Image Vflip(Image &img)
{

    Image output = img;
    for (int i = 0; i < img.width; i++)
    {

        for (int j = 0; j < img.height; j++)
        {
            for (int k = 0; k < 3; k++)
            {
                output(i, j, k) = img(i, img.height - j - 1, k);
            }
        }
    }
    return output;
}
Image Rotate90Clockwise(Image img)
{

    Image Rotated(img.height, img.width);

    for (int i = 0; i < img.width; i++)
    {

        for (int j = 0; j < img.height; j++)
        {

            for (int k = 0; k < 3; k++)
            {
                Rotated(img.height - 1 - j, i, k) = img(i, j, k);
            }
        }
    }
    return Rotated;
}
Image Rotate180(Image img)
{

    Image output = img;

    for (int i = 0; i < img.width; i++)
    {

        for (int j = 0; j < img.height; j++)
        {

            for (int k = 0; k < 3; k++)
            {
                output(img.width - 1 - i, img.height - 1 - j, k) = img(i, j, k);
            }
        }
    }
    return output;
}
Image Rotate270(Image img)
{

    Image Rotated(img.height, img.width);

    for (int i = 0; i < img.width; i++)
    {

        for (int j = 0; j < img.height; j++)
        {

            for (int k = 0; k < 3; k++)
            {

                Rotated(j, img.width - 1 - i, k) = img(i, j, k);
            }
        }
    }
    return Rotated;
}
Image crop(Image &img, int x, int y, int w, int h)
{
    Image output(w, h);
    for (int i = 0; i < w; i++)
    {

        for (int j = 0; j < h; j++)
        {

            for (int k = 0; k < 3; k++)
            {
                output(i, j, k) = img(i + x, j + y, k);
            }
        }
    }
    return output;
}

Image Frame(Image img, int thickness, unsigned char R, unsigned char G, unsigned char B)
{
    Image Framed(img.width + 2 * thickness, img.height + 2 * thickness);

    for (int i = 0; i < Framed.width; i++)
    {
        for (int j = 0; j < Framed.height; j++)
        {
            Framed(i, j, 0) = R;
            Framed(i, j, 1) = G;
            Framed(i, j, 2) = B;
        }
    }

    for (int i = 0; i < img.width; i++)
    {
        for (int j = 0; j < img.height; j++)
        {
            for (int k = 0; k < 3; k++)
            {
                Framed(i + thickness, j + thickness, k) = img(i, j, k);
            }
        }
    }
    return Framed;
}

Image Blur(Image &img, float radius)
{
    Image blurred = img;

    for (int i = 0; i < img.width; i++)
    {
        for (int j = 0; j < img.height; j++)
        {
            int rSum = 0, gSum = 0, bSum = 0;
            int count = 0;

            for (int x = -radius; x <= radius; x++)
            {
                for (int y = -radius; y <= radius; y++)
                {
                    int nx = i + x;
                    int ny = j + y;

                    if (nx >= 0 && nx < img.width && ny >= 0 && ny < img.height)
                    {
                        rSum += img(nx, ny, 0);
                        gSum += img(nx, ny, 1);
                        bSum += img(nx, ny, 2);
                        count++;
                    }
                }
            }

            blurred(i, j, 0) = rSum / count;
            blurred(i, j, 1) = gSum / count;
            blurred(i, j, 2) = bSum / count;
        }
    }

    return blurred;
}
Image resize(Image &img)
{
    int choice;
    cout << "1- Choose a new Ratio\n2-Add new dimensions\n";
    cin >> choice;
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    if (choice == 1)
    {
        double ratio;
        cout << "Enter resize ratio (0.5 = half, 2.0 = double , etc..)\n";
        cin >> ratio;
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        int w = (int)(img.width * ratio);
        int h = (int)(img.height * ratio);

        Image output(w, h);

        double wr = (double)img.width / w;
        double hr = (double)img.height / h;
        for (int i = 0; i < w; i++)
        {
            for (int j = 0; j < h; j++)
            {
                for (int k = 0; k < 3; k++)
                {
                    output(i, j, k) = img(round(i * wr), round(j * hr), k);
                }
            }
        }
        return output;
    }
    else if (choice == 2)
    {
        int w, h;
        cout << "Enter new dimensions.\n";
        cin >> w >> h;
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        Image output(w, h);
        double wr, hr;
        hr = (double)img.height / h;
        wr = (double)img.width / w;
        for (int i = 0; i < w; i++)
        {
            for (int j = 0; j < h; j++)
            {
                for (int k = 0; k < 3; k++)
                {
                    output(i, j, k) = img(round(i * wr), round(j * hr), k);
                }
            }
        }
        return output;
    }
}
void save(Image &output)
{
    cout << "1- overwrite the existing image ?\n2- Save new image\n";
    int x;
    cin >> x;
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    if (x == 1)
    {
        output.saveImage(CurrentName);
    }
    if (x == 2)
    {
        string OutputName;
        cout << "Please enter the NewImageName.extension\n";

        while (true)
        {
            getline(cin, OutputName);
            try
            {
                if (output.saveImage(OutputName))
                    cout << "Image Saved Successfully!.\n";
                break;
            }
            catch (const invalid_argument &e)
            {
                cout << "Failed to Save The Image.\nPlease check the filename or extension and try again." << '\n';
            }
        }
    }
}
void menu()
{
    Image img;
    img = load_image();
    int choice;
    bool exit_flag = false;
    bool img_loaded = false;
    bool saved_flag = false;
    string menu_str = "0- Load Image\n"
                      "1- Filter 1 //Grayscaling\n"
                      "2- Filter 2 //Black & White\n"
                      "3- Filter 3 //Invert\n"
                      "4- Filter 4 //Merge two images\n"
                      "5- Filter 5 //Flip\n"
                      "6- Filter 6 //Rotate Clockwise\n"
                      "8- Filter 8 //Crop\n"
                      "9- Filter 9 //Add Frame\n"
                      "11-Filter 11//Resize\n"
                      "12-Filter 12 //Blur\n"
                      "7- Save the image\n"
                      "99- Exit\n";

    do
    {
        cout << menu_str;
        cin >> choice;
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        if (choice == 0)
        {
            if (saved_flag == false)
            {
                cout << "Do you want to save current changes?\n1-Yes\n2-No\n";
                cin >> choice;
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                if (choice == 1)
                    save(img);
            }
            img = load_image();
            img_loaded = true;
            saved_flag = false;
        }

        else if (choice == 1)
        {
            img = Grayscaling(img);
        }

        else if (choice == 2)
        {
            img = B_and_W(img);
        }

        else if (choice == 3)
        {
            img = InvertedImg(img);
        }

        else if (choice == 4)
        {
            img = merge(img);
        }

        else if (choice == 5)
        {
            cout << "1-Horizontal flip\n2-Vertical Flip\n";
            cin >> choice;
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            if (choice == 1)
                img = Hflip(img);
            else if (choice == 2)
                img = Vflip(img);
        }

        else if (choice == 6)
        {
            cout << "1- 90 \n2- 180 \n3- 270\n";
            int x;
            cin >> x;
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            if (x == 1)
            {
                img = Rotate90Clockwise(img);
            }
            else if (x == 2)
            {
                img = Rotate180(img);
            }
            else if (x == 3)
            {
                img = Rotate270(img);
            }
        }

        else if (choice == 7)
        {
            save(img);
            saved_flag = true;
        }
        else if (choice == 8)
        {
            cout << "Enter x and y of starting point\n";
            int x, y;
            cin >> x >> y;
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout << "Enter the new dimentions of the image with spaces between them.\n";
            int w, h;
            cin >> w >> h;
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            img = crop(img, x, y, w, h);
        }
        else if (choice == 9)
        {
            int thick;
            cout << "please enter required thickness\n ";
            cin >> thick;
            cout << "Please enter R G B values (0 <= R,G,B <= 255)\n";
            int r, g, b;
            cin >> r >> g >> b;
            img = Frame(img, thick, r, g, b);
        }
        else if (choice == 11)
        {
            img = resize(img);
        }
        else if (choice == 12)
        {
            float r;
            cout << "Please enter blur level from 1 to 100\n";
            cin >> r;
            r = r / 10;
            img = Blur(img, r);
        }

        else if (choice == 99)
        {
            if (saved_flag == false)
            {
                cout << "Do you want to save current changes?\n1-Yes\n2-No\n";
                cin >> choice;
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                if (choice == 1)
                    save(img);
            }
            exit_flag = true;
        }
        else
        {
            cout << "please choose an option from the list" << endl;
        }
    } while (exit_flag == false);
}

int main()
{
    menu();
    return 0;
}