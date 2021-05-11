void MedianFilter(BYTE **img1, double **img3, int width, int height)
{
	int i, j;

	// 3x3 window 내 픽셀 값들을 정렬하기 위해 1차원 배열 만들기.
	BYTE m[9];

	// 3x3 window 내 픽셀값을 1차원 배열 m에 대입.
	for (j = 1; j < height - 1; j++) {
		for (i = 1; i < width - 1; i++) {
			m[0] = img1[j - 1][i - 1];
			m[1] = img1[j - 1][i];
			m[2] = img1[j - 1][i + 1];
			m[3] = img1[j][i - 1];
			m[4] = img1[j][i];
			m[5] = img1[j][i + 1];
			m[6] = img1[j + 1][i - 1];
			m[7] = img1[j + 1][i];
			m[8] = img1[j + 1][i + 1];

			// BYTE형 배열 m을 오름차순으로 정렬하는 알고리즘. #include <algorithm> 추가함.
			std::sort(m, m + 9);

			// 오름차순으로 정렬된 배열 m에서 m[4]가 중간값.
			img3[j][i] = m[4];
		}
	}
}