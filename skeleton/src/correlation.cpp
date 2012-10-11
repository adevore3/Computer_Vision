#include "correlation.h"

/************************ TO BE DONE 2 **************************/
/*
 *	INPUT: 
 *		origImg:		the original image, 
 *		imgWidth:		the width of the image
 *		imgHeight:		the height of the image
 *						the image is arranged such that 
 *						origImg[3*(row*imgWidth+column)+0], 
 *						origImg[3*(row*imgWidth+column)+1], 
 *						origImg[3*(row*imgWidth+column)+2]
 *						are R, G, B values for pixel at (column, row).
 *
 *      kernel:			the 2D filter kernel,
 *		knlWidth:		the width of the kernel
 *		knlHeight:		the height of the kernel
 *		
 *		scale, offset:  after correlating the kernel with the origImg, 
 *						each pixel should be divided by scale and then added by offset
 *      
 *		selection:      a byte array of the same size as the image, 
 *						indicating where in the original image should be filtered, e.g., 
 *						selection[k] == 1 ==> pixel k should be filtered
 *                      selection[k] == 0 ==> pixel k should NOT be filtered
 *                      a special case is selection is a NULL pointer, which means all the pixels should be filtered. 
 *
 *  OUTPUT:
 *		rsltImg:		the filtered image of the same size as original image.
 *						it is a valid pointer ( allocated already ).
 */

void image_filter(double *rsltImg, const unsigned char *origImg, const unsigned char *selection, 
			int imgWidth, int imgHeight, 
			const double *kernel, int knlWidth, int knlHeight,
			double scale, double offset)
{
	//copy origImg to rsltImg is NOT the solution, it does nothing!, 
	//you need to figure sth out.
  for (int row = 0; row < imgHeight; row++)
  {
    for (int col = 0; col < imgWidth; col++)
    {
      int index = 3 * (row * imgWidth + col);

      if (! selection || selection[index / 3] == 1)
      {
        double rsltPixel[] = {0 , 0, 0};
        pixel_filter(rsltPixel,
                     col,
                     row,
                     origImg, 
                     imgWidth, 
                     imgHeight, 
                     kernel, 
                     knlWidth, 
                     knlHeight, 
                     scale, 
                     offset);
        for (int color = 0; color < 3; color++)
          rsltImg[index + color] = rsltPixel[color];
      }
      else
        for (int color = 0; color < 3; color++)
          rsltImg[index + color] = origImg[index + color];
    }
  }
}

/************************ END OF TBD 2 **************************/


/************************ TO BE DONE 3 **************************/
/*
 *	INPUT: 
 *      x:				a column index,
 *      y:				a row index,
 *		origImg:		the original image, 
 *		imgWidth:		the width of the image
 *		imgHeight:		the height of the image
 *						the image is arranged such that 
 *						origImg[3*(row*imgWidth+column)+0], 
 *						origImg[3*(row*imgWidth+column)+1], 
 *						origImg[3*(row*imgWidth+column)+2]
 *						are R, G, B values for pixel at (column, row).
 *
 *      kernel:			the 2D filter kernel,
 *		knlWidth:		the width of the kernel
 *		knlHeight:		the height of the kernel
 *
 *		scale, offset:  after correlating the kernel with the origImg, 
 *						the result pixel should be divided by scale and then added by offset
 *
 *  OUTPUT:
 *		rsltPixel[0], rsltPixel[1], rsltPixel[2]:		
 *						the filtered pixel R, G, B values at row y , column x;
 */

void pixel_filter(double rsltPixel[3], int x, int y, const unsigned char *origImg, int imgWidth, int imgHeight, 
			  const double *kernel, int knlWidth, int knlHeight,
			  double scale, double offset)
{
  int startWidth = (knlWidth / 2);
  int startHeight = (knlHeight / 2);

  for (int color = 0; color < 3; color++) {
    double sum = 0;

    for (int row = -startHeight; row < knlHeight - startHeight; row++) {
      for (int col = -startWidth; col < knlWidth - startWidth; col++) {
        int knlIndex = (row + startHeight) * knlWidth + (col + startWidth);

        if (kernel[knlIndex] != 0) {
          int imageX = x + col;
          int imageY = y + row;

          if (imageX >= 0 && imageX < imgWidth && imageY >= 0 && imageY < imgHeight)
           sum += kernel[knlIndex] * origImg[3 * (imageY * imgWidth + imageX) + color];
        }
      }
    }

    sum = abs(sum);
    if (scale != 0)
      rsltPixel[color] = sum/scale + offset;
  }
}

/************************ END OF TBD 3 **************************/

