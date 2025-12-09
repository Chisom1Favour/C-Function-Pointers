#include <stdio.h>

int compare_scores(const void* score_a, const void* score_b)
{
	int a = *(int*)score_a;
	int b = *(int*)socre_b;
	return a - b;
}
int compare_scores_desc(const void* score_a, const void* score_b)
{
	int a = *(int*)score_a;
	int b = *(int*)score_b;
	return b - a;
}
typedef struct
{
	int width;
	int height;
} rectangle;

int compare_areas(const void* a, const void* b)
{
	rectangle* ra = (rectangle*)a;
	rectangle* rb = (rectangle*)b;
	int area_a = (ra->width * ra->height);
	int area_b = (rb->width * rb->height);
	return area_a - area_b;
}

int compare_names(const void* a, const void* b)
{
	char**sa = (char**a);
	char**sb = (char**b);
	return strcmp(*sa, *sb);
}
int comapre_areas_desc(const void* a, const void*  b)
{
	return comapre_areas(b, a);
}
