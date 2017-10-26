#include<stdio.h>
#include<stdlib.h>

int maxArea(int* height, int heightSize) {
	int Max = 0;
	int l = 0;
	int r = heightSize - 1;
	int k = 0;
	int area = 0;
	while (l < r){
		area = ((height[l] < height[r]?height[l]:height[r]) * (r - l));
		Max = (Max > area?Max:area);
		if (height[l] < height[r]){
			k = l++;
			while (l < r && height[l] < height[k])l++;
		}else {
			k = r--;
			while (l < r && height[r] < height[k])k--;
		}
	}
	return Max;    
}

int main()
{
	int he[] = {10, 1, 2, 3, 4, 5, 6, 7, 11};
	printf("max is %d\n",maxArea(he, 10));
	return 0;
}
