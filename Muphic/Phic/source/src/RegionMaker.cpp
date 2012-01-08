#include "RegionMaker.h"

#include "opencv2/opencv.hpp"
#include "opencv2/imgproc/imgproc.hpp"

RegionMaker::RegionMaker()
{
    //ctor
}

RegionMaker::~RegionMaker()
{
    //dtor
}


bool emptyBoolMatrix(bool** matrix, int w, int h)
{
	bool empty = true;
	int i, j;

	i = 0;
	while (i < w && empty)
	{
		j = 0;
		while (j < h && empty)
		{
			empty = !matrix[i][j];
			j++;
		}
		i++;
	}

	return empty;
}

bool emptyMatrix(int** matrix, int w, int h)
{
	bool empty = true;
	int i, j;

	i = 0;
	while (i < w && empty)
	{
		j = 0;
		while (j < h && empty)
		{
			empty = !(matrix[i][j] == 1);
			j++;
		}
		i++;
	}

	return empty;
}

bool** createBoolMatrix(int w, int h)
{
	bool** matrix;
	matrix = new bool*[w];
	for (int i = 0; i < w; i++)
	{
		matrix[i] = new bool[h];
		for (int j = 0; j < h; j++)
			matrix[i][j] = false;
	}

	return matrix;
}


int** createMatrix(int w, int h)
{
	int** matrix;
	matrix = new int*[w];
	for (int i = 0; i < w; i++)
	{
		matrix[i] = new int[h];
		for (int j = 0; j < h; j++)
			matrix[i][j] = 0;
	}

	return matrix;
}

void showBoolMatrix(bool** matrix, int w, int h)
{
	for (int i = 0; i < w; i++)
	{
		for (int j = 0; j < h; j++)
			if (matrix[i][j])
				cout << "1 ";
			else
				cout << "0 ";
		cout << endl;
	}
}

void showMatrix(int** matrix, int w, int h)
{
	for (int i = 0; i < w; i++)
	{
		for (int j = 0; j < h; j++)
			cout << matrix[i][j] << " ";
		cout << endl;
	}
}

bool** intToBoolMatrix(int** a, int w, int h)
{
	bool ** out = createBoolMatrix(w,h);

	for (int i = 0; i < w; i++)
		for (int j = 0; j < h; j++)
			out[i][j] = a[i][j] == 1;

	return out;
}

int** boolToIntMatrix(bool** a, int w, int h)
{
	int ** out = createMatrix(w,h);

	for (int i = 0; i < w; i++)
		for (int j = 0; j < h; j++)
			if (a[i][j])
				out[i][j] = 1;

	return out;
}

int expand(int** src, bool** out, int i, int j, int w, int h)
{
	int n1, n2, n3, n4;
	n1 = n2 = n3 = n4 = 0;

	if (i < w-1 && src[i+1][j] > 0)
	{
		i++;					
		// connected component gets bigger
		out[i][j] = true;
		// one more pixel visited
		src[i][j] = -1;
		// expand this way
		n1 = 1 + expand(src, out, i, j, w, h);
	}
	
	if (i > 0 && src[i-1][j] > 0)
	{
		i--;
		// connected component gets bigger
		out[i][j] = true;
		// one more pixel visited
		src[i][j] = -1;
		// expand this way
		n2 = 1 + expand(src, out, i, j, w, h);
	}
	
	if (j < h-1 && src[i][j+1] > 0)
	{
		j++;
		// connected component gets bigger
		out[i][j] = true;
		// one more pixel visited
		src[i][j] = -1;
		// expand this way
		n3 = 1 + expand(src, out, i, j, w, h);
	}
	
	if (j > 0 && src[i][j-1] > 0)
	{
		j--;
		// connected component gets bigger
		out[i][j] = true;
		// one more pixel visited
		src[i][j] = -1;
		// expand this way
		n4 = 1 + expand(src, out, i, j, w, h);
	}


	return n1 + n2 + n3 + n4;
}


// a breaks b into pieces, and modifies itself in the process
vector<int**> cartessianProduct1on1(int** a, int** b, int w, int h)
{
	int ** onesBoth, ** onesB;
	onesBoth = createMatrix(w,h);
	onesB = createMatrix(w,h);

	for (int i = 0; i < w; i++)
	{
		for (int j = 0; j < h; j++)
		{
			if ((a[i][j] == b[i][j]) && (a[i][j])) // both one
			{
				onesBoth[i][j] = 1;
				a[i][j] = 0; // this pixel has been used
			}
			else if (b[i][j])
			{
				onesB[i][j] = 1;
				a[i][j] = 0; // this pixel has been used
			}
		}
	}

	vector<int**> sol;
	if (!emptyMatrix(onesBoth, w, h))
		sol.push_back(onesBoth);
	if (!emptyMatrix(onesB, w, h))
		sol.push_back(onesB);

	return sol;
}

vector<int**> cartessianProduct1onN(int** a, vector<int**> b, int w, int h)
{
	vector<int**> sol;
	vector<int**> tmp;

	for (vector<int**>::iterator it = b.begin(); it != b.end(); it++)
	{
		// use a to break to pieces, add pieces to sol and keep going with a
		tmp = cartessianProduct1on1(a, *it, w, h);
		sol.insert(sol.end(), tmp.begin(), tmp.end());
		
		if (emptyMatrix(a, w, h))
		{
			it++;
			sol.insert(sol.end(), it, b.end());
			break;
		}
	}

	return sol;
}

