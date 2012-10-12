
        switch ( paddingSection )
        {
          case TOP_LEFT:
            break;
            
          case TOP:
            break;
            
          case TOP_RIGHT:
            break;
            
          case RIGHT:
            break;
            
          case BOTTOM_RIGHT:
            break;
            
          case BOTTOM:
            break;
            
          case BOTTOM_LEFT:
            break;
            
          case LEFT:
            break;

          default:
            paddedImg[padIndex + color] = img[imgIndex + color];
            break;
        }

      enum int { TOP_LEFT, TOP, TOP_RIGHT, RIGHT, BOTTOM_RIGHT, BOTTOM, BOTTOM_LEFT, LEFT };

  for (int row = 0; row < imgHeight; row++) {
    for (int col = 0; col < imgWidth; col++) {
      int padRow = row + (knlWidth / 2);
      int padCol = col + (knlHeight / 2);
      int padIndex = 3 * (padRow * padWidth + padCol);
      int imgIndex = 3 * (row * imgWidth + col);

      for (int color = 0; color < 3; color++) {
        paddedImg[padIndex + color] = img[imgIndex + color];
      }
    }
  }


  for (int padRow = 0; padRow < padHeight; padRow++) {
    for (int padCol = 0; padCol < padWidth; padCol++) {
      int index = 3 * (padRow * padWidth + padCol);
      for (int color = 0; color < 3; color++) {
        if (padRow == padHeight -1 && color == 2)
          printf("%*u \n", 5, paddedImg[index + color]);
        else
          printf("%*u ", 5, paddedImg[index + color]);
      }
    }
  }

{
	//// printf("InitNodeBuf in iScissor.cpp: to be implemented!\n");

  // Pad image using linear extrapolation. Need padded image to
  // determine cost of links between pixels.
  int knlWidth, knlHeight; 
  knlWidth = knlHeight = 3; // Currently kernels are 3 x 3
  int padWidth = imgWidth + (knlWidth - 1);
  int padHeight = imgHeight + (knlHeight -1);
  int padImageSize = padWidth * padHeight * 3;

  unsigned char *paddedImg = new unsigned char[padImageSize];

  PadImage(paddedImg, img, padWidth, padHeight, imgWidth, imgHeight, knlWidth, knlHeight);

  double maxD = 0;

	for (int row = 0; row < imgHeight; row++) {
		for (int col = 0; col < imgWidth; col++) {
      Node node = Node();
      node.column = col;
      node.row = row;

      for (int link = 0; link < 8; link++) {
        double rsltPixel[] = {0 , 0, 0};
        double cost = 0;

        pixel_filter(rsltPixel,
                     row + 1, // because we're using the paddedImg; (0, 0) in
                     col + 1, // the original corresponds to (1, 1) in the padded
                     paddedImg, 
                     padWidth, 
                     padHeight, 
                     kernels[link], 
                     knlWidth, 
                     knlHeight, 
                     1, 
                     0);

        // Compute magnitude of the color derivate across each link.
        for (int color = 0; color < 3; color++) {
          cost += rsltPixel[color] * rsltPixel[color];
        }

        cost = sqrt(cost/3);
        node.linkCost[link] = cost;

        // maxD is the maximum link cost for all links in the image.
        if (cost > maxD)
          maxD = cost;
      }

      nodes[row*imgWidth + col] = node;
		}
	}

  //// for (int link = 0; link < 8; link++) {
  ////   double *filterImg = new double[imgWidth * imgHeight * 3];
  ////   image_filter(filterImg, img, NULL, imgWidth, imgHeight, kernels[link], 3, 3, 1, 0);

  ////   for (int row = 0; row < imgHeight; row++)
  ////   {
  ////     for (int col = 0; col < imgWidth; col++)
  ////     {
  ////       double sum = 0;

  ////       for (int color = 0; color < 3; color++)
  ////       {
  ////         double cost = filterImg[3 * (row * imgWidth + col) + color];
  ////         if (cost > maxD)
  ////           maxD = cost;

  ////         sum += cost * cost;
  ////       }
  ////       sum = sqrt(sum/3);

  ////       nodes[row * imgWidth + col].linkCost[link] = sum;
  ////     }
  ////   }

  ////   delete[] filterImg;
  //// }

  // Once maxD is determined, compute the final cost for each link.
  for (int row = 0; row < imgHeight; row++) {
    for (int col = 0; col < imgWidth; col++) {
      Node *node = nodes + row * imgWidth + col;
      node->column = col;
      node->row = row;

      for (int link = 0; link < 8; link++) {
        node->linkCost[link] = maxD - nodes->linkCost[link];
        node->linkCost[link] *= (link % 2 == 0) ? 1 : SQRT2;
      }
    }
  }
}

