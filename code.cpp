/* Team Details:
Section: S1 with TA/ Hassan Mourad

Member 1:
Name: Omar Ahmed Mostafa Allam
ID: 20240362
Filter 1 Grayscaling
Filter 4 Merge two images
Filter 7 Darken and Lighten Image brightness
Filter 10 Detect Image Edges
Filter 13 Add sunlight (bonus)
Filter 16 purple (bonus)

Member 2:
Name: Karim Mohamed Ramadan
ID: 20240423
Filter 2 black and white
Filter 5 horizontal and vertical flip
Filter 8 Crop Image
Filter 11 Resize Image
Filter 14 Oil Painting (bonus)
Filter 17 Infrared (bonus)

Member 3:
Name: Youssef Aly El-Sayed
ID: 20242408
Filter 3 Inverted
Filter 6 Rotate
Filter 9 Add Frame
Filter 12 Blur
Filter 15 Old TV (bonus)
Filter 18 Skew (Bonus)
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
Image brightness(Image &img)
{
    Image output = img;
    cout << "please choose an option (make image brightness..):\n1- Darker by 50%\n2- lighter by 50%\n";
    int option;
    cin >> option;
    if (option == 1)
    {
        for (int i = 0; i < img.width; i++)
        {

            for (int j = 0; j < img.height; j++)
            {

                for (int k = 0; k < 3; k++)
                {
                    output(i, j, k) = img(i, j, k) * 0.5;
                }
            }
        }
    }

    if (option == 2)
    {
        int value;
        for (int i = 0; i < img.width; i++)
        {

            for (int j = 0; j < img.height; j++)
            {

                for (int k = 0; k < 3; k++)
                {
                    value = img(i, j, k) * 1.5;
                    if (value > 255)
                    {
                        value = 255;
                    }
                    output(i, j, k) = value;
                }
            }
        }
    }
    return output;
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
Image edge(Image &img)
{
    img = B_and_W(img);
    Image output = img;

    for (int i = 1; i < output.width - 1; i++)
    {

        for (int j = 1; j < output.height - 1; j++)
        {

            int value = img(i, j, 0);
            bool edge = false;

            if (img(i + 1, j, 0) != value)
            {
                edge = true;
            }
            else if (img(i - 1, j, 0) != value)
            {
                edge = true;
            }
            else if (img(i, j + 1, 0) != value)
            {
                edge = true;
            }
            else if (img(i, j - 1, 0) != value)
            {
                edge = true;
            }

            for (int k = 0; k < 3; k++)
            {
                if (edge)
                {
                    output(i, j, k) = 0;
                }
                else
                {
                    output(i, j, k) = 255;
                }
            }
        }
    }

    return output;
}
Image resize(Image &img)
{
    int choice;
    cout << "1-Choose a new Ratio\n2-Add new dimensions\n";
    cin >> choice;
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    Image final;
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
        final = output;
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
        final = output;
    }
    return final;
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
Image sunlight(Image &img){
    Image output = img ;
    for (int i=0 ; i<img.width ; i++){

        for (int j=0 ; j<img.height ; j++){
            float red = img(i,j,0)*1.15 + 10 ;
            float green = img(i,j,1)*1.08 + 6 ;
            float blue = img(i,j,2)*0.88 + 10 ;

            if(red>255){red=255 ;}
            if(green>255){green=255 ;}
            if(blue>255){blue=255 ;}

            output(i,j,0) = red ;
            output(i,j,1) = green ;
            output(i,j,2) = blue ;
        }
    }
    return output ;
}
Image oil(Image &img)
{
    Image output = img;
    int radius = 2;
    for (int i = 0; i < img.width; i++)
    {
        for (int j = 0; j < img.height; j++)
        {
            int rSum[16] = {0};
            int gSum[16] = {0};
            int bSum[16] = {0};
            int count[16] = {0};

            for (int x = -radius; x <= radius; x++)
            {
                for (int y = -radius; y <= radius; y++)
                {
                    int nx = i + x;
                    int ny = j + y;

                    if (nx >= 0 && nx < img.width && ny >= 0 && ny < img.height)
                    {
                        int average = (img(nx, ny, 0) + img(nx, ny, 1) + img(nx, ny, 2)) / 3;
                        int bin = average * 16 / 256;
                        rSum[bin] += img(nx, ny, 0);
                        gSum[bin] += img(nx, ny, 1);
                        bSum[bin] += img(nx, ny, 2);
                        count[bin]++;
                    }
                }
            }
            int maxBin = 0;
            for (int z = 1; z < 16; z++)
            {
                if (count[z] > count[maxBin])
                    maxBin = z;
            }
            output(i, j, 0) = rSum[maxBin] / count[maxBin];
            output(i, j, 1) = gSum[maxBin] / count[maxBin];
            output(i, j, 2) = bSum[maxBin] / count[maxBin];
        }
    }

    return output;
}
Image oldTV(Image &img, int noiseLevel, int scanlineIntensity, int distortionLevel)
{
    srand(time(0));

    for (int i = 0; i < img.width; i++)
    {
        for (int j = 0; j < img.height; j++)
        {
            for (int k = 0; k < 3; k++)
            {
                int noise = (rand() % (2 * noiseLevel + 1)) - noiseLevel;
                int value = img(i, j, k) + noise;
                img(i, j, k) = max(0, min(255, value));
            }
        }
    }

    for (int y = 0; y < img.height; y++)
    {
        if (y % 2 == 0)
        {
            for (int x = 0; x < img.width; x++)
            {
                for (int k = 0; k < 3; k++)
                {
                    int value = img(x, y, k) - scanlineIntensity;
                    img(x, y, k) = max(0, value);
                }
            }
        }
    }

    srand(time(0) + 1);
    for (int i = 0; i < img.width; i++)
    {
        for (int j = 0; j < img.height; j++)
        {
            for (int k = 0; k < 3; k++)
            {
                int shift = (rand() % (2 * distortionLevel + 1)) - distortionLevel;
                int value = img(i, j, k) + shift;
                img(i, j, k) = max(0, min(255, value));
            }
        }
    }

    return img;
}
Image IR(Image &img)
{
    Image output = img;
    for (int i = 0; i < img.width; i++)
    {
        for (int j = 0; j < img.height; j++)
        {
            float average = (img(i, j, 0) + img(i, j, 1) + img(i, j, 2)) / 3;
            float percent = average / 255;

            output(i, j, 0) = 255;
            output(i, j, 1) = 255 * (1 - percent);
            output(i, j, 2) = 255 * (1 - percent);
        }
    }

    return output;
}
Image purple(Image &img){
    Image output = img ;
    for (int i=0 ; i<img.width ; i++){

        for (int j=0 ; j<img.height ; j++){

            float red = img(i,j,0)*1.1 + 4.8 ;
            float green = img(i,j,1)*0.81 -2.2 ;
            float blue = img(i,j,2)*1.18 + 3.7 ;

            if(red>255){red=255 ;}
            if(green>255){green=255 ;}
            if(blue>255){blue=255 ;}

            output(i,j,0) = red ;
            output(i,j,1) = green ;
            output(i,j,2) = blue ;
        }
    }
    return output ;
}
Image Skew(Image &img, float angle)
{
    float radians = angle * M_PI / 180.0;
    int shift = (img.height * tan(radians));

    Image skewed(img.width + abs(shift), img.height);

    for (int i = 0; i < skewed.width; i++)
    {
        for (int j = 0; j < skewed.height; j++)
        {
            skewed(i, j, 0) = 255;
            skewed(i, j, 1) = 255;
            skewed(i, j, 2) = 255;
        }
    }

    for (int y = 0; y < img.height; y++)
    {

        int offset = ((img.height - y - 1) * tan(radians));

        for (int x = 0; x < img.width; x++)
        {
            int newX = x + offset;

            if (newX >= 0 && newX < skewed.width)
            {
                for (int c = 0; c < 3; c++)
                {
                    skewed(newX, y, c) = img(x, y, c);
                }
            }
        }
    }

    return skewed;
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
    string menu_str = "0 - Load Image\n"
                      "1 - Filter 1  //Grayscaling\n"
                      "2 - Filter 2  //Black & White\n"
                      "3 - Filter 3  //Invert\n"
                      "4 - Filter 4  //Merge two images\n"
                      "5 - Filter 5  //Flip\n"
                      "6 - Filter 6  //Rotate Clockwise\n"
                      "7 - Filter 7  //Darken or Lighten Image brightness\n"
                      "8 - Filter 8  //Crop\n"
                      "9 - Filter 9  //Add Frame\n"
                      "10- Filter 10 //Detect Image Edges\n"
                      "11- Filter 11 //Resize\n"
                      "12- Filter 12 //Blur\n"
                      "13- Filter 13 //Add sunlight\n"
                      "14- Filter 14 //Oil Painting\n"
                      "15- Filter 15 //old tv\n"
                      "15- Filter 16 //purple\n"
                      "17- Filter 17 //Infrared\n"
                      "18- Filter 18 //Skew\n"
                      "19- Save The Image\n"
                      "20- Exit\n";

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
            img = brightness(img);
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
        else if (choice == 10)
        {
            img = edge(img);
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
        else if (choice == 13)
        {
            img = sunlight(img);
        }
        else if (choice == 14)
        {
            img = oil(img);
        }
        else if (choice == 15)
        {
            img = oldTV(img, 30, 40, 20);
        }
        else if (choice == 16)
        {
            img = purple(img);
        }
        else if (choice == 17)
        {
            img = IR(img);
        }
        else if (choice == 18)
        {
            img = Skew(img, 45);
        }
        else if (choice == 19)
        {
            save(img);
            saved_flag = true;
        }
        else if (choice == 20)
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
            cout << "Please choose a valid option from the list." << endl;
        }
    } while (exit_flag == false);
}

int main()
{
    menu();
    return 0;
}