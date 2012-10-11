
#include "correlation.h"
#include "iScissor.h"




// two inlined routined that may help;

inline Node &NODE(Node *n, int i, int j, int width)
{ return *(n+j*width+i); }

inline unsigned char PIXEL(const unsigned char *p, int i, int j, int c, int width)
{ return *(p+3*(j*width+i)+c); }

/************************TO BE DONE 1***************************
 *InitNodeBuf
 *	INPUT: 
 *		img:	a RGB image of size imgWidth by imgHeight;
 *		nodes:	a allocated buffer of Nodes of the same size, one node corresponds to a pixel in img;
 *  OUPUT:
 *      initializes the column, row, and linkCost fields of each node in the node buffer.  
 */

void InitNodeBuf(Node *nodes, const unsigned char *img, int imgWidth, int imgHeight)
{
  int knlWidth, knlHeight; 
  knlWidth = knlHeight = 3; // Currently kernels are 3 x 3

  double maxD = 0;

  for (int link = 0; link < 8; link++)
  {
    double *filterImg = new double[imgWidth * imgHeight * 3];
    image_filter(filterImg,
                 img,
                 NULL,
                 imgWidth,
                 imgHeight,
                 kernels[link],
                 knlWidth,
                 knlHeight,
                 1,
                 0);

    for (int row = 0; row < imgHeight; row++)
    {
      for (int col = 0; col < imgWidth; col++)
      {
        double sum = 0;

        for (int color = 0; color < 3; color++)
        {
          double cost = filterImg[3 * (row * imgWidth + col) + color];
          if (cost > maxD)
            maxD = cost;

          sum += cost * cost;
        }
        sum = sqrt(sum/3);

        nodes[row * imgWidth + col].linkCost[link] = sum;
      }
    }

    delete[] filterImg;
  }

  // Once maxD is determined, compute the final cost for each link.
  for (int row = 0; row < imgHeight; row++)
  {
    for (int col = 0; col < imgWidth; col++)
    {
      Node *node = nodes + row * imgWidth + col;
      node->column = col;
      node->row = row;
      for (int link = 0; link < 8; link++)
      {
        node->linkCost[link] = maxD - node->linkCost[link];
        node->linkCost[link] *= (link % 2 == 0) ? 1 : SQRT2;
      }
    }
  }
}

/************************ END OF TBD 1 **************************/


/************************TO BE DONE 4***************************
 *LiveWireDP:
 *	INPUT:
 *		seedX, seedY:	seed position in nodes
 *		nodes:			node buffer of size width by height;
 *      width, height:  dimensions of the node buffer;
 *		selection:		if selection != NULL, search path only in the subset of nodes[j*width+i] if selection[j*width+i] = 1;
 *						otherwise, search in the whole set of nodes. 
 *		numExpanded:		compute the only the first numExpanded number of nodes; (for debugging)
 *	OUTPUT:
 *		computes the minimum path tree from the seed node, by assigning 
 *		the prevNode field of each node to its predecessor along the minimum 
 *		cost path from the seed to that node.
 */

void LiveWireDP(int seedX, int seedY, Node *nodes, int width, int height, const unsigned char *selection, int numExpanded)
{
  CTypedPtrHeap<Node>pq;

  for (int i = 0; i < width * height; i++)
  {
    nodes[i].state = INITIAL;
    nodes[i].totalCost = 0;
    nodes[i].prevNode = NULL;
  }

  int seedIndex = seedY * width + seedX;
  Node *seed = nodes + seedIndex;
  
  seed->totalCost = 0;

  pq.Insert(seed);

  while (! pq.IsEmpty())
  {
    Node *current = pq.ExtractMin();

    current->state = EXPANDED;

    for (int r = 0; r < 8; r++)
    {
      int offsetX, offsetY, nbrCol, nbrRow, nbrIndex;

      current->nbrNodeOffset(offsetX, offsetY, r);
      nbrCol = current->column + offsetX;
      nbrRow = current->row + offsetY;

      // Check that coordinates are within the boundaries of the image.
      if (nbrCol >= 0 && nbrCol < width && nbrRow >= 0 && nbrRow < height)
      {
        Node *nbr = nodes + nbrRow * width + nbrCol;

        if (nbr->state != EXPANDED)
        {
          if (nbr->state == INITIAL)
          {
            nbr->totalCost = current->totalCost + current->linkCost[r];
            nbr->prevNode = current;
            nbr->state = ACTIVE;
            pq.Insert(nbr);
          }
          else if (nbr->state == ACTIVE)
          {
            if (current->totalCost + current->linkCost[r] < nbr->totalCost)
            {
              nbr->totalCost = current->totalCost + current->linkCost[r];
              nbr->prevNode = current;
            }
          }
        }
      }
    }
  }
}
/************************ END OF TBD 4 **************************/



