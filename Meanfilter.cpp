void MeanFilter(BYTE **img1, double **img2, int width, int height)
{
	// 3x3 window 설정하기. 평균만 구하면 되므로 모든 원소는 1로 설정.
	int window[3][3] = {
		{1, 1, 1},
		{1, 1, 1},
		{1, 1, 1},
	};

	int i, j, m, n, sum;

	// 최외각 픽셀은 무시하고 연산하기
	for (j = 1; j < height - 1; j++) {
		for (i = 1; i < width - 1; i++) {
			sum = 0;

			// 3x3 window 내 9개 픽셀값을 모두 더하기
			for (m = 0; m < 3; m++) {
				for (n = 0; n < 3; n++) {
					sum += (img1[j - 1 + m][i - 1 + n] * window[m][n]);
				}
			}

			// 픽셀 9개의 평균값 구하기
			img2[j][i] = sum / 9.;
		}
	}
}

void CHomework::OnClickedFilter3()
{
	// 각종 변수 선언하기
	int width, height, x0, y0;
	BYTE **img1, **img3;
	double **img2;

	// 입력영상 정보 읽기
	if (!GetCurrentImageInfo(&width, &height, &x0, &y0)) return;

	// BYTE**, double** 자료형 할당하기
	img1 = cmatrix(height, width);
	img2 = dmatrix(height, width);
	img3 = cmatrix(height, width);

	// 회색조 영상 읽기
	GetCurrentImageGray(img1);

	// Mean-Filter
	MeanFilter(img1, img2, width, height);

	// 결과를 화면에 출력하기 위해 normalize
	DNormalize2D(img2, img3, width, height);

	//회색조 영상 출력
	DisplayCimage2D(img3, width, height, x0 + width, y0, true);


	//BYTE**, double** 자료형 할당 해제하기
	free_cmatrix(img1, height, width);
	free_dmatrix(img2, height, width);
	free_cmatrix(img3, height, width);
}