vector<int**> cartessianProductNonN(vector<int**> a, vector<int**> b, int w, int h)
{
	// a will break sol
	vector<int**> sol;
	vector<int**> tmp;
	
	vector<int**> in;

	// in will initially be a
	for (vector<int**>::iterator it = a.begin(); it != a.end(); it++)
	{
		if (!emptyMatrix(*it, w, h))
			in.push_back(*it);
	}

	// sol will initially be b
	for (vector<int**>::iterator it = b.begin(); it != b.end(); it++)
	{
		if (!emptyMatrix(*it, w, h))
			sol.push_back(*it);
	}



	vector<int**>::iterator i = in.begin();
	while (i != in.end())
	{
		tmp = cartessianProduct1onN(*i, sol, w, h);
		sol = tmp;
		i++;
	}

	// the rest of a is added to sol
	for (vector<int**>::iterator it = a.begin(); it != a.end(); it++)
	{
		if (!emptyMatrix(*it, w, h))
			sol.push_back(*it);
	}

	return sol;
}



vector<bool**> connectedComponents(int** matrix, int w, int h)
{
	// count pixels
	int total = 0;
	for (int x = 0; x < w; x++)
		for (int j = 0; j < h; j++)
			total += matrix[x][j];

	int n = 0;
	int phase = 0;
	int i;
	int j;
	bool** currentMatrix;
	vector<bool**> out;

	if (total == 0)
		return out;

	while (n < total)
	{
		switch (phase)
		{
			case 0:
				// phase 0 (find 1s)
				i = 0;
				while (i < w && phase == 0)
				{
					j = 0;
					while (j < h && phase == 0)
					{
						if (matrix[i][j] > 0)
						{
							// one more connected component found
							currentMatrix = createBoolMatrix(w, h);
							currentMatrix[i][j] = true;
							out.push_back(currentMatrix);	
							// one more pixel visited
							n++;	
							matrix[i][j] = -1;	
							phase = 1;
						}
						else
							j++;
					}
					if (phase == 0)
						i++;
				}
				break;
			case 1:
				// phase 1 (pixel alocated, find neighbors)
				n += expand(matrix, currentMatrix, i, j, w, h);
				phase = 0;
		}
	}
	return out;
}

vector<Mask*> RegionMaker::makeRegions(std::string picPath)
{
	// read image

	IplImage* img = cvLoadImage(picPath.c_str(), CV_LOAD_IMAGE_COLOR);
	IplImage* imgR = cvCreateImage( cvSize(img->width,img->height), img->depth, 1 );
	IplImage* imgG = cvCreateImage( cvSize(img->width,img->height), img->depth, 1 );
	IplImage* imgB = cvCreateImage( cvSize(img->width,img->height), img->depth, 1 );

	cv::Mat image = img;
	uchar*    ptrR;
	uchar*    ptrG;
	uchar*    ptrB;
	for (int i=0; i < image.rows; i++)
	{
		for (int j=0; j  <image.cols; j++)
		{
			ptrR = cvPtr2D(imgR, i, j, NULL);
			ptrG = cvPtr2D(imgG, i, j, NULL);
			ptrB = cvPtr2D(imgB, i, j, NULL);

			ptrR[0] = 0;
			ptrR[1] = 0;
			ptrR[2] = 0;

			ptrG[0] = 0;
			ptrG[1] = 0;
			ptrG[2] = 0;

			ptrB[0] = 0;
			ptrB[1] = 0;
			ptrB[2] = 0;
		}
	}


	// regions by channels
	vector<int**> regionsR, regionsG, regionsB;
	float divisions = 3;

	// each channel will have <division> regions
	int** matrix;
	for (int i = 0; i <= divisions; i++)
	{
		matrix = createMatrix(img->width, img->height);
		regionsR.push_back(matrix);

		matrix = createMatrix(img->width, img->height);
		regionsG.push_back(matrix);

		matrix = createMatrix(img->width, img->height);
		regionsB.push_back(matrix);
	}

	// compute regions of each channel and put them in regionsR, regionsG & regionsB
	CvScalar s;
	int r, g, b;
	float delta = 255 / divisions;

	for (int i=0; i<image.rows; i++)
	{
		for (int j=0; j<image.cols; j++)
		{
			s = cvGet2D(img, i, j);

			r = (int) s.val[2] / delta;
			regionsR[r][i][j] = 1;
			
			g = (int) s.val[1] / delta;
			regionsG[g][i][j] = 1;

			b = (int) s.val[0] / delta;
			regionsB[b][i][j] = 1;

			//std::cout << "(" << s.val[0] << "," << s.val[1] << "," << s.val[2] << ") ";
		}
		std::cout << endl;
	}

	cout << endl;

	// Cartessian product
	
	vector<int**> regionstmp, regionstmp2, regions;
	
	regionstmp = cartessianProductNonN(regionsR, regionsG, img->width, img->height);
	regionstmp2 = cartessianProductNonN(regionstmp, regionsB, img->width, img->height);
	regions.insert(regions.begin(), regionstmp.begin(), regionstmp.end());
	regions.insert(regions.begin(), regionstmp2.begin(), regionstmp2.end());
	

	vector<bool**> finalRegions;
	vector<bool**>  tmp;
	int** tmp2;
	for (vector<int**>::iterator it = regions.begin(); it != regions.end(); it++)
	{
		if (!emptyMatrix(*it, img->width, img->height))
		{
			tmp = connectedComponents(*it, img->width, img->height);
			finalRegions.insert(finalRegions.begin(), tmp.begin(), tmp.end());
		}
	}

/*
	for (vector<bool**>::iterator it = finalRegions.begin(); it != finalRegions.end(); it++)
	{
		cout << "-" << endl;
		showBoolMatrix(*it, img->width, img->height);
		cout << endl;
	}

	*/
	system("PAUSE");
	





	vector<Mask*> tetas;
	return tetas;
}