/************************TO BE DONE 5***************************
 *MinimumPath:
 *	INPUT:
 *		nodes:				a node buffer of size width by height;
 *		width, height:		dimensions of the node buffer;
 *		freePtX, freePtY:	an input node position;
 *	OUTPUT:
 *		insert a list of nodes along the minimum cost path from the seed node to the input node.  
 *		Notice that the seed node in the buffer has a NULL predecessor.
 *		And you want to insert pointer to Node in path, e.g., 
 *		insert nodes+j*width+i if you want to insert node at (i,j), instead of nodes[nodes+j*width+i]!!!
 *		after the procedure, the seed should be the head of path and the input code should be the tail
 */

void MinimumPath(CTypedPtrDblList <Node> *path, int freePtX, int freePtY, Node *nodes, int width, int height)
{
	// printf("MinimumPath in iScissor.cpp: to be implemented!\n");

  Node *freeNode = nodes + freePtY * width + freePtX;
  Node *prevNode = freeNode->prevNode;

  if (prevNode == NULL)
  {
    path->AddTail(freeNode);
  }
  else
  {
    MinimumPath(path, prevNode->column, prevNode->row, nodes, width, height);
    path->AddTail(freeNode);
  }
}
/************************ END OF TBD 5 **************************/



/************************An Extra Credit***************************
 *SeeSnap:
 *	INPUT:
 *		img:				a RGB image buffer of size width by height;
 *		width, height:		dimensions of the image buffer;
 *		x,y:				an input seed position;
 *	OUTPUT:
 *		update the value of x,y to the closest edge based on local image information.
 */

void SeedSnap(int &x, int &y, unsigned char *img, int width, int height)
{
	printf("SeedSnap in iScissor.cpp: to be implemented for extra credits!\n");
}

//generate a cost graph from original image and node buffer with all the link costs;
void MakeCostGraph(unsigned char *costGraph, const Node *nodes, const unsigned char *img, int imgWidth, int imgHeight)
{
	int graphWidth = imgWidth * 3;
	int graphHeight = imgHeight * 3;
	int dgX = 3;
	int dgY = 3*graphWidth;

	int i,j;
	for (j=0;j<imgHeight;j++)
	{
		for (i=0;i<imgWidth;i++)
		{
			int nodeIndex = j*imgWidth+i;
			int imgIndex = 3*nodeIndex;
			int costIndex = 3*((3*j+1)*graphWidth+(3*i+1));
			
			const Node *node = nodes+nodeIndex;
			const unsigned char *pxl = img + imgIndex;
			unsigned char *cst = costGraph + costIndex;

			cst[0] = pxl[0];
			cst[1] = pxl[1];
			cst[2] = pxl[2];
			
			//r,g,b channels are grad info in seperate channels;				
			DigitizeCost(cst	   + dgX, node->linkCost[0]);
			DigitizeCost(cst - dgY + dgX, node->linkCost[1]);
			DigitizeCost(cst - dgY      , node->linkCost[2]);
			DigitizeCost(cst - dgY - dgX, node->linkCost[3]);
			DigitizeCost(cst	   - dgX, node->linkCost[4]);
			DigitizeCost(cst + dgY - dgX, node->linkCost[5]);
			DigitizeCost(cst + dgY	   ,  node->linkCost[6]);
			DigitizeCost(cst + dgY + dgX, node->linkCost[7]);
		}
	}
}
