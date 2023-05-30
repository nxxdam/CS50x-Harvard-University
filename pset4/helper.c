#include "helpers.h"
#include <cs50.h>
#include <math.h>
// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    for (int j = 0; j < width; j++)
    {
        RGBTRIPLE pixel = image[i][j];
        int average = round((pixel.rgbtRed + pixel.rgbtGreen + pixel.rgbtBlue) / 3.0);
        image[i][j].rgbtRed = image[i][j].rgbtGreen = image[i][j]. rgbtBlue = average;
    }
}
int cap(int value)
{
     return value > 255 ? 255 : value;
}
// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    for (int j = 0; j < width; j++)
    {
         RGBTRIPLE pixel = image[i][j];
         int originalRed = pixel.rgbtRed;
         int originalBlue= pixel.rgbtBlue;
         int originalGreen = pixel.rgbtGreen;
         image[i][j].rgbtRed = cap (round(0.393 * originalRed + 0.769 * originalGreen + 0.189 * originalBlue));
         image [i][j].rgbtGreen = cap(round(0.349 * originalRed + 0.686 * originalGreen + 0.168 * originalBlue));
         image [i][j].rgbtBlue =cap(round (0.272 * originalRed + 0.534 * originalGreen + .131 * originalBlue));
    }

}

void swap(RGBTRIPLE *pixel_1, RGBTRIPLE *pixel_2)
{
    RGBTRIPLE temp = *pixel_1;
    *pixel_1 = *pixel_2;
    *pixel_2 = temp;
}
// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    for (int j = 0; j < width/2; j++)
    {
        swap(&image[i][j],&image[i][width-1-i]);
    }
}

bool is_valid_pixel(int i, int j, int height, int width)

{
    return i >= 0&& i<height && j >=0 && j < width;
}

RGBTRIPLE get_blurred_pixel(int i, int j, int height, int width, RGBTRIPLE image[height][width])
{
    int red_value, blue_value, green_value; red_value = blue_value = green_value = 0;
    int num_of_valid_pixel =0;
    for (int di = -1; di <= 1; di++)

    {
        for (int dj = -1; dj <= 1; dj++)
        {
            int new_i = i + di;
            int new_j = j + dj;
            if (is_valid_pixel(new_i, new_j, height, width))
            {
                num_of_valid_pixel++;
                red_value += image[new_i][new_j].rgbtRed;
                blue_value += image[new_i][new_j].rgbtBlue;
                green_value += image [new_i][new_j].rgbtGreen;
            }
        }
    }
    RGBTRIPLE blurred_pixel;
    blurred_pixel.rgbtRed = round((float)red_value / num_of_valid_pixel);
    blurred_pixel.rgbtGreen = round((float)green_value / num_of_valid_pixel);
    blurred_pixel.rgbtBlue = round((float)blue_value / num_of_valid_pixel);
    return blurred_pixel;

}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE image_new [height][width];
    for (int i = 0; i < height; i++)
    for (int j = 0; j < width; j++)
    {
        image_new[i][j] = get_blurred_pixel(i,j, height, width, image);
     }

    for (int i = 0; i < height; i++)
    for (int j = 0; j < width; j++)
        image[i][j] = image_new[i][j];
}