// Uses linear extrapolation to pad an image for filtering purposes.
void PadImage(unsigned char *paddedImg,
              const unsigned char *img,
              int padWidth,
              int padHeight,
              int imgWidth,
              int imgHeight,
              int knlWidth,
              int knlHeight)
{
  int extraRows, extraCols;
  extraRows = knlHeight / 2;
  extraCols = knlWidth / 2;

  for (int padRow = 0; padRow < padHeight; padRow++) {
    for (int padCol = 0; padCol < padWidth; padCol++) {
      int row, col, linearRow, linearCol;

      if (padRow < extraRows) // extend image upwards
      {
        row = 0 + (extraRows - padRow);
        linearRow = 0;
      }
      else if (padRow >= extraRows + imgHeight) // extend image downwards
      {
        row = (imgHeight - 1) - (padRow - imgHeight);
        linearRow = imgHeight - 1;
      }
      else // duplicate original image
      {
        row = padRow - extraRows;
        linearRow = row;
      }

      if (padCol < extraCols) // extend image to the left
      {
        col = 0 + (extraCols - padCol);
        linearCol = 0;
      }
      else if (padCol >= extraCols + imgWidth) // extend image to the right
      {
        col = (imgWidth - 1) - (padCol - imgWidth);
        linearCol = imgWidth - 1;
      }
      else // duplicate original image
      {
        col = padCol - extraCols;
        linearCol = col;
      }

      int padIndex, imgIndex, linearIndex;
      padIndex = 3 * (padRow * padWidth + padCol);
      imgIndex = 3 * (row * imgWidth + col);
      linearIndex = 3 * (linearRow * imgWidth + linearCol);

      // Determine the section of the image we are padding, then determine
      // the which pixel on the edge of the image to be used for linear
      // extrapolation

      // // Upper Left
      // if (padRow < extraRows && padCol < extraCols)
      // {
      //   linearIndex = 3 * (0); // 0 * imgWidth + 0
      // }
      // // Upper
      // else if (padRow < extraRows && 
      //          padCol >= extraCols && padCol < extraCols + imgWidth)
      // {
      //   linearIndex = 3 * (col); // 0 * imgWidth + col
      // }
      // // Upper Right
      // else if (padRow < extraRows && 
      //          padCol >= extraCols + imgWidth)
      // {
      //   linearIndex = 3 * (imgWidth - 1); // 0 * imgWidth + imgWidth - 1
      // }
      // // Right
      // else if (padRow >= extraRows && padRow < extraRows + imgHeight && 
      //          padCol >= extraCols + imgWidth)
      // {
      //   linearIndex = 3 * (row * imgWidth + (imgWidth - 1));
      // }
      // // Bottom Right
      // else if (padRow >= extraRows + imgHeight && 
      //          padCol >= extraCols + imgWidth)
      // {
      //   linearIndex = 3 * ((imgHeight - 1) * imgWidth + (imgWidth - 1));
      // }
      // // Bottom
      // else if (padRow >= extraRows + imgHeight && 
      //          padCol < extraCols + imgWidth && padCol >= extraCols)
      // {
      //   linearIndex = 3 * ((imgHeight - 1) * imgWidth + col);
      // }
      // // Bottom Left
      // else if (padRow >= extraRows + imgHeight && 
      //          padCol < extraCols)
      // {
      //   linearIndex = 3 * ((imgHeight - 1) * imgWidth); // (imgHeight - 1) * imgWidth + 0
      // }
      // // Left
      // else if (padRow < extraRows + imgHeight && padRow >= extraRows && 
      //          padCol < extraCols)
      // {
      //   linearIndex = 3 * (row * imgWidth); // row * imgWidth + 0
      // }
      // // Middle or original section
      // else
      // {
      //   linearIndex = imgIndex;
      // }

      for (int color = 0; color < 3; color++) {
        if (linearIndex == imgIndex) {
          paddedImg[padIndex + color] = img[imgIndex + color];
        }
        else {
          paddedImg[padIndex + color] = (2 * img[linearIndex + color]) - img[imgIndex + color];
        }
      }
    }
  }
}